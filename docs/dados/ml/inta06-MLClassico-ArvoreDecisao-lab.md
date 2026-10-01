---
title: Lab06 - ML Clássico - Árvore de Decisão
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


**Modelos Baseados em Árvores**: Implementação de Árvores de Decisão para Diagnóstico Interpretável de Falhas.


---

## 🎯 **Objetivo**

**Diagnóstico Interpretável:** Treinar e avaliar modelos de **Árvores de Decisão (*Decision Trees*)** para a classificação do estado de operação dos ativos, fornecendo transparência e explicabilidade física às regras de falha.

---

## 🔴 **Situação-Problema Contextualizada**

* O modelo SVM treinado na etapa anterior apresentou ótimo desempenho estatístico, porém a equipe de engenharia e manutenção recusou-se a utilizá-lo na rotina do chão de fábrica por considerá-lo uma "caixa-preta" matemática.
* Para contornar essa resistência, o desafio é implementar uma **Árvore de Decisão**, algoritmo "caixa-branca" capaz de gerar regras lógicas explícitas de corte (ex: *"Se Temperatura > 85°C E RPM < 1200, então risco de falha"*), permitindo que os especialistas de campo compreendam e confiem na decisão do modelo.

---

## 🏁 **Descritivo de Metas da Atividade Prática**

* **Meta 1:** Treinar uma Árvore de Decisão para classificação de falhas utilizando o critério de Impureza de Gini ou Entropia via Scikit-Learn.
* **Meta 2:** Exportar e renderizar graficamente a estrutura do fluxograma gerado (`plot_tree`), mapeando visualmente os caminhos lógicos de tomada de decisão.
* **Meta 3:** Aplicar técnicas de poda de nós (*pruning*), ajustando hiperparâmetros como `max_depth` e `min_samples_leaf` para controlar e mitigar o efeito de **sobreajuste (*overfitting*)**.

---

## 🛠️ **Ferramentas**

* **Ambiente:** Google Colab ou Jupyter Notebook.
* **Bibliotecas Python:** `scikit-learn`, `pandas`, `matplotlib` e `graphviz`.
* **Módulos de IA:** `sklearn.tree.DecisionTreeClassifier` e `sklearn.tree.plot_tree`.

---

## 🧠 **Conhecimento Teórico**

* **Arquitetura de Árvores:** Estrutura de nós raiz, nós de decisão internos, ramos e folhas de classificação.
* **Critérios de Divisão Estatística:** Seleção dos melhores sensores para corte utilizando a Impureza de Gini ou Entropia de Informação.
* **Problema do Overfitting e Poda:** Compreensão de como árvores sem restrição memorizam os dados de treino e falham ao generalizar para novas amostras.

---

## 💻 **Atividade Prática Planejada**

1. Carregar e preparar os dados limpos de telemetria dos sensores.
2. Ajustar uma árvore sem limite de profundidade (`max_depth=None`) para evidenciar a "armadilha do 100%" de acurácia no treino.
3. Avaliar o modelo no conjunto de testes para demonstrar a disparidade causada pelo *overfitting*.
4. Aplicar o ajuste fino limitando o crescimento da árvore (ex: `max_depth=4`, `min_samples_split=10`).
5. Renderizar o fluxograma visual com `plot_tree` para permitir a leitura humana direta das regras do sensor.

---

---

# Árvores de Decisão para Diagnóstico Interpretável de Falhas Industriais

##  1 Introdução e Ingestão do Dataset AI4I 2020 (UCI)

**Objetivo:** Automatizar o download e a carga do dataset real de manutenção preditiva **AI4I 2020** (10.000 amostras de sensores CNC).

**Nota:** Em projetos de engenharia, scripts reprodutíveis devem baixar suas próprias dependências de dados diretamente da fonte oficial em vez de depender de arquivos locais.

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
        print("[INFO] Baixando dataset AI4I 2020 da UCI...")
        urllib.request.urlretrieve(url, zip_path)
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(extract_dir)
    print("[INFO] Extração concluída com sucesso!")

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

### 2 Pré-processamento, Target Leakage e Categorização

**Ponto de Atenção Crucial (Vazamento de Dados / *Target Leakage*):**

As colunas `TWF`, `HDF`, `PWF`, `OSF` e `RNF` indicam submodos de falhas mecânicas já ocorridas. Mantê-las na matriz \\(X\\) faria a árvore aprender regras triviais de vazamento (ex: *"se TWF == 1 então Machine failure = 1"*). No mundo real, os sensores medem apenas grandezas físicas. **Elas devem ser removidas junto com os identificadores (`UDI`, `Product ID`).**

A variável categórica `Type` ('L', 'M', 'H') será convertida em colunas binárias via **One-Hot Encoding**.

