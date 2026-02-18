---
title: 4. Simuladores
icon: fontawesome/solid/photo-film
author: José W. R. Pereira
tags: 
    - Tinkercad
    - Simulador
    - Arduino

---

# Simuladores

Os **simuladores para sistemas embarcados** são aplicativos de software executados em um computador host (geralmente um PC comum) que modelam e imitam o comportamento do processador e do sistema de hardware alvo. Eles permitem a **execução de modelos de design** para fins de validação e avaliação funcional, sem a necessidade imediata do hardware físico.

Abaixo, detalho as características dessas ferramentas:

**Aplicações**

*   **Validação de Design:** Verificação do comportamento funcional (entrada/saída) e de propriedades não-funcionais, como comportamento térmico e compatibilidade eletromagnética (EMC).
*   **Desenvolvimento Precoce:** Permite que programadores experimentem o software nos estágios iniciais de um projeto, mesmo antes do hardware real existir.
*   **Simulação de Algoritmos:** Teste de algoritmos complexos (como codificação de vídeo MPEG) para avaliar a qualidade dos resultados antes da implementação em hardware.
*   **Educação:** Ferramenta útil para o aprendizado de novas linguagens de programação e arquiteturas de microcontroladores.
*   **Simulação de Falhas (*Fault Simulation*):** Modificação de modelos para prever como o sistema reagirá na presença de erros específicos.

**Vantagens**

*   **Baixo Custo e Velocidade:** É mais barato e rápido implementar um produto inicial em um simulador do que construir um protótipo físico.
*   **Controle e Observabilidade:** Oferecem visibilidade total do estado interno (registradores e memória) e controle sobre a repetibilidade de eventos, o que é difícil em hardware real.
*   **Segurança:** Permite testar sistemas críticos, como controles automotivos ou de usinas, sem os perigos físicos de um sistema real instável.
*   **Depuração Facilitada:** Permite isolar se um comportamento estranho é erro de hardware ou interpretação errada da documentação do processador.

**Desvantagens**

*   **Velocidade Reduzida:** Simulações são tipicamente muito mais lentas do que o tempo de execução real, o que pode causar violações de restrições temporais se interfaceadas com o ambiente real.
*   **Falta de Precisão em Tempo Real:** Muitos simuladores não conseguem duplicar efetivamente as interações complexas de tempo real entre hardware e software.
*   **Escopo Limitado:** Frequentemente focam apenas no processador, ignorando periféricos externos complexos; criar modelos para esses periféricos pode ser mais trabalhoso do que o valor da simulação.
*   **Incompletude:** Não podem garantir a ausência de erros, pois é impossível simular todas as combinações de entradas e estados internos.

**Simuladores Comuns no Mercado**

*   **Proteus (ISIS):** Amplamente utilizado na academia e indústria para simular microcontroladores (como a família AVR) e circuitos eletrônicos completos.
*   **MATLAB/Simulink:** Popular para engenharia de controle e design baseado em modelos, permitindo simular sistemas dinâmicos e traduzi-los para código C ou VHDL.
*   **AVR Simulator:** Integrado ao ambiente profissional **AVR Studio**, permitindo depurar o código vendo o estado dos registradores bit a bit.
*   **PSpice/SPICE:** Padrão industrial para simulação de circuitos ao nível elétrico para análise de ruído, distorção e transientes.
*   **Qemu:** Ferramenta de código aberto utilizada para emular diversos sistemas, incluindo arquiteturas ARM.
*   **Soluções Acadêmicas e Profissionais:** **gem5**, **SimpleScalar** e **OpenModelica** (acadêmicos); **Synopsys Virtualizer** (comercial).

---



## 1. Tinkercad

O [Tinkercad](https://www.tinkercad.com/) é uma ferramenta online gratuita da Autodesk voltada para niciantes. Ele permite a modelagem 3D, mas é amplamente conhecido na eletrônica por seu simulador de circuitos, onde é possível montar projetos com Arduino, LEDs, botões e sensores de forma virtual e programá-los em blocos ou em código C/C++, antes da implmentação em *hardware* real.


![Tinkercad](img/sim-tinkercad-autodesk.png)

![Tinkercad](img/sim-tinkercad-login.png)

![Tinkercad](img/sim-tinkercad-principal.png)

![Tinkercad](img/sim-tinkercad-testeCI.png)

![Tinkercad](img/sim-tinkercad-blink.png)

![Tinkercad](img/sim-tinkercad-blink_code.png)

---

## 2. SimulIDE

O [SimulIDE](https://simulide.com/p/) é um simulador de circuitos eletrônicos de tempo real, de código aberto e multiplataforma. Ele é focado principalmente na simulação de microcontroladores (como AVR, Arduino e PIC) e componentes periféricos. É uma alternativa leve a softwares profissionais, permitindo testar o código e o hardware virtualmente antes da montagem física.


![Simulide](img/sim-simulide-site.png)

![Simulide](img/sim-simulide-principal.png)

![Simulide](img/sim-simulide-testeCI.png)

![Simulide](img/sim-simulide-blink.png)

![Simulide](img/sim-simulide-load_firmware.gif)


---

# Referências

1. ANDERSON, Rick; CERVO, Dan. **Pro Arduino**: Arduino Expert Topics and Techniques. New York: Apress, 2013.

2. BARR, Michael. **Programming Embedded Systems in C and C++**. 1. ed. [S. l.]: O'Reilly, 1999.

3. LANGBRIDGE, James A. **Professional Embedded ARM Development**. Indianapolis: John Wiley & Sons, 2014.

4. LIMA, Charles Borges de; VILLAÇA, Marco Valério Miorim. **AVR e Arduino**: Técnicas de Projeto. 2. ed. Florianópolis: Edição dos Autores, 2012.

5. MARWEDEL, Peter. **Embedded System Design**: Embedded Systems Foundations of Cyber-Physical Systems, and the Internet of Things. 4. ed. Dortmund: Springer Nature, 2021.

6. NOERGAARD, Tammy. **Embedded Systems Architecture**: A Comprehensive Guide for Engineers and Programmers. Oxford: Elsevier, 2005.

7. RUSSELL, David J. **Introduction to Embedded Systems**: Using ANSI C and the Arduino Development Environment. [S. l.]: Morgan & Claypool, 2010.

8. VALVANO, Jonathan W. **Embedded Systems**: Introduction to ARM® Cortex™-M Microcontrollers. 5. ed. Austin: [s. n.], 2014. v. 1.

9. Tinkercad url: https://www.tinkercad.com/

10. SimulIDE url: https://simulide.com/p/



---
