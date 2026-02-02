---
title: 0000 - Fundamentos
icon: fontawesome/solid/square-binary
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
---



# Sistemas Digitais

Um sistema digital pode ser definido como um **conjunto de componentes eletrônicos interconectados projetado para processar informações sob uma forma discreta**. Ao contrário dos sistemas analógicos, que lidam com funções e sinais contínuos, os sistemas digitais operam através de pulsos ou intervalos predeterminados, tratando um conjunto finito de valores. Essa estrutura lógica é baseada no sistema de numeração binário, no qual as quantidades são representadas por _bits_ (0 e 1) que simbolizam estados opostos. Fisicamente, esses estados lógicos correspondem à presença ou à ausência de tensão elétrica em elementos específicos do circuito.

A implementação desses sistemas baseia-se em elementos fundamentais: as portas lógicas, que formam a lógica combinacional, e os _flip-flops_, que constituem a base da lógica sequencial. Enquanto na lógica combinacional a saída é estritamente dependente das variáveis de entrada atuais, a lógica sequencial introduz a capacidade de memória, onde o estado da saída é influenciado por estados anteriores e frequentemente sincronizado por pulsos de _clock_.

A análise e o projeto de sistemas digitais modernos exigem diferentes níveis de abstração, partindo do nível elementar de transistores e resistores até blocos funcionais mais complexos, como registradores e processadores. Por fim, visto que a maioria das grandezas físicas é inerentemente analógica, esses sistemas frequentemente integram conversores analógico-digitais (A/D) e digital-analógicos (D/A) para permitir a interface e o processamento eficiente de informações do mundo real.

---


- **1. Fundamentos:** [slide](../slides/SDIG00-Apresentacao.pdf)
	- 1.1 Diferença entre sistemas analógicos e digitais;
	- 1.2 Sistemas de Numeração 
		- 1.2.1 Bases numéricas (Binária, Octal e Hexadecimal)
		- 1.2.2 Códigos (ASCII, BCD e Gray)
- **2. Lógica Combinacional Básica:** 
	- 2.1 Portas lógicas fundamentais (AND, OR, NOT) e suas tabelas-verdade [slide](../slides/SDIG01-ElementosLogicos.pdf)
	- 2.2 Portas lógicas derivadas (NAND, NOR, XOR, XNOR) e suas tabelas-verdade
	- 2.3 Expressões lógicas e circuitos
	- 2.4 Otimização de circuitos através de simplificação de expressões lógicas 
		- 2.4.1 Álgebra de Boole
		- 2.4.2 Teorema de De Morgan
		- 2.4.3 Mapa de Karnaugh
- **3. Blocos Combinacionais Funcionais:** 
	- 3.1 Somadores e subtratores
	- 3.2 Comparadores 
	- 3.3 Decodificadores
	- 3.4 Multiplexadores
- **4. Lógica Sequencial (Armazenamento e Contagem):** 
	- 4.1 Latches e Flip-Flops
	- 4.2 Sinal de _clock_
	- 4.3 Registradores de deslocamento
	- 4.4 Contadores
- **5. Conversores:**
	- 5.1 Conversores A/D e D/A


---

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---
