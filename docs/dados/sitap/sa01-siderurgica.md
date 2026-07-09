---
title: SA1 - Siderúrgica
icon: fontawesome/solid/book
author:
 - José W. R. Pereira
tags:
 - Ciência de Dados
 - Inteligência Artificial
 - Aprendizado de Máquina
 - SLTINTA
---


---
# Situação de Aprendizagem

> Você foi contratado como Engenheiro de IA por uma grande planta siderúrgica que opera 24 horas por dia. O principal ativo da fábrica é uma estação de usinagem CNC de alto desempenho. Recentemente, a quebra inesperada do cabeçote de corte dessa máquina causou uma parada na linha de produção que durou 36 horas, gerando um prejuízo estimado em R$ 150.000,00 entre peças de reposição urgentes, ociosidade da equipe e multas por atraso na entrega dos produtos aos clientes.

> A gerência de manutenção possui sensores que medem variáveis físicas da máquina a cada segundo, mas atualmente esses dados são apenas visualizados em telas isoladas e descartados. O seu desafio no semestre é interligar essa telemetria e criar um sistema inteligente capaz de prever uma falha mecânica com antecedência, permitindo que a equipe agende o reparo durante uma pausa planejada de produção.



---

## Metodologia CRISP-DM

O fluxo de trabalho para resolver o problema da quebra do cabeçote de corte CNC, utilizando a metodologia **CRISP-DM** (*Cross Industry Standard Process for Data Mining* - Processo Padrão Inter-Indústrias para Mineração de Dados), organiza o projeto de Aprendizado de Máquina (ML) em seis etapas cíclicas que garantem que a solução técnica esteja alinhada aos objetivos financeiros da siderúrgica (LET'S DATA, 2021; POD ACADEMY, 2023).

Abaixo, detalha-se como cada etapa seria aplicada à situação-problema:



**1. Entendimento do Negócio (*Business Understanding*)**

O foco inicial é traduzir o problema industrial em um problema de dados.

*   **Objetivo de Negócio:** Evitar paradas inesperadas de 36 horas e eliminar o prejuízo de **R$ 150.000,00** por falha (POD ACADEMY, 2023).
*   **Critério de Sucesso:** O sistema deve prever falhas mecânicas com antecedência mínima suficiente para que a manutenção seja agendada em uma pausa planejada (POD ACADEMY, 2023).
*   **Avaliação de Viabilidade:** Verificar se o custo de implementar o monitoramento e o modelo de ML é inferior ao prejuízo causado pelas quebras recorrentes (POD ACADEMY, 2023).



**2. Entendimento dos Dados (*Data Understanding*)**

Nesta fase, interrompe-se o descarte da telemetria para análise.

*   **Coleta:** Interligar os sensores que medem variáveis como **vibração, temperatura e carga** a cada segundo, armazenando-os em uma base de dados histórica (ENCOPEL ROLAMENTOS, 2020; POD ACADEMY, 2023).
*   **Exploração:** Realizar uma análise exploratória para identificar padrões de comportamento nos sensores nos momentos que antecederam a quebra do cabeçote (MURPHY, 2022; LET'S DATA, 2021).
*   **Teste de Sanidade:** Garantir que os dados coletados pelos sensores representam fielmente o estado físico da máquina CNC (POD ACADEMY, 2023).



**3. Preparação dos Dados (*Data Preparation*)**

É a fase mais trabalhosa, onde os dados brutos são transformados para o treinamento (LET'S DATA, 2021; GÉRON, 2019).

*   **Limpeza e Integração:** Unir as diferentes telas isoladas de telemetria em um único conjunto de dados estruturado (SANTOS et al., 2025; LET'S DATA, 2021).
*   **Engenharia de Atributos (*Feature Engineering*):** Transformar a telemetria bruta em indicadores úteis, como o uso de **Transformada Rápida de Fourier (FFT)** para extrair frequências de vibração que indicam desgaste de rolamentos (SANTOS et al., 2025; INDUSTRIA 4.0, 2020).
*   **Rotulagem:** Marcar nos dados históricos o tempo exato de cada falha para que o modelo possa aprender a diferença entre o estado `Normal` e o `Estado Perigoso` (BOUSDEKIS et al., 2019; SANTOS et al., 2025).



**4. Modelagem (*Modeling*)**

Aqui, selecionam-se os algoritmos de ML.

*   **Seleção de Modelos:** Testar diferentes arquiteturas, como **Árvores de Decisão, SVM ou Redes Neurais (ANN)**, para classificar o risco de falha ou prever a Vida Útil Restante (RUL) (RASCHKA, 2015; SANTOS et al., 2025).
*   **Divisão dos Dados:** Separar o histórico em conjuntos de **treinamento (ex: 70%) e teste (ex: 30%)** para garantir a capacidade de generalização do sistema (GÉRON, 2019; SANTOS et al., 2025).
*   **Otimização:** Ajustar os **hiperparâmetros** dos modelos via *Grid Search* para extrair a melhor performance preditiva (MURPHY, 2022; SANTOS et al., 2025).



**5. Avaliação (*Evaluation*)**

Antes de implantar, verifica-se se o modelo resolve o problema de negócio.

*   **Métricas Técnicas:** Avaliar o **Recall (Sensibilidade)**, pois um "Falso Negativo" (falha não prevista) custa R$ 150 mil à empresa (GÉRON, 2019; SANTOS et al., 2025).
*   **Alinhamento com o Negócio:** Se o modelo prediz falhas com 98% de acurácia, mas apenas com 5 minutos de antecedência, ele falha no objetivo de permitir um reparo planejado. Caso os critérios não sejam atendidos, deve-se retornar à etapa de **Entendimento do Negócio** para reajustar as premissas (POD ACADEMY, 2023; LET'S DATA, 2021).



**6. Implantação (*Deployment*)**

A etapa final coloca o modelo em operação real.

*   **Integração:** Conectar o modelo de ML diretamente ao fluxo de dados em tempo real da CNC (LET'S DATA, 2021; POD ACADEMY, 2023).
*   **Interface:** Criar um **Dashboard ou sistema de alertas** (via e-mail ou SMS) que notifique a equipe de manutenção assim que uma anomalia for detectada (INDUSTRIA 4.0, 2020; ENCOPEL ROLAMENTOS, 2020).
*   **Monitoramento:** Implementar o acompanhamento do modelo para detectar degradação de performance ao longo do tempo (*model drift*), garantindo retreinos periódicos com novos dados (GÉRON, 2019; POD ACADEMY, 2023).

---

**Referências**

ABNT - ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **ABNT NBR 14724**: informação e documentação: trabalhos acadêmicos: apresentação. 4. ed. Rio de Janeiro: ABNT, 2024.

ABNT - ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **ABNT NBR 6023**: informação e documentação: referências: elaboração. Rio de Janeiro: ABNT, 2018.

BOUSDEKIS, Alexandros; APOSTOLOU, Dimitris; MENTZAS, Gregoris. **Predictive maintenance in the 4th industrial revolution**: benefits business opportunities and managerial implications. [S. l.]: [s. n.], 2019.

ENCOPEL ROLAMENTOS. **Webinar**: manutenção preditiva na indústria 4.0. [S. l.]: Youtube, 2020. Disponível em: https://www.youtube.com/watch?v=A8f9D590p8c. Acesso em: 8 jul. 2026.

GÉRON, Aurélien. **Hands-on machine learning with Scikit-Learn, Keras, and TensorFlow**: concepts, tools, and techniques to build intelligent systems. 2. ed. [S. l.]: O'Reilly Media, 2019.

INDUSTRIA 4.0. **Manutenção Preditiva On-Line - Industria 4.0**. [S. l.]: Youtube, 2020. Disponível em: https://www.youtube.com/watch?v=Fst5jZ8v7I8. Acesso em: 8 jul. 2026.

LET'S DATA. **CRISP-DM**: a melhor metodologia para projetos de Data Science. [S. l.]: Youtube, 2021. Disponível em: https://www.youtube.com/watch?v=fV7i6U-0Q7M. Acesso em: 8 jul. 2026.

MURPHY, Kevin P. **Probabilistic machine learning**: an introduction. [S. l.]: MIT Press, 2022.

POD ACADEMY | DATA & ANALYTICS. **Aprenda a metodologia CRISP-DM para tomada de decisão data-driven [Webinar PoD Academy]**. [S. l.]: Youtube, 2023. Disponível em: https://www.youtube.com/watch?v=C7QYm0fL2vA. Acesso em: 8 jul. 2026.

RASCHKA, Sebastian. **Python machine learning**. Birmingham: Packt Publishing, 2015.

SANTOS, Bruno J. et al. Electroencephalogram Signal Acquisition System with Machine Learning for Robotic Prosthesis Control: In Vivo Dataset. **Artificial Intelligence and Applications**, [S. l.], v. 00, n. 00, p. 1-22, 2025. DOI: 10.47852/bonviewAIA52024252.

---

Material produzido com auxílio de `NotebookLM`

---

---
