---
title: Lab05 - ML Clássico e Fronteiras de Decisão
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

Machine Learning Clássico e Fronteiras de Decisão abrange o estudo e a aplicação dos algoritmos tradicionais de aprendizado de máquina supervisionado para resolver problemas de classificação e diagnóstico.

Em problemas de classificação, uma fronteira de decisão é a linha, curva ou hiperplano geométrico traçado matematicamente pelo algoritmo no espaço de atributos (por exemplo, em um gráfico de Temperatura versus Rotação). Essa fronteira divide o espaço em regiões de decisão, sendo as amostras que caem de um lado da fronteira são classificadas como operação normal (Classe 0), enquanto amostras do outro lado são rotuladas como falha mecânica (Classe 1).

O primeiro algoritmo abordado para resolução do problema de classificação é denominado **Máquinas de Vetores de Suporte (SVM)**, que busca encontrar o hiperplano separador com a margem máxima (a maior distância possível até os pontos mais próximos de cada classe, chamados de vetores de suporte).

Quando os dados de sensores não podem ser separados por uma linha reta (dados não lineares), o SVM utiliza o **Truque do Kernel (Kernel Trick)**, como os kernels Linear e RBF(*Radial Basis Function*), para projetar os dados em dimensões superiores e traçar uma fronteira divisória complexa. 


---

## 🎯 **Objetivo**
*   **Classificação de Falhas com SVM:** Aplicar o algoritmo SVM para construir fronteiras matematicamente separáveis e classificar o estado de operação dos sensores industriais.

---

## 🔴 **Situação-Problema Contextualizada**

*   Com a aquisição e a visualização de dados em dashboard, <!-- o duto de dados em pleno funcionamento (ESP32 transmitindo via MQTT e o gateway gravando no banco SQLite), --> a diretoria da siderúrgica solicita o primeiro modelo inteligente de triagem;
*   O objetivo é analisar os parâmetros de `Temperatura` e `Torque` e classificar de forma binária se a máquina está em operação segura (Classe 0) ou se entrou em zona crítica de quebra (Classe 1). Como esses dados formam agrupamentos complexos e não lineares, será utilizado o SVM com o **truque do kernel (*kernel trick*)** para traçar a melhor fronteira matemática divisória entre a saúde e a falha da máquina.

---

## 🏁 **Descritivo de Metas da Atividade Prática**

*   **Meta 1:** Importar o dataset histórico e realizar a divisão das matrizes entre conjunto de treino (\\(X_{train}, y_{train}\\)) e conjunto de teste (\\(X_{test}, y_{test}\\)).
*   **Meta 2:** Treinar o algoritmo SVM aplicando diferentes hiperparâmetros de kernel (Linear e RBF – *Radial Basis Function*) via Scikit-Learn.
*   **Meta 3:** Validar o modelo gerando a **Matriz de Confusão** e extraindo as métricas de **Precision**, **Recall** e **F1-Score**, identificando qual kernel obteve o menor índice de **Falsos Negativos**.

---

## 🛠️ **Ferramentas**

*   **Ambiente:** Google Colab ou Jupyter Notebook.
*   **Bibliotecas Python:** `scikit-learn`, `pandas`, `numpy`.
*   **Módulo de IA:** `sklearn.svm.SVC`.

---

## 🧠 **Conhecimento Teórico**

*   **Fundamentos do SVM:** Conceitos de vetores de suporte, margem máxima e hiperplano de separação.
*   **O Truque do Kernel (*Kernel Trick*):** Como projetar dados linearmente inseparáveis para dimensões superiores para torná-los separáveis (diferenças entre Kernel Linear, Polinomial e RBF(*Radial Basis Function*)).
*   **Métricas para Dados Desbalanceados:** O perigo de avaliar o modelo usando acurácia bruta em cenários onde as falhas industriais representam uma fração pequena das amostras.

---

## 💻 **Atividade Prática**

