---
title: 8 - ML Clássico - Análise de Componentes Principais - PCA - Redução de Dimensionalidade
icon: fontawesome/solid/book
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

# Redução de Dimensionalidade e Análise de Componentes Principais (PCA)

---

## 1. Contextualização e a Situação-Problema na Indústria 4.0

Na engenharia moderna, a transição da manutenção corretiva para a **Manutenção Preditiva (PdM)** apoia-se na instalação de dezenas ou centenas de sensores IoT em máquinas industriais. Em um centro de usinagem CNC, por exemplo, sensores monitoram simultaneamente a temperatura ambiente, temperatura do motor, velocidade de rotação (RPM), torque de corte e taxa de desgaste da ferramenta.

Embora a abundância de telemetria seja desejável para o diagnóstico, ela cria um grande obstáculo prático: a **Maldição da Dimensionalidade** (*Curse of Dimensionality*). 

```
[ Sensor 1: Temp. Ar   ] ──┐
[ Sensor 2: Temp. Motor] ──┼─► Espaço de 5+ Dimensões ──► Desafios:
[ Sensor 3: Rotação    ] ──┤   (Dados redundantes,        - Impossível de visualizar em 2D/3D
[ Sensor 4: Torque     ] ──┤    altamente acoplados       - Custo computacional elevado
[ Sensor 5: Desgaste   ] ──┘    e correlacionados)        - Ruído acumulado
```

### O Desafio Técnico
1. **Redundância de Informação (Multicolinearidade):** Se a carga do motor aumenta, a rotação varia e a temperatura sobe de forma acoplada. Esses sensores medem, em grande parte, variações do mesmo fenômeno físico subjacente.
2. **Incapacidade de Visualização Humana:** Operadores em salas de controle conseguem interpretar facilmente gráficos bidimensionais (\\(X, Y\\)) ou tridimensionais (\\(X, Y, Z\\)). Analisar simultaneamente um espaço com 10 ou 15 dimensões é humanamente inviável.

A técnica de **Análise de Componentes Principais (PCA - *Principal Component Analysis*)** resolve esse dilema através da **Extração de Atributos**. O algoritmo comprime matematicamente o espaço vetorial multidimensional original em um número reduzido de novos eixos ortogonais (chamados **Componentes Principais**), preservando a maior quantidade possível da variância original dos dados.

---

## 2. Progressão Estatística dos Conceitos-Chave

Para compreender o PCA sem tratá-lo como uma "caixa-preta", é necessário avançar progressivamente por três fundamentos estatísticos: **Variância**, **Covariância** e **Padronização de Escala**.

```
  [1. Variância]          [2. Covariância]         [3. Padronização]
Variabilidade =       Grau de acoplamento        Igualdade de peso
  Informação             entre sensores            entre escalas
      │                        │                         │
      ▼                        ▼                         ▼
  ┌─────────────────────────────────────────────────────────────┐
  │                 Matriz de Covariância                       │
  └────────────────────────────┬────────────────────────────────┘
                               │
                               ▼
                 [ Autovalores e Autovetores ]
                               │
                               ▼
                [ Componentes Principais (PCA) ]
```

---

### Nível 1: Variância como Medida de Informação
Na ciência de dados e na teoria da informação, **variância é sinônimo de informação**. 

* **Exemplo Prático:** Imagine um sensor de temperatura instalado na máquina que apresente uma leitura rigorosamente travada em \\(25,0^\circ\text{C}\\) durante semanas (variância zero). Essa variável é inútil para prever se a máquina vai quebrar, pois não registra nenhuma oscilação do processo. Por outro lado, um sensor cuja leitura oscila entre \\(25^\circ\text{C}\\) e \\(95^\circ\text{C}\\) possui alta variância e carrega o sinal das mudanças de estado operacional do ativo.

A variância de uma variável \\(x\\) com \\(N\\) amostras é calculada por:
\\[\text{Var}(x) = \sigma_x^2 = \frac{1}{N} \sum_{i=1}^{N} (x_i - \bar{x})^2\\]

---

### Nível 2: Covariância e Redundância
Quando monitoramos múltiplos sensores, precisamos medir como eles variam **em conjunto**. A **covariância** entre duas variáveis \\(x\\) e \\(y\\) quantifica a tendência de ambas subirem ou descerem juntas.

