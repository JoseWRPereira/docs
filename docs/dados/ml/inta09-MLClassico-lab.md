---
title: Lab09 - ML Clássico - Atividades
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

# Atividade Prática: Aprendizado de Máquina Aplicado à Manutenção Preditiva Industrial

## 1. Apresentação

A manutenção preditiva utiliza dados provenientes de sensores, sistemas de monitoramento e processos industriais para identificar padrões associados a falhas e condições anormais de operação.

Nesta atividade, serão utilizados diferentes conjuntos de dados (*datasets*) relacionados à manutenção preditiva, ao monitoramento de máquinas e ao controle de qualidade industrial. A proposta é desenvolver experimentos práticos de aprendizado de máquina, aplicando técnicas de classificação supervisionada e redução de dimensionalidade.

Os experimentos deverão utilizar as seguintes ferramentas:

- **SVM (Support Vector Machine):** máquinas de vetores de suporte.
- **Árvore de decisão:** modelo de classificação baseado em regras de decisão.
- **Floresta aleatória (Random Forest):** conjunto de árvores de decisão.
- **PCA (Principal Component Analysis):** análise de componentes principais para redução de dimensionalidade.

O objetivo não é estabelecer previamente qual técnica apresenta o melhor desempenho, mas investigar o comportamento dos modelos em diferentes conjuntos de dados, considerando suas características, limitações e resultados experimentais.

## 2. Objetivos da atividade

### 2.1. Objetivo geral

Aplicar e comparar técnicas de aprendizado de máquina em conjuntos de dados industriais, investigando sua utilização em problemas de diagnóstico de falhas, classificação de condições operacionais e análise de dados multivariados.

### 2.2. Objetivos específicos

1. Identificar as características, as variáveis e os objetivos de cada dataset.
2. Realizar o pré-processamento dos dados, incluindo tratamento de valores ausentes, codificação de variáveis e normalização quando necessária.
3. Aplicar SVM, árvore de decisão e floresta aleatória em problemas de classificação.
4. Utilizar PCA para investigar a estrutura dos dados e reduzir a dimensionalidade.
5. Comparar os resultados obtidos com e sem a aplicação de PCA.
6. Avaliar os modelos por meio de métricas adequadas aos problemas investigados.
7. Interpretar os resultados considerando o contexto industrial e as limitações de cada conjunto de dados.
8. Elaborar um relatório técnico com a metodologia, os experimentos, os resultados e as conclusões.

## 3. Ferramentas computacionais

Sugere-se a utilização de Python com as seguintes bibliotecas:

- `pandas`: carregamento e manipulação de dados.
- `numpy`: operações numéricas.
- `matplotlib` e `seaborn`: visualização dos dados e dos resultados.
- `scikit-learn`: pré-processamento, PCA, treinamento e avaliação dos modelos.
- `scipy` ou bibliotecas específicas de processamento de sinais, quando necessárias para os datasets de vibração.

Os experimentos podem ser realizados em Jupyter Notebook, Google Colab ou ambiente Python equivalente.

## 4. Datasets propostos

### 4.1. Dataset 1 — AI4I 2020 Predictive Maintenance Dataset

**Link:** https://archive.ics.uci.edu/static/public/601/ai4i+2020+predictive+maintenance+dataset.zip

**Descrição**

O AI4I 2020 é um conjunto de dados sintético desenvolvido para representar um cenário de manutenção preditiva industrial. Contém 10.000 registros e variáveis relacionadas às condições de operação de máquinas, como temperatura do ar, temperatura do processo, velocidade de rotação, torque e desgaste da ferramenta.

O conjunto inclui indicadores de falha e informações sobre diferentes modos de falha.

**Objetivo específico na atividade**

Estabelecer uma referência experimental para a aplicação das técnicas estudadas, utilizando dados tabulares com variáveis numéricas e categorias associadas às condições operacionais e às falhas.

**Exercícios propostos**

1. Identificar as variáveis de entrada e as variáveis-alvo.
2. Treinar modelos de classificação para prever a ocorrência de falha.
3. Investigar a relação entre as variáveis operacionais e os diferentes tipos de falha.
4. Aplicar PCA e verificar a proporção da variância explicada pelos componentes principais.
5. Comparar os resultados dos modelos antes e depois da redução de dimensionalidade.

