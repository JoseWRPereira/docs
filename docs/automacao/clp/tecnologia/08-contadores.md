---
title: 08 - Contadores
icon: fontawesome/solid/arrow-up-9-1
author: José W. R. Pereira
tags:
    - CLP
    - Controlador programável
    - PLC
---

#

# Contadores

Em sistemas de automação e Controladores Lógicos Programáveis (CLPs), **contadores são instruções de software que emulam o funcionamento de contadores mecânicos ou eletrônicos**, sendo utilizados para contar eventos externos ou transições internas no programa. Diferente dos temporizadores, que dependem de pulsos de um relógio interno, os contadores dependem de pulsos externos ou de condições do programa para realizar a contagem.

Principais características e tipos de contadores:

## Funcionamento Básico

*   **Transição de Sinal:** Os contadores operam na **borda de subida** do sinal de entrada, ou seja, eles incrementam ou decrementam o valor acumulado apenas quando o sinal de entrada transita do estado desligado (0) para o estado ligado (1).
*   **Retentividade:** Geralmente, os contadores são **retentivos**, o que significa que eles mantêm o valor acumulado na memória mesmo havendo queda de energia, retomando a contagem de onde pararam quando o sistema é religado.
*   **Reinicialização (Reset):** É necessária uma instrução de reset (RES) com o mesmo endereço do contador, ou na entrada de reset do bloco contador, para zerar o valor acumulado.

## Elementos de um Contador

Um contador no CLP é composto por sinais de interface cruciais para o seu uso:

1.  **Entrada de contagem (CU/CD):** Entrada booleana para o sinal de execução do evento incremento ou decremento da contagem.
2.  **Entrada de Reset (RESET):** Entrada booleana que executa a reinicialização do contador.
3.  **Valor pré-ajustado (PRE/PV):** É o valor alvo (set-point) que o contador deve atingir para sinalizar que a tarefa foi concluída.
4.  **Valor Acumulado (ACC) ou Valor de Contagem (CV):** Indica o número atual de transições (contagens) que ocorreram até o momento.
5.  **Saída de fim de contagem (Q):** Indica que o valor de contagem alcançou ou superou o valor pré-ajustado. 

## Tipos de Contadores

*   **Contador Crescente (CTU):** Incrementa o valor acumulado em 1 a cada pulso de entrada até atingir o valor pré-ajustado.
*   **Contador Decrescente (CTD):** Diminui o valor acumulado a cada pulso de entrada, sendo frequentemente usado para contagens regressivas ou em conjunto com contadores crescentes.
*   **Contador Crescente e Decrescente (CTUD):** Combina as duas funções em uma única estrutura, permitindo monitorar, por exemplo, o número de peças em processo à medida que entram e saem de uma máquina.
*   **Módulo Contador de Alta Velocidade (HSC):** São módulos de hardware especiais usados quando a frequência dos pulsos (como os de um encoder) é tão alta (ex: 100 kHz) que ultrapassa a capacidade de processamento da CPU do CLP.

## Exemplos de Aplicação

Os contadores são amplamente aplicados na indústria para tarefas como **contar a quantidade de itens que passam por um sensor em uma esteira**, monitorar o número de operações (ciclos) de um motor para manutenção, controlar o acesso de veículos em estacionamentos ou medir comprimentos de materiais em movimento.

---

## Equipamentos 

- ### [Altus TB131 - Contadores](../altus_tb131/lab06-contadores.md)


---

# Referências

1. PETRUZELLA, Frank D. Controladores lógicos programáveis. Tradução de Romeu Abdo; revisão técnica de Antonio Pertence Júnior. 4. ed. Porto Alegre: AMGH, 2014.

2. GEORGINI, Marcelo. Automação Aplicada: Descrição e Implementação de Sistemas Sequenciais com PLCs. 9. ed. São Paulo: Érica, 2007.

3. FACULDADE DE ENGENHARIA DA UERJ. Curso de Controladores Lógicos Programáveis. Rio de Janeiro: Laboratório de Engenharia Elétrica, [s.d.].

4. ALTUS SISTEMAS DE AUTOMAÇÃO. O que é CLP e quando utilizá-lo?. São Leopoldo: Altus, 2025.

---