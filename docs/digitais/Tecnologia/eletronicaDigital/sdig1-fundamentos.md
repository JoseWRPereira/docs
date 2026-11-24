---
title: 0000 - Fundamentos
icon: fontawesome/solid/square-binary
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
---


#

# [Sistemas Digitais](../../slides/SDIG01-Apresentacao.pdf)



## Fundamentos, representação da informação e características elétricas

### Objetivos 

-   definir sistema digital e reconhecer suas principais aplicações;
-   distinguir grandezas e sinais analógicos e digitais;
-   explicar como informações são representadas por bits;
-   relacionar estados lógicos a faixas de tensão elétrica;
-   interpretar os parâmetros elétricos básicos de entradas e saídas digitais;
-   calcular margens de ruído e explicar sua importância para a confiabilidade dos circuitos;
-   reconhecer a organização hierárquica de um sistema digital, desde os dispositivos semicondutores até os sistemas computacionais.

------------------------------------------------------------------------

## 1. Sistemas digitais

Um **sistema digital** é um sistema destinado à representação, ao
processamento, ao armazenamento ou à transmissão de informações por meio
de valores discretos. Sua implementação pode envolver circuitos
eletrônicos, dispositivos semicondutores, circuitos integrados e
unidades de processamento, que operam segundo regras definidas pela
lógica digital.

Ao contrário dos sistemas analógicos, que representam informações por
meio de grandezas que podem variar continuamente, os sistemas digitais
utilizam um conjunto discreto de símbolos ou estados. Na maioria dos
sistemas eletrônicos atuais, esses estados são representados pelo
**sistema de numeração binário**, que utiliza apenas os algarismos 0 e
1.

Cada algarismo binário é denominado **bit** (*binary digit*).
Fisicamente, em circuitos eletrônicos, os bits são representados por
faixas de tensão elétrica reconhecidas como estados lógicos. Portanto,
um bit não corresponde necessariamente a uma tensão exata, mas a uma
faixa de valores elétricos interpretada pelo circuito como 0 ou 1.

Os sistemas digitais estão presentes em computadores, telefones
celulares, sistemas embarcados, equipamentos de automação industrial,
instrumentos de medição, sistemas de comunicação e dispositivos de
controle.

### 1.1 Elementos fundamentais

A construção de sistemas digitais envolve diferentes elementos e níveis
de organização:

-   **Transistores:** dispositivos semicondutores utilizados, entre
    outras funções, como elementos de chaveamento e amplificação.
-   **Portas lógicas:** circuitos que realizam operações booleanas, como
    AND, OR e NOT.
-   **Circuitos combinacionais:** circuitos cujas saídas dependem dos
    valores atuais de suas entradas.
-   **Circuitos sequenciais:** circuitos capazes de armazenar estado, de
    modo que seu comportamento depende das entradas atuais e do estado
    anterior.
-   **Registradores e unidades funcionais:** blocos que armazenam dados
    e realizam operações específicas.
-   **Processadores e sistemas computacionais:** estruturas complexas
    que integram unidades de processamento, memória e interfaces de
    entrada e saída.

A lógica sequencial pode ser implementada por elementos de memória, como
*latches* e *flip-flops*. Muitos circuitos sequenciais são síncronos,
isto é, utilizam um sinal de *clock* para coordenar as mudanças de
estado. Também existem circuitos sequenciais assíncronos, cujas
transições não dependem de um clock global.

### 1.2 Níveis de abstração

A análise e o projeto de sistemas digitais podem ser realizados em
diferentes níveis de abstração. Em um nível físico, são considerados os
transistores, as interconexões e as características elétricas dos
componentes. Em níveis mais elevados, o projetista trabalha com portas
lógicas, blocos funcionais, registradores, unidades de processamento e
arquiteturas computacionais.

Essa organização hierárquica permite desenvolver sistemas complexos sem
precisar analisar simultaneamente todos os detalhes físicos de seus
componentes. Entretanto, o funcionamento lógico precisa respeitar as
limitações elétricas e temporais do hardware que o implementa.

Como a maioria das grandezas físicas do mundo real é analógica, sistemas
digitais frequentemente utilizam sensores, circuitos de condicionamento
e conversores analógico-digitais (A/D) para adquirir informações. Quando
precisam produzir sinais analógicos, podem utilizar conversores
digital-analógicos (D/A).

------------------------------------------------------------------------

## 2. Grandezas analógicas e digitais

Na eletrônica e na teoria dos sistemas, é importante distinguir as
grandezas físicas dos sinais utilizados para representá-las e
processá-las.

### 2.1 Grandezas e sinais analógicos

