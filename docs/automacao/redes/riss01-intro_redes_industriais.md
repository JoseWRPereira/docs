---
title: 01 - Introdução às Redes Industriais
icon: fontawesome/solid/network-wired
author: José W. R. Pereira
tags:
    - Redes Industriais e Protocolos de Comunicação
    - Redes Industriais
    - Protocolos de Comunicação
    - RPI
    - SLTRISS
---

SLTRISS - [Ementa](../../ifsp-slt/automacao/sltriss_ementa.md) - [Plano de Aula](../../ifsp-slt/automacao/sltriss_plano_aula.md) - [Slide da aula](../../automacao/slides/SLTRISS-01-Intro_redes.pdf)

---

#

#

# Fundamentos de Redes

## 1. Redes

De forma abrangente, uma **rede** é um sistema estruturado para a troca de informações e compartilhamento de recursos entre entidades autônomas. No campo da tecnologia, uma **rede de computadores** é definida como um conjunto de computadores autônomos interconectados por uma única tecnologia, permitindo que troquem dados através de diversos meios, como fios de cobre, fibras ópticas ou micro-ondas.

As redes de computadores são classificadas primordialmente pela sua **escala de abrangência**:

*   **PAN (Personal Area Network):** Redes de curtíssimo alcance, destinadas a uma única pessoa.
*   **LAN (Local Area Network):** Abrangem prédios ou campi.
*   **MAN (Metropolitan Area Network):** Cobrem cidades inteiras.
*   **WAN (Wide Area Network):** Estendem-se por países ou continentes.
*   **Internet:** O exemplo máximo de uma "rede de redes", interconectando sub-redes globalmente.

---

## 2. Redes de Computadores vs. Redes Industriais

Embora compartilhem princípios fundamentais, as redes industriais diferem drasticamente das redes de TI (Tecnologia da Informação) convencionais devido aos seus requisitos operacionais. Enquanto na TI o foco é o volume de dados e a flexibilidade, na indústria a prioridade é o **determinismo temporal** e a **robustez**.

### 2.1. Diferenças Essenciais

*   **Criticidade:** Uma falha em uma rede de escritório pode causar atrasos administrativos; uma falha no chão de fábrica pode paralisar uma linha de montagem em segundos ou causar acidentes.
*   **Ambiente:** As redes industriais operam em condições severas de ruído eletromagnético, vibração e temperaturas extremas.
*   **Tipos de Redes Industriais:**
    *   **Redes de Manufatura:** Focadas em alta velocidade e pacotes pequenos para automação discreta (Ex: Profinet, Ethernet/IP).
    *   **Redes de Processo:** Priorizam a continuidade e segurança intrínseca em ambientes quimicamente agressivos (Ex: Profibus PA, Foundation Fieldbus).

---

## 3. O Modelo ISO/OSI na Indústria

Para garantir a interoperabilidade, utiliza-se o modelo **ISO/OSI**, que divide a comunicação em sete camadas de abstração. Na automação industrial, frequentemente utiliza-se uma pilha simplificada (*Communication Stack*) para reduzir a latência:

1.  **Camada 1 (Física):** Define cabos, conectores e sinais elétricos (bits brutos).
2.  **Camada 2 (Enlace):** Gerencia o acesso ao meio e a detecção de erros para garantir transferências confiáveis entre nós.
3.  **Camada 7 (Aplicação):** Onde o software interage com a rede para ler/escrever variáveis e disparar tarefas.

---

## 4. Aspectos Físicos e Lógicos da Rede Industrial

### 4.1. Meios Físicos e Interfaceamento

A robustez física é garantida pelo uso de:

*   **Cabo de Par Trançado (RS-485):** Utiliza sinalização diferencial para cancelar interferências, permitindo distâncias de até 1.200 metros.
*   **Fibra Ótica:** Essencial em ambientes com altíssima interferência eletromagnética ou para longas distâncias.
*   **Conectores Robustos:** Uso de padrões como o **M12** em vez do RJ-45 convencional para suportar vibrações e umidade.

### 4.2. Topologias e Protocolos (Lógica)

As redes podem ser organizadas em **Estrela** (nó central), **Barramento** (linear), **Anel** (redundância) ou **Árvore**. No nível lógico, os protocolos definem as regras de conversação:

*   **Modbus RTU:** Baseado em mestre-escravo, onde um mestre inicia transações lendo ou escrevendo em registros de escravos.
*   **Profibus:** Utiliza passagem de bastão (*Token Pass*) entre mestres para evitar colisões e mestre-escravo para dispositivos de campo.
*   **Foundation Fieldbus:** Distribui o controle através de blocos funcionais diretamente nos instrumentos de campo.

---

## 5. Do Campo à Gestão (Integração TA + TI)

### 5.1. Instrumentação de Campo e CLP

