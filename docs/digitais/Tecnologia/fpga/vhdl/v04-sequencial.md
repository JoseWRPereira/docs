---
title: 04 - Sequencial
icon: fontawesome/solid/arrows-turn-right
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---




**Comandos Sequenciais Básicos em VHDL**
  
A elaboração de projetos de _Hardware Description Language_ (HDL) em VHDL frequentemente exige a delimitação de regiões de código que devem ser executadas em sequência, necessárias para descrever o comportamento interno de estruturas digitais complexas, como máquinas de estados e lógica de controle.

Comandos sequenciais são inerentemente localizados em contextos específicos da linguagem, notadamente dentro de **processos** ou **subprogramas** (funções e procedimentos). Uma vez iniciada a execução em uma região de código sequencial, os comandos são avaliados na ordem em que aparecem, diferentemente dos comandos concorrentes, onde a ordem é irrelevante.

---

**1. Processos e a Lista de Sensibilidade**

O comando **PROCESS** define uma região de código sequencial, mas ele próprio opera como um comando concorrente. Uma descrição VHDL pode conter múltiplos processos que, embora executados internamente em sequência, operam simultaneamente uns com os outros.

A execução de um processo é governada pela **Lista de Sensibilidade**, um conjunto de sinais especificados após a palavra-chave `PROCESS`. Uma alteração no valor de qualquer sinal listado ativa o processo, resultando na avaliação sequencial dos comandos internos. Ao término da execução, o processo é suspenso, aguardando um novo evento na lista.

A lista de sensibilidade é crítica, pois a omissão de um sinal de entrada relevante pode levar a um comportamento sequencial indesejado (a manutenção do valor anterior), que nem sempre é corretamente inferido como um elemento de memória pelas ferramentas de síntese.

**Exemplo de Processo com Lista de Sensibilidade**:

```vhdl
ENTITY exemplo IS
	PORT ( a, b   : IN  BIT;
		   sa, sb : OUT BIT );
END ENTITY;

ARCHITECTURE teste OF exemplo IS
BEGIN
	abc: PROCESS (a) -- executado na alteracao do valor de 'a'
	BEGIN
		sa <= a;
		sb <= b;
	END PROCESS abc;
END ARCHITECTURE;
```

![Sensibilidade_a](img/v04-sens_a.png)


---

**2. Atribuição de Valor em Regiões Sequenciais**

Em regiões de código sequencial, a atribuição de valor a um sinal utiliza o delimitador $`<=`$. É fundamental compreender que, embora o comando seja executado sequencialmente, a atualização do valor do sinal não é imediata. Em vez disso, a atribuição é **agendada** para ocorrer após um intervalo de tempo nulo ($\Delta$) na suspensão do processo (ou seja, quando o simulador coordena as iterações dos comandos concorrentes).

A ordem de execução é crucial. Se houver múltiplas atribuições a um sinal dentro do mesmo processo, todas as atribuições são avaliadas sequencialmente, mas apenas a última agendada é efetivada após o atraso $\Delta$.

**Exemplo de Agendamento em Processo**:

Este exemplo ilustra como a ordem sequencial dos comandos interage com o agendamento de sinais, que se torna visível na iteração seguinte (devido ao $\Delta$):

```vhdl
ENTITY exemplo IS
    PORT (  a      : IN     BIT;
            s0, s1 : BUFFER BIT  );
END ENTITY;

ARCHITECTURE teste OF exemplo IS
BEGIN
	PROCESS (a, s0)
	BEGIN
		s1 <= s0;
		s0 <= a;
	END PROCESS;
END ARCHITECTURE;
```

![AgendaProcesso](img/v04-agendaProcess.png)


---

**3. Estruturas de Execução Condicional**

Duas construções principais permitem a execução condicional de comandos sequenciais: `IF ELSE` e `CASE WHEN`.

**3.1. Construção IF ELSE**

A estrutura `IF ELSE` permite avaliar uma lista de condições em ordem de prioridade. Se a primeira condição (`IF`) for verdadeira, o bloco de comandos associado é executado, e a estrutura é encerrada. Se não, as condições subsequentes (`ELSIF`) são avaliadas sequencialmente até que uma seja verdadeira. Se nenhuma for verdadeira e uma cláusula `ELSE` estiver presente, seu bloco de comandos é executado.

