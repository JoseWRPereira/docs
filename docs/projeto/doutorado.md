---
title: Doutorado
icon: fontawesome/solid/chalkboard-user
author:
 - José W. R. Pereira
tags:
 - Doutorado
 - Unicamp
 - UFABC
---




# Proposta de Projeto de Doutorado

# MQCA: um Modelo Quantitativo de Custo-Benefício para Aprendizado Contínuo em TinyML e Co-Design de Extensões RISC-V, Validado Fora da Amostra

**Área:** Arquitetura de Computadores, Sistemas Embarcados e Inteligência Artificial


---

## 1. Síntese da Proposta

Dispositivos TinyML industriais operam por anos em ambientes que mudam: o processo se altera, os sensores envelhecem, as condições operacionais variam. O paradigma *train-once-deploy-forever* degrada com o tempo, e o aprendizado contínuo (AC) local é a alternativa natural, mas custa energia, memória e ciclos em um dispositivo que tem pouco de cada.

O projetista enfrenta duas decisões acopladas: **(a) quando adaptar localmente compensa**, e **(b) que suporte arquitetural justifica o seu custo**. Hoje elas são resolvidas por implementação e medição caso a caso.

A literatura recente já oferece peças desse quebra-cabeça: plataformas RISC-V para AC, rooflines de energia para treino, preditores de energia de treino on-device, formalizações do custo de retreinar e fluxos de co-design com unidades funcionais customizadas. O que **não foi encontrado** na triagem preliminar é um modelo que, ao mesmo tempo:

1. decomponha o custo de uma atualização adaptativa em operações, acessos por nível de memória e movimento de dados, de forma **interpretável e independente de tecnologia**;
2. relacione esse custo ao **ganho adaptativo sob um cenário de drift definido**, derivando uma condição de *break-even*;
3. seja **validado fora da amostra** (por configuração e por família de algoritmo), em mais de uma plataforma;
4. seja **usado para escolher extensões RISC-V** e comparado, sob o mesmo orçamento de sínteses, com exploração black-box do espaço de projeto.

Esta tese propõe o **MQCA (Modelo Quantitativo de Co-Design Adaptativo)** com essa integração e a entrega de um **benchmark aberto de aprendizado contínuo com drift para TinyML**, cuja ausência é apontada pela literatura recente. A detecção de anomalias em motores elétricos é o ambiente de validação, não o objetivo científico.

## 2. Contextualização

O aprendizado contínuo em dispositivos de borda avançou em frentes que raramente se encontram:

- **Treino e adaptação on-device em MCUs e plataformas RISC-V**, incluindo plataformas de AC com latent replay, análises de trade-off memória-latência-acurácia e estudos de vida útil de bateria em função da taxa de adaptação.
- **Modelagem de custo**: rooflines de tempo e energia (inicialmente para HPC e GPUs, depois para aceleradores de borda e treino) e preditores de energia de treino por camada.
- **Decisão de retreinar**: formalizações do trade-off entre obsolescência do modelo e custo de retreinamento, majoritariamente fora do contexto embarcado.
- **Co-design de hardware**: extensões ISA para treino em baixa precisão, SIMD FP16 para ODL em RISC-V e frameworks de exploração com CFUs sobre softcores em FPGA.

Fenômenos como concept drift, mudanças ambientais, envelhecimento de sensores e alterações operacionais degradam modelos estáticos. Segundo um survey de 2026 sobre aprendizado on-device em TinyML (cerca de 70 trabalhos), trabalhos aplicados nos regimes de concept drift e AC são quase ausentes, e o campo carece de benchmarks realistas para esses regimes. Entre as direções futuras apontadas estão frameworks de avaliação padronizados e hardware dedicado a ODL.

## 3. Posicionamento e Lacuna Científica

### 3.1 Trabalhos relacionados (triagem preliminar)

| Linha de trabalho (exemplos) | O que cobre | O que o MQCA acrescenta |
|---|---|---|
| Plataformas RISC-V para AC (por exemplo, o node RISC-V com latent replay e o SoC VEGA) | Viabilidade do AC no extreme-edge; trade-offs memória-latência-acurácia; vida de bateria versus taxa de adaptação | Modelo preditivo geral, com ganho sob drift e custo arquitetural no mesmo formalismo |
| Rooflines de energia (Choi et al.; Pagoda, para treino em Jetson) | Limites de tempo e energia por intensidade aritmética | Adaptação ao regime MCU/AC e inclusão do ganho adaptativo |
| Preditores de energia de treino on-device (THOR; otimização em tempo de projeto para aprendizado intermitente em MCUs) | Predição de energia por camada, inclusive backward; MAPE por camada na casa de dezenas de pontos percentuais em MCUs | Modelo interpretável por operação/memória/movimento, validação por família e extensões ISA como parâmetro |
| Retreinamento com custo (CARA; DriftGuard) | Trade-off entre obsolescência e custo de retreinar, em contexto não embarcado | Condição de *break-even* com custo arquitetural embarcado |
| Co-design e DSE (CFU Playground com Vizier) | Fluxo de co-design em softcores RISC-V/FPGA; DSE black-box | Camada preditiva que reduz o número de sínteses para chegar perto do ótimo |
| Extensões ISA para treino (MiniFloat-NN/ExSdotp; SIMD FP16 em GAP9/PULP-TrainLib) | Suporte a treino em baixa precisão em RISC-V | Seleção de extensões **guiada por modelo** para cargas de adaptação sob drift |
| Estudos de co-design com adaptação sob orçamento (por exemplo, um estudo de simulação de 2026 em quantização, esparsidade e adaptação) | Trade-offs acurácia-latência-energia-memória por simulação | Validação em hardware real, em duas plataformas, com previsão fora da amostra |
| ODL em máquinas rotativas (OS-ELM/ONLAD, Keio) | Detecção de anomalias com aprendizado on-device e FPGA, inclusive sob drift simulado | Uso do caso de uso como veículo de validação, não como contribuição |
| Benchmarks (MLPerf Tiny) | Latência, energia e acurácia de **inferência** | Benchmark de **adaptação sob drift** |

