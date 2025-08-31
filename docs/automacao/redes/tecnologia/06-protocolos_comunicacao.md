---
title: Protocolos de Comunicação
icon: fontawesome/solid/language
author: José W. R. Pereira
tags:
    - Redes Industriais
    - Protocolos de Comunicação
    - RPI
---

#

**[Protocolo de comunicação <br> MODBUS](../slides/aula06-protocolo_de_comunicacao_MODBUS.pdf)**

---

- Introdução;
- Modicon, protocolo aberto;
- Conexão e cabo de transmissão;
- Modbus e modelo ISO/OSI;
- Cliente-Servidor - Unicast x Broadcast;
- Codificação da mensagem - RTU e Ascii;
- Modelo de organização da memória;
- Unidade de dados de protocolo (PDU);
- Frame e temporização em modo RTU;
- Codificação da mensagem.

---

**Principais protocolos de comunicação industriais**

0.  **Modbus**: Um dos protocolos mais antigos e difundidos, estabelecendo um padrão para a troca de dados em sistemas de automação.
1. **Profibus**: Desenvolvido pela Siemens, é um protocolo de comunicação de campo para automação de processos, permitindo a troca de dados entre dispositivos e controladores. 
2. **Profinet**:  A evolução do Profibus, é um protocolo de Ethernet Industrial que permite uma comunicação mais rápida e eficiente, suportando a arquitetura da Indústria 4.0. 
3. **Ethernet/IP**: Um protocolo de Ethernet Industrial suportado pela ODVA, amplamente utilizado para comunicação de aplicações e controle. 
4. **CANopen**: Baseado no CAN (Controller Area Network), é um protocolo de comunicação em tempo real utilizado em sistemas de automação, robótica e equipamentos automotivos. 
5. **DeviceNet**: Um protocolo de automação que permite a conexão e comunicação de dispositivos no chão de fábrica. 
6. **EtherCAT**: Um protocolo de Ethernet Industrial de alta performance, conhecido por sua velocidade e eficiência em aplicações de controle de movimento. 
7. **HART**: Faz comunicação digital bidirecional usando loops de corrente analógica. Auxilia na calibração e no ajuste de damping e range de diversos dispositivos industriais, como sensores e atuadores.
8. **ASi**: Para projetos de automação é um protocolo prático e barato, ideal para maquinário de pequeno porte, realizando a conectividade digital de atuadores e sensores com os seus respectivos controladores.
9. **Zigbee**: É um protocolo de comunicação sem fio projetado para dispositivos de baixo consumo de energia e baixa taxa de dados, ideal para automação residencial e industrial, como sensores e lâmpadas inteligentes.
10. **OPC UA** (*Open Platform Communications Unified Architecture*): Um padrão de comunicação aberto e seguro para a troca de dados, que se baseia na tecnologia binária para garantir a interoperabilidade entre diversos dispositivos e sistemas. 
11. **MQTT** (*Message Queue Telemetry Transport*): Um protocolo leve e flexível, ideal para sistemas de IoT, com baixo consumo de energia e aplicável em dispositivos com restrições de hardware e redes com banda limitada. 
12. **IO-Link**: Uma interface padrão aberta para sensores e atuadores, que permite a comunicação bidirecional e fornece dados detalhados sobre o status dos dispositivos, sendo crucial para a manutenção preditiva.

---
