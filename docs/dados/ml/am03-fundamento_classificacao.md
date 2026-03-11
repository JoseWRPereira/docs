---
title: Fundamentos do algoritmo de classificação
icon: fontawesome/solid/signs-post
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
---


# Fundamentos dos Algoritmos de Classificação

As origens históricas do aprendizado de máquina podem ser traçadas até a década de 1940, quando os pesquisadores começaram a estudar como os cérebros humanos processam informações. Uma das primeiras abordagens foi o modelo de McCulloch-Pitts (MCP), proposto por Warren McCulloch e Walter Pitts em 1943. Este modelo simplificou o funcionamento de uma célula nervosa como um portão lógico binário, onde a saída era determinada pela soma ponderada das entradas.

---

# O Algoritmo Perceptron

*   **Origem e Funcionamento:** Alguns anos após o modelo McCulloch-Pitts, Frank Rosenblatt em 1957, propôs o perceptron, que introduziu uma regra de aprendizado capaz de ajustar automaticamente os coeficientes de peso aplicados às características de entrada para decidir se um neurônio deve "disparar" ou não.
*   **Função de Ativação:** O algoritmo utiliza uma **função de degrau unitário** (Heaviside) para converter a entrada líquida em uma saída binária (-1 ou 1).
*   **Convergência:** O perceptron só tem garantia de convergência se as duas classes forem **linearmente separáveis** e a taxa de aprendizado for suficientemente pequena.

---

# Neurônios Lineares Adaptativos (Adaline)

*   **Melhoria em relação ao Perceptron:** O Adaline, proposto por Widrow e Hoff, diferencia-se por atualizar os pesos com base em uma **função de ativação linear** contínua, e não em uma função de degrau binária.
*   **Otimização e Função de Custo:** Ele introduz o conceito crucial de **função de custo**, especificamente a Soma dos Erros Quadrados (SSE), que é minimizada durante o treinamento.
*   **Gradiente Descendente:** Para encontrar os pesos que minimizam o custo, o Adaline utiliza o algoritmo de **gradiente descendente**, que acompanha a **derivada da função de custo** até atingir um mínimo local ou global.

---

# Técnicas de Otimização Avançadas

*   **Escalonamento de Características:** Algoritmos baseados em gradiente, como o Adaline, operam de forma muito mais eficiente quando os dados passam por **padronização** (*standardization*), garantindo que as características estejam em escalas comparáveis.
*   **Gradiente Descendente Estocástico (SGD):** Para lidar com grandes volumes de dados onde o gradiente descendente em lote seria caro demais, o autor apresenta o SGD, que atualiza os pesos incrementalmente após cada amostra de treinamento.
*   **Aprendizado Online:** O SGD permite o **aprendizado online**, onde o modelo pode ser treinado e atualizado em tempo real à medida que novos dados chegam.

---

# Referências

1. RASCHKA, Sebastian. Python Machine Learning: unlock deeper insights into machine learning with this vital guide to cutting-edge predictive analytics. Birmingham: Packt Publishing, 2015



---