Uma grandeza analógica pode assumir valores em um intervalo contínuo.
Temperatura, pressão, posição, intensidade luminosa e pressão acústica
são exemplos de grandezas físicas que, em muitas situações, variam
continuamente.

Um **sinal analógico** é uma representação de informação por meio de uma
grandeza que pode variar continuamente em amplitude. Em sua
representação ideal, também pode variar continuamente no tempo.

Por exemplo, a tensão produzida por um sensor de temperatura pode variar
de maneira proporcional à temperatura medida, dentro da faixa de
operação do sensor.

### 2.2 Sinais digitais

Um **sinal digital** representa informação por meio de valores
discretos. Em circuitos binários, esses valores são associados a dois
estados lógicos: 0 e 1.

É importante distinguir duas propriedades:

-   **Discretização no tempo:** o sinal é considerado ou medido em
    instantes determinados. Essa operação está associada à amostragem.
-   **Discretização na amplitude:** os valores possíveis do sinal são
    limitados a um conjunto discreto de níveis. Essa operação está
    associada à quantização.

Um sinal amostrado pode ser discreto no tempo e ainda apresentar
amplitudes contínuas. Para obter uma representação digital quantizada, é
necessário também associar as amostras a níveis discretos de amplitude e
codificar esses níveis.

### 2.3 Digitalização de sinais analógicos

A conversão de uma informação analógica para uma representação digital
normalmente envolve as seguintes etapas:

1.  **Transdução:** o transdutor converte uma grandeza física, como
    temperatura ou pressão, em um sinal, frequentemente elétrico.
2.  **Condicionamento de sinal:** circuitos adequam o sinal às
    características da etapa de conversão. Podem realizar amplificação,
    filtragem, proteção e deslocamento de nível.
3.  **Amostragem:** o sinal é medido em instantes determinados.
4.  **Quantização:** cada amostra é associada a um dos níveis discretos
    disponíveis.
5.  **Codificação:** o nível quantizado é representado por uma sequência
    de bits.

O conversor A/D realiza as operações de amostragem, quantização e
codificação, de acordo com sua arquitetura. O condicionamento de sinal é
normalmente realizado por circuitos externos ou integrados ao sistema de
aquisição.

Na conversão D/A, uma sequência de códigos digitais é transformada em um
sinal analógico, que pode ser posteriormente filtrado ou condicionado
conforme a aplicação.

### 2.4 Resolução e quantidade de níveis

Em um conversor ideal de (n) bits, a quantidade de códigos digitais
disponíveis é:

\[ N = 2^n \]

Assim, um conversor de 8 bits pode representar:

\[ N = 2^8 = 256 \text{ códigos} \]

Um conversor de 12 bits pode representar:

\[ N = 2^{12} = 4096 \text{ códigos} \]

Considerando um conversor unipolar ideal com faixa de entrada de 0 V a 5
V, a largura de um intervalo de quantização ($q$), usando a convenção  $V_{\mathrm{FS}}/2^n$, é:

$$ q = \frac{V_{Full-Scale}}{2^n} = \frac{5}{256} \approx 0,019531 V $$

ou aproximadamente 19,53 mV por intervalo, para 8 bits.

O número de bits determina a quantidade de códigos disponíveis e está
diretamente relacionado à **resolução nominal**. Entretanto, resolução
não é sinônimo de precisão. A precisão real também depende de fatores
como erro de offset, erro de ganho, não linearidade, ruído, estabilidade
da referência de tensão e calibração.

### 2.5 Vantagens e limitações do processamento digital

O processamento digital oferece vantagens importantes:

1.  **Representação e armazenamento:** informações podem ser codificadas
    em sequências de bits e armazenadas em memórias digitais.
2.  **Reprodutibilidade:** operações digitais podem ser executadas de
    forma consistente, desde que as condições de operação e a
    implementação sejam adequadas.
3.  **Regeneração dos sinais:** circuitos receptores podem reconstruir
    níveis lógicos, reduzindo o efeito acumulado de determinadas
    perturbações.
4.  **Detecção e correção de erros:** técnicas de codificação podem
    identificar e, em determinadas condições, corrigir erros de
    transmissão ou armazenamento.
5.  **Flexibilidade:** funções podem ser alteradas por programação ou
    reconfiguração, sem necessariamente modificar todo o hardware.

Essas vantagens não significam que sistemas digitais sejam imunes a
falhas. Ruído, interferências, limitações de temporização, defeitos de
componentes e erros de projeto também podem comprometer seu
funcionamento. A confiabilidade depende da arquitetura, das
especificações elétricas e das técnicas de proteção e validação
adotadas.

