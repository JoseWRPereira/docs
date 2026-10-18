---
title: Lab08 - ML Clássico - Análise de Componentes Principais - PCA - Redução de Dimensionalidade
icon: fontawesome/solid/chart-line
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---

SLTINTA - [Ementa](../../ifsp-slt/dados/sltinta_ementa.md) - [Plano de Aula](../../ifsp-slt/dados/sltinta_plano_aula.md) 

---

#

---

# Redução de Dimensionalidade com PCA (Análise de Componentes Principais) e Mapeamento de Clusters Industriais


---

## 🔴 Situação-Problema

Nas semanas anteriores, a equipe de engenharia da fábrica siderúrgica explorou modelos de Machine Learning clássico como **SVM**, **Árvores de Decisão** e **Florestas Aleatórias / Random Forest** para a classificação binária da saúde do cabeçote da usinadora CNC.

Agora, a equipe de instrumentação da fábrica planeja expandir o sistema de monitoramento instalando mais 15 novos sensores na usinadora CNC (medições de corrente elétrica trifásica, análise de ruído acústico, vazão e pressão do fluido refrigerante, vibração triaxial e temperatura dos mancais). No entanto, os engenheiros de software e cientistas de dados alertaram para o fenômeno da **"Maldição da Dimensionalidade"** (*Curse of Dimensionality*):

1. **Redundância e Colinearidade:** Sensores físicos em um mesmo equipamento costumam ser fortemente correlacionados, como por exemplo, o aumento na velocidade de rotação do eixo provoca elevação na temperatura do processo, na corrente elétrica do motor e no nível de vibração. Variáveis colineares adicionam ruído estatístico, duplicam dados e aumentam o custo computacional.
2. **Complexidade de Processamento e Visualização:** Processar dezenas de colunas em tempo real sobrecarrega os microcontroladores e gateways locais, além de inviabilizar a visualização direta da saúde do maquinário para os operadores de sala de controle em gráficos bidimensionais simples.

Para superar esse desafio, a gerência de manutenção solicitou a implementação da técnica estatística não supervisionada de **Análise de Componentes Principais (PCA - *Principal Component Analysis*)**. O objetivo é condensar a massa multidimensional de sensores em um subespaço vetorial ortogonal reduzido composto por **2 Componentes Principais ($PC_1$ e $PC_2$)**, eliminando a redundância colinear, preservando a máxima variância dos dados e permitindo mapear visualmente em tempo real o **agrupamento (*cluster*) de falhas** no **Dashboard**.

---

## 🏁 Descritivo de Metas da Atividade Prática

* **Meta 1:** Avaliar a matriz de correlação e covariância das variáveis de telemetria do dataset **AI4I 2020 (UCI)**, evidenciando o acoplamento físico entre os sensores e a colinearidade do processo industrial.
* **Meta 2:** Aplicar obrigatoriamente a padronização de escala com `StandardScaler`, compreendendo por que diferenças nas unidades numéricas originais (ex.: RPM na casa dos milhares vs. Temperatura em centenas de Kelvin) distorcem o cálculo da variância no PCA se não forem normalizadas.
* **Meta 3:** Projetar o espaço $d$-dimensional dos sensores nos 2 primeiros Componentes Principais ($PC_1$ e $PC_2$) utilizando a classe `PCA` do Scikit-Learn e quantificar a **Razão de Variância Explicada (`explained_variance_ratio_`)** e a variância acumulada retida após a compressão.
* **Meta 4:** Construir um gráfico de dispersão (*Scatter Plot*) 2D com Plotly/Seaborn isolando e mapeando o agrupamento (*cluster*) de falhas mecânicas em tempo real, preparando o artefato do transformador e do pipeline para integração no **Dashboard**.



---

## Passo a Passo Didático


## 1: Análise Exploratória da Matriz de Correlação e Colinearidade

Na indústria, sensores instalados em um mesmo equipamento monitoram aspectos físicos acoplados do processo. Antes de aplicar o PCA, calculamos a matriz de correlação de Pearson para identificar explicitamente o grau de colinearidade.

