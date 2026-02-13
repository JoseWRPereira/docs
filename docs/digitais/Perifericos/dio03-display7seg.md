---
title: 3 - Display 7 segmentos
icon: fontawesome/solid/7
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - MMR
 - MCU
 - AVR
 - ATMega328P
---

#

![disp7seg_capa](img/disp7seg_capa.png)

---

# 1. Display 7-segmentos


O display de 7 segmentos basicamente é um conjunto de LEDs dispostos de forma a cada um deles iluminar um segmento no encapsulamento. Existem vários modelos para diferentes necessidades, mas aqui usamos o mais comum.

O display possui, além dos sete segmentos, um ponto, que pode ser utilizado para sinalizar um ponto decimal (vírgula) ao associar vários displays. Nesse projeto o ponto não será utilzado.

Existem dois modelos de display, **Anodo comum** e **Catodo comum**, que se referem aos terminais dos LEDs conectados em comum, conforme exemplo da Figura 1.

| Figura 1: Segmentos do display          |
|:--------------------------------------:|
| ![display7seg](img/disp7seg.jpg) |
| Fonte: Autor                           |

Cada segmento recebe uma identificação em letra minúscula de `a` a `g` e o `p`. O display possui um terminal para cada segmento do display.

Note que cada segmento, composto por um LED, necessita de um resistor para limitar a corrente que percorre ele. Como cada pino do uC fornece uma tensão de 5V para acionar o segmento. A queda de tensão no LED é de 2V, aproximadamente. Pode-se assim calcular o valor do resistor limitador de corrente:

\[ R = \frac{V_{pino} - V_{LED}}{I_{LED}} = \frac{5-2}{0,02} = 150\Omega \]


O display aqui utilizado é do tipo catodo comum, assim basta acionar os pinos que correspondam aos segmentos a serem acionados para formar o dígito que se deseja exibir.

Para mostrar o dígito 0(zero), aciona-se os segmento a, b, c, d, e, f conforme mostrado na Figura 2.

| Figura 2: Código de formação do digito 0 (Zero) |
|:-----------------------------------------------:|
| ![digito0](img/disp7seg-digito0.jpg)      |
| Fonte: Autor                                    |


É importante notar a sequência de pinos do display e do PORT utilizado, pois uma alteração de ordem muda o que é exibido no display.

Para o dígito 1(um), Figura 3, é necessário ligar apenas os segmentos b e c, mantendo os demais desligados.

| Figura 3: Código de formação do digito 1 (Um)   |
|:-----------------------------------------------:|
| ![digito1](img/disp7seg-digito1.jpg)      |
| Fonte: Autor                                    |

Para o dígito 2(dois), Figura 4, é mais fácil perceber os dígitos desligados, pois estão em menor quantidade, sendo o `c` e o `f` desligados e os demais ligados (exceto o ponto como já foi citado).


| Figura 4: Código de formação do digito 2 (Dois) |
|:-----------------------------------------------:|
| ![digito2](img/disp7seg-digito2.jpg)      |
| Fonte: Autor                                    |


A Figura 5 mostra uma tabela com todas as combinações para os dígitos decimais e seus valores correspondentes em hexadecimal. Ao atribuir ao PORT um dos valores em hexadecimal da tabela, o digito correspondente deve ser mostrado no display.

| Figura 5: Código de formação do dígitos `0` a `9` |
|:-------------------------------------------------:|
| ![digitos](img/disp7seg-digitos.jpg)        |
| Fonte: Autor                                      |


Estão faltando os dados dos dígitos que completam o conjunto hexadecimal, que podem te servir como exercícios. 

Bom trabalho!

---


# 2. Uso com um Único Dígito

Para acionar um display individual, cada segmento (identificado pelas letras de **a** até **g** e **p** para o ponto) deve ser conectado a um pino de saída do microcontrolador através de um **resistor limitador de corrente**. O uso prático envolve os seguintes passos:

1.  **Mapeamento:** Define-se quais segmentos devem ser acesos para formar cada número de 0 a 9 (ou A-F).
2.  **Decodificação:** Utiliza-se uma **tabela de decodificação** (ou *lookup table*) no código, que traduz o valor binário convencional para o padrão de bits que o display exige. 
3.  **Saída de Dados:** O microcontrolador escreve o valor da tabela diretamente no registrador da porta (PORT) conectada ao display.

# 3. Uso com Múltiplos Dígitos (Multiplexação)

Ligar vários dígitos diretamente exigiria um número excessivo de pinos (ex: 32 pinos para 4 dígitos). Para resolver isso, utiliza-se a técnica de **multiplexação temporal**, baseada no fenômeno da **persistência da visão** humana.

*   **Conexão Física:** Os segmentos correspondentes de todos os dígitos (todos os "a", todos os "b", etc.) são interconectados em um barramento comum. Os pinos comuns de cada dígito (anodo ou catodo comum) são conectados individualmente a pinos de controle, geralmente através de **transistores** (PNP para anodo comum ou NPN para catodo comum) para suportar a corrente.
*   **Lógica de Varredura:** O sistema embarcado liga apenas um dígito por vez, coloca o dado correspondente no barramento de segmentos, espera alguns milissegundos, apaga-o e repete o processo para o próximo dígito.
*   **Frequência:** Para que o olho humano não perceba a cintilação e veja todos os dígitos acesos simultaneamente, a varredura deve ocorrer a uma frequência mínima de **24 Hz a 50 Hz** por dígito.



Segue um exemplo, Figura 6, de implementação de dois dígitos com displays de sete segmentos utilizando a técnica de multiplexação.

| Figura 6: Contagem com 2 dígitos            |
|:-------------------------------------------:|
| ![2xdisp7seg](img/disp7seg-0_99.gif)  |
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


Para projetos que visam economizar ainda mais pinos e processamento, podem ser utilizados drivers de hardware dedicados, como o **MAX7221** ou o **SAA1064**, que gerenciam a multiplexação e a decodificação internamente via comunicação serial (SPI ou I2C).

---

# Referências

1. LIMA, Charles Borges de; VILLAÇA, Marco V. M. **AVR e Arduino: técnicas de projeto**. 2. ed. Florianópolis: Edição dos Autores, 2012..
2. VALVANO, Jonathan W. **Embedded Systems: Introduction to ARM® Cortex™-M Microcontrollers**. 5. ed. [S.l.]: Jonathan Valvano, 2014. v. 1..
3. [**SAP-1**](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.ic.unicamp.br/~ducatte/mc542/2012S2/sap-1.pdf&ved=2ahUKEwiDudPG_7OSAxXOK7kGHaWnASEQFnoECBIQAQ&usg=AOvVaw1vCyc0wwa3fZKVV3eVa875) (Simple-As-Possible Computer 1).

---
