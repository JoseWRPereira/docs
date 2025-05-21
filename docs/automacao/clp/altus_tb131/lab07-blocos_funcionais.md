---
title: Blocos Funcionais
# icon: fontawesome/solid/cube
icon: fontawesome/brands/uncharted
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Contadores
---

# Blocos Funcionais

## Comparação

- EQ: *EQUAL* - IGUAL
- NE: *NOT EQUAL* - DIFERENTE
- LT - *LESS THAN* - MENOR QUE
- LE - *LESS OR EQUAL* - MENOR OU IGUAL
- GT - *GREATER THAN* - MAIOR QUE
- GE - *GREATER OR EQUAL* - MAIOR OU IGUAL

**Tipos de dados suportados para as comparações**

<!-- ![Inserir Bloco Funcional](./img/h1-7_1-bf_comparacao.png) -->


```PASCAL
                         ________
                        |  COMP  |
|-----------------------|EN      |
                        |        |----- Resultado
            Valor_A ----|        |
            Valor_B ----|________|
```

Os blocos de comparação possuem três entradas e uma saída, sendo elas:

- EN: Entrada do tipo `bool`, que tem como função habilitar a comparação;
- Resultado: Saída do tipo `bool`, que expressa o resultado da operação de comparação entre as duas entradas `Valor_A` e `Valor_B`;
- Valor_A e Valor_B: Valores de comparação. Podem ser de vários tipos: BOOL, BYTE, WORD, DWORD, SINT, USINT, INT, UINT, DINT, UDINT, REAL, LREAL, TIME, DATE, TIME_OF_DAY, DATE_AND_TIME e STRING.

Podemos representar o comportamento do bloco COMP da seguinte forma: 

```
IF EN == True THEN
    Resultado = Valor_A COMP Valor_B
END_IF;
```
O bloco `COMP` representa uma das operações lógicas de comparação.


**1. Função EQ - *EQUAL* - IGUAL**

```PASCAL
                         ________
                        |   EQ   |
|-----------------------|EN      |
                        |        |----- Igual
            Valor_A ----|        |
            Valor_B ----|________|
```


<!-- ![FB_EQ](./img/h1-7_1_1-bf_comparacao_eq.png) -->

**2. Função NE - *NOT EQUAL* - DIFERENTE**

```PASCAL
                         ________
                        |   NE   |
|-----------------------|EN      |
                        |        |----- Diferente
            Valor_A ----|        |
            Valor_B ----|________|
```

<!-- ![FB_NE](./img/h1-7_1_2-bf_comparacao_ne.png) -->

**3. Função LT - *LESS THAN* - MENOR QUE**

```PASCAL
                         ________
                        |   LT   |
|-----------------------|EN      |
                        |        |----- Menor_Que
            Valor_A ----|        |
            Valor_B ----|________|
```

<!-- ![FB_LT](./img/h1-7_1_3-bf_comparacao_lt.png) -->

**4. Função LE - *LESS OR EQUAL* - MENOR OU IGUAL**

```PASCAL
                         ________
                        |   EQ   |
|-----------------------|EN      |
                        |        |----- Menor_ou_Igual
            Valor_A ----|        |
            Valor_B ----|________|
```

<!-- ![FB_LE](./img/h1-7_1_4-bf_comparacao_le.png) -->

**5. Função GT - *GREATER THAN* - MAIOR QUE**

```PASCAL
                         ________
                        |   GT   |
|-----------------------|EN      |
                        |        |----- Maior_Que
            Valor_A ----|        |
            Valor_B ----|________|
```

<!-- ![FB_GT](./img/h1-7_1_5-bf_comparacao_gt.png) -->

**6. Função GE - *GREATER OR EQUAL* - MAIOR OU IGUAL**

```PASCAL
                         ________
                        |   GE   |
|-----------------------|EN      |
                        |        |----- Maior_ou_Igual
            Valor_A ----|        |
            Valor_B ----|________|
```

<!-- ![FB_GE](./img/h1-7_1_6-bf_comparacao_ge.png) -->




---

## Aritméticos

- ADD: Adição
- SUB: Subtração
- ADD/SUB TIME: Adição e Subtração de tempo
- MUL: Multiplicação
- DIV: Divisão
- MOD: Módulo - Resto da Divisão


**Tipos de dados suportados para as operações aritméticas**

Os tipos de dados suportados pelas entradas `Valor_A` e `Valor_B` são:
BYTE, WORD, DWORD, SINT, USINT, INT, UINT, DINT, UDINT, REAL e LREAL;

```PASCAL
                         ________
                        |OPERACAO|
|-----------------------|EN      |
                        |        |----- Resultado
            Valor_A ----|        |
            Valor_B ----|________|
```

As entradas `Valor_A` e `Valor_B` devem ser do mesmo tipo, que é o tipo do `Resultado`.


O bloco `OPERACAO` representa uma das operações aritméticas. 

<!-- ![Inserir Bloco Funcional](./img/h1-7_2-bf_operacao.png) -->

**1. Função ADD - Adição**

