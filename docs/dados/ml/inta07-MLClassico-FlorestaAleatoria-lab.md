---
title: Lab07 - ML Clássico - Floresta Aleatória
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

**Florestas Aleatórias (*Random Forest*)** e **Aprendizado por Comitê (*Ensemble Learning*)**


O objetivo aqui é superar as limitações da Árvore de Decisão, **reduzindo drasticamente os alarmes falsos** no chão de fábrica sem perder a capacidade de detectar quebras reais, treinando um comitê de múltiplas árvores com o dataset industrial **AI4I 2020 (UCI)** e extrair a **importância dos atributos (`feature_importances_`)** para comprovar numericamente à gerência quais sensores (como Torque e Desgaste da Ferramenta) dominam o risco de parada da máquina.



## 🎯 **Objetivo Principal**

**Machine Learning Clássico e Algoritmos Ensemble:** Desenvolvimento de **Florestas Aleatórias (*Random Forest*)** para predições industriais de alta performance e diagnóstico de falhas.

---

## 🔴 **Situação-Problema Contextualizada**

Embora a Árvore de Decisão simples (trabalhada na etapa anterior) tenha atendido ao requisito de transparência ("caixa-branca"), a poda necessária para torná-la legível gerou um número elevado de alarmes falsos, o que sobrecarrega a equipe de manutenção de campo. 

O desafio é evoluir para o paradigma de **Ensemble Learning (Aprendizado por Comitê)** com o **Random Forest**. Ao combinar centenas de árvores treinadas em diferentes subconjuntos de dados e atributos, reduz-se a variância do modelo, diminui-se drasticamente o número de alarmes falsos e obtém-se maior estabilidade estatística no monitoramento da planta siderúrgica.

---

## 🏁 **Descritivo de Metas da Atividade Prática**

* **Meta 1:** Configurar e treinar um classificador `RandomForestClassifier` contendo múltiplos estimadores no Scikit-Learn.
* **Meta 2:** Extrair o vetor de relevância dos atributos (`feature_importances_`) gerado intrinsecamente pelo comitê de árvores.
* **Meta 3:** Criar um gráfico de barras ordenado para revelar à gerência da fábrica qual sensor é estatisticamente o gatilho mais forte para as paradas de máquina.

---

## 🛠️ **Ferramentas e Bibliotecas**

* **Ambiente de Desenvolvimento:** Google Colab ou Jupyter Notebook.
* **Bibliotecas Python:** `scikit-learn`, `pandas`, `matplotlib` e `seaborn`.
* **Módulo de IA:** `sklearn.ensemble.RandomForestClassifier`.

---

## 🧠 **Conhecimentos Teóricos Abordados**

* **Paradigmas de Ensemble Learning:** Entendimento do conceito de *Bagging* (*Bootstrap Aggregating*) e como ele reduz a variância de classificadores individuais.
* **Mecânica da Floresta Aleatória:** Amostragem aleatória de linhas com reposição e sorteio aleatório de atributos por nó (*Feature Subspacing*), evitando a correlação entre as árvores do comitê.
* **Feature Importance:** Cálculo do decréscimo médio da impureza de Gini associado a cada sensor de entrada.

---

## ⚠️ **Pontos de Atenção**

1. **Troca da Visualização Direta pelo Ganho de Desempenho:** Diferente da Árvore de Decisão, uma floresta com 100 árvores não pode ser desenhada em um único fluxograma simples. A explicabilidade visual direta dá lugar ao ranking de `feature_importances_` em troca de um ganho expressivo em precisão.
2. **Dimensionamento de `n_estimators`:** Aumentar excessivamente o número de árvores (ex.: 5.000 árvores) não melhora indefinidamente o desempenho, apenas eleva o consumo de memória RAM e torna o modelo mais lento para futuras integrações em dashboards.


---

---


# Florestas Aleatórias (*Random Forest*) e *Ensemble Learning* para Diagnóstico de Falhas Industriais

---

## 1 Introdução e Ingestão Automatizada do Dataset AI4I 2020 (UCI)

**Objetivo da Célula:** Baixar e carregar o dataset oficial **AI4I 2020 Predictive Maintenance Dataset** da UCI (10.000 amostras de sensores de máquinas CNC).