------------------------------------------------------------------------

## 3. Informação e representação binária

O **bit** é a unidade básica de informação em sistemas binários. Como
cada bit pode assumir dois valores, 0 ou 1, um conjunto de (n) bits pode
representar:

\[ N = 2^n \]

combinações distintas.

| Quantidade de bits | Combinações possíveis |
|:------------------:|:---------------------:|
|                  1 |                    2  |
|                  2 |                    4  |
|                  4 |                   16  |
|                  8 |                  256  |
|                 16 |               65.536  |
|                 32 |        4.294.967.296  |

Por exemplo, com 2 bits podem ser formadas as combinações 00, 01, 10 e
11. Com 8 bits, são possíveis 256 combinações, de 00000000 a 11111111.

Um agrupamento de 8 bits é denominado **byte**. Agrupamentos de bits são
utilizados para representar números, caracteres, instruções, estados de
controle e diversos outros tipos de informação.

A interpretação de uma sequência de bits depende da convenção de
codificação utilizada. A sequência 01000001, por exemplo, pode
representar um valor numérico sem sinal ou um caractere, dependendo do
contexto e do padrão adotado.

------------------------------------------------------------------------

## 4. Abstração dos níveis de tensão elétrica para estados lógicos

A **abstração digital** permite projetar e analisar sistemas complexos
utilizando estados lógicos discretos, sem precisar acompanhar
continuamente todos os fenômenos físicos que ocorrem nos transistores e
nas interconexões.

Essa abstração não elimina a natureza elétrica do circuito. Na
implementação física, os estados lógicos são representados por faixas
contínuas de tensão elétrica, definidas pelas especificações dos
dispositivos transmissores e receptores.

### 4.1 Lógica positiva

Na convenção denominada **lógica positiva**, a faixa de tensão mais
baixa representa o estado lógico 0 e a faixa de tensão mais elevada
representa o estado lógico 1.

Em muitos circuitos digitais, são utilizadas tensões de alimentação como
3,3 V e 5 V. Esses valores, entretanto, não devem ser interpretados como
níveis exatos obrigatórios para todas as entradas e saídas. Os limites
válidos dependem da família lógica e do componente utilizado.

De maneira simplificada:

-   **Nível lógico 0 (LOW):** representado por uma faixa de tensão
    baixa, próxima ao potencial de referência do circuito.
-   **Nível lógico 1 (HIGH):** representado por uma faixa de tensão
    alta, próxima ao nível de alimentação positivo do circuito.

Existe também a convenção de **lógica negativa**, na qual a associação
entre os níveis elétricos e os estados lógicos é invertida. Portanto, é
necessário identificar a convenção adotada ao analisar um circuito.

### 4.2 Referências e nomenclaturas de alimentação

Os datasheets utilizam diferentes nomenclaturas para identificar os
terminais de alimentação. Algumas designações usuais são:

|  Nomenclatura  |  Significado usual |
|:--------------:|:----------------------------------|
| $V_{CC}$       | Alimentação positiva, frequentemente utilizada em circuitos bipolares |
| $V_{DD}$       | Alimentação positiva, frequentemente utilizada em circuitos CMOS |
| $V_{SS}$       | Referência inferior ou alimentação negativa em circuitos CMOS; frequentemente conectada ao GND|
| $V_{EE}$       | Alimentação inferior, frequentemente utilizada em circuitos bipolares |
| $GND$          | Referência de potencial do circuito |

Essas designações são convenções usuais, e não equivalências universais.
A função exata de cada terminal deve ser verificada no datasheet do
componente.

### 4.3 Entradas flutuantes e polarização

Uma entrada digital desconectada pode permanecer em um estado elétrico
indefinido, denominado **estado flutuante** (*floating*). Nesse caso,
ruídos e acoplamentos elétricos podem alterar a tensão da entrada e
provocar interpretações imprevisíveis.

Para estabelecer um estado lógico definido quando uma chave ou saída
está desconectada, podem ser utilizados resistores de polarização:

-   **Pull-up:** conecta a entrada, por meio de um resistor, à
    alimentação positiva, estabelecendo HIGH como estado padrão.
-   **Pull-down:** conecta a entrada, por meio de um resistor, à
    referência de potencial, estabelecendo LOW como estado padrão.

A escolha depende da topologia do circuito, do tipo de entrada e da
lógica adotada.

------------------------------------------------------------------------

## 5. Integridade do sinal e imunidade ao ruído

