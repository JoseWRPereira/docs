---
title: Classificação e Arquiteturas
icon: fontawesome/solid/hexagon-nodes
author: José W. R. Pereira
tags:
    - Redes Industriais
    - Protocolos de Comunicação
    - RPI
---

#

**[Classificação e arquiteturas](../slides/aula02-classificacao_das_redes.pdf)**

---

||||
|:--:|:-----------------|:----------------------|
| 1 | Topologia física | - Barramento;<br> - Anel;<br> - Estrela;<br> - Árvore; - Misto. |
| 2 | Modelos de redes | - Origem-Destino;<br> - Produtor-Consumidor. |
| 3 | Método de troca de dados | - Polling;<br> - Cíclico;<br> - Mudança de estado. |
| 4 | Tipo de conexão | - Ponto a ponto;<br> - Multiplos pontoss.|
| 5 |Modo de transmissão | - Serial; <br> - Paralelo. |
| 6 | Sincronização de bits | - Síncrona; <br> - Assíncrona. |
| 7 | Modo de operação | - Simplex; <br> - Half duplex; <br> - Full duplex. |
| 8 | Tipo de comunicação | - Comutação de circuitos; <br> - Comutação de  pacotes.|


---

**Análise Comparativa de Classificações de Redes Industriais**

**Introdução**

A complexidade dos ambientes de automação modernos exige uma compreensão clara dos fundamentos que governam a comunicação entre dispositivos, desde o nível de chão de fábrica até os sistemas de supervisão.

A compreensão dessas classificações — que abrangem desde a topologia física e os modelos lógicos até os modos de transmissão e operação — é fundamental para a tomada de decisões informadas no projeto e na arquitetura de sistemas de automação. Uma escolha adequada de arquitetura garante não apenas o desempenho requerido pela aplicação, mas também a eficiência, a confiabilidade e a escalabilidade do sistema como um todo. Este relatório irá dissecar sistematicamente cada categoria de classificação, detalhando suas variantes e implicações práticas para o ambiente industrial.


---


**1.0 Análise de Topologias Físicas**

A escolha da topologia física de uma rede industrial é uma decisão estratégica de projeto. O arranjo físico dos nós (dispositivos) e dos cabos que os interconectam impacta diretamente fatores críticos como o custo de implementação, a robustez do sistema a falhas, a facilidade de expansão futura e o desempenho geral da comunicação. A seguir, analisamos as topologias mais comuns no contexto industrial.

**1.1 Topologia Barramento (Bus)**

A topologia de barramento, ou bus, é caracterizada por uma estrutura onde todos os nós compartilham um mesmo meio físico de transmissão. Nessa configuração, a comunicação é realizada de forma que apenas um dispositivo pode transmitir dados por vez, evitando colisões de informação.

* Características Principais:
  * Todos os nós estão conectados ao mesmo meio de comunicação.
  * Apenas um nó pode comunicar por vez.
  * É uma topologia muito utilizada na indústria devido à sua simplicidade.
  * Apresenta um menor custo de implementação em comparação com outras topologias.

Esta simplicidade, no entanto, introduz um ponto único de falha crítico: uma quebra no cabo principal pode interromper a comunicação para todo o segmento da rede, um risco significativo em aplicações de missão crítica.

**1.2 Topologia Anel (Ring)**

Utilizada em diversos sistemas de automação industrial, a topologia em anel conecta os nós em uma formação circular fechada. Cada dispositivo se comunica diretamente com seus vizinhos imediatos, e a informação circula pelo anel, sendo regenerada em cada nó até chegar ao seu destino.

* Vantagens Estratégicas:
  * Capacidade de transmitir dados para ambos os lados do anel.
  * Possibilidade de implementação com dupla redundância, aumentando a tolerância a falhas.
  * Garante que todos os nós da rede recebam a informação transmitida.

A principal vantagem reside na sua alta resiliência quando implementada com redundância, mas a adição ou remoção de nós pode exigir a interrupção temporária da rede, e a latência aumenta linearmente com o número de dispositivos no anel.