**Conceito:** A Árvore de Decisão simples atendeu ao requisito de transparência ("caixa-branca"), mas a poda necessária para torná-la legível gerou muitos **Falsos Positivos** (alarmes falsos que interrompem a produção). Nesta semana, evoluímos para **Ensemble Learning (Aprendizado por Comitê)** com **Random Forest**, combinando centenas de árvores para atingir máxima estabilidade matemática e reduzir chamados desnecessários da manutenção.

```python
import os
import zipfile
import urllib.request
import pandas as pd
import numpy as np

# 1. Configuração do download do dataset AI4I 2020 da UCI
url = "https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip"
zip_path = "ai4i_2020.zip"
extract_dir = "dataset"
csv_path = os.path.join(extract_dir, "ai4i2020.csv")

# 2. Execução do Download e Extração
os.makedirs(extract_dir, exist_ok=True)
if not os.path.exists(csv_path):
    if not os.path.exists(zip_path):
        try:
            print("[INFO] Baixando dataset AI4I 2020 da UCI...")
            urllib.request.urlretrieve(url, zip_path)
        except Exception as e:
            print(f"[OFFLINE] Download indisponível ({e}). Carregando estrutura sintética fidedigna...")
    if os.path.exists(zip_path):
        with zipfile.ZipFile(zip_path, 'r') as zip_ref:
            zip_ref.extractall(extract_dir)

# 3. Leitura para o DataFrame
df_raw = pd.read_csv(csv_path)

print(f"Dimensão do Dataset Bruto: {df_raw.shape} linhas x {df_raw.shape} colunas")
print("\nPrimeiras 5 linhas do dataset:")
df_raw.head()
```

```text
Dimensão do Dataset Bruto: 10000 linhas x 14 colunas

Primeiras 5 linhas do dataset:
   UDI Product ID Type  Air temperature [K]  Process temperature [K]  Rotational speed [rpm]  Torque [Nm]  Tool wear [min]  Machine failure  TWF  HDF  PWF  OSF  RNF
0    1     M14860    L                298.1                    308.6                    1551         42.8                0                0    0    0    0    0    0
1    2     L47181    L                298.2                    308.7                    1408         46.3                3                0    0    0    0    0    0
2    3     L47182    L                298.1                    308.5                    1498         49.4                5                0    0    0    0    0    0
3    4     L47183    L                298.2                    308.6                    1433         39.5                7                0    0    0    0    0    0
4    5     L47184    L                298.2                    308.7                    1408         40.0                9                0    0    0    0    0    0
```

---

## 2 Pré-processamento e Prevenção de Vazamento de Alvo (*Target Leakage*)

**Ponto de Atenção Crucial (Prevenção de Target Leakage):**

As colunas `TWF`, `HDF`, `PWF`, `OSF` e `RNF` revelam os submodos das falhas que já ocorreram. Mantê-las na matriz \\(X\\) causaria **vazamento de dados**, fazendo com que a floresta aprendesse regras triviais. **Elas devem ser removidas juntamente com os identificadores (`UDI`, `Product ID`).**

A variável categórica `Type` ('L', 'M', 'H') é codificada via **One-Hot Encoding**.

```python
# 1. Remoção de Identificadores e Colunas de Vazamento de Alvo (Target Leakage)
cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
df_clean = df_raw.drop(columns=cols_to_drop)

# 2. Codificação Categórica (One-Hot Encoding)
df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

# 3. Separação de Atributos Preditores (X) e Rótulo Alvo (y)
X = df_encoded.drop(columns=['Machine failure'])
y = df_encoded['Machine failure']

print(f"Features Preditores Selecionados ({X.shape} colunas):")
print(list(X.columns))

print(f"\nDistribuição da Variável Alvo 'Machine failure':")
print(y.value_counts(normalize=True) * 100)
```

```text
Features Preditores Selecionados (8 colunas):
['Air temperature [K]', 'Process temperature [K]', 'Rotational speed [rpm]', 'Torque [Nm]', 'Tool wear [min]', 'Type_H', 'Type_L', 'Type_M']

Distribuição da Variável Alvo 'Machine failure':
Machine failure
0    96.61%
1     3.39%
Name: proportion, dtype: float64
```

---

## 3 Divisão Estratificada (*Train/Test Split*)

**Propriedade da Random Forest:**

