---
title: Plano de Aula
icon: fontawesome/solid/list
author:
 - José W. R. Pereira
tags:
 - Microcontroladores e Microprocessadores
 - MCMP
---

#

# Plano de aulas

- [Calendário Escolar](https://slt.ifsp.edu.br/index.php/calendario-escolar)


| Semana | Data  | Conteúdo Planejado | Metodologia de Ensino e Recursos | Material de Apoio |
| :----: | :---: | :----------------- | :------------------------------- | :---------------: |
|   1    | 24/07 | Introdução à Plataforma e "Hello World" Físico<br>- Teoria: [A plataforma Arduino Uno; Anatomia do ATmega328P (pinagem e alimentação);](../../digitais/slides/MCMP01-intro_arq_plataforma.pdf)<br>- Prática: Instalação da IDE e montagem do primeiro circuito (Piscar LED) em protoboard        | - Exposição Dialogada<br>- Prática orientada |     |
|   2    | 31/07 | Saídas Digitais e Sequenciais Industriais<br>- T: Registradores de direção (`DDRx`) e dados (`PORTx`); conceitos de corrente máxima por pino.<br>- P: Montagem de um sinalizador sequencial com 8 LEDs (simulando status de processo)   | - Exposição Dialogada<br>- Prática orientada |     |
|   3    | 07/08 | Entradas Digitais e o Problema do Bounce<br>- T: Leitura de botões (`PINx`); resistores de _pull-up_ internos; ruído mecânico (_bounce_);<br>- P: Acionamento de uma carga (LED) por botão com tratamento de _debounce_ via software.   | - Exposição Dialogada<br>- Prática orientada |     |
|   4    | 14/08 | Lógica de Controle: Semáforo e Intertravamento<br>- T: Estruturas condicionais (`if/else`) e de repetição (`for/while`) aplicadas a I/O;<br>- P: Montagem de um semáforo industrial com botão de pedestre e aviso sonoro (buzzer).      | - Exposição Dialogada<br>- Prática orientada |     |
|   5    | 21/08 | Display de 7 Segmentos e Decodificação<br>- T: Funcionamento de displays (Anodo/Catodo comum); criação de tabelas de busca em memória;<br>- P: Contador de lotes (0-9) em display de 7 segmentos acionado por sensor tátil.             | - Exposição Dialogada<br>- Prática orientada |     |
|   6    | 28/08 | LCD 16x2 e Comunicação de 4 Bits<br>- T: O controlador HD44780; otimização de pinos usando interface de 4 bits.<br>- P: Montagem de uma IHM básica para exibir mensagens de texto fixas e variáveis.                                    | - Exposição Dialogada<br>- Prática orientada |     |
|   7    | 04/09 | Teclado Matricial e Varredura<br>- T: Técnica de varredura de colunas e leitura de linhas para economia de pinos;<br>- P: Entrada de senhas numéricas para liberação de um acesso (simulado por LED verde).                             | - Exposição Dialogada<br>- Prática orientada |     |
|   8    | 11/09 | Interrupções Externas para Eventos Críticos<br>- T: O conceito de interrupção vs. consulta (_polling_); pinos `INT0` e `INT1`;<br>- P: Implementação de um botão de emergência que interrompe qualquer ciclo em execução imediatamente. | - Exposição Dialogada<br>- Prática orientada |     |
|   9    | 18/09 | Temporizadores (Timers) e Base de Tempo<br>- T: O Timer 0 e Timer 1; _prescalers_ e estouro de contagem (_overflow_);<br>- P: Criação de um cronômetro de precisão exibido no LCD sem usar a função `delay()`.                          | - Exposição Dialogada<br>- Prática orientada |     |
|   10   | 25/09 | Modulação por Largura de Pulso (PWM)<br>- T: Conceito de ciclo ativo (_duty cycle_); saídas PWM no Arduino;<br>- P: Controle de intensidade de iluminação (_dimmer_) e variação de velocidade de um motor DC via transistor;            | - Exposição Dialogada<br>- Prática orientada |     |
|   11   | 02/10 | Servomotores e Posicionamento<br>- T: Protocolo de controle de servos (pulso de 0,5ms a 2,5ms em 50Hz);<br>- P: Controle de posição de um braço robótico simples ou válvula usando potenciômetro.                                       | - Exposição Dialogada<br>- Prática orientada |     |
|   12   | 09/10 | Motores de Passo e Drivers de Corrente<br>- T: Sequenciamento de fases; uso do driver ULN2803 ou L298;<br>- P: Movimentação precisa de um motor de passo (avanço e recuo por botões).                                                   | - Exposição Dialogada<br>- Prática orientada |     |
|   13   | 23/10 | Conversão Analógico-Digital (ADC)<br>- T: Resolução de 10 bits; tensão de referência e cálculo de escala;<br>- P: Leitura de sensores resistivos (LDR para luz ou Potenciômetro para setpoint).                                         | - Exposição Dialogada<br>- Prática orientada |     |
|   14   | 24/10 |                                                                                                                                                                                                                                         | IFCiência                                    |     |
|   15   | 30/10 | Sensores de Temperatura Industriais (LM35)<br>- T: Integração do LM35; linearização e exibição de dados reais;<br>- P: Termostato digital: monitorar temperatura e acionar um ventilador/aquecedor baseado em um limite.                | - Exposição Dialogada<br>- Prática orientada |     |
|   16   | 06/11 | Comunicação Serial USART (PC-Arduino)<br>- T: Protocolo RS232 via USB; taxas de transmissão (_baud rate_);<br>- P: Envio de telemetria de sensores para o Monitor Serial do PC e recepção de comandos para atuar no hardware.           | - Exposição Dialogada<br>- Prática orientada |     |
|   17   | 13/11 | Projeto Integrador <br>- Atividade: Montagem final de um sistema microcontrolado completo (ex: Controle de Nível de Reservatório ou Estufa Automatizada);                                                                               | - Exposição Dialogada<br>- Prática orientada |     |
|   18   | 27/11 | Projeto Integrador <br>- Atividade: Montagem final de um sistema microcontrolado completo (ex: Controle de Nível de Reservatório ou Estufa Automatizada);                                                                               | - Exposição Dialogada<br>- Prática orientada |     |
|   19   | 04/12 | Manutenção<br>- Discussão sobre técnicas de soldagem, PCIs e manutenção.                                                                                                                                                                | - Exposição Dialogada                        |     |
|   20   | 11/12 | Manutenção<br>- Discussão sobre técnicas de soldagem, PCIs e manutenção.                                                                                                                                                                | - Exposição Dialogada                        |     |

---

# Planejamento

**Módulo I: Fundamentos e Manipulação de I/O**

- Introdução à Plataforma e "Hello World" Físico
- Saídas Digitais e Sequenciais Industriais
- Entradas Digitais e o Problema do *Bounce*
- Lógica de Controle: Semáforo e Intertravamento

**Módulo II: Interfaces Homem-Máquina (IHM)**

- Display de 7 Segmentos e Decodificação
- LCD 16x2 e Comunicação de 4 Bits
- Teclado Matricial e Varredura
- Interrupções Externas para Eventos Críticos

**Módulo III: Controle de Potência e Atuadores**

- Temporizadores (Timers) e Base de Tempo
- Modulação por Largura de Pulso (PWM)
- Servomotores e Posicionamento
- Motores de Passo e Drivers de Corrente

**Módulo IV: Sinais Analógicos**

- Conversão Analógico-Digital (ADC)
- Sensores de Temperatura Industriais (LM35)
- Comunicação Serial USART (PC-Arduino)

**Módulo V: Integração Final** 

-  Projeto Integrador e Manutenção

---