---
title: 2. Microcontroladores
icon: fontawesome/solid/microchip
author: José W. R. Pereira
tags: 
    - Microcontrolador
    - MCU
    - MCMP
    - AVR
---

#

![capa](img/mcu01-mcu_capa.png)

---

# [1. Microcontroladores](../../slides/uC02-Microcontroladores.pdf)

Os Microcontroladores são uma derivação dos Microprocessadores que surgiram para uso e 
aplicações específicas, principalmente em sistemas industriais e mais recentemente 
eletrodomésticos até os atuais dispositivos de Internet das coisas, ou IoT 
(*Internet of things*).

Basicamente, tanto os microprocessadores quanto os microcontroladores são circuitos lógicos digitais que processam dados, realizam cálculos e interagem com um conjunto de outros circuitos. Nos processadores, os demais circuitos estão em um corpo distinto, formando as placas mãe como nos computadores de uso geral. No caso dos microcontroladores, há uma série de circuitos periféricos montados no mesmo encapsulamento da unidade de processamento, ou seja, no mesmo corpo do circuito de controle também estão presentes memórias, circuitos contadores, conversores, de comunicação entre outros, a combinação é extremamente ampla. 


| Figura : Microcprocessador x Microcontrolador |
|:------------------:|
|![MPU x MCU](img/mcu02-mpu_x_mcu.png)|
| Fonte: Próprio autor |


Em função principalmente do tipo de aplicação aos quais cada um desses dispositivos é 
empregado, algumas de suas características acabam sendo bem diferentes. 
A Tabela mostra algumas diferenças de características entre os microprocessadores e os 
microcontroladores.

Tabela: Comparação entre MPU e MCU

|                               | Microprocessador (MPU)                                                                                   | Microcontrolador (MCU)                                                                                                                                              |
| ----------------------------- | -------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Memória                       | Requer memória externa e armazenamento de dados.                                                         | Módulos de memória no chip (ROM, RAM).                                                                                                                              |
| Periféricos                   | Precisa de peças adicionais. <br>Conecta-se ao barramento externo.                                       | Periféricos no chip (timers, portas de E/S, conversor de sinal).                                                                                                    |
| Capacidade computacional      | Capaz de realizar tarefas computacionais complexas.                                                      | Limitado à lógica específica da aplicação.                                                                                                                          |
| Velocidade do relógio (Clock) | Faixa de GHz.                                                                                            | Faixa de kHz a MHz.                                                                                                                                                 |
| Consumo de energia            | Alto consumo de energia. <br>Sem modo de economia de energia.                                            | Consome energia mínima. <br>Modos de economia de energia integrados.                                                                                                |
| Sistema operacional           | Requer sistemas operacionais.                                                                            | O sistema operacional é opcional para alguns microcontroladores.                                                                                                    |
| Conectividade                 | Lida com transferência de dados em alta velocidade. <br>Oferece suporte para USB 3.0 e Gigabit Ethernet. | Oferece suporte para comunicação de velocidade baixa a moderada. <br>Interface periférica serial (SPI) e I²C. <br>Receptor-transmissor assíncrono universal (UART). |
| Custo                         | Caro por causa dos componentes adicionais.                                                               | Mais barato porque um único circuito integrado oferece várias funcionalidades.                                                                                      |
| Caso de uso                   | Para computação genérica ou sistemas que exigem capacidade computacional robusta.                        | Para sistemas compactos, alimentados por bateria ou dispositivos de processamento lógico.                                                                           |

