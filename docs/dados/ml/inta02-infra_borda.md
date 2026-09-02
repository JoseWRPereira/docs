---
title: 02 - Infraestrutura de borda
icon: fontawesome/solid/border-top-left
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---

SLTINTA - [Ementa](../../ifsp-slt/dados/sltinta_ementa.md) - [Plano de Aula](../../ifsp-slt/dados/sltinta_plano_aula.md)

---


#

#

## Infraestrutura de Borda e Ingestão de Dados

A estruturação da **Infraestrutura de Borda e Engenharia de Ingestão de Dados**, estabelecendo a base física e lógica necessária para capturar a telemetria da planta siderúrgica e enviá-la ao ecossistema analítico sem perda de informação. 


<!--No contexto do **Caminho 2 (Arduino Uno + Gateway Python via USB/Serial)**, a ementa de engenharia é desmembrada em **três pilares teóricos** fundamentais:-->

---


### Pilar 1: Arquitetura de Dispositivos de Borda (Sistemas Embarcados com Recursos Restritos)

Os melhores microcontroladores (MCUs) para aplicações de computação de borda (especialmente voltados para **TinyML**) variam de acordo com as restrições de consumo de energia, custo, poder de processamento e interfaces de sensores necessárias para o projeto. 

É importante destacar que **microcontroladores são significativamente diferentes de Computadores de Placa Única (SBCs, como o Raspberry Pi 3 ou 4)**: enquanto os SBCs funcionam como computadores completos com sistemas operacionais robustos (como Linux) e consomem centenas de miliwatts, os microcontroladores são dedicados a uma única aplicação, não rodam sistemas operacionais complexos e operam com baixíssimo consumo de energia (na faixa de miliwatts ou microwatts). Isso permite que fiquem ativos por semanas, meses ou até anos com uma única bateria de moeda.

Abaixo estão os modelos mais destacados e recomendados para desenvolvimento na borda:

### 1. Arduino Nano 33 BLE Sense

*   **Por que é um dos melhores:** É amplamente recomendado pelas fontes como a **placa de desenvolvimento ideal para experimentar e criar aplicações práticas de TinyML**.
*   **Especificações:** Equipado com o processador **nRF52840** da Nordic ( clock de 64 MHz, 256 kB de RAM (SRAM) e 1 MB de memória flash).
*   **Diferencial:** Possui uma **rica gama de sensores embutidos** diretamente na placa (microfone, acelerômetro/giroscópio/magnetômetro de 9 eixos, sensores de temperatura, umidade, pressão barométrica, proximidade, cor e brilho). Isso permite coletar dados e realizar inferências de IA (como reconhecimento de comandos de voz ou gestos) localmente sem precisar de fiação ou circuitos adicionais.

### 2. ESP32 (Espressif)

*   **Por que é um dos melhores:** É uma das opções de **baixo custo mais populares e consolidadas no mercado**, amplamente utilizada na indústria para conectar sensores físicos à rede.
*   **Especificações:** Chips como o **ESP32-D0WD** operam com clock de 240 MHz, 520 kB de RAM (SRAM) e 4 MB de flash. Modelos como o **ESP-32-S3** e placas como o **ESP32-DevKitC** também são amplamente adotados no ecossistema de borda.
*   **Diferencial:** Possui conectividade **Wi-Fi e Bluetooth (BLE)** nativa. Em projetos de manutenção preditiva e IoT industrial, ele é muito usado para ler portas analógicas/digitais, calibrar as variáveis de sensores e estruturá-las em formato JSON para transmissão de rede via protocolo leve como o **MQTT**.

### 3. SparkFun Edge (e Edge 2)

*   **Por que é um dos melhores:** É um hardware de baixíssimo custo (cerca de US\$ 15) projetado especificamente como uma plataforma dedicada para machine learning em dispositivos de baixo consumo.
*   **Especificações:** Equipado com o processador **Ambiq Apollo3** (núcleo ARM Cortex-M4), que se destaca pela sua excelente eficiência energética. No modelo com módulo ArtemisV1, possui clock de 48 MHz, 384 kB de RAM e 1 MB de memória flash.
*   **Diferencial:** Focado em eficiência de energia extrema. Possui microfones integrados e acelerômetro de fábrica para detecção local de áudio e movimento.

