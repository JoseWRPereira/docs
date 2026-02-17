---
title: 01 - Entrada/Saída Digital
icon: fontawesome/solid/lightbulb
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

![atmega328](img/atmega328p_pin.png)


# Entrada/Saída Digital - *Digital Input/Output*

---



## 1. Saídas Digitais

Uma **saída digital** é um recurso fundamental de um sistema embarcado que permite ao microcontrolador interagir com elementos externos, enviando sinais que possuem apenas **dois estados lógicos possíveis**: o estado "ligado" (on) e o estado "desligado" (off). Esses estados são representados, respectivamente, pelos valores binários **'1' e '0'**.

### 1.1 Representação Elétrica e Níveis Lógicos
Os valores lógicos de uma saída digital são traduzidos em **níveis de tensão** específicos:

*   **Nível Lógico Baixo (0 ou LOW):** Corresponde geralmente a **0V** (terra ou ground).
*   **Nível Lógico Alto (1 ou HIGH):** Corresponde à tensão de alimentação do circuito, geralmente **5V ou 3,3V**.
*   **Estado de Alta Impedância (Z):** Representa uma saída "desconectada" eletricamente, onde o pino não drena nem fornece corrente considerável.



### 1.2 Capacidade Elétrica e Restrições
As saídas digitais possuem limitações físicas que devem ser respeitadas para não danificar o componente:

*   **Limite de Corrente:** Cada pino pode fornecer ou receber uma corrente limitada. No caso do ATmega328, o limite é de **40 mA** por pino, sendo recomendado manter-se em torno de **20 mA** para operação segura.
*   **Drivers Externos:** Quando a carga a ser controlada exige mais corrente do que a saída pode fornecer (como motores ou relés), é necessário utilizar circuitos de interface, como **chaves transistorizadas** ou CIs de potência como o **ULN2003**.


### 1.3 Funções Alternativas
Muitos pinos de saída podem ser multiplexados para servir como saídas de periféricos internos específicos, como:

- **USART:** O pino TXD (transmissão de dados seriais) é forçado como saída sempre que o transmissor está habilitado;
- **PWM:** Pinos de comparação de saída (como OC0A, OC1A) enviam sinais de modulação por largura de pulso para controle de potência;
- **SPI:** O pino MOSI atua como a saída de dados do mestre na comunicação serial periférica
.

###  1.4 Aplicações Comuns
As saídas digitais são usadas para controlar uma vasta gama de periféricos, incluindo:

*   **LEDs:** Atuando como sinalizadores visuais.
*   **Displays:** Acionando displays de 7 segmentos ou módulos LCD.
*   **Transistores:** Para o chaveamento de Reles, Sinaleiros, Motores CC entre outros. 



## 2. Entradas Digitais

Uma **entrada digital** é o recurso de um sistema embarcado que permite ao microcontrolador **ler estados binários do mundo físico**. Diferente de um sinal analógico, que é contínuo, o sinal digital possui apenas dois estados claramente definidos: **ligado ou desligado**, representados logicamente como **'1' e '0'**.


### 2.1 Representação Elétrica
Os estados lógicos de uma entrada digital são traduzidos por níveis de tensão elétrica:

*   **Nível Lógico Baixo (LOW / 0):** Geralmente correspondente a **0V (GND)**.
*   **Nível Lógico Alto (HIGH / 1):** Geralmente correspondente à tensão de alimentação, como **5V ou 3,3V**.
*   **Limiares de Tensão:** Para evitar incertezas, os microcontroladores definem faixas de tolerância. Por exemplo, em alguns sistemas de 3,3V, tensões entre 2V e 5V são interpretadas como HIGH, enquanto entre 0V e 1,3V são consideradas LOW.

### 2.2 Estado de Alta Impedância (Hi-Z)
Quando um pino é configurado como entrada, ele se comporta como uma **alta impedância**. Isso significa que o pino atua como se estivesse eletricamente "desconectado", permitindo que um dispositivo externo (como um sensor ou botão) controle a tensão no pino com facilidade, sem que o microcontrolador interfira nesse sinal.

### 2.3 Pinos Flutuantes e Resistores de Pull-up/Pull-down
Um pino de entrada nunca deve ser deixado "flutuando" (sem conexão definida), pois ruídos eletromagnéticos podem causar leituras erráticas. Para garantir estabilidade, utilizam-se resistores:

*   **Pull-up:** Conecta o pino ao **VCC**, mantendo-o em nível HIGH por padrão até que um sinal externo o leve ao GND.
*   **Pull-down:** Conecta o pino ao **GND**, mantendo-o em nível LOW até que um sinal externo o leve ao VCC.
*   **Pull-ups Internos:** Microcontroladores modernos, como o ATmega328P, possuem **resistores de pull-up internos** que podem ser ativados via software, simplificando o circuito externo.