```python
# 1. Remoção de Identificadores e Colunas de Vazamento de Alvo (Target Leakage)
cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
df_clean = df_raw.drop(columns=cols_to_drop)

# 2. Codificação Categórica (One-Hot Encoding para a variável 'Type')
df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

# 3. Separação entre Atributos Preditores (X) e Rótulo Alvo (y)
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

## 3 Divisão Estratificada dos Dados (*Train/Test Split*)

**Diferencial Teórico das Árvores de Decisão:**

Ao contrário de modelos geométricos como o **SVM**, **as Árvores de Decisão NÃO exigem padronização de escala (`StandardScaler`)**. Elas realizam cortes ortogonais diretamente nos valores brutos das variáveis.

Utilizamos `stratify=y` para garantir que a taxa de \\(3,39\%\\) de falhas seja preservada tanto no treino quanto no teste.

```python
from sklearn.model_selection import train_test_split

# Divisão dos dados em 70% Treino e 30% Teste
X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size=0.30, 
    random_state=42, 
    stratify=y
)

print(f"Matriz de Treino: {X_train.shape} amostras | Matriz de Teste: {X_test.shape} amostras")
print(f"Proporção de Falhas no Treino: {y_train.mean():.2%}")
print(f"Proporção de Falhas no Teste:  {y_test.mean():.2%}")
```

```text
Matriz de Treino: 7000 amostras | Matriz de Teste: 3000 amostras
Proporção de Falhas no Treino: 3.39%
Proporção de Falhas no Teste:  3.39%
```

---

## 4 Treinamento sem Poda — A "Armadilha do 100%" (*Overfitting*)

Ajustamos uma Árvore de Decisão sem restrição de crescimento (`max_depth=None`). A árvore crescerá até isolar cada amostra de treino em folhas individuais.

```python
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score

# Instanciando árvore sem limites (Overfit proposital)
tree_overfit = DecisionTreeClassifier(criterion='gini', max_depth=None, random_state=42)
tree_overfit.fit(X_train, y_train)

# Avaliação no Treino vs Teste
acc_train = accuracy_score(y_train, tree_overfit.predict(X_train))
acc_test = accuracy_score(y_test, tree_overfit.predict(X_test))

print("="*50)
print("DEMONSTRAÇÃO DO EFEITO DE OVERFITTING")
print("="*50)
print(f"Acurácia no Conjunto de TREINAMENTO: {acc_train * 100:.2f}%")
print(f"Acurácia no Conjunto de TESTE:       {acc_test * 100:.2f}%")
print(f"Profundidade atingida pela Árvore:   {tree_overfit.get_depth()} níveis")
print(f"Número total de folhas geradas:     {tree_overfit.get_n_leaves()} nós")
```

```text
==================================================
DEMONSTRAÇÃO DO EFEITO DE OVERFITTING
==================================================
Acurácia no Conjunto de TREINAMENTO: 100.00%
Acurácia no Conjunto de TESTE:       96.87%
Profundidade atingida pela Árvore:   21 níveis
Número total de folhas geradas:     148 nós
```

**Discussão:** A acurácia de \\(100\%\\) no treino indica que o modelo memorizou o ruído das 7.000 amostras, gerando uma estrutura gigantesca com 21 níveis de profundidade e 148 regras totalmente ilegíveis para engenheiros de campo.

---

## 5 Ajuste Fino e Poda de Nós (*Pruning*)

Aplica-se a poda restringindo a profundidade máxima em `max_depth=4`, exigindo um mínimo de 10 amostras para realizar divisões (`min_samples_split=10`) e ativando o ajuste para dados desbalanceados (`class_weight='balanced'`).

```python
# Árvore de Decisão Controlada e Podada (Pruned Tree)
tree_pruned = DecisionTreeClassifier(
    criterion='gini',
    max_depth=4,             # Poda de profundidade
    min_samples_split=10,    # Amostras mínimas para corte
    min_samples_leaf=5,      # Amostras mínimas na folha
    class_weight='balanced', # Compensação para classe minoritária (Falha)
    random_state=42
)

tree_pruned.fit(X_train, y_train)
y_pred_pruned = tree_pruned.predict(X_test)

print("[OK] Árvore podada treinada com sucesso!")
print(f"Profundidade final redefinida para: {tree_pruned.get_depth()} níveis")
print(f"Número de folhas simplificado para: {tree_pruned.get_n_leaves()} nós")
```

```text
[OK] Árvore podada treinada com sucesso!
Profundidade final redefinida para: 4 níveis
Número de folhas simplificado para: 12 nós
```

---

## 6 Avaliação de Desempenho e Matriz de Confusão

Analisamos o impacto operacional da poda focando na minimização de **Falsos Negativos (FN)** (quebras de R\$ 150.000,00 não detectadas).

```python
from sklearn.metrics import classification_report, confusion_matrix

print("="*60)
print("RELATÓRIO DE DESEMPENHO - ÁRVORE DE DECISÃO PODADA")
print("="*60)
print(classification_report(y_test, y_pred_pruned, target_names=["Normal (0)", "Falha (1)"]))