### 4. Himax WE-I Plus EVB

*   **Por que é um dos melhores:** Destaca-se em aplicações que exigem processamento de sinais mais robustos na borda, como classificação de imagens e visão computacional básica.
*   **Especificações:** Conta com um processador **DSP EM9D de 32 bits rodando a 400 MHz**, acompanhado de 2 MB de memória RAM e 2 MB de flash.
*   **Diferencial:** Já vem integrado com acelerômetro, microfone e uma **câmera digital**, facilitando a implementação de algoritmos de detecção visual local (como "Visual Wake Words").

### 5. ST Microelectronics STM32F746G Discovery Kit

*   **Por que é um dos melhores:** É uma plataforma de desenvolvimento baseada em um núcleo **ARM Cortex-M7** bastante poderoso para a categoria.
*   **Especificações:** Roda o **Mbed OS**, um sistema operacional de tempo real projetado para facilitar o desenvolvimento embarcado.
*   **Diferencial:** Vem integrado com uma **tela LCD acoplada**, o que permite desenhar gráficos, animações e plotar resultados de predições de inteligência artificial em tempo real diretamente no dispositivo.

### 6. Raspberry Pi Pico
*   **Por que é um dos melhores:** É um microcontrolador extremamente popular e acessível, listado nas fontes como um dos dispositivos suportados para execução de modelos comprimidos de TinyML.

### 7. Arduino


O **Arduino Uno** (baseado no microcontrolador ATmega328P) é uma lenda da prototipagem eletrônica, mas quando o assunto é **computação de borda avançada (Edge AI) e TinyML**, ele apresenta sérias limitações técnicas que praticamente inviabilizam seu uso para esse fim. 

Abaixo estão detalhadas as vantagens e desvantagens do Arduino Uno para aplicações de inteligência artificial de borda, comparando-o com placas modernas de 32 bits recomendadas pelas fontes (como o **Arduino Nano 33 BLE Sense** ou o **ESP32**):


#### Vantagens

*   **Baixo Custo e Ubiquidade:** O microcontrolador do Arduino Uno é extremamente barato e amplamente difundido no mercado. Sua proposta de substituir circuitos analógicos e eletromecânicos tradicionais por lógica baseada em software é excelente para automação básica em brinquedos ou eletrodomésticos.
*   **Curva de Aprendizado Suave:** Graças ao ecossistema unificado da **Arduino IDE**, o Uno é excelente para estudantes darem os primeiros passos na programação de entradas e saídas digitais ou leituras analógicas básicas (como ler sensores físicos).
*   **Ausência de Sistema Operacional:** Assim como outros microcontroladores, o Uno não possui um sistema operacional (como Linux). Isso simplifica o modelo mental do desenvolvedor, pois o programa roda em um loop infinito sem sofrer interrupções de processos concorrentes ou necessitar de gerenciamento complexo de memória dinâmica (*malloc*).


#### Desvantagens (Os Impedimentos Técnicos para IA)