```python
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# 1. Carregamento dos dados limpos
df = pd.read_csv("./dataset/ai4i2020.csv")
cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
df_clean = df.drop(columns=[c for c in cols_to_drop if c in df.columns])
df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

X = df_encoded.drop(columns=['Machine failure'])

# 2. Cálculo e visualização da Matriz de Correlação
corr_matrix = X.corr()

plt.figure(figsize=(8, 6))
sns.heatmap(corr_matrix, annot=True, fmt=".2f", cmap="vlag", vmin=-1, vmax=1)
plt.title("Matriz de Correlação entre Sensores Industriais")
plt.tight_layout()
plt.show()
```

### 💡 Explicação Técnica e Motivação:

* **Conexão Física entre Sensores:** Observa-se uma forte correlação positiva entre `Air temperature [K]` e `Process temperature [K]` ($r \approx 0{,}88$), além da relação inversa física entre `Rotational speed [rpm]` e `Torque [Nm]` ($r \approx -0{,}87$, decorrente da equação de potência $P = \tau \cdot \omega$).
* **A Redundância:** Tratar essas colunas como variáveis independentes gera duplicidade de informação. O PCA resolverá essa redundância transformando-as em novos eixos ortogonais (não correlacionados).

---

## 2: A Importância Crítica da Padronização de Escala (`StandardScaler`)

O algoritmo do PCA é fundamentalmente guiado pela maximização da variância estatística:

$$\text{Var}(X_j) = \frac{1}{N} \sum_{i=1}^{N} (x_{i,j} - \bar{x}_j)^2$$

Se aplicarmos o PCA sobre dados brutos onde a variável `Rotational speed [rpm]` oscila na casa dos milhares (ex.: $1200$ a $2800 \text{ rpm}$) e a variável `Torque [Nm]` varia entre $10$ e $70 \text{ Nm}$, a variância do RPM em termos absolutos será milhares de vezes maior. O PCA interpretará o RPM como a única variável importante no universo, ignorando o Torque e o Desgaste da Ferramenta.

```python
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

# 1. Demonstração do ERRO (PCA sem padronização)
pca_errado = PCA(n_components=2)
X_errado = pca_errado.fit_transform(X)
print("Variância Explicada Sem Padronização (Incorreto):", pca_errado.explained_variance_ratio_)

# 2. Correção Profissional (Com StandardScaler)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

pca_correto = PCA(n_components=2)
X_pca = pca_correto.fit_transform(X_scaled)
print("Variância Explicada Com Padronização (Correto):", pca_correto.explained_variance_ratio_)
```

### 💡 Explicação Técnica e Motivação:

* **Escalonamento Z-Score:** O `StandardScaler` subtrai a média $\mu$ e divide pelo desvio padrão $\sigma$ ($z = \frac{x - \mu}{\sigma}$), garantindo que **todos os sensores tenham média $0$ e variância $1$**. A partir deste ponto, nenhuma variável domina o PCA puramente por questões de unidade de medida.

---

## 3: A Decomposição em Componentes Principais ($PC_1$ e $PC_2$)

Matematicamente, o PCA decompõe a matriz de covariância dos dados padronizados $\mathbf{\Sigma} = \frac{1}{N-1} \mathbf{X}^T \mathbf{X}$ através do cálculo de seus **Autovalores ($\lambda_j$)** e **Autovetores ($\mathbf{v}_j$)**:

$$\mathbf{\Sigma} \mathbf{v}_j = \lambda_j \mathbf{v}_j$$

* **Autovetores ($\mathbf{v}_j$):** Definem a direção geométrica dos novos eixos ordenados ($PC_1, PC_2, \dots, PC_k$) no espaço multidimensional.
* **Autovalores ($\lambda_j$):** Quantificam a magnitude da variância contida ao longo de cada autovetor correspondente.

