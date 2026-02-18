---
title: Partida Direta de Motor
icon: fontawesome/solid/radiation
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Partida Estrela-Triângulo
---

# 1. Partida Direta de Motor

A partida direta de um motor é um dos circuitos de acionamento mais comuns na indústria, e ótimo para iniciar o aprendizado conhecendo os elementos dessa tecnolgia, já que sua lógica de acionamento é bem simples. 

A Figura 1 ilustra os diagramas de potência e de comandos, responsáveis pela alimentação trifásica do motor com o seu acionamento utilizando botoeiras.


| Figura 1: Diagrama de Potência e Comando de uma partida direta de motor |
|:------------------------------------------------:|
| ![DiagramaPotCom](img/sa1-diagrama_pot_com.png)  |
| Fonte: [PARTIDA DIRETA DE MOTORES - COMO LIGAR? - Ômega Treinamentos](https://youtu.be/V2DbwDzUdlQ?si=F2xr17v3h1VSgnTC) |


Explicação detalhada sobre o acionamento não faz parte do escopo deste material, sendo assim, seguem indicações:

1. [Sala da Elétrica](https://www.saladaeletrica.com.br/partida-direta-de-motor-trifasico/)
2. [PARTIDA DIRETA DE MOTORES - COMO LIGAR? - Ômega Treinamentos](https://youtu.be/V2DbwDzUdlQ?si=-oEMoCHHalq4K1QM&t=1)



| Vídeo 1: Animação de ligações em um comando de partida direta de motor |
|:-----:|
| <iframe width="560" height="315" src="https://www.youtube.com/embed/_97EQvxI12A?si=R9dSME2s-DAB5Cxm" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe> |
| Fonte: [Comando Elétrico Super Fácil (Partida Direta) - Marcos Instalação Elétrica](https://youtu.be/_97EQvxI12A?si=6ZC8aJwrHlz5k8Ck)|

---

# 2. Desenvolvimento do projeto/atividade/tarefa

A etapa inicial no desenvolvimento de uma atividade, tarefa ou projeto é ter um objetivo bem definido. 

## 2.1 Requisitos da solução (Componentes de interface e Comportamento)

Lista dos componentes de interface com suas características e a descrição do comportamento que se deve atingir na solução.

## 2.2 Planejamento (Produto final, Ferramentas, Materiais e Processo )

Definir como será feita a entrega: simulador, montagem de protótipo, montagem de circuito em painel ou PCI, etc, assim como listar os materiais e ferramentas em função do tipo de entrega. Por fim o planejamento do processo, em que deve ficar explicito como, utilizando os materiais listados e manipulando da ferramentas, chega-se ao produto final, com um encadeamento lógico das tarefas que compoem o processo.

## 2.3 Solução

Produto ou processo que atinge o objetivo proposto, através da execução de seu planejamento e satisfação dos seus requisitos.

---

# 3. Objetivo
Desenvolver uma aplicação, programa, em CLP para realizar uma partida direta de motor trifásico.

---

## 3.1 Requisitos da solução

### 3.1.1 Componentes de interface
  * Botoeira ligar: `S1`;
  * Botoeira desligar: `S0`;
  * Contator de acionamento: `K1`;

### 3.1.2 Comportamento
  - Ao pressionar `S1`:
	- Ligar `K1`;
	
  - Ao pressionar `S0`:
  	- Desligar `K1`.

  - `S0` é mandatório sobre `S1`.


## 3.2 Planejamentos 

### 3.2.1 Produto final

1. Apresentação de funcionamento em kit didático;
2. Arquivo .pdf contendo:
	* declaração de interface física, entradas e saídas com respectivos endereços;
	* programa em linguagem `Ladder`, `ST` ou `SFC(Grafcet)` contendo comportamento para a partida proposta.


### 3.2.2 Ferramentas 

1. Software Master Tool IEC
2. Kit didático: TB131 Altus


### 3.2.3 Materiais

* Não há!


### 3.2.4 Planejamento do processo

- Abrir projeto a partir do modelo: `Modelo_DU350_DU351_v110.pro`;
- Acrescentar objeto POU do tipo Programa em linguagem Ladder ou ST ou SFC;
- Declarar entradas e saídas físicas (Mapa de Entradas e Saídas);
- Programar a lógica de funcionamento;
- Testar e Validar o comportamento.

---

## 3.3 Solução

## 3.3.1 Mapa de Entradas e Saídas

| Função  | Identificador | Descrição                 | Tipo |Endereço |
|:-------:|:-------------:|:-------------------------:|:----:|:-------:|
| Entrada | Ligar         | Ligar motor               | Bool |%IX0.1   |
| Entrada | Desligar      | Desligar motor            | Bool |%IX0.0   |
| Saída   | K1            | Contator que aciona motor | Bool |%QX1.0   |


## 3.3.2 Programa em Linguagem Ladder

![Solucao_prog](img/sa1-solucao_prog.png)

Para imprimir o projeto, basta clicar em `Arquivo` e `Imprimir` e realizar a impressão em arquivo .pdf. 


## 3.3.3 Impressão

![Solucao_imprimir](img/sa1-imprimir.png)

Caso haja necessidade, realize ajustes na folha de impressão. Cada software possui ajustes próprios. 

![Solucao_impressao](img/sa1-impressao.png)

---
