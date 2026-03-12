---
title: 0101 - Circuitos combinacionais
icon: fontawesome/solid/object-group
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Circuitos Combinacionais
    - Somador
    - Subtrator
---

# 

**Circuitos combinacionais**

1. Somadores e subtratores
2. Comparadores
3. Decodificadores
4. Multiplexadores e Demultiplexadores

---

# 1. Somadores e subtratores

Os circuitos somadores e subtratores são blocos fundamentais da eletrônica digital, pertencentes à categoria dos circuitos aritméticos. Eles são os componentes centrais da Unidade Lógica e Aritmética (ULA) de um computador, onde executam os cálculos matemáticos binários necessários para o processamento de dados.

## Circuitos Somadores
Os somadores realizam a adição de números binários e são divididos em dois tipos principais conforme a complexidade da operação:

*   **Meio Somador (*Half Adder*):** É o circuito mais simples, projetado para somar apenas um bit de cada entrada ($A$ e $B$). Ele possui duas saídas: **SOMA**, que corresponde a uma porta lógica XOR ($A \oplus B$), e **VAI-UM** (*Carry*), resultante de uma porta AND ($A \cdot B$) que sinaliza o transporte para a próxima casa decimal.
*   **Somador Completo (*Full Adder*):** Diferente do meio somador, este circuito possui uma terceira entrada para o transporte vindo de uma operação anterior (*Carry-in* ou "vem-um"). Isso permite que múltiplos somadores completos sejam interconectados em paralelo para realizar a soma de números com $n$ bits.

## Circuitos Subtratores
Os subtratores operam sob o conceito de "empresta-1" (*Borrow*), similar à subtração decimal.

*   **Meio Subtrator (*Half Subtractor*):** Realiza a subtração de um bit de informação. Suas saídas são a **DIFERENÇA** (uma porta XOR) e o **EMPRESTA-1**, que assume nível lógico 1 apenas quando a entrada $A$ é 0 e a entrada $B$ é 1.
*   **Subtrator Completo:** Assim como o somador completo, ele considera o bit emprestado de uma etapa anterior para permitir a subtração de múltiplos bits.

## Implementação e Integração
Na prática da arquitetura de computadores, é comum otimizar o hardware utilizando circuitos somadores para realizar também a subtração através da lógica de **complemento de dois**. Nesse processo, inverte-se o subtraendo e soma-se 1 (ajustando o bit de transporte de entrada para 1), o que permite que um somador paralelo execute a função de um subtrator. 

Existem ainda circuitos **Somadores/Subtratores Duais**, que utilizam portas XOR como inversores controlados: quando o sinal de controle é 1, o circuito atua como subtrator (complementando a entrada); quando é 0, atua como um simples somador. Esses circuitos integrados, como a série 74LS283, são amplamente utilizados para manipulação de dados em sistemas digitais.

---

# 2. Comparadores

Circuitos comparadores são blocos fundamentais da eletrônica digital, classificados como circuitos combinacionais, o que significa que suas saídas dependem única e exclusivamente das variáveis de entrada em um determinado instante. Eles operam em um nível de abstração superior ao das portas lógicas básicas, sendo frequentemente agrupados com somadores, contadores e registradores no projeto de sistemas digitais.

Abaixo, detalham-se sua definição e princípio de funcionamento:

## Definição e Finalidade
A função primordial de um comparador é analisar dois números binários (geralmente denominados $A$ e $B$) para determinar a relação de magnitude entre eles. O resultado dessa comparação é expresso através de saídas digitais que indicam três condições possíveis:

*   **$A > B$:** A saída correspondente assume nível lógico 1 se o valor de $A$ for superior ao de $B$.
*   **$A < B$:** A saída assume nível lógico 1 se $A$ for inferior a $B$.
*   **$A = B$:** Ambas as saídas de magnitude (maior e menor) permanecem em nível lógico 0, indicando igualdade, ou uma terceira saída específica de igualdade é ativada.

## Funcionamento e Estrutura
O funcionamento de um comparador de $n$ bits baseia-se na comparação bit a bit das entradas, seguindo uma lógica de prioridade que geralmente procede do bit mais significativo (MSB) para o bit menos significativo (LSB).

1.  **Lógica Celular:** Comparadores para múltiplos bits são frequentemente construídos de forma modular ou celular. Cada célula processa um par de bits ($a_i, b_i$) e recebe informações de células anteriores através de entradas de cascateamento.
2.  **Processo de Decisão:** Se, ao comparar os bits mais significativos, o circuito detectar que $a_n=1$ e $b_n=0$, ele define imediatamente que $A > B$, independentemente dos bits de menor peso. A comparação só avança para os bits subsequentes se os bits atuais forem iguais.
3.  **Implementação Física:** Embora possam ser descritos textualmente em linguagens como VHDL, fisicamente os comparadores são implementados através da interconexão de portas lógicas que realizam operações de "E" (AND), "OU" (OR) e "OU-Exclusivo" (XOR/XNOR) para inferir a igualdade ou diferença entre os sinais.

Esses componentes são essenciais em unidades de processamento para a execução de instruções de tomada de decisão e em controladores que exigem o monitoramento de limites numéricos.

---

# 3. Decodificadores

No contexto da eletrônica digital e da arquitetura de computadores, um **decodificador** é um circuito combinacional projetado para converter um código de entrada binário (geralmente considerado "desconhecido" ou compactado) em um código de saída reconhecível pela máquina ou pelo usuário. Tecnicamente, ele realiza a operação inversa de um codificador.