### 2.4 Configuração e Leitura
No contexto de arquiteturas como a do AVR, o gerenciamento é feito por registradores específicos:

*   **Configuração:** Deve-se escrever o valor **'0'** no bit correspondente do registrador **DDR (Data Direction Register)**. No Arduino, usa-se `pinMode(pino, INPUT)`.
*   **Leitura:** O estado físico do pino é lido através do registrador **PIN (Port Input Pins)**. No Arduino, utiliza-se a função `digitalRead(pino)`, que retorna HIGH ou LOW.

### 2.5 Desafios Práticos: O Bounce
Ao usar entradas digitais com componentes mecânicos (como botões), ocorre o fenômeno do **bounce (trepidação)**. Devido ao contato físico metálico, o sinal oscila rapidamente entre 0 e 1 antes de estabilizar. Para evitar que o microcontrolador interprete isso como múltiplos cliques, é necessário implementar técnicas de **debounce** via software (atrasos) ou hardware (filtros).


###  2.6 Aplicações Comuns
As entradas digitais são usadas para interagir uma vasta gama de periféricos, incluindo:

- **Botões e Chaves Tácteis:** Utilizados para ações simples como ligar/desligar um acionamento ou processo;
- **Teclados Matriciais:** Empregados quando há necessidade de inserir dados complexos, como em controles de acesso por senha numérica ou calculadoras, permitindo ler várias teclas com poucos pinos de I/O;
- **Sensores e fins de curso**: Detectam a presença de um objeto a ser contato, por exemplo, ou o momento de finalizar uma movimentação.


## 3. Configuração e Funcionamento Interno

Em microcontroladores como o **ATmega328P** (usado no Arduino), o comportamento de um pino como saída digital é gerenciado por registradores de memória internos:

*   **DDRx (Data Direction Register):** É o registrador de direção; para configurar um pino como saída, o programador deve escrever o valor **'1'** no bit correspondente deste registrador.
*   **PORTx (Data Register):** Uma vez configurado como saída, a escrita neste registrador define o estado do pino. Escrever `1` coloca o pino em nível alto (VCC) e escrever `0` coloca-o em nível baixo (0V).
*   **PINx (Port Input Pins):** É o registrador exclusivo de leitura. Ao acessá-lo, o microcontrolador lê o estado atual do buffer de entrada, que reflete se a tensão no pino é alta (1) ou baixa (0) no exato momento da leitura.

No ambiente **Arduino**, essas operações são simplificadas pelas funções `pinMode(pino, OUTPUT)` para configuração, `digitalWrite(pino, valor)` para o acionamento e `digitalRead(pino)` para a leitura.


### 5.1 DDR (Data Direction Register)
O **DDR** é o **registrador de direção de dados**. Sua função exclusiva é configurar se um pino específico se comportará como uma **entrada** ou como uma **saída**.

*   **Configuração como Saída:** Escreve-se o valor lógico **'1'** no bit correspondente do DDR. Isso habilita um buffer (tri-state) que conecta internamente o registrador de dados ao pino físico.
*   **Configuração como Entrada:** Escreve-se o valor lógico **'0'** no bit correspondente. Isso desabilita o buffer de saída, permitindo que um dispositivo externo controle a tensão no pino com segurança.
*   **Equivalência no Arduino:** Configurar o DDR é o equivalente direto de usar a função `pinMode(pino, OUTPUT)` ou `pinMode(pino, INPUT)`.

### 5.2 PORT (Data Register)
O **PORT** é o **registrador de dados**, utilizado para definir o estado lógico enviado para o pino ou para configurar recursos internos, dependendo da direção definida no DDR. Sua função é dual:

*   **Quando o pino é Saída (DDR = 1):**
    *   Escrever **'1'** no bit do PORT coloca o pino em **nível lógico alto (5V ou VCC)**.
    *   Escrever **'0'** no bit do PORT coloca o pino em **nível lógico baixo (0V ou GND)**.
    *   **Equivalência no Arduino:** É o equivalente a usar `digitalWrite(pino, HIGH)` ou `digitalWrite(pino, LOW)`.
*   **Quando o pino é Entrada (DDR = 0):**
    *   Escrever **'1'** no bit do PORT habilita o **resistor de pull-up interno** para aquele pino. Esse resistor garante um nível lógico estável quando nada está conectado ao pino.
    *   Escrever **'0'** desabilita o pull-up, deixando o pino em estado de alta impedância (flutuante).


