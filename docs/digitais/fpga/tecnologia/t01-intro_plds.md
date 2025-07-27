---
title: Introdução aos Dispositivos Lógicos Programáveis
icon: fontawesome/solid/microchip
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---

---

O universo dos dispositivos digitais podem ser resumidos na Figura 1, desde dispositivos simples, como portas lógicas básicas implementados em circuitos integrados, que possuem comportamento muito específico, e geralmente bem simples, em que são usados para compor um circuito mais complexo através de associações que dependem da aplicação.

Seguindo pelo Circuitos Integrados de Aplicação Específicas (*Application-Specific Integrated Circuit* - ASICs), em que o arranjo de circuito complexos são implementados em um único componente, gerelmente feito por encomenda.

Na sequência temos os microprocessadores (microprocessor) e microcontroladores (microcontroller), em que um circuito dedicado orquestra o acionamento e processamento de sinais baseados em uma sequencia de códigos gravados em memória. O comportamento que estes circuitos apresentam, dependem do código que eles executam, e possuem razoável flexibilidade, porém, os circuitos internos que responsáveis por essa execução é estático.

Já os disposivos lógicos programáveis (*Programmable Logic Devices - PLDs*) possuem a capacidade de serem programados em sua totalidade de comportamento, possibilitando a reconfiguração completa do circuito e por consequencia de seu comportamento. Tornando eles assim, os mais genéricos, pois é possível sintetizar em um PLD, inclusive, o circuito de um microcontrolador ou processador, a depender do seu grau de integração, ou seja, da quantidade de células que ele dispõe para ser programado.


| Figura 1: Tecnologias digitais                |
|:---------------------------------------------:|
| ![digitalCircuit](img/t01-digitalCircuit.png) |
| Fonte: autor                                  |


Os circuitos integrados, a depender da quantidade de dispositivos lógicos implementados, como transistores, são classificados pelo grau de integração, como ilustrado na tabela que segue:

| Grau de Integração | Característica |
|:------------------:|:--------------:|
| SSI (*Small Scale Integration*)        | Dezenas de dispositivos |
| MSI (*Medium Scale Integration*)       | Centenas de dispositivos |
| LSI (*Large Scale Integration*)        | Dezenas de milhares de dispositivos |
| VLSI (*Very Large Scale Integration*)  | Milhões de dispositivos |
| ULSI (*Ultra Large Scale Integration*) | Utiliza Nanotecnologia |

Portanto, os primeiros circuitos integrados possuiam grau de integração pequeno (SSI), já os processadores modernos, são classificados como ULSI, bem como os PLDs.


**Dispositivos Lógicos Programáveis (PLDs)**

Os dispositivos lógicos programáveis (PLDs) surgem da necessidade de criar circuitos integrados flexíveis, que possuem a capacidade de implementar funções lógicas sem a necessidade de mudar o hardware, neste caso, numa escala de circuito integrado. Assim, circuitos de lógica combinacional puderam ser programados a partir da década de 1970.

O PLD é portanto, um circuito integrado configurado para atender à diversas especificações. Para isso, possui um grande número de portas lógicas e unidades de memória interconectadas em um único circuito integrado.


A maioria das conexões é feita através de elos, do tipo fusíveis, que podem ser "queimados" ou não, a depender da função lógica que está sendo implementada e da forma de programação do PLD.

| Figura 2: Diagrama de uma célula de um PLD |
|:------------------------------------------:|
| ![spld](img/t01-spld.png)                  |



O processo de "queima" pode ser feito pelo fabricante, de acordo com as especificações do cliente, ou pelo próprio usuário, por meio de equipamentos programadores.

Os primeiros PLDs foram desenvolvidos para construir apenas circuitos combinacionais, chamados de PAL (programmable array logic) e PLA (programmable logic array).

Logo surgiu a necessidade de construir circuitos sequenciais e então foi criada a estrutura GAL (generic array logic), que continha flip-flop, portas logicas e multiplexadores.

Essas estruturas até aqui foram denominadas de SPLD (simple PLDs), que utilizam tecnologia CMOS e disponibilizam elementos de memória do tipo EPROM, EEPROM e FLASH.

Com a evolução foram criados os CPLDs (**Complex PLDs**) e os FPGAs (**Field Programmable Gate Array**).



**Simbologia dos PLDs**

Foi adotada uma simbologia simplificada para representar os circuitos internos dos PLDs, conforme ilustrado na Figura 3.

| Figura 3: Diagrama de uma célula de um PLD |
|:------------------------------------------:|
| ![simbologia](img/t01-simbologia_pld.png)      |


