---
title: 03 - Sistema Supervisório
icon: fontawesome/solid/tv
author: José W. R. Pereira
tags:
    - Redes Industriais e Protocolos de Comunicação
    - Redes Industriais
    - Protocolos de Comunicação
    - RPI
    - SLTRISS
---

SLTRISS - [Ementa](../../ifsp-slt/automacao/sltriss_ementa.md) - [Plano de Aula](../../ifsp-slt/automacao/sltriss_plano_aula.md)

---

#

# Sistemas Supervisórios e Interfaces Homem-Máquina (IHM): Fundamentos, Paradigmas e Diretrizes de Design

---

## 1. Introdução aos Sistemas Supervisórios (SCADA)

No contexto da automação e do controle de processos industriais, os sistemas **SCADA** (*Supervisory Control and Data Acquisition* ou Controle Supervisório e Aquisição de Dados) atuam na camada superior de controle e supervisão, permitindo que estações de operação monitorem, configurem e interajam com variáveis físicas de processo à distância. O funcionamento básico de um sistema SCADA baseia-se em um fluxo estruturado de dados que interliga o mundo físico à representação digital:

**A Aquisição Física e Mapeamento de Memória:** Variáveis físicas de processo (como temperatura, pressão ou umidade) são detectadas por sensores de campo. Esses sensores geram sinais que os módulos de entrada do Controlador Lógico Programável (CLP) convertem em representações de dados lógicos (bits ou palavras de 16 bits) em sua memória interna, mapeados classicamente em áreas como:

- *Coils* (saídas/bobinas discretas - 0XXXX);
- *Digital Inputs* (entradas digitais discretas - 1XXXX);
- *Analog Inputs* (registradores de entrada analógica - 3XXXX);
- *Holding Registers* (registradores de retenção - 4XXXX).

**A Rede de Comunicação e o Host SCADA:** O sistema supervisório centralizado, funcionando como um dispositivo *Host* (Servidor de Operação ou Cliente em nível superior), estabelece conexão lógica com os múltiplos CLPs distribuídos através de meios de transmissão (como par trançado RS-485 ou redes Ethernet Industrial) utilizando protocolos de comunicação industriais padronizados (como Modbus RTU, Modbus TCP/IP, Profibus, entre outros).

**Mecanismo de Requisição/Resposta (Polling):** O software supervisório realiza varreduras periódicas na rede, enviando frames de consulta estruturados para ler os registradores e bobinas de memória interna dos CLPs (ex: enviando o código de função Modbus `03` para ler um registrador de memória 4XXXX). O CLP escravo responde encapsulando os dados lidos em frames de resposta que trafegam de volta ao supervisório para atualizar dinamicamente o estado das telas visuais.

---

## 2. Paradigmas de Engenharia nos Sistemas Supervisórios

O desenvolvimento de projetos SCADA de nível industrial exige a compreensão de paradigmas críticos de arquitetura, latência, resiliência e concorrência:

*   **Tags de Comunicação vs. Tags Virtuais (Humanas):** As variáveis do sistema SCADA são divididas entre **Tags de Comunicação** (vinculadas diretamente ao endereço de memória física de um registrador ou bobina de um CLP de campo) e **Tags Humanas/Virtuais** (variáveis internas da interface de supervisão usadas para simulação, cálculos matemáticos locais ou lógica de alternância de telas).
*   **O Driver de Comunicação e a Taxa de Varredura (Polling):** O driver de comunicação é o intermediário que traduz os comandos de software do SCADA para o protocolo físico aceito pelo hardware de controle. A definição da taxa de *polling* (frequência de atualização) é um fator de otimização de banda da rede industrial. Configurar frequências de varredura excessivamente baixas (por exemplo, 10 milissegundos) gera uma saturação de pacotes de dados no barramento e pode causar travamentos por colisão e sobrecarga de processamento no CLP de controle.
*   **Concorrência Multitela e Hierarquias de Comando:** Em plantas industriais reais, múltiplos nós de visualização operam simultaneamente (por exemplo, uma IHM com painel físico de toque no chão de fábrica e um computador supervisório centralizado na sala de controle). Sem uma clara definição de **hierarquia de comandos** (quem tem a prioridade de controle em um dado instante), a concorrência de comandos (como o operador de campo apertar "parar" e o operador da sala de controle enviar comandos automáticos de "ligar") pode causar disputa perigosa de pacotes na rede e comportamentos intermitentes e inseguros na planta.
*   **Tempo Real Instantâneo vs. Historiadores (SGBD):** Telas de supervisão comuns mostram apenas o estado instantâneo do processo ("o agora"). Se um operador fechar ou minimizar a janela visível do SCADA, o software visual convencional para de armazenar dados do processo. Para auditorias de qualidade, manutenção preditiva e análise de quebras de turno, a indústria exige a integração com um **Historiador (SGBD)** — um Sistema de Gerenciamento de Banco de Dados relacionais (como PostgreSQL ou SQLite) ou não-relacionais, que grava dados históricos continuamente em segundo plano com um carimbo de tempo (*timestamp*), independentemente da tela visual estar ativa ou inativa. Esse processo geralmente é orquestrado por um *middleware* resiliente de controle (como o Node-RED).
*   **Diagnóstico de Comunicação e o Comportamento de Tags "Congeladas":** Um dos problemas de segurança operacional mais críticos ocorre no comportamento de um programa SCADA quando há uma falha de comunicação física na planta. Tipicamente, o SCADA tende a **congelar visualmente o último valor lido estável** de uma variável na tela, em vez de exibir um erro explícito imediatamente. Se não houver mecanismos de *watchdog*    de comunicação ou alarmes de desconexão estruturados de forma explícita, o operador de processo pode acreditar que as variáveis estão normais (por exemplo, uma caldeira estável a \\(65^\circ\text{C}\\)) enquanto na verdade a comunicação foi rompida e a temperatura física real está subindo perigosamente.

---

### 3. Foco em Software Prático: Configuração no ScadaBR e BluePlant (Altus)

No desenvolvimento acadêmico e de integração, utilizam-se tanto ferramentas *open-source* com arquiteturas abertas quanto pacotes industriais proprietários de alta performance:

#### 3.1. ScadaBR
É um software de supervisão de código aberto ideal para simulação, pesquisa acadêmica e integração de sistemas heterogêneos (combinando CLPs tradicionais com plataformas open-hardware como Arduino ou ESP32).

*   **Configuração do Data Source (Driver):** Na interface de configuração do ScadaBR, o projetista cria um novo *Data Source* selecionando o protocolo correspondente (por exemplo, *Modbus Serial* ou *Modbus IP*). Na configuração serial, devem ser definidos os parâmetros físicos da rede (Porta COM do computador, *Baud Rate* - taxa de transmissão, Bits de dados, Paridade e Bits de Parada - *Stop Bits*) de acordo com os limites físicos da interface do barramento RS-485 ou RS-232 correspondente.
*   **Configuração de Data Points (Tags de Comunicação):** Dentro do Data Source ativo, o projetista adiciona os *Data Points* associando-os aos endereços lógicos dos CLPs. Configura-se o ID do CLP na rede Modbus (de 1 a 247), a faixa de registro a ser lida (ex: *Holding Register* ou *Coils*) e o código de função de leitura (como a função Modbus `03` para registradores ou `01` para bobinas de saída).

#### 3.2. Altus BluePlant

*   O **BluePlant** é o SCADA industrial de alta performance da Altus, desenvolvido para ambientes que exigem alta taxa de disponibilidade e integração nativa com o barramento do CLP. No BluePlant, o engenheiro de controle configura *drivers* nativos de comunicação industrial que suportam protocolos complexos de rede como Profinet, EtherNet/IP ou o Modbus TCP de modo nativo e integrado.
*   Diferente da configuração manual ponto a ponto do ScadaBR, o BluePlant permite a importação integrada de tabelas de variáveis simbólicas (*Tags* lógicas) diretamente do ambiente de programação dos controladores (como tabelas IEC 61131-3 do CODESYS), eliminando a necessidade de mapear endereços numéricos decimais de registradores. Suporta nativamente protocolos de telemetria com estampa de tempo incorporada na origem, como o IEC 60870-5-104 Server.

