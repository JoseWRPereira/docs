---
title: K-Nearest Neighbors - KNN
icon: fontawesome/solid/k
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
---


# *Nearest Neighbors - KNN* (K-vizinhos mais próximos)

O KNN é um algoritmo de Machine Learning da classe de aprendizado supervisionado. 

Ele pode ser utilizado para resolver problemas de classificação e de regressão.

**KNN: Premissas**
> A proximidade entre duas evidências de um fenômeno observado, pode ser representada por uma medida de distância.

Objetos similares estão próximos uns aos outros, portanto, as características precisam ser numéricas. Assim, é calculada a distância entre um ponto sem rótulo e todos os seus K vizinhos mais próximos, e o rótulo que possuir o maior número de vizinhos é atribuído ao ponto. 

O melhor K é obtido testando valores diferentes e calculando o erro do algoritmo. O algoritmo que apresentar o menor erro, possui o melhor K.


**Exemplos de uso**

- Sistemas de recomendação: Dado um filme, encontre os K filmes mais similares;
- Classificação de notícias: Dada uma notícia, em qual categoria ela se encaixa?
- Classifiação de cliente: Dado um novo cliente, qual o grupo ele pertence dado o seu perfil?
- Sistema de busca: Dada uma nova consulta, quais notícias podem ser retornadas?


**Vantagens**

1. O KNN é fácil de entender e simples de explicar o seu funcionamento.
2. Não há a necessidade de construir um modelo, ajustar vários parâmetros ou assumir premissas adicionais.
3. O KNN é versátil. Ele pode ser usando para resolver problemas de classificação, regressão e busca.


**Desvantagens**

1. O KNN se tornar significativamente devagar quanto mais o número de exemplos e/ou preditores aumenta. Com o aumento da dimensionalidade dos dados através das colunas, o cálculo da distância fica mais demorado.
2. Em alta dimensionalidade, a distância entre os pontos podem ser distorcidas. Os mesmos pontos podem se aproximar ou se distanciar dependendo da quantidade de colunas na tabela e isso pode alterar os rótulos. O que foi classificado como A, pode ser reclassificado como B.


**Processo de treino em problema de classificação**

1. Carregue os dados
2. Defina o número K vizinhos mais próximos.
3. Para cada exemplo sem rótulo:
      1. Calcule a distância entre o ponto sem rótulo e todos os outros pontos rotulados do conjunto de dados.
      2. Encontre o K pontos mais próximos.
      3. Identifique os rótulos de cada um dos K vizinhos mais próximos.
      4. Calcule a “moda” dos K vizinhos mais próximos.
      5. Classifique o ponto sem rótulo com a moda de seus k vizinhos
mais próximos

**Cálculo de Distância**

Dados dois pontos \(P\) e \(Q\) localizados, respectivamente, nas coordenadas \((P_x,P_y)\) e \((Q_x,Q_y)\).

- Distância Euclidiana: \( d = \sqrt{ (P_x-Q_x)^2 + (P_y-Q_y)^2 } \)
- Distância de Manhattan: \( d = |P_x-Q_x| + |P_y-Q_y| \)
- Distância de Mahallanobis: \( d= \sqrt{ \frac{(P_x-Q_x)^2 + (P_y-Q_y)^2}{ \sigma_{xy}^2} } \)

---

**Referências**

1. [O que é: Distância de Mahalanobis - Aprenda estatística Fácil](https://estatisticafacil.org/glossario/o-que-e-distancia-de-mahalanobis/)


---
