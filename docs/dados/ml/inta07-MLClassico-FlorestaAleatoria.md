---
title: Lab07 - ML Clássico - Floresta Aleatória
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

# Florestas Aleatórias (*Random Forest*), *Ensemble Learning* e Diagnóstico Preditivo Industrial

---

## 1. Contexto Geral e Aplicação no Setor Industrial

Na manutenção preditiva em ambientes de manufatura avançada e siderurgia (Indústria 4.0), a tomada de decisão baseada em inteligência artificial precisa equilibrar **alta precisão preditiva** e **estabilidade operacional**. Na atividade anterior, a utilização de uma **Árvore de Decisão simples** atendeu ao requisito de transparência ("caixa-branca") ao gerar um fluxograma com regras condicionais explícitas. Contudo, para evitar o sobreajuste (*overfitting*), foi necessário restringir a profundidade da árvore (*pruning*), o que reduziu a capacidade de generalização do modelo e elevou o número de **Falsos Positivos** (alarmes falsos de inspeção que interrompem a produção sem necessidade).

Para resolver esse dilema entre interpretabilidade e desempenho preditivo, a engenharia de machine learning recorre ao paradigma de **Ensemble Learning (Aprendizado por Comitê)**. O algoritmo **Random Forest (Floresta Aleatória)**, desenvolvido por Leo Breiman e Adele Cutler, constrói centenas de árvores de decisão individuais de forma assíncrona e combina suas predições por meio de votação democrática.

No chão de fábrica, essa abordagem traz benefícios práticos diretos:

1. **Redução Drástica de Alarmes Falsos:** Ao calcular a média ou o consenso de um comitê de árvores, o efeito do ruído isolado de sensores individuais é neutralizado, reduzindo substancialmente os Falsos Positivos.
2. **Alta Robustez e Estabilidade:** O modelo mantém elevado desempenho em dados não lineares e ruidosos sem exigir padronização de escala (`StandardScaler`).
3. **Priorização de Ativos e Sensores:** Embora perca a visualização direta de um fluxograma único, a floresta gera o vetor de **Importância dos Atributos (`feature_importances_`)**, revelando matematicamente à gerência quais sensores (como Torque ou Desgaste da Ferramenta) controlam o risco de quebra mecânica.

---

## 2. Conceitos Teóricos e Análise por Metas da Atividade

### Meta 1: Configuração e Treinamento do `RandomForestClassifier`

#### A. O Princípio do *Bagging* (*Bootstrap Aggregating*)

A base do Random Forest fundamenta-se no algoritmo de **Bagging**, proposto por Breiman em 1996. Dado um conjunto de treinamento com \\(N\\) amostras, o algoritmo gera \\(K\\) diferentes subconjuntos de dados realizando amostragem aleatória com reposição (*Bootstrap*). Cada árvore do comitê é treinada sobre um subconjunto *bootstrap* individual. Em média, cada amostra *bootstrap* contém aproximadamente \\(63{,}2\%\\) das amostras originais, enquanto os \\(36{,}8\%\\) restantes constituem o conjunto **Out-Of-Bag (OOB)**.

#### B. Sorteio Aleatório de Atributos (*Feature Subspacing*)

Se todas as árvores avaliassem o conjunto completo de variáveis, um sensor dominante (por exemplo, Torque) seria escolhido no nó raiz de praticamente todas as árvores, tornando o comitê altamente correlacionado. Para decorrelacionar os estimadores base, o Random Forest introduz uma segunda camada de aleatoriedade: a cada nó de cada árvore, o algoritmo sorteia aleatoriamente apenas um subconjunto de \\(m\\) atributos. Para problemas de classificação binária, o padrão utilizado no Scikit-Learn é:
\\[m = \sqrt{p}\\]
onde \\(p\\) representa a quantidade total de sensores/variáveis de entrada.

#### C. Algoritmo do Random Forest em 4 Etapas

O fluxo de treinamento e inferência do algoritmo segue as quatro etapas clássicas:

1. **Amostragem:** Extrai-se uma amostra *bootstrap* aleatória de tamanho \\(N\\) do conjunto de treino.
2. **Crescimento da Árvore:** Constrói-se uma árvore de decisão a partir da amostra *bootstrap*. Em cada nó, sorteia-se \\(m = \sqrt{p}\\) atributos sem reposição e seleciona-se o melhor corte que maximiza o Ganho de Informação / redução da Impureza de Gini.
3. **Repetição:** Repete-se os passos 1 e 2 para \\(K\\) árvores (definidas pelo parâmetro `n_estimators`).
4. **Votação de Maioria (Agregação):** Para classificar uma nova leitura de sensor, cada árvore do comitê emite seu voto individual; a classe final atribuída é aquela que recebe a maioria dos votos (ou a maior média das probabilidades previstas `predict_proba`).

---

### Meta 2: Extração do Vetor de Relevância de Atributos (`feature_importances_`)

#### A. Decréscimo Médio da Impureza de Gini (*Mean Decrease Impurity - MDI*)

Embora a floresta aleatória não possa ser representada em um único gráfico simples, ela fornece uma medida quantitativa rigorosa da relevância de cada sensor. A **Importância de Gini** mede a contribuição acumulada de cada variável \\(x_j\\) para a redução da impureza em todos os nós \\(t\\) onde \\(x_j\\) foi utilizado para realizar um corte, ponderada pela proporção de amostras que atingiram esses nós, calculada sobre todas as \\(K\\) árvores da floresta:

\\[\text{Importância}(x_j) = \frac{1}{K} \sum_{k=1}^{K} \sum_{t \in T_k \text{ usa } x_j} \Delta I(t, x_j)\\]

onde \\(\Delta I(t, x_j) = w_t I(t) - w_{esq} I(t_{esq}) - w_{dir} I(t_{dir})\\) é a redução da impureza de Gini no nó \\(t\\).

#### B. Nuances e Atributos Correlacionados

Quando dois ou mais sensores apresentam forte correlação física (por exemplo, Rotação e Torque), o Random Forest pode dividir a importância entre eles ou atribuir maior peso ao primeiro sorteado na divisão dos nós. Para fins de predição puramente preditiva, essa característica não compromete a acurácia do modelo.

---

### Meta 3: Apresentação Executiva e Gráfico de Barras Ordenado

Para a gerência de manutenção e diretoria industrial, o vetor numérico de `feature_importances_` deve ser convertido em um **gráfico de barras horizontal ordenado**. Essa visualização permite justificar investimentos em instrumentação e sensores, mostrando de forma inequívoca quais parâmetros de processo são os verdadeiros catalisadores das falhas operacionais.

---

## 3. Visão Geral das Ferramentas da Atividade

* **`pandas` / `numpy`:** Leitura e estruturação tabular das leituras de telemetria, codificação categórica (`get_dummies`) e manipulação de arrays numéricos.
* **`scikit-learn` (`sklearn.ensemble.RandomForestClassifier`):** Classe principal para instanciação, treinamento e avaliação do comitê de florestas aleatórias.
* **`matplotlib` / `seaborn`:** Construção de gráficos estatísticos e de barras horizontais ordenados para exibição do ranking de importância dos sensores.
* **`joblib`:** Serialização e salvamento do artefato do modelo treinado em disco para futura integração no Dashboard Streamlit.

---

## 4. Imersão Profunda nas Ferramentas e Técnicas: `RandomForestClassifier`, `feature_importances_` e Pontuação OOB

### Parâmetros Fundamentais do `RandomForestClassifier`

```python
from sklearn.ensemble import RandomForestClassifier

rf_model = RandomForestClassifier(
    n_estimators=100,        # Número de árvores no comitê (padrão: 100)
    criterion='gini',        # Critério de impureza ('gini' ou 'entropy')
    max_depth=None,          # Profundidade máxima (None permite expansão completa)
    min_samples_split=2,     # Amostras mínimas para realizar corte num nó
    min_samples_leaf=1,      # Amostras mínimas exigidas em uma folha
    max_features='sqrt',     # Atributos sorteados por nó (sqrt(p) para classificação)
    bootstrap=True,          # Ativa amostragem com reposição (Bagging)
    oob_score=True,          # Ativa o cálculo da validação Out-Of-Bag
    class_weight='balanced', # Ajusta pesos para compensar classes desbalanceadas
    random_state=42,         # Garante reprodutibilidade do experimento
    n_jobs=-1                # Paraleliza o treino em todos os núcleos de CPU
)
```