*O conteúdo de cada linha é preliminar e será consolidado na revisão sistemática (seção 9).*

### 3.2 Alegação de originalidade (reformulada)

A tese **não** alega ser o primeiro modelo de custo de treino, nem a primeira condição de *break-even* para retreinamento, nem a primeira extensão RISC-V para treino. A contribuição original proposta é:

> Um modelo interpretável e independente de tecnologia que **acopla ganho adaptativo sob drift a custo arquitetural em TinyML**, **validado fora da amostra** em mais de uma plataforma, **usado para decidir quando adaptar e que extensão RISC-V implementar**, com desempenho comparado a baselines que reproduzem o estado da arte (preditores por camada, gatilhos de retreinamento com custo e exploração black-box do espaço de projeto), acompanhado de um **benchmark aberto de AC com drift**.

## 4. Problema, Questão e Hipótese Central

**Problema.** Como prever, a partir de grandezas independentes de tecnologia, quanto custa e quanto rende uma estratégia de adaptação contínua em um sistema TinyML restrito, e como usar essa previsão para decidir quando adaptar e que suporte arquitetural implementar?

**Questão central.** Um modelo analítico de poucos parâmetros supera, fora da amostra, os preditores e as estratégias de exploração do estado da arte na previsão de custo adaptativo, na decisão de adaptar e na escolha de extensões RISC-V?

**Hipótese central.** Sim: o custo de adaptação é bem descrito por operações por tipo, acessos por nível de memória e bytes movimentados, e o ganho adaptativo por uma função do cenário de drift. Combinados, produzem previsões com erro inferior ao dos baselines, decisões de *break-even* concordantes com a medição e escolhas de co-design de baixo *regret* com menos sínteses que a exploração black-box.

## 5. O Modelo Proposto (MQCA)

### 5.1 Estrutura

Para uma configuração `c = (algoritmo, estratégia de adaptação, precisão numérica, extensão arquitetural)` e um cenário de drift `D = (tipo, severidade, frequência)`:

```
Custo de uma atualização
  E_upd(c) = Σ_k n_k(c)·e_k(c)         # operações do tipo k (MAC, soma, ativação, ...)
           + Σ_l a_l(c)·e_l            # acessos ao nível de memória l (regs, SRAM, flash/ext.)
           + b(c)·e_mov                # bytes movimentados
           + E_fixo                    # overhead de controle/estática por atualização

Ganho adaptativo acumulado sob o cenário D, no horizonte T
  G(c, D) = ∫₀ᵀ [ P_adapt(t; c, D) − P_estático(t; D) ] dt
  # P = desempenho de detecção (ex.: F1 ou AUROC) ao longo do tempo;
  # G é a área entre as curvas "com adaptação" e "sem adaptação".

Custo total de adaptação no horizonte T
  E_adapt(c, D) = N_upd(c, D)·E_upd(c) + E_inf_extra(c)

Condição de break-even
  adaptar compensa  ⇔  λ·G(c, D) > E_adapt(c, D)
  # λ converte desempenho em energia equivalente (custo de falsos alarmes e
  # falhas não detectadas); é parâmetro de aplicação, explicitado e submetido
  # a análise de sensibilidade.
```

Os coeficientes `e_k`, `e_l` e `e_mov` são ajustados por regressão a partir de medições na plataforma-base. O número de parâmetros livres é deliberadamente pequeno (meta: ≤ 8) para preservar a interpretabilidade.

**Relação com trabalhos anteriores.** A decomposição de energia em componentes de computação e de memória, e a ideia de comparar custo e ganho para decidir sobre retreinamento, têm precedentes (rooflines de energia, preditores por camada, CARA). O MQCA os integra no regime TinyML, acrescenta o ganho sob drift como termo de primeira classe e trata a extensão arquitetural como parâmetro (`e_k(c)`, `a_l(c)`), o que permite prever o efeito de uma extensão **antes** de sintetizá-la.

### 5.2 Definição operacional de capacidade adaptativa

- **Recuperação acumulada** `G(c, D)`: área entre as curvas de desempenho com e sem adaptação.
- **Eficiência adaptativa** `η(c, D) = G(c, D) / E_adapt(c, D)`: ganho de desempenho por joule.
- Complementos: tempo de recuperação a 90% do desempenho pré-drift e esquecimento (queda em regimes anteriores).

### 5.3 Uso do modelo para co-design