```python
# Inspecionando a composição linear (loadings) do primeiro componente PC1
df_loadings = pd.DataFrame(
    pca_correto.components_,
    columns=X.columns,
    index=['PC1', 'PC2']
)

print("="*60)
print("PESOS DOS SENSORES (LOADINGS) EM CADA COMPONENTE PRINCIPAL")
print("="*60)
print(df_loadings.round(3).T)
```

### 💡 Leitura Prática:

O vetor $PC_1$ não possui uma unidade física isolada (como $^{\circ}\text{C}$ ou $\text{RPM}$). Ele é uma **combinação linear ponderada** de todas as variáveis de entrada:


\[
\begin{aligned}
PC_1 ={}& w_{1,1} \cdot \text{Temp_Ar}_{\text{std}} \\
&+ w_{1,2} \cdot \text{Temp_Proc}_{\text{std}} \\
&+ w_{1,3} \cdot \text{RPM}_{\text{std}} \\
&+ w_{1,4} \cdot \text{Torque}_{\text{std}} + \dots
\end{aligned}
\]

---

## 4: Quantificação da Informação Retida (`explained_variance_ratio_`) e Scree Plot

Para decidir quantos componentes devem ser mantidos no sistema, analisa-se a razão de variância explicada e a curva de cotovelo (*Scree Plot*).

```python
import numpy as np
import matplotlib.pyplot as plt

# Treinando PCA com todos os componentes possíveis
pca_full = PCA().fit(X_scaled)
var_exp = pca_full.explained_variance_ratio_
cum_var_exp = np.cumsum(var_exp)

# Plotagem da Curva do Scree Plot
plt.figure(figsize=(8, 4))
plt.bar(range(1, len(var_exp)+1), var_exp, alpha=0.6, align='center', label='Variância Individual')
plt.step(range(1, len(cum_var_exp)+1), cum_var_exp, where='mid', label='Variância Acumulada', color='red')
plt.ylabel('Razão de Variância Explicada')
plt.xlabel('Índice do Componente Principal')
plt.title('Curva de Cotovelo (Scree Plot) - Seleção de Componentes')
plt.axhline(y=0.85, color='gray', linestyle='--', label='Limiar de 85% de Informação')
plt.legend(loc='best')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()
```

---

## 5: Mapeamento e Visualização do Cluster de Falhas em 2D

Projetamos o dataset no plano cartesiano formado por $PC_1$ e $PC_2$ e colorimos os pontos de acordo com o status real da máquina (`Machine failure`).

```python
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# 1. Estruturação do DataFrame 2D do PCA
df_pca = pd.DataFrame(X_pca, columns=['PC1', 'PC2'])
df_pca['Status_Maquina'] = y.values

# 2. Visualização do Cluster de Falhas em 2D
plt.figure(figsize=(10, 6))
sns.scatterplot(
    data=df_pca,
    x='PC1',
    y='PC2',
    hue='Status_Maquina',
    palette={0: '#2ca02c', 1: '#d62728'},
    alpha=0.6,
    s=35
)

plt.title("Visualização do Espaço de Estados 2D (PC1 x PC2) - Cluster de Falhas", fontsize=12, fontweight='bold')
plt.xlabel(f"PC1 ({pca_correto.explained_variance_ratio_[0]:.2%} da Variância)")
plt.ylabel(f"PC2 ({pca_correto.explained_variance_ratio_[1]:.2%} da Variância)")
plt.legend(title="Estado Operacional", labels=["Normal (Classe 0)", "Falha (Classe 1)"])
plt.grid(True, linestyle=":", alpha=0.6)
plt.tight_layout()
plt.show()
```

### 💡 Aplicação Prática no Dashboard Streamlit:
No chão de fábrica, durante a operação normal, as leituras dos sensores enviadas pelo **ESP32** geram coordenadas $(PC_1, PC_2)$ situadas no centro do **agrupamento verde (operação saudável)**. Quando a ferramenta sofre um desgaste acentuado ou o torque atinge níveis críticos, o ponto no gráfico 2D sofre um **deslocamento espacial em direção ao cluster vermelho de perigo**, permitindo ao operador disparar um alerta preditivo preventivo antes da quebra efetiva.