Fonte: [AWS - Qual é a diferença entre microprocessadores e microcontroladores?](https://aws.amazon.com/pt/compare/the-difference-between-microprocessors-microcontrollers/)


---

# 2. Contexto Histórico

## 2.1 Como surgiu a ideia do primeiro processador?

No ano de 1971, Federico Faggin da Intel, respondeu a um pedido de 12 microchips 
personalizados para uma calculadora do fabricante de eletrônicos japonês Busicom com 
um único circuito de uso geral, que correspondia à solicitação, chamado de Intel 4004 
foi o precursor de uma significativa evolução da computação. Operava com frequência de 
clock de 740 kHz e operava fluxos de 4 bits, *nibbles* e realizada até 92 mil instruções 
por segundo. 

|                                    Figura: Intel 4004: protótipo, esquemático, chip em produção e Calculadora Busicom 141-PF                                    |
| :-------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| ![intel4004](img/mcu02-intel4004.png)                                                               |
| Fonte: [Intel Marks 50th Anniversary of the Intel 4004](https://www.intel.com/content/www/us/en/newsroom/news/intel-marks-50th-anniversary-4004.html#gs.jyxddl) |


Poucos meses após o lançamento do Intel 4004, foi a vez do segundo processador, 
desenvolvido de forma independente e com especificações distintas ao primeiro, 
foi a vez do 
[Intel 8008](https://www.intel.com/content/www/us/en/history/virtual-vault/articles/the-8008.html), 
primeiro processador de 8 bits, com 50 porcento mais transistores e um clock oito vezes maior, 
com capacidade de manipulação de dados ou caracteres, sendo o antecessor capaz apenas de 
manipulações aritméticas.

Com relatos de clientes do 8008, sobre o projeto do chip estar restringindo a 
escala e a complexidade do software que eles queriam criar, foi desenvolvido o 
[Intel 8080](https://www.intel.com.br/content/www/br/pt/newsroom/news/50-years-ago-the-influential-intel-8080.html)
que tornou real o que os seus antecessores criaram, segundo Federico Notebookgin, 
designer-chefe da Intel para o 8080 os antecessores 4004 e 8008.

> O novo chip de 8 bits resultante foi mais eficiente, mais poderoso e mais flexível, capaz de 290.000 operações por segundo (10 vezes a do 8008). E com uma configuração de 40 pinos, tornou a conexão a outros componentes mais fácil do que o projeto de 18 pinos do 8008. O 8080 também integrou as funções dos chips de suporte que os 4004 e 8008 precisavam, tornando-o um verdadeiro microprocessador de chip único.
> 
> [Há 50 anos: celebrando o influente Intel 8080](https://www.intel.com.br/content/www/br/pt/newsroom/news/50-years-ago-the-influential-intel-8080.html)

## 2.2 Uma nova era

O Intel 8080 abriu as portas de um novo mundo a ser explorado por programadores do 
mundo inteiro de tecnologias a explorar, o que possibilitou o seu uso não só em 
computadores ou calculadoras, mas permitiu o seu uso no famoso Altair 8800, 
o primeiro computador portátil e de baixo custo, tornando mais acessível a computação 
comercial e científica. Ainda substituindo toda uma lógica discreta, 
pela primeira vez para processar um jogo, o Gun Fight, da Midway Games, 
foi o primeiro jogo de arcade disponível comercialmente a utilizar este processador. 

|                                Figura : Uso do 8080 em caixa eletrônico, computador Altair 8800 e Gun Fight, da Midway Games.                                 |
| :-----------------------------------------------------------------------------------------------------------------------------------------------------------: |
| ![intel8080](img/mcu02-intel8080.png)                                                              |
| Fonte: [Há 50 anos: celebrando o influente Intel 8080](https://www.intel.com.br/content/www/br/pt/newsroom/news/50-years-ago-the-influential-intel-8080.html) |

A evolução e o avanço tecnológico desde os primeiros passos com os processadores é 
notório e ultrapassa quaisquer limites até então pensados. 
A figura a seguir ilustra as principais características dos processadores depois de 50 anos, 
desde o icônico 8080. 

|                                                Figura : Comparação de 50 anos entre o 8080 e o Core Ultra 200S                                                |
| :-----------------------------------------------------------------------------------------------------------------------------------------------------------: |
| ![50 anos 8080](img/mcu02-50anos8080.png)                                                              |
| Fonte: [Há 50 anos: celebrando o influente Intel 8080](https://www.intel.com.br/content/www/br/pt/newsroom/news/50-years-ago-the-influential-intel-8080.html) |




## 2.3 O lendário 8051

Ainda no começo dos anos 80, a Intel desenvolveu um controlador com tecnologia NMOS, 
o famoso **8051**, que logo evoluiu para tecnologia CMOS, 
reduzindo drasticamente o consumo de energia, possibilitando dispositivos com fontes 
reduzidas de energia, como baterias portáteis. Possui memória para o seu programa, 
temporizador, barramento de 8 bits, 32 entradas e saídas digitais, 
porta de comunicação serial, interrupções, entre outros. 

|                                                                 Figura : Intel P8051                                                                  |
| :---------------------------------------------------------------------------------------------------------------------------------------------------: |
| ![intelP8051](img/mcu02-KL_Intel_P8051.jpg)                                                                |
| Por Konstantin Lanzet (with permission) - CPU collection Konstantin Lanzet, CC BY-SA 3.0, https://commons.wikimedia.org/w/index.php?curid=4774266<br> |

O [8051](https://pt.wikipedia.org/wiki/Intel_8051) como ficou popular, se mostrou muito adequado para aplicações industriais, e ganhou o título de mais usado no mundo com mais de dois mil fabricantes que o utilizam como base dos seus projetos, em milhares de aplicações embarcadas. 



A arquitetura do 8051 utiliza o trabalho proposto por [Burks, Goldstine e von Neumann - 1946](https://www.cs.princeton.edu/courses/archive/fall13/cos375/Burks.pdf), sendo este último o mais notório que acabou batizando o nome da arquitetura: **Von Neumann**, utilizando um conjunto de instruções denominadas, [CISC](https://pt.wikipedia.org/wiki/CISC). A ideia base é acessar as memórias de código e de trabalho por um mesmo barramento de dados. 
No computador com conjunto complexo de instruções é possível realizar praticamente todos os acessos e operações de forma direta, com uma única instrução, sendo sua complexidade associada ao circuito que permite a vasta possibilidade de instruções diretas. 

Em oposição ao modelo CISC, foi desenvolvido em Harvard uma arquitetura que utiliza uma arquitetura com dois barramentos de acesso distintos entre programa e dados, assim, praticamente todas as ações são executadas em pelo menos duas instruções, simplificando o circuito de acesso, reduzindo o número de possiblidades de instruções, [RISC](https://pt.wikipedia.org/wiki/RISC), mas ganhando em velocidade, principalmente quando utilizada a técnica de *pipeline*. Esta tecnologia se tornou muito predominante em diversas aplicações de controladores. 

Com o passar do tempo essas tecnologias forma se fundindo, características de uma foram incorporadas à outra e vice-versa. 

## 2.4 AVR

No início dos anos 90 surge um projeto de estudantes noruegueses ganhou muito espaço no mercado com seu controlador com arquitetura baseada em RISC, denominada AVR, que foi adquirida a licença pela Atmel, o maior fabricante de microcontroladores de 8 bits, na época, grande fornecedor de chips 8051, apesar de já ser um projeto aberto e fabricado por diversas outras empresas. 

A partir de 1996 a Atmel incorporou a linha proprietária ATMega com dispositivos AVR, competindo diretamente com os PICs da Microchip e outros fabricantes como Renesas, Texas Istruments, Motorolla, etc.

No ano de 2016, a líder do mercado de semicondutores de 8 bits foi adquirida pela sua principal concorrente, e desde então os PICs e AVRs fazem parte de uma mesma empresa fabricante. 


| Figura: Relação entre as marcas AVR, Atmel e Microchip  |
|:-------------------------------------------------------:|
| ![AVR_ATMEL_Microchip](img/mcu02-avr_atmel_microchip.png)|
| Fonte: Próprio autor |

## 2.5 Arduino

Em 2005 na Itália foi desenvolvida a plataforma de prototipagem Arduino, que ganhou a mente e os corações de estudantes, entusiastas e hobbistas no mundo todo, por sua facilidade de uso inclusive e principalmente para leigos, robustez e acesso à informações, simples, objetivas e claras. 

Dentre os diversos modelos de Arduino, o mais comum e popular é o Uno, que utiliza um controlador AVR ATMega328P, que alavancou suas vendas e lhe deu uma grande sobrevida. 

| Figura: Placas de desenvolvimento |
|:---------------------------------:|
| ![PlacasDesenvolvimento](img/mcu02-placasDesen.png)|
| Fonte: Próprio autor |


## 2.6 ARM 

Outra grande evolução foi a adoção da arquitetura ARM, que apesar de ser dos anos 80, tornou-se popular tanto em processadores quanto em microcontroladores nos anos 2000. 

A quantidade de microcontroladores hoje é imensa, cada fabricante possui diversas famílias com dezenas ou centenas de modelos, cada um com alguma característica de periférico que pode ser o mais adequado para cada aplicação. O mercado é gigante bem como suas possibilidades, principalmente com a utilização de dispositivos de 32 bits a um preço menor do que os de 8 bits e a implementação de sistemas de comunicação sem fio. 

Assim como há diversos microcontroladores, os fabricantes também investiram no modelo de desenvolvimento amplamente aceito pelo mercado com o Arduino, e disponibiliza placas de desenvolvimento para os desenvolvedores se familiarizarem com os seus dispositivos e poderem utilizar com mais segurança em projetos próprios. 

---

# 3. Tipos de Microprocessadores

Os microprocessadores variam em potência, desempenho, metodologias de arquitetura, tamanho, consumo de energia e muitas outras variáveis e são projetados para todos os tipos de aplicações. Microprocessadores de uso geral são comuns em computadores pessoais e dispositivos móveis, enquanto unidades especializadas de alto desempenho, como Processadores de Sinal Digital (DSPs), são projetadas para tarefas exigentes como processamento de áudio, fala, vídeo e imagem.  

A seguir estão alguns dos principais tipos de microprocessadores.

- **Microprocessadores de uso geral**: Esses microprocessadores versáteis são encontrados em uma ampla gama de aplicações e dispositivos comuns, como notebooks e servidores. 
- **Microcontroladores**: Embora seja mais correto dizer que os [microcontroladores](https://www.ibm.com/br-pt/think/topics/microcontroller) contêm microprocessadores, esses tipos de chips também apresentam todos os componentes adicionais necessários para um computador funcional, ou seja, memória interna. Microcontroladores funcionam como microcomputadores e são preferidos para controlar elementos específicos dentro de sistemas de computadores embarcados. Microcontroladores pequenos e de baixo consumo de energia não exigem sistemas operacionais complexos para funcionar e são comumente usados na indústria automotiva para otimizar Unidades de Controle do Motor (ECUs), Sistemas Avançados de Assistência ao Motorista (ADAS) e unidades de infoentretenimento, bem como em uma vasta gama de dispositivos eletrônicos de consumo e até mesmo em automação industrial.
- **Processadores de sinal digital (DSPs)**: Os DSPs são especializados em cálculos numéricos de alta velocidade e geralmente são usados para tarefas exigentes, como processamento de áudio, telecomunicações e processamento de imagens. Eles também podem ser encontrados em aplicações que requerem a interpretação de sinais analógicos para digitais, como sensores meteorológicos. Os DSPs são comumente usados em aplicações militares, como drones de vigilância e outras aeronaves autônomas.
- **Circuitos integrados específicos de aplicações (ASICs)**: Os microprocessadores ASIC são projetados para tarefas específicas e são personalizados para atender às demandas específicas de diversas aplicações. Alguns exemplos de microprocessadores ASIC incluem chips personalizados para consoles de jogos ou mineração de criptomoedas. DSPs, GPUs e outros tipos de microprocessadores especializados também são tecnicamente ASICs.  
- **Unidades de processamento gráfico (GPUs)**: Os microprocessadores de [GPU](https://www.ibm.com/br-pt/topics/gpu) são especialmente projetados para a exigente tarefa de renderizar vídeos e gráficos digitais que exigem desempenho de alta potência e processamento paralelo. Essencialmente importantes para jogos de última geração, os potentes microprocessadores de GPU também são comumente usados na mineração de criptomoedas e são conhecidos pelo alto consumo de energia. 
- **Processadores de rede**: Um tipo de microprocessador ASIC especificamente otimizado para o processamento de pacotes de dados de rede mais frequentemente utilizados em switches de telecomunicações, roteadores e dispositivos de segurança de rede. 
- **Coprocessadores**: Os coprocessadores, como as unidades de ponto flutuante (FPUs), são projetados para fornecer suporte auxiliar à CPU principal de um sistema para aumentar o desempenho durante certas tarefas exigentes, como a realização de cálculos científicos avançados ou fórmulas matemáticas complicadas.

---

Um **microcontrolador (MCU)** é essencialmente um "computador em um único chip", que integra em um único encapsulamento a unidade de processamento, memórias e diversos periféricos. Para entender sua estrutura e interações internas, podemos dividir o conceito em três pilares fundamentais:
# 4. Estrutura e interações

Para entender as estruturas e interações internas, podemos dividir o conceito de microcontrolador em três pilares fundamentais

# 4.1 Arquitetura e Organização de Barramentos

A forma como os componentes internos se comunicam é definida por sua arquitetura de barramentos:

*   **Von Neumann:** Utiliza um **único barramento** para tráfego de dados e instruções, o que simplifica o design, mas pode criar um gargalo de processamento.

*   **Harvard:** Possui **barramentos e memórias fisicamente separados** para dados e instruções, o que permite ao processador buscar uma instrução e acessar dados simultaneamente, aumentando o desempenho através do *pipeline*.

| Figura: Arquiteturas Von Neumann x Harvard |
|:------------------------------------------:|
| ![vonNeumann_x_harvard](img/mcu02-vonNeumann_x_Harvard.png)|
| Fonte: Próprio autor |


*   **ISA (Arquitetura de Conjunto de Instruções):** Define as operações que o processador pode executar, sendo as mais comuns a **RISC** (instruções simples e de tamanho fixo, focadas em velocidade) e a **CISC** (instruções complexas que realizam múltiplas operações de uma vez).

| Figura: Arquiteturas internas de microcontroladores |
|:---------------------------------------------------:|
| ![arquitetura](img/mcu02-barramentos.png) |
| Fonte: Datasheet [STM32F103xx](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.st.com/resource/en/datasheet/stm32f103c8.pdf&ved=2ahUKEwjNzMOW_LOSAxXNALkGHUPoNqcQFnoECAQQAQ&usg=AOvVaw0rd6I_7fuhTLdZOoycvGV5) [AT89C51ED2](https://www.microchip.com/en-us/product/at89c51ed2)|

---

## 4.2 Partes Fundamentais (Estrutura Interna)

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

## 4.3. Interações Internas: O Ciclo de Operação

As interações ocorrem de forma sincronizada por um sinal de **Clock**, que dita o ritmo das transferências de dados entre a CPU, a memória e os periféricos. O processamento segue quatro etapas principais:

1.  **Buscar (Fetch):** A CPU busca a instrução na memória de programa no endereço apontado pelo **Contador de Programa (PC)**.

2.  **Decodificar (Decode):** A instrução é carregada no **Registrador de Instrução (IR)** e traduzida pela Unidade de Controle em sinais elétricos de comando.

3.  **Executar (Execute):** A ALU realiza a operação matemática ou lógica solicitada.

4.  **Armazenar (Store):** O resultado é gravado de volta em um registrador ou na memória de dados.

Além desse ciclo, o microcontrolador interage com o mundo externo através de **interrupções**, eventos de hardware que suspendem temporariamente a execução do programa principal para atender a uma tarefa imediata e prioritária, garantindo a natureza reativa do sistema.


---


**Referências e complementos**

1. [Como a AWS pode ajudar com suas necessidades de desenvolvimento de microprocessadores e microcontroladores? - AWS](https://aws.amazon.com/pt/compare/the-difference-between-microprocessors-microcontrollers/)
2. [O que é um microprocessador? - IBM](https://www.ibm.com/br-pt/think/topics/microprocessor)
3. [Microcontroladores vs. microprocessadores: qual é a diferença? - IBM](https://www.ibm.com/br-pt/think/topics/microcontroller-vs-microprocessor)
4. [Microprocessadores e Microcontroladores - Prof. José Wilson Lima Nerys - UFG](http://inf.ufes.br/~zegonc/material/Introducao_a_Computacao/Microprocessadores%20-%20Parte%201.pdf)
5. [Intel's First Microprocessor](https://www.intel.com.br/content/www/br/pt/history/museum-story-of-intel-4004.html)
6. [A história dos processadores - TecMundo](https://www.tecmundo.com.br/historia/2157-a-historia-dos-processadores.htm)
7. [Evolução Dos Processadores Da Intel - miso](https://youtu.be/MS3weNIvswA?si=7pEy__NShgaY_9p-)
8. [The story of AVR - avrtvtube](https://youtu.be/HrydNwAxbcY?si=HqoJjr9_3EDnhDOB)
9. [The Evolution Of CPU Processing Power Part 1: The Mechanics Of A CPU - New Mind](https://youtu.be/sK-49uz3lGg?si=RFxLWCPxjpoKNXbq)
10. [How Amateurs created the world’s most popular Processor (History of ARM Part 1) - LowSpecGamer](https://youtu.be/nIwdhPOVOUk?si=-_QEV4eiWaIqgFip)
11. [ARM's Secret Weapon (History of ARM Part 2) - LowSpecGamer](https://youtu.be/vx1-6yRAGk0?si=PRtjnqGqqbeysnj0)
12. [The potted history of ARM - Retro Bytes](https://youtu.be/t59EtDxpYmM?si=e6WpiiISbu4CHehz)
13. [Explaining RISC-V: An x86 & ARM Alternative - ExplainingComputers](https://youtu.be/Ps0JFsyX2fU?si=mpfbKea0VbzFJ5Ok)
14. [SAP-1](https://www.ic.unicamp.br/~ducatte/mc542/2012S2/sap-1.pdf)



---

---
