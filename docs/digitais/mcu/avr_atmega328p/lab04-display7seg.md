---
title: Lab 4 - Display 7 segmentos
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


<!-- ![atmega328](img/lab0-atmega328p.png) -->
![disp7seg_capa](img/lab04-display7seg_capa.png)

---

# Display 7-segmentos


**Objetivo**

Acionar um display de 7 segmentos para exibir os 16 dígitos hexadecimais: `0,1,2,3,4,5,6,7,8,9,A,B,C,D,E e F`.

**O display**

O display de 7 segmentos basicamente é um conjunto de LEDs dispostos de forma a cada um deles iluminar um segmento no encapsulamento. Existem vários modelos para diferentes necessidades, mas aqui usamos o mais comum.

O display possui, além dos sete segmentos, um ponto, que pode ser utilizado para sinalizar um ponto decimal (vírgula) ao associar vários displays. Nesse projeto o ponto não será utilzado.

Existem dois modelos de display, **Anodo comum** e **Catodo comum**, que se referem aos terminais dos LEDs conectados em comum, conforme exemplo da Figura 1.

| Figura 1: Segmentos do display          |
|:--------------------------------------:|
| ![display7seg](img/lab04-disp7seg.jpg) |
| Fonte: Autor                           |

Cada segmento recebe uma identificação em letra minúscula de `a` a `g` e o `p`. O display possui um terminal para cada segmento do display.

Note que cada segmento, composto por um LED, necessita de um resistor para limitar a corrente que percorre ele. Como cada pino do uC fornece uma tensão de 5V para acionar o segmento. A queda de tensão no LED é de 2V, aproximadamente. Pode-se assim calcular o valor do resistor limitador de corrente:

\[ R = \frac{V_{pino} - V_{LED}}{I_{LED}} = \frac{5-2}{0,02} = 150\Omega \]


O display aqui utilizado é do tipo catodo comum, assim basta acionar os pinos que correspondam aos segmentos a serem acionados para formar o dígito que se deseja exibir.

Para mostrar o dígito 0(zero), aciona-se os segmento a, b, c, d, e, f conforme mostrado na Figura 2.

| Figura 2: Código de formação do digito 0 (Zero) |
|:-----------------------------------------------:|
| ![digito0](img/lab04-disp7seg-digito0.jpg)      |
| Fonte: Autor                                    |


É importante notar a sequência de pinos do display e do PORT utilizado, pois uma alteração de ordem muda o que é exibido no display.

Para o dígito 1(um), Figura 3, é necessário ligar apenas os segmentos b e c, mantendo os demais desligados.

| Figura 3: Código de formação do digito 1 (Um)   |
|:-----------------------------------------------:|
| ![digito1](img/lab04-disp7seg-digito1.jpg)      |
| Fonte: Autor                                    |

Para o dígito 2(dois), Figura 4, é mais fácil perceber os dígitos desligados, pois estão em menor quantidade, sendo o `c` e o `f` desligados e os demais ligados (exceto o ponto como já foi citado).


| Figura 4: Código de formação do digito 2 (Dois) |
|:-----------------------------------------------:|
| ![digito2](img/lab04-disp7seg-digito2.jpg)      |
| Fonte: Autor                                    |


A Figura 6 mostra uma tabela com todas as combinações para os dígitos decimais e seus valores correspondentes em hexadecimal. Ao atribuir ao PORT um dos valores em hexadecimal da tabela, o digito correspondente deve ser mostrado no display.

| Figura 5: Código de formação do dígitos `0` a `9` |
|:-------------------------------------------------:|
| ![digitos](img/lab04-disp7seg-digitos.jpg)        |
| Fonte: Autor                                      |


Estão faltando os dados dos dígitos que completam o conjunto hexadecimal, que podem te servir como exercícios. 

Bom trabalho!



---

**Mapa de entradas e saídas**

| Função | Dispositivo | Descrição | Pino <br> (Arduino Uno) | Pino <br> (ATmega328P) | PORT |
|:------:|:-----------:|:---------:|:-----------------------:|:----------------------:|:----:|
| Saída  | Diplay 7 segmentos | Segmento a |  0 |  2 | PD0 |
| Saída  | Diplay 7 segmentos | Segmento b |  1 |  3 | PD1 |
| Saída  | Diplay 7 segmentos | Segmento c |  2 |  4 | PD2 |
| Saída  | Diplay 7 segmentos | Segmento d |  3 |  5 | PD3 |
| Saída  | Diplay 7 segmentos | Segmento e |  4 |  6 | PD4 |
| Saída  | Diplay 7 segmentos | Segmento f |  5 | 11 | PD5 |
| Saída  | Diplay 7 segmentos | Segmento g |  6 | 12 | PD6 |
| Saída  | Diplay 7 segmentos | Segmento p |  7 | 13 | PD7 |


**Circuito de Simulação**

| Figura 6: Montagem do circuito de contagem com display de 7 segmentos |
|:---------------------------------------------------------------------:|
| ![digitos](img/lab04-disp7seg_digitos.gif)                            |
| Fonte: Autor                                                          |

---

**Código**

```C
#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

char digitos7seg[16] = {	0x3F, 0x06, 0x5B, 0x4F, 
							0x66, 0x6D, 0x7D, 0x07, 
							0x7F, 0x6F, 0x77, 0x7C, 
							0x39, 0x5E, 0x79, 0x71  };

void disp7seg_init( void )
{
	DDRD  = 0xFF;
	PORTD = 0x00;
}

void disp7seg( unsigned char d )
{
	PORTD = digitos7seg[d];
}

int main(void) 
{
	char i = 0;
	disp7seg_init();
	while( 1 )
	{
		disp7seg( i );
		_delay_ms(500);

        // Incremento limitado: 0..15
		++i;
		if( i >= 16 )
			i = 0;
	}
}
```

Há outras formas de realizar o incremento de forma limitada e retornar ao zero, reiniciando a contagem. 

Uma dessas formas é utilizando o [operador ternário](https://www.freecodecamp.org/portuguese/news/operador-ternario-em-c/).


```C title="Incremento limitado: 0..15"
        i = (i>=16) ? 0: (i+1);
```
Outra forma de realizar um incremento limitado é utilizando o operador `mod` que em linguagem C é o símbolo: `%`.

O operador `%` produz o resto da divisão. 

```C title="Incremento limitado: 0..15"
        i = ++i % 16;
```

---

**Problema de memória**

Dado o trecho de código destacado, o que acontece se a função for executada da seguinte forma: `disp7seg(16);`? 

```C
char digitos7seg[16] = {	0x3F, 0x06, 0x5B, 0x4F, 
							0x66, 0x6D, 0x7D, 0x07, 
							0x7F, 0x6F, 0x77, 0x7C, 
							0x39, 0x5E, 0x79, 0x71  };

void disp7seg( unsigned char d )
{
	PORTD = digitos7seg[d];
}
```



---