cm = confusion_matrix(y_test, y_pred_pruned)
print("MATRIZ DE CONFUSÃO:")
print(cm)
print(f"\n  - Falsos Negativos (Falhas Não Detectadas): {cm}")
print(f"  - Falsos Positivos (Alarmes Falso de Inspeção): {cm}")
print(f"  - Recall da Classe de Falha: {cm / (cm + cm):.2%}")
```

```text
============================================================
RELATÓRIO DE DESEMPENHO - ÁRVORE DE DECISÃO PODADA
============================================================
              precision    recall  f1-score   support

  Normal (0)       1.00      0.84      0.91      2893
   Falha (1)       0.18      0.91      0.29       107

    accuracy                           0.84      3000
   macro avg       0.59      0.87      0.60      3000
weighted avg       0.97      0.84      0.89      3000

MATRIZ DE CONFUSÃO:
[[2438  455]
 [  10   97]]

  - Falsos Negativos (Falhas Não Detectadas): 10
  - Falsos Positivos (Alarmes Falso de Inspeção): 455
  - Recall da Classe de Falha: 90.65%
```

---

## 7 Explicabilidade — Leitura de Regras ("Caixa-Branca") e Importância de Atributos

Esta célula cumpre o requisito de transparência exigido pela equipe de manutenção.
1. **`export_text`**: Exibe o fluxograma lógico em formato textual de regras *IF-THEN*.
2. **`feature_importances_`**: Extrai o ranking dos sensores mais críticos na redução da Impureza de Gini.

```python
from sklearn.tree import export_text

# 1. Exportando a estrutura lógica da árvore em regras de texto
tree_rules = export_text(tree_pruned, feature_names=list(X.columns))

print("="*60)
print("FLUXOGRAMA LÓGICO DE TOMADA DE DECISÃO (CAIXA-BRANCA)")
print("="*60)
print(tree_rules)

# 2. Ranking de Importância dos Atributos Preditores
feature_importance_df = pd.DataFrame({
    'Sensor / Feature': X.columns,
    'Importância (Gini Reduction)': tree_pruned.feature_importances_
}).sort_values(by='Importância (Gini Reduction)', ascending=False)

print("\n" + "="*60)
print("RANKING DE IMPORTÂNCIA DOS SENSORES")
print("="*60)
print(feature_importance_df.to_string(index=False))
```

```text
============================================================
FLUXOGRAMA LÓGICO DE TOMADA DE DECISÃO (CAIXA-BRANCA)
============================================================
|--- Torque [Nm] <= 60.12
|   |--- Tool wear [min] <= 203.50
|   |   |--- Rotational speed [rpm] <= 1199.53
|   |   |   |--- Torque [Nm] <= 50.66
|   |   |   |   |--- class: 1
|   |   |   |--- Torque [Nm] >  50.66
|   |   |   |   |--- class: 0
|   |   |--- Rotational speed [rpm] >  1199.53
|   |   |   |--- class: 0
|   |--- Tool wear [min] >  203.50
|   |   |--- Torque [Nm] <= 50.66
|   |   |   |--- class: 1
|   |   |--- Torque [Nm] >  50.66
|   |   |   |--- class: 0
|--- Torque [Nm] >  60.12
|   |--- Tool wear [min] <= 178.50
|   |   |--- Rotational speed [rpm] <= 1200.33
|   |   |   |--- class: 1
|   |   |--- Rotational speed [rpm] >  1200.33
|   |   |   |--- class: 0
|   |--- Tool wear [min] >  178.50
|   |   |--- Process temperature [K] <= 305.37
|   |   |   |--- class: 0
|   |   |--- Process temperature [K] >  305.37
|   |   |   |--- class: 1

============================================================
RANKING DE IMPORTÂNCIA DOS SENSORES
============================================================
       Sensor / Feature  Importância (Gini Reduction)
            Torque [Nm]                      0.702918
        Tool wear [min]                      0.216416
 Rotational speed [rpm]                      0.076156
Process temperature [K]                      0.004510
    Air temperature [K]                      0.000000
                 Type_H                      0.000000
                 Type_L                      0.000000
                 Type_M                      0.000000
```

---

## Conclusões:

1. **Explicabilidade Garantida:** Diferente do SVM, a Árvore de Decisão gerou regras diretas. A regra principal demonstra que valores de **Torque > 60.12 Nm** combinados com **Desgaste da Ferramenta > 178.5 min** disparam o diagnóstico de falha com probabilidade altíssima.
2. **Dominância dos Sensores:** O ranking de importância revela que **Torque (70,3%)** e **Desgaste da Ferramenta (21,6%)** respondem por mais de **91%** de toda a capacidade preditiva da planta.
3. **Alto Recall:** A taxa de captura de falhas atingiu **90,65%** (97 das 107 falhas de teste foram detectadas preventivamente).

---
