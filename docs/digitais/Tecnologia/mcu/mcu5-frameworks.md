---
title: 5. Frameworks
icon: fontawesome/solid/shield-halved
author: José W. R. Pereira
tags: 
    - Framework
    - Arduino

---

#

# 1. Framework

Um framework ou plataforma como o **Arduino** é um ecossistema de código aberto que integra **hardware** (placas baseadas em microcontroladores) e **software** (um ambiente de desenvolvimento integrado - IDE e bibliotecas) para simplificar a computação física. Ele atua como uma **camada de abstração de software**, oferecendo uma interface amigável (um subconjunto de C/C++ conhecido como a biblioteca **Wiring**) que esconde os detalhes complexos do hardware e dos registradores.

**Função**
A principal função de um framework desse tipo é servir como uma ferramenta de **prototipagem rápida** e educação. Ele permite que iniciantes, artistas e designers criem sistemas funcionais (chamados de *sketches*) que sentem e respondem ao mundo físico sem a necessidade de profundos conhecimentos técnicos em eletrônica ou programação de baixo nível.

**Vantagens**

*   **Facilidade e Acessibilidade:** Projetado para pessoas sem experiência prévia, incluindo farta documentação e exemplos de código.
*   **Baixo Custo:** As placas são baratas e o software é gratuito, de código aberto e multiplataforma (roda em Windows, Mac e Linux).
*   **Comunidade Global:** Possui uma vasta comunidade ativa que compartilha projetos e soluções em fóruns e wikis como o *Arduino Playground*.
*   **Hardware Aberto:** Os esquemas das placas são públicos, permitindo que qualquer pessoa fabrique suas próprias versões ou módulos de expansão (**shields**).
*   **Desenvolvimento Ágil:** Favorece a implementação imediata de ideias, permitindo testar conceitos rapidamente.

**Desvantagens**

*   **Eficiência de Memória:** O uso das bibliotecas de abstração consome significativamente mais memória flash e RAM do que um código escrito puramente em C ou Assembly.
*   **Desempenho Reduzido:** Comandos abstratos como `digitalWrite` podem ser mais de **30 vezes mais lentos** do que o acesso direto aos registradores do microcontrolador.
*   **Limitações de Depuração:** A IDE padrão não oferece ferramentas nativas para a **depuração (*debug*)** passo a passo no hardware, o que dificulta a resolução de problemas em projetos profissionais complexos.
*   **Baixa Portabilidade:** Códigos dependentes das funções específicas do framework (Wiring) geralmente não funcionam em outras plataformas de hardware que não suportam a mesma camada de abstração.

**Exemplos de outros frameworks e ambientes**

*   **chipKIT:** Uma das primeiras plataformas a suportar a compilação de código Arduino para microcontroladores PIC32.
*   **openFrameworks:** Conjunto de bibliotecas C++ voltado para componentes de áudio, vídeo e gráficos, que interage com o Arduino para expandir suas capacidades.
*   **Atmel Software Framework (ASF):** Biblioteca profissional que fornece milhares de exemplos e drivers para microcontroladores AVR e ARM.
*   **.NET Compact Framework:** Sistema da Microsoft que permite a execução de aplicações em linguagens como C# e Visual Basic em dispositivos embarcados.

---


# 2 Arduino x C x Asm

A comparação foi desenvolvida comparando os arquivos .hex gerados pela compilação após cada uma das três formas de codificação propostas: Framework Arduino, C e Assembly. Sendo que os três códigos executam o mesmo programa, que consiste em duas saídas digitais piscando de forma alternada e condicionada ao valor de uma entrada digital, assim, quando a entrada possui o valor lógico `1`, as saídas piscam alternadamente com intervalo de aproximadamente 500 ms e a entrada com o valor lógico `0` produz um desligamento das saídas. 

Segue o código feito das três formas propostas.


> Código utilizando o *framework* Arduino.


``` Arduino

// Código .ino

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode( 8, INPUT);
}

void loop()
{
  if( digitalRead(8) == 1 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}

```

---

> Código fonte em linguagem C para AVR.

``` c

// Código .c

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{   
    DDRB = 0b00110000;
    PORTB = 0;
    while (1)
    {
        if( PINB & (1<<0))
        {
            PORTB |= (1<<4);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            PORTB ^= (1<<4 | 1<<5);
            _delay_ms(500);
        }
        else
        {
            PORTB &= ~(1<<4);
            PORTB &= ~(1<<5);
        }
    }
}
```



---

> Código fonte em linguagem Assembly para AVR.

``` Asm

; Código .asm

            ; Inclusão das definições de pinos fornecidas pelo fabricante
.include "m328pdef.inc"

                ; Programa alocado no enderaço 0 da memória de código.
.ORG 0X0000

                ; PB5, PB4: out;    PB0: in;	0b00110000 = 0x30
    LDI	    R16,0x30
    OUT 	DDRB,R16

DESLIGA_LEDS:
    LDI	    R16,0x00
    OUT	    PORTB,R16

INICIO:
    IN	    R16,PINB
    SBRS	R16,0
    RJMP	DESLIGA_LEDS

    RCALL	DELAY
    SBI	    PORTB,PB5
    CBI	    PORTB,PB4
    RCALL	DELAY
    CBI	    PORTB,PB5
    SBI	    PORTB,PB4
    RJMP	INICIO

DELAY:
    LDI	    R16,0
    LDI	    R17,0
    LDI	    R18,41
DELAY_LOOP:
    INC	    R16
    BRNE	DELAY_LOOP
    INC	    R17
    BRNE	DELAY_LOOP
    DEC	    R18
    BRNE	DELAY_LOOP
    RET

```

> O arquivo de inclusão do projeto em Assembly [`m328pdef.inc`](https://codeberg.org/JoseWRPereira/sitap-cp/src/branch/main/11-cp-avr-atmega328p/01_5-asm-sinalizador_de_garagem/m328pdef.inc) contém a definição dos registradores e seus respectivos endereços. Este arquivo é fornecido pelo fabricante.


---

Após a compilação dos códigos, são gerados arquivos .hex equivalentes em comportamento, porém com uma diferença absurda em termos de ocupação de memória.

![Arduino_C_Asm](img/framework-arduino_c_asm.png)

---










---

# Referências

1. ANDERSON, Rick; CERVO, Dan. **Pro Arduino**: Arduino Expert Topics and Techniques. New York: Apress, 2013.

2. LIMA, Charles Borges de; VILLAÇA, Marco Valério Miorim. **AVR e Arduino**: Técnicas de Projeto. 2. ed. Florianópolis: Edição dos Autores, 2012.

3. MARGOLIS, Michael. **Arduino Cookbook**. 2. ed. [S. l.]: O'Reilly Media, 2012.

4. NOERGAARD, Tammy. **Embedded Systems Architecture**: A Comprehensive Guide for Engineers and Programmers. Oxford: Elsevier, 2005.

5. PEREA, Francis. **Arduino Essentials**. Birmingham: Packt Publishing, 2015.

6. PURDUM, Jack. **Beginning C for Arduino**: Learn C Programming for the Arduino and Compatible Microcontrollers. New York: Apress, 2012.

7. RUSSELL, David J. **Introduction to Embedded Systems**: Using ANSI C and the Arduino Development Environment. [S. l.]: Morgan & Claypool, 2010.


---
