---
title: 1000 - Mux/Demux
icon: fontawesome/solid/shuffle
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Circuitos Combinacionais
    - Somador
    - Subtrator
---

# 


# Multiplexadores e Demultiplexadores

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