Dada a caracterização de um algoritmo, o MQCA estima o efeito de uma extensão alterando `e_k` e `a_l` (por exemplo, MAC SIMD int8, acesso fundido a memória, instrução de atualização de protótipo), ranqueia candidatas **antes** da síntese e seleciona a de maior retorno por unidade de área em FPGA. Esse uso é avaliado contra a exploração black-box sob o mesmo orçamento de sínteses (H5).

## 6. Hipóteses (falsificáveis)

Os limiares são valores iniciais, a calibrar no piloto. **Os limiares de H2, H5 e H7 são formulados em relação a baselines que reproduzem o estado da arte**, e não apenas como valores absolutos.

**H1 – Dominância e especificidade das operações críticas.** Em cada família de algoritmos, no máximo 3 kernels respondem por pelo menos 80% dos ciclos e da energia de uma atualização, e o conjunto dominante difere entre as famílias. (Se for idêntico em todas, o resultado é trivial e o MQCA se simplifica, o que é achado negativo relevante.)

**H2 – Previsão do custo adaptativo fora da amostra.** O MQCA, com no máximo 8 parâmetros, prevê a energia por atualização em configurações e famílias **não usadas no ajuste** (leave-one-configuration-out e leave-one-family-out) com MAPE ≤ 15% no **nível de atualização completa**, e reduz o MAPE em pelo menos 2× em relação ao melhor entre os baselines: (a) contagem de MACs; (b) contagem de ciclos; (c) regressão por camada no estilo dos preditores de energia de treino existentes (THOR e similares). O erro é reportado também por camada, para comparação direta com a literatura.

**H3 – Superioridade da adaptação parcial.** A adaptação seletiva (últimas camadas ou apenas protótipos) atinge ≥ 90% da recuperação pós-drift do retreinamento completo com ≤ 30% da energia, em pelo menos dois terços dos cenários de drift.

**H4 – Fronteira de Pareto prevista versus medida.** A fronteira de Pareto prevista pelo MQCA (ganho adaptativo × energia × memória) coincide com a medida: correlação de Spearman ≥ 0,85 entre configurações e hipervolume previsto ≥ 90% do medido.

**H5 – Co-design guiado por modelo versus exploração black-box.** Sob o **mesmo orçamento de sínteses** (K execuções, K a definir no piloto), a extensão escolhida pelo MQCA (i) tem *regret* ≤ 10% em relação à melhor extensão obtida por exploração exaustiva, (ii) supera a seleção feita por otimização black-box (CFU Playground com Vizier) em pelo menos dois terços dos casos, ou atinge o mesmo *regret* com ≤ 50% das sínteses, e (iii) reduz em pelo menos 20% a energia por atualização frente a uma extensão genérica de referência com área em FPGA equivalente.

**H6 – Generalização entre domínios e plataformas.** Em um segundo domínio independente e em uma segunda plataforma, o MQCA mantém MAPE ≤ 25% após **apenas recalibração dos coeficientes**, sem alterar sua estrutura.

**H7 – Decisão de adaptar.** A condição de *break-even* concorda com a decisão ótima medida (adaptar ou não) em pelo menos 85% dos cenários, e o custo total no horizonte `T` é inferior ao de dois baselines: (a) gatilho por limiar de desempenho e (b) gatilho de retreinamento com custo no estilo CARA.

## 7. Objetivos

**Objetivo geral.** Desenvolver e validar fora da amostra um modelo quantitativo de custo-benefício para AC em TinyML, capaz de prever o custo de adaptação, decidir quando adaptar e orientar a escolha de extensões RISC-V, com desempenho superior ao de baselines do estado da arte, e disponibilizar um benchmark aberto de AC com drift.

**Objetivos específicos.**

1. Realizar a revisão sistemática formal (PRISMA) e consolidar o posicionamento (seção 3).
2. Construir uma taxonomia de mecanismos adaptativos organizada por custo-benefício embarcado.
3. Definir formalmente o MQCA e a capacidade adaptativa (seção 5).
4. Construir a instrumentação de energia e ciclos na plataforma principal e na plataforma de transferência.
5. Implementar os baselines do estado da arte (preditor por camada, gatilho com custo, DSE black-box).
6. Caracterizar duas famílias de algoritmos e identificar suas operações críticas (H1).
7. Projetar e implementar extensões RISC-V orientadas pelo MQCA e compará-las com extensões genéricas e com a seleção black-box (H5).
8. Validar a capacidade preditiva e decisória do modelo (H2, H4, H6, H7).
9. Construir e publicar o benchmark e o framework abertos (seção 11).
10. Derivar diretrizes de projeto para plataformas TinyML adaptativas.

## 8. Delimitação Experimental e Metodologia

### 8.1 Escopo

O núcleo da tese compreende **duas famílias** de algoritmos:

- **Família A:** autoencoders compactos, com adaptação completa e parcial, em int8/ponto fixo.
- **Família B:** métodos baseados em protótipos e estatística incremental.

Uma terceira família (por exemplo, OS-ELM) é *stretch goal*, útil também por permitir comparação direta com trabalhos prévios em FPGA.

### 8.2 Domínio principal, dados e *ground truth*

Detecção de anomalias em motores elétricos industriais (vibração e temperatura). O principal risco metodológico é a escassez de dados com drift realista e rótulos confiáveis. A estratégia combina:

1. **Bancada experimental** (própria ou de laboratório parceiro), com falhas induzidas de forma controlada e **drift injetado de forma controlada**: variação de carga e velocidade, variação térmica e envelhecimento de sensor emulado (offset, ganho, ruído);
2. **Conjuntos públicos** de vibração em máquinas rotativas (candidatos a verificar: CWRU, Paderborn, MAFAULDA), com drift sintético documentado;
3. Rótulos de anomalia conhecidos por construção nos experimentos controlados, permitindo calcular F1 e AUROC durante o drift sem inferir rótulos.

### 8.3 Plataformas (duas, para testar transferência)

- **Plataforma principal:** softcore RISC-V em FPGA com extensões customizadas (por exemplo, via CFU), com instrumentação de energia nos trilhos de alimentação e estimativa por atividade.
- **Plataforma de transferência (obrigatória):** um MCU RISC-V comercial (por exemplo, ESP32 em variante RISC-V), usado para **validar o modelo em hardware distinto** da plataforma de calibração (parte de H6).
- **Referência opcional:** STM32 (Arm), apenas para ordem de grandeza.

Como as plataformas diferem em ISA, nó tecnológico e microarquitetura, a comparação usa **métricas independentes de tecnologia** (operações, acessos por nível de memória, bytes movimentados), e os coeficientes de energia são tratados como **parâmetros de tecnologia**, recalibráveis.

**Transferibilidade FPGA → ASIC.** Energia em FPGA não é energia em ASIC. A tese trata isso como limitação explícita, com análise de sensibilidade e, como complemento, projeções que substituem os coeficientes por tabelas de energia por operação de nós ASIC publicados.

### 8.4 Segundo domínio

Para H6, o MQCA é aplicado, **sem alterar sua estrutura**, a um segundo domínio independente (por exemplo, reconhecimento de atividade humana por acelerômetro ou detecção de palavras-chave com drift de locutor/ambiente), tratado como **conjunto de teste do modelo**.

### 8.5 Precisão numérica

A precisão (float32, int8, ponto fixo de largura variável) é variável do espaço de projeto, por afetar a qualidade do treino on-device, a memória e a energia.

### 8.6 Baselines do estado da arte

| Finalidade | Baseline |
|---|---|
| Predição de custo (H2) | Contagem de MACs; contagem de ciclos; regressão linear por camada (estilo THOR e preditores por camada em MCUs); regressão sobre contagens de instruções; modelo caixa-preta (por exemplo, floresta aleatória) como teto de precisão |
| Decisão de adaptar (H7) | Gatilho por limiar de desempenho; gatilho de retreinamento com custo (estilo CARA) |
| Co-design (H5) | Extensão genérica de referência (por exemplo, SIMD int8 genérico); seleção por otimização black-box (CFU Playground com Vizier) com o mesmo orçamento de sínteses; exploração exaustiva como *oracle* |

### 8.7 Fases metodológicas

1. **Revisão sistemática (PRISMA) e taxonomia.**
2. **Plataformas, instrumentação, baselines e coleta de dados** (softcore, MCU RISC-V, bancada, cenários de drift).
3. **Caracterização experimental** (perfilamento, operações dominantes, H1).
4. **Formulação e calibração do MQCA** (v0 no Ano 1, v1 no Ano 2).
5. **Co-design arquitetural** (extensões guiadas pelo modelo versus genéricas e black-box, H5).
6. **Validação fora da amostra, decisão e generalização** (H2, H4, H6, H7).

## 9. Protocolo de Revisão Sistemática (Ano 1)

A triagem preliminar não substitui uma revisão formal. O protocolo será registrado antes da execução e seguirá a estrutura PRISMA.

- **Bases:** IEEE Xplore, ACM Digital Library, Scopus, Web of Science, Springer/Elsevier/MDPI (via portais), mais arXiv e anais de ISCA, MICRO, HPCA, DAC, DATE, ICCAD, MLSys e tinyML Research Symposium. Um acompanhamento mensal de novas submissões será mantido ao longo da tese, pois o campo se move rápido.
- **Strings-base (a refinar):**
  - (`continual learning` OR `on-device learning` OR `on-device training` OR `incremental learning`) AND (`TinyML` OR `microcontroller` OR `embedded`) AND (`energy` OR `latency` OR `memory`);
  - (`energy model` OR `performance model` OR `analytical model` OR `roofline`) AND (`training` OR `fine-tuning`) AND (`edge` OR `microcontroller`);
  - (`RISC-V`) AND (`custom instruction` OR `ISA extension` OR `custom function unit`) AND (`training` OR `learning`);
  - (`concept drift`) AND (`TinyML` OR `microcontroller`) AND (`retraining cost` OR `break-even`).
- **Critérios de inclusão:** alvo em MCU/RISC-V ou arquiteturas de baixo consumo; fase de aprendizado executada ou projetada para o dispositivo; modelo, preditor ou método de decisão de custo explícito.
- **Produtos:** tabela de posicionamento final, taxonomia (C3) e lista de baselines a reproduzir.

## 10. Protocolo de Validação Estatística