### 5.3 PIN (Port Input Pins)
o registrador PINx é utilizado para ler o estado lógico atual dos pinos físicos do microcontrolador.

- **Leitura Exclusiva:** Na maioria das operações, o PINx funciona como um registrador de leitura exclusiva
- **Recurso de Toggle (Inversão):** Uma característica específica de arquiteturas AVR mais modernas (como o ATmega328P) é que escrever o valor lógico '1' em um bit do registrador PINx resulta na inversão automática (toggle) do bit correspondente no registrador de dados PORTx, alternando seu estado entre alto e baixo sem a necessidade de uma operação de leitura-modificação-escrita complexa.

Internamente, cada bit do registrador PINx possui um hardware de sincronização composto por latches. Isso é necessário para evitar o fenômeno da metaestabilidade, garantindo que o valor lido seja estável mesmo que o sinal externo mude no momento da amostragem do clock interno. Devido a esse hardware de sincronização, existe um atraso de aproximadamente um ciclo de clock para que o dado físico chegue ao registrador interno. Por essa razão, se o código realizar uma leitura do PINx imediatamente após uma alteração no DDRx ou PORTx, é recomendado assim inserir uma instrução NOP (nenhuma operação) para dar tempo ao hardware de sincronizar o valor correto.


### 5.4 Organização e Grupos
Esses registradores são organizados em grupos (portas) de até **8 bits**, onde cada bit controla um pino físico específico. No ATmega328P, os grupos comuns são:

*   **DDRB / PORTB / PINB:** Controlam os pinos digitais 8 a 13 do Arduino.
*   **DDRC / PORTC / PINC:** Controlam os pinos A0 a A5 do Arduino.
*   **DDRD / PORTD / PIND:** Controlam os pinos digitais 0 a 7 do Arduino.

### 5.5 Resumo de Funcionamento
| DDR (bit n) | PORT (bit n) | Modo do Pino | Descrição |
| :--- | :--- | :--- | :--- |
| **0** | **0** | Entrada | Alta impedância (entrada simples). |
| **0** | **1** | Entrada | Entrada com resistor de **pull-up** ativado. |
| **1** | **0** | Saída | Saída em **nível baixo** (0V). |
| **1** | **1** | Saída | Saída em **nível alto** (5V). |

Manipular esses registradores diretamente é uma técnica avançada que permite alterar o estado de até 8 pinos simultaneamente com uma única linha de código, o que é muito mais rápido do que usar funções individuais da IDE Arduino.

### 5.6 Registradores PORT, DDR e PIN

![PORTBreg](img/io-PORTB_register.png)
![PORTCreg](img/io-PORTC_register.png)
![PORTDreg](img/io-PORTD_register.png)


---

### 5.7 Circuito geral dos pinos de entrada e saída

![IOGeral](img/io-geral.png)



### 5.8 Acionamento do circuito de entrada e saída em função do comando

![IOcmd](img/io-cmd.png)



---

## 6. Programando

Segue exemplo de uma aplicação de pisca led condicionado a uma entrada digital. 

| Função | Pino <br> (Arduino Uno) | Pino <br> (ATmega328P) | PORT |
|:------:|:---:|:---:|:---:|
| Entrada|  8 | 14 | PB0 |
| Saída  | 12 | 18 | PB4 |
| Saída  | 13 | 19 | PB5 |



```c
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{   
    DDRB = 0b00110000;
    PORTB = 0;
    while (1)
    {
        if( PINB & (1<<PINB0))
        {
            PORTB |= (1<<PORTB4);
            PORTB &= ~(1<<PORTB5);
            _delay_ms(500);
            PORTB ^= (1<<PORTB4 | 1<<PORTB5);
            _delay_ms(500);
        }
        else
        {
            PORTB &= ~(1<<PORTB4);
            PORTB &= ~(1<<PORTB5);
        }
    }
}

```


---


### 6.1 Configurando Entradas e Saídas

Para a configuração das entradas e saídas, é necessário que sejam definidos os pinos para cada função da interface na aplicação. 

A configuração dos pinos pode ser realizada de forma unitária ou através de uma escrita única em cada registrador, configurando todos os pinos representados por ele de uma só vez.

Para a configuração individual de pinos, é necessário usar o seguinte padrão de ligar um bit ou zerá-lo:

Para ligar (setar) um bit dentro de um registrador:
```C
  registrador |= (1<<numero_do_bit);
```