Esta construção, devido à sua natureza sequencial de avaliação e prioridade implícita, é frequentemente usada para descrever lógica de prioridade ou elementos de memória (como _latches_ ou _flip-flops_).

**Exemplo de Multiplexador 4 para 1 com IF ELSE**:

```vhdl
ENTITY mux_4x1 IS
    PORT(   in0, in1, in2, in3 : IN  BIT;
            s0, s1             : IN  BIT;
            out0               : OUT BIT  );
END ENTITY;

ARCHITECTURE teste_if_else OF mux_4x1 IS
    SIGNAL sel : BIT_VECTOR(1 DOWNTO 0);
BEGIN
    sel <= s1 & s0;
    abc: PROCESS (in0, in1, in2, in3, sel) -- sinal "sel" inserido na lista
    BEGIN
        IF sel = "00" THEN
            out0 <= in0;
        ELSIF sel = "01" THEN
            out0 <= in1;
        ELSIF sel = "10" THEN
            out0 <= in2;
        ELSE
            out0 <= in3;
        END IF;
    END PROCESS abc;
END teste_if_else;
```

**3.2. Construção CASE WHEN**

A estrutura `CASE WHEN` executa comandos sequenciais com base no valor de uma única expressão de escolha. As condições de escolha devem ser **mutuamente exclusivas**, e todas as possibilidades de valor da expressão devem ser cobertas, frequentemente utilizando a cláusula **OTHERS** para englobar os valores restantes.

O tipo de retorno da expressão de escolha deve ser discreto (como `INTEGER` ou `BIT_VECTOR`). Por não ter prioridade implícita, o `CASE WHEN` é frequentemente preferido para descrever estruturas de seleção ou decodificação sem hierarquia de decisão, resultando em circuitos mais eficientes do que estruturas complexas aninhadas de `IF ELSE`.

**Exemplo de Multiplexador 4 para 1 com CASE WHEN**:

```vhdl
ENTITY mux_4x1 IS
	PORT(   in0, in1, in2, in3 : IN  BIT;
			s0, s1             : IN  BIT;
			out0               : OUT BIT  );
END mux_4x1;

ARCHITECTURE teste_case_when OF mux_4x1 IS
	SIGNAL sel : BIT_VECTOR(1 DOWNTO 0);
BEGIN
	sel <= s1 & s0;
	abc: PROCESS (in0, in1, in2, in3, sel) -- sinal "sel" inserido na lista
	BEGIN
		CASE sel IS
			WHEN "00" => out0 <= in0;
			WHEN "01" => out0 <= in1;
			WHEN "10" => out0 <= in2;
			WHEN OTHERS => out0 <= in3;
		END CASE;
	END PROCESS abc;
END teste_case_when;
```

---

**4. Comandos de Controle de Fluxo**

**4.1. Comando WAIT**

O comando **WAIT** é usado para suspender a execução de um processo ou procedimento. É uma alternativa fundamental à Lista de Sensibilidade; um processo não pode conter ambos. As três formas de uso são:

1. **WAIT ON (Lista de Sinais):** Suspende até que um evento ocorra em qualquer sinal especificado, funcionando de forma equivalente a uma lista de sensibilidade.
2. **WAIT UNTIL (Expressão Booleana):** Suspende até que a expressão se torne verdadeira. É crucial na inferência de registradores sensíveis à borda.
3. **WAIT FOR (Expressão de Tempo):** Suspende a execução por um período definido, amplamente utilizado em entidades de teste.

**Exemplo de Uso de WAIT ON**:

```vhdl
ENTITY mux_4x1 IS
	PORT( in0, in1, in2, in3 : IN  BIT; 
		  s0, s1             : IN  BIT;
		  out0               : OUT BIT);
END teste_wait;

ARCHITECTURE teste_wait OF mux_4x1 IS
	SIGNAL int0, int1, int2, int3 : BIT;
BEGIN
	PROCESS
	BEGIN
		out0 <= int0 OR int1 OR int2 OR int3;
		int0 <= in0 AND NOT s1 AND NOT s0;
		int1 <= in1 AND NOT s1 AND s0;
		int2 <= in2 AND s1 AND NOT s0;
		int3 <= in3 AND s1 AND s0;
		WAIT ON in0, in1, in2, in3, s0, s1, int0, int1, int2, int3;
	END PROCESS;
END teste_wait;
```