**Questões para análise**

- Como a escala das variáveis influencia o treinamento?
- Qual é o efeito da redução de dimensionalidade sobre o desempenho dos modelos?
- A ocorrência de falhas está distribuída uniformemente entre as classes?
- Quais limitações existem ao utilizar dados sintéticos para representar situações industriais reais?

### 4.2. Dataset 2 — SECOM

**Link:** https://archive.ics.uci.edu/dataset/179/secom

**Descrição**

O SECOM contém dados de um processo industrial de fabricação de semicondutores. Possui 1.567 amostras e 591 atributos numéricos, além de rótulos relacionados à aprovação ou reprovação do processo. O conjunto apresenta valores ausentes e muitas variáveis, algumas das quais podem conter informação redundante ou pouco relevante.

**Objetivo específico na atividade**

Investigar problemas de alta dimensionalidade, tratamento de dados ausentes e redução de dimensionalidade em um processo industrial com grande quantidade de variáveis em relação ao número de amostras.

**Exercícios propostos**

1. Identificar a quantidade de valores ausentes e atributos constantes ou pouco informativos.
2. Preparar os dados para a aplicação dos modelos.
3. Aplicar PCA e analisar a variância explicada acumulada.
4. Visualizar as amostras utilizando os dois ou três primeiros componentes principais.
5. Aplicar os modelos de classificação e analisar seus resultados.
6. Investigar como diferentes quantidades de componentes principais afetam o desempenho.

**Questões para análise**

- Quais dificuldades surgem ao trabalhar com centenas de atributos?
- Como o tratamento dos valores ausentes influencia os resultados?
- Os componentes principais permitem visualizar alguma separação entre as classes?
- A variância explicada pelo PCA é suficiente para preservar a informação relevante à classificação?

### 4.3. Dataset 3 — APS Failure at Scania Trucks

**Link:** https://archive.ics.uci.edu/dataset/421/aps+failure+at+scania+trucks

**Descrição**

Este dataset reúne dados operacionais de caminhões pesados, relacionados ao sistema pneumático APS (*Air Pressure System*). O conjunto disponibiliza 60.000 registros de treinamento e 171 atributos. A tarefa original consiste em identificar falhas de componentes do sistema.

Os dados apresentam valores ausentes e forte desequilíbrio entre as classes.

**Objetivo específico na atividade**

Investigar a aplicação dos modelos de classificação em um problema industrial de maior volume, com atributos numerosos, valores ausentes e classes desbalanceadas.

**Exercícios propostos**

1. Investigar a distribuição das classes.
2. Identificar os valores ausentes e definir uma estratégia de tratamento.
3. Treinar os modelos de classificação utilizando os dados de treinamento.
4. Avaliar os resultados com matriz de confusão, precisão, recall e F1-score.
5. Aplicar PCA e investigar o efeito da redução de dimensionalidade.
6. Comparar a acurácia com métricas que considerem o desempenho na identificação de falhas.

**Questões para análise**

- Por que a acurácia pode ser insuficiente para avaliar esse problema?
- Quais são as consequências de não identificar uma falha real?
- Como a redução de dimensionalidade afeta a classificação?
- Como o custo dos falsos negativos e falsos positivos pode influenciar a avaliação de um modelo industrial?

**Observação:** o dataset original disponibiliza conjuntos específicos de treinamento e teste. Para uma avaliação rigorosa, deve-se respeitar a separação oficial e evitar utilizar os rótulos do conjunto de teste durante o desenvolvimento do modelo.

### 4.4. Dataset 4 — CWRU Bearing Dataset

**Link:** https://engineering.case.edu/bearingdatacenter/download-data-file

**Descrição**

O CWRU Bearing Dataset reúne sinais experimentais de vibração de rolamentos em condições normais e defeituosas. Os defeitos incluem alterações na pista interna, na pista externa e nos elementos rolantes.

Os arquivos apresentam sinais temporais de acelerômetros e informações relacionadas à velocidade de rotação. Há experimentos com diferentes frequências de amostragem, incluindo 12 kHz e 48 kHz em determinados ensaios.

**Objetivo específico na atividade**

Investigar como técnicas de aprendizado de máquina podem ser aplicadas ao diagnóstico de falhas mecânicas a partir de sinais de sensores, introduzindo a etapa de extração de características antes da classificação.