---

### 4. Interfaces Homem-Máquina (IHM) e Diretrizes de Design de Telas (Norma ISA-101)

A **Interface Homem-Máquina (IHM)** é o componente físico (painéis dedicados de campo) ou lógico (telas de software do sistema SCADA) que permite a tradução visual de fluxos de dados de controle complexos para a interação segura com o operador de campo.

#### 4.1. O Desafio da Poluição Visual no Chão de Fábrica
Historicamente, as IHMs industriais eram construídas com animações exageradas (motores que giravam na tela, chamas 3D animadas em caldeiras), paletas de cores berrantes de alto contraste (fundos totalmente pretos ou cinza-escuro com linhas brilhantes em azul ou verde) e exibições exaustivas de números piscando de forma aleatória pela tela.

A pesquisa ergonômica e os estudos de engenharia humana provaram que esse estilo visual poluído causa **fadiga severa no operador**, cansaço ocular após poucas horas de turno e esgota a atenção do profissional. Sob estresse ou sobrecarga de informação, o operador perde a capacidade de identificar rapidamente qual indicador ou alarme é realmente crítico, o que já levou a acidentes catastróficos em processos (como picos de pressão não visualizados a tempo).

#### 4.2. A Filosofia de Design de Telas de Alta Performance baseada na Norma ISA-101
A norma **ISA-101** (*Human-Machine Interfaces*) padronizou o design de IHMs industriais eficazes para focar a atenção do cérebro humano apenas no que é de fato importante no processo:

```
   +-------------------------------------------------------+
   |  [ALARME] REGISTRADOR FORA DA FAIXA - TEMP: >95°C !  | <-- Cor quente de destaque (Exclusiva de Alarmes)
   +-------------------------------------------------------+
   |                                                       |
   |   [Tanque Principal]      Grafico de Tendencia (Trend)|
   |       +-------+             80 |      /\              | <-- Mini-grafico mostra a variacao
   |       |       |             60 |     /  \             |     e a direcao da variavel ao longo
   |       |       |             40 |____/____\___________ |     do tempo (Muito superior a numeros soltos)
   |       +-------+                +--------------------> |
   |     (Tons de Cinza)                     Tempo         | <-- Elementos normais do sinotico em tons neutros
   +-------------------------------------------------------+
```

1.  **Fundos e Elementos Estáveis em Tons Neutros (Cinza-Claro):** O fundo da tela e todos os elementos de equipamentos que estão operando em condições normais estáveis devem ser representados de forma simples, em linhas finas e tons de cinza ou bege-claro. Isso mantém a IHM silenciosa e não cansativa à visão humana.
2.  **Uso de Cores Quentes Exclusivo para Anormalidades e Alarmes:** Cores vibrantes (vermelho para alarmes severos de parada, amarelo para avisos e laranja para desvios críticos) devem ser mantidas **estritamente desligadas** durante a operação normal. Elas só devem acender em tela quando houver um desvio real fora das faixas normativas de alarme (por exemplo, temperatura acima de \\(95^\circ\text{C}\\) ou limites críticos baixíssimos `LO_LO` e altíssimos `HI_HI`). O que está em operação segura fica "invisível" em termos de coloração ativa.
3.  **Indicadores de Tendência (Trends) vs. Exibições Numéricas Soltas:** Exibir apenas o valor instantâneo isolado (ex: temperatura de \\(85^\circ\text{C}\\)) não permite deduzir a direção da variável. A norma ISA-101 prescreve o uso de pequenos **Gráficos de Tendência** analógicos ao lado do sinótico. Esses gráficos mostram a linha temporal recente da variável, permitindo ao operador prever desvios futuros de temperatura antes mesmo que o limite crítico de segurança do processo seja ultrapassado.
4.  **Hierarquia de Navegação Visiva:**
    *   **Nível 1 (Visão Global):** Uma única tela mostrando o estado de saúde global de toda a planta ou linha de montagem, focada apenas nos KPIs principais.
    *   **Nível 2 (Visão de Subsistema):** Telas dedicadas para a operação de um subsistema específico (como a planta da caldeira ou reator).
    *   **Nível 3 (Visão de Detalhes):** Telas com pop-ups e páginas de ajuste fino de controladores de campo (como loops de sintonia PID).
    *   **Nível 4 (Diagnósticos e Ajuda):** Telas de troubleshoot de rede, monitoramento de cartões de CLP e páginas de help desk técnico.