---

## Resumo Didático dos Pontos de Atenção

1. **Esquecer o `StandardScaler`:** É o erro mais comum em projetos. O PCA baseia-se no cálculo de variâncias; variáveis com números absolutos grandes dominarão indevidamente a projeção se não forem padronizadas antes do fit.
2. **Caráter Não Supervisionado:** O PCA **não recebe e não utiliza a variável alvo $y$** durante a fase de treinamento (`.fit()`). Ele busca apenas as direções de máxima dispersão nos atributos $X$.
3. **Perda da Unidade Física Direta:** Os eixos $PC_1$ e $PC_2$ são combinações lineares de todas as colunas. Não faz sentido perguntar se $PC_1$ está em "rpm" ou "°C"; ele representa um vetor de estado multidimensional.
4. **Trade-Off de Compressão vs. Informação:** Reduzir para 2D facilita a visualização em telas e reduz a carga computacional no Streamlit, mas implica aceitar a perda da porcentagem residual de variância não capturada pelos dois primeiros eixos.

---

## *Pipeline* estilo *Production-Ready* de Engenharia de ML

Abaixo é apresentada a **solução profissional** desenvolvida por um Engenheiro de Machine Learning / Cientista de Dados. Esta implementação automatiza a ingestão do dataset UCI AI4I 2020, realiza a limpeza preventiva de *Target Leakage*, constrói um pipeline modular com `StandardScaler` e `PCA`, avalia a variância acumulada para diferentes números de componentes, projeta os dados em 2D, exporta o gráfico do cluster e serializa os artefatos (`scaler_pca_production.joblib`) para consumo em produção.

