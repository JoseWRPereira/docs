---
title: Doutorado
icon: fontawesome/solid/chalkboard-user
author:
 - José W. R. Pereira
tags:
 - Doutorado
 - Unicamp
---

**"Co-Design de Arquiteturas de Hardware e Algoritmos de TinyML para Inferência e Aprendizado Adaptativo em Dispositivos de Borda Restritos"**

---

### Resumo

A pesquisa propõe o desenvolvimento de um *framework* de **Co-Design Hardware-Software** focado na integração entre modelos matemáticos de Aprendizado de Máquina (*TinyML*) e arquiteturas de microcontroladores de baixo consumo energético (com foco em **RISC-V** e ecossistemas comerciais de borda).

O trabalho investiga métodos de quantização adaptativa, poda de redes neurais e otimização do uso de memória SRAM combinados a extensões de instruções personalizadas no processador. O objetivo principal é viabilizar a execução de inferências e o aprendizado local em dispositivos IoT de extrema borda (*Extreme Edge*), reduzindo o consumo de energia por operação sem comprometer a acurácia dos modelos em aplicações como sensoriamento inteligente e manutenção preditiva industrial.


---

## 0. Resumo Cronológico de Bordo (48 Créditos Totalizados)

| Período | Vínculo | Disciplinas Cursadas | Créditos | Foco de Trabalho |
| --- | --- | --- | --- | --- |
| **2026.2** | *Preparação* | Cursos de Matemática para ML, C/C++ e RISC-V | 0 cr | Nivelamento e estudo autônomo. |
| **2027.1** | **Aluno Especial** | MO401 (IC)[cite: 1] | 4 cr | Base em Arquitetura e Contato IC[cite: 1]. |
| **2027.2** | **Aluno Especial** | IA247 (FEEC) + MO444 (IC) | 8 cr | Embarcados + Machine Learning. |
| **2028.1** | **Aluno Regular** | MO826 (IC) + EE850 (FEEC)[cite: 1] | 8 cr | *Power-aware* e FPGAs[cite: 1]. |
| **2028.2** | **Aluno Regular** | MO833 (IC) + MO417 (IC) | 8 cr | Compressão TinyML e RISC-V. |
| **2029.1** | **Aluno Regular** | MO825 (IC) + MO901 (IC) | 8 cr | Compiladores + Artigo 1. |
| **2029.2** | **Aluno Regular** | PED I (IC) + IA888 (FEEC) | 8 cr | Estágio Docência + Aplicação IoT. |
| **2030.1** | **Aluno Regular** | MO905 (IC) | 4 cr | **Exame de Qualificação** e Tese. |
| **2030.2+** | **Aluno Regular** | *Sem disciplinas (Apenas Tese)* | Total: **48 cr** | Redação final e Defesa do Doutorado. |

---


## 1. Conhecimentos e Cursos Prévia de Preparação

Para que você chegue às disciplinas do IC e da FEEC com total domínio prático e teórico, a preparação deve cobrir três pilares: **Matemática do Machine Learning**, **Arquitetura & Baixo Nível** e **Sistemas Embarcados com C/C++**.

```
TRILHA PREPARATÓRIA:
[Matemática & Python ML] ➔ [C/C++ & Arquitetura RISC-V] ➔ [RTOS & Compiladores]

```

---

### Módulo 1: Matemática Aplicada e Fundamentos de Machine Learning