**1.3 Topologia Estrela (Star)**

Na topologia em estrela, todos os dispositivos são interligados a um equipamento central, como um concentrador ou switch, que centraliza e coordena toda a comunicação. Cada nó possui um link dedicado ao ponto central, e a comunicação entre nós periféricos deve, obrigatoriamente, passar por este equipamento.

* Vulnerabilidades e Limitações:
  * Pontos de Falha: A operação da rede é vulnerável a falhas tanto no nó central (o que compromete toda a rede) quanto em um nó de extremidade (que isola apenas aquele dispositivo).
  * Limites de Expansão: A capacidade de expansão é limitada pelo número de portas disponíveis no equipamento central.
  * Limites de Velocidade: A velocidade da rede pode ser limitada pela capacidade de processamento do nó central.
  * Custo de Implementação: O custo de implementação costuma ser mais elevado que o das topologias de barramento e anel devido à necessidade do equipamento central e maior quantidade de cabeamento.

Por outro lado, esta centralização simplifica drasticamente a detecção e o isolamento de falhas, pois um nó ou cabo defeituoso pode ser desconectado do hub central sem impactar o restante da rede, um benefício considerável para a manutenção.

**1.4 Topologia em Árvore (Tree)**

A topologia em árvore pode ser vista como uma extensão hierárquica da topologia estrela. Ela conecta múltiplas redes em estrela a um barramento central ou a um nó raiz, criando uma estrutura ramificada.

* Características e Aplicações:
  * Permite a segmentação da rede em grupos de trabalho lógicos e gerenciáveis.
  * Facilita a expansão da rede de forma estruturada, adicionando novas "ramificações".
  * A falha de um nó afeta apenas sua própria ramificação, mas a falha de um nó de nível superior (especialmente a raiz) pode isolar grandes segmentos da rede.

Esta topologia é ideal para plantas industriais de grande porte, onde diferentes setores ou linhas de produção podem ser organizados como ramos distintos da rede principal.

Além destas, topologias como Malha (Mesh), onde os nós se interconectam diretamente com múltiplos outros nós para máxima redundância, e Mista (Hybrid), que combina características de duas ou mais topologias, são empregadas para atender a requisitos específicos de confiabilidade e escalabilidade. Embora a topologia física defina o layout da infraestrutura, são os modelos lógicos de comunicação que ditam como os dados são efetivamente trocados entre os dispositivos.


---


**2.0 Análise de Modelos de Comunicação de Redes**

Os modelos de comunicação definem a arquitetura lógica e a hierarquia da troca de informações em uma rede industrial. Eles estabelecem as regras de interação, determinando como os dispositivos iniciam a comunicação, acessam os dados e respondem a solicitações, independentemente do arranjo físico dos cabos.

**2.1 Modelos Origem/Destino e Mestre/Escravo**

O modelo fundamental de comunicação é o Origem/Destino (Source/Destination), no qual as mensagens são explicitamente endereçadas de um nó de origem para um nó de destino específico. A rede garante a entrega da mensagem ao destinatário endereçado.

Uma implementação hierárquica e especializada deste conceito é o modelo Mestre/Escravo (Master/Slave). Nesta arquitetura, um dispositivo "Mestre" (Master) controla a rede, sendo o único a iniciar todas as transações e enviar requisições aos dispositivos "Escravos" (Slaves).

* Papel do Escravo: O "escravo" é um dispositivo periférico passivo — como sensores, atuadores ou inversores de frequência — cuja função é exclusivamente responder a requisições diretas vindas do mestre.
* Variações: Uma rede pode operar com um único mestre (monomestre) ou com vários mestres no mesmo barramento (multimestre), embora o acesso ao meio ainda precise ser coordenado.

Este modelo oferece simplicidade e determinismo, mas sua principal limitação é que os escravos não podem iniciar a comunicação, mesmo que possuam dados críticos para reportar, devendo aguardar a interrogação do mestre.

