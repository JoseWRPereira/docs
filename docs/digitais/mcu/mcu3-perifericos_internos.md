---
title: 3. Periféricos
icon: fontawesome/solid/arrow-right-to-bracket
author: José W. R. Pereira
tags: 
    - Microcontrolador
    - MCU
    - MCMP
    - AVR
---

# Periféricos

Um **microcontrolador (MCU)** é um sistema microprocessado que integra, em um **único chip**, a unidade de processamento, memórias e diversas funcionalidades conhecidas como **periféricos**. Diferente dos microprocessadores de uso geral (MPU), que requerem componentes externos para funcionar, o microcontrolador é projetado para **aplicações específicas**, onde a alta integração reduz custo, tamanho e consumo de energia.

---

# Periféricos Internos

Os **periféricos internos** são módulos de hardware integrados no **mesmo encapsulamento** da CPU, atuando como extensões que realizam tarefas dedicadas sem a necessidade de componentes extras na placa. Eles incluem as portas de entrada e saída de uso geral (**GPIO**), **temporizadores e contadores** (timers), comparadores analógicos e conversores de sinal, como o **ADC** (Analógico-Digital). Interfaces de comunicação como **USART, SPI e I2C (ou TWI)** também são periféricos internos comuns, permitindo que o chip se comunique com outros dispositivos. Esses módulos internos trocam informações com o processador através de **barramentos de dados e controle** embutidos no silício, como o barramento de periféricos privados (PPB).

---

# Periféricos Externos

Os **periféricos externos**, por outro lado, são dispositivos que residem **fora do chip** do processador e são conectados a ele através de seus pinos de entrada e saída. Eles são utilizados para suplementar a funcionalidade do sistema e permitir a interação com o **mundo físico**. Exemplos típicos incluem **displays de cristal líquido (LCD)**, teclados matriciais, **motores de passo**, sensores de temperatura externos (como o TC72) e cartões de memória (**SD/MMC**). Para que o microcontrolador interaja com esses componentes, geralmente é necessário um **circuito de interface** ou *driver* (como uma Ponte H para motores) que ajuste os níveis de tensão ou corrente.



Em resumo, a diferença fundamental é que os periféricos internos fazem parte da **arquitetura do chip**, enquanto os externos são componentes de hardware conectados para atender às necessidades da **aplicação final**. O programador gerencia ambos através de **registradores de controle e status**, que funcionam como o "painel de controle" do microcontrolador, permitindo ligar, desligar ou configurar cada funcionalidade.

---

# Referências

1. LIMA, Charles Borges de; VILLAÇA, Marco V. M. **AVR e Arduino: técnicas de projeto**. 2. ed. Florianópolis: Edição dos Autores, 2012..
2. VALVANO, Jonathan W. **Embedded Systems: Introduction to ARM® Cortex™-M Microcontrollers**. 5. ed. [S.l.]: Jonathan Valvano, 2014. v. 1..
3. [**SAP-1**](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.ic.unicamp.br/~ducatte/mc542/2012S2/sap-1.pdf&ved=2ahUKEwiDudPG_7OSAxXOK7kGHaWnASEQFnoECBIQAQ&usg=AOvVaw1vCyc0wwa3fZKVV3eVa875) (Simple-As-Possible Computer 1).

---
