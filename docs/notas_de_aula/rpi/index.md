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


## C1. [O que são Redes Industriais? Conceito, história e evolução](slides/aula01-definicao_de_redes_industriais.pdf)

1. Definição: Rede e indústria;
2. Revoluções Industriais;
3. Tipos de redes industriais;
4. Convergência tecnológica: TI + TA;
5. Arquitetura de referência para uma planta de Automação Industrial;
6. Necessidades emergentes;
7. Benefícios da convergência;
8. Objetivos da Rede Industrial;
9. Protocolos de comunicação:
	1. Níveis da rede industrial;
	2. Evolução das redes industriais;
	3. Tipos de transmissão;
	4. Finalidade dos protocolos no meio industrial;



## C2. [Classificação e arquiteturas de redes industriais](slides/aula02-classificacao_das_redes.pdf)

1. Topologia física;
2. Modelos de redes;
3. Método de troca de dados;
4. Tipo de conexão;
5. Modo de transmissão;
6. Sincronização de bits;
7. Modo de operação;
8. Tipo de comunicação;

## C3. [Critérios para dimensionamento](slides/aula03-criterios_para_dimensionamento.pdf)

1. Meio físico de comunicação;
2. Cobertura geográfica;
3. Método de acesso;
4. Desempenho: Velocidade x *Throughput*;
5. Confiabilidade: Determinístico x Probabilístico;
6. Protocolo de comunicação;

## C4. [Modelo OSI/ISO](slides/aula04-Modelo_OSI.pdf)

1. Características do Modelo
2. Camada 7 - Aplicação
3. Camada 6 - Apresentação
4. Camada 5 - Sessão
5. Camada 4 - Transporte
6. Camada 3 - Rede 
7. Camada 2 - Enlace
8. Camada 1 - Física

## C5. [Meio Físico - RS232/RS485/RS422](slides/aula05-MeioFisico-RS_232-485-422.pdf)

1. RS232
	1. Conectores e pinagem
	2. Características elétricas
	3. Distância e baud rate
	4. Controle de fluxo por hardware
	5. Transceiver - MAX232
2. RS485
	1. Aplicação
	2. Topologias
	3. Par diferencial e níveis de tensão
	4. Resistor de terminação
	5. Distância e velocidade de comunicação
	6. Multiponto
	7. Transceivers comerciais


## C6. [Protocolo de comunicação - MODBUS](slides/aula06-protocolo_de_comunicacao_MODBUS.pdf)

1. Introdução - Modicon, protocolo aberto
2. Conexão e cabo de transmissão
3. Modbus e modelo ISO/OSI
4. Cliente-Servidor - Unicast x Broadcast
5. Codificação da mensagem - RTU e Ascii
6. Modelo de organização da memória
7. Unidade de dados de protocolo (PDU)
8. Frame e temporização em modo RTU
9. Codificação da mensagem

## C7. [Sistema Supervisório - SCADA](slides/aula07-sistemas_SCADA.pdf)
1. Objetivos
2. Aplicações
3. Benefícios
4. Desafios
5. Exemplos de sistemas:
	1. Indusoft/Aveva Edge
	2. Elipse
	3. BluePlant
	4. ScadaBR

## C8. [Rede sem fio industrial](slides/aula08-redes_sem_fio_em_ambiente_industrial.pdf)
1. Introdução
2. Wi-Fi
3. Bluetooth
4. Redes de Sensores Sem Fio (RSSF)
5. Fatores determinantes em redes sem fio
6. Práticas recomendadas

## C9. [IIoT](slides/aula09-IIoT.pdf)
1. Indústria 4.0
2. Modelo hierárquico ISA95
3. Mudança de paradigma com dados
4. IoT x IIoT
5. Tecnologias de IIoT
	1. Inteligência artificial
	2. Segurança cibernética
	3. Computação em nuvem
	4. Computação de borda
	5. Mineração e Análise de Dados
6. Desafios da IIoT



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
