---
title: 03 - Concorrência
icon: fontawesome/solid/equals
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---


A característica definidora do VHDL é a **concorrência**: exceto em regiões de código sequencial (como processos ou subprogramas), todos os comandos em uma arquitetura são executados simultaneamente. A ordem na qual esses comandos são apresentados no código é irrelevante para o comportamento da descrição, espelhando a operação conjunta dos elementos em um circuito digital.

---

**1. O Conceito Crítico de Atraso Delta ($\Delta$)**

Para manter a integridade da simulação em um ambiente onde a execução é concorrente, o simulador VHDL emprega um mecanismo interno de coordenação temporal conhecido como **atraso delta** ($\Delta$).

O $\Delta$ é um intervalo de tempo nulo ($\Delta=0$). Quando um evento ocorre em um sinal (ou seja, seu valor muda), todos os comandos sensíveis a esse sinal são avaliados. O resultado dessas avaliações é agendado para transferência ao sinal de destino em $1\Delta$ de tempo. Uma vez que esta primeira iteração ($\Delta$) é concluída, a nova condição de sinal pode ativar novos comandos, repetindo o processo em sucessivas iterações ($2\Delta, 3\Delta, \ldots$) até que o circuito atinja uma condição estável, onde nenhuma nova mudança é agendada.

A rigidez deste mecanismo é vital para garantir que a lógica e o comportamento do circuito simulado sejam independentes da ordem de avaliação sequencial interna do simulador. Em casos onde um circuito atinge um estado instável (como um laço com _delay_ nulo), o simulador, após um limite de iterações, aborta a simulação para evitar execuções infinitas.

---

**2. Atribuição de Valores a Sinais**

A atribuição de um valor a um objeto da classe _sinal_ é realizada pelo delimitador `<=`, que é a forma mais básica de comando concorrente, transferindo o valor de uma fonte ou expressão para um sinal de destino.

Não é permitida a transferência de valores entre objetos declarados com tipos diferentes.

---

**3. Estruturas de Decisão Concorrente para Lógica Combinacional**

Para a modelagem de circuitos de seleção e decodificação na camada concorrente, são utilizadas as construções `WHEN ELSE` e `WITH SELECT`. Embora ambas permitam o roteamento de dados com base em condições, elas implicam estruturas de hardware fundamentalmente diferentes devido à prioridade de avaliação.

**3.1. Construção `WHEN ELSE` (Atribuição Condicional de Sinal)**

A construção `WHEN ELSE` define uma transferência condicional que é avaliada em **ordem de prioridade**. A sintaxe consiste em uma lista de opções, onde a primeira condição que retorna o valor verdadeiro define o valor a ser transferido ao sinal de destino.

> **Estrutura Implicada:** Devido à prioridade sequencial, o hardware inferido corresponde a uma **cadeia de seletores**, Figura 1, ou um **codificador de prioridade**. Ao modelar circuitos onde a precedência das condições é inerente (como um decodificador de interrupção ou prioridade), o `WHEN ELSE` é frequentemente mais sucinto e reflete melhor o comportamento desejado.

| Figura 1: Cadeia de seletores      |
|:----------------------------------:|
| ![WhenElse](img/v03-when_else.png) |
| Fonte: Autor                       |

Segue código genérico de implementação da estrutura da cadeia seletora apresentada na Figura 1. Note que o tipo das entradas e saída devem ser os mesmos, inclusive sua dimensão, se forem declarados do tipo `bit_vector`. A variável de seleção não precisam ser do mesmo tipo ou dimensão das entradas e saída. 

```vhdl title="When Else"
entity sel is
    port(
        Expression_1, Expression_2, Expression_3: in <type>;
        Condition_1, Condition2: in <type>;
        signal_name: out <type>
    );
end entity;

architecture behavioral of sel is
begin
    signal_name <=  expression_1 when condition_1 else
                    expression_2 when condition_2 else
                    expression_3;
end architecture;
```



A Figura 2 ilustra uma simbologia de implementação de um mux de quatro entradas (D0..D3), duas seleções (S0,S1) e uma saída (Y), que será usado para exemplificar as aplicações da estrutura `when else` e `with select`.

| Figura 2: MUX 4x1                         |
|:-----------------------------------------:|
| ![WhenElse](img/v03-when_else_mux4x1.png) |
| Fonte: Autor                              |


```vhdl title="MUX 4x1 com when else"
entity mux4x1 is 
    port(
            D0, D1, D2, D3: in  bit;
            S0, S1:         in  bit;
            Y:              out bit
        );
end entity mux4x1;


architecture main of mux4x1 is 
    signal sel : bit_vector(1 downto 0) := "00";
begin
    sel <= S1 & S0; -- Concatenação de bits

    Y <=    D0 when sel = "00" else
            D1 when sel = "01" else
            D2 when sel = "10" else
            D3;
end architecture main;
```