Em circuitos eletrônicos reais, os sinais elétricos estão sujeitos a
perturbações. Essas perturbações podem ser causadas por interferência
eletromagnética, variações na alimentação, acoplamento entre condutores,
ruído térmico, efeitos de chaveamento e características das
interconexões.

Essas perturbações são denominadas **ruídos** e podem modificar a tensão
que chega à entrada de um circuito receptor.

Se um sistema digital exigisse exatamente 0,00 V para representar 0 e
exatamente 5,00 V para representar 1, pequenas variações poderiam
provocar erros frequentes. Para evitar essa dependência de valores
exatos, os circuitos digitais trabalham com faixas de tensão
especificadas.

### 5.1 Especificações elétricas de transmissores e receptores

As folhas de dados (*datasheets*) dos circuitos integrados apresentam
parâmetros que definem os limites elétricos garantidos para os níveis
lógicos.

#### Limites do transmissor - saída

-   $V_{OH}$ (*Voltage Output High*): tensão de saída correspondente ao
    nível HIGH. Em especificações de garantia, utiliza-se normalmente o
    valor mínimo, $V_{OH(min)}$.
-   $V_{OL}$ (*Voltage Output Low*): tensão de saída correspondente ao
    nível LOW. Em especificações de garantia, utiliza-se normalmente o
    valor máximo, $V_{OL(max)}$.

Esses valores indicam os limites garantidos para a tensão produzida pela
saída, sob condições especificadas de alimentação, temperatura e
corrente de carga.

#### Limites do receptor - entrada

-   $V_{IH}$ (*Voltage Input High*): tensão mínima que a entrada
    reconhece garantidamente como nível HIGH. Utiliza-se normalmente
    $V_{IH(min)}$.
-   $V_{IL}$ (*Voltage Input Low*): tensão máxima que a entrada
    reconhece garantidamente como nível LOW. Utiliza-se normalmente
    $V_{IL(max)}$.

Os valores exatos dependem do componente e devem ser consultados em seu
datasheet.

### 5.2 Região de entrada não especificada

O intervalo entre $V_{IL(max)}$ e $V_{IH(min)}$ é uma região na qual o
receptor não garante a interpretação do sinal como 0 ou 1.

Essa região pode ser denominada **região de entrada não especificada**
ou, em determinados contextos didáticos, **zona proibida**.

É importante compreender que a tensão de um sinal atravessa essa região
durante uma transição entre LOW e HIGH, ou entre HIGH e LOW. Isso é
normal. O problema ocorre quando o receptor permanece exposto a uma
tensão nessa região ou quando a transição é lenta ou ruidosa a ponto de
provocar comportamento indesejado.

Assim, não se deve tratar a região intermediária como um terceiro estado
lógico válido em uma entrada binária convencional.

### 5.3 Margem de ruído (*Noise Margin*)

A **margem de ruído** representa a perturbação de tensão que uma
interface pode tolerar, segundo as condições especificadas, antes que a
compatibilidade entre os níveis de saída do transmissor e os níveis de
entrada do receptor deixe de ser garantida.

São calculadas duas margens:

**Margem de ruído em nível alto:**

\[ NM_H = V_{OH(min)} - V_{IH(min)} \]

**Margem de ruído em nível baixo:**

\[ NM_L = V_{IL(max)} - V_{OL(max)} \]

Em uma interface compatível, espera-se que ambas as margens sejam
positivas. Quanto maiores forem as margens, maior será a tolerância
nominal da interface a perturbações de tensão, consideradas as condições
de especificação.

A margem de ruído não deve ser interpretada como uma garantia isolada
contra qualquer tipo de interferência. A integridade do sinal também
depende de fatores como corrente de carga, comprimento e disposição das
trilhas, impedâncias, velocidade de transição, alimentação, aterramento
e características do ambiente eletromagnético.

### 5.4 Exemplo numérico de cálculo das margens de ruído

Considere uma interface digital hipotética com as seguintes
especificações:

| Parâmetro       | Valor |
|:---------------:|:-----:|
|  $V_{OH(min)}$  | 2,7 V |
|  $V_{IH(min)}$  | 2,0 V |
|  $V_{OL(max)}$  | 0,4 V |
|  $V_{IL(max)}$  | 0,8 V |

A margem de ruído em nível alto é:

\[ NM_H = 2,7 - 2,0 \]

\[ \boxed{NM_H = 0{,}7\text{ V}} \]

A margem de ruído em nível baixo é:

\[ NM_L = 0,8 - 0,4 \]

\[ \boxed{NM_L = 0,4\text{ V}} \]

Portanto, para essa interface hipotética, as margens calculadas são 0,7
V para o nível alto e 0,4 V para o nível baixo.