* **Conteúdos Chave:** Álgebra Linear (produto interno, decomposição matricial, SVD), Cálculo Multivariado (gradientes, regra da cadeia), Otimização Convexa, Representação Numérica (ponto flutuante vs. inteiros com sinal em INT8/INT4).
* **Cursos Recomendados:**
* [Mathematics for Machine Learning Specialization (Imperial College London - Coursera)](https://www.coursera.org/specializations/mathematics-machine-learning): Excelente para revisar vetorização, matrizes e gradientes antes do doutorado.
* [Machine Learning Specialization (Andrew Ng / Stanford - Coursera)](https://www.coursera.org/specializations/machine-learning-introduction): Cobre a intuição matemática necessária para a disciplina `MO444` / `MO416` da UNICAMP.



---

### Módulo 2: C/C++ Bare-Metal e Arquitetura de Computadores

* **Conteúdos Chave:** Programação de firmware sem SO (*bare-metal*), manipulação de ponteiros e memória em C, organização de instrução ISA (RISC-V e ARM), análise de hazards de pipeline e estrutura de caches/SRAM.
* **Cursos Recomendados:**
* [Computer Architecture (Princeton University - Coursera)](https://www.google.com/search?q=https://www.coursera.org/learn/aqa): Curso clássico que cobre a teoria base da disciplina `MO401` do IC (pipelines, caches e ILP).
* [Building a RISC-V CPU from Scratch (edX / Linux Foundation)](https://www.google.com/search?q=https://www.edx.org/learn/computer-hardware/linux-foundation-building-a-risc-v-cpu-from-scratch): Teoria e prática em circuito lógico e ISA RISC-V.



---

### Módulo 3: Sistemas Embarcados e TinyML Prático

* **Conteúdos Chave:** Estrutura de Sistemas Operacionais de Tempo Real (FreeRTOS), quantização, destilação de modelos, TensorFlow Lite for Microcontrollers e medição de consumo de energia em microcontroladores.
* **Cursos Recomendados:**
* [Applications of TinyML (Harvard University - edX)](https://www.edx.org/learn/tinyml/harvard-university-applications-of-tinyml): O curso de referência mundial em TinyML. Ensina a embarcar modelos em microcontroladores comerciais.
* [Real-Time Operating Systems (RTOS) Step by Step (Udemy)](https://www.google.com/search?q=https://www.udemy.com/course/rtos-freertos-debugging-using-stm32/): Base prática para disciplinas da FEEC (`IA247`).



---

## 2. Planejamento de Disciplinas de DoutoradoDireto (48 Créditos)

Neste cenário de **Doutorado Direto**, a meta é totalizar **48 créditos (12 disciplinas de 4 créditos)**, estendendo a fase regular confortavelmente para absorver o ritmo de pesquisa.

### Estrutura de Distribuição de Carga:

* **Fase 1 (Aluno Especial):** 3 semestres | **12 créditos**
* *Ritmo:* 1 disciplina no S1, 2 disciplinas no S2, 2 disciplinas no S3 (sendo a 5ª matéria um excedente para garantir 12 cr convalidados sem sobcalço de edital).


* **Fase 2 (Aluno Regular):** 5 a 6 semestres | **36 créditos restantes** (ritmo suave de 1 a 2 disciplinas por semestre para focar na pesquisa e nos experimentos de bancada).

---

### FASE 1: Como Aluno Especial (12 Créditos | Semestres 1 a 3)

Esta fase foi desenhada no ritmo solicitado: apenas 1 disciplina no primeiro semestre para adaptação e aproximação, e 2 nos semestres seguintes.

#### **Semestre 1 (2027.1) — 1 Disciplina (4 Créditos)**

1. **MO401 — Arquitetura de Computadores I (IC)**[cite: 1]
* *Pré-requisito prévio:* Cursos de C/C++ e Arquitetura de Princeton.
* *Objetivo:* Fazer a principal disciplina de base da Pós-Graduação do IC e criar contato direto com docentes da área de arquitetura e co-design (ex: Prof. Rodolfo Azevedo)[cite: 1].



#### **Semestre 2 (2027.2) — 2 Disciplinas (8 Créditos)**

2. **IA247 — Sistemas Embarcados (FEEC)**
* *Pré-requisito prévio:* Cursos de RTOS e Harvard TinyML.
* *Objetivo:* Dominar o ecossistema de firmware e consumo de potência na FEEC.


3. **MO444 / MO416 — Aprendizado de Máquina (IC)**
* *Pré-requisito prévio:* Cursos de Matemática para ML e Stanford ML.
* *Objetivo:* Garantir o embasamento formal dos algoritmos de redes neurais antes de quantizá-los.



---

### FASE 2: Como Aluno Regular (36 Créditos | Semestres 3 a 7)

Após a aprovação formal no Doutorado Direto do IC, a transição para aluno regular ocorre aproveitando os 12 créditos acumulados. O tempo de integralização pode se estender por 4 a 5 anos mantendo o foco nos artigos.

#### **Semestre 3 (2028.1) — 2 Disciplinas (8 Créditos)**

4. **MO826 — Tópicos em Sistemas: Computação Eficiente em Energia (IC)**
* *Objetivo:* Trabalhar com sistemas *power-aware* e restrições térmicas/energéticas de nós IoT com o Prof. Lucas Wanner[cite: 1].


5. **EE850 / IA014 — Projeto de Sistemas em FPGAs / Processamento de Sinais (FEEC)**
* *Objetivo:* Desenvolver aceleradores de hardware em lógica programável e tratamento de dados de sensores.



#### **Semestre 4 (2028.2) — 2 Disciplinas (8 Créditos)**

6. **MO833 — Tópicos em Deep Learning e Compressão de Modelos (IC)**
* *Objetivo:* Aprofundamento em quantização (INT8/INT4), *pruning* e compilação para TinyML (TVM, TFLite Micro).


7. **MO417 — Tópicos em Arquitetura: Sistemas Heterogêneos e RISC-V (IC)**
* *Objetivo:* Estudo avançado de extensões de instrução e aceleração em processadores RISC-V.



#### **Semestre 5 (2029.1) — 2 Disciplinas (8 Créditos)**

8. **MO825 — Compiladores e Otimização de Código (IC)**
* *Objetivo:* Entender a tradução de grafos de computação de IA para código de máquina em processadores restritos.


9. **MO901 — Tópicos em Sistemas de Computação (IC)**
* *Objetivo:* Disciplina focada em seminários de pesquisa e escrita científica de artigos internacionais.



#### **Semestre 6 (2029.2) — 2 Disciplinas / Atividades (8 Créditos)**

10. **PED I — Programa de Estágio Docente (IC)**
* *Objetivo:* Estágio de docência obrigatório (para bolsistas) que pontua 4 créditos na pós-graduação.


11. **IA888 — Tópicos em Automação e Redes Industriais / IoT (FEEC)**
* *Objetivo:* Aplicação dos modelos na borda em cenários reais de manutenção preditiva industrial.



#### **Semestre 7 (2030.1) — 1 Disciplina de Fechamento (4 Créditos)**

12. **MO905 — Estudo Dirigido em Co-Design e TinyML (IC)**
* *Objetivo:* Conduzido pelo orientador para o fechamento dos experimentos finais e redação da Tese de Doutorado.



---