**2.2 Modelo Produtor/Consumidor (Producer/Consumer)**

O modelo Produtor/Consumidor (Producer/Consumer) opera sob um princípio de comunicação orientada a dados, e não a dispositivos. Neste modelo, os pacotes de dados recebem um identificador único (como um Connection ID ou CAN ID) que os associa a uma informação específica, não a um dispositivo de destino.

O processo de comunicação se dá quando um nó "Produtor" publica os dados na rede. Qualquer nó "Consumidor" que tenha sido configurado para "assinar" aquele identificador de dados específico irá recebê-lo e processá-lo. Este mecanismo resulta em uma significativa economia de banda, pois as informações são transmitidas uma única vez e consumidas por múltiplos nós interessados, sem a necessidade de envios individuais. Este modelo é altamente eficiente e flexível, mas pode exigir uma configuração mais complexa para gerenciar as associações entre produtores e consumidores.

Embora os modelos Mestre/Escravo e Produtor/Consumidor sejam prevalentes em redes de chão de fábrica, outros modelos como Cliente/Servidor, baseados em filas ou em tabelas de comunicação, também existem em contextos industriais, tipicamente em níveis mais altos da pirâmide de automação (MES, ERP). A escolha do modelo de comunicação influencia diretamente os métodos pelos quais os dados são consultados e transmitidos na rede.


---


**3.0 Análise de Métodos de Troca de Dados**

O método de troca de dados determina o gatilho para a transmissão de informações entre os dispositivos. Essa escolha impacta criticamente a eficiência do uso da banda de rede, o determinismo (previsibilidade do tempo de entrega de mensagens) e a latência da comunicação, fatores essenciais em sistemas de controle em tempo real.

**3.1 Polling**

No método de Polling (ou varredura), a comunicação é iniciada por um dispositivo mestre, que interroga sequencialmente cada um dos dispositivos escravos na rede para solicitar dados ou enviar comandos. O escravo só transmite informações quando "questionado" pelo mestre.

* Características e Compatibilidades:
  * Compatibilidade: É compatível com sistemas Mestre/Escravo e Multimestre.
  * Base de Desenvolvimento: Construído sobre os modelos de comunicação Origem/Destino e Mestre/Escravo.
  * Limitação: É inerentemente um método ponto a ponto, não oferecendo suporte a multicast.

O Polling garante um alto nível de determinismo, pois o mestre controla todo o tráfego. Contudo, pode ser ineficiente se os dados nos escravos mudarem com pouca frequência, consumindo largura de banda para consultar informações inalteradas.

**3.2 Cíclico (Cyclic)**

No método Cíclico, os dispositivos são configurados para produzir e transmitir dados em intervalos de tempo pré-definidos pelo usuário. Cada nó opera com uma taxa de atualização específica, adequada à sua função no processo.

* Fatores de Eficiência:
  * Permite que os dados sejam transferidos a uma taxa adequada para cada dispositivo ou aplicação.
  * Preserva recursos de rede, pois dispositivos que geram dados com alta variação podem ter taxas mais altas, enquanto outros, mais lentos, utilizam menos banda.
  * Proporciona um bom determinismo, já que a transmissão ocorre em intervalos regulares.
  * É compatível com os modelos Mestre/Escravo, Multimestre, "peer-to-peer" e Multicast.

Este método oferece um excelente equilíbrio entre determinismo e eficiência para a maioria das aplicações de controle, embora ainda possa haver desperdício de banda se os dados permanecerem constantes entre os ciclos de transmissão.

**3.3 Mudança de Estado (Change of State)**

O método de Mudança de Estado é projetado para otimizar ao máximo o uso da rede. A transmissão de dados ocorre apenas quando o estado de um dispositivo é alterado, ou seja, quando há uma nova informação relevante a ser comunicada. Para garantir que um dispositivo silencioso ainda está funcional, um sinal de Heartbeat é transmitido ciclicamente para confirmar que ele continua operacional.