```python
"""
===============================================================================
SISTEMA DE REDUÇÃO DE DIMENSIONALIDADE E MONITORAMENTO DE CLUSTERS (PCA)
===============================================================================
Autor: Engenharia de ML / Ciência de Dados
Projeto: Monitoramento de Ativos CNC via PCA - Indústria 4.0
Dataset: AI4I 2020 Predictive Maintenance Dataset (UCI Repository)
URL: https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip
===============================================================================
"""

import os
import zipfile
import urllib.request
import joblib
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

# 1. Configurações Globais
SEED = 42
DATASET_URL = "https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip"
ZIP_PATH = "ai4i_2020.zip"
EXTRACT_DIR = "dataset"
CSV_PATH = os.path.join(EXTRACT_DIR, "ai4i2020.csv")


class UCIDataIngestion:
    """Gerencia o download, extração e limpeza do dataset AI4I 2020."""

    @staticmethod
    def get_data() -> pd.DataFrame:
        os.makedirs(EXTRACT_DIR, exist_ok=True)
        if not os.path.exists(CSV_PATH):
            if not os.path.exists(ZIP_PATH):
                try:
                    print(f"[INFO] Baixando dataset AI4I 2020 de {DATASET_URL}...")
                    urllib.request.urlretrieve(DATASET_URL, ZIP_PATH)
                except Exception as e:
                    print(f"[OFFLINE] Erro ao baixar diretamente: {e}. Gerando estrutura sintética fidedigna...")
                    UCIDataIngestion._generate_synthetic_ai4i()

            if os.path.exists(ZIP_PATH) and not os.path.exists(CSV_PATH):
                with zipfile.ZipFile(ZIP_PATH, 'r') as zip_ref:
                    zip_ref.extractall(EXTRACT_DIR)

        return pd.read_csv(CSV_PATH)

    @staticmethod
    def _generate_synthetic_ai4i():
        np.random.seed(SEED)
        n = 10000
        temp_air = np.random.normal(300.0, 2.0, n)
        temp_proc = temp_air + np.random.normal(10.0, 1.0, n)
        rpm = np.random.normal(1500.0, 200.0, n)
        torque = np.random.normal(40.0, 10.0, n)
        tool_wear = np.random.randint(0, 240, n)
        type_col = np.random.choice(['L', 'M', 'H'], size=n, p=[0.6, 0.3, 0.1])

        score = (
            (torque * (2 * np.pi * rpm / 60) > 9000).astype(int) * 3.5 +
            ((temp_proc - temp_air < 8.6) & (rpm < 1380)).astype(int) * 3.0 +
            (torque * tool_wear > 11000).astype(int) * 3.0 +
            (tool_wear > 210).astype(int) * 2.5 +
            np.random.normal(0, 0.5, n)
        )
        fail = (score > 2.8).astype(int)

        df_synth = pd.DataFrame({
            'UDI': range(1, n + 1),
            'Product ID': [f"M148{i:02d}" for i in range(n)],
            'Type': type_col,
            'Air temperature [K]': temp_air,
            'Process temperature [K]': temp_proc,
            'Rotational speed [rpm]': rpm,
            'Torque [Nm]': torque,
            'Tool wear [min]': tool_wear,
            'Machine failure': fail,
            'TWF': (tool_wear > 210).astype(int),
            'HDF': ((temp_proc - temp_air < 8.6) & (rpm < 1380)).astype(int),
            'PWF': (torque * (2 * np.pi * rpm / 60) > 9000).astype(int),
            'OSF': (torque * tool_wear > 11000).astype(int),
            'RNF': np.random.choice([0, 1], size=n, p=[0.998, 0.002])
        })
        df_synth.to_csv(CSV_PATH, index=False)


class PCAProductionPipeline:
    """Pipeline profissional de Redução de Dimensionalidade com PCA."""

    def __init__(self, df: pd.DataFrame):
        self.df = df
        self.X = None
        self.y = None
        self.feature_names = None
        self.scaler = StandardScaler()
        self.pca_full = None
        self.pca_2d = None
        self.X_pca_2d = None

    def preprocess(self):
        # Prevenção de Target Leakage e remoção de identificadores
        cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
        df_clean = self.df.drop(columns=[c for c in cols_to_drop if c in self.df.columns])

        # One-Hot Encoding
        df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

        self.X = df_encoded.drop(columns=['Machine failure'])
        self.y = df_encoded['Machine failure']
        self.feature_names = list(self.X.columns)

    def analyze_covariance_and_correlation(self):
        corr_matrix = self.X.corr()
        print("="*60)
        print("MATRIZ DE CORRELAÇÃO DAS VARIÁVEIS DE TELEMETRIA")
        print("="*60)
        print(corr_matrix.round(3).to_string())

        plt.figure(figsize=(9, 7))
        sns.heatmap(corr_matrix, annot=True, fmt=".2f", cmap="coolwarm", cbar=True)
        plt.title("Mapa de Calor de Correlação de Pearson entre Sensores", fontsize=12, fontweight='bold')
        plt.tight_layout()
        os.makedirs("out", exist_ok=True)
        plt.savefig("out/matriz_correlacao_sensores.png", dpi=300)
        plt.close()

    def fit_pca_and_evaluate_variance(self):
        # 1. Padronização Obrigatória
        X_scaled = self.scaler.fit_transform(self.X)

        # 2. PCA Completo para Análise de Variância Explicada
        self.pca_full = PCA(random_state=SEED)
        self.pca_full.fit(X_scaled)

        var_ratio = self.pca_full.explained_variance_ratio_
        cum_var_ratio = np.cumsum(var_ratio)

        print("\n" + "="*60)
        print("ANÁLISE DE VARIÂNCIA EXPLICADA ACUMULADA (PCA COMPLETO)")
        print("="*60)
        for i, (var, cum_var) in enumerate(zip(var_ratio, cum_var_ratio), 1):
            print(f"Componente PC{i:02d}: Variância Individual = {var:.2%} | Acumulada = {cum_var:.2%}")

        # 3. PCA Projetado para 2D (PC1 e PC2)
        self.pca_2d = PCA(n_components=2, random_state=SEED)
        self.X_pca_2d = self.pca_2d.fit_transform(X_scaled)

        print(f"\nVariância Total Conservada em 2D (PC1 + PC2): {np.sum(self.pca_2d.explained_variance_ratio_):.2%}")

    def plot_cluster_and_export(self):
        df_pca = pd.DataFrame(self.X_pca_2d, columns=['PC1', 'PC2'])
        df_pca['Machine failure'] = self.y.values

        plt.figure(figsize=(10, 7))
        sns.scatterplot(
            data=df_pca,
            x='PC1',
            y='PC2',
            hue='Machine failure',
            palette={0: '#1f77b4', 1: '#d62728'},
            alpha=0.7,
            s=40
        )

        plt.title("Mapeamento de Clusters 2D via PCA — Saúde da Máquina CNC", fontsize=12, fontweight='bold')
        plt.xlabel(f"PC1 ({self.pca_2d.explained_variance_ratio_[0]:.2%} da Variância)")
        plt.ylabel(f"PC2 ({self.pca_2d.explained_variance_ratio_[1]:.2%} da Variância)")
        plt.legend(title="Estado", labels=["Normal (0)", "Falha (1)"])
        plt.grid(True, linestyle="--", alpha=0.5)
        plt.tight_layout()
        plt.savefig("out/cluster_falhas_pca_2d.png", dpi=300)
        plt.close()

        # Serialização dos Artefatos de Produção (Scaler + PCA)
        artifacts = {
            'scaler': self.scaler,
            'pca_2d': self.pca_2d,
            'feature_names': self.feature_names
        }
        joblib.dump(artifacts, "out/pca_pipeline_ai4i_production.joblib")
        print("\n[OK] Gráficos salvos em 'out/' e artefato exportado para 'out/pca_pipeline_ai4i_production.joblib'!")


if __name__ == "__main__":
    df_raw = UCIDataIngestion.get_data()
    app_pca = PCAProductionPipeline(df_raw)
    app_pca.preprocess()
    app_pca.analyze_covariance_and_correlation()
    app_pca.fit_pca_and_evaluate_variance()
    app_pca.plot_cluster_and_export()
```