O exemplo mostra que o transmissor não precisa produzir exatamente a
tensão que o receptor utiliza como limite de reconhecimento. Existe uma
faixa de segurança entre os limites garantidos de saída e os limites de
reconhecimento da entrada.

**Observação:** os valores deste exemplo são didáticos e não devem ser
associados a uma família lógica específica. Em um projeto real, os
parâmetros devem ser obtidos nos datasheets dos dispositivos que serão
interligados.

------------------------------------------------------------------------

## 6. Organização funcional de um sistema digital

Os sistemas digitais podem ser compreendidos como uma hierarquia de
elementos, desde os dispositivos semicondutores até os sistemas
computacionais completos.

Uma visão simplificada dessa organização é:

1.  **Transistores:** elementos físicos utilizados na implementação dos
    circuitos.
2.  **Portas lógicas:** estruturas que realizam operações booleanas.
3.  **Circuitos combinacionais:** blocos de processamento lógico sem
    armazenamento de estado.
4.  **Circuitos sequenciais:** blocos que armazenam informações e
    evoluem entre estados.
5.  **Registradores e unidades funcionais:** estruturas que armazenam
    dados e realizam operações.
6.  **Processadores e sistemas computacionais:** sistemas complexos que
    integram processamento, memória e interfaces.

Essa hierarquia será retomada ao longo da disciplina. Ela ajuda a
compreender como operações lógicas elementares podem ser combinadas para
construir circuitos capazes de realizar operações aritméticas, armazenar
informações, controlar processos e executar programas.

------------------------------------------------------------------------

## 7. Síntese da aula

Nesta primeira aula, foram apresentados os conceitos que fundamentam o
estudo dos sistemas digitais:

-   Sistemas digitais representam, processam, armazenam ou transmitem
    informações por meio de valores discretos.
-   O bit é a unidade básica de informação binária e pode assumir os
    valores 0 ou 1.
-   A quantidade de combinações possíveis com (n) bits é $2^n$.
-   A digitalização de sinais analógicos envolve amostragem, quantização
    e codificação.
-   Os estados lógicos são abstrações representadas fisicamente por
    faixas de tensão elétrica.
-   As especificações de entrada e saída definem os limites elétricos
    necessários à comunicação entre circuitos.
-   As margens de ruído expressam a tolerância nominal de uma interface
    a perturbações de tensão.
-   Sistemas digitais complexos são construídos por meio da integração
    hierárquica de transistores, portas lógicas, circuitos
    combinacionais e sequenciais e blocos funcionais.

A compreensão desses fundamentos é essencial para avançar no estudo dos
sistemas de numeração, da álgebra booleana, das portas lógicas, dos
circuitos combinacionais, dos circuitos sequenciais e das arquiteturas
de computadores.

------------------------------------------------------------------------

## 8. Questões para reflexão e fixação

1.  Qual é a diferença fundamental entre representar uma informação por
    uma grandeza analógica e representá-la por uma sequência de bits?
2.  Por que um sinal amostrado ainda não é necessariamente um sinal
    digital quantizado?
3.  Quantas combinações distintas podem ser representadas por 10 bits?
4.  Por que um nível lógico não deve ser associado a um único valor
    exato de tensão?
5.  Qual é a diferença entre resolução e precisão em um conversor A/D?
6.  O que pode acontecer quando uma entrada digital permanece
    desconectada?
7.  Qual é a função dos parâmetros $V_{OH}$, $V_{OL}$, $V_{IH}$ e
    $V_{IL}$?
8.  Por que as margens de ruído HIGH e LOW são calculadas separadamente?
9.  Uma margem de ruído positiva, isoladamente, garante o funcionamento
    correto de qualquer interface digital? Justifique.
10. Qual é a diferença entre um circuito combinacional e um circuito
    sequencial?

------------------------------------------------------------------------

## Referências 

HARRIS, Sarah L.; HARRIS, David. **Digital design and computer
architecture: RISC-V edition**. Cambridge: Morgan Kaufmann, 2022.

NOERGAARD, Tammy. **Embedded systems architecture: a comprehensive guide
for engineers and programmers**. 2. ed. Amsterdam: Newnes, 2013.

TOCCI, Ronald J.; WIDMER, Neal S.; MOSS, Gregory L. **Sistemas digitais:
princípios e aplicações**. 10. ed. São Paulo: Pearson Prentice Hall,
2007.

TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira. **Circuitos
digitais**. Manaus: Centro de Educação Tecnológica do Amazonas;
Universidade Federal de Santa Catarina, Rede e-Tec Brasil, 2012.

