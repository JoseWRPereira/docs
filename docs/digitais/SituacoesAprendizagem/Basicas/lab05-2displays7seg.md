---
title: Lab 5 - 2 Displays 7 segmentos
icon: fontawesome/solid/border-none
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - MMR
 - MCU
 - AVR
 - ATMega328P
---


<!-- ![atmega328](img/lab0-atmega328p.png) -->
![disp7seg_capa](img/lab04-display7seg_capa.png)

---

# 2 Displays 7-segmentos

Raramente um único display de 7 segmentos é suficiente para exibir o valor de alguma grandeza. Assim faz-se necessária a ligação de ao menos outro dígito. Para acionar este outro dígito pode-se utilizar outro PORT de 8 pinos do uC. A quantidade de pinos utilizados para o display começa a ficar inviável ao aumentar a quantidade de dígitos. Para viabilizar a utilização de vários dígitos, é utilizada uma técnica chamada multiplexação.

**Objetivo**

Acionar dois displays de 7 segmentos de forma multiplexada para exibir uma contagem de 0 a 99.


| Figura 1: Contagem com 2 dígitos            |
|:-------------------------------------------:|
| ![2xdisp7seg](img/lab05-disp7seg-0_99.gif)  |
| Fonte: Autor                                |


**Mapa de entradas e saídas**

| Função | Dispositivo | Descrição | Pino <br> (Arduino Uno) | Pino <br> (ATmega328P) | PORT |
|:------:|:-----------:|:---------:|:-----------------------:|:----------------------:|:----:|
| Saída  | Diplay 7 segmentos | Segmento a   |  0 |  2 | PD0 |
| Saída  | Diplay 7 segmentos | Segmento b   |  1 |  3 | PD1 |
| Saída  | Diplay 7 segmentos | Segmento c   |  2 |  4 | PD2 |
| Saída  | Diplay 7 segmentos | Segmento d   |  3 |  5 | PD3 |
| Saída  | Diplay 7 segmentos | Segmento e   |  4 |  6 | PD4 |
| Saída  | Diplay 7 segmentos | Segmento f   |  5 | 11 | PD5 |
| Saída  | Diplay 7 segmentos | Segmento g   |  6 | 12 | PD6 |
| Saída  | Diplay 7 segmentos | Segmento p   |  7 | 13 | PD7 |
| Saída  | Diplay 7 segmentos | Sel. Unidade |  8 | 14 | PB0 |
| Saída  | Diplay 7 segmentos | Sel. Dezena  |  9 | 15 | PB1 |


---


---
