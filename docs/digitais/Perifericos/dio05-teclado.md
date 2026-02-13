---
title: 05 - Teclado Matricial 
icon: fontawesome/solid/keyboard
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

![atmega328](img/teclado-capa.png)

# 1. Teclado Matricial 4x4

Um **teclado matricial** é uma interface de entrada composta por botões (chaves tácteis) organizados em um arranjo de **linhas e colunas**. Essa técnica é amplamente utilizada em sistemas embarcados para **maximizar o uso dos pinos de I/O** do microcontrolador.

Diferente de conectar cada botão individualmente a um pino, o teclado matricial interconecta as chaves de forma que $N$ linhas e $M$ colunas resultem em $N \times M$ teclas utilizando apenas $N + M$ pinos. Por exemplo:

*   Um teclado de **16 teclas (4×4)** utiliza apenas **8 pinos** do microcontrolador, em vez de 16.
*   Internamente, as teclas são interruptores do tipo **Normalmente Aberto (NA)**. Quando uma tecla é pressionada, ela cria um curto-circuito elétrico entre uma linha e uma coluna específica.

## 1.1 Como usar: Conexão e Hardware
Para o funcionamento correto, o hardware deve garantir que os pinos de entrada não fiquem "flutuando".

*   **Conexão física:** Geralmente, as **linhas** são configuradas como **entradas** (com resistores de *pull-up* ou *pull-down*) e as **colunas** como **saídas** de controle. 
*   **Resistores:** O uso de resistores é fundamental para manter um nível lógico conhecido quando nenhuma tecla está pressionada. Em microcontroladores com **pull-ups internos**, eles são utilizados frequentemente para simplificar o circuito.

## 1.2 A Técnica de Varredura (*Scanning*)
A leitura do teclado não ocorre de forma passiva; o microcontrolador executa um processo sequencial chamado **varredura**:

1.  O sistema coloca nível lógico baixo (0) em apenas **uma coluna** por vez, mantendo as outras em nível alto (1) ou alta impedância.
2.  O software então **lê o estado das linhas**. Se uma linha apresentar nível baixo, significa que a tecla correspondente ao cruzamento daquela linha com a coluna ativa foi pressionada.
3.  Esse processo se repete rapidamente para todas as colunas, de modo que a percepção para o usuário seja instantânea.

## 1.3 Implementação em Software
Para converter o sinal elétrico em um caractere útil, o programador utiliza:

*   **Matriz de Decodificação:** Uma tabela (*lookup table*) no código que associa os índices de linha e coluna aos caracteres desejados (como '1', '2', '3', 'A').
*   **Debounce:** Assim como em botões simples, é necessário aplicar um **atraso (delay)** de aproximadamente 10 ms a 20 ms para ignorar o ruído mecânico dos contatos antes de validar a tecla.


![teclas](img/teclado-teclas.gif)


## 1.4 Alternativa: Leitura via ADC
Uma técnica avançada e ainda mais econômica em pinos consiste em utilizar uma **rede resistiva** ligada a um **Conversor Analógico-Digital (ADC)**. Nesse arranjo, cada tecla pressionada gera uma **tensão única** em um único pino analógico, permitindo ler até 16 teclas com apenas **um pino** de I/O, embora exija resistores de precisão para evitar erros de leitura.
