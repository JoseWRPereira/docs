---
title: Novo Projeto
icon: fontawesome/solid/folder-plus
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Novo projeto
---

# Criando um novo projeto

## 1. Criando um novo projeto a partir de um modelo: 

![Novo Projeto](./gif/h1-1_1-novo.gif)


## 2. Verificando arquivo `NAVEGA (PRG)`:


``` Pascal
PROGRAM NAVEGA
VAR
	ControleTelas : NAVIGATION;
	ListaTelas 	: ARRAY [0..30] OF STRING(10);
END_VAR
```

``` Pascal
(* Adiciona a tela MAIN como tela principal *)
ListaTelas[0] := 'MAIN';

(* Ativa o controle automático de navegação somente pelo teclado *)
ControleTelas(ENABLE_UPDW := FALSE, VISU_LIST := ListaTelas, UP := FALSE , DOWN := FALSE);
```


## 3. Acrescentando um objeto do tipo `Programa` em linguagem `Ladder`: 

![Acrescentar Objeto - Diagrama Ladder](./gif/h1-1_3-add_obj-plc_prg.gif)



## 4. Testando comunicação com PLC:

4.1 Conecte o PLC ao computador;

4.2 Abra o gerenciador de dispositivos e verifique qual porta foi alocada para a comunicação com o PLC:

![Gerenciador de dispositivos - Windows](img/h1-1_4_2-gerenciado_dispositivos_com3.jpeg)

4.3 Clique em `Comunicação` -> `Parâmetros de comunicação ...`

![Parâmetros de comunicação](img/h1-1_4_3-com3.png)

	* Para ajustar a porta clique duplo sobre a `COM n` e use as setas para cima e para baixo para ajustar a porta correta, neste caso a `COM3`;
	* Clique em `OK`.


## 5. Testando o processo de gravação:

![Conectando e gravando](gif/h1-1_5-com_login.gif)