**Exercícios propostos**

1. Selecionar sinais representativos de diferentes condições dos rolamentos.
2. Segmentar os sinais em janelas de duração definida.
3. Extrair características temporais, como média, desvio-padrão, valor RMS e curtose.
4. Quando possível, extrair características espectrais, como energia em bandas de frequência.
5. Utilizar as características extraídas como entrada dos modelos de classificação.
6. Aplicar PCA sobre a matriz de características e investigar a estrutura dos dados.

**Questões para análise**

- Como transformar um sinal temporal em uma tabela de atributos?
- Quais características podem diferenciar condições normais e defeituosas?
- Como a escolha do tamanho das janelas afeta os resultados?
- O que se perde quando o sinal bruto é representado por um conjunto reduzido de características?

**Observação:** o CWRU não é uma tabela pronta para aplicação direta dos modelos. É necessário realizar o processamento dos sinais e definir cuidadosamente as classes e os procedimentos de separação dos dados.

### 4.5. Dataset 5 — Paderborn University Bearing Dataset

**Link:** https://mb.uni-paderborn.de/en/kat/research/bearing-datacenter/data-sets-and-download

**Descrição**

O conjunto de dados da Universidade de Paderborn contém medições de corrente elétrica e vibração sincronizadas, além de informações auxiliares como velocidade, torque, carga radial e temperatura.

A base contempla 32 condições de rolamentos: seis condições saudáveis, doze com danos artificiais e quatorze com danos reais obtidos em ensaios de vida acelerada. As medições foram realizadas sob diferentes condições operacionais.

**Objetivo específico na atividade**

Explorar a classificação de condições de saúde de componentes mecânicos utilizando diferentes tipos de sinais e atributos operacionais, além de investigar a redução de dimensionalidade em dados multivariados.

**Exercícios propostos**

1. Selecionar condições saudáveis e defeituosas para um primeiro experimento.
2. Extrair características de vibração e, quando disponíveis, de corrente elétrica.
3. Organizar os atributos em uma matriz de amostras e variáveis.
4. Aplicar PCA e examinar a variância explicada e a distribuição das amostras.
5. Treinar e avaliar os modelos de classificação.
6. Comparar experimentos com diferentes conjuntos de características e condições operacionais.

**Questões para análise**

- A combinação de vibração e corrente elétrica altera os resultados?
- Como a mudança das condições operacionais influencia a classificação?
- É possível observar agrupamentos associados às condições dos rolamentos?
- Como distinguir o aprendizado de características específicas de um ensaio da capacidade de generalização para outras condições?

**Observação:** os arquivos exigem processamento e extração de atributos. Deve-se ter atenção especial à separação entre treinamento e teste para evitar que janelas provenientes da mesma medição apareçam nos dois conjuntos.

### 4.6. Dataset 6 — NASA C-MAPSS: degradação de motores turbofan

**Link:** https://www.nasa.gov/intelligent-systems-division/discovery-and-systems-health/pcoe/pcoe-data-set-repository/

**Descrição**

O C-MAPSS é um conjunto de dados de simulação de degradação de motores turbofan. Os registros apresentam trajetórias temporais de motores, variáveis operacionais e múltiplos canais de sensores ao longo de ciclos de funcionamento.

O conjunto é tradicionalmente utilizado em estudos de prognóstico, degradação e estimativa da vida útil remanescente, conhecida como RUL (*Remaining Useful Life*).

**Objetivo específico na atividade**

Ampliar a atividade para dados temporais, investigando como as variáveis de sensores se comportam ao longo do processo de degradação e como podem ser utilizadas em problemas de classificação e redução de dimensionalidade.

**Exercícios propostos**

1. Identificar os motores, os ciclos operacionais e os canais de sensores.
2. Investigar a evolução das variáveis ao longo dos ciclos.
3. Construir atributos por janela ou definir estados de degradação a partir dos ciclos.
4. Aplicar PCA para investigar padrões de variação dos sensores ao longo do tempo.
5. Definir um problema de classificação de estados de degradação e aplicar os modelos estudados.
6. Como extensão, investigar a estimativa de RUL utilizando versões de regressão dos modelos.

**Questões para análise**

