---
title: Portão de Garagem
icon: fontawesome/solid/archway
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Semaforo
---

# Portão de Garagem

---

# 1. Objetivo

Desenvolver uma aplicação, programa de PLC, para um 
 **porta de garagem basculante motorizada**. O sistema utiliza um contator para subir a porta e outro para descê-la, com sensores de fim de curso para detectar quando a porta está totalmente aberta ou fechada e botões para acionamento.


|Figura 1: Exemplo de cruzamento de pedestres    |
|:-----------------------------------------------:|
| ![semaforo_pedestre](img/portao-sobe-desce.png) |
| Fonte: Gemini |

Para atender o objetivo solicitado, deve ser implementada uma **partida direta com reversão**, que é um sistema de acionamento de motores que combina a função básica de uma chave de partida direta com a capacidade de **inverter o sentido de rotação** do motor.

Uma chave de partida direta convencional é composta essencialmente por um **contator acoplado a um relé de sobrecarga**.

Na versão com reversão, são utilizados **dois contatores** (um para cada sentido de rotação, como "subir" e "descer" ou "frente" e "ré") e um relé de sobrecarga para proteção contra correntes excessivas.

O sistema utiliza dispositivos de campo como botões de comando (partida, parada e botões específicos para cada sentido) e, em muitos casos, chaves-limite (fim de curso) para interromper o movimento automaticamente ao atingir um ponto específico.

Para que o sentido de rotação de um motor trifásico seja alterado, é necessário **inverter duas das três fases** de alimentação (por exemplo, a fase R se torna T e a fase T se torna R).

Os contatores de reversão são instalados de forma que um deles conecte as fases na ordem normal e o outro as conecte na ordem invertida.


O **Intertravamento (Bloqueio)** é uma regra fundamental na lógica de reversão em que o motor deve **parar completamente antes de inverter o sentido**. Assim, no programa (lógica ladder), é essencial incluir um bloqueio ou **intertravamento elétrico/lógico**, garantindo que o contator de um sentido não possa ser energizado enquanto o outro estiver ativo, o que evitaria um curto-circuito entre as fases. O circuito geralmente conta com um **contato de selo**, que mantém o contator energizado após o operador liberar o botão de partida.

---

## 1.1 - Requisitos da solução

### 1.1.1 Componentes de interface

- S1: Botão Abrir;
- S0: Botão Fechar;
- fc1: Fim de curso de portão aberto;
- fc2: Fim de curso de portão fechado;
- K1: Contator que realiza a abertura do portão;
- K2: Contator que realiza o fechamento do portão.

### 1.1.2 Comportamento

- Condição: Portão fechado
	- fc2 acionado;
	- Se pressionar o "Abrir" o portão deve abrir até atingir o fc1. 

- Condição: Portão aberto
	- fc1 acionado;
	- Se pressionar o "Fechar" o portão deve fechar até atingir o fc2.

- Condição: Portão abrindo
	- Se pressionar o "Fechar" o botão não tem efeito.

- Condição: Portão fechando
	- Se pressionar o "Abrir" o botão não tem efeito.

---

# 2 Planejamentos 

Definir como será feita a entrega: 
simulador, montagem de protótipo, montagem de circuito em painel ou PCI, etc, 
assim como listar os materiais e ferramentas em função do tipo de entrega. 
Por fim o planejamento do processo, em que deve ficar explicito como, 
utilizando os materiais listados e manipulando da ferramentas, 
chega-se ao produto final, com um encadeamento lógico das tarefas que compoem o processo.

## 2.1 Produto final
## 2.2 Ferramentas
## 2.3 Materiais
## 2.4 Processo


---

# 3. Solução

Produto ou processo que atinge o objetivo proposto, através da execução de seu planejamento e satisfação dos seus requisitos.

---

Bom trabalho!

