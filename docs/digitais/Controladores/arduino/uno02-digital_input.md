---
title: 2. Entrada Digital
icon: fontawesome/solid/toggle-on
author: José W. R. Pereira
tags: 
    - Arduino UNO
---

#

# Entrada Digital - *Digital Input*

Uma **entrada digital** é uma interface que permite ao microcontrolador ler e interpretar sinais binários vindos do ambiente externo. Esses sinais possuem apenas dois estados possíveis: **ligado ou desligado**, representados logicamente como **'1' (HIGH)** e **'0' (LOW)**. No contexto elétrico, o nível LOW corresponde geralmente a 0V (GND), enquanto o nível HIGH corresponde à tensão de alimentação do circuito, como 5V ou 3,3V.


Para utilizar uma entrada digital, é necessário seguir passos de configuração tanto em hardware quanto em software:



## 1. Configuração (Função `setup`)
No Arduino Uno, existem **14 pinos digitais (0 a 13)** que podem ser usados como entradas. Pinos analógicos (A0 a A5) também podem ser configurados para funcionar como entradas digitais. Recomenda-se evitar o uso dos pinos 0 e 1, pois são reservados para a comunicação serial USB.

Antes de utilizar um pino, você deve configurá-lo, para que ele funcione como uma entrada. Isso é feito através da função **`pinMode(pin, mode)`**, que deve ser executada dentro da função `setup()`.

*   **Parâmetros** 
    * **pin**: Pino do arduino a ser configurado, no Uno de 0 a 13;
    * **mode**: `INPUT` ou `INPUT_PULLUP`;
*   **Sintaxe:** `pinMode(pino, INPUT);` ou `pinMode(pino, INPUT_PULLUP);`
*   **Exemplo:** `pinMode(8, INPUT);` define o pino 8 como entrada.
*   **Nota técnica:** Internamente, esse comando escreve o valor '0' no bit correspondente do registrador de direção de dados (**DDRx**) do microcontrolador.


## 2. Uso (Função `loop`)
Após a configuração, você pode ler o estado do pino usando a função **`digitalRead(pin)`**, que retorna o valor HIGH ou LOW, respectivamente `1` ou `0`. 

*   **Sintaxe:** `digitalRead(pino);` para ler o estado lógico do pino.



## 3. Considerações Práticas e Elétricas

Um pino configurado como entrada não deve ficar "flutuando" (desconectado), pois ruídos podem causar leituras instáveis. Por isso, utilizam-se resistores de **pull-up** (conectando ao VCC) ou **pull-down** (conectando ao GND). O microcontrolador ATmega328 possui resistores de **pull-up internos** que podem ser habilitados via software para simplificar o circuito.

Ao usar botões mecânicos, ocorre o fenômeno do **bounce** (trepidação dos contatos), que pode ser interpretado como múltiplos acionamentos rápidos. Para corrigir isso, implementa-se o **debounce** via software, inserindo um pequeno atraso (delay) após a detecção do sinal para aguardar a estabilização mecânica.

---

# Referências 

1. ANDERSON, Rick; CERVO, Dan. **Pro Arduino**: Arduino Expert Topics and Techniques. New York: Apress, 2013.

2. ATMEL. **ATmega328P**: 8-bit AVR Microcontroller with 4/8/16/32K Bytes In-System Programmable Flash. Rev. 8161D. [S. l.], 2009.

3. LIMA, Charles Borges de; VILLAÇA, Marco Valério Miorim. **AVR e Arduino**: Técnicas de Projeto. 2. ed. Florianópolis: Edição dos Autores, 2012.

4. MARGOLIS, Michael. **Arduino Cookbook**. 2. ed. [S. l.]: O'Reilly Media, 2012.

5. MARWEDEL, Peter. **Embedded System Design**: Embedded Systems Foundations of Cyber-Physical Systems, and the Internet of Things. 4. ed. Dortmund: Springer Nature, 2021.

6. PEREA, Francis. **Arduino Essentials**. Birmingham: Packt Publishing, 2015.

7. PURDUM, Jack. **Beginning C for Arduino**: Learn C Programming for the Arduino and Compatible Microcontrollers. New York: Apress, 2012.

8. RUSSELL, David J. **Introduction to Embedded Systems**: Using ANSI C and the Arduino Development Environment. [S. l.]: Morgan & Claypool, 2010.

9. VALVANO, Jonathan W. **Embedded Systems**: Introduction to ARM® Cortex™-M Microcontrollers. 5. ed. Austin: [s. n.], 2014. v. 1.

---