---

### Resumo dos Principais Mapeamentos e Códigos de Comunicação Associados (Modbus)

| Tipo de Variável no CLP | Faixa de Endereços | Código de Leitura (Polling) | Código de Escrita | Aplicação Típica em Telas SCADA |
| :--- | :--- | :--- | :--- | :--- |
| **Coils (Bobinas)** | `0XXXX` | `01` | `05, 15` | Botões de liga/desliga de motores e atuadores discretos. |
| **Digital Inputs** | `1XXXX` | `02` | *N/A (Somente Leitura)* | Indicadores de sensores de presença de peças ou fim-de-curso. |
| **Analog Inputs** | `3XXXX` | `04` | *N/A (Somente Leitura)* | Leitura bruta de transmissores de pressão, fluxo ou umidade. |
| **Holding Registers** | `4XXXX` | `03` | `06, 16` | Armazenamento de variáveis de set-point de controladores ou escalas complexas. |

---


### Sugestões de cursos no Youtube
   
  
- [Curso ScadaBR 1.2 Completo - Celso Automação](https://youtu.be/Q-ysIqivosg?si=0nbzTJsavEbaC0dF)
- [Blue Plant - Sistema HMI/Scada by Altus S.A.](https://www.youtube.com/playlist?list=PLyXOhZvvjr-8q3h51W2gAHNJMKIGvHns7)



---

### Referências

ALBUQUERQUE, Pedro Urbano Braga de; ALEXANDRIA, Auzuir Ripardo de. **Redes industriais**: aplicações em sistemas digitais de controle distribuído. 2. ed. rev. e ampl. São Paulo: Ensino Profissional, 2009. 258 p. ISBN 9788599823118.

ALTUS SISTEMAS DE AUTOMAÇÃO. **Protocolos de comunicação**: afinal, o que é isso?!. São Leopoldo: Altus, [201-?]. E-book. Disponível em: <https://www.altus.com.br>. Acesso em: 1 set. 2026.

CODESYS GmbH. **CODESYS Online Help & Documentation Portal**. Kempten, Alemanha, 2026. Disponível em: <https://help.codesys.com>. Acesso em: 1 set. 2026.

COELHO, Marcelo Saraiva. **Apostila de Redes de Comunicação Industrial (RCI)**. Cubatão: Instituto Federal de Educação, Ciência e Tecnologia de São Paulo (IFSP), Campus Cubatão, 2008.

INTERNATIONAL SOCIETY OF AUTOMATION. **ANSI/ISA-101.01-2015**: Human-Machine Interfaces for Process Automation Systems. Research Triangle Park: ISA, 2015.

LAGES, Walter Fetter; PEREIRA, Carlos Eduardo. **Redes Industriais**. Porto Alegre: Universidade Federal do Rio Grande do Sul (UFRGS), Escola de Engenharia, Departamento de Engenharia Elétrica, [200-?]. Disponível em: <http://www.eletro.ufrgs.br/~fetter/ele00012>. Acesso em: 1 set. 2026.

LUGLI, Alexandre Baratella; SANTOS, Max Mauro Dias. **Sistemas Fieldbus para automação industrial**: DeviceNet, CANopen, SDS e Ethernet. 1. ed. São Paulo: Érica, 2009. 156 p. ISBN 9788536502496.

SCADABR. **Desenvolvimento de telas e inserção de Tags no ScadaBR**. 2026. Disponível em: <http://www.scadabr.org.br>. Acesso em: 1 set. 2026.

TANENBAUM, Andrew S.; WETHERALL, David J. **Redes de Computadores**. Tradução de Daniel Vieira. Revisão Técnica de Isaias Lima. 5. ed. São Paulo: Pearson Education do Brasil, 2011.

---