Os principais aspectos técnicos que definem esses dispositivos são:

## Princípio de Funcionamento
Um decodificador possui $N$ linhas de entrada binárias e $2^N$ linhas de saída. Sua característica fundamental é que, para cada combinação única das variáveis de entrada, **apenas uma linha de saída é acionada** por vez. 

*   **Entradas:** Recebem um endereço ou código binário de $n$ bits.
*   **Saídas:** Representam todas as combinações possíveis ($2^n$). Se as saídas forem "Ativas em Alto" (*Active High*), a saída selecionada assume o nível lógico 1 enquanto as demais permanecem em 0. Se forem "Ativas em Baixo" (*Active Low*), como é comum em muitos circuitos integrados (CIs) comerciais, a saída selecionada vai para o nível lógico 0 e as outras permanecem em 1.

## Implementação e CIs Comuns
Na prática, os decodificadores são encontrados na forma de circuitos integrados. Um exemplo clássico mencionado nas fontes é o **74xx138**, um decodificador de 3 para 8 linhas (binário para octal). 

*   Ele possui entradas de habilitação (*Enable*), que permitem ativar ou desativar o chip independentemente das entradas de dados. 
*   Se as entradas de habilitação não estiverem no estado correto, todas as saídas permanecem inativas.

## Aplicações Acadêmicas e de Projeto
Para o estudante de engenharia ou ciência da computação, os decodificadores são essenciais para:

*   **Seleção de Memória:** São usados para rotear sinais de barramentos de endereço para chips específicos de memória ou periféricos.
*   **Decodificação de Instruções:** Em microprocessadores, ajudam a identificar qual operação deve ser executada a partir de um código de instrução binário.
*   **Conversores de Display:** Decodificadores como o de BCD para sete segmentos convertem números binários em sinais para acender os segmentos corretos de um mostrador numérico.
*   **Demultiplexação:** Muitos CIs decodificadores (como o 74138) podem operar como **demultiplexadores** (distribuidores de dados) ao utilizar um de seus pinos de habilitação como entrada de dados e as entradas normais como seletores de rota.

Em resumo, o decodificador atua como um tradutor de endereços binários, permitindo que um sistema digital aponte para um recurso ou função específica dentro de uma vasta gama de opções possíveis.

---

# 4. Multiplexadores e Demultiplexadores

Multiplexadores e demultiplexadores são circuitos combinacionais fundamentais na eletrônica digital, utilizados para o gerenciamento e roteamento de sinais de dados.

## Multiplexadores (MUX)
Um multiplexador, frequentemente designado pela sigla **MUX** ou como seletor de dados, é um circuito projetado para selecionar uma entre diversas entradas de dados e roteá-la para uma única saída comum. Ele funciona de maneira análoga a uma chave seletora controlada eletronicamente, permitindo que múltiplos sinais compartilhem um único caminho de comunicação ou recurso.

**Funcionamento:**

*   **Lógica de Seleção:** A escolha de qual entrada será conectada à saída é determinada por variáveis de controle denominadas **variáveis de seleção**.
*   **Relação Matemática:** Existe uma relação estrita entre o número de entradas ($N$) e o número de variáveis de seleção ($m$), definida pela fórmula $N = 2^m$. Por exemplo, um MUX de 4 canais requer 2 variáveis de seleção ($2^2=4$), enquanto um de 8 canais requer 3 ($2^3=8$).
*   **Expressão Lógica:** Internamente, o MUX utiliza portas AND, OR e NOT. Para um MUX de dois canais com seleção $V$ e entradas $E_1$ e $E_2$, a saída $S$ é regida pela expressão $S = \bar{V} \cdot E_1 + V \cdot E_2$.
*   **Hardware e Implementação:** Na prática, são encontrados em circuitos integrados como o **74xx157**, que agrupa quatro multiplexadores de 2 para 1 em um único chip. Em projetos modernos usando VHDL, multiplexadores são descritos eficientemente através de construções como `WHEN ELSE` (atribuição condicional) ou `WITH SELECT`.

## Demultiplexadores (DEMUX)
O demultiplexador (ou **DEMUX**) executa a operação inversa ao multiplexador: ele recebe um único sinal em sua entrada e o distribui para uma entre várias saídas possíveis. Por essa função, ele é tecnicamente conhecido como um distribuidor de dados.

**Funcionamento:**

*   **Lógica de Distribuição:** Assim como no MUX, a seleção da saída que receberá o dado de entrada é feita por meio de variáveis de seleção.
*   **Relação Matemática:** A mesma relação de potência de 2 se aplica, onde o número de saídas ($N$) é função do número de variáveis de seleção ($m$), ou seja, $N = 2^m$.
*   **Expressão Lógica:** Em um DEMUX de dois canais, a entrada $E$ é direcionada para a saída $S_1$ se a seleção $V=0$, ou para $S_2$ se $V=1$, resultando nas expressões $S_1 = \bar{V} \cdot E$ e $S_2 = V \cdot E$.
*   **Dualidade com Decodificadores:** Muitos circuitos integrados decodificadores, como o **74xx138** (3 para 8 linhas), podem operar como demultiplexadores ao utilizar um de seus pinos de habilitação (*Enable*) como entrada de dados e as entradas de endereço como seletores de rota.

Esses dispositivos são essenciais na arquitetura de computadores para a multiplexação de barramentos e para economizar conexões físicas em sistemas complexos.

---

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
