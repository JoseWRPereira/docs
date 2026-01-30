---
title: Periféricos Internos
icon: fontawesome/solid/arrow-right-to-bracket
author: José W. R. Pereira
tags: 
    - Microcontrolador
    - MCU
    - MCMP
    - AVR
---

# 

Um **microcontrolador (MCU)** é essencialmente um "computador em um único chip", que integra em um único encapsulamento a unidade de processamento, memórias e diversos periféricos. Para entender sua estrutura e interações internas, podemos dividir o conceito em três pilares fundamentais:

# 1. Arquitetura e Organização de Barramentos

A forma como os componentes internos se comunicam é definida por sua arquitetura de barramentos:

*   **Von Neumann:** Utiliza um **único barramento** para tráfego de dados e instruções, o que simplifica o design, mas pode criar um gargalo de processamento.

*   **Harvard:** Possui **barramentos e memórias fisicamente separados** para dados e instruções, o que permite ao processador buscar uma instrução e acessar dados simultaneamente, aumentando o desempenho através do *pipeline*.

*   **ISA (Arquitetura de Conjunto de Instruções):** Define as operações que o processador pode executar, sendo as mais comuns a **RISC** (instruções simples e de tamanho fixo, focadas em velocidade) e a **CISC** (instruções complexas que realizam múltiplas operações de uma vez).

| Figura: Arquiteturas internas de microcontroladores |
|:---------------------------------------------------:|
| ![arquitetura](img/mcu03-barramentos.png) |
| Fonte: Datasheet [STM32F103xx](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.st.com/resource/en/datasheet/stm32f103c8.pdf&ved=2ahUKEwjNzMOW_LOSAxXNALkGHUPoNqcQFnoECAQQAQ&usg=AOvVaw0rd6I_7fuhTLdZOoycvGV5) [AT89C51ED2](https://www.microchip.com/en-us/product/at89c51ed2)|

---

# 2. Partes Fundamentais (Estrutura Interna)

Os componentes principais que residem dentro do chip são:

*   **CPU (Unidade Central de Processamento):** É o "cérebro" composto pela **Unidade de Controle (CU)**, que coordena as operações; pela **Unidade Lógica e Aritmética (ALU)**, que realiza cálculos e testes lógicos; e por **Registradores**, que são memórias ultra-rápidas para armazenamento temporário de dados de trabalho.

*   **Memórias Internas:**
    *   **Flash:** Memória não volátil onde o **firmware** (programa) é armazenado.
    *   **SRAM:** Memória volátil de acesso rápido para variáveis e dados de execução.
    *   **EEPROM:** Usada para armazenar dados que precisam ser preservados mesmo sem energia, como configurações.

*   **Periféricos:** Os principais periféricos internos encontrados em microcontroladores modernos, como a família **AVR (ATMega328P)** e **ARM Cortex-M**, incluem:
    *   **Portas de Entrada e Saída de Uso Geral (GPIO):** São as interfaces mais comuns, permitindo a conexão com dispositivos digitais como botões e LEDs. Elas são organizadas em registradores (como o **DDR**, que define a direção, e o **PORT**, que define o nível lógico) e podem ser multiplexadas com outras funções internas para otimizar o número de pinos do componente.
    *   **Temporizadores e Contadores (Timers/Counters):** Essenciais para o gerenciamento de tempo, esses módulos permitem contar eventos externos ou gerar intervalos de tempo precisos para interrupções periódicas. Eles também são a base para a geração de sinais **PWM (Modulação por Largura de Pulso)**, fundamentais no controle de potência de motores e intensidade de luz.
    *   **Conversores de Sinal:** 
        *   **ADC (Conversor Analógico-Digital):** Traduz grandezas físicas (como temperatura ou luz lidas por sensores analógicos) em valores binários que o processador consegue interpretar.
        *   **Comparador Analógico:** Compara as tensões em dois pinos de entrada, alterando sua saída digital de acordo com qual sinal é maior, o que é útil para detecção de níveis de tensão e alarmes.
    *   **Interfaces de Comunicação:** Permitem que o microcontrolador troque dados com outros circuitos ou computadores. As mais comuns são:
        *   **USART/UART:** Comunicação serial assíncrona, muito utilizada para terminais de depuração e módulos Bluetooth ou RF.
        *   **SPI (Serial Peripheral Interface):** Protocolo síncrono de alta velocidade, ideal para cartões SD e displays gráficos.
        *   **I2C ou TWI (Two-Wire Interface):** Barramento de dois fios que permite conectar múltiplos dispositivos de baixa velocidade, como sensores de temperatura e relógios de tempo real (RTC).
    *   **Módulos de Supervisão e Segurança:**
      *   **Watchdog Timer (WDT):** Funciona como um "cão de guarda" que reinicializa o sistema automaticamente caso o programa trave devido a erros ou interferências, garantindo a confiabilidade de sistemas críticos.
      *   **Controlador de Interrupções (como o NVIC no ARM):** Gerencia a prioridade e a execução de tarefas que devem interromper o fluxo normal do programa para responder a eventos imediatos.

    Além desses, dependendo do modelo, podem estar integrados outros periféricos sofisticados como controladores **USB, CAN** (comum em veículos) e até interfaces **Ethernet** para conectividade de rede direta. A integração desses recursos no mesmo silício reduz drasticamente o custo, o tamanho físico das placas de circuito impresso e o consumo de energia, tornando os microcontroladores a escolha ideal para sistemas embarcados e dispositivos de **Internet das Coisas (IoT)**.

    Além disso, muitos microcontroladores modernos também incluem recursos de **segurança**, como **criptografia** e **autenticação**, para proteger dados e garantir a integridade dos sistemas. 

---

# 3. Interações Internas: O Ciclo de Operação

As interações ocorrem de forma sincronizada por um sinal de **Clock**, que dita o ritmo das transferências de dados entre a CPU, a memória e os periféricos. O processamento segue quatro etapas principais:

1.  **Buscar (Fetch):** A CPU busca a instrução na memória de programa no endereço apontado pelo **Contador de Programa (PC)**.

2.  **Decodificar (Decode):** A instrução é carregada no **Registrador de Instrução (IR)** e traduzida pela Unidade de Controle em sinais elétricos de comando.

3.  **Executar (Execute):** A ALU realiza a operação matemática ou lógica solicitada.

4.  **Armazenar (Store):** O resultado é gravado de volta em um registrador ou na memória de dados.

Além desse ciclo, o microcontrolador interage com o mundo externo através de **interrupções**, eventos de hardware que suspendem temporariamente a execução do programa principal para atender a uma tarefa imediata e prioritária, garantindo a natureza reativa do sistema.



---

# Referências

1. LIMA, Charles Borges de; VILLAÇA, Marco V. M. **AVR e Arduino: técnicas de projeto**. 2. ed. Florianópolis: Edição dos Autores, 2012..
2. VALVANO, Jonathan W. **Embedded Systems: Introduction to ARM® Cortex™-M Microcontrollers**. 5. ed. [S.l.]: Jonathan Valvano, 2014. v. 1..
3. [**SAP-1**](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.ic.unicamp.br/~ducatte/mc542/2012S2/sap-1.pdf&ved=2ahUKEwiDudPG_7OSAxXOK7kGHaWnASEQFnoECBIQAQ&usg=AOvVaw1vCyc0wwa3fZKVV3eVa875) (Simple-As-Possible Computer 1).

---
