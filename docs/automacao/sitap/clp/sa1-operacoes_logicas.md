---
title: Operações lógicas
icon: fontawesome/solid/greater-than-equal
authors:
 - José W. R. Pereira
tags:
 - CLP
 - Altus
 - TB131
 - Partida Estrela-Triângulo
---

# 1. Operações lógicas

As situações problema resolvidas por um CLP (Controlador Lógico Programável) envolvem a tradução de necessidades industriais em instruções lógicas que o processador executa sequencialmente durante o seu ciclo de varredura (*scan*). A lógica é a capacidade de tomar decisões quando diversos fatores devem ser considerados para que uma ação (saída) ocorra.


Seguem algums exemplos que utilizam as funções lógicas para sua implementação:


1) Uma prensa de furar só deve entrar em funcionamento se uma peça estiver posicionada no local **E** o operador estiver com as duas mãos acionando chaves de partida distintas.

2) Um motor misturador deve agitar o líquido de um tanque somente quando a temperatura **E** a pressão atingirem valores pré-ajustados.

3) O sinaleiro de um reservatório deve acender se o sensor de nível baixo for ativado **OU** se o sensor de temperatura excessiva detectar uma falha.

4) Em um automóvel, a luz de teto acende se a porta do motorista **OU** a porta do passageiro for aberta.

5) Um indicador de "baixa pressão" deve ser ligado sempre que o pressostato **NÃO** estiver fechado (ou seja, quando a pressão cair abaixo do limite).

6) Um sistema de segurança que interrompe um processo se dois sensores de proximidade críticos forem ativados ao mesmo tempo, indicando uma colisão iminente.

7) Um sinaleiro de "Sistema em Espera" que permanece ligado apenas enquanto **nenhuma** das bombas (Bomba A e Bomba B) estiver em operação.

8) Controle de uma lâmpada por dois interruptores diferentes (como em um corredor); se você mudar o estado de qualquer um dos interruptores, a lâmpada inverte seu estado atual.

9) Um sistema de diagnóstico que compara o estado real de chaves de cames rotativas com um padrão desejado armazenado na memória; o sistema indica "Normal" apenas se houver coincidência absoluta entre os bits.

10) Em uma linha de envasamento, **SE** a garrafa estiver cheia (entrada A), **ENTÃO** a tampa deve ser prensada (saída B).


![Implica](img/logica-implica.png)


---

# 2. Desenvolvimento do projeto/atividade/tarefa

## Elabore uma rede (*Network*) para cada uma das lógicas: `E`, `OU`, `Não`, `Não-E`, `Não-OU`, `Ou-Exclusivo` e `Coincidência`. 


Para todas as lógicas, use as mesmas entradas `A` e `B`. 


---