A interconexão começa no nível mais baixo da pirâmide de automação. Sensores e atuadores binários são ligados a redes como **AS-Interface (AS-i)**, que transporta dados e energia no mesmo cabo. Instrumentos mais complexos utilizam barramentos de campo que fornecem diagnósticos e calibração remota.
O **Controlador Lógico Programável (CLP)** atua como o cérebro, processando essas variáveis mapeadas em sua memória como **Tags** ou Registradores.

### 5.2. Fluxo de Dados e Camada de Gestão (IIoT)

Para que os dados cheguem à gestão, eles trafegam por:

1.  **SCADA/Supervisórios:** Fornecem a interface visual (IHM) para operação local.
2.  **Middleware (Ex: Node-RED):** Orquestra o fluxo de dados entre protocolos industriais (Modbus, Profinet) e sistemas de TI (SQL, HTTP).
3.  **Persistência e Historiadores:** Bancos de dados industriais (**SGBD**) armazenam séries temporais para análise de causa raiz e manutenção preditiva.
4.  **IIoT e Virtualização:** Tecnologias como **Docker** e protocolos como **MQTT** permitem dashboards modernos acessíveis via navegador e integração com a nuvem.

---

## 6. Segurança Cibernética no Ambiente Industrial

Com a convergência TI/TA, a segurança tornou-se crítica. O planejamento prevê:

*   **Isolamento:** Uso de **VLANs** industriais para separar o tráfego crítico do administrativo.
*   **Criptografia:** Implementação de padrões como **WPA3** para redes sem fio industriais.
*   **Controle de Acesso:** Proteção rigorosa de portas de containers e interfaces de rede para evitar invasões que possam comprometer a integridade da planta.

---

## Referências

ALBUQUERQUE, Pedro Urbano Braga de; ALEXANDRIA, Alzuir Ripardo de. **Redes industriais**: aplicações em sistemas digitais de controle distribuído. 2. ed. São Paulo: Ensino Profissional, 2009.

ALTUS. **Protocolos de comunicação**: o que são e quais os principais padrões utilizados na indústria. [S. l.]: Altus. E-book.

ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **ABNT NBR 14724**: informação e documentação: trabalhos acadêmicos: apresentação. 4. ed. Rio de Janeiro: ABNT, 2024.

ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **ABNT NBR 6023**: informação e documentação: referências: elaboração. Rio de Janeiro: ABNT, 2018.

COELHO, Marcelo Saraiva. **Redes de comunicação industrial**: padrões industriais. [S. l.: s. n.], 2009. Apostila.

LAGES, Walter Fetter; PEREIRA, Carlos Eduardo. **Redes industriais**. Porto Alegre: UFRGS, 2004. Apresentação em slides.

STALLINGS, William. **Criptografia e segurança de redes**: princípios e práticas. 6. ed. São Paulo: Pearson Education do Brasil, 2015.

TANENBAUM, Andrew S.; WETHERALL, David J. **Redes de computadores**. 5. ed. São Paulo: Pearson, 2011.


---



---


## Pós Ref 0 - Estudo de caso

Às 03:14 da madrugada, as sirenes da Usina Termoelétrica Alfa romperam o silêncio do turno de contingência, anunciando o desligamento de emergência do Setor 4. A sala de controle virou um caos de luzes vermelhas. O supervisor jurava que o sistema supervisório mostrava a temperatura do reator perfeitamente estável nos $65^\circ\text{C}$ minutos antes da trava de segurança ser acionada. No entanto, ao examinarem a caldeira fisicamente, a medição mecânica de backup revelava que o calor havia ultrapassado os limites críticos, sem que nenhum alarme de alta temperatura tivesse sido disparado na tela do operador.

Na manhã seguinte, os peritos iniciaram a investigação buscando falhas de software ou sabotagem no código do supervisório, mas a camada de aplicação da rede parecia intocada. Os registros mostravam que a tela simplesmente parou de atualizar a leitura de temperatura no exato momento da crise, mantendo congelado o último valor válido recebido. Para o sistema, tudo parecia calmo; para a máquina, o desastre era iminente. O software de monitoramento não travou — ele apenas ficou misteriosamente "surdo" para as medições enviadas pelo sensor do processo.

Ao analisarem os registros de tráfego de dados na camada de enlace, a equipe encontrou a primeira pista importante: centenas de quadros de comunicação (*frames*) que vinham daquele setor estavam sendo rejeitados sequencialmente devido a erros irrecuperáveis na verificação de paridade e checagem de redundância (CRC). O cabo de comunicação responsável por trazer os pacotes até o supervisório passava pelo mesmo eletroduto de alvenaria e, misteriosamente, a sequência de erros de transmissão começou no exato minuto em que os grandes motores de indução do compressor principal foram acionados para o ciclo noturno.

