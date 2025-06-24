


# [TerasIC DE1-SoC](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=836) for Intel FPGA University Program

| Característica | DE1-SoC |
|:---------------|:-------:|
| FPGA Device     | Cyclone V SoC 5CSEMA5F31C6N |
| FPGA Logic Elements | 85K |
| Processor | ARM Cortex-A9 Dual-Core |
| HPS SDRAM | 1GB DDR3 |
| FPGA SDRAM |64MB SDRAM|
| USB | Host x2|
| Ethernet | 1 Gigabit |
| UART | UART to USB |
| Video In | Composite-in |
| Video Out | 24-bit VGA DAC |
| Audio | 24-bit Coded |
| FPGA Expansion | 40-pin GPIO x2 |
| HPS Expansion | LTC Connector (I2C/SPI) |
| User LED/Button/Switch/7-SEG | 11 LEDs/10 Switches/4 Buttons/6 7-SEG |
| ADC | 8ch / 12-bit |
| Sensor | G-sensor |
| Other Interface | PS/2 & IR Emitter/Receiver |


## Especificações

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

| Figura 1: Diagrama de blocos - DE1-Soc DevKit         |
|:-----------------------------------------------------:|
| ![blockDiagram](img/blockDiagram-DE1_SoC-DevKit.png)  |
| Fonte: [DE1-SoC Development and Education Kit](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=2#heading) |




---





Driver no linux (Debian)
- [USB Blaster](https://www.rocketboards.org/foswiki/Documentation/UsingUSBBlasterUnderLinux)



---

[My First FPGA Tutorial](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=&No=658#contents)


---

# Referências

1. [DE1-SoC Development and Education Kit | terasIC](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=205&No=836&PartNo=1#contents)
2. [Digital System Design (DSD) | kevinwlu github](https://github.com/kevinwlu/dsd)
3.
