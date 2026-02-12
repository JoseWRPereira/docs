---
title: 1. Saída Digital
icon: fontawesome/solid/lightbulb
author: José W. R. Pereira
tags: 
    - Arduino UNO
---

#

# Saída Digital - *Digital Output*

Uma **saída digital** é o recurso que permite ao microcontrolador interagir com o mundo externo, enviando sinais que possuem apenas dois estados possíveis: **ligado ou desligado**. No ecossistema Arduino, isso significa que a tensão em um pino configurado como saída será alternada entre o **nível lógico alto (HIGH)**, correspondente a 5V (ou 3,3V dependendo do modelo), e o **nível lógico baixo (LOW)**, correspondente a 0V ou terra (GND).

Para configurar e usar uma saída digital, segue-se o procedimento abaixo:

## 1. Configuração (Função `setup`)
Antes de utilizar um pino, você deve configurá-lo, para que ele funcione como uma saída. Isso é feito através da função **`pinMode(pin, mode)`**.

*   **Parâmetros** 
    * **pin**: Pino do arduino a ser configurado, no Uno de 0 a 13;
    * **mode**: `INPUT`, `OUTPUT` ou `INPUT_PULLUP`;
*   **Sintaxe:** `pinMode(pino, OUTPUT);`
*   **Exemplo:** `pinMode(13, OUTPUT);` define o pino 13 como saída.
*   **Nota técnica:** Internamente, esse comando escreve o valor '1' no bit correspondente do registrador de direção de dados (**DDRx**) do microcontrolador.


## 2. Uso (Função `loop`)
Após a configuração, você controla o estado do pino usando a função **`digitalWrite()`**, que define se o dispositivo conectado receberá ou não energia.

*   **Sintaxe:** `digitalWrite(pino, HIGH);` para aplicar tensão (5V) e ligar o componente.
*   **Sintaxe:** `digitalWrite(pino, LOW);` para aplicar a tensão (0V) e desligar o componente.

No lugar das definições `HIGH` e `LOW` podem ser usados os valores `1` e `0`, respectivamente. 

*   **Sintaxe:** `digitalWrite(pino, 1);` para aplicar tensão (5V) e ligar o componente.
*   **Sintaxe:** `digitalWrite(pino, 0);` para aplicar a tensão (0V) e desligar o componente.


### Considerações Práticas e Elétricas

*   **Pinos Disponíveis:** O Arduino Uno possui **14 pinos digitais** (0 a 13). Recomenda-se evitar o uso dos pinos **0 e 1**, pois são utilizados para a comunicação serial com o computador.
*   **Capacidade de Corrente:** Cada pino pode fornecer ou drenar uma corrente de até **40 mA** (sendo recomendado manter-se em **20 mA** para segurança), o que é suficiente para acender um LED diretamente, desde que se utilize um **resistor limitador** para não queimar o componente.
*   **Atividade Blink:** O exemplo mais comum de uso é o programa "Blink", que alterna o estado de um LED entre HIGH e LOW em intervalos de tempo definidos pela função `delay(ms)`.

Ao conectar cargas que exijam correntes maiores, como motores ou lâmpadas de corrente alternada, a saída digital deve ser conectada a um **circuito de interface**, como um transistor, relé ou driver de corrente.

---

---

# Blink ou Pisca LED

A atividade **Pisca LED** ou **Blink** é considerada o "Hello World!" dos sistemas embarcados e microcontroladores. Ela consiste em um programa básico cujo único objetivo é fazer um **LED piscar** em uma frequência determinada, servindo como a primeira prova de conceito para verificar se o hardware, o compilador e o processo de gravação estão funcionando corretamente.

A lógica fundamental dessa atividade segue um ciclo de quatro passos executados dentro de um **laço infinito**:

1.  **Ligar o LED**, aplicando o nível lógico alto no pino em que o LED está ligado.
2.  **Aguardar um tempo**, geralmente 1 segundo ou 500 ms.
3.  **Desligar o LED**, aplicar nível lógico baixo no pino do LED.
4.  **Aguardar novamente o tempo** antes de reiniciar o ciclo.

## Formas de Implementação
Dependendo da plataforma e linguagem utilizada, a implementação varia:

*   **No Arduino (Linguagem Wiring/C++):** É o exemplo mais popular, disponível nativamente na IDE. Utiliza as funções `pinMode()` para configurar o pino como saída, `digitalWrite()` para alterar o estado e `delay()` para as pausas.
*   **Em Linguagem C (AVR-GCC):** O programador utiliza macros para manipulação direta de bits nos registradores (como `set_bit` e `clr_bit`) e bibliotecas de utilitários de tempo, como a `<util/delay.h>`.
*   **Em Assembly:** É a forma mais complexa e próxima do hardware, onde o programador utiliza instruções de baixo nível (como `SBI` para ativar e `CBI` para limpar bits) e cria sub-rotinas de atraso decrementando valores em registradores de trabalho.

A implementação do Blink como código introduz um conceito vital nos sistemas embarcados: o **loop infinito**. Diferente de programas de computador de uso geral que têm um fim, o software de um sistema embarcado deve rodar continuamente enquanto o dispositivo estiver ligado ou até que sofra um *reset*. Sem esse laço de repetição, o LED mudaria de estado apenas uma vez e o hardware permaneceria inútil.

Seguem algumas montagens de circuito pisca LED em simuladores:

| Figura: Montagem de pisca LED no TinkerCad |
|:------------------------------------------:|
| ![Blink](img/uno01-blink.png) |
| Fonte: Autor |



| Pisca LED em ligação do pino como fonte (Source) | Pisca LED em ligação do pino como dreno (Sink) |
|:-----------------------------------:|:---------------------------------:|
|![pinSouce](img/01-pin_source.gif)  | ![pinSink](img/01-pin_sink.gif)  |

# Código Fonte

```C
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  	digitalWrite(LED_BUILTIN, HIGH);  
  	delay(1000); 
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); 
}
```

---

# Referências

1. [Arduino Builtin Examples - Blink](https://docs.arduino.cc/built-in-examples/basics/Blink/?_gl=1*1l1ps36*_up*MQ..*_ga*MTk3MjQxOTcwOC4xNzcwMzMyNjA1*_ga_NEXN8H46L5*czE3NzAzMzI2MDMkbzEkZzEkdDE3NzAzMzI3MDYkajQzJGwwJGgxNjY5MDAwODU0)


---
