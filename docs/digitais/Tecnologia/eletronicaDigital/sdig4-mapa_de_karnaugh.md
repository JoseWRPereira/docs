---
title: 0100 - Mapa de Karnaugh
icon: fontawesome/solid/table-cells-large
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Expressões Lógicas
    - Simplificação
    - Mapa de Karnaugh
---

# 

# [Mapa de Karnaugh](../../slides/SDIG04-MapaK.pdf)

O Mapa de Karnaugh (ou Mapa K) simplifica expressões de **mintermos** — representadas na forma de **Soma de Produtos (SOP)** — através de um método gráfico que identifica padrões de adjacência lógica para eliminar variáveis redundantes. Enquanto a simplificação por álgebra booleana exige manipulações matemáticas complexas, o Mapa K permite visualizar essas reduções diretamente da tabela-verdade.


## 1. Organização por Adjacência Lógica (Código Gray)
O mapa é construído de forma que as células adjacentes (horizontal ou verticalmente) difiram por apenas um bit em suas variáveis de entrada. Essa organização segue o **Código Gray**, garantindo que, ao mover-se de uma célula para a vizinha, apenas o estado de uma variável mude (de 0 para 1 ou vice-versa).

![](img/mapaK-posicao.png)


## 2. Agrupamento de Mintermos (Looping)
O processo de simplificação baseia-se em identificar regiões onde a saída assume o valor lógico 1 e agrupá-los em laços (*loops*). As regras fundamentais para esses agrupamentos são:

*   **Tamanho dos Grupos:** Os grupos devem conter obrigatoriamente potências de 2 (1, 2, 4, 8 ou 16 elementos).
*   **Maximização:** Os laços devem ser o maior possível para garantir a máxima simplificação; quanto maior o laço, mais variáveis são eliminadas.
*   **Flexibilidade:** Os laços podem se sobrepor e também podem "dar a volta" pelas bordas do mapa (adjacência circular).

![](img/mapaK-posicao_valor.png)



## 3. Eliminação de Variáveis
A simplificação ocorre quando uma variável aparece dentro de um mesmo laço tanto em sua forma **complementada** (0) quanto **não complementada** (1). Como essas formas se anulam logicamente ($A + \bar{A} = 1$), a variável "desaparece" da expressão resultante.

O impacto da simplificação depende do número de elementos no grupo:

*   **Par (2 células):** Elimina 1 variável da expressão do mintermo.
*   **Quadra (4 células):** Elimina 2 variáveis.
*   **Oitava (8 células):** Elimina 3 variáveis.


![](img/mapaK-posicao_valor_simplifica.png)

---

![](img/mapaK-3vars.png)



## 4. Construção da Expressão Simplificada
Após realizar todos os agrupamentos necessários para cobrir todos os 1s do mapa, a função final simplificada é obtida através da disjunção (operação OR) dos termos resultantes de cada laço. Se houver condições de **"não importa" (*don't care*)**, representadas por "X", elas podem ser tratadas como 1 para aumentar o tamanho dos laços e simplificar ainda mais a expressão, ou como 0 se não ajudarem no agrupamento.

## 5. Casos Irrelevantes 

As condições "don't care" (frequentemente denominadas como condições de "não importa" ou "casos irrelevantes") referem-se a combinações de variáveis de entrada que nunca ocorrerão em um projeto específico ou cujos resultados de saída não interferem no funcionamento do sistema,. Nos Mapas de Karnaugh (Mapa K) e nas tabelas-verdade, esses estados são representados graficamente pelo símbolo "X" ou por um hífen "-".

A utilização dessas condições no Mapa de Karnaugh segue critérios técnicos de otimização de hardware:

*   **Flexibilidade no Agrupamento:** Durante o processo de simplificação gráfica, o projetista pode tratar cada "X" individualmente como nível lógico 1 ou 0, dependendo do que for mais vantajoso para a redução do circuito.
*   **Maximização dos Laços (Looping):** Para obter a expressão booleana mais simples, deve-se considerar o "X" como valor 1 sempre que ele permitir a formação de grupos maiores — como quadras (4 células) ou oitavas (8 células) — já que grupos maiores eliminam um número maior de variáveis redundantes.
*   **Tratamento como Nível Zero:** Se uma condição "don't care" não auxiliar na expansão de um laço ou na cobertura de uma saída 1 que precise ser agrupada, ela deve ser tratada como 0 e, consequentemente, ignorada nas associações.
*   **Simplificação de Expressões:** O uso estratégico de "X" permite que funções complexas sejam reduzidas a formas canônicas muito mais simples, minimizando o número de portas lógicas e os atrasos de propagação no circuito final.

Essa técnica é amplamente aplicada em componentes onde certas combinações binárias são descartadas, como em decodificadores de BCD para sete segmentos ou em codificadores de prioridade, permitindo que a lógica resultante seja mais econômica em termos de área de silício e consumo de recursos.

![](img/mapaK-disp7seg.png)

Segue exemplo de simplificação usando mapa de Karnaugh com quatro variáveis para o segmento `a` do display. 

![](img/mapaK-disp7seg_a.png)

---

# Exercícios


1) Simplificação de Mintermos (3 Variáveis)

Dada a expressão booleana abaixo, preencha o Mapa de Karnaugh de três variáveis ($A, B, C$) e determine a expressão simplificada final. 
Lembre-se de que a organização das células deve seguir o **Código Gray** (00, 01, 11, 10).

$S = \bar{A}\bar{B}C + \bar{A}BC + A\bar{B}C + ABC + AB\bar{C}$


---

2) Conversão de Tabela-Verdade para Mapa K (3 Variáveis)

A partir da tabela-verdade fornecida, monte o Mapa de Karnaugh e obtenha a função lógica simplificada.

| A | B | C | S |
| :--- | :--- | :--- | :--- |
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |


---

3) Otimização de Sistema com 4 Variáveis

Projete a lógica simplificada para um sistema de quatro variáveis ($A, B, C, D$) onde a saída assume valor lógico 1 para os seguintes mintermos:

**Mintermos (m):** $\sum m(0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14)$

---

4) Uso de Condições "Don't Care" (X)

Em projetos de hardware, como decodificadores de BCD para sete segmentos, algumas combinações de entrada nunca ocorrem ou são irrelevantes. Utilize o Mapa K de quatro variáveis ($P, Q, R, S$) para simplificar a função abaixo, tratando os "X" como 1 sempre que ajudarem a expandir um laço.

*   **Segmento C: Mintermos (1):** $m_0, m_1, m_3, m_4, m_5, m_6, m_7, m_8, m_9$
*   **Don't Cares (X):** $m_{10}, m_{11}, m_{12}, m_{13}, m_{14}, m_{15}$

---

5) Ainda usando condições "Don't Care" (X)

Da mesma forma que o exercício anterior, defina os mintermos (1) para os segmentos do conversor (BCD para 7 segmentos) e utilizando o Mapa K de quatro variáveis ($P, Q, R, S$), simplifique as funções:

*   **Segmento b: Mintermos (1):** 
*   **Segmento d: Mintermos (1):** 
*   **Segmento e: Mintermos (1):** 
*   **Segmento f: Mintermos (1):** 
*   **Segmento g: Mintermos (1):** 

Para todos use: 

*   **Don't Cares (X):** $m_{10}, m_{11}, m_{12}, m_{13}, m_{14}, m_{15}$

---


# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
