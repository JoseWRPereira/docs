---
title: Lab01 - Introdução ao Aprendizado de Máquina
icon: fontawesome/solid/chart-line
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---

SLTINTA - [Ementa](../../ifsp-slt/dados/sltinta_ementa.md) - [Plano de Aula](../../ifsp-slt/dados/sltinta_plano_aula.md) - [Slide da aula](../../dados/slides/SLTINTA-01-intro_conceitos_iniciais-lab.pdf)

---



#

## 🎯 Objetivo

- Introdução ao Aprendizado de Máquina (Machine Learning);
- Visão Geral de um Projeto de IA:
	- estabelecendo a fase de **Definição do Escopo** e **mapeamento requisitos** na Indústria 4.0 (Manutenção Preditiva).

---

## 🔴 Situação-Problema Contextualizada

Você foi contratado como Engenheiro de IA para compor a equipe de desenvolvimento de uma grande planta siderúrgica que opera 24 horas por dia. O principal ativo da fábrica é uma estação de usinagem CNC de alto desempenho. Recentemente, a quebra inesperada do cabeçote de corte dessa máquina causou uma parada na linha de produção que durou 36 horas, gerando um prejuízo estimado em R$ 150.000,00 entre peças de reposição urgentes, ociosidade da equipe e multas por atraso na entrega dos produtos aos clientes.

A gerência de manutenção possui sensores que medem variáveis físicas da máquina a cada segundo, mas atualmente esses dados são apenas visualizados em telas isoladas e descartados. O seu desafio no semestre é interligar essa telemetria e **criar um sistema inteligente capaz de prever uma falha mecânica com antecedência**, permitindo que a equipe agende o reparo durante uma pausa planejada de produção.

---

## 🏁 Descritivo de Metas da Atividade Prática

Para dar o primeiro passo na resolução do problema da siderúrgica, sua equipe deverá atingir as seguintes metas nesta primeira sessão de laboratório:

- **Meta 1:** **Validar a integridade do histórico de telemetria fornecido pela fábrica (_dataset_)**, mapeando os tipos de dados de cada sensor e identificando se há registros nulos ou corrompidos.
    
- **Meta 2:** **Quantificar estatisticamente a distribuição das classes de falha** para entender a frequência real das quebras e a severidade do desbalanceamento dos dados.
    
- **Meta 3:** **Descobrir**, por meio de matrizes de correlação inicial, **quais sensores** (ex: temperatura ou vibração) **demonstram maior vínculo linear imediato com o comportamento de quebra da máquina**.
    
---

## 🛠️ Ferramentas