Para zerar (resetar) um bit dentro de um registrador:
```C
  registrador &= ~(1<<numero_do_bit);
```
Sendo o `numero_do_bit` um valor de `0` a `7`, ou ainda, podem-ser utilizados os `defines` declarados na biblioteca, como: `PINB0` que corresponde ao `0`, `PINB1` correpondente ao `1` e assim por diante. Da mesma forma para os PORT e o DDR: `PORTB0`, `PORTB1`,..., e `DDRB0`, `DDRB1`, ... 

Para configurar um pino como entrada, é necessário zerar o respectivo bit do registrador `DDRx` e ligar ou desligar o Resistor de Pull-up interno pelo registrador `PORTx`.

No exemplo, temos que configurar o `PB0` como entrada. Assim, são utilizados os registradores `DDRB` para a direção de entrada e o `PORTB` para desabilitar o Resistor de Pull-Up interno, pois no exemplo, é utilizado um resistor de Pull-Up externo.
```C
    // Configuração das Entradas
  DDRB &= ~(1<<0);      // PB0 <- 0
  PORTB &= ~(1<<0);     // PB0 Pull-up OFF
```

Ainda no exemplo, temos que configurar e inicializar os pinos de saída: PB4 e PB5. Da mesma forma, são utilizados os registradores `DDRB` para configuração de saída e `PORTB` para acionar um nível lógico no pino do microcontrolador.

```C
    // Configuração das Saídas
  DDRB |= (1<<4);       // PB4 <- 1
  DDRB |= (1<<5);       // PB4 <- 1
    // Inicialização do estado lógico dos pinos
  PORTB &= ~(1<<4);      // PB4 <- 0
  PORTB &= ~(1<<5);      // PB5 <- 0
```

Note que a função do registrador `PORTx` depende da configuração do registrador `DDRx`.

No nosso exemplo, todos os pinos utilizados pertencem ao mesmo PORT, assim, é possível realizar a configuração dos três elementos todos de uma única vez:

O bit 0 (PB0) deve ser configurado como entrada (E) e os bits 4 e 5 (PB4 e PB5) devem ser configurados como saídas (S).

```C
  // Configuração do registrador de direção de dados (Entrada / Saída)

  // DDRx = 0b--SS---E;

  // Onde:
  //      0b: Notação que indica número com notação binária.
  //      E: Entradas (0)
  //      S: Saída (1)
  //      -: Bit não utilizado.

  // Reescrevendo com os valores adequados no Registrador dos pinos PB0, PB4 e PB5:

  // DDRB = 0b--11---0;

  // Os pinos não utilizados (-) devem ser configurados como entradas (0):

  DDRB = 0b00110000;
```

Após a configuração do `DDRx` é a vez do `PORTx`.

```C
  // Configuração de resistor de pull-up para entradas e estado lógico para as saídas.

  // PORTB = 0b--SS---E;
  // Onde:
  //      E: Entradas (0)
  //      S: Saída (1)
  //      -: Bit não utilizado.

  // Como os bits não utilizados são entradas:

  // PORTB = 0bEESSEEEE;

  // Desligando os resistores de pull-up internos:

  // PORTB = 0b00SS0000;

  // Desligando o estado lógico das saídas PB4 e PB5:

  PORTB = 0b00000000;
```

Os valores carregados nos registradores são costumeiramente notados com valores em hexadecimal:

```C
  DDRB  = 0x30;
  PORTB = 0x00;
```

Qualquer forma de configuração pode ser utilizada, tanto um bit por vez quanto a escrita integral dos registradores, anotados com valores em binário, decimal ou hexadecimal.

---

### 6.2 Resumo da configuração dos pinos no ATmega328P

```
///////////////////////////////////////////////////////////////////////////////
//  Registradores de configuração e manipulação de dados nos pinos
//
//        DDRxn   :   Data Direction Register
//        PORTxn  :   Data Register
//        PINxn   :   Input Pin Address
//
//        ===================
//        x |        n
//        ===================
//        B | 7 6 5 4 3 2 1 0
//        C |   6 5 4 3 2 1 0
//        D | 7 6 5 4 3 2 1 0
//        E |         3 2 1 0
//        ===================
//
//  Configuração e Manipulação de dados nos pinos
//
//        DDRxn = 1;          // Output
//            {
//                PORTxn = 1; //          High
//                PORTxn = 0; //          Low
//            }
//
//        DDRxn = 0;          // Input
//            {
//                PORTxn = 0; //          Pull-Up Resistor OFF
//                PORTxn = 1; //          Pull-Up Resistor ON
//                {
//                    (PINxn == 1)    //  ON
//                    (PINxn == 0)    //  OFF
//                }
//            }
//        
////////////////////////////////////////////////////////////////////////////////
```

---

