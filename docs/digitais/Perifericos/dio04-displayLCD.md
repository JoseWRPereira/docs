---
title: 04 - Display de Cristal Líquido
icon: fontawesome/solid/tv
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - MMR
 - MCU
 - AVR
 - ATMega328P
---

# 

![atmega328](img/dispLCD-capa.png)

---

# 1. Display de Cristal Líquido

Um **display de cristal líquido (LCD - *Liquid Crystal Display*)** é uma interface de saída amplamente utilizada em sistemas embarcados para fornecer informações visuais ao usuário de forma conveniente e econômica, permitindo padrões de exibição flexíveis com **baixo consumo de energia**.

## 1.1 Tipos de Displays
Os módulos LCD podem ser classificados em dois tipos principais:

*   **Alfanuméricos (ou de caractere):** Destinados à exibição de letras, números e símbolos pré-definidos. São especificados pelo número de colunas e linhas, sendo os modelos **16 × 2** (16 caracteres por 2 linhas) e **20 × 4** os mais populares.
*   **Gráficos (GLCD):** Compostos por uma matriz de pontos (pixels), como o modelo de **128 × 64**, que permitem a criação de figuras, ícones e fontes customizadas.

## 1.2 Hardware e Conexão
A maioria dos displays alfanuméricos utiliza o controlador **[Hitachi HD44780](https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf)**, que se tornou um padrão de mercado. Para utilizá-lo, é necessário conectar os seguintes pinos:

*   **Alimentação e Contraste:** VSS (GND), VDD (VCC) e **VEE**, que deve ser ligado a um **trimpot** de 10kΩ para ajustar a visibilidade dos caracteres.
*   **Controle:** **RS** (*Register Select* - define se o dado é instrução ou caractere), **R/W** (*Read/Write* - geralmente aterrado para modo de escrita) e **E** (*Enable* - habilita a leitura dos dados pelo LCD).
*   **Barramento de Dados:** Composto pelos pinos DB0 a DB7.

## 1.3 Modos de Operação e Interface
Existem duas formas principais de interface paralela para displays alfanuméricos:

1.  **Interface de 8 bits:** Utiliza todos os pinos de dados (DB0-DB7).
2.  **Interface de 4 bits:** Envia o byte de dado em duas partes (*nibbles*) utilizando apenas os pinos DB4 a DB7. Esta forma é a **mais recomendada**, pois libera 4 pinos de E/S do microcontrolador para outras tarefas.

## 1.4 Lógica de Utilização e Programação
Para que o LCD funcione corretamente, o firmware deve seguir uma sequência lógica rigorosa:

*   **Inicialização:** Após ligar a alimentação, deve-se aguardar um tempo de estabilização (aprox. 15ms) e enviar uma sequência específica de comandos para configurar o modo de bits (4 ou 8), o número de linhas e o estado do cursor.
*   **Escrita de Dados:** Para exibir um caractere, coloca-se o pino **RS em nível alto (1)**, carrega-se o valor ASCII no barramento e gera-se um **pulso no pino Enable** (levar a 1 e depois a 0).
*   **Comandos:** Para limpar a tela ou mover o cursor, o processo é o mesmo, mas com o pino **RS em nível baixo (0)**.
*   **Arduino:** A plataforma facilita o uso através da biblioteca **`LiquidCrystal.h`**, que abstrai a complexidade do protocolo Hitachi, permitindo comandos simples como `lcd.begin(colunas, linhas)` e `lcd.print("texto")`.


| Figura 1: [Simulação](simulide/LCD_HD44780.sim1) de acionamento manual e inserção de caracteres |
|:-----------------------------------------------------:|
| ![AcionamentoManual](img/dispLCD-manual.gif)            |
| Fonte: Autor (SimulIDE-1.1.0-SR1)                     |

Além dos caracteres padrão, esses dispositivos possuem uma memória chamada **CGRAM**, onde o programador pode criar até **oito caracteres especiais** personalizados em uma matriz de 5 × 8 pixels.

| Figura 2: Mapa de caracteres                          |
|:-----------------------------------------------------:|
| ![MapaDeCaracteres](img/dispLCD-mapa_caracteres.png)    |
| Fonte: [Sparkfun - Hitachi](https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf) |