- **Fora da amostra:** leave-one-configuration-out e leave-one-family-out; o modelo nunca é avaliado nas configurações usadas no ajuste. Validação adicional em segunda plataforma e segundo domínio.
- **Métricas de predição:** MAPE (por camada e por atualização completa), erro máximo, intervalos de confiança por *bootstrap*.
- **Métricas de decisão:** concordância adaptar/não adaptar (H7), correlação de ranking (Spearman/Kendall), *regret*, hipervolume da fronteira de Pareto.
- **Comparação com baselines:** testes de significância apropriados e tamanhos de efeito; baselines reproduzidos com o mesmo protocolo de dados e medição.
- **Repetições:** múltiplas execuções e sementes por configuração, com intervalos de confiança.
- **Sensibilidade e ablações:** de `λ`, do horizonte `T` e da severidade do drift; contribuição de cada termo do modelo (operações, memória, movimento de dados).
- **Pré-registro:** limiares e análises primárias registrados após o piloto e antes da validação final.

## 11. Métricas e Artefatos Abertos

**Desempenho adaptativo:** F1, AUROC, recuperação acumulada `G`, tempo de recuperação, esquecimento catastrófico.
**Eficiência computacional:** latência, ciclos por atualização e por inferência, *throughput*.
**Recursos:** SRAM, Flash, memória temporária de atualização.
**Energia:** energia por atualização, por inferência e por anomalia detectada; eficiência adaptativa `η`.
**Arquitetura:** *speedup*, eficiência energética, utilização de FPGA (LUTs, FFs, DSPs, BRAM).
**Qualidade do modelo:** MAPE, concordância de decisão, correlação de ranking, *regret*, hipervolume.

**Artefatos abertos (contribuição co-principal):**

- **Benchmark de AC com drift para TinyML** (nome provisório), com cenários de drift documentados, dados de bancada própria quando possível, protocolo de avaliação prequential e métricas de custo e energia. Responde diretamente à lacuna de benchmarks realistas para os regimes de concept drift e AC apontada pela literatura recente, e é um complemento natural de benchmarks de inferência como o MLPerf Tiny.
- **Framework do MQCA** em código aberto (calibração, validação, exploração de espaço de projeto, baselines reproduzidos).
- **Descrições das extensões RISC-V** (CFUs) e fluxos de medição de energia.

## 12. Contribuições Esperadas

**C1 – MQCA validado fora da amostra:** modelo interpretável e independente de tecnologia, com condição de *break-even*.
**C2 – Benchmark aberto de AC com drift para TinyML** e protocolo de avaliação (co-principal).
**C3 – Definição operacional de capacidade adaptativa** (`G`, `η`) e taxonomia de mecanismos adaptativos por custo-benefício.
**C4 – Metodologia de co-design guiada por modelo**, com avaliação contra exploração black-box sob o mesmo orçamento de sínteses.
**C5 – Extensões RISC-V** orientadas pelo modelo, validadas em FPGA.
**C6 – Framework e fluxos abertos** (modelo, baselines e medição).
**C7 – Diretrizes de projeto** para plataformas TinyML adaptativas.

## 13. Cronograma

### Ano 1 – Fundamentos, dados e baselines
- Revisão sistemática formal (PRISMA), taxonomia e tabela de posicionamento;
- MQCA v0 e definição operacional de capacidade adaptativa;
- Softcore base em FPGA e plataforma de transferência instrumentadas;
- Reprodução dos baselines (preditor por camada, gatilho com custo, DSE black-box);
- Bancada/coleta de dados e cenários de drift; estudo piloto para calibrar limiares;
- *Marco:* artigo de revisão/posicionamento e relatório do piloto.

### Ano 2 – Caracterização e modelo
- Caracterização das famílias A e B (H1); MQCA v1 e primeira validação fora da amostra (H2);
- Benchmark v1 e framework abertos;
- *Marco:* artigo do modelo e da caracterização; liberação do benchmark v1.

### Ano 3 – Co-design e generalização
- Extensões guiadas pelo modelo versus genéricas e black-box (H5);
- H3, H4 e H7; transferência para a segunda plataforma e segundo domínio (H6);
- *Marco:* artigo de co-design e extensões RISC-V.

### Ano 4 – Consolidação
- Validação final, sensibilidade e ablações; liberação final dos artefatos;
- Escrita da tese e defesa.

## 14. Riscos e Planos de Contingência

| Risco | Impacto | Mitigação / Plano B |
|---|---|---|
| Percepção de que o MQCA é apenas "roofline + regressão + CARA" | Alto | Foco na integração validada, nos baselines reproduzidos e no benchmark; relatar ganhos relativos (H2, H5, H7) |
| Trabalhos concorrentes surgindo durante a tese (campo muito ativo) | Alto | Monitoramento mensal de preprints; benchmark e artefatos abertos como contribuição resistente a sobreposição |
| O MQCA não supera o DSE black-box (H5) | Médio-alto | Relatar o resultado com análise de causa; deslocar o valor para previsão (H2/H4) e decisão (H7) |
| Erro de predição acima do almejado (MAPE) | Médio | Metas relativas aos baselines; reportar por nível (camada versus atualização); modelo restrito a uma família |
| O modelo não generaliza entre famílias/plataformas (H6) | Alto | Reposicionar como modelo por família, mantendo a metodologia e o benchmark como contribuições |
| Dados com drift realista insuficientes | Alto | Drift sintético documentado sobre dados públicos; bancada controlada já no Ano 1 |
| Energia em FPGA pouco representativa | Médio | Coeficientes por tecnologia; sensibilidade; verificação cruzada no MCU RISC-V |
| H1 trivial (mesmo kernel dominante em tudo) | Médio | Tratar como achado; simplificar o modelo; foco em H2–H5 e H7 |
| Escopo excessivo | Médio | Duas famílias no núcleo; terceira apenas como *stretch goal* |