* Benefícios de Eficiência:
  * Reduz significativamente o tráfego da rede, pois elimina transmissões redundantes.
  * Evita o desperdício de recursos de processamento, pois os dispositivos não precisam processar dados antigos que não foram alterados.

Esta abordagem é a mais eficiente em termos de largura de banda, mas sacrifica o determinismo temporal estrito, pois o instante da transmissão depende do processo e não de um ciclo de relógio fixo.

Estes métodos de troca de dados são suportados por diferentes naturezas de conexões físicas que os sustentam.


---


**4.0 Análise de Tipos de Conexão**

O tipo de conexão descreve a forma como os dispositivos são ligados a um meio de transmissão. A escolha entre um link dedicado ou compartilhado tem implicações diretas na alocação de largura de banda, na complexidade da instalação física, no custo e na resiliência da rede a falhas de equipamentos.

**4.1 Conexão Ponto a Ponto (Point-to-Point)**

Uma conexão ponto a ponto estabelece um link de comunicação dedicado que conecta apenas dois dispositivos. Não há compartilhamento do meio físico com outros nós.

* Atributos:
  * Instalação fácil e prática.
  * Modelo de fácil entendimento.
  * Não há divisão de banda, o que contribui para a estabilidade e previsibilidade da conexão.

Este tipo de conexão é ideal para links de comunicação críticos e de alta velocidade entre dois equipamentos específicos, como um CLP e um sistema de I/O remoto principal.

**4.2 Conexão Múltiplos Pontos (Multipoint/Multicast)**

Na conexão de múltiplos pontos, um único link físico é compartilhado por diversos dispositivos. Esta topologia de meio compartilhado é a base para a comunicação Multicast, onde uma única mensagem pode ser recebida por múltiplos (mas não necessariamente todos) os nós.

* Características Principais:
  * A largura de banda do link é dividida entre todos os dispositivos conectados.
  * Instalação geralmente fácil e de baixo custo.
  * Alta confiabilidade e resiliência, pois a falha de um dos equipamentos da rede não causa a interrupção da conexão para os outros dispositivos no barramento.

Esta abordagem é extremamente econômica em termos de cabeamento, mas requer um protocolo de acesso ao meio para gerenciar o compartilhamento da banda e evitar colisões.

Além do tipo de conexão, o modo como os bits de dados são enviados através do meio físico é outra camada fundamental da arquitetura de comunicação.


---


**5.0 Análise de Modos de Transmissão**

O modo de transmissão refere-se à maneira como os bits de informação são enviados através do canal de comunicação. A escolha entre enviar múltiplos bits simultaneamente ou um de cada vez define uma relação fundamental entre velocidade de transmissão, custo do cabeamento e complexidade da interconexão física.

**5.1 Transmissão Paralela**

Na transmissão paralela, um conjunto de bits (como um byte de 8 bits) é enviado simultaneamente através de várias vias ou fios condutores. Embora ofereça altíssima taxa de transferência em curtas distâncias, é impraticável em ambientes industriais devido ao alto custo do cabeamento e à suscetibilidade a ruído (crosstalk) e desalinhamento de clock (skew) em cabos longos.

**5.2 Transmissão Serial**

Na transmissão serial, os bits são enviados um após o outro, em sequência, pelo mesmo meio físico. Este método é o padrão para praticamente todas as redes industriais.

* Vantagens em Aplicações Industriais:
  * Economia na Interconexão: Requer menos fios, resultando em cabos mais simples, de menor custo e mais robustos.
  * Maior Velocidade em Longas Distâncias: Surpreendentemente, em longas distâncias comuns no chão de fábrica, a transmissão serial atinge velocidades superiores, pois é imune aos problemas de ruído (crosstalk) e desalinhamento de clock (skew) que degradam sinais paralelos.

A transmissão de bits, seja ela serial ou paralela, requer um mecanismo de sincronização para que o receptor possa interpretar o fluxo de dados corretamente.