Assim como a Árvore de Decisão simples, **a Random Forest NÃO exige padronização de escala (`StandardScaler`)**. Os cortes em cada nó testam desigualdades do tipo \\(x_j \le \text{limiar}\\), que são invariantes às escalas das outras variáveis.

```python
from sklearn.model_selection import train_test_split

# Divisão dos dados (70% Treino / 30% Teste) com ESTRATIFICAÇÃO
X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size=0.30, 
    random_state=42, 
    stratify=y
)

print(f"Amostras de Treino: {X_train.shape} | Amostras de Teste: {X_test.shape}")
print(f"Taxa de falhas no treino: {y_train.mean():.2%}")
```

```text
Amostras de Treino: 7000 | Amostras de Teste: 3000
Taxa de falhas no treino: 3.39%
```

---

## 4 Treinamento da Floresta Aleatória (*RandomForestClassifier*)

A **Random Forest** combina duas camadas de aleatoriedade:

1. **Bagging (*Bootstrap Aggregating*):** Cada árvore é treinada sobre uma amostra aleatória com reposição do conjunto de treino.
2. **Feature Subspacing:** Em cada nó de cada árvore, o algoritmo sorteia aleatoriamente apenas \\(m = \sqrt{p}\\) atributos (no nosso caso, \\(\sqrt{8} \approx 2\\) variáveis), garantindo que as árvores do comitê não fiquem correlacionadas.

```python
from sklearn.ensemble import RandomForestClassifier

# Instanciando o classificador Random Forest com 100 árvores
rf_model = RandomForestClassifier(
    n_estimators=100,         # Número de árvores no comitê
    max_depth=10,             # Profundidade máxima de cada árvore
    max_features='sqrt',      # Sorteia sqrt(p) colunas por nó
    class_weight='balanced',  # Compensação para classe desbalanceada
    random_state=42,
    n_jobs=-1                 # Utiliza todos os núcleos da CPU em paralelo
)

# Treinamento do Ensemble
rf_model.fit(X_train, y_train)
y_pred_rf = rf_model.predict(X_test)

print("[OK] Comitê de 100 Árvores (Random Forest) treinado com sucesso!")
```

```text
[OK] Comitê de 100 Árvores (Random Forest) treinado com sucesso!
```

---

## 5 Avaliação de Desempenho e Comparativo Semestral (SVM vs Árvore vs Random Forest)

Avaliamos a capacidade do **Random Forest** no conjunto de testes e comparamos seus resultados contra os modelos anteriores.

```python
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score, f1_score

print("="*60)
print("RELATÓRIO DE DESEMPENHO NO CONJUNTO DE TESTES — RANDOM FOREST")
print("="*60)
print(classification_report(y_test, y_pred_rf, target_names=["Normal (0)", "Falha (1)"]))

cm = confusion_matrix(y_test, y_pred_rf)
print("MATRIZ DE CONFUSÃO:")
print(cm)
print(f"\n  - Falsos Negativos (Falhas Não Detectadas): {cm}")
print(f"  - Falsos Positivos (Alarmes Falsos de Inspeção): {cm}")
```

```text
============================================================
RELATÓRIO DE DESEMPENHO NO CONJUNTO DE TESTES — RANDOM FOREST
============================================================
              precision    recall  f1-score   support

  Normal (0)       0.99      0.97      0.98      2893
   Falha (1)       0.51      0.82      0.65       107

    accuracy                           0.97      3000
   macro avg       0.75      0.90      0.82      3000
weighted avg       0.98      0.97      0.97      3000

MATRIZ DE CONFUSÃO:
[
 [  19   88]]

  - Falsos Negativos (Falhas Não Detectadas): 19
  - Falsos Positivos (Alarmes Falsos de Inspeção): 83
```

## Tabela Comparativa de Evolução dos Modelos Industriais:

| Modelo / Algoritmo | Acurácia Geral | Recall (Falha) | Precisão (Falha) | F1-Score (Falha) | Falsos Positivos (Alarmes Falsos) |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **SVM Kernel Linear** | 81,5% | 88,0% | 11,0% | 0,19 | 547 |
| **Árvore de Decisão Podada** | 84,0% | 90,6% | 18,0% | 0,29 | 455 |
| **Random Forest Ensemble** | **97,0%** | **82,2%** | **51,5%** | **0,65** | **83** |


**Conclusão:** 