1. Importar o dataset de manutenção preditiva com Pandas e separar as *features* preditoras da coluna alvo (*target*).
2. Realizar a divisão com `train_test_split(..., test_size=0.3, stratify=y)`, utilizando o parâmetro `stratify` para preservar a proporção de classes desbalanceadas.
3. Instanciar e treinar o classificador linear: `SVC(kernel='linear')`.
4. Instanciar e treinar o classificador com kernel RBF: `SVC(kernel='rbf', C=1.0, gamma='scale')`.
5. Gerar o relatório de classificação com `classification_report` e a `confusion_matrix` para comparar o desempenho dos kernels.

---

## ⚠️ **Pontos de Atenção**

*   **Escalonamento de Recursos (*Feature Scaling*):** O SVM é extremamente sensível à escala das variáveis. Como a Rotação (RPM) está na casa dos milhares e a Vibração em decimais, o RPM dominaria o cálculo das distâncias se os dados não fossem normalizados com `StandardScaler` ou `MinMaxScaler` antes do treino.
*   **Custo Computacional:** O kernel RBF possui complexidade computacional elevada (\\(O(n^3)\\)), escalando mal em volumes massivos de dados.

---

## 🔗 **Indicação de material de apoio**

*   **Artigo Científico:** [*Zonta, T., et al. (2020). "Machine Learning for Predictive Maintenance in Industry 4.0: A Review". International Journal of Production Research*](https://www.sciencedirect.com/science/article/abs/pii/S0360835220305787).
*   **Vídeo do YouTube:** Busca recomendada por StatQuest: *"Support Vector Machines (SVM) claramente explicado"*.


---


## Roteiro Prático

#

### Classificação de Falhas Industriais com Máquinas de Vetores de Suporte (SVM)


## 1. Contextualização da Situação-Problema e Metas da Atividade

### 🔴 Situação-Problema

O objetivo é analisar variáveis preditoras físicas — como Temperatura, Torque e Velocidade de Rotação (RPM) — para classificar o estado do ativo em duas categorias:

* **Classe 0 (Operação Normal):** Condição segura de trabalho.
* **Classe 1 (Zona Crítica / Falha Iminente):** Risco de quebra mecânica, exigindo intervenção preditiva.

Como o comportamento mecânico dos sensores em condições limiares forma agrupamentos geométricos complexos e não lineares, utilizaremos o algoritmo **SVM (Support Vector Machines)** equipado com o **Truque do Kernel (*Kernel Trick*)** para traçar a melhor fronteira matemática de separação entre a saúde e a falha da máquina.

---



## 2. Pipeline Estilo *Production-Ready*

Segue a **solução de produção** construída para realizar o download e extração automatizada do arquivo ZIP da UCI, encapsular o pré-processamento e o modelo via `Pipeline` do Scikit-Learn (evitando *data leakage*), executando busca de hiperparâmetros com `GridSearchCV` e validação cruzada estratificada (`StratifiedKFold`), e salvando o artefato do modelo treinado.

```python
"""
===============================================================================
SISTEMA DE TRIAGEM PREDITIVA COM DATASET UCI AI4I 2020 - SVM CLASSIFIER
===============================================================================
Autor: Prof. José W. R. Pereira + notebooklm
Projeto: Monitoramento de Ativos CNC - Baraldis Steelworks
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

from sklearn.model_selection import train_test_split, StratifiedKFold, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.pipeline import Pipeline
from sklearn.metrics import classification_report, confusion_matrix, roc_auc_score

# 1. Configurações Globais
SEED = 42
DATASET_URL = "https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip"
ZIP_PATH = "ai4i_2020.zip"
EXTRACT_DIR = "ai4i_dataset"
CSV_PATH = os.path.join(EXTRACT_DIR, "ai4i2020.csv")


class UCIDataPipeline:
    """Classe responsável pelo download, extração e engenharia de recursos do dataset AI4I 2020."""

    @staticmethod
    def fetch_and_prepare() -> pd.DataFrame:
        if not os.path.exists(EXTRACT_DIR):
            os.makedirs(EXTRACT_DIR, exist_ok=True)

        if not os.path.exists(CSV_PATH):
            if not os.path.exists(ZIP_PATH):
                print(f"[INFO] Baixando dataset AI4I 2020 da UCI: {DATASET_URL}...")
                urllib.request.urlretrieve(DATASET_URL, ZIP_PATH)
            
            print(f"[INFO] Extraindo pacote ZIP em '{EXTRACT_DIR}'...")
            with zipfile.ZipFile(ZIP_PATH, 'r') as zip_ref:
                zip_ref.extractall(EXTRACT_DIR)
            print("[INFO] Extração concluída!")

        df = pd.read_csv(CSV_PATH)
        print(f"[OK] Dataset carregado. Formato original: {df.shape}")
        return df

    @staticmethod
    def preprocess_features(df: pd.DataFrame) -> tuple[pd.DataFrame, pd.Series]:
        """
        Remove identificadores e colunas de vazamento de alvo (Target Leakage),
        aplica One-Hot Encoding na variável 'Type' e separa X e y.
        """
        # Removendo identificadores (UDI, Product ID) e sub-tipos de falha (TWF, HDF, PWF, OSF, RNF)
        cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
        df_clean = df.drop(columns=cols_to_drop)

        # Codificação de Variáveis Categóricas (Type)
        df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

        X = df_encoded.drop(columns=['Machine failure'])
        y = df_encoded['Machine failure']

        return X, y


class IndustrialSVMOptimizer:
    """Gerencia a otimização de hiperparâmetros, treino e avaliação do modelo SVM."""

    def __init__(self, X: pd.DataFrame, y: pd.Series):
        self.X = X
        self.y = y
        self.pipeline = None
        self.best_model = None

    def run_optimization(self):
        # Divisão estratificada (70% Treino / 30% Teste)
        X_train, X_test, y_train, y_test = train_test_split(
            self.X, self.y, test_size=0.30, random_state=SEED, stratify=self.y
        )

        # Encapsulamento com Pipeline para evitar Data Leakage
        pipe = Pipeline([
            ('scaler', StandardScaler()),
            ('svm', SVC(random_state=SEED, probability=True))
        ])

        # Grade de Hiperparâmetros (Linear vs RBF)
        param_grid = [
            {
                'svm__kernel': ['linear'],
                'svm__C': [0.1, 1.0, 10.0],
                'svm__class_weight': ['balanced', None]
            },
            {
                'svm__kernel': ['rbf'],
                'svm__C': [0.1, 1.0, 10.0],
                'svm__gamma': ['scale', 'auto', 0.1],
                'svm__class_weight': ['balanced', None]
            }
        ]

        cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=SEED)

        grid_search = GridSearchCV(
            estimator=pipe,
            param_grid=param_grid,
            cv=cv,
            scoring='recall', # Foco prioritário em capturar falhas (Recall)
            n_jobs=-1,
            verbose=1
        )

        print("\n[INFO] Executando GridSearchCV para ajuste fino do SVM...")
        grid_search.fit(X_train, y_train)
        self.best_model = grid_search.best_estimator_

        # Avaliação no conjunto de testes
        y_pred = self.best_model.predict(X_test)
        y_proba = self.best_model.predict_proba(X_test)[:, 1]

        print("\n" + "="*60)
        print("MELHORES HIPERPARÂMETROS ENCONTRADOS:")
        for k, v in grid_search.best_params_.items():
            print(f"  - {k}: {v}")
        print("="*60)

        print("\nRELATÓRIO DE DESEMPENHO NO CONJUNTO DE TESTES:")
        print(classification_report(y_test, y_pred, target_names=["Normal (0)", "Falha (1)"]))

        cm = confusion_matrix(y_test, y_pred)
        print("MATRIZ DE CONFUSÃO:")
        print(cm)
        print(f"  - Falsos Negativos (Risco de Quebra R$ 150k): {cm[1, 0]}")
        print(f"  - Falsos Positivos (Inspecionar/Alarme Falso): {cm[0, 1]}")
        print(f"  - ROC-AUC Score: {roc_auc_score(y_test, y_proba):.4f}")

        # Serialização do Modelo Otimizado
        joblib.dump(self.best_model, "svm_ai4i_production.joblib")
        print("\n[OK] Modelo exportado com sucesso para 'svm_ai4i_production.joblib'.")


if __name__ == "__main__":
    df_raw = UCIDataPipeline.fetch_and_prepare()
    X, y = UCIDataPipeline.preprocess_features(df_raw)
    optimizer = IndustrialSVMOptimizer(X, y)
    optimizer.run_optimization()
```

---

## 3. Passo a Passo

Agora vamos construir a solução passo a passo de forma didática, detalhando a extração do arquivo ZIP, a engenharia de recursos para evitar vazamento de dados, a matemática do SVM e a interpretação crítica do modelo.

---

### Passo 1: Download e Extração do Dataset AI4I 2020 da UCI

O dataset oficial está hospedado no Repositório de Machine Learning da UCI em formato ZIP (`ai4i+2020+predictive+maintenance+dataset.zip`). Usamos as bibliotecas `urllib.request` e `zipfile` para automatizar a ingestão no projeto.

```python
import urllib.request
import zipfile
from pathlib import Path

# 1. Definição da URL e da pasta de destino 'dataset'
url = "https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip"
diretorio_destino = Path("./dataset")

# Cria o diretório 'dataset' caso ele não exista
diretorio_destino.mkdir(parents=True, exist_ok=True)

# 2. Definição do caminho para o arquivo .zip e do CSV final
caminho_zip = diretorio_destino / "download.zip"
csv_path = diretorio_destino / "dataset.csv"

# 3. Baixa o arquivo .zip para dentro da pasta 'dataset'
print(f"Baixando o arquivo .zip em: {caminho_zip.resolve()}...")
urllib.request.urlretrieve(url, caminho_zip)
print("Download concluído!")

# 4. Extrai o arquivo .zip e renomeia o CSV para 'dataset.csv'
with zipfile.ZipFile(caminho_zip, 'r') as zip_ref:
    # Identifica o nome do arquivo .csv presente dentro do pacote .zip
    arquivos_no_zip = zip_ref.namelist()
    arquivo_csv_interno = next((f for f in arquivos_no_zip if f.endswith('.csv')), None)
    
    if arquivo_csv_interno:
        # Extrai apenas o arquivo CSV interno para a pasta 'dataset'
        zip_ref.extract(arquivo_csv_interno, path=diretorio_destino)
        
        # Caminho onde o arquivo foi extraído originalmente (ex: ai4i2020.csv)
        caminho_extraido = diretorio_destino / arquivo_csv_interno
        
        # Renomeia para 'dataset.csv'
        caminho_extraido.replace(csv_path)
        print(f"Arquivo extraído e renomeado para: {csv_path.resolve()}")
    else:
        print("Nenhum arquivo com extensão .csv foi encontrado dentro do .zip.")

# 5. Leitura do arquivo CSV para um DataFrame do Pandas
df = pd.read_csv(csv_path)

print("--- PASSO 1: Inspeção dos Dados Brutos do AI4I 2020 ---")
print(f"Dimensão do Dataset: {df.shape[0]} linhas x {df.shape[1]} colunas")
print("\nColunas do Dataset:")
print(df.columns.tolist())
print("\nPrimeiras 5 linhas:")
print(df.head())
```

* **Por que automação de download?** Em pipelines de engenharia de dados, scripts reprodutíveis devem baixar suas próprias dependências de dados diretamente da fonte oficial em vez de depender de downloads manuais do usuário.

---

### Passo 2: Pré-processamento e Prevenção de Vazamento de Dados (*Target Leakage*)

Antes de treinar qualquer modelo, devemos analisar criticamente as 14 colunas do dataset AI4I 2020:

1. `UDI`: Identificador sequencial da linha (remover).
2. `Product ID`: Código do produto como "M14860" (remover).
3. `Type`: Variante de qualidade da máquina ('L', 'M', 'H') (aplicar One-Hot Encoding).
4. `Air temperature [K]`: Temperatura do ar ambiente em Kelvin (manter em $X$).
5. `Process temperature [K]`: Temperatura do processo em Kelvin (manter em $X$).
6. `Rotational speed [rpm]`: Velocidade de rotação do eixo em RPM (manter em $X$).
7. `Torque [Nm]`: Torque aplicado em Newton-metro (manter em $X$).
8. `Tool wear [min]`: Tempo de desgaste da ferramenta em minutos (manter em $X$).
9. `Machine failure`: Alvo binário geral — 0 para Normal, 1 para Falha (nosso vetor $y$).
10. `TWF`, `HDF`, `PWF`, `OSF`, `RNF`: Modos específicos de falha (Desgaste de Ferramenta, Dissipação de Calor, Energia, Sobrecarga e Falhas Aleatórias).

```python
# 1. Identificando e removendo colunas inadequadas para treinamento
cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
df_clean = df.drop(columns=cols_to_drop)

# 2. Aplicando One-Hot Encoding na variável categórica 'Type'
df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

# 3. Separando a Matriz de Atributos (X) e o Vetor Alvo (y)
X = df_encoded.drop(columns=['Machine failure'])
y = df_encoded['Machine failure']

print("--- PASSO 2: Separação de Parâmetros e Limpeza ---")
print(f"Features finais selecionadas ({X.shape[1]} colunas): {list(X.columns)}")
print(f"\nDistribuição da Variável Alvo 'Machine failure':")
print(y.value_counts(normalize=True) * 100)
X.head()
```

* **⚠️ O PERIGO DO *TARGET LEAKAGE*:** As colunas `TWF`, `HDF`, `PWF`, `OSF` e `RNF` são indicadores diretos de que uma falha específica já ocorreu. Se mantivermos essas colunas na matriz $X$, o algoritmo simplesmente aprenderá a regra trivial de que `se TWF == 1 então Machine failure = 1`, obtendo 100% de acurácia artificial. No mundo real, os sensores não sabem com antecedência qual modo de falha vai ocorrer — eles medem apenas as variáveis físicas. Remover essas colunas é **imprescindível** para garantir a validade do projeto.

---

### Passo 3: Divisão Estratificada dos Dados (*Train/Test Split*)

Separamos $70\%$ das amostras para treinamento e $30\%$ para teste mantendo a proporção de classes desbalanceadas.

```python
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size=0.30, 
    random_state=42, 
    stratify=y # Garante a proporção exata de ~3.39% de falhas no treino e no teste
)

print(f"Amostras de Treino: {X_train.shape[0]} | Amostras de Teste: {X_test.shape[0]}")
print(f"Falhas no Treino: {y_train.sum()} ({y_train.mean():.2%})")
print(f"Falhas no Teste:  {y_test.sum()} ({y_test.mean():.2%})")
```

* **Por que usar `stratify=y`?** 
    
    Apenas $\approx 3,39\%$ das 10.000 amostras do AI4I 2020 representam falhas reais ($339$ falhas no total). Sem a estratificação, uma amostragem aleatória poderia concentrar quase todas as falhas no treino, deixando o conjunto de testes sem amostras suficientes da classe 1 para uma validação confiável.

---

### Passo 4: Escalonamento de Atributos (*Feature Scaling*)

Padronizamos as escalas numéricas utilizando o `StandardScaler`.

```python
from sklearn.preprocessing import StandardScaler

scaler = StandardScaler()

# Ajustando o escalonador e transformando a matriz de Treino
X_train_scaled = scaler.fit_transform(X_train)

# Transformando a matriz de Teste usando a média e desvio do Treino
X_test_scaled = scaler.transform(X_test)

# Visualização dos parâmetros de treino após o ajuste do escalonador
X_train_scaled
```

* **Por que o SVM exige escalonamento?** 
    A rotação (`Rotational speed`) atinge valores superiores a $2800$ RPM, enquanto as temperaturas ficam próximas de $300$ K e o torque varia entre $3.8$ e $76.6$ Nm. Como o SVM é baseado no cálculo da distância euclidiana para encontrar a margem máxima, atributos com magnitudes maiores dominariam as equações.
* O `StandardScaler` transforma os dados para média zero ($\mu = 0$) e desvio padrão unitário ($\sigma = 1$):
  $z = \frac{x - \mu}{\sigma}$

---

### Passo 5: Treinamento do SVM com Kernel Linear e Balanceamento de Classe

Treinamos nosso modelo de linha de base com o Kernel Linear ativando a compensação de desbalanceamento de classes (`class_weight='balanced'`).

```python
from sklearn.svm import SVC

# Instanciando o SVM Linear com pesos balanceados
svm_linear = SVC(kernel='linear', C=1.0, class_weight='balanced', random_state=42)
svm_linear.fit(X_train_scaled, y_train)

# Predição no conjunto de testes
y_pred_linear = svm_linear.predict(X_test_scaled)
```

 - **`kernel='linear'`** - Função de Kernel
    - Define o tipo de fronteira matemática que o SVM usará para separar as classes no espaço de atributos. 
    - `'linear'`: O algoritmo tentará traçar uma linha reta (em 2D), um plano (em 3D) ou um hiperplano reto (em dimensões superiores) definido pela equação $w^T x + b = 0$. É ideal para dados que já são linearmente separáveis ou quando há um número muito elevado de atributos (variáveis de entrada), oferecendo um modelo mais simples, rápido e de menor custo computacional se comparado a kernels não lineares como o `'rbf'`.

- **`C=1.0`** - Parâmetro de Regularização / Custo
    - Controla a troca (*trade-off*) entre obter uma margem ampla de separação e minimizar os erros de classificação no conjunto de treinamento. 
    - `1.0`: É o valor padrão (default) do Scikit-Learn, representando um equilíbrio intermediário.
    - `C` Grande (ex: $100.0$): Penaliza severamente qualquer erro ou invasão da margem (Hard Margin). O modelo tenta classificar corretamente todas as amostras de treino, gerando margens mais estreitas. Isso pode causar ***overfitting*** se houver ruído nos dados.
    - `C` Pequeno (ex: $0.1$): É mais tolerante a pequenas violações da margem (Soft Margin). O modelo prioriza uma margem mais larga e generalizável, mesmo que cometa alguns pequenos erros no treino. Se for pequeno demais, pode causar ***underfitting***.

- **`class_weight='balanced'`** - Ponderação de Classes 
    - Ajusta automaticamente a penalidade de erro para compensar o desbalanceamento entre as classes do dataset. 
    - `'balanced'`: O Scikit-Learn calcula os pesos das classes de forma inversamente proporcional às suas frequências no conjunto de treino, utilizando a fórmula: 
    
    $$w_j = \frac{n\_amostras}{n\_classes \times n\_amostras_j}$$
    
Em dados industriais reais, a classe de falha (Classe 1) é rara (~3% dos dados) em relação à operação normal (Classe 0, ~97%). Sem esse parâmetro, o SVM tenderia a ignorar a classe minoritária. O `class_weight='balanced'` aumenta o valor de `$C$` para a classe de falha, forçando o modelo a dar muito mais atenção à detecção de quebras e elevando a métrica de Recall.


---

### Passo 6: Treinamento do SVM com Kernel RBF (*Radial Basis Function*)

Instanciamos o Kernel RBF (Gaussiano) para capturar as interações não lineares entre o torque, o desgaste da ferramenta e as temperaturas do processo.

```python
# Instanciando o SVM Não Linear (RBF)
svm_rbf = SVC(kernel='rbf', C=10.0, gamma='scale', class_weight='balanced', random_state=42)
svm_rbf.fit(X_train_scaled, y_train)

# Predição no conjunto de testes
y_pred_rbf = svm_rbf.predict(X_test_scaled)
```

* **Matemática do RBF:** 
Utiliza a distância Gaussiana para mapear a similaridade entre pares de pontos:

$K(x^{(i)}, x^{(j)}) = \exp\left(-\gamma \|x^{(i)} - x^{(j)}\|^2\right)$

  Permite traçar regiões de decisão curvas ao redor de agrupamentos de falha no espaço de sensores.

---

### Passo 7: Avaliação de Desempenho e Comparação de Métricas Industriais

Comparamos o desempenho dos dois kernels gerando as Matrizes de Confusão e os relatórios de avaliação.

```python
from sklearn.metrics import classification_report, confusion_matrix

print("==================================================")
print("EVALUAÇÃO MODELO 1: SVM KERNEL LINEAR")
print("==================================================")
print(confusion_matrix(y_test, y_pred_linear))
print(classification_report(y_test, y_pred_linear, target_names=["Normal (0)", "Falha (1)"]))

print("\n==================================================")
print("EVALUAÇÃO MODELO 2: SVM KERNEL RBF (NÃO LINEAR)")
print("==================================================")
print(confusion_matrix(y_test, y_pred_rbf))
print(classification_report(y_test, y_pred_rbf, target_names=["Normal (0)", "Falha (1)"]))
```

#### Análise Financeira e Técnica da Matriz de Confusão:

* **Falso Positivo (FP):** O modelo aponta falha em uma máquina que está normal. A consequência é uma checagem preventiva em campo (custo operacional pequeno).
* **Falso Negativo (FN):** O modelo classifica uma máquina como normal, mas ela quebra em operação. **É a parada não planejada catastrófica de R$ 150.000,00.**
* **Objetivo de Engenharia:** Minimizar rigorosamente os Falsos Negativos (FN), maximizando a métrica de **Recall** para a classe 1 (`Machine failure = 1`).

---

<!-- 
## 4. Resumo Didático dos Pontos de Atenção para a Turma

1. **Prevenção de Target Leakage:** Sempre audit do dataset antes de treinar. Colunas como `TWF`, `HDF`, `PWF`, `OSF` e `RNF` devem ser removidas, pois revelam o resultado que o modelo deveria prever com base nos sensores físicos.
2. **Desbalanceamento Severo:** Em cenários onde a classe positiva representa $< 5\%$ do total, nunca utilize acurácia isolada. Foque em **Recall**, **F1-Score** e ajuste o hiperparâmetro `class_weight='balanced'`.
3. **Escalonamento Obrigatório:** O `StandardScaler` é pré-requisito indispensável para o cálculo de distâncias do SVM. Fazer `fit` apenas no treino previne o **Vazamento de Dados (*Data Leakage*)**.
 -->
---

## Referências

* DALZOCHIO, J. et al. Predictive Maintenance in the Fourth Industrial Revolution: A Literature Review. **Computers & Industrial Engineering**, v. 142, p. 106486, 2020.
* GÉRON, Aurélien. **Hands-on Machine Learning with Scikit-Learn, Keras, and TensorFlow**: concepts, tools, and techniques to build intelligent systems. 2. ed. Sebastopol: O'Reilly Media, 2019.
* MATTOS, S.; MATOS, R. **AI4I 2020 Predictive Maintenance Dataset**. UCI Machine Learning Repository, 2020. Disponível em: <https://archive.ics.uci.edu/dataset/601/ai4i+2020+predictive+maintenance+dataset>.
* MURPHY, Kevin P. **Machine Learning**: a probabilistic perspective. Cambridge: MIT Press, 2012.
* RASCHKA, Sebastian. **Python Machine Learning**. Birmingham: Packt Publishing, 2015.

---