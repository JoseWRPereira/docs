---
title: 02 - Interfaces
icon: fontawesome/solid/arrow-down-up-across-line
author: José W. R. Pereira
tags:
    - CLP
    - Controlador programável
    - PLC
---

# Interfaces de Entrada e Saída

As **interfaces de entrada e saída (E/S)** de um CLP, representam o local onde os **dispositivos de campo** são conectados, servindo como o vínculo físico e de comunicação entre esses dispositivos e a Unidade Central de Processamento (CPU). A função primordial dessas interfaces é **condicionar os vários sinais** recebidos ou enviados aos dispositivos externos, garantindo que a comunicação entre o mundo físico e o processador ocorra de forma eficiente.

As funções podem ser detalhadas da seguinte maneira:

*   **Interface de Entrada:** Recebe sinais dos dispositivos de processo (como sensores e botões) e os converte em sinais digitais que podem ser utilizados pelo processador.

![Entradas](img/t02-entradas.png)

*   **Interface de Saída:** Recebe os dados digitais resultantes da lógica do programa e os converte em sinais elétricos externos para acionar atuadores (como motores, válvulas e sinaleiros).

![Saidas](img/t02-saidas.png)

---

# Configurações Físicas

Existem dois modos principais de incorporar essas interfaces ao CLP:

1.  **E/S Fixa:** Comum em CLPs de pequeno porte, onde o processador e os terminais de entrada e saída são incorporados em uma única unidade não removível. Embora tenha menor custo, sua flexibilidade é limitada, pois o número de conexões é fixado pelo fabricante.

2.  **E/S Modular:** Utiliza um **rack ou chassi** com compartimentos (slots) onde os módulos de E/S podem ser plugados individualmente. Isso oferece grande flexibilidade, permitindo misturar diferentes tipos de módulos conforme a necessidade da aplicação.

![EsquemaEletrico](img/t02-esquema.png)

---

# Tipos de Sinais e Processamento

As interfaces são divididas conforme a natureza do sinal que processam:

*   **Interfaces Discretas (Digitais):** Lidam com dispositivos de natureza **LIGA/DESLIGA**, onde cada bit na memória representa um estado completo (como uma chave aberta ou fechada).

*   **Interfaces Analógicas:** Monitoram grandezas físicas que variam continuamente, como temperatura e pressão. Elas utilizam um **conversor analógico-digital (A/D)** para traduzir o sinal do campo para o processador e um **conversor digital-analógico (D/A)** para enviar comandos proporcionais aos atuadores.

---

# Proteção e Segurança

Para garantir a integridade do sistema, os CLPs utilizam **isoladores ópticos** nas interfaces de E/S. Esses componentes usam a luz para acoplar os circuitos, isolando eletricamente os terminais de campo dos circuitos lógicos internos do processador, o que previne danos causados por transientes de tensão e ruídos elétricos do ambiente industrial.

---

# Endereçamento

Além disso, as interfaces utilizam um **sistema de endereçamento**, que funciona como um número residencial, indicando exatamente onde cada informação está localizada na memória para que o processador saiba qual dispositivo deve monitorar ou controlar. Em sistemas modernos, como o ControlLogix, esse endereçamento evoluiu para o uso de **etiquetas (tags)**, nomes descritivos que facilitam a identificação dos dados.




| Tipo | E/S | Etiqueta (TAG) | Contato | Endereço | Descrição | 
|:---:|:---:|:---:|:---:|:---:|:---:|
| Entrada Digital | X0 | Stop  | NO | IX0.0 | Parar o processo |
| Entrada Digital | X1 | Start | NO | IX0.1 | Iniciar o processo |
| Entrada Digital | X2 | Clean | NO | IX0.2 | Zerar contadores |
| Entrada Digital | X3 | Reset | NO | IX0.3 | Reiniciar o processo |
| Entrada Digital | X4 | FS1   | NO | IX0.4 | Acionamento por pedal 1 |
| Entrada Digital | X5 | FS2   | NC | IX0.5 | Acionamento por pedal 2 |
| Entrada Digital | X6 | TC1   | NO | IX0.6 | Contato auxiliar de temporização |
| Entrada Digital | X7 | P/S1  | NO | IX0.7 | Sensor |
| Saída Digital   | Y0 | K1 | - | QX0.0 | Comum |
| Saída Digital   | Y1 | K2 | - | QX0.1 | Estrela |
| Saída Digital   | Y2 | K3 | - | QX0.2 | Triangulo |
| Saída Digital   | Y3 | K4 | - | QX0.3 | Direta |
| Saída Digital   | Y4 | K5 | - | QX0.4 | Sinalização |
| Saída Digital   | Y5 | K6 | - | QX0.5 | Auxiliar |


---

**Material Complementar**

---

1. [Programable Logic Controller Basics Explained - The Engineering Mindset](https://youtu.be/uOtdWHMKhnw?si=1IrKs67Iis5yiBli)
2. [PLC Basics - Programmable Logic Controller - RealPairs](https://youtu.be/PbAGl_mv5XI?si=aiqbq88qaY9JAKWf)
3. [PLC Hardware Components - Automatedo](https://youtu.be/wlCG8d2iQ5c?si=tq6QTypNT3LbYfkn)

---