## 15. Critérios de Sucesso

Com limiares calibrados e pré-registrados após o piloto, a tese será bem-sucedida se demonstrar:

1. **Predição superior ao estado da arte:** MAPE ≤ 15% no nível de atualização e redução de pelo menos 2× do erro frente ao melhor baseline (H2); fronteira de Pareto com Spearman ≥ 0,85 (H4);
2. **Decisão correta:** concordância ≥ 85% na decisão de adaptar e custo total inferior ao dos gatilhos de referência (H7);
3. **Co-design efetivo:** *regret* ≤ 10% e vantagem sobre a exploração black-box sob o mesmo orçamento de sínteses, mais ganho ≥ 20% sobre a extensão genérica (H5);
4. **Generalização:** MAPE ≤ 25% no segundo domínio e na segunda plataforma com recalibração apenas de coeficientes (H6);
5. **Artefatos abertos** (benchmark e framework) publicados, documentados e reprodutíveis.

Resultados negativos em hipóteses específicas, quando bem caracterizados, são considerados contribuições, desde que cumpridos os critérios 1 e 5.

## 16. Resumo Executivo

Esta tese propõe o **MQCA**, um modelo interpretável e independente de tecnologia que relaciona o custo de atualização de modelos TinyML (operações, memória e movimento de dados) ao ganho adaptativo sob drift, deriva uma condição de *break-even* para decidir quando adaptar localmente e orienta a escolha de extensões RISC-V antes da síntese. Reconhece que há trabalhos prévios sobre custo de treino on-device, rooflines de energia, decisão de retreinamento e co-design em RISC-V, e posiciona a originalidade na **integração validada fora da amostra**, em duas plataformas e dois domínios, com desempenho comparado a baselines que reproduzem o estado da arte, inclusive a exploração black-box do espaço de projeto. Entrega também um **benchmark aberto de aprendizado contínuo com drift para TinyML**, que responde a uma lacuna apontada pela literatura recente. A detecção de anomalias em motores elétricos é o ambiente de validação.

---


## Apêndice A – Referências a verificar

Triagem preliminar (nomes e temas, sem substituir a revisão sistemática; confirmar autoria, venue e conteúdo antes de citar):

- Plataforma RISC-V para AC com latent replay (VEGA) e o node RISC-V de AC com análise de trade-offs memória-latência-acurácia;
- Choi et al., *A Roofline Model of Energy*; Pagoda (rooflines de tempo e energia em Jetson, incluindo treino);
- THOR (estimativa de energia para treino on-device) e *Design-Time Optimization of DNNs for Intermittent Learning on Microcontrollers* (2026);
- CARA (*Cost-Effective Retraining of Machine Learning Models*) e DriftGuard;
- CFU Playground (Prakash et al.), com Vizier;
- MiniFloat-NN/ExSdotp; trabalho de SIMD FP16 para ODL em GAP9/PULP-TrainLib;
- Survey *What changes after deployment? On-device Learning in TinyML* (Pavan et al., 2026);
- Estudo de simulação *Trend-Aware TinyML Co-Design on Microcontrollers* (conteúdo não verificado);
- Matsutani et al. (OS-ELM, ONLAD, ODL em máquinas rotativas);
- TinyOL, MCUNet/MCUNetV3, PockEngine; MLPerf Tiny; Timeloop/Accelergy; PULP/XpulpNN.

---

---


# Cronograma de Nivelamento (Ano 0)
## Preparação para o Doutorado: MQCA — Modelo Quantitativo de Custo-Benefício para Aprendizado Contínuo em TinyML e Co-Design de Extensões RISC-V

Este plano de 12 meses foi desenhado para evoluir de uma base introdutória em **programação**, **eletrônica** e **matemática** até o domínio prático e conceitual necessário para iniciar o **Ano 1** da proposta (`PropostaDoutoral-rev5.md`) com autonomia experimental, leitura crítica de literatura e domínio do ferramental de hardware e software.

---

## Visão Geral dos 4 Trimestres

| Trimestre | Meses | Foco Principal | Entrega / Marco de Nivelamento |
| :--- | :--- | :--- | :--- |
| **T1** | 1 – 3 | Programação (Python/C), Matemática aplicada e Eletrônica básica/sinais | Scripts de análise numérica, leitura de sensores e domínio de álgebra, cálculo e estatística aplicados |
| **T2** | 4 – 6 | Eletrônica digital, Microcontroladores (MCU) e Fundamentos de TinyML | Firmware coletando sinais em MCU e modelos compactos (autoencoder/protótipos) treinados e quantizados |
| **T3** | 7 – 9 | Arquitetura de Computadores, Verilog/FPGA e Ecossistema RISC-V | Softcore RISC-V rodando em FPGA/simulador e compreensão de ciclos, memória e extensões customizadas |
| **T4** | 10 – 12 | Aprendizado Contínuo, *Concept Drift*, Instrumentação e Pré-Piloto MQCA | Pipeline de *drift* sintético, medição de ciclos/energia e ambiente base pronto para o Ano 1 |

