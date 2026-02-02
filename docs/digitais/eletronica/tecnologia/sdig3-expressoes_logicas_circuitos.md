---
title: 0011 - Expressões Lógicas
icon: fontawesome/solid/florin-sign
author: José W. R. Pereira
tags: 
    - Sistemas Digitais
    - Eletrônica Digital
    - Portas Lógicas
    - Expressões Lógicas
    - Circuitos
---

# [Expressões Lógicas](../../slides/SDIG02-ExpressoesLogicas.pdf)

Expressões lógicas, também denominadas expressões booleanas, consistem na **representação algébrica** do comportamento de circuitos e sistemas digitais, estabelecendo uma **relação matemática entre variáveis de entrada e uma saída resultante**. Elas fundamentam-se na **Álgebra de Boole**, desenvolvida por George Boole no século XIX, que utiliza postulados e operações simples para resolver problemas práticos de controle através de estados binários: 0 (ausência de tensão ou não-condução) e 1 (presença de tensão ou condução).

As **funções lógicas primárias** que compõem essas expressões são **AND (conjunção), OR (disjunção) e NOT (negação ou inversão)**, a partir das quais derivam-se blocos mais complexos como **NAND, NOR, XOR (OU-Exclusivo) e XNOR (Coincidência)**. Na notação algébrica usual, a operação **AND** é representada por um ponto **($A \cdot B$)** ou pela justaposição das variáveis **($AB$)**, enquanto a operação **OR** é representada pelo sinal de adição **($A + B$)**.

No âmbito do projeto de sistemas, a **interconexão de portas lógicas forma circuitos combinacionais**, cuja saída é descrita por uma expressão booleana que depende exclusivamente das variáveis de entrada atuais. A análise dessas expressões pode ser feita através de tabelas-verdade, que listam todas as combinações possíveis de entrada e seus respectivos resultados. Além disso, **expressões lógicas podem ser estruturadas em formatos específicos** como a **Soma de Produtos** , onde termos de produto são unidos por portas **OR**, ou o **Produto de Somas**, onde termos de soma são unidos por portas **AND**.

É fundamental compreender que essas **expressões podem ser otimizadas utilizando leis e teoremas booleanos**, como as Leis de De Morgan, visando **reduzir a complexidade do hardware e os atrasos de propagação**. Em linguagens de descrição de hardware como VHDL, as expressões lógicas seguem regras estritas de precedência de operadores — onde o NOT possui a maior precedência e o AND precede o OR — sendo o uso de parênteses essencial para garantir a ordem correta de avaliação e evitar ambiguidades.

---

# Mintermos e Maxtermos

No contexto da lógica booleana e do projeto de sistemas digitais, **mintermos** e **maxtermos** representam as **formas canônicas** de descrever matematicamente uma função a partir de uma tabela-verdade.

## Mintermos (Soma de Produtos)

Um mintermo é um **termo de produto (operação lógica AND)** que assume o **valor lógico 1** para uma única combinação específica das variáveis de entrada. Na análise de circuitos combinacionais, os mintermos são utilizados no método da **Soma de Produtos**, onde se identificam **todas as linhas da tabela-verdade cujo resultado da saída é 1**. Para a construção de um mintermo, segue-se a regra de que variáveis com valor 0 aparecem na forma complementada (barrada) e variáveis com valor 1 aparecem na forma não complementada. Ao realizar a **disjunção (operação OR) de todos os mintermos** que resultam em saída alta, obtém-se a **expressão lógica completa do sistema**.

## Maxtermos (Produto de Somas)

Em contrapartida, um maxtermo é um **termo de soma (operação lógica OR)** que produz o **valor lógico 0** para uma combinação exclusiva das variáveis de entrada. O uso de maxtermos fundamenta o método de **Produto de Somas**, que é menos frequente em sistemas digitais, mas igualmente válido do ponto de vista algébrico. Na convenção de maxtermos, a lógica é invertida em relação aos mintermos: a variável assume a forma não complementada se seu valor for 0 e a forma complementada se seu valor for 1, visando forçar o resultado do termo de soma para 0. A **função completa** é obtida através da **conjunção (operação AND) de todos os maxtermos que representam as saídas 0 da tabela-verdade**.


A distinção entre esses conceitos é vital para a otimização de hardware, pois:

*   **Minimização:** Ambas as representações podem ser simplificadas utilizando as leis da Álgebra de Boole ou o **Mapa de Karnaugh** para reduzir a complexidade do circuito e os atrasos de propagação.

*   **Dualidade:** Através do **Teorema de De Morgan**, é possível demonstrar que uma expressão em Soma de Produtos (mintermos) é logicamente equivalente ao complemento de uma expressão em Produto de Somas (maxtermos).

*   ***Don't Care:*** Em projetos avançados, condições de "não importa" (*don't care*) podem ser tratadas como 0 ou 1 para simplificar ainda mais os agrupamentos de mintermos ou maxtermos em um diagrama de Veitch-Karnaugh.