A Árvore de Decisão simples gerava 455 alarmes falsos. O **Random Forest** manteve uma alta taxa de captura de falhas (**82,2%**) e reduziu os alarmes falsos para apenas **83**, elevando o **F1-Score para 0,65** e a **Acurácia para 97%**.

---

## 6 Extração e Plotagem da Importância dos Atributos (`feature_importances_`)

Embora um comitê de 100 árvores perca a capacidade de ter um único fluxograma desenhado em tela, ele fornece a propriedade `feature_importances_`, que calcula o **decréscimo médio da Impureza de Gini** proporcionado por cada sensor em toda a floresta.

```python
import matplotlib.pyplot as plt
import seaborn as sns

# 1. Extração das importâncias
importances = rf_model.feature_importances_
feature_names = X.columns

# 2. Criação do DataFrame ordenado
fi_df = pd.DataFrame({
    'Sensor / Atributo': feature_names,
    'Importância (Gini Reduction)': importances
}).sort_values(by='Importância (Gini Reduction)', ascending=False)

print("="*60)
print("RANKING DE IMPORTÂNCIA DOS SENSORES (RANDOM FOREST)")
print("="*60)
print(fi_df.to_string(index=False))

# 3. Plotagem Gráfica
plt.figure(figsize=(10, 5))
sns.barplot(data=fi_df, x='Importância (Gini Reduction)', y='Sensor / Atributo', palette='magma')
plt.title("Importância dos Atributos de Telemetria (Random Forest)", fontsize=12, fontweight='bold')
plt.xlabel("Decréscimo Médio de Impureza de Gini")
plt.ylabel("Variável do Sensor")
plt.tight_layout()
plt.show()
```

```text
============================================================
RANKING DE IMPORTÂNCIA DOS SENSORES (RANDOM FOREST)
============================================================
       Sensor / Atributo  Importância (Gini Reduction)
             Torque [Nm]                      0.420292
        Tool wear [min]                      0.284563
 Rotational speed [rpm]                      0.142987
Process temperature [K]                      0.073937
    Air temperature [K]                      0.067832
                 Type_M                      0.003808
                 Type_L                      0.003642
                 Type_H                      0.000207
```

**Diagnóstico de Campo:** 

O gráfico e a tabela provam de forma conclusiva à gerência da siderúrgica que **Torque (42,0%)** e **Desgaste da Ferramenta (28,5%)** somam juntos mais de **70% de toda a relevância preditiva da planta**, orientando onde a equipe de instrumentação deve investir em sensores de maior precisão.

---

## 7 Validação *Out-Of-Bag* (OOB Score) e Exportação do Modelo

O cálculo do **OOB Score** aproveita o fato de que \\(\approx 36,8\%\\) das amostras ficam de fora de cada árvore no *Bagging*, fornecendo uma pontuação de validação "gratuita" sem necessidade de um conjunto de validação separado.

```python
import joblib

# 1. Instanciando o modelo com OOB Score ativado
rf_oob = RandomForestClassifier(
    n_estimators=100,
    max_depth=10,
    oob_score=True,
    class_weight='balanced',
    random_state=42,
    n_jobs=-1
)

rf_oob.fit(X_train, y_train)

print(f"Pontuação de Validação Out-Of-Bag (OOB Score): {rf_oob.oob_score_ * 100:.2f}%")

# 2. Exportando o modelo treinado para uso no Dashboard Streamlit
joblib.dump(rf_model, "random_forest_ai4i_production.joblib")
print("[OK] Modelo serializado e salvo com sucesso em 'random_forest_ai4i_production.joblib'!")
```

```text
Pontuação de Validação Out-Of-Bag (OOB Score): 96.84%
[OK] Modelo serializado e salvo com sucesso em 'random_forest_ai4i_production.joblib'!
```

---

## **Resumo:**

1. **Sucesso do Comitê:** O *Ensemble* reduziu os Falsos Positivos de 455 para apenas 83 sem derrubar a sensibilidade de captura de falhas.
2. **Prioridade de Sensores:** A gerência agora possui dados numéricos comprovando que **Torque** e **Desgaste da Ferramenta** controlam 70% das quebras.
3. **Pronto para o Dashboard:** O arquivo `random_forest_ai4i_production.joblib` está pronto para ser carregado na interface interativa em **Streamlit**.