- Quais variáveis apresentam alterações ao longo da degradação?
- Como o PCA pode auxiliar na visualização da evolução operacional?
- Quais cuidados são necessários para separar motores de treinamento e teste?
- Quais diferenças existem entre classificar uma condição de falha e estimar o tempo restante até a falha?

**Observação:** o C-MAPSS é originalmente orientado a trajetórias temporais e prognóstico. Para utilizá-lo em classificação, é necessário definir previamente as classes ou estados de degradação. Para a extensão de RUL, os modelos devem ser adaptados para regressão. A página oficial da NASA informa que a disponibilidade dos arquivos pode variar; caso o acesso direto não esteja disponível, consulte os recursos do repositório de dados de prognóstico da NASA.

## 5. Condução dos experimentos

Para permitir comparações consistentes, os procedimentos deverão seguir uma metodologia comum.

### Etapa 1 — Conhecimento e preparação do dataset

Cada grupo deverá:

1. Carregar os dados e identificar seu formato.
2. Descrever as variáveis e suas unidades, quando disponíveis.
3. Identificar os atributos de entrada e a variável-alvo.
4. Investigar valores ausentes, valores constantes, duplicatas e possíveis inconsistências.
5. Verificar a distribuição das classes e identificar possíveis desequilíbrios.
6. Registrar as decisões adotadas no pré-processamento.

Para os datasets de sinais temporais, deverá ser documentada a forma de segmentação e extração de características.

### Etapa 2 — Separação dos dados

Separar os dados em conjuntos de treinamento e teste. Quando apropriado, utilizar também validação cruzada ou um conjunto de validação para ajustar os hiperparâmetros.

A separação deverá ser realizada antes de ajustar transformações que aprendem parâmetros a partir dos dados, como imputação, normalização e PCA.

Quando existirem grupos naturais, como motores, máquinas, rolamentos ou ensaios, considerar uma divisão por grupo para reduzir o risco de vazamento de dados.

Sempre que houver um conjunto oficial de teste, respeitar sua finalidade e não utilizá-lo para selecionar modelos ou ajustar hiperparâmetros.

### Etapa 3 — Pré-processamento

Definir e documentar os procedimentos adotados:

- Tratamento dos valores ausentes.
- Codificação de variáveis categóricas.
- Remoção ou tratamento de atributos constantes.
- Normalização ou padronização das variáveis, quando necessária.
- Tratamento do desequilíbrio de classes, se aplicável.

Ajustar as transformações apenas com os dados de treinamento e aplicá-las posteriormente aos dados de validação e teste.

### Etapa 4 — Aplicação dos modelos

Implementar os seguintes experimentos:

**Experimento A — SVM**

Treinar um modelo de SVM, documentando as escolhas de kernel e dos principais hiperparâmetros. Investigar a influência da escala das variáveis e, quando pertinente, comparar configurações distintas.

**Experimento B — Árvore de decisão**

Treinar uma árvore de decisão, registrando parâmetros como profundidade máxima, critério de divisão e tamanho mínimo dos nós. Examinar as regras de decisão e o comportamento do modelo.

**Experimento C — Floresta aleatória**

Treinar uma floresta aleatória, registrando o número de árvores e outros parâmetros relevantes. Investigar a estabilidade dos resultados e a importância atribuída às variáveis.

**Experimento D — PCA**

Aplicar PCA após o pré-processamento adequado. Investigar a variância explicada acumulada e selecionar diferentes quantidades de componentes para avaliar seus efeitos.

O PCA deverá ser ajustado exclusivamente com os dados de treinamento. As mesmas transformações deverão ser aplicadas aos demais conjuntos.

### Etapa 5 — Comparação com e sem PCA

Para cada modelo de classificação, realizar experimentos com os atributos originais preparados e com os atributos transformados pelo PCA.

Registrar:

- Quantidade de atributos antes e depois da transformação.
- Variância explicada pelos componentes principais.
- Métricas de desempenho.
- Tempo de treinamento, quando possível.
- Tempo de inferência, quando relevante.
- Configurações e hiperparâmetros utilizados.

O objetivo é verificar como a redução de dimensionalidade se relaciona com o desempenho, o custo computacional e a interpretação dos resultados.

### Etapa 6 — Avaliação

Para problemas de classificação, utilizar métricas adequadas às características do dataset:

- **Acurácia:** proporção total de classificações corretas.
- **Precisão:** proporção de previsões positivas que realmente são positivas.
- **Recall:** proporção de exemplos positivos identificados corretamente.
- **F1-score:** média harmônica entre precisão e recall.
- **Matriz de confusão:** detalhamento dos acertos e erros.
- **PR-AUC ou ROC-AUC:** métricas complementares, quando apropriadas ao problema.

Em conjuntos fortemente desbalanceados, apresentar a distribuição das classes e evitar conclusões baseadas somente na acurácia.

Para o PCA, registrar a variância explicada por componente e a variância explicada acumulada. Quando houver uma variável-alvo, a visualização dos componentes poderá ser colorida por classe, sem pressupor que a separação visual determine o desempenho do modelo.

## 6. Organização e registro dos resultados

Cada grupo deverá manter uma tabela de experimentos com, no mínimo, os seguintes campos:

| Dataset | Modelo | Uso de PCA | Nº de componentes | Métrica principal | Resultado |
|---|---|---|---|---|---|
| Nome do dataset | SVM | Não | — | F1-score | Preencher |
| Nome do dataset | SVM | Sim | Definir | F1-score | Preencher |
| Nome do dataset | Árvore de decisão | Não | — | F1-score | Preencher |
| Nome do dataset | Árvore de decisão | Sim | Definir | F1-score | Preencher |
| Nome do dataset | Floresta aleatória | Não | — | F1-score | Preencher |
| Nome do dataset | Floresta aleatória | Sim | Definir | F1-score | Preencher |

A tabela deverá ser complementada com os resultados das demais métricas, o tempo computacional, as configurações dos modelos e as observações relevantes.

Os experimentos deverão ser reproduzíveis, registrando as sementes aleatórias, as versões das bibliotecas e os procedimentos de divisão dos dados.

## 7. Questões gerais para discussão

Ao concluir os experimentos, responder:

1. Quais diferenças foram observadas entre os datasets quanto à quantidade de amostras, número de atributos, distribuição das classes e formato dos dados?
2. Quais dificuldades de pré-processamento foram encontradas em cada conjunto?
3. Como as métricas variaram entre os experimentos realizados?
4. Quais alterações foram observadas após a aplicação do PCA?
5. A redução de dimensionalidade alterou o custo computacional?
6. Como o desequilíbrio de classes influenciou a interpretação dos resultados?
7. Quais limitações impedem generalizar os resultados obtidos para outras máquinas ou processos industriais?
8. Quais informações adicionais seriam necessárias para implementar uma solução em um ambiente industrial real?

## 8. Entregáveis

Cada grupo deverá entregar:

1. **Notebook executável:** código comentado, pré-processamento, treinamento e avaliação.
2. **Relatório técnico:** apresentação do dataset, metodologia, experimentos e resultados.
3. **Visualizações:** distribuição das classes, análise dos atributos e gráficos do PCA.
4. **Tabela comparativa:** registro dos experimentos e das métricas.
5. **Conclusão técnica:** interpretação dos resultados, limitações e possíveis aplicações industriais.

## 9. Critérios de avaliação

| Critério | Peso sugerido |
|---|---:|
| Conhecimento e caracterização do dataset | 15% |
| Pré-processamento e prevenção de vazamento de dados | 20% |
| Implementação dos modelos e do PCA | 25% |
| Avaliação e interpretação das métricas | 20% |
| Qualidade do relatório, visualizações e reprodutibilidade | 20% |
| **Total** | **100%** |

## 10. Considerações finais

A atividade deverá demonstrar que a aplicação de aprendizado de máquina em manutenção preditiva envolve mais do que treinar modelos. É necessário compreender os dados, preparar adequadamente as variáveis, definir uma metodologia de avaliação e interpretar os resultados em função do problema industrial.

A utilização de datasets com diferentes características permitirá investigar o comportamento das técnicas em situações que envolvem dados tabulares, alta dimensionalidade, desequilíbrio de classes, sinais de vibração e degradação temporal.

As conclusões deverão ser sustentadas pelos experimentos realizados, sem pressupor previamente que uma técnica seja superior às demais. O desempenho observado dependerá do dataset, do pré-processamento, da configuração dos modelos e dos critérios de avaliação utilizados.