Na análise e síntese de sistemas digitais, a compreensão da hierarquia de precedência e das operações lógicas é fundamental para evitar ambiguidades no comportamento dos circuitos e garantir a inferência correta de hardware. As expressões lógicas fundamentam-se na Álgebra de Boole, que utiliza estados binários (0 e 1) para resolver problemas de controle e processamento de informação.

Abaixo, detalham-se a tabela de precedência e as principais operações lógicas booleanas.

**Tabela de Precedência de Operadores**

A hierarquia de precedência define a ordem em que os operadores são avaliados em uma expressão. No contexto de linguagens de descrição de hardware (como VHDL), a ordem de precedência, da maior para a menor, é organizada em classes:

| Precedência | Classe de Operadores | Operadores |
| :--- | :--- | :--- |
| **Maior** | Diversos | `**`, `abs`, `not` |
| | Multiplicação | `*`, `/`, `mod`, `rem` |
| | Sinal | `+`, `-` |
| | Adição | `+`, `-`, `&` (concatenação) |
| | Deslocamento | `sll`, `srl`, `sla`, `sra`, `rol`, `ror` |
| | Relacionais | `=`, `/=`, `<`, `<=`, `>`, `>=` |
| **Menor** | Lógicos | `and`, `or`, `nand`, `nor`, `xor`, `xnor` |

**Nota importante sobre ambiguidade:** Na Álgebra de Boole clássica, a operação **AND** geralmente tem precedência sobre a **OR**. No entanto, em linguagens como VHDL, todos os operadores lógicos (exceto o `not`) possuem o mesmo nível de precedência, tornando o uso de parênteses essencial para definir a ordem desejada e evitar erros de compilação.

---

# Axiomas e Teoremas

Para a simplificação de expressões, as fontes destacam postulados fundamentais:

*   **Identidade:** 
    * $A + 0 = A$
    * $A \cdot 1 = A$

*   **Nulo (Absorvente):** 
    * $A + 1 = 1$
    * $A \cdot 0 = 0$

*   **Idempotência:** 
    * $A + A = A$
    * $A \cdot A = A$

*   **Complementaridade:** 
    * $A + \overline{A} = 1$
    * $A \cdot \overline{A} = 0$

*   **Involução (Dupla Negação):** 
    * $\overline{\overline{A}} = A$
    

A álgebra de Boole, formalizada pelo matemático inglês George Boole em meados do século XIX, constitui a base teórica essencial para o desenvolvimento e a simplificação de sistemas e circuitos lógicos digitais. Esta estrutura algébrica permite solucionar problemas práticos de controle através de operações sobre variáveis que assumem apenas dois estados discretos: 0 (falso ou ausência de tensão) e 1 (verdadeiro ou condução).

Abaixo estão detalhados os postulados, leis e teoremas fundamentais conforme a literatura técnica:

---

# Propriedades e Leis Algébricas

Essas leis regem a manipulação de expressões complexas e seguem princípios similares à álgebra convencional, com exceções específicas.

*   **Comutativa:** A ordem das variáveis não altera o resultado da operação
    * $A + B = B + A$
    * $A \cdot B = B \cdot A$
    
*   **Associativa:** O agrupamento de termos em somas ou produtos não altera o resultado final 
    * $A + (B + C) = (A + B) + C$
    * $A \cdot (B \cdot C) = (A \cdot B) \cdot C$
    
*   **Distributiva:** Permite a expansão ou fatoração de termos 
    * $A \cdot (B + C) = (A \cdot B) + (A \cdot C)$
    * $(A \cdot B) + C = (A + C) \cdot (B + C)$
    
*   **Absorção:** Termos redundantes são eliminados pela variável dominante 
    * $A + A \cdot B = A$
    * $A \cdot (A + B) = A$

---

# Teoremas de De Morgan

Augustus De Morgan estabeleceu dois teoremas vitais que permitem a conversão entre operadores e a simplificação de barras de inversão sobre expressões complexas.

*   **Primeira Lei:** O complemento do produto de variáveis é igual à soma dos complementos individuais 
    * $\overline{A \cdot B} = \overline{A} + \overline{B}$
    
*   **Segunda Lei:** O complemento da soma de variáveis é igual ao produto dos complementos individuais 
    * $\overline{A + B} = \overline{A} \cdot \overline{B}$

**Princípio da Dualidade**

Toda expressão booleana permanece válida se os operadores AND e OR forem trocados entre si, simultaneamente com a troca dos valores lógicos 0 e 1. Este princípio é fundamental para a síntese de hardware, permitindo, por exemplo, a implementação de uma porta AND utilizando uma porta OR com entradas e saídas invertidas.


---

# Referências e complementos

- **TOCCI, Ronald J.; WIDMER, Neal S.** _Sistemas Digitais: Princípios e Aplicações_. 8. ed. Pearson, 2015.
- **PALANIAPPAN, Ramaswamy.** _Digital Systems Design_. bookboon.com, 2011.
- **TRINDADE JUNIOR, Rosumiro; JULIÃO, Jodelson Moreira.** _Circuitos Digitais_. Manaus: Centro de Educação Tecnológica do Amazonas (CETAM), 2012.
- **D’AMORE, Roberto.** _VHDL: Descrição e Síntese de Circuitos Digitais_. LTC.

---

---
