---
title: 0101 - Decodificadores
icon: fontawesome/brands/hive
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Circuitos Combinacionais
    - Decodificadores
---

# 


# Decodificadores

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

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