---

## Rotina Semanal Recomendada

Para manter constância ao longo dos 12 meses, distribua o tempo de estudo na seguinte proporção:

- **50% Prática (Hands-on):** implementação em Python/C, montagem de circuitos, programação de MCU, descrição em Verilog e experimentos em FPGA.
- **30% Teoria Estruturada:** estudo de matemática, eletrônica, arquitetura de computadores e fundamentos de aprendizado de máquina.
- **20% Leitura Técnica e Documentação:** construção de glossário próprio, resumos de conceitos e leitura introdutória de artigos de *TinyML*, *RISC-V* e *concept drift*.

---

## T1 (Meses 1–3): Fundamentos de Programação, Matemática e Eletrônica

**Objetivo:** Construir a base matemática e computacional para implementar modelos analíticos, manipular séries temporais e compreender sinais físicos vindos de sensores.

### 1. Programação Científica e Embarcada Base
- **Python:** estruturas de dados, orientação a objetos, ambientes virtuais, `Git`, `NumPy`, `SciPy`, `Pandas` e `Matplotlib`.
- **C e C++:** ponteiros, alocação e gerenciamento de memória, *structs*, operações *bitwise*, aritmética inteira e organização modular de projetos.

### 2. Matemática para Modelagem Analítica e ML
- **Álgebra Linear:** vetores, matrizes, produto interno, normas ($L_1$, $L_2$), transposição, autovalores/autovetores e projeções (base para autoencoders e métodos baseados em protótipos).
- **Cálculo e Otimização:** derivadas parciais, gradiente, regra da cadeia (*backpropagation*), integrais definidas (interpretação de áreas sob curvas, como o ganho acumulado $G(c, D)$) e regressão por mínimos quadrados.
- **Probabilidade e Estatística:** distribuições, média, variância, covariância, métricas de classificação/detecção (Precisão, *Recall*, F1-Score, AUROC), intervalos de confiança, *bootstrap* e testes de hipótese.

### 3. Eletrônica Básica e Aquisição de Sinais
- **Circuitos:** Lei de Ohm, leis de Kirchhoff, divisores de tensão, filtros passivos RC (passa-baixa/passa-alta) e acoplamento de sensores.
- **Sinais:** diferença entre sinais analógicos e digitais, frequência de amostragem, teorema de Nyquist, ruído, *offset* e ganho em sensores (acelerômetro/vibração e temperatura).

### Marco de Conclusão do T1
- [ ] Repositório Git organizado com rotinas em Python para regressão linear, cálculo de métricas (F1/AUROC) e visualização de séries temporais.
- [ ] Código em C puro realizando operações matriciais básicas sem bibliotecas externas.
- [ ] Leitura funcional de um sensor analógico/digital (ex.: acelerômetro ou temperatura) com análise de ruído.

---

## T2 (Meses 4–6): Eletrônica Digital, Microcontroladores e Base de TinyML

**Objetivo:** Conectar software e hardware restrito, compreendendo restrições de RAM/Flash, representação numérica reduzida e execução de algoritmos de detecção de anomalias em microcontroladores.

### 1. Eletrônica Digital e Microcontroladores (MCU)
- **Lógica Digital:** portas lógicas, combinacional vs. sequencial, *flip-flops*, registradores, multiplexadores e contadores.
- **Periféricos e Arquitetura de MCU:** barramentos (`UART`, `SPI`, `I2C`), conversor analógico-digital (`ADC`), `DMA`, *timers* e interrupções.
- **Prática em Hardware:** desenvolvimento em placa MCU (preferencialmente variante RISC-V, como ESP32-C3/C6, ou STM32) com medição precisa de tempo de execução via contadores de ciclos.

### 2. Machine Learning e TinyML
- **Algoritmos Alvo da Proposta:**
  - *Família A:* Autoencoders compactos (treinamento, erro de reconstrução e limiar de anomalia).
  - *Família B:* Métodos baseados em protótipos e estatística incremental (atualização recursiva de média/variância e distância a centróides).
- **Quantização e Precisão Numérica:** representação em `float32`, ponto fixo (`Q-format`) e inteiros de 8 bits (`int8`); impacto da precisão em memória, latência e qualidade do modelo.
- **Inferência vs. Adaptação On-Device:** diferenças estruturais de memória e computação entre apenas inferir (*forward pass*) e atualizar pesos/protótipos localmente.

### Marco de Conclusão do T2
- [ ] Firmware rodando em MCU coletando dados de sensor e executando inferência de um modelo compacto.
- [ ] Implementação funcional (em Python e C) de um autoencoder simples e de um classificador/detector baseado em protótipos.
- [ ] Comparativo prático de uso de RAM, Flash e ciclos entre versões `float32` e `int8`/ponto fixo.

---

## T3 (Meses 7–9): Arquitetura de Computadores, FPGA e Ecossistema RISC-V