\\[\text{Cov}(x, y) = \sigma_{xy} = \frac{1}{N} \sum_{i=1}^{N} (x_i - \bar{x})(y_i - \bar{y})\\]

* **Covariância Positiva Alta:** Quando o Torque (\\(x\\)) sobe, a Temperatura (\\(y\\)) também sobe.
* **Covariância Próxima de Zero:** As variações do sensor de Torque não possuem relação linear com as variações do sensor de Temperatura.

Quando organizamos todas as combinações possíveis de covariâncias entre os \\(D\\) sensores da fábrica, obtemos a **Matriz de Covariância (\\(\boldsymbol{\Sigma}\\))**:

\[
\boldsymbol{\Sigma} =
\begin{bmatrix}
\operatorname{Var}(x_1) & \operatorname{Cov}(x_1,x_2) & \dots & \operatorname{Cov}(x_1,x_D) \\
\operatorname{Cov}(x_2,x_1) & \operatorname{Var}(x_2) & \dots & \operatorname{Cov}(x_2,x_D) \\
\vdots & \vdots & \ddots & \vdots \\
\operatorname{Cov}(x_D,x_1) & \operatorname{Cov}(x_D,x_2) & \dots & \operatorname{Var}(x_D)
\end{bmatrix}
\]


Os elementos da **diagonal principal** representam a variância individual de cada sensor, enquanto os elementos **fora da diagonal** medem o grau de redundância entre eles. O objetivo do PCA é transformar o conjunto de dados para que todos os termos fora da diagonal tornem-se iguais a zero (eliminação da correlação).

---

### Nível 3: O Passo Crítico da Padronização (`StandardScaler`)
O PCA é extremamente sensível às escalas numéricas originais dos atributos. 

#### O Risco do Erro em Engenharia:

Considere dois sensores industriais:

* **Sensor de Rotação (RPM):** Varia na faixa de \\(1000\\) a \\(2500\text{ rpm}\\) (\\(\text{Variância} \approx 40.000\\)).
* **Sensor de Vibração (mm/s):** Varia na faixa de \\(0,1\\) a \\(5,0\text{ mm/s}\\) (\\(\text{Variância} \approx 1,2\\)).

Se o PCA for aplicado aos dados brutos sem pré-processamento, a variável Rotação dominará completamente o cálculo dos novos eixos simplesmente porque seus números são maiores em magnitude. O algoritmo interpretará a diferença de escala como "maior informação", ignorando o sensor de vibração — que é, na realidade, o parâmetro mais crítico para diagnosticar a falha no rolamento.

Para evitar essa distorção, é **obrigatório** aplicar o escalonamento `StandardScaler`, que subtrai a média \\(\mu\\) e divide pelo desvio padrão \\(\sigma\\) de cada variável, fazendo com que todas passem a ter média \\(0\\) e variância \\(1\\):

\\[z = \frac{x - \mu}{\sigma}\\]

---

## 3. A Matemática dos Componentes Principais

Após centralizar e padronizar os dados, o PCA realiza a decomposição espectral da Matriz de Covariância calculando seus **Autovalores (\\(\lambda\\))** e **Autovetores (\\(\mathbf{v}\\))**.

\\[\boldsymbol{\Sigma} \mathbf{v} = \lambda \mathbf{v}\\]

```
                Espaço Original (X1, X2)               Espaço Rotacionado (PC1, PC2)
                
                  X2 ▲                                  PC2 ▲
                     │       / PC1                          │      x x  
                     │     /                                │    x x x  
                     │   / x x                              │   x x x   
                     │ / x x x                              └─────────────► PC1
                     └───────────► X1                       (Correlação = 0)
                 (Dados Correlacionados)                   (Variância Maximizada em PC1)
```

### O Significado Geométrico e Físico

* **Autovetor (\\(\mathbf{v}\\)):** Define a **direção espacial** (a orientação do novo eixo) para a qual os dados apresentam a maior espalhamento/variância.
* **Autovalor (\\(\lambda\\)):** Quantifica a **magnitude ou quantidade de variância** contida ao longo daquela direção.

### Definição Matemática do \\(PC_k\\)

O **Primeiro Componente Principal (\\(PC_1\\))** é a combinação linear dos atributos originais padronizados que captura a maior proporção da variância total:

\\[PC_1 = w_{11} z_1 + w_{12} z_2 + \dots + w_{1D} z_D\\]