Examinando o trajeto do cabo de rede que interligava o sensor ao painel central, os peritos notaram algo suspeito na infraestrutura física: durante uma manutenção recente, o antigo cabo blindado fora substituído por um modelo simples de par trançado sem blindagem (UTP), instalado bem próximo aos cabos de alta potência dos motores. Agora, resta à equipe de investigação técnica entender: como um evento elétrico invisível no meio físico foi capaz de corromper os bits do quadro de dados a ponto de cegar a aplicação do supervisório e provocar o desligamento da planta?

---

## Pós Ref 1 - Material Complementar

| #   | Material | Assuntos |
|:---:|:--------:|:--------:|
| 1   | [Introdução às Redes de Computadores - Comunicação de Dados para Automação](https://youtu.be/0mCzjkEAN6g?si=-FHDcPKRcq3W6w2m) | Conceito de redes <br> LAN, MAN, WAN e PAN <br> Topologias <br> Protocolos <br> Modelo OSI <br> Redes aplicadas à automação |
| 2   | [Modelo ISO/OSI](https://youtu.be/VAKjLpGTnlg?si=l7YChOf37Y8RtYvk) | Camadas do OSI <br>Comunicação entre camadas  <br>Encapsulamento  <br>Protocolos  <br>Equipamentos de rede <br> 34:30 → Modelo ISO/OSI <br> 38:15 → Elementos de rede|
| 3   | [Protocolo Modbus - Visão Geral - Redes Industriais](https://youtu.be/VAKjLpGTnlg?si=srME_WeA5Y_AKfzp) | Modbus RTU <br> Modbus TCP <br> Cliente × Servidor <br> Mestre × Escravo <br> RS-485 <br> Camada de aplicação <br> Funções Modbus  |
| 4   | [Curso gratuito ScadaBR – Modbus: visão geral](https://celsoautomacao.com.br/curso-scadabr/aulas/tema-1/modbus-visao-geral/) | Modbus <br> Endereçamento <br> Frames <br> Registros <br> Comunicação com o supervisório   |
| 5   | [Inter-communication between Programmable Logic Controllers using IoT technologies: A Modbus RTU/MQTT Approach](https://arxiv.org/pdf/2102.05988) | MQTT <br> Docker <br> Node-RED <br> IIoT <br> |
| 6   | [An Implementation of SCADA Network Security Testbed](https://arxiv.org/pdf/1701.05323)| VLAN Industrial <br> Defesa em profundidade <br> ISA/IEC 62443 <br> Segurança em SCADA <br> Segurança em Modbus <br>  |



---

## Pós Ref 2 - Recomendação de leitura

| Índice | Título do artigo | Link de acesso  | Conteúdos abordados |
| :----: | ---------------- | --------------- | ------------------- |
|    1   | **The Future of Industrial Communication: Automation Networks in the Era of the Internet of Things and Industry 4.0** | [IEEE Xplore (DOI)](https://doi.org/10.1109/MIE.2017.2649104) | Evolução das redes industriais; Ethernet Industrial; Internet das Coisas (IoT); Sistemas Ciberfísicos (CPS); Time-Sensitive Networking (TSN); redes 5G industriais; convergência OT/IT; tendências da comunicação industrial. ([DOI][1]) |
|    2   | **Literature Review of Industry 4.0 and Related Technologies**  | [Springer (DOI)](https://doi.org/10.1007/s10845-018-1433-8) | Revisão abrangente sobre Indústria 4.0; Smart Factory; IoT; Big Data; Cloud Computing; CPS; interoperabilidade; virtualização; integração entre tecnologias digitais e manufatura inteligente. ([DOI][2])                                |
|    3   | **Mapping Industry 4.0 Technologies: From Cyber-Physical Systems to Artificial Intelligence**  | [arXiv (pré-print)](https://arxiv.org/abs/2111.14168) | Mapeamento das tecnologias da Indústria 4.0; IIoT; Inteligência Artificial; CPS; análise bibliométrica; tendências tecnológicas; relações entre tecnologias habilitadoras. ([arXiv][4])                                                  |
|    4   | **Artificial Intelligence in Industry 4.0: A Review of Integration Challenges for Industrial Systems** | [arXiv (pré-print)](https://arxiv.org/abs/2405.18580) | Integração de IA em sistemas industriais; IIoT; CPS; Edge Computing; desafios de integração; interoperabilidade; dados industriais; automação inteligente. ([arXiv][5])                                                                  |
|    5   | **Industry 4.0: A Step Towards Achieving the SDGs? A Critical Literature Review** | [Springer (artigo)](https://link.springer.com/article/10.1007/s43621-021-00030-1) | Evolução da Indústria 4.0; transformação digital; impacto das tecnologias industriais; sustentabilidade; manufatura inteligente; integração entre tecnologias digitais e objetivos de desenvolvimento sustentável. ([Springer][3])       |

---

---