*   **Incompatibilidade de Arquitetura (8-bit vs. 32-bit):** O **TensorFlow Lite para Microcontroladores** (runtime padrão para executar inteligência de máquina na borda) **requer obrigatoriamente uma plataforma de 32 bits** para operar (como a arquitetura ARM Cortex-M). O Arduino Uno opera em uma arquitetura de **8 bits** (AVR ATmega328P), impossibilitando a compilação e execução direta do framework do Google.
*   **Memória RAM Extremamente Insuficiente:** O Arduino Uno possui míseros **2 kB de memória RAM** (SRAM). O core básico do runtime do TensorFlow Lite Micro sozinho ocupa cerca de **16 kB** (em um processador ARM Cortex-M3), o que representa **8 vezes mais do que toda a RAM disponível no Uno**. Em comparação, placas de TinyML possuem entre **256 kB** (Nano 33 BLE Sense) e **520 kB** (ESP32) de RAM.
*   **Armazenamento Flash Altamente Limitado:** O Uno conta com apenas **32 kB de memória Flash** para guardar o programa. Embora um modelo matemático simples de onda senoidal ocupe cerca de **2,5 kB**, modelos reais de processamento de sinais (como classificação de áudio de 1 segundo) exigem no mínimo **136 kB** de espaço, enquanto modelos de imagem superam facilmente **5 MB**. 
*   **Poder de Processamento Reduzido (Clock Speed):** O Uno funciona a **16 MHz**, uma frequência muito baixa se comparada aos **64 MHz** do Nano 33 BLE Sense, **240 MHz** do ESP32 ou aos **400 MHz** do Himax WE-I Plus. Essa velocidade lenta impede que o processador execute os milhões de cálculos de multiplicação de matrizes exigidos por redes neurais em tempo real.
*   **Falta de Sensores Integrados na Placa:** O Uno exige que você monte circuitos complexos na protoboard para conectar sensores externos. Já placas TinyML dedicadas, como o **Nano 33 BLE Sense**, trazem embutidos de fábrica microfone, acelerômetro, giroscópio, termômetro e barômetro, permitindo que você colete e analise dados locais imediatamente sem fios extras.

#### Mega e Due

Embora o **Arduino Mega seja completamente inviável** por sua arquitetura de 8 bits e memória extremamente baixa (8 KB SRAM), o **Arduino Due é arquitetonicamente compatível** por possuir um núcleo ARM de 32 bits (Cortex-M3). No entanto, o Due possui sérias limitações práticas devido aos seus restritivos 96 KB de SRAM e à falta de sensores embutidos, o que restringe seu uso apenas a modelos matemáticos rudimentares ou simulações básicas.

**Principais temas observados:**

1. **A Barreira Técnica dos 8 bits:** Placas baseadas na arquitetura AVR de 8 bits (como o Arduino Uno e Mega) são incompatíveis com os frameworks de inferência modernos (como o TensorFlow Lite para Microcontroladores), que exigem instruções de 32 bits e buffers de memória muito superiores à capacidade total desses chips.
2. **Arduino Due e o Limbo do TinyML:** O chip SAM3X8E de 32 bits do Due atende às especificações básicas de arquitetura do interpretador TFLite Micro, mas seus 96 KB de SRAM impossibilitam a execução de modelos práticos de áudio (reconhecimento de voz) ou visão (detecção de pessoas).
3. **Hardware Padrão Moderno:** Dispositivos contemporâneos de desenvolvimento para TinyML (como o Nano 33 BLE Sense ou a família ESP32) estabeleceram um piso mínimo de 256 KB a 520 KB de SRAM e uma rica gama de sensores integrados de fábrica, tornando obsoletos os microcontroladores mais antigos para tarefas de IA local.


---

### Pilar 2: Conversão Analógico-Digital (ADC) e Calibração Física de Sensores

Os fenômenos dinâmicos da máquina CNC (vibração mecânica e aquecimento do cabeçote) são medidos por transdutores que geram sinais elétricos analógicos de tensão contínua. O pilar do ADC estuda o mapeamento matemático desses níveis elétricos para o domínio digital discretizado:

*   **Resolução e Quantização:** Um conversor ADC que possui uma resolução de **10 bits** significa que o intervalo de tensão de entrada (tipicamente \(0\) a \(5\text{ V}\)) é mapeado em uma escala discreta de \(2^{10} = 1024\) níveis (valores inteiros de \(0\) a \(1023\)). A menor variação de tensão detectável (resolução do degrau de quantização, \(\Delta V\)) é expressa por:
    \\[\Delta V = \frac{V_{ref}}{2^N - 1} = \frac{5\text{ V}}{1023} \approx 4,88\text{ mV}\\]
    Para conversores, cuja resolução do ADC é de **12 bits** (\(0\) a \(4095\)) operando sob referência de \(3,3\text{ V}\), a sensibilidade elétrica é significativamente superior:
    \\[\Delta V = \frac{3,3\text{ V}}{4095} \approx 0,80\text{ mV}\\]
