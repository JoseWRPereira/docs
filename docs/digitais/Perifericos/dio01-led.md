---
title: 1. LED
icon: fontawesome/solid/lightbulb
author: José W. R. Pereira
tags: 
    - Microcontrolador
    - MCU
    - MCMP
    - AVR
---

![LED](img/01-led.png)


# LED - Light-Emitting Diode - Diodo Emissor de Luz


Um **LED** (*Light Emitting Diode*) é um **dispositivo semicondutor (diodo)** composto por dois terminais, um **anodo** e um **catodo**, que tem a propriedade de emitir luz (fótons) quando percorrido por uma corrente elétrica. Ele é construído a partir da junção de dois materiais, um do **tipo P** e outro do **tipo N**, organizados de forma a permitir o fluxo de eletricidade em apenas uma direção.

A luz é produzida quando o LED está em **polarização direta**, o que acontece quando a tensão no anodo é mais positiva que no catodo por uma diferença mínima chamada **tensão direta** (*forward voltage*). O brilho resultante depende diretamente da potência elétrica aplicada e, como a tensão do LED permanece aproximadamente constante enquanto ele está ativo, o controle da intensidade luminosa é realizado através do ajuste da **corrente**.

No desenvolvimento de sistemas embarcados, é fundamental observar os seguintes conceitos técnicos:

*   **Necessidade de Resistor:** Quando um LED entra em condução, ele se torna um curto-circuito quase perfeito; por isso, é obrigatório utilizar um **resistor em série** para limitar a corrente e evitar que o componente seja danificado ou "queime".
*   **Cálculo de Proteção:** O valor do resistor limitador é obtido pela **Lei de Ohm**: 

    $R = \frac{(V_s - V_f)}{I}$, 

    onde $V_s$ é a tensão da fonte (como os 5V de um Arduino), $V_f$ é a tensão direta do LED (cerca de 1,8V para um LED vermelho comum) e $I$ é a corrente desejada (geralmente entre 10mA e 20mA).

*   **Polaridade:** O LED é um componente **polarizado**; o anodo (+) é normalmente o terminal mais longo e o catodo (-) possui um chanfro ou lado chato no corpo plástico do componente.

*   **Aplicações:** Em projetos com microcontroladores, os LEDs atuam como **atuadores simples**, servindo como indicadores visuais de estado do sistema, monitores de processamento (*heartbeat*) ou emissores de sinais infravermelhos em controles remotos.

*   **Variedades:** Existem ainda LEDs **multicoloridos (RGB)**, que integram elementos de cores primárias em um único encapsulamento, permitindo a criação de diversas cores através do controle individual de cada elemento.

A integração de LEDs é tão comum que quase todo sistema embarcado possui ao menos um para testes iniciais, sendo o programa que o faz piscar (o famoso *Blink*) considerado o "Hello World" da eletrônica.


Através de um pino de microcontrolador, configurado como saída, pode-se realizar o acionamento do LED. Este pino pode estar fornecendo corrente como fonte (source) ao ramo ou drenando (sink) corrente dele.

| Ligação do pino como fonte (Source) | Ligação do pino como dreno (Sink) |
|:-----------------------------------:|:---------------------------------:|
|![pinSouce](img/01-pin_source.gif)  | ![pinSink](img/01-pin_sink.gif)  |

O pino do uC possui limitação de corrente, que pode variar a depender do modelo ou fabricante.

A corrente máxima por pino é de `40 mA`, de acordo com o Datasheet (AVR ATmega328P, capítulo *28.1 Absolute maximum ratings*, pág. 258), que é o microcontrolador do Arduino Uno. Este valor varia de acordo com o dispositivo controlador, sendo assim, sempre consulte o manual do fabricante do controlador que está sendo utilizado. 

A vantagem de utilizar o pino como fonte é trabalhar com uma lógica direta, em que o estado lógico 1 (verdadeiro, +5V) produz o acionamento do LED, enquanto que na configuração do pino como dreno a lógica de acionamento é invertida, pois para produzir o acionamento do LED o pino deve estar em estado lógico 0 (falso, 0V).




---
# Referências

1. LIMA, Charles Borges de; VILLAÇA, Marco V. M. **AVR e Arduino: técnicas de projeto**. 2. ed. Florianópolis: Edição dos Autores, 2012..
2. VALVANO, Jonathan W. **Embedded Systems: Introduction to ARM® Cortex™-M Microcontrollers**. 5. ed. [S.l.]: Jonathan Valvano, 2014. v. 1..
3. [**SAP-1**](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.ic.unicamp.br/~ducatte/mc542/2012S2/sap-1.pdf&ved=2ahUKEwiDudPG_7OSAxXOK7kGHaWnASEQFnoECBIQAQ&usg=AOvVaw1vCyc0wwa3fZKVV3eVa875) (Simple-As-Possible Computer 1).

---