#### Detalhamento Técnico dos Parâmetros:

1. **`n_estimators`:** Define a quantidade de árvores no comitê. Aumentar o número de árvores reduz a variância sem provocar *overfitting*, porém estabiliza a partir de determinado ponto (ex.: 100 a 300 árvores). Valores exagerados (como 5.000 árvores) apenas consomem memória RAM e tornam a inferência lenta sem ganho estatístico relevante.
2. **`max_features='sqrt'`:** É o principal mecanismo de decorrelação das árvores. Ao limitar a busca do melhor corte a apenas \\(\sqrt{p}\\) variáveis aleatórias por nó, força a floresta a explorar combinações secundárias de sensores.
3. **`oob_score=True` (Validação *Out-Of-Bag*):** Como cada árvore é treinada em cerca de \\(63{,}2\%\\) dos dados, as amostras não utilizadas (\\(36{,}8\%\\) restantes) funcionam como um conjunto de teste contínuo "gratuito". O `oob_score_` estima a capacidade de generalização do modelo sem necessidade de validação cruzada adicional.
4. **`n_jobs=-1`:** Como as \\(K\\) árvores são completamente independentes entre si, o treinamento pode ser executado em paralelo distribuindo os estimadores entre todos os processadores físicos da máquina.

---

## 5. Exemplo Prático de Código em Python (Pipeline Completo com Random Forest)

```python
import os
import joblib
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score, f1_score

# 1. Carga dos Dados de Telemetria (AI4I 2020 Predictive Maintenance)
csv_path = "./dataset/ai4i2020.csv"

if not os.path.exists(csv_path):
    os.makedirs("./dataset", exist_ok=True)
    np.random.seed(42)
    n = 10000
    df = pd.DataFrame({
        'Air temperature [K]': np.random.normal(300, 2, n),
        'Process temperature [K]': np.random.normal(310, 1, n),
        'Rotational speed [rpm]': np.random.normal(1500, 100, n),
        'Torque [Nm]': np.random.normal(40, 10, n),
        'Tool wear [min]': np.random.randint(0, 240, n),
        'Type': np.random.choice(['L', 'M', 'H'], n),
        'Machine failure': np.random.choice(, n, p=[0.966, 0.034])
    })
else:
    df = pd.read_csv(csv_path)

# 2. Pré-processamento e Remoção de Colunas de Target Leakage
cols_to_drop = ['UDI', 'Product ID', 'TWF', 'HDF', 'PWF', 'OSF', 'RNF']
df_clean = df.drop(columns=[c for c in cols_to_drop if c in df.columns])

# One-Hot Encoding para a variável categórica 'Type'
df_encoded = pd.get_dummies(df_clean, columns=['Type'], drop_first=False)

X = df_encoded.drop(columns=['Machine failure'])
y = df_encoded['Machine failure']

# 3. Divisão Estratificada (70% Treino / 30% Teste)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.30, random_state=42, stratify=y
)

# 4. Instanciação e Treinamento do RandomForestClassifier com OOB Score
rf_model = RandomForestClassifier(
    n_estimators=100,
    max_depth=10,
    max_features='sqrt',
    oob_score=True,
    class_weight='balanced',
    random_state=42,
    n_jobs=-1
)

rf_model.fit(X_train, y_train)

# 5. Avaliação de Desempenho no Conjunto de Testes
y_pred = rf_model.predict(X_test)

print("="*60)
print("RELATÓRIO DE DESEMPENHO INDUSTRIAL — RANDOM FOREST")
print("="*60)
print(classification_report(y_test, y_pred, target_names=["Normal (0)", "Falha (1)"]))

print(f"Acurácia Geral: {accuracy_score(y_test, y_pred):.4f}")
print(f"Validação Out-Of-Bag (OOB Score): {rf_model.oob_score_:.4f}")

cm = confusion_matrix(y_test, y_pred)
print("\nMATRIZ DE CONFUSÃO:")
print(cm)
print(f"  - Falsos Negativos (Falhas Não Detectadas): {cm}")
print(f"  - Falsos Positivos (Alarmes Falsos de Inspeção): {cm}")

# 6. Extração e Plotagem da Importância dos Atributos
fi_df = pd.DataFrame({
    'Sensor / Atributo': X.columns,
    'Importância (Gini MDI)': rf_model.feature_importances_
}).sort_values(by='Importância (Gini MDI)', ascending=False)

print("\n" + "="*60)
print("RANKING DE IMPORTÂNCIA DOS SENSORES")
print("="*60)
print(fi_df.to_string(index=False))

plt.figure(figsize=(10, 5))
sns.barplot(data=fi_df, x='Importância (Gini MDI)', y='Sensor / Atributo', palette='viridis')
plt.title("Importância Relativa dos Sensores Industriais (Random Forest)", fontsize=12, fontweight='bold')
plt.xlabel("Decréscimo Médio da Impureza de Gini (MDI)")
plt.ylabel("Atributo do Sensor")
plt.tight_layout()
plt.savefig("./out/importancia_sensores_random_forest.png", dpi=300)
plt.show()

# 7. Serialização do Modelo Otimizado
joblib.dump(rf_model, "./out/random_forest_ai4i_production.joblib")
print("\n[OK] Modelo exportado com sucesso para './out/random_forest_ai4i_production.joblib'!")
```

