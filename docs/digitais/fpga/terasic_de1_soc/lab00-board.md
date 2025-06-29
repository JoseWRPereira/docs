---
title: Lab00 - DevKit
icon: fontawesome/solid/earth-americas
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---

![Board](img/lab00-board.png)


# [TerasIC DE1-SoC](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=836) for Intel FPGA University Program

O Kit de Desenvolvimento (*Development Kit*) **DE1-SoC** apresenta uma plataforma robusta de **design de hardware** construída em torno do **FPGA System-on-Chip (SoC)** da Altera, que **combina núcleos embarcados Cortex-A9 dual-core com lógica programável** para **máxima flexibilidade de design**, aproveitando poder da **reconfigurabilidade** aliada a um sistema de **processador de alto desempenho e baixo consumo de energia**.

O SoC da Altera integra, como mostrado na Figura 1, um **sistema de processador rígido** ( **HPS** - *Hard Processor System*) baseado em **ARM**, composto por processador, periféricos e interfaces de memória, perfeitamente integrados à estrutura **FPGA** por meio de um ***backbone*** de interconexão de alta largura de banda.



| Figura 1: Diagrama de blocos - DE1-Soc DevKit         |
|:-----------------------------------------------------:|
| ![blockDiagram](img/lab00-blockDiagram-DE1_SoC-DevKit.png)  |
| Fonte: [DE1-SoC Development and Education Kit](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=2#heading) |

---

**Especificações**

1. FPGA Device
    - Cyclone V SoC 5CSEMA5F31C6 Device
    - Dual-core ARM Cortex-A9 (HPS)
    - 85K Programmable Logic Elements
    - 4,450 Kbits embedded memory
    - 6 Fractional PLLs
    - 2 Hard Memory Controllers
2. Configuration and Debug
    - Serial Configuration device – EPCS128 on FPGA
    - On-Board USB Blaster II (Normal type B USB connector)
3. Memory Device
    - 64MB (32Mx16) SDRAM on FPGA
    - 1GB (2x256Mx16) DDR3 SDRAM on HPS
    - Micro SD Card Socket on HPS
4. Communication
    - Two USB 2.0 Host Ports (ULPI interface with USB type A connector) on HPS
    - UART to USB (USB Mini B connector)
    - 10/100/1000 Ethernet
    - PS/2 mouse/keyboard
    - IR Emitter/Receiver
5. Connectors
    - Two 40-pin Expansion Headers (voltage levels: 3.3V)
    - One 10-pin ADC Input Header
    - One LTC connector (One Serial Peripheral Interface (SPI) Master ,one I2C and one GPIO interface )
6. ADC
    - Sample rate: 500 KSPS
    - Channel number: 8
    - Resolution: 12 bits
    - Analog input range : 0 ~ 4.096 V
7. Switches, Buttons and Indicators
    - 4 User Keys (FPGA x4)
    - 10 User switches (FPGA x10)
    - 11 User LEDs (FPGA x10 ; HPS x 1)
    - 2 HPS Reset Buttons (HPS_RST_n and HPS_WARM_RST_n)
    - Six 7-segment displays
8. Sensors
    - G-Sensor on HPS
9. Power
    - 12V DC input


---

**Layout**

A Figura 2 ilustra a distribuição na parte superior da placa de desenvolvimento dos dispositivos associados ao FPGA e ao HPS.
Os diversos dispositivos da placa e os conectores podem ser vistos na distribuição apresentada na Figura 2.

| Figura 2: Layout superior da placa DE1-SoC                 |
|:-------------------------------------------------:|
| ![layout](img/lab00-DE1-SoC_Layout_top_01-01.jpg) |
| Fonte: [DE1-SoC Development and Education Kit](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=3#heading) |

| Figura 3: Layout inferior da placa DE1-SoC                 |
|:-------------------------------------------------:|
| ![layout](img/lab00-DE1-SoC_Layout_bot_01-01.jpg) |
| Fonte: [DE1-SoC Development and Education Kit](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=3#heading) |


---

**Distribuição de Clock no DE1-SoC**

| Figura : Diagrama de blocos da distribuição de clock no DE1-SoC |
|:---------------------------------------------------------------:|
| ![diagramaBlocos_clockDistribution](img/lab00-blockDiagram-ClockDistribution_DE1-SoC.png) |
| Fonte: Manual do usuário DE1-SoC - rev. F/G - pág. 22           |

**Tabela 1: Atribuição de pinos de clock**

|  Signal Name  |  FPGA Pin No.   |  Description        | I/O Standard  |
|:-------------:|:---------------:|:-------------------:|:-------------:|
| CLOCK_50      | PIN_AF14        | 50 MHz clock input  | 3.3V          |
| CLOCK2_50     | PIN_AA16        | 50 MHz clock input  | 3.3V          |
| CLOCK3_50     | PIN_Y26         | 50 MHz clock input  | 3.3V          |
| CLOCK4_50     | PIN_K14         | 50 MHz clock input  | 3.3V          |
| HPS_CLOCK1_25 | PIN_D25         | 25 MHz clock input  | 3.3V          |
| HPS_CLOCK2_25 | PIN_F25         | 25 MHz clock input  | 3.3V          |

---


---



Driver no linux (Debian)
- [USB Blaster](https://www.rocketboards.org/foswiki/Documentation/UsingUSBBlasterUnderLinux)



---

[My First FPGA Tutorial](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=&No=658#contents)


---

- [Manual do usuário DE1-SoC - rev.F/G](https://www.terasic.com.tw/cgi-bin/page/archive_download.pl?Language=English&No=836&FID=3a3708b0790bb9c721f94909c5ac96d6)

---
# Referências

1. [DE1-SoC Development and Education Kit | terasIC](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=1#contents)
2. [Digital System Design (DSD) | kevinwlu github](https://github.com/kevinwlu/dsd)
3.
