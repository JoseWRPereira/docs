---
title: 0110 - Somador e Subtrator
icon: fontawesome/solid/plus-minus
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Circuitos Combinacionais
    - Somador
    - Subtrator
---

# 

# Somadores e subtratores

Os circuitos somadores e subtratores são blocos fundamentais da eletrônica digital, pertencentes à categoria dos circuitos aritméticos. Eles são os componentes centrais da Unidade Lógica e Aritmética (ULA) de um computador, onde executam os cálculos matemáticos binários necessários para o processamento de dados.

## Circuitos Somadores
Os somadores realizam a adição de números binários e são divididos em dois tipos principais conforme a complexidade da operação:

*   **Meio Somador (*Half Adder*):** É o circuito mais simples, projetado para somar apenas um bit de cada entrada ($A$ e $B$). Ele possui duas saídas: **SOMA**, que corresponde a uma porta lógica XOR ($A \oplus B$), e **VAI-UM** (*Carry*), resultante de uma porta AND ($A \cdot B$) que sinaliza o transporte para a próxima casa decimal.
*   **Somador Completo (*Full Adder*):** Diferente do meio somador, este circuito possui uma terceira entrada para o transporte vindo de uma operação anterior (*Carry-in* ou "vem-um"). Isso permite que múltiplos somadores completos sejam interconectados em paralelo para realizar a soma de números com $n$ bits.

## Circuitos Subtratores
Os subtratores operam sob o conceito de "empresta-1" (*Borrow*), similar à subtração decimal.

*   **Meio Subtrator (*Half Subtractor*):** Realiza a subtração de um bit de informação. Suas saídas são a **DIFERENÇA** (uma porta XOR) e o **EMPRESTA-1**, que assume nível lógico 1 apenas quando a entrada $A$ é 0 e a entrada $B$ é 1.
*   **Subtrator Completo:** Assim como o somador completo, ele considera o bit emprestado de uma etapa anterior para permitir a subtração de múltiplos bits.

## Implementação e Integração
Na prática da arquitetura de computadores, é comum otimizar o hardware utilizando circuitos somadores para realizar também a subtração através da lógica de **complemento de dois**. Nesse processo, inverte-se o subtraendo e soma-se 1 (ajustando o bit de transporte de entrada para 1), o que permite que um somador paralelo execute a função de um subtrator. 

Existem ainda circuitos **Somadores/Subtratores Duais**, que utilizam portas XOR como inversores controlados: quando o sinal de controle é 1, o circuito atua como subtrator (complementando a entrada); quando é 0, atua como um simples somador. Esses circuitos integrados, como a série 74LS283, são amplamente utilizados para manipulação de dados em sistemas digitais.

---


---

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
