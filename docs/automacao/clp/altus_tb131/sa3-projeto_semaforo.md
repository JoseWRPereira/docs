---
title: Semaforo
icon: fontawesome/solid/traffic-light
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Semaforo
---

# Semáforo

---

**1. Objetivo**

Desenvolver uma aplicação, programa de PLC, 
para um dispositivo de controle de tráfego (semáforo), 
a ser instalado em um cruzamento de pedestre.


|Figura 1a: Exemplo de cruzamento de pedestres | Figura 1b: Semáforo para veículos|
|:-------------------------------------------:|:--------------------------------:|
| ![semaforo_pedestre](img/sa3-semaforo_freepik.png)|![semaforo](gif/sa3-semaforo.gif)|
| Fonte: [freepik](https://br.freepik.com/vetores-premium/pedestre-atravessar-a-rua-com-pessoas-da-equipe-e-semaforo-e-cidade_5589436.htm)  | |


---

**2. Requisitos**

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

---

**3. Planejamento**

Definir como será feita a entrega: 
simulador, montagem de protótipo, montagem de circuito em painel ou PCI, etc, 
assim como listar os materiais e ferramentas em função do tipo de entrega. 
Por fim o planejamento do processo, em que deve ficar explicito como, 
utilizando os materiais listados e manipulando da ferramentas, 
chega-se ao produto final, com um encadeamento lógico das tarefas que compoem o processo.


**4. Solução**

---

Bom trabalho!