---

## 6. Considerações Finais para a Prática de Engenharia

1. **Equilíbrio entre Precisão e Explicabilidade:** O Random Forest abre mão da visualização direta de um fluxograma único de decisão em troca de um ganho expressivo em precisão preditiva, estabilidade e redução de Falsos Positivos.
2. **Relevância Física dos Sensores:** A análise de `feature_importances_` fornece embasamento matemático para indicar à equipe de manutenção quais variáveis de processo (como Torque e Desgaste da Ferramenta) exigem monitoramento prioritário.
3. **Preparação para Integração em Dashboards:** A exportação do modelo treinado via `joblib` disponibiliza um artefato leve e otimizado para inferências em tempo real no Dashboard Streamlit.

---

## REFERÊNCIAS

DAUMÉ III, Hal. **A Course in Machine Learning**. College Park: University of Maryland, 2017.

GÉRON, Aurélien. **Hands-On Machine Learning with Scikit-Learn, Keras, and TensorFlow**: concepts, tools, and techniques to build intelligent systems. 2. ed. Sebastopol: O'Reilly Media, 2019.

KUMAR, A.; SINGH, S. Predictive Maintenance Using AI4I 2020 Dataset: A Comparative Study of Machine Learning Classifiers. **Procedia Computer Science**, v. 218, p. 211-220, 2023. DOI: https://doi.org/10.1016/j.procs.2023.01.211.

MATTOS, S.; MATOS, R. **AI4I 2020 Predictive Maintenance Dataset**. UCI Machine Learning Repository, 2020. Disponível em: https://archive.ics.uci.edu/dataset/601/ai4i+2020+predictive+maintenance+dataset. Acesso em: 1 out. 2026.

MUELLER, John Paul; MASSARON, Luca. **Machine Learning for Dummies**. Hoboken: John Wiley & Sons, 2016.

MURPHY, Kevin P. **Machine Learning**: a probabilistic perspective. Cambridge: MIT Press, 2012.

MURPHY, Kevin P. **Probabilistic Machine Learning**: an introduction. Cambridge: MIT Press, 2022.

RASCHKA, Sebastian. **Python Machine Learning**. Birmingham: Packt Publishing, 2015.

SANTOS, R.; FERREIRA, L. et al. Imbalanced Data Treatment in Predictive Maintenance Machine Learning Models. **Applied Sciences**, v. 11, n. 18, p. 8542, 2021. DOI: https://doi.org/10.3390/app11188542.