**Exemplo de Uso de WAIT FOR**:


```vhdl
ENTITY teste IS
    PORT( in0  : IN  BIT; 
          out0 : OUT BIT);
END ENTITY;

ARCHITECTURE teste_wait_for OF teste IS
    SIGNAL ck : BIT;
BEGIN

	 out0 <= ck and in0;

    abc: PROCESS
    BEGIN
			ck <= not ck;
			wait for 10 ns;
    END PROCESS;

END ARCHITECTURE;
```

![WaitFor](img/v04-wait_for.png)



**4.2. Comando NULL**

O comando **NULL** não realiza nenhuma operação; ele simplesmente passa o fluxo de execução para o próximo comando. Sua utilidade primária é satisfazer as regras sintáticas que exigem a cobertura de todas as condições possíveis, como na cláusula `WHEN OTHERS` em um `CASE WHEN`, quando nenhuma ação lógica é necessária para os valores restantes.

A ausência de atribuição de valor a um sinal em uma condição resulta na inferência de um elemento de memória (_latch_), que mantém o valor anterior. O `NULL` pode ser usado explicitamente para indicar que, em certas condições, não há ação a ser tomada (o que pode levar à inferência de um _latch_ se o sinal não for atribuído em todos os caminhos possíveis).

**Exemplo de Uso de NULL com CASE WHEN**:

```vhdl
ENTITY sel_op IS
	PORT(   x   : IN  BIT_VECTOR(2 DOWNTO 0);
			sel : IN  BIT_VECTOR(1 DOWNTO 0);
			y   : OUT BIT  );
END ENTITY;

ARCHITECTURE teste_null_case_when OF sel_op IS
BEGIN
	abc: PROCESS (x, sel)
	BEGIN
		CASE sel IS
			WHEN "00" => y <= x(0) AND x(1);
			WHEN "10" => y <= x(2) XOR x(0);
			WHEN OTHERS => NULL;
		END CASE;
	END PROCESS abc;
END teste_null_case_when;

ARCHITECTURE teste_null_if_else OF sel_op IS
BEGIN
	abc: PROCESS (x, sel)
	BEGIN
		IF sel = "00" THEN 
			y <= x(0) AND x(1);
		ELSIF sel = "01" THEN
			y <= x(2) XOR x(0);
		ELSE 
			NULL;
		END IF;
	END PROCESS abc;
END teste_null_if_else;
```

Neste exemplo, se `sel` for `"01"` ou `"11"`, o `NULL` é executado, e o valor do sinal `s` é mantido, implicando a necessidade de um _latch_ pelo sintetizador.

---

**Comparação de Estruturas Condicionais**

É vital distinguir o uso das construções concorrentes (`WHEN ELSE`, `WITH SELECT`) daquelas sequenciais (`IF ELSE`, `CASE WHEN`):

| Construção    | Natureza    | Prioridade                | Cobertura Total Necessária?      |
| :------------ | :---------- | :------------------------ | :------------------------------- |
| `WHEN ELSE`   | Concorrente | Sim (pela ordem)          | Não (gera _latch_ se incompleta) |
| `IF ELSE`     | Sequencial  | Sim (pela ordem)          | Não (gera _latch_ se incompleta) |
| `WITH SELECT` | Concorrente | Não (mútua exclusividade) | Sim (gera _latch_ se incompleta) |
| `CASE WHEN`   | Sequencial  | Não (mútua exclusividade) | Sim (gera _latch_ se incompleta) |

Para a síntese de circuitos combinacionais, quando todas as condições são cobertas e a prioridade é irrelevante, `CASE WHEN` ou `WITH SELECT` são geralmente preferidos, pois representam uma lógica de decodificação mais direta e evitam a complexidade desnecessária inerente à prioridade das estruturas `IF ELSE`. Além disso, o uso de `CASE WHEN` ajuda o projetista a evitar a criação acidental de elementos de memória (_latches_), um erro comum quando nem todas as condições são cobertas em estruturas `IF ELSE`..



---

**Referências**

1. D'AMORE, Roberto. **VHDL**: descrição e síntese de circuitos digitais. 2. ed. Rio
de Janeiro: LTC, 2012.

