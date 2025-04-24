---
title: Lab 6 - Detecção de bordas
icon: fontawesome/solid/border-top-left
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
![disp7seg_capa](img/lab06-bordas_capa.png)

---

# 2 Displays 7-segmentos

Raramente um único display de 7 segmentos é suficiente para exibir o valor de alguma grandeza. Assim faz-se necessária a ligação de ao menos outro dígito. Para acionar este outro dígito pode-se utilizar outro PORT de 8 pinos do uC. A quantidade de pinos utilizados para o display começa a ficar inviável ao aumentar a quantidade de dígitos. Para viabilizar a utilização de vários dígitos, é utilizada uma técnica chamada multiplexação.

**Objetivo**

Detectar as bordas de subida e descida em botão pulsador, gerando um incremento e decremento de uma variável de contagem.



| Figura 1: Detecção de borda para incremento e decremento |
|:--------------------------------------------------------:|
| ![bordas_inc_dec](img/lab06-bordas_inc_dec.gif)          |
| Fonte: Autor                                             |


**Mapa de entradas e saídas**

| Função  | Dispositivo | Descrição | Pino <br> (Arduino Uno) | Pino <br> (ATmega328P) | PORT |
|:-------:|:-----------:|:---------:|:-----------------------:|:----------------------:|:----:|
| Saída   | Diplay 7 segmentos | Segmento a   |  0 |  2 | PD0 |
| Saída   | Diplay 7 segmentos | Segmento b   |  1 |  3 | PD1 |
| Saída   | Diplay 7 segmentos | Segmento c   |  2 |  4 | PD2 |
| Saída   | Diplay 7 segmentos | Segmento d   |  3 |  5 | PD3 |
| Saída   | Diplay 7 segmentos | Segmento e   |  4 |  6 | PD4 |
| Saída   | Diplay 7 segmentos | Segmento f   |  5 | 11 | PD5 |
| Saída   | Diplay 7 segmentos | Segmento g   |  6 | 12 | PD6 |
| Saída   | Diplay 7 segmentos | Segmento p   |  7 | 13 | PD7 |
| Saída   | Diplay 7 segmentos | Sel. Unidade |  8 | 14 | PB0 |
| Saída   | Diplay 7 segmentos | Sel. Dezena  |  9 | 15 | PB1 |
| Entrada | Botão pulsador NA  | B0 : incrementa contagem | 13 | 19 | PB5 |
| Entrada | Botão pulsador NA  | B1 : decrementa contagem | 12 | 18 | PB4 |


---


---
