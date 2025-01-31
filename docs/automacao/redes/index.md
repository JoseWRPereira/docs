---
title: Redes e Protocolos Industriais
icon: fontawesome/solid/network-wired
author: José W. R. Pereira
tags: 
    - RPI
    - Redes Industriais
    - Protocolos Industriais
    - IFSP
---


# Redes e Protocolos Industriais

## Slides: Aulas


| Aula | Título                                                                                                         | Conteúdo                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| ---- | -------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 01   | [O que são Redes Industriais? <br>Conceito, história e evolução](slides/aula01-definicao_de_redes_industriais.pdf) | - Definição: Rede e indústria;<br>- Revoluções Industriais;<br>- Tipos de redes industriais;<br>- Convergência tecnológica: TI + TA;<br>- Arquitetura de referência para uma planta de Automação Industrial;<br>- Necessidades emergentes;<br>- Benefícios da convergência;<br>- Objetivos da Rede Industrial;<br>- Protocolos de comunicação:<br>&emsp; - Níveis da rede industrial;<br>&emsp; - Evolução das redes industriais;<br>&emsp; - Tipos de transmissão;<br>&emsp; - Finalidade dos protocolos no meio industrial; |
| 02   | [Classificação e arquiteturas](slides/aula02-classificacao_das_redes.pdf)                 | - Topologia física;<br>- Modelos de redes;<br>- Método de troca de dados;<br>- Tipo de conexão;<br>- Modo de transmissão;<br>- Sincronização de bits;<br>- Modo de operação;<br>- Tipo de comunicação;                                                                                                                                                                                                                                                                                                                        |
| 03   | [Critérios para dimensionamento](slides/aula03-criterios_para_dimensionamento.pdf)                             | - Meio físico de comunicação;<br>- Cobertura geográfica;<br>- Método de acesso;<br>- Desempenho: Velocidade x *Throughput*;<br>- Confiabilidade: Determinístico x Probabilístico;<br>- Protocolo de comunicação;                                                                                                                                                                                                                                                                                                              |
| 04   | [Modelo OSI/ISO](slides/aula04-Modelo_OSI.pdf)                                                                 | - Características do Modelo<br>- Camada 7 - Aplicação<br>- Camada 6 - Apresentação<br>- Camada 5 - Sessão<br>- Camada 4 - Transporte<br>- Camada 3 - Rede <br>- Camada 2 - Enlace<br>- Camada 1 - Física                                                                                                                                                                                                                                                                                                                      |
| 05   | [Meio Físico <br> RS232/RS485/RS422](slides/aula05-MeioFisico-RS_232-485-422.pdf)                                 | - RS232<br>&emsp; - Conectores e pinagem<br>&emsp; - Características elétricas<br>&emsp; - Distância e baud rate<br>&emsp; - Controle de fluxo por hardware<br>&emsp; - Transceiver - MAX232<br>- RS485<br>&emsp; - Aplicação<br>&emsp; - Topologias<br>&emsp; - Par diferencial e níveis de tensão<br>&emsp; - Resistor de terminação<br>&emsp; - Distância e velocidade de comunicação<br>&emsp; - Multiponto<br>&emsp; - Transceivers comerciais                                                                           |
| 06   | [Protocolo de comunicação <br> MODBUS](slides/aula06-protocolo_de_comunicacao_MODBUS.pdf)                         | - Introdução - Modicon, protocolo aberto<br>- Conexão e cabo de transmissão<br>- Modbus e modelo ISO/OSI<br>- Cliente-Servidor - Unicast x Broadcast<br>- Codificação da mensagem - RTU e Ascii<br>- Modelo de organização da memória<br>- Unidade de dados de protocolo (PDU)<br>- Frame e temporização em modo RTU<br>- Codificação da mensagem                                                                                                                                                                             |
| 07   | [Sistema Supervisório <br> SCADA](slides/aula07-sistemas_SCADA.pdf)                                               | - Objetivos<br>- Aplicações<br>- Benefícios<br>- Desafios<br>- Exemplos de sistemas:<br>&emsp; - Indusoft/Aveva Edge<br>&emsp; - Elipse<br>&emsp; - BluePlant<br>&emsp; - ScadaBR                                                                                                                                                                                                                                                                                                                                             |
| 08   | [Rede sem fio industrial](slides/aula08-redes_sem_fio_em_ambiente_industrial.pdf)                              | - Introdução<br>- Wi-Fi<br>- Bluetooth<br>- Redes de Sensores Sem Fio (RSSF)<br>- Fatores determinantes em redes sem fio<br>- Práticas recomendadas                                                                                                                                                                                                                                                                                                                                                                           |
| 09   | [IIoT](slides/aula09-IIoT.pdf)                                                                                 | - Indústria 4.0<br>- Modelo hierárquico ISA95<br>- Mudança de paradigma com dados<br>- IoT x IIoT<br>- Tecnologias de IIoT<br>&emsp; - Inteligência artificial<br>&emsp; - Segurança cibernética<br>&emsp; - Computação em nuvem<br>&emsp; - Computação de borda<br>&emsp; - Mineração e Análise de Dados<br>- Desafios da IIoT                                                                                                                                                                                               |




## A1. Prática orientada em laboratório
1. [Sinal de comunicação](https://solace.com/wp-content/uploads/2021/02/baud-rate-4.png)
	1. Baud Rate, Tbit; 
	2. [Configurações de comunicação:](https://www.picotech.com/images/uploads/software/RS-232_diagram_1.jpg)
		1. Bit de início de comunicação (Start bits);
		2. Bits de Dados;
		3. Bit de Paridade;
		4. Bits de parada (Stop bits);
		5. Tchar;
	3. [Tabela](https://repositorio.ufu.br/bitstream/123456789/14443/4/SFOLima4DISSPRT.pdf) [Ascii](https://www.ime.usp.br/~pf/algoritmos/apend/ascii.html)
		1. Códigos em hexadecimal
		2. Códigos em binário
	4. [Lab. Sinais de Comunicação - ArduinoUno](slides/cofre.zip)
	
2. [Comunicação Serial via RS485](slides/lab4-comunicacao_serial_rs485.pdf)

3. [Sistema Supervisório - ScadaBR](slides/aula07lab-ScadaBR.pdf)

4. [Projeto Modbus+Supervisório](slides/aula08lab-supervisorio.pdf)


## A2. Ferramentas/Software

* [Termite: a simple RS232 terminal](https://www.compuphase.com/software_termite.htm)
* [Terminal](https://sites.google.com/site/terminalbpp/)

* T1: [Soldagem SMD](https://github.com/JoseWRPereira/docs/tree/main/docs/notas_de_aula/pci/soldagem)
