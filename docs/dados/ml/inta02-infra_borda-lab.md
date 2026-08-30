---
title: Lab02 - Infraestrutura de borda
icon: fontawesome/solid/border-top-left
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---

SLTINTA - [Ementa](../../ifsp-slt/dados/sltinta_ementa.md) - [Plano de Aula](../../ifsp-slt/dados/sltinta_plano_aula.md) - [Slide da aula](../../dados/slides/SLTINTA-01-intro_conceitos_iniciais.pdf)

---



#

## 🎯 Objetivo

*   **Aprender sobre Infraestrutura de Borda**, abordando a programação do microcontroladores para a aquisição de sinais analógicos/digitais e a estruturação de dados industriais.

## 🔴 Situação-Problema Contextualizada

A equipe de manutenção da siderúrgica instalou microcontroladores nas máquinas CNC. Contudo, os sensores físicos originais operam enviando sinais elétricos brutos (tensões de 0 a 3.3V) que o servidor de IA não consegue interpretar diretamente. O desafio é programar o controlador para ler esses sinais analógicos, converter os sinais de volta para as unidades físicas reais (como graus Celsius ou mm/s de vibração) e organizar essas variáveis em uma string padronizada.

## 🏁 Descritivo de Metas da Atividade Prática

*   **Meta 1:** Configurar o controlador para realizar leitura e conversão das variáveis dos sensores para suas reapectivas grandezas físicas.
*   **Meta 2:** Implementar um algoritmo de simulação matemática (usando geradores de ruído e aleatoriedade) no controlador que replique o comportamento dinâmico do dataset analisado na Semana 1.
*   **Meta 3:** Serializar as variáveis de leitura em um objeto CSV ou JSON estruturado contendo as chaves `temperatura`, `vibracao` e `rpm`, exibindo o resultado formatado no Monitor Serial a cada 2 segundos.

## 🛠️ Ferramentas

*   **Hardware:** Placa de desenvolvimento com PIC, AVR, 8051, ARM, RISC-V (Arduino, ESP32, STM32, Raspberry Pi, etc).
*   **IDE:** Arduino IDE, VS Code, PlatformIO, etc.
*   **Bibliotecas C++:** *ArduinoJson.h* (de Benoit Blanchon), etc.

## 🧠 Conhecimento Teórico

*   **Arquitetura de Dispositivos de Borda:** Compreender o processamento interno de um microcontrolador SoC (System on Chip).
*   **Conversão Analógico-Digital (ADC):** Entender a resolução de bits do ADC do controlador e aplicar equações de mapeamento linear (\\(f(x) = ax + b\\)) para calibrar sensores.
*   **Serialização de Dados:** Vantagens de usar o formato estruturado JSON em comparação com strings de texto puro em sistemas distribuídos.

## 💻 Atividade Prática

1. Instalar o suporte às placas de desenvolvimento no gerenciador de placas da IDE, se for o caso.
2. Escrever o código base para a inicialização das portas de leitura e da comunicação Serial a 115200 bps.
3. Criar variáveis dinâmicas em C++ para simular o comportamento estável da máquina siderúrgica.
4. Instalar a biblioteca de serialização de dados. <!--*ArduinoJson* e instanciar o objeto `StaticJsonDocument`.-->
5. Codificar a rotina para converter os dados numéricos para JSON e imprimir o buffer na porta serial de forma cíclica usando uma função não bloqueante (evitando o travamento do processador que o `delay()` causa).

## 🔗 Indicação de Artigo Científico

*   [Non-Intrusive Low-Cost IoT-Based Hardware System for Sustainable Predictive Maintenance of Industrial Pump Systems ](https://www.mdpi.com/2079-9292/14/14/2913)






