---
title: Outras Contagens
icon: fontawesome/brands/schlix
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
---

#

# Outras Contagens

---


## 1 Contagem de Peças em Esteira:

1.1 O exercício mais básico consiste em usar um sensor de proximidade para contar itens que passam por um ponto específico de uma esteira.

1.2 Conte itens/peças metálicas e não metálicas que atravessam um ponto específico da esteira e separe-as nos pontos de saída, rampas. 


1.3 Conte os itens(peças) por altura (pequnas, médias e grandes) que entram em uma esteira e separe-as em ordem nas rampas, sendo a menor na primeira rampa e a maior na última rampa (final da esteira).


## 2 Parada para Manutenção Preventiva:

Programar um contador para monitorar o número de ciclos de uma máquina (motor ligando em partida direta e desligando). Ao atingir 10 operações, o contador impede que o motor ligue novamente até que um botão de "Reset" seja acionado.



## 3 Sistema de Empacotamento:

Criar uma lógica onde o contador C1 conta 6 latas para fechar uma embalagem; um segundo contador (C2) conta quantas embalagens foram completadas no dia, com limite de 300 unidades.


## 4 Controle de Lote para Inspeção:

Projetar um sistema que desvia automaticamente uma peça para a linha de controle de qualidade a cada 1000 itens produzidos, acionando uma solenoide de forma temporizada.

## 5 Montagem de Kits Eletrônicos:

Controlar um carretel de resistores para que ele pare automaticamente após liberar exatamente 100 unidades para o kit.


## 6 Controle de Depósito:

Implementar um sistema para um depósito que inicia com 100 peças. À medida que as peças saem, o contador decrescente monitora o saldo atualizado para fins de reposição. Sinalizar uma quantidade menor do que 20% de peças restantes com um sinal luminoso contínuo e piscante para menos do que 10%. 



## 7 Lotação de Estacionamento:

Utilizar um sensor na entrada e outro na saída com o mesmo endereço de memória. Quando o acumulador chegar a 150, um sinaleiro de "Lotação Esgotada" deve acender.


## 8 Gerenciamento de Área de Armazenamento:

Controlar uma esteira que abastece três áreas com capacidade máxima de X itens. Se alguma área atingir o limite, a esteira de alimentação deve parar automaticamente até que peças sejam retiradas e um botão de reset seja pressionado, reiniciando completamente somente a área que gerou a parada.

## 9 Contador de Altas Quantidades:

Criar um sistema capaz de contar até 250.000 eventos utilizando dois contadores em cascata (o bit de finalização do primeiro incrementa o segundo).

## 10 Temporizador de Longuíssima Duração:

Projetar um sistema que necessite de um retardo de 1.000.000 de segundos, utilizando um temporizador (ex: 10.000s) para enviar pulsos a um contador (ex: 100 contagens).


## 11 Taxa de Fluxo de Produção:

Utilizar um temporizador de 1 minuto para habilitar a contagem de latas e, ao fim do tempo, ler o acumulador do contador para determinar a produção por minuto (latas/min).


## 12 Empilhamento Automático:
Contar 15 chapas metálicas que caem de uma esteira para outra. Após atingir a contagem, a segunda esteira deve ser ativada por 5 segundos para mover a pilha, repetindo o ciclo.

## 13 Monitoramento de Nível de Tanque: 

13.1 Utilizando um sensor de nível para o CLP, considerando a escala lateral com o valor de 5 cm como o mínimo e 15cm como o máximo, mapeie esse sinal para indicar se o tanque está vazio (0 V) ou cheio (10 V) em uma escala de 0 a 100%, e mostre no display.


13.2 Complemente a tarefa anterior, controlando o nível de água no tanque para 10 cm, independente do ângulo de abertura da válvula de saída. 



---

Bom trabalho!