O **Segundo Componente Principal (\\(PC_2\\))** é construído na direção de maior variância remanescente, sob a restrição matemática rígida de ser estritamente **ortogonal (perpendicular)** ao \\(PC_1\\). A ortogonalidade garante que o \\(PC_2\\) trará informação totalmente nova, sem nenhuma repetição ou correlação com o \\(PC_1\\).

---

## 4. Avaliação da Compressão e Seleção de Componentes

Ao aplicar o PCA, comprimimos um espaço de \\(D\\) dimensões originais para \\(K\\) componentes (\\(K < D\\)). Para mensurar quanta informação retivemos, utiliza-se a **Razão de Variância Explicada** (*Explained Variance Ratio*).

Para o \\(j\\)-ésimo componente principal, a taxa de variância mantida é dada por:


\[
\operatorname{EVR}_j = \frac{\lambda_j}{\sum_{i=1}^{D} \lambda_i}
\]


---

### O Gráfico do Cotovelo (*Scree Plot*)
Para definir quantos componentes principais devem ser mantidos no modelo, plota-se a variância explicada acumulada em função do número de eixos.

```
  Variância Acumulada (%)
  100% ┼───────────────────────────────- - - - - - - (Info Completa)
   90% ┼─────────- - - - - - - - - ─────────► [Ponto de Retenção Ideal ~90%]
   80% ┼                     ●
   70% ┼             ●
   60% ┼     ● (Ponto de Cotovelo / Elbow)
       └─────┬───────┬───────┬───────┬───────► Número de Componentes (K)
            PC1     PC2     PC3     PC4
```

### Regras Práticas de Escolha na Engenharia:
1. **Para Visualização Gráfica e Dashboards:** Define-se \\(K = 2\\) ou \\(K = 3\\), pois permite mapear os dados em gráficos cartesianos de dispersão no Streamlit.
2. **Para Pipeline de Machine Learning (ex: SVM/Regressão):** Seleciona-se o menor número \\(K\\) de componentes que acumule entre **\\(90\%\\) e \\(95\%\\) da variância total**, eliminando o ruído de fundo sem perder capacidade preditiva.

---

## 5. Exemplo Prático de Código em Python (Pipeline Completo com Scikit-Learn)

Abaixo é apresentado o código completo e autossuficiente para ingerir dados de 5 sensores industriais, aplicar a padronização e executar a redução de dimensionalidade via PCA com interpretação gráfica.

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

# ==============================================================================
# 1. SIMULAÇÃO DE TELEMETRIA INDUSTRIAL (5 SENSORES ALTAMENTE CORRELACIONADOS)
# ==============================================================================
np.random.seed(42)
n_amostras = 1000

# Simulação de variáveis físicas com acoplamento mecânico real
temp_ambiente = np.random.normal(300, 2, n_amostras)
temp_processo = temp_ambiente + np.random.normal(10, 1, n_amostras)  # Correlacionada
rotacao_rpm = np.random.normal(1500, 100, n_amostras)
torque_nm = 40 + (1800 - rotacao_rpm) * 0.1 + np.random.normal(0, 2, n_amostras) # Inversamente correlacionada
desgaste_min = np.random.randint(0, 240, n_amostras)

# Rótulo de estado da máquina (0: Normal, 1: Risco de Falha)
falha = ((torque_nm * desgaste_min > 10000) | (temp_processo > 313)).astype(int)

df_sensores = pd.DataFrame({
    'Temp_Ambiente_K': temp_ambiente,
    'Temp_Processo_K': temp_processo,
    'Rotacao_RPM': rotacao_rpm,
    'Torque_Nm': torque_nm,
    'Desgaste_Min': desgaste_min
})

print("1. Estrutura dos Dados Brutos dos Sensores (5 Dimensões):")
print(df_sensores.head())

# ==============================================================================
# 2. PADRONIZAÇÃO OBRIGATÓRIA DOS DADOS (StandardScaler)
# ==============================================================================
scaler = StandardScaler()
X_escalonado = scaler.fit_transform(df_sensores)

# ==============================================================================
# 3. APLICAÇÃO DO PCA PARA REDUÇÃO DE 5D PARA 2D
# ==============================================================================
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_escalonado)

