---
title: 1 - KiCad
icon: fontawesome/solid/k
author:
 - José W. R. Pereira
tags:
 - KiCad
 - PCI
 - PCB
---

#

![capa](img/kicad-capa.png)

# 


O [**KiCad**](https://www.kicad.org/) é um pacote de software **livre e de código aberto** voltada para a automação de design eletrônico (EDA). Ele oferece ferramentas completas para a criação de circuitos eletrônicos, incluindo captura de esquemas, simulação de circuitos integrados, layout de placas de circuito impresso (PCB), renderização 3D e exportação de dados para fabricação. O software é multiplataforma, funcionando em **Linux, Windows e macOS**.

## Fluxo de Trabalho do KiCad
O fluxo de trabalho no KiCad é centralizado em um **Gerenciador de Projetos** que integra os diversos componentes do software. Diferente de versões muito antigas, onde era necessário gerar arquivos de "netlist" manualmente para passar do esquema para a PCB, as versões modernas realizam essa integração de forma direta.

O processo típico envolve:

1.  **Edição do Esquema:** Utiliza-se o **Editor de Esquemas** para desenhar o circuito usando símbolos (resistores, microcontroladores, etc.) de bibliotecas preexistentes.
2.  **Simulação:** É possível realizar simulações de circuitos (via **Ngspice**) diretamente no editor de esquemas para verificar o comportamento elétrico.
3.  **Layout da PCB:** No **Editor de PCB**, o design é transformado em um layout físico, posicionando as **footprints** (pegadas) dos componentes e traçando as conexões de cobre.
4.  **Geração de Arquivos de Saída:** O processo de **plotagem** gera os arquivos necessários para a fabricação, como arquivos Gerber, brocas de perfuração e listas de materiais (BOM).

## Informações Relevantes

*   **Componentes Adicionais:** A suíte inclui ferramentas como: 
    - **GerbView**: visualizador de arquivos Gerber.
    - **PCB Calculator**: para cálculos de largura de trilha e espaçamento elétrico.
    - **Bitmap2Component**: converte imagens em símbolos ou footprints.
*   **Gerenciamento de Biblioteca:** O KiCad possui bibliotecas vastas de símbolos, footprints e modelos 3D, além de editores dedicados para que o usuário crie seus próprios componentes.
*   **Compatibilidade de Arquivos:** O software é **retrocompatível**, abrindo arquivos de versões anteriores. Entretanto, uma vez que um arquivo é salvo em uma versão principal nova (como a 9.0), ele **não poderá mais ser aberto por versões anteriores**.
*   **Interface de Usuário:** O comportamento é baseado em "ferramentas" (modos de operação). A tecla **Esc** é usada universalmente para cancelar ações ou retornar à ferramenta de seleção padrão.


# Principais etapas do projeto eletrônico

![](img/kicad-esquematico-layout-3dviewer.png)

## 1. Esquemático (Schematic)

O **esquemático** é uma coleção de uma ou mais páginas (folhas) que contêm os **desenhos do circuito eletrônico**.

*   **Símbolos:** Nele, você utiliza **símbolos** para representar elementos do circuito, que podem ser componentes físicos (como resistores e microcontroladores) ou conceitos não físicos (como terminais de energia ou terra).
*   **Conexões:** Os símbolos possuem **pinos**, que são os pontos de conexão interligados por fios no desenho.
*   **Funcionalidade:** No Editor de Esquemáticos do KiCad, além de desenhar o circuito, é possível realizar **simulações integradas (via SPICE)** e gerar listas de materiais (BOM).

## 2. Layout (PCB)

O **layout** (ou placa de circuito impresso - PCB) é o documento de design que representa a **implementação física** do esquemático.

*   **Footprints:** No layout, os símbolos do esquemático são substituídos por **footprints** (pegadas), que definem o espaço físico e os **pads** (áreas de cobre) onde os componentes serão soldados na placa real.
*   **Roteamento:** É nesta etapa que se definem as trilhas de cobre, o empilhamento de camadas (padstacks) e as vias de conexão entre elas.
*   **Fabricação:** O Editor de PCB é usado para gerar os arquivos de saída necessários para a produção da placa, como arquivos **Gerber** ou o formato **ODB++**.

## 3. Visualizador 3D (3D Viewer)

O **3D Viewer** é a ferramenta de **renderização 3D** integrada ao KiCad, que permite visualizar a placa antes de ela ser fabricada.

*   **Modelagem Detalhada:** Ele exibe modelos 3D dos componentes montados sobre a placa, permitindo uma inspeção visual do design físico.
*   **Exportação:** O sistema de renderização 3D do KiCad permite exportar o design em diversos formatos para uso em outros softwares de engenharia.
*   **Precisão:** Versões recentes (como a 9.0) melhoraram o suporte para exibir detalhes finos de cobre e oferecem mais controle sobre quais dados são incluídos na visualização e exportação do modelo.




---

# Referências

KICAD. **Homepage**. Disponível em: https://www.kicad.org/. Acesso em: 24 fev. 2026.

LIMA, Charles Borges de; VILLAÇA, Marco Valério Miorim. **AVR e Arduino**: Técnicas de Projeto. 2. ed. Florianópolis: Edição dos Autores, 2012.

TAVARES, Rodrigo. **Curso de Projeto de PCB com KiCAD**. YouTube. [s. d.]. Playlist (26 vídeos). Disponível em: https://www.youtube.com/playlist?list=PL8kCnofYYWZrkhUis1svLGux1tjYNJy2Z. Acesso em: 24 fev. 2026.