*   **Mapeamento e Calibração Linear:** A conversão do valor digital lido pelo ADC (\(x\)) para a grandeza física real (\(y\), em \(^\circ\text{C}\) ou \(\text{mm/s}\)) é dada pela aplicação da equação linear de calibração:
    \\[y = a \cdot x + b\\]
    Onde \(a\) é o ganho da curva do sensor (sensibilidade física por Volt) e \(b\) é o deslocamento de zero (*offset*).
*   **Filtragem de Ruído de Alta Frequência:** O ambiente fabril é eletromagneticamente ruidoso. Leituras instantâneas do ADC podem sofrer flutuações espúrias. Para mitigar esse efeito, aplica-se uma **filtragem de média móvel na borda**. O firmware acumula \(k\) amostras consecutivas (ex: \(k=20\)) em uma janela temporal rápida e calcula o valor médio estável, eliminando picos de ruído elétrico antes da transmissão de dados:
    \\[\bar{X} = \frac{1}{k} \sum_{i=1}^{k} X_i\\]

---

### Pilar 3: Serialização e Protocolos de Ingestão de Dados (UART, JSON, MQTT e SQLite)

A escolha entre formatos de serialização de dados tem papéis fundamentais em  diferentes etapas de um projeto de dados e inteligência artificial, e depende das restrições e objetivos do sistema. 

Os formatos mais usados e os motivos de sua adoção são apresentados abaixo.


#### 1. JSON (JavaScript Object Notation)

O JSON é o formato mais utilizado para a **transmissão de dados em tempo real, APIs e arquiteturas de IoT (computação de borda)**. Por exemplo, o microcontrolador ESP32 realiza a leitura de dados brutos e os serializa em um objeto JSON contendo as chaves `temperatura`, `vibracao` e `rpm` antes de transmiti-los via MQTT.

*   **Por que é usado:**
    *   **Suporte a estruturas complexas e aninhadas:** Ao contrário do CSV, o JSON permite representar dados hierárquicos, listas e objetos aninhados (semelhantes aos dicionários em Python).
    *   **Independência de linguagem:** É um padrão de texto simples que pode ser facilmente interpretado por praticamente qualquer linguagem de programação (como C++ na placa de borda e Python no servidor de IA), garantindo que sistemas heterogêneos conversem sem problemas.
    *   **Ideal para sistemas distribuídos:** É o formato padrão na Indústria 4.0 para o tráfego de dados leves e estruturados em barramentos de mensageria assíncrona, apresentando enorme vantagem sobre strings de texto puro.


Para ilustrar e comparar diretamente os formatos, vamos utilizar o mesmo conjunto de 3 amostras de telemetria de sensores industriais (medindo as variáveis físicas temperatura, vibracao, rpm e a classificação de falha).
As amostras lógicas que utilizaremos são:

- Amostra 1: Temperatura de 65.0 °C, Vibração de 2.5 mm/s, RPM de 1800, Sem falha (0).
- Amostra 2: Temperatura de 85.5 °C, Vibração de 4.8 mm/s, RPM de 1200, Com falha (1).
- Amostra 3: Temperatura de 62.1 °C, Vibração de 1.8 mm/s, RPM de 1750, Sem falha (0).

```json title="JSON"
[
  {
    "temperatura": 65.0,
    "vibracao": 2.5,
    "rpm": 1800,
    "falha": 0
  },
  {
    "temperatura": 85.5,
    "vibracao": 4.8,
    "rpm": 1200,
    "falha": 1
  },
  {
    "temperatura": 62.1,
    "vibracao": 1.8,
    "rpm": 1750,
    "falha": 0
  }
]
```

---

#### 2. CSV (Comma-Separated Values)

O CSV é o formato soberano na **fase de análise exploratória, armazenamento de datasets tabulares e treinamento de modelos de Aprendizado de Máquina**.