---


**6.0 Análise de Sincronização de Bits**

Para que o dispositivo receptor interprete corretamente um fluxo de dados recebido, ele precisa saber exatamente quando cada bit começa e termina. A sincronização de bits é o mecanismo que estabelece um acordo sobre o tempo de cada bit. Este alinhamento temporal é alcançado através de métodos síncronos ou assíncronos.

**6.1 Transmissão Síncrona**

Na transmissão síncrona, um sinal de temporização, conhecido como clock, é enviado por um circuito separado, paralelamente ao sinal de dados. Cada pulso do sinal de clock marca o intervalo de tempo exato de um bit, garantindo uma sincronização perfeita. Este método é altamente eficiente para a transferência de grandes blocos de dados, mas o circuito de clock adicional aumenta o custo e a complexidade do cabeamento.

**6.2 Transmissão Assíncrona**

A transmissão assíncrona não utiliza um sinal de clock externo. Em vez disso, a sincronização é feita por caractere ou byte. Cada bloco de dados é enquadrado por um "bit de início" (start bit) e um ou mais "bits de parada" (stop bits). Opcionalmente, um bit de paridade pode ser incluído no quadro para detecção de erros básicos. Este método, associado ao conceito de Baud rate (taxa de símbolos por segundo), é mais simples e barato de implementar, sendo ideal para comunicação intermitente, mas o overhead dos bits de enquadramento reduz a taxa de transferência efetiva de dados.

Além da sincronização, a direcionalidade do fluxo de dados é outra característica fundamental que define a comunicação.


---


**7.0 Análise de Modos de Operação**

Os modos de operação classificam a comunicação com base na direcionalidade do fluxo de informações entre dois dispositivos. Eles determinam se a transmissão pode ocorrer em um ou em ambos os sentidos e, no segundo caso, se essa comunicação bidirecional pode ser simultânea.

Em redes maiores, com múltiplos caminhos possíveis, a forma como as conexões são estabelecidas e os dados são roteados define o tipo de comutação utilizado.


---


**8.0 Análise de Tipos de Comutação**

Para que os dados possam atravessar uma rede composta por múltiplos nós e caminhos, são necessárias estratégias para estabelecer rotas entre a origem e o destino. A comutação é o processo que gerencia esse roteamento. As duas principais abordagens são a comutação de circuitos e a comutação de pacotes.

**8.1 Comutação de Circuitos**

A comutação de circuitos é um método onde uma conexão física dedicada e exclusiva é estabelecida entre a origem e o destino antes do início da transferência de dados. Este circuito permanece ativo durante toda a sessão, garantindo uma taxa de transmissão constante e latência mínima. Embora ideal para dados sensíveis ao tempo, como voz, é ineficiente para o tráfego de dados típico, pois a largura de banda fica alocada mesmo durante os períodos de silêncio.

**8.2 Comutação de Pacotes**

Na comutação de pacotes, a mensagem original é dividida em blocos menores, chamados pacotes. Cada pacote contém informações de endereçamento e é enviado pela rede de forma independente, podendo seguir rotas diferentes até o destino, onde a mensagem é reconstruída. Esta abordagem, base da Internet e das redes Ethernet industriais, permite um uso altamente eficiente dos recursos da rede. No entanto, pode introduzir variações na latência (jitter), o que representa um desafio de engenharia para aplicações de controle em tempo real.

Esta análise completa as principais categorias de classificação que definem a arquitetura de uma rede.


---


É crucial entender que essas categorias não são mutuamente exclusivas; pelo contrário, elas formam um conjunto de características que, quando combinadas, definem a arquitetura completa de uma rede industrial específica. O domínio deste framework de classificação é, portanto, essencial para que engenheiros e arquitetos de sistemas possam projetar, implementar e otimizar soluções de rede que atendam com precisão aos rigorosos requisitos de desempenho, custo e confiabilidade exigidos pelas modernas aplicações de automação industrial.


---