```PASCAL
                         _________
                        |   ADD   |
|-----------------------|EN       |
                        |         |----- SOMA
            Valor_A ----|         |
            Valor_B ----|_________|
```
<!-- ![FB_ADD](./img/h1-7_2_1-bf_operacao_add.png) -->

**2. Função SUB - Subtração**

```PASCAL
                         _________
                        |   SUB   |
|-----------------------|EN       |
                        |         |----- SUBTRACAO
            Valor_A ----|         |
            Valor_B ----|_________|
```

<!-- ![FB_SUB](./img/h1-7_2_2-bf_operacao_sub.png) -->

**3. Função ADD/SUB TIME - Adição e Subtração de tempo**

```PASCAL
                         _________
                        | ADD/SUB |
|-----------------------|EN       |
                        |         |----- ADD_SUB_TIME
            Valor_A ----|         |
            Valor_B ----|_________|
```

O tipo de dado aqui suportado é apenas o tipo `TIME`.

Ex: T#45s + T#50s = T#1m35s
<!-- ![FB_ADD_SUB](./img/h1-7_2_3-bf_operacao_add_sub.png) -->

**4. Função MUL - Multiplicação**

```PASCAL
                         _________
                        |   MUL   |
|-----------------------|EN       |
                        |         |----- MULTIPLICACAO
            Valor_A ----|         |
            Valor_B ----|_________|
```

<!-- ![FB_MUL](./img/h1-7_2_4-bf_operacao_mul.png) -->

**5. Função DIV - Divisão**

```PASCAL
                         _________
                        |   DIV   |
|-----------------------|EN       |
                        |         |----- DIVISAO
            Valor_A ----|         |
            Valor_B ----|_________|
```

Funções `DIV` com os seguintes nomes:
`CheckDivByte`, `CheckDivWord`, `CheckDivDWord` e `CheckDivReal` realizam o teste no divisor para evitar divisão por zero.
<!-- ![FB_DIV](./img/h1-7_2_5-bf_operacao_div.png) -->

**6. Função MOD - Módulo - Resto da Divisão**

```PASCAL
                         _________
                        |   MOD   |
|-----------------------|EN       |
                        |         |----- RESTO
            Valor_A ----|         |
            Valor_B ----|_________|
```

<!-- ![FB_MOD](./img/h1-7_2_6-bf_operacao_mod.png) -->








---



<!-- ![Inserir Bloco Funcional](./img/h1-7_0-inserir_instrucao_EN.png) -->



---


## Seleção

- MOVE: Mover
- MIN: Menor valor
- MAX: Maior valor
- LIMIT: Limitadores
- SEL: Seleção
- MUX: Multiplexação

<!-- ![Inserir Bloco Funcional](./img/h1-7_0-inserir_instrucao_EN.png) -->

**1. Função MOVE - Mover**

<!-- ![FB_MOVE](./img/h1-7_3_1-bf_selecao_move.png) -->

```PASCAL
                         ________
                        |  MOVE  |
|-----------------------|EN      |
                        |        |----- DESTINO
              VALOR ----|        |
                        |________|
```


**2. Função MIN - Menor valor**

<!-- ![FB_MIN](./img/h1-7_3_2-bf_selecao_min.png) -->

```PASCAL
                         ________
                        |   MIN  |
|-----------------------|EN      |
                        |        |----- MENOR_VALOR
            VALOR_A ----|        |
            VALOR_B ----|________|
```

**3. Função MAX - Maior valor**

<!-- ![FB_MAX](./img/h1-7_3_3-bf_selecao_max.png) -->
```PASCAL
                         ________
                        |   MAX  |
|-----------------------|EN      |
                        |        |----- MAIOR_VALOR
            VALOR_A ----|        |
            VALOR_B ----|________|
```

**4. Função LIMIT - Limitadores**

<!-- ![FB_LIMIT](./img/h1-7_3_4-bf_selecao_limit.png) -->
```PASCAL
                         _________
                        |  LIMIT  |
|-----------------------|EN       |
            VALOR_MIN --|         |
     VALOR_DE_ENTRADA --|         |----- VALOR_LIMITADO
            VALOR_MAX --|_________|
```


**5. Função SEL - Seleção**

<!-- ![FB_SEL](./img/h1-7_3_5-bf_selecao_sel.png) -->
```PASCAL
                         _________
                        |   SEL   |
|-----------------------|EN       |
              SELECAO --|         |
            ENTRADA_0 --|         |----- VALOR_SELECIONADO
            ENTRADA_1 --|_________|
```




**6. Função MUX - Multiplexação**

<!-- ![FB_MUX](./img/h1-7_3_6-bf_selecao_mux.png) -->

```PASCAL
                         _________
                        |   MUX   |
|-----------------------|EN       |
              SELECAO --|         |
            ENTRADA_0 --|         |----- VALOR_MULTIPLEXADO
            ENTRADA_1 --|_________|
```



---

## Inserir Bloco Funcional

![Inserir Bloco Funcional](img/lab07-inserir_instrucao_EN.png)

---