![MUX4x1_when_else](img/v03-mux4x1_when_else.png)



**3.2. Construção `WITH SELECT` (Atribuição Selecionada de Sinal)**

A construção `WITH SELECT` utiliza uma _expressão de escolha_ para definir o valor do sinal de destino. Ao contrário do `WHEN ELSE`, todas as condições de seleção são avaliadas com a **mesma prioridade** e devem ser **mutuamente exclusivas**. É obrigatório que todas as possíveis condições da expressão de escolha sejam cobertas, frequentemente utilizando-se a cláusula `OTHERS` para englobar as condições restantes.

> **Estrutura Implicada:** O circuito equivalente corresponde a um **circuito de seleção comandado por um decodificador** que detecta as condições.



```vhdl title="MUX 4x1 com with select"
entity mux4x1 is 
    port(
            D0, D1, D2, D3: in  bit;
            S0, S1:         in  bit;
            Y:              out bit
        );
end entity mux4x1;

architecture main of mux4x1 is 
    signal sel : bit_vector(1 downto 0) := "00";
begin
    sel <= S1 & S0; -- Concatenação de bits

    with sel select
        Y   <=      D0 when "00",
                    D1 when "01",
                    D2 when "10",
                    D3 when others;
end architecture;
```

![mux4x1_with_select](img/v03-mux4x1_with_select.png)


**3.3. Inferência de Elementos de Memória (Latches)**

Um cuidado essencial na utilização destas construções é garantir que **todas as combinações lógicas** que possam ocorrer sejam endereçadas pela atribuição de um novo valor. Se uma condição de escolha não for coberta pelo código, o sintetizador assume que o valor anterior do sinal deve ser mantido, o que implica a necessidade de um elemento de memória sensível a nível (_latch_). Esse comportamento é a base para a inferência de _latches_.

---

**4. Delimitação de Regiões Concorrentes**

O VHDL oferece comandos para organizar e modularizar o código concorrente.

**4.1. Comando `BLOCK`**

O comando `BLOCK` (`BLOCO`) permite dividir o código em regiões, melhorando a organização e clareza, mas não interfere no circuito sintetizado. Sinais declarados dentro de um bloco têm sua visibilidade restrita ao seu interior.

Uma aplicação avançada do `BLOCK` é a implementação de _sinais de guarda_ (`GUARDED`), onde um sinal dentro do bloco pode ser desabilitado sob certas condições. Se o sinal for declarado como `BUS`, a desativação pode inferir um estado de alta impedância (`Z`). Caso contrário, o sintetizador pode inferir um _latch_. No entanto, esta construção é frequentemente considerada obsoleta e deve ser tratada com cautela em síntese.


**4.2. Comando `PROCESS`**

O comando `PROCESS` (`PROCESSO`) delimita uma área contendo comandos sequenciais. Embora os comandos internos sejam sequenciais, o processo em si é um comando concorrente, executado simultaneamente com outros comandos concorrentes (incluindo outros processos).

A ativação de um processo é determinada pela **lista de sensibilidade**; se houver uma alteração de valor em qualquer sinal listado, o processo é executado sequencialmente do início ao fim.

**5. Palavra Reservada `UNAFFECTED`**

A palavra reservada `UNAFFECTED` (`NÃO AFETADO`), válida apenas no VHDL-1993, pode ser usada em atribuições concorrentes (como `WHEN ELSE` ou `WITH SELECT`). Ela indica explicitamente que, sob uma determinada condição, o valor do sinal de destino não deve ser alterado. Embora útil para clareza, ela não é universalmente suportada pelas ferramentas de síntese.

---

**Tabela de Comparação de Comandos Concorrentes**

|Comando|Execução|Prioridade|Cobertura Total|Estrutura Lógica Inferida|
|:--|:--|:--|:--|:--|
|`WHEN ELSE`|Concorrente|Prioritária (sequencial)|Opcional|Codificador de Prioridade (Encadeamento de Seletores)|
|`WITH SELECT`|Concorrente|Paralela (Equivalente)|Obrigatória|Multiplexador (Seletor Decodificado)|
|Atribuição `<=`|Concorrente|N/A|N/A|Lógica Combinacional Direta|

---

A Figura 5 apresenta o RTL gerado para cada um dos códigos apresentados anteriormente, usando `WHEN ELSE` em (a) e  `WITH SELECT` em (b).  

| Figura 5: RTL das duas versões de MUX 4x1 |
|:-----------------------------------------:|
| ![RTL](img/v03-rtl.png) |
|Fonte: Autor |

---

**Referências**

1. D'AMORE, Roberto. **VHDL**: descrição e síntese de circuitos digitais. 2. ed. Rio
de Janeiro: LTC, 2012.