Exemplo: Simbologia utilizada para uma porta AND de 4 entradas.

- Observe que, nas saídas dos buffers, estão representadas uma saída inversora e uma não inversora;
- Uma única linha aparece como entrada da porta AND, representando as 4 entradas existentes;
- As conexões das variáveis de entrada à porta AND são indicadas por um ponto ou por um X.
- O X representa um fusível intacto, e o ponto representa uma ligação, ou seja, ambas representações indicam que existe uma ligação física ou uma conexão.
- A ausência do X ou do ponto indica ausência de conexão.




**Arquitetura dos PLD**

Dentre os SPLD (simple PLDs), têm-se:

- PLA (arranjo lógico programável - programmable logic array);
    - Consiste em um arranjo de portas AND programável e um arranjo de portas OR também programável.
- PAL (lógica de arranjo programável - programmable array logic);
    - Consiste em um arranjo de portas AND programável e um arranjo de portas OR fixo.
- GAL (lógica de arranjo genérico - generic array logic).
    - Assim como a PAL, tem um arranjo AND programável e um arranjo OR fixo.
    - Adicionalmente, a GAL apresenta uma macrocélula de saída (OMLC) programável, com capacidade de armazenamento de dados de saída.



| Figura 4: Exemplo de diagrama              |
|:------------------------------------------:|
| ![simbologia](img/t01-spld_queima.png)     |


Uma vez programado, o PLD programável através da queima de fusíveis não pode ser recomposto. Essa desvantagem foi eliminada pela maioria dos fabricantes de PLD ao desenvolverem dispositivos que podem ser apagados e reprogramados quantas vezes forem necessárias. Esses dispositivos são também chamados de dispositivos lógicos programáveis apagáveis (EPLD - Erasable programmable logic device), sendo eles programados e apagados de maneira semelhante às EEPROM





---


 **Dispositivos Lógicos Programáveis Complexos (CPLDs)**

Os Dispositivos Lógicos Programáveis Complexos (CPLDs) foram introduzidos no mercado internacional pela empresa Altera Corp. em 1983, inicialmente como Dispositivos Lógicos Programáveis Apagáveis (EPLDs) e, posteriormente, como CPLDs.

Nessa arquitetura foram utilizados esquemas de roteamento sofisticado, tecnologia de silício mais avançada, entre outras características.

Originalmente, os CPLDs podiam ser obtidos com a construção e associação de inúmeros SPLDs no mesmo chip.


**Arquitetura de um CPLD**

A arquitetura de um CPLD é baseada em certo número de blocos lógicos, conforme ilustrado na Figura 4, cada um deles contendo uma macrocélula e um arranjo PLA ou PAL, alguns blocos de E/S e todos estes blocos interligados por uma rede de interconexão global programável.

| Figura 5: Estrutura padrão de um CPLD                       |
|:-----------------------------------------------------------:|
| ![estrutura_padrao_cpld](img/t01-estrutura_padrao_cpld.png) |

Normalmente, incorporam blocos combinacionais e elementos de memória do tipo flip-flop ou registros.

Os elementos programáveis são células do tipo EEPROM.

Esta arquitetura de dispositivo permite tornar mais aproveitável a área de integração (área em silício) permitindo um desempenho melhor e redução de custo. Um único CPLD pode substituir centenas de componentes 74XX (portas lógicas).

As interconexões programáveis formam um espécie de barramento que roteia (interliga) sinais das entradas ou saídas para as entradas de um bloco lógico, ou das saídas de um bloco lógico para as entradas do mesmo ou outro bloco.

Cada bloco lógico é equivalente à um SPLD, contendo suas macro células com suas interconexões.

Diferente das interconexões configuráveis da SPLD, as interconexões entre os blocos lógicos da CPLD podem não ser totalmente conectáveis, ou seja, algumas conexões entre um bloco e outro, teoricamente pode ser possível, mas na prática não podem ser executadas.

Com isso, torna-se difícil utilizar 100% das macrocélulas.

**Encapsulamentos**

Um Quad Flat Package (QFP ou encapsulamento quadrado) é um encapsulamento de circuito integrado com terminais que se estendem de cada um dos quatro lados.

Acondicionamentos especiais incluem LQFP (Low profile QFP) e TQFP (Thin QFP).

Um *plastic leaded chip carrier* (PLCC) é um encapsulamento plástico de quatro lados, com um terminal em "J" e espaçamentos de pino de 0,05" (1,27 mm).

