---
title: 07 - Temporizadores
icon: fontawesome/solid/hourglass-half
author: José W. R. Pereira
tags:
    - CLP
    - Controlador programável
    - PLC
---

#

# Temporizadores 

Os **temporizadores** são, depois dos contatos e bobinas, as instruções de CLP mais utilizadas em sistemas de automação industrial. Eles exercem a mesma função que os relés de tempo eletrônicos e mecânicos convencionais, porém de forma lógica como funções definidas internamente e controladas pela programação do usuário. 

Eles oferecem vantagens significativas sobre os modelos mecânicos, como:

*   Facilidade para alterar os ajustes de tempo via software.
*   Maior precisão e repetibilidade, pois os atrasos são gerados pelo relógio interno do processador.
*   Flexibilidade para aumentar ou diminuir a quantidade de temporizadores sem a necessidade de novas fiações físicas.

O funcionamento básico de um temporizador consiste em **contar intervalos de uma base de tempo**  até atingir um valor desejado.

## Elementos Principais
Para operar, um temporizador utiliza três parâmetros fundamentais:

*   **Valor Pré-ajustado (Preset - PRE ou PT):** É o tempo total de retardo desejado (ex: 10 segundos).
*   **Valor Acumulado (ACC ou ET):** Representa o tempo que já decorreu desde que a instrução foi ativada.
*   **Base de Tempo:** É a unidade de incremento do contador (ex: 1s, 0,1s ou 0,01s). Se a base for 0,1s e o pré-ajuste for 50, o retardo será de 5 segundos (50 × 0,1s).

## Bits de Interface
O temporizador interage com o programa através de bits:

*   **IN (Entrada):** Habilita a contagem de tempo.
*   **Q (Entrada):** Indica o fim da contagem de tempo estabelecida.
*   **EN (Habilitação):** Verdadeiro enquanto o temporizador estiver energizado.
*   **TT (Cronometragem):** Verdadeiro enquanto o tempo acumulado estiver mudando (contando).
*   **DN (Finalização/Done):** Muda de estado quando o valor acumulado atinge o valor pré-ajustado.
*   **IN (Entrada):** Habilita a contagem de tempo.

Note que cada modelo de CLP pode usar uma nomenclatura diferente ou mesmo possuir ou não algum desses bits de interface. 

## Tipos de Temporizadores
Existem três tipos principais utilizados na indústria:

*   **TON (Retardo ao Ligar):** Inicia a contagem quando o degrau da lógica torna-se verdadeiro. A saída (Q) é ativada somente após o término do tempo.
*   **TOF (Retardo ao Desligar):** A saída liga imediatamente quando a entrada é ativada, mas só desliga após um período determinado depois que a entrada foi desativada.
*   **TP (Temporiza ao Pulsar):** Funciona como o TON, mas **retém a temporização** mesmo se a entrada for desligada.

## Aplicação
Os temporizadores servem para gerenciar qualquer processo que dependa do decurso do tempo para garantir eficiência ou segurança. Algumas aplicações típicas incluem:

*   **Sinalização e Segurança:** Acionar uma sirene de aviso por 10 segundos antes de uma esteira transportadora começar a se mover.
*   **Partida Sequencial:** Ligar motores de alta potência em sequência, com intervalos entre eles, para evitar picos de corrente na rede elétrica.
*   **Controle de Tráfego:** Gerenciar os tempos de abertura e fechamento de semáforos em cruzamentos.
*   **Processos Químicos e Alimentares:** Controlar períodos de aquecimento ou agitação em tanques de mistura.
*   **Manutenção Preventiva:** Utilizar temporizadores retentivos para registrar o tempo total de funcionamento de uma máquina e alertar quando um filtro ou óleo precisar ser substituído.

---

# Equipamentos 

## [Altus TB131 - Temporizadores](../altus_tb131/lab05-temporizadores.md)


---

# Referências

1. GEORGINI, Marcelo. **Automação aplicada**: descrição e implementação de sistemas sequenciais com PLCs. 9. ed. São Paulo: Érica, 2007.
2. PETRUZELLA, Frank D. **Controladores lógicos programáveis**. Tradução: Romeu Abdo. Revisão técnica: Antonio Pertence Júnior. 4. ed. Porto Alegre: AMGH, 2014.
3. SILVA FILHO, Bernardo Severo da (Orient.). **Curso de controladores lógicos programáveis**. Rio de Janeiro: Faculdade de Engenharia da UERJ, Laboratório de Engenharia Elétrica, [s.d.].
4. ALTUS SISTEMAS DE AUTOMAÇÃO. **O que é CLP e quando utilizá-lo?** São Leopoldo: Altus, 2025.

---