*   **Por que é usado:**
    *   **Extrema simplicidade:** É uma representação plana de linhas e colunas muito fácil de ser importada para ambientes de análise através de bibliotecas populares como o Pandas (`pd.read_csv()`).
    *   **Interoperabilidade humana:** Pode ser aberto e editado de forma nativa em qualquer software de planilha eletrônica (como o Excel) ou visualizadores básicos de texto, facilitando a auditoria rápida dos dados.
*   **Limitações do CSV:**
    *   **Ineficiência de espaço:** Arquivos CSV ocupam substancialmente mais espaço físico em disco se comparados a formatos binários.
    *   **Incompatibilidade com dados complexos:** O CSV lida mal com estruturas que não sejam estritamente bidimensionais/tabulares, tornando-se inadequado para armazenar dados complexos como áudio, imagens ou listas de listas.

```csv title="CSV"
temperatura,vibracao,rpm,falha
65.0,2.5,1800,0
85.5,4.8,1200,1
62.1,1.8,1750,0
```

---

#### 3. TFRecord e Protocol Buffers (O formato de alta performance)

Para além do JSON e CSV, quando o volume de dados na IA escala significativamente (como em pipelines de Deep Learning), utiliza-se o formato **TFRecord** (baseado em *Protocol Buffers* ou *protobufs* do Google).

*   **Por que é usado:**
    *   **Eficiência de carregamento:** CSVs e JSONs exigem muito processamento de parsing de texto em tempo de execução. O TFRecord armazena os dados em um formato binário compacto de tamanho variável que pode ser lido de forma sequencial e extremamente rápida pela GPU. Ele é adotado especificamente quando o gargalo de tempo do treinamento da IA passa a ser a velocidade de leitura do disco rígido.


O TFRecord é um formato de arquivo binário otimizado para o TensorFlow. Ele não é guardado como texto legível. Em vez disso, cada registro do arquivo armazena um Protocol Buffer serializado do tipo tf.train.Example
.
A. Estrutura lógica do primeiro registro (tf.train.Example):
Por baixo dos panos, o TensorFlow enxerga a primeira amostra organizada sob este esquema de tipos de dados (FloatList para decimais e Int64List para inteiros):

```tfrecord title="TFRecord adaptado"
features {
  feature {
    key: "temperatura"
    value { float_list { value: 65.0 } }
  }
  feature {
    key: "vibracao"
    value { float_list { value: 2.5 } }
  }
  feature {
    key: "rpm"
    value { int64_list { value: 1800 } }
  }
  feature {
    key: "falha"
    value { int64_list { value: 0 } }
  }
}
```



**Resumo Prático**

**JSON** é excelente para a comunicação em tempo real entre a máquina na borda e o servidor, pois protege a estrutura dos dados individuais no tráfego de rede.

**CSV** é o padrão para a ciência de dados offline, permitindo que você analise gigabytes de logs históricos acumulados e treine seus modelos com alta performance no Pandas e Scikit-Learn.









---
<!--
Uma vez calificados na borda, os dados precisam ser envelopados e transportados de forma íntegra e legível através das camadas da arquitetura de dados:

```
+------------------+         USB (Serial)         +------------------+         Rede (Wi-Fi)         +-----------------+
|   Arduino Uno    |  -------------------------   |  Gateway Python  |  --------------------------- |   Broker MQTT   |
| (Borda Primária) |  `{"temp":65.2,"vib":1.5}`   |  (Borda Secundária) |  Callback on_message()    |    (HiveMQ)     |
+------------------+                              +------------------+                              +-----------------+
                                                           |
                                                           | SQL INSERT
                                                           v
                                                  +------------------+
                                                  |  Banco SQLite    |
                                                  |   (Histórico)    |
                                                  +------------------+
```