**Objetivo:** Adquirir domínio sobre como instruções são executadas no hardware, como a hierarquia de memória afeta energia e desempenho, e como projetar extensões customizadas em FPGA.

### 1. Arquitetura de Computadores e Eficiência Energética
- **Microarquitetura:** ciclo de instrução, *datapath*, unidade de controle, *pipeline*, *hazards* e execução de operações MAC (*Multiply-Accumulate*).
- **Hierarquia de Memória:** registradores, SRAM/caches, Flash e memória externa; compreensão do custo energético da movimentação de dados frente ao custo aritmético (intuição por trás de modelos *Roofline*).

### 2. Descrição de Hardware (HDL) e FPGA
- **Verilog / SystemVerilog:** modelagem combinacional e sequencial, máquinas de estados finitos (FSM), *testbenches* e simulação funcional.
- **Fluxo FPGA:** síntese, *place-and-route*, análise de temporização ($f_{\max}$) e leitura de relatórios de utilização de recursos (`LUTs`, `FFs`, `DSPs`, `BRAM`).

### 3. Arquitetura RISC-V e Co-Design
- **ISA RISC-V:** conjunto base (`RV32I`), extensões padrão (`M` para multiplicação, `C` para instruções comprimidas), registradores e convenção de chamada (*ABI*).
- **Extensões Customizadas:** conceito de instruções customizadas e unidades funcionais customizadas (*Custom Function Units* — CFUs) acopladas a softcores RISC-V em FPGA.

### Marco de Conclusão do T3
- [ ] Módulo aritmético simples (ex.: acelerador de produto interno ou MAC `int8`) escrito em Verilog, simulado com *testbench* e sintetizado em FPGA.
- [ ] Softcore RISC-V básico compilando e executando código C em ambiente FPGA ou simulador cycle-accurate.
- [ ] Capacidade de extrair contagem de ciclos, instruções executadas e recursos de FPGA de um experimento simples.

---

## T4 (Meses 10–12): Aprendizado Contínuo, *Concept Drift* e Pré-Piloto MQCA

**Objetivo:** Integrar os conhecimentos dos trimestres anteriores no contexto exato da tese, preparando ferramentas, métricas e procedimentos experimentais para o início do Ano 1.

### 1. Aprendizado Contínuo e *Concept Drift*
- **Paradigmas:** limitações do modelo estático (*train-once-deploy-forever*) frente ao aprendizado contínuo/incremental (*on-device learning*).
- **Tipos de Drift:** abrupto, gradual, incremental e recorrente; diferença entre mudança na distribuição de entrada (*covariate/sensor drift*) e mudança na relação de decisão (*concept drift*).
- **Simulação Controlada:** injeção documentada de *drift* (variação de carga/velocidade, deriva térmica, *offset*, ganho e ruído de sensor) sobre séries temporais de vibração/temperatura.

### 2. Instrumentação de Energia e Perfilamento
- **Medição Física:** fundamentos de medição de corrente e potência em placas embarcadas (resistor *shunt*, amplificador de corrente, osciloscópio/analisador de potência) para obter energia por operação e por atualização ($E_{\text{upd}}$).
- **Perfilamento de Kernel:** identificação de gargalos computacionais e de acesso à memória em rotinas de atualização de modelos.

### 3. Pré-Piloto Integrado (Ponte para o Ano 1)
- **Formulação Inicial:** familiarização com as equações do MQCA ($E_{\text{upd}}$, $G(c, D)$, $\eta(c, D)$ e condição de *break-even* $\lambda \cdot G > E_{\text{adapt}}$).
- **Organização Bibliográfica:** configuração de gerenciador de referências (Zotero/Mendeley) e leitura preliminar dos trabalhos centrais listados no Apêndice A da proposta (TinyOL, MCUNetV3, PockEngine, CFU Playground, PULP/XpulpNN, CARA e *surveys* recentes de ODL em TinyML).

### Marco de Conclusão do T4 (Pronto para o Ano 1)
- [ ] Pipeline experimental funcional que aplica *drift* sintético em dados de vibração, executa inferência e atualização local, e registra desempenho (F1/AUROC) ao longo do tempo.
- [ ] Bancada de bancada/medição inicial validada para extrair tempo, ciclos e estimativa/medição de energia por atualização.
- [ ] Ambiente de software, simuladores e ferramentas FPGA configurados e documentados para iniciar imediatamente a Revisão Sistemática e o Estudo Piloto do Ano 1.

---

## Checklist Final de Prontidão para o Doutorado

Ao final do Ano 0, você deverá estar apto a responder "sim" a todos os itens abaixo:

- [ ] Consigo implementar e depurar algoritmos numéricos em Python e C embarcado sem dependência de frameworks pesados?
- [ ] Compreendo como derivadas, matrizes, quantização (`int8`/ponto fixo) e métricas estatísticas (F1, AUROC, Spearman, MAPE) operam na prática?
- [ ] Consigo ler sinais de sensores físicos em um microcontrolador e medir com precisão o tempo/ciclos de execução?
- [ ] Entendo o funcionamento de um softcore RISC-V em FPGA, sei ler relatórios de recursos/temporização e simular um módulo simples em Verilog?
- [ ] Tenho um ambiente preparado para medir energia/ciclos e simular cenários de *drift* para iniciar o estudo piloto do MQCA?

---