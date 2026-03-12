---
title: 0111 - Comparador
icon: fontawesome/solid/greater-than-equal
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Circuitos Combinacionais
    - Comparador
---

# 


# Comparadores

Circuitos comparadores são blocos fundamentais da eletrônica digital, classificados como circuitos combinacionais, o que significa que suas saídas dependem única e exclusivamente das variáveis de entrada em um determinado instante. Eles operam em um nível de abstração superior ao das portas lógicas básicas, sendo frequentemente agrupados com somadores, contadores e registradores no projeto de sistemas digitais.

Abaixo, detalham-se sua definição e princípio de funcionamento:

## Definição e Finalidade
A função primordial de um comparador é analisar dois números binários (geralmente denominados $A$ e $B$) para determinar a relação de magnitude entre eles. O resultado dessa comparação é expresso através de saídas digitais que indicam três condições possíveis:

*   **$A > B$:** A saída correspondente assume nível lógico 1 se o valor de $A$ for superior ao de $B$.
*   **$A < B$:** A saída assume nível lógico 1 se $A$ for inferior a $B$.
*   **$A = B$:** Ambas as saídas de magnitude (maior e menor) permanecem em nível lógico 0, indicando igualdade, ou uma terceira saída específica de igualdade é ativada.

## Funcionamento e Estrutura
O funcionamento de um comparador de $n$ bits baseia-se na comparação bit a bit das entradas, seguindo uma lógica de prioridade que geralmente procede do bit mais significativo (MSB) para o bit menos significativo (LSB).

1.  **Lógica Celular:** Comparadores para múltiplos bits são frequentemente construídos de forma modular ou celular. Cada célula processa um par de bits ($a_i, b_i$) e recebe informações de células anteriores através de entradas de cascateamento.
2.  **Processo de Decisão:** Se, ao comparar os bits mais significativos, o circuito detectar que $a_n=1$ e $b_n=0$, ele define imediatamente que $A > B$, independentemente dos bits de menor peso. A comparação só avança para os bits subsequentes se os bits atuais forem iguais.
3.  **Implementação Física:** Embora possam ser descritos textualmente em linguagens como VHDL, fisicamente os comparadores são implementados através da interconexão de portas lógicas que realizam operações de "E" (AND), "OU" (OR) e "OU-Exclusivo" (XOR/XNOR) para inferir a igualdade ou diferença entre os sinais.

Esses componentes são essenciais em unidades de processamento para a execução de instruções de tomada de decisão e em controladores que exigem o monitoramento de limites numéricos.


---

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
