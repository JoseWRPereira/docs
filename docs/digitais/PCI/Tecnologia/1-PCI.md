---
title: 1 - PCI/PCB
icon: fontawesome/solid/route
author:
 - José W. R. Pereira
tags:
 - KiCad
 - PCI
 - PCB
---

#

# Placa de Circuito Impresso - PCI

Uma **PCI** (**Placa de Circuito Impresso**) ou **PCB** (**Printed Circuit Board**) é a base física e o suporte onde reside todo o hardware eletrônico de um dispositivo ou sistema.

## 1. Composição e Função

*   **Materiais:** As PCIs são geralmente fabricadas em folhas finas de **fibra de vidro** (ou fenolite em versões mais simples).
*   **Caminhos Elétricos:** O circuito elétrico é "impresso" na placa na forma de **trilhas de cobre**, que têm a função de transportar os sinais elétricos entre os diversos componentes conectados.
*   **Conexão de Componentes:** Todos os componentes eletrônicos que formam o sistema são fixados à placa por meio de **soldagem**, uso de soquetes ou outros mecanismos de conexão.

## 2. Elementos do Projeto

*   **Pads:** São áreas de cobre destinadas à soldagem dos terminais dos componentes.
*   **Vias:** Pequenos furos revestidos de cobre usados para realizar **conexões elétricas entre diferentes camadas** da placa (por exemplo, ligar uma trilha da face superior à face inferior).
*   **Trilhas:** A largura das trilhas deve ser dimensionada de acordo com a corrente elétrica que irá percorrê-las para garantir a durabilidade e o funcionamento correto.
*   **Silkscreen:** É a parte impressa (geralmente em branco) que contém legendas, numeração de componentes e nomes de pinos para facilitar a montagem e manutenção.

## 3. Tipos de Montagem e Camadas

*   **PTH (*Plated/Pin Through-Hole*):** Componentes cujos terminais atravessam furos na placa para serem soldados no lado oposto.
*   **SMD (*Surface Mount Device*):** Componentes soldados diretamente sobre a superfície da placa, permitindo a **miniaturização** dos circuitos.
*   **Camadas:** As placas podem ser de **face simples** (cobre em apenas um lado), **dupla face** (cobre em ambos os lados) ou **multicamadas** (*multi-layer*), que funcionam como um "sanduíche" de circuitos para sistemas mais complexos.

## 4. Importância do Design

Um bom projeto de PCI não foca apenas na estética, mas segue regras rigorosas de **compatibilidade eletromagnética** para assegurar que o hardware se comporte conforme o esperado e resista a interferências. Softwares profissionais são utilizados para converter diagramas esquemáticos em layouts físicos de placas. Como principais ferramentas podemos citar o Altium Designer, Cadence OrCAD/Allegro, Autodesk Eagle, Ares (Proteus), EasyEDA e **KiCad**.

***Nota sobre a sigla PCI:*** Além de significar Placa de Circuito Impresso, em contextos de arquitetura de computadores, **PCI** também se refere ao barramento **Peripheral Component Interconnect**, um padrão de comunicação síncrono usado para conectar placas de expansão (como placas de vídeo ou som) à placa-mãe.
PCB é o acrônimo de *Printed Circuit Board*, em português Placa de Circuito Impresso (PCI).

## 5. Fluxo do projeto para PCB

1. Protótipo
2. Esquemático
3. Desenho PCB
4. Produção





---

# Referências

KICAD. **Homepage**. Disponível em: https://www.kicad.org/. Acesso em: 24 fev. 2026.

LIMA, Charles Borges de; VILLAÇA, Marco Valério Miorim. **AVR e Arduino**: Técnicas de Projeto. 2. ed. Florianópolis: Edição dos Autores, 2012.

TAVARES, Rodrigo. **Curso de Projeto de PCB com KiCAD**. YouTube. [s. d.]. Playlist (26 vídeos). Disponível em: https://www.youtube.com/playlist?list=PL8kCnofYYWZrkhUis1svLGux1tjYNJy2Z. Acesso em: 24 fev. 2026.