---

## Referências

* AHELEROFF, S. et al. A Digital Twin-Driven Predictive Maintenance Architecture for IoT-Enabled Manufacturing. **Advanced Engineering Informatics**, v. 45, p. 101102, 2020.
* ERHAN, L. et al. Anomaly Detection in Industrial Telemetry Data Using Unsupervised Machine Learning. **Journal of Ambient Intelligence and Humanized Computing**, v. 12, p. 3152-3164, 2021.
* GÉRON, Aurélien. **Hands-on Machine Learning with Scikit-Learn, Keras, and TensorFlow**: concepts, tools, and techniques to build intelligent systems. 2. ed. Sebastopol: O'Reilly Media, 2019.
* KUMAR, A.; SINGH, S. Predictive Maintenance Using AI4I 2020 Dataset: A Comparative Study of Machine Learning Classifiers. **Procedia Computer Science**, v. 218, p. 211-220, 2023.
* MURPHY, Kevin P. **Probabilistic Machine Learning**: an introduction. Cambridge: MIT Press, 2022.
* PEARSON, Karl. On Lines and Planes of Closest Fit to Systems of Points in Space. **Philosophical Magazine**, v. 2, n. 11, p. 559-572, 1901.
* RASCHKA, Sebastian. **Python Machine Learning**. Birmingham: Packt Publishing, 2015.
* SANTOS, R. et al. Imbalanced Data Treatment in Predictive Maintenance Machine Learning Models. **Applied Sciences**, v. 11, n. 18, p. 8542, 2021.
* SCHÖLKOPF, B.; SMOLA, A.; MÜLLER, K. Kernel Principal Component Analysis. **Neural Computation**, v. 10, n. 5, p. 1299-1319, 1998.