- **Ambiente de Desenvolvimento:** [Google Colab](https://colab.research.google.com/) ou [Jupyter Notebook](https://jupyter.org/) ([Python](https://www.python.org/) 3.10+).  
- **Bibliotecas Iniciais:** [pandas](https://pandas.pydata.org/), [numpy](https://numpy.org/), [matplotlib](https://matplotlib.org/) e [seaborn](https://seaborn.pydata.org/).
- **Dataset de Trabalho:** [_AI4I 2020 Predictive Maintenance Dataset_](https://archive.ics.uci.edu/dataset/601/ai4i+2020+predictive+maintenance+dataset) ([UCI Machine Learning Repository](https://archive.ics.uci.edu/)).
    
---

## 🧠 Conhecimento Teórico

- **Conceitos de IA na Indústria:** Diferença conceitual, operacional e financeira entre as estratégias de manutenção corretiva, preventiva e preditiva.
    
- **Taxonomia do Aprendizado de Máquina:** O papel do Aprendizado Supervisionado (focado em Classificação Binária para o rótulo de falha) e do Aprendizado Não Supervisionado.
    
- **Ciclo de Vida de Projetos de Dados:** Introdução à metodologia CRISP-DM, com ênfase nas fases de _Entendimento do Negócio_ e _Entendimento dos Dados_.
    
---

## 💻 Atividade Prática

**Análise Exploratória de Dados (EDA) do Ativo Industrial**

1. Carregar o arquivo CSV contendo os dados dos sensores usando `pd.read_csv()`.
    
2. Inspecionar a estrutura volumétrica e os tipos de dados das colunas (`df.info()` e `df.describe()`).
    
3. Isolar as variáveis preditoras (_Features_: temperatura ambiente, velocidade de rotação, torque, desgaste) da variável alvo (_Target_: falha da máquina).
    
4. Plotar um gráfico de barras volumétrico da variável alvo para evidenciar visualmente a raridade do evento de quebra.
    
5. Gerar um mapa de calor (_Heatmap_) de correlação de Pearson para identificar dependências numéricas entre as temperaturas do processo e o desgaste da ferramenta.
    
---
<!--
## ⚠️ Pontos de Atenção

- **A "Mágica" da IA:** Desmistificar a IA logo no primeiro dia. Mostrar aos alunos que o modelo não prevê o futuro por intuição, mas encontrando padrões matemáticos repetitivos em dados passados de sensores.
    
- **Sintaxe Inicial:** Nivelar o uso básico do Pandas. Como é a primeira semana, alguns alunos podem se confundir com a indexação de DataFrames em Python.
    
- **O Perigo do Desbalanceamento:** Certificar-se de que todos os alunos entenderam o gráfico gerado na _Meta 2_. Eles precisam registrar que falhas ocorrem em menos de 4% do tempo, pois esse fato moldará a escolha de todas as métricas de IA nas semanas seguintes.
-->

---


---

## Notebook

User o [Google Colab](https://colab.research.google.com/) ou use um [ambiente virtual](../ml/inta00-venv-lab.md) para executar a análise a seguir.


```python
import pandas as pd
```

```python
df = pd.read_csv('dataset/ai4i2020.csv')
```

# Meta 1: Validação dos dados

Validar a integridade do histórico de telemetria fornecido pela fábrica (_dataset_), mapeando os tipos de dados de cada sensor e identificando se há registros nulos ou corrompidos.

## 1. Mapeamento dos Tipos de Dados (dtypes)

O primeiro passo é garantir que o Python interpretou os dados corretamente (ex: se um sensor de temperatura está como número e a timestamp como data, e não como texto/string).


```python
# Validação do tipo de dado
df.columns
```

```python
df.info()
```



```python
import pandera.pandas as pa
```


```python
schema = pa.DataFrameSchema(
    columns={
                'UDI':                      pa.Column('int64'),
                'Product ID':               pa.Column('str'),
                'Type':                     pa.Column('str'),
                'Air temperature [K]':      pa.Column('float64'),
                'Process temperature [K]':  pa.Column('float64'), 
                'Rotational speed [rpm]':   pa.Column('int64'), 
                'Torque [Nm]':              pa.Column('float64'),
                'Tool wear [min]':          pa.Column('int64'), 
                'Machine failure':          pa.Column('int64'), 
                'TWF':                      pa.Column('int64'), 
                'HDF':                      pa.Column('int64'), 
                'PWF':                      pa.Column('int64'), 
                'OSF':                      pa.Column('int64'),
                'RNF':                      pa.Column('int64')
    }
)

```

```python
schema.validate(df)
```



## 2. Identificando Registros Nulos (Missing Values)

Sensores falham e deixam buracos. Para mapear quantos nulos existem por sensor, tanto em números absolutos quanto em porcentagem:



```python
# Identificando registros nulos

# Contagem absoluta de nulos
nulos_por_sensor = df.isnull().sum()

# Porcentagem de nulos
porcentagem_nulos = (df.isnull().sum() / len(df)) * 100

# Criando uma tabela de diagnóstico
diagnostico_nulos = pd.DataFrame({
    'Total Nulos': nulos_por_sensor,
    'Porcentagem (%)': porcentagem_nulos
}).sort_values(by='Porcentagem (%)', ascending=False)

print("\n--- Relatório de Dados Ausentes ---")
print(diagnostico_nulos)

```


## 3. Identificando Dados Corrompidos (Outliers e Anomalias)

Dados corrompidos nem sempre são nulos. Às vezes, um sensor travou em um valor impossível (ex: temperatura de $-999°C$ ou $9999°C$) ou enviou uma string corrompida.Para pegar esses "falsos dados", use o método .describe() para olhar os valores mínimos, máximos e quartis:


Como identificar os corrompidos aqui:
- Mínimos/Máximos absurdos: Um sensor de pressão que bateu $0$ ou um valor absurdamente alto do nada.
- Desvio Padrão (std) igual a zero: Significa que o sensor travou no mesmo valor para sempre.Se você quiser criar uma regra customizada para marcar dados corrompidos (ex: temperatura fora da faixa de $-10°C$ a $120°C$):


```python
# Criando uma máscara de dados corrompidos
limite_min, limite_max = 295.3, 304.5
dados_corrompidos = df[(df['Air temperature [K]'] < limite_min) | (df['Air temperature [K]'] > limite_max)]

print(f"Quantidade de registros corrompidos no sensor de temperatura: {len(dados_corrompidos)}")
```


```python
def validar_integridade(dataframe):
    validacao = pd.DataFrame({
        'Tipo de Dado': dataframe.dtypes,
        'Qtd Nulos': dataframe.isnull().sum(),
        '% Nulos': (dataframe.isnull().sum() / len(dataframe)) * 100,
        'Valores Únicos': dataframe.nunique()
    })
    return validacao

print(validar_integridade(df))
```


# Meta 2: Quantificar a distribuição das classes de falhas

Quantificar estatisticamente a distribuição das classes de falha para entender a frequência real das quebras e a severidade do desbalanceamento dos dados.
    

```python
df[(df['Machine failure'] > 0)]
```

```python
df['Machine failure'].loc[df['Machine failure'] > 0].count()
```

```python
df['Machine failure'].eq(1).sum()
```

```python
len(df['Machine failure'])
```


TWF (Tool Wear Failure): 120 casos (A ferramenta desgasta e falha/é trocada de forma crítica).

HDF (Heat Dissipation Failure): 115 casos (Superaquecimento por falta de dissipação térmica).

OSF (Overstrain Failure): 98 casos (A tensão gerada pelo produto entre torque e desgaste passa do limite).

PWF (Power Failure): 95 casos (A potência consumida cai abaixo de 3500W ou passa de 9000W).

RNF (Random Failure): 5 casos (Falhas puramente aleatórias de 0,1% de chance ocorridas no processo).


```python
mf = df['Machine failure'].eq(1).sum()/len(df['Machine failure'])
print("Falha de máquina: ", mf*100, "%")
```


```python
mf = df['TWF'].eq(1).sum()/len(df['TWF'])
print("TWF: ", mf*100, "%")
```

```python
mf = df['HDF'].eq(1).sum()/len(df['HDF'])
print("HDF: ", mf*100, "%")
```


```python
mf = df['PWF'].eq(1).sum()/len(df['PWF'])
print("PWF: ", mf*100, "%")
```


```python
mf = df['OSF'].eq(1).sum()/len(df['OSF'])
print("OSF: ", mf*100, "%")
```


```python
mf = df['RNF'].eq(1).sum()/len(df['RNF'])
print("RNF: ", mf*100, "%")
```



# Meta 3: Quais Sensores possuem vínvulo imediado com a quebra da máquina

Descobrir, por meio de matrizes de correlação inicial, quais sensores (ex: temperatura ou vibração) demonstram maior vínculo linear imediato com o comportamento de quebra da máquina.


```python
#sensores=['Air temperature [K]','Process temperature [K]', 'Rotational speed [rpm]', 'Torque [Nm]','Tool wear [min]', 'Machine failure', 'TWF', 'HDF', 'PWF', 'OSF','RNF']
sensores = {
    'Air temperature [K]': 'Temp_Ambiente_K',
    'Process temperature [K]': 'Temp_Processo_K',
    'Rotational speed [rpm]': 'Velocidade_Rotacao_RPM',
    'Torque [Nm]': 'Torque_Nm',
    'Tool wear [min]': 'Desgaste_Ferramenta_min',
    'Machine failure': 'Falha_Maquina'
}
df_analise = df[list(sensores.keys())].rename(columns=sensores)

```


```python
# Calcular a Matriz de Correlação de Pearson
matriz_corr = df_analise.corr()
matriz_corr
```





```python
# Isolar a correlação estritamente com o alvo (ordenada do maior para o menor)
corr_com_alvo = matriz_corr[['Falha_Maquina']].drop('Falha_Maquina').sort_values(by='Falha_Maquina', ascending=False)
corr_com_alvo
```




```python
print("--- Correlação Linear de Pearson com a Falha da Máquina ---")
print(corr_com_alvo)
```


```python
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
```


```python
# 5. Plotar o Heatmap da Matriz Completa
plt.figure(figsize=(8, 6))
sns.heatmap(matriz_corr, annot=True, cmap='RdBu_r', fmt=".3f", vmin=-1, vmax=1, linewidths=0.5)
plt.title('Matriz de Correlação Linear dos Sensores')
plt.tight_layout()
plt.show()
```



```python
def matriz_correlacao_linear_sensores( failure, falha ):
    sensores = {
        'Air temperature [K]': 'Temp_Ambiente_K',
        'Process temperature [K]': 'Temp_Processo_K',
        'Rotational speed [rpm]': 'Velocidade_Rotacao_RPM',
        'Torque [Nm]': 'Torque_Nm',
        'Tool wear [min]': 'Desgaste_Ferramenta_min',
        failure: falha
    }
    df_analise = df[list(sensores.keys())].rename(columns=sensores)
    matriz_corr = df_analise.corr()
    corr_com_alvo = matriz_corr[[falha]].drop(falha).sort_values(by=falha, ascending=False)
    
    plt.figure(figsize=(8, 6))
    sns.heatmap(matriz_corr, annot=True, cmap='RdBu_r', fmt=".3f", vmin=-1, vmax=1, linewidths=0.5)
    plt.title('Matriz de Correlação Linear dos Sensores')
    plt.tight_layout()
    plt.show()
```


```python
matriz_correlacao_linear_sensores('TWF', 'Falha de Desgaste de Ferramenta')
```



```python
# heat dissipation failure (HDF) - Falha de dissipação de calor
matriz_correlacao_linear_sensores('HDF', 'Falha de dissipação de calor')
```




```python
# power failure (PWF) - falha de energia
matriz_correlacao_linear_sensores('PWF', 'Falha de Energia')
```



```python
# overstrain failure (OSF) - falha de tensão excessiva
matriz_correlacao_linear_sensores('OSF', 'Falha de tensão excessiva')
```



```python
# random failures (RNF) - Falha aleatória
matriz_correlacao_linear_sensores('RNF', 'Falhas aleatorias')
```

---