| Figura 6: Encapsulamento |
|:-----------------------------------------------------------:|
| ![encapsulamento_cpld](img/t01-cpld_encapsulamento.png) |


Como os principais [fabricantes de CPLD](https://br.mouser.com/c/semiconductors/programmable-logic-ics/cpld-complex-programmable-logic-devices/?q=CPLD) podemos citar a Intel, que comprou a Altera em 2015, Xilinx, Microchip e Lattice.

---


 **Matriz de Portas Programáveis (*Field Programmable Gate Arrays* - FPGAs)**

Ainda na década de 1980, lançadas pelas empresa Xilinx, surgiram as FPGAs (Field Programmable Gate Arrays) que diferem dos CPLDs em arquitetura, tecnologia, características embutidas, tamanho, desempenho e custo.

Elas são, de forma geral, uma matriz de blocos, ao invés de uma pilha como nos CPLDs, que possuem um número de blocos maior, com blocos menores porém mais sofisticados.


FPGAs são circuitos programáveis que não possuem planos AND e OR, mas possuem um grande número (da ordem de milhares) de unidades idênticas (blocos lógicos) configuráveis.

As unidades lógicas podem ser vistas como componentes padrões que podem ser configurados independentemente e interconectados a partir de uma matriz de  trilhas condutoras e chaves programáveis

| Figura 7: Diagrama de blocos lógicos de FPGA  |
|:---------------------------------------------:|
| ![blocosLogicosFPGA](img/t01-fpga_logicBlock.png) |


**Arquitetura de uma FPGA**

Arquitetura baseada em blocos lógicos configuráveis, chamados de CLB (Configuration Logical Blocks).

- Os CLBs são formados por portas lógicas e flip-flops que implementam funções lógicas.
- Blocos de entrada e saída (IOB – In/Out Blocks), os quais são responsáveis pela interface das saídas provenientes das combinações de CLBs.

| Figura 8: Arquitetura de um FPGA                    |
|:---------------------------------------------------:|
| ![blocosLogicosFPGA](img/t01-fpga_architecture.png) |


- Os bits de configuração são selecionados de acordo com a função lógica desejada (combinacional ou sequencial).
- A configuração é uma tabela verdade (LUT - look up table) da funcionalidade. As LUTs podem ser programadas para qualquer tipo de porta necessária ao projeto. Há um número finito de LUTs em uma FPGA.


| Figura 9:                     |
|:---------------------------------------------------:|
| ![lutFPGA](img/t01-fpga_lut_example.png) |


**Granularidade**

- É uma característica dos FPGAs relacionada com o grão.
- O grão é a menor unidade configurável que compõe um FPGA.
- A fim de classificar os FPGAs quanto ao bloco lógico, foram criadas algumas categorias:

    - Grão Grande: Os FPGAs dessa categoria podem possuir como grão unidades lógicas aritméticas, pequenos microprocessadores e memórias.

    - Grão Médio: Os FPGAs de grão médio frequentemente contêm dois ou mais LUTs e dois ou mais flip-flops. A maioria das arquiteturas de FPGAs implementam a lógica em LUTs de quatro entradas.

    - Grão Pequeno: Os FPGAs de grão pequeno contêm um grande número de blocos lógicos simples. Os blocos lógicos normalmente contêm uma função lógica de duas entradas ou multiplexadores 4x1 e um flip-flop.

> Atenção!

> A configuração da LUT e da interconexão é volátil, isto é, se perde quando a alimentação é removida.

> São voláteis pois as células de armazenamento são implementadas com memórias SRAMs (memórias RAM estáticas).


- Existe uma memória não-volátil associada à FPGA de onde a sua configuração é carregada quando o sistema é ligado.
- São necessárias PROMS ao lado de FPGAs (conteúdo atualizado ao serem alimentadas).
- Geralmente utiliza-se uma pequena memória FLASH ou EEPROM, cuja função é carregar automaticamente as células de armazenamento, toda vez que o FPGA for energizado.
- Já que a programação é feita pelo usuário depois da fabricação, ela é chamada de programável no campo – field programmable.



**Técnicas de Configuração da Interconexão**

- As chaves programáveis de roteamento apresentam algumas propriedades, tais como tamanho, resistência, capacitância e tecnologia de fabricação, que afetam principalmente a velocidade e o tempo de propagação dos sinais e definem características como volatilidade e capacidade de reprogramação.
- Na escolha de um dispositivo reconfigurável, esses fatores devem ser avaliados.
- Basicamente existem três tipos de tecnologia de programação das chaves de roteamento:

- SRAM;
- Antifuse;
- Gate Flutuante

**SRAM**

Nessa tecnologia, a chave de roteamento ou comutador é um transistor de passagem ou um multiplexador controlado por uma memória estática de acesso randômico SRAM.

A figura ilustra essa tecnologia de programação, na qual uma célula SRAM é utilizada para controlar a porta (gate) do transistor de passagem.

| Figura 10: SRAM                   |
|:---------------------------------:|
| ![lutFPGA](img/t01-fpga_sram.png) |

Devido a volatilidade dessas memórias, os FPGAs que se utilizam dessa tecnologia precisam de uma memória externa tipo FLASH ou EEPROM.

Essa tecnologia ocupa muito espaço no circuito integrado, porém é rapidamente reprogramável.


**Antifuse**

Essa tecnologia baseia-se num dispositivo de dois terminais, que no estado não programado apresenta uma alta impedância (circuito aberto).

Aplicando-se a uma tensão, por exemplo, entre 11 e 20Vdc, o dispositivo forma um caminho de baixa impedância entre seus terminais.

| Figura 11: Antifuse                    |
|:--------------------------------------:|
| ![antifuse](img/t01-fpga_antifuse.png) |

**Gate Flutuante**

A tecnologia Gate flutuante baseia-se em transistores MOS (Metal Oxide Semicondutor), especialmente construídos com dois Gates flutuantes semelhantes ao usados nas memórias EPROM (Erasable Programmable Read Only Memory) e EEPROM (Electrical EPROM).

A maior vantagem dessa tecnologia é sua capacidade de programação e a retenção dos dados.

Além disso, da mesma forma que uma memória EEPROM, os dados podem ser programados com o circuito integrado instalado na placa, característica denominada ISP (In System Programmability).


| Figura 12: Gate Flutuante                        |
|:------------------------------------------------:|
| ![gateFlutuante](img/t01-fpga_gateflutuante.png) |


**Encapsulamentos**

- ***Ball Grid Array (BGA)***: a conexão entre o circuito integrado e a placa é feita por pequenos pontos de solda na sua parte inferior, que estão em contato direto com o chip de silício, dispensando os pinos externos como também outros tipos de pinagens não fixos.
- É um tipo de soldagem onde os terminais de contato são do tipo esfera.


- ***Pin Grid Array (PGA)***: o CI é montado numa placa cerâmica na qual uma face é coberta, ou parcialmente coberta, numa matriz quadrada de pinos de metal.


- ***Quad Flat Package (QFP)***: é conhecido por sua alta densidade de pinos e sua capacidade de fornecer uma conexão confiável entre o chip e a placa de circuito impresso.


| Figura 13: Encapsulamento de FPGA                       |
|:-------------------------------------------------------:|
| ![fpga_encapsulamento](img/t01-fpga_encapsulamento.png) |


Entre os principais [fabricantes de FPGA](https://br.mouser.com/c/semiconductors/integrated-circuits-ics/embedded-processors-controllers/fpga-field-programmable-gate-array/?pg=2), pode-se destacar novamente a Xilinx, Lattice, Microchip e Intel (Altera).

---

**FPGA x CPLD**

Ambos são dispositivos lógico programáveis e ambos, muitas vezes, são produzidos pelas mesmas empresas. Porém, existem muitas diferenças entre estas tecnologias:

- FPGAs contém muitos pequenos blocos lógicos com flip-flops (até da ordem de 1.000.000). CPLDs são compostos por um pequeno número (algumas centenas) de grandes blocos lógicos.
- FPGAs, tipicamente, são baseados em RAM. Isto significa que eles precisam ser reconfigurados (ou reprogramados) após cada corte de energia (existem FPGAs com programação persistente baseados em Flash ou EEPROM). CPLDs são, tipicamente, baseados em EEPROM. Eles já estão ativos ao serem ligados (desde que tenham sido programados pelo menos uma vez).
- CPLDs têm um tempo de resposta melhor, por ser composto de alguns poucos grande blocos lógicos. Em contrapartida esta característica lhe dá menos flexibilidade.
- FPGAs têm recursos de roteamento especiais para implementar de maneira eficiente funções aritméticas e RAM. CPLDs não têm.
- FPGAs podem ser usados em projetos grandes e complexos, enquanto CPLDs estão restritos a projetos bem menores.









---
# Referências

1. [Integrated Circuits - Learn Sparkfun ](https://learn.sparkfun.com/tutorials/integrated-circuits/all)