# Construção do DataFrame transformado
df_pca = pd.DataFrame(X_pca, columns=['PC1', 'PC2'])
df_pca['Falha'] = falha

# ==============================================================================
# 4. ANÁLISE DE VARIÂNCIA EXPLICADA
# ==============================================================================
var_explicada = pca.explained_variance_ratio_
print("\n2. Relatório de Compressão do PCA:")
print(f"  - Variância em PC1: {var_explicada*100:.2f}%")
print(f"  - Variância em PC2: {var_explicada*100:.2f}%")
print(f"  - Informação Total Retida (PC1 + PC2): {np.sum(var_explicada)*100:.2f}%")

# ==============================================================================
# 5. VISUALIZAÇÃO GRÁFICA DO CLUSTER DE FALHAS EM 2D
# ==============================================================================
plt.figure(figsize=(10, 6))
plt.scatter(
    df_pca[df_pca['Falha'] == 0]['PC1'],
    df_pca[df_pca['Falha'] == 0]['PC2'],
    c='blue', label='Operação Normal (0)', alpha=0.5, s=20
)
plt.scatter(
    df_pca[df_pca['Falha'] == 1]['PC1'],
    df_pca[df_pca['Falha'] == 1]['PC2'],
    c='red', label='Risco de Falha (1)', alpha=0.8, s=30, marker='^'
)

plt.title("Mapa Bidimensional de Saúde da Máquina (PCA: 5D -> 2D)", fontsize=12, fontweight='bold')
plt.xlabel(f"PC1 ({var_explicada*100:.1f}% da Variância Total)")
plt.ylabel(f"PC2 ({var_explicada*100:.1f}% da Variância Total)")
plt.axhline(0, color='grey', linestyle='--', linewidth=0.8)
plt.axvline(0, color='grey', linestyle='--', linewidth=0.8)
plt.legend(loc='upper right')
plt.grid(True, linestyle=':', alpha=0.6)
plt.tight_layout()
plt.show()
```

---

## 6. Interpretação dos Resultados para Engenharia

```
  ANTES DO PCA (5D)                       DEPOIS DO PCA (2D)
┌───────────────────────┐               ┌───────────────────────┐
│ - Temp_Ambiente_K     │               │ - PC1 (Comportamento  │
│ - Temp_Processo_K     │ ─── PCA ────► │       Térmico/Torque) │
│ - Rotacao_RPM         │  (Standard    │ - PC2 (Desgaste da    │
│ - Torque_Nm           │   Scaler)     │       Ferramenta)     │
│ - Desgaste_Min        │               └───────────────────────┘
└───────────────────────┘               (Agrupamento nítido de
(Dados redundantes)                     falhas visível em 2D)
```

1. **Abstração dos Eixos (\\(PC_1\\) e \\(PC_2\\)):** Os eixos \\(PC_1\\) e \\(PC_2\\) não possuem mais unidades físicas diretas como `°C` ou `RPM`. Eles passam a ser **combinações ponderadas de todos os sensores originais**. O \\(PC_1\\) pode capturar a resposta combinada de temperatura e torque, enquanto o \\(PC_2\\) isola o efeito do desgaste.
2. **Separação Geométrica de Classes:** Ao plotar o mapa \\(2\text{D}\\), percebe-se que as amostras da classe de **Falha (Vermelho)** se concentram em uma região isolada do espaço projetado. Isso possibilita aplicar algoritmos simples de classificação linear (como o SVM com kernel linear) no espaço reduzido com alto desempenho e menor custo computacional.

---

## REFERÊNCIAS

DAUMÉ III, Hal. **A Course in Machine Learning**. College Park: University of Maryland, 2017.

GÉRON, Aurélien. **Hands-On Machine Learning with Scikit-Learn, Keras, and TensorFlow**: concepts, tools, and techniques to build intelligent systems. 2. ed. Sebastopol: O'Reilly Media, 2019.

MUELLER, John Paul; MASSARON, Luca. **Machine Learning for Dummies**. Hoboken: John Wiley & Sons, 2016.

MURPHY, Kevin P. **Machine Learning**: a probabilistic perspective. Cambridge: MIT Press, 2012.

MURPHY, Kevin P. **Probabilistic Machine Learning**: an introduction. Cambridge: MIT Press, 2022.

RASCHKA, Sebastian. **Python Machine Learning**. Birmingham: Packt Publishing, 2015.

