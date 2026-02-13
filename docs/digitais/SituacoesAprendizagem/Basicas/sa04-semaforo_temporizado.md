---
title: sa04 - Semáforo Temporizado
icon: fontawesome/solid/traffic-light
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - MMR
 - MCU
 - AVR
 - ATMega328P
---


# Semáforo com temporizador


# 1. Objetivo:

Desenvolver uma aplicação, programa, para um ser executado na [simulação](img/lab08-sim-avr-semaforo_temporizado.sim1) de controle de tráfego (semáforo), a ser instalado em um cruzamento de pedestre. 

|Figura 1a: Exemplo de cruzamento de pedestres| Figura 1b: Semáforo para veículos|
|:-------------------------------------------:|:--------------------------------:|
| ![semaforo_pedestre](img/semaforo-freepik.png)|![semaforo](img/semaforo.gif)|
| Fonte: [freepik](https://br.freepik.com/vetores-premium/pedestre-atravessar-a-rua-com-pessoas-da-equipe-e-semaforo-e-cidade_5589436.htm)  | |



# 2. Requisitos da solução

1. Interface
      1. Semáforo de veículos (Vm, Am, Vd);
      2. Semáforo de pedestres (Vd, Vm);
      3. Botão pulsador para pedestres;
      4. Display de temporização decrescente;
2. Comportamento
    * Intervalo de tempo para o Semáforo de Veículos(sv):
        * Verde: 42s
        * Amarelo: 3s
        * Vermelho: 15s
    * Semáforo de Pedestre(sp) sincronizado com o de veículos:
        * Verde (sv) : Vermelho (sp)
        * Amarelo (sv) : Vermelho (sp)
        * Vermelho (sv) : Verde (sp)
        * Piscar Vermelho (sp) 3x antes de mudar em definitivo.
    * Botão pulsador para antecipar liberação de passagem dos pedestres:
        * Se faltar mais do que 10s para o acionamento da cor amarela, reduzir para 10s.
        * Se faltar menos do que 10s para o acionamento da cor amarela, manter o tempo restante.
    * O display de temporização deve exibir a contagem decrescente com o tempo restante para atravessia do pedestre, ou o tempo restante da cor vermelha no semáforo dos veículos. 
        * Em qualquer outra situação, o display não deve mostrar contagem, apenas uma indicação de que está funcionando, não podendo ficar totalmente apagado. 
3. Estrutra (*Hardware*): Circuito eletrônico
    * Potência por sinaleiro: 7W
    * Tensão de operação: 24V
    * Displays de 7 segmentos Anodo ou Catodo comum

---

# 3. Planejamento da solução

1. Planejamento do produto final
2. Planejamento das ferramentas e materiais
3. Planejamento do processo

---

# 4. Solução

![SemaforoTemporizado](img/semaforo_temporizado.gif)

Bom trabalho!
