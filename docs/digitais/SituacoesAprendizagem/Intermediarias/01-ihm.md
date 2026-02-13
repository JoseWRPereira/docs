---
title: 01 - Interface Homem-Máquina
icon: fontawesome/solid/robot
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

# Interface Homem-Máquina

Uma **IHM (Interface Homem-Máquina)**, também referida pelos termos em inglês **HCI** (*Human-Computer Interface*) ou **MMI** (*Man-Machine Interface*), define a maneira como um sistema computacional interage com os seres humanos. Em sistemas embarcados, a IHM é o componente que permite ao usuário monitorar o estado do dispositivo, fornecer comandos ou realizar a parametrização de seu comportamento.

Os principais conceitos e características de uma IHM no contexto de sistemas embarcados incluem:

*   **Interfaces Dedicadas:** Diferente dos computadores de uso geral, que utilizam teclados, mouses e grandes monitores, a maioria dos sistemas embarcados possui uma **interface de usuário dedicada** e simplificada. Isso pode incluir botões (*push buttons*), LEDs, volantes, pedais e chaves tácteis.
*   **Componentes de Hardware:** As IHMs podem variar conforme a complexidade da aplicação:
    *   **Simples:** LEDs para sinalização visual e botões para entradas binárias.
    *   **Alfanuméricas e Numéricas:** Displays de sete segmentos e módulos LCD (16x2, 20x4) para exibição de mensagens de texto e números.
    *   **Avançadas:** Displays gráficos (GLCD), telas sensíveis ao toque (*touch screens*), teclados matriciais e até interfaces de voz.
*   **Computação Ubíqua:** Muitas vezes, a IHM é projetada para ser tão integrada ao produto físico que o usuário mal percebe que há processamento de informações envolvido, um conceito conhecido como **"computador que desaparece"**.
*   **Camada de Software:** A interação é gerenciada por códigos específicos:
    *   **Drivers de Dispositivo:** Funções de baixo nível que controlam diretamente o hardware da interface.
    *   **GUI (Interface Gráfica de Usuário):** Em sistemas mais robustos que utilizam Sistemas Operacionais de Tempo Real (RTOS), pode haver suporte para elementos gráficos mais complexos, facilitando a usabilidade.

Em resumo, a IHM é o elo de comunicação entre o **firmware** (a lógica interna do sistema) e o operador humano, sendo essencial para que o sistema embarcado cumpra seu objetivo prático de forma eficiente e segura.

---

# Desafio

Elabore um programa que execute o comportamento conforme ilustração da [simulação](../../sim/simulide/ihm.sim1) que segue.

![atmega328](img/ihm-desafio.gif)