*   **Serialização Estruturada em JSON:** Transmitir variáveis em formatos proprietários ou strings de texto separadas por vírgula cria um acoplamento rígido inaceitável em engenharia de sistemas. O formato **JSON** (*JavaScript Object Notation*) padroniza o intercâmbio no esquema chave-valor, permitindo que os metadados trafeguem autoexplicativos pela rede.
*   **Comunicação Assíncrona via UART:** O envio do JSON pelo cabo USB utiliza a porta **UART** (*Universal Asynchronous Receiver-Transmitter*), onde os dados são transmitidos bit a bit em uma taxa pré-configurada de **115200 bps** (Baud Rate).
    *   *Temporização Não-Bloqueante:* O firmware deve evitar o uso da função `delay()`, pois ela paralisa o clock da CPU e impede o tratamento de outras rotinas de controle. Utiliza-se o padrão de temporização assíncrona baseado em **`millis()`**, comparando cronologicamente os ciclos da máquina:
        \\[\Delta t_{ciclo} = t_{atual} - t_{anterior} \ge T_{amostragem}\\]
*   **Ingestão MQTT (*Publish/Subscribe*):** O script Python no gateway atua como um coordenador assíncrono. Ele decodifica o fluxo serial e publica os payloads em um **Broker MQTT** utilizando o protocolo leve de mensagens sob IP. A arquitetura assíncrona baseada em *callbacks* (funções de retorno como `on_message()`) garante que o sistema de visualização ou IA não precise polling constante, consumindo banda de rede apenas quando novas amostras de sensores de fato chegam.
*   **Persistência Histórica no SQLite:** Para viabilizar o posterior treinamento de modelos supervisionados (SVM, LSTMs), os fluxos de rede voláteis devem ser consolidados cronologicamente. O gateway Python executa comandos `INSERT` em um banco de dados relacional leve **SQLite**, registrando cada leitura com um carimbo de data e hora automático (*Timestamp*). Essa base limpa e estruturada elimina as inconsistências temporais e serve como fundação de engenharia para toda a modelagem de Inteligência Artificial subsequente.
-->

---

### Referências

AHELEROFF, S. et al. A Digital Twin-Driven Predictive Maintenance Architecture for IoT-Enabled Manufacturing. **Advanced Engineering Informatics**, v. 45, p. 101102, 2020. (Aheleroff et al., 2020).

ARENA, F. et al. An IoT-Based Predictive Maintenance Architecture for Industrial Equipment. **Sensors**, v. 22, n. 2, p. 485, 2022. (Arena et al., 2022).

GARCIA, G.; ALBALADEJO, C.; MOLINA, J. M. Low-Cost IoT Sensor Node for Predictive Maintenance in Industrial Environments. **Electronics**, v. 10, n. 11, p. 1289, 2021. (Garcia; Albaladejo; Molina, 2021).

GÉRON, Aurélien. **Mãos à obra: aprendizado de máquina com Scikit-Learn, Keras & TensorFlow**: conceitos, ferramentas e técnicas para a construção de sistemas inteligentes. 2. ed. [S. l.]: Alta Books, 2021.

LET'S DATA. **CRISP-DM**: a melhor metodologia para projetos de Data Science. [S. l.]: Youtube, 2021. Disponível em: https://www.youtube.com/watch?v=fV7i6U-0Q7M. Acesso em: 20 ago. 2026.

POD ACADEMY | DATA & ANALYTICS. **Aprenda a metodologia CRISP-DM para tomada de decisão data-driven [Webinar PoD Academy]**. [S. l.]: Youtube, 2023. Disponível em: https://www.youtube.com/watch?v=C7QYm0fL2vA. Acesso em: 20 ago. 2026.

RASCHKA, Sebastian. **Python machine learning**. Birmingham: Packt Publishing, 2015.

SANTOS, Bruno J. et al. Electroencephalogram Signal Acquisition System with Machine Learning for Robotic Prosthesis Control: In Vivo Dataset. **Artificial Intelligence and Applications**, [S. l.], v. 00, n. 00, p. 1-22, 2025. DOI: 10.47852/bonviewAIA52024252.

WARDEN, Pete; SITUNAYAKE, Daniel. **TinyML**: machine learning with TensorFlow Lite on Arduino and ultra-low-power microcontrollers. Sebastopol: O'Reilly Media, 2019.

---

Material produzido com auxílio de `NotebookLM` e `Gemini`

---

---

