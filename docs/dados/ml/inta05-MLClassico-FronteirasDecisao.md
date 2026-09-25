---
title: 05 - ML Clássico e Fronteiras de Decisão
icon: fontawesome/solid/book
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
---

# Máquinas de Vetores de Suporte (SVM) no Diagnóstico de Falhas Industriais


---

## 1. Contexto Histórico e Origem das Máquinas de Vetores de Suporte

Para compreender o impacto e a elegância matemática do **SVM (*Support Vector Machines*)**, é fundamental analisar a evolução dos algoritmos de classificação ao longo do século XX.

No final da década de 1950, Frank Rosenblatt desenvolveu o **Perceptron**, a primeira arquitetura de rede neural artificial simplificada. O Perceptron buscava encontrar um hiperplano capaz de separar duas classes ajustando iterativamente seus pesos a cada erro de classificação. No entanto, o Perceptron possuía duas limitações severas:

1. **Infinidade de Soluções:** Se os dados fossem linearmente separáveis, existia um número infinito de linhas ou hiperplanos capazes de separar as classes com \\(100\%\\) de acerto. O Perceptron parava assim que encontrava a *primeira* linha válida, sem qualquer garantia de qualidade ou estabilidade temporal.
2. **Sensibilidade a Amostras Limítrofes e Ruído:** Fronteiras traçadas muito próximas dos pontos de treino tendiam a falhar categoricamente ao receber novos dados ligeiramente ruidosos.

Nas décadas de 1960 a 1990, o matemático russo **Vladimir Vapnik** e seus colaboradores nos laboratórios da AT&T Bell Labs, como Alexey Chervonenkis, Isabelle Guyon e Corinna Cortes, reformularam os fundamentos do aprendizado de máquina ao propor a **Teoria do Aprendizado Estatístico**. 

Em vez de focar apenas na *Minimização do Risco Empírico*, reuzir o erro no conjunto de treinamento, Vapnik introduziu o princípio da **Minimização do Risco Estrutural (SRM)**. A grande inovação ocorreu em 1992, com a introdução do *Truque do Kernel*, e em 1995 ,com a formulação da *Margem Suave* por Vapnik e Cortes, consolidando o SVM como o algoritmo soberano em classificação e reconhecimento de padrões antes do advento do Deep Learning moderno.

---

## 2. Objetivo e Necessidade do SVM na Manutenção Preditiva (Indústria 4.0)

Na engenharia de manutenção preditiva, o objetivo de um modelo de classificação é atuar como um **agente de triagem em tempo real**. Sensores físicos instalados em máquinas (medindo Temperatura, Torque, Vibração e Rotação/RPM) enviam fluxos contínuos de dados. O modelo deve analisar essas variáveis e responder instantaneamente: a máquina opera em **Condição Normal (Classe 0)** ou entrou em **Zona de Falha Iminente (Classe 1)**?

### Por que o SVM é a ferramenta ideal para essa tarefa?
* **Busca pela Fronteira de Separação Ótima:** Diferente de outros classificadores, o SVM posiciona a fronteira de decisão exatamente no centro do "corredor" mais largo possível entre as duas classes. Isso confere ao modelo uma alta capacidade de generalização ao lidar com variações e ruídos térmicos dos sensores no chão de fábrica.
* **Capacidade de Lidar com Relações Não Lineares:** Fenômenos físicos industriais raramente são lineares. A interação entre alta temperatura e queda de RPM exige fronteiras curvas complexas, que o SVM constrói eficientemente no espaço dimensional adequado.
* **Robustez em Espaços de Alta Dimensão:** O SVM permanece matematicamente estável mesmo quando o número de sensores e variáveis derivadas supera a quantidade de amostras disponíveis.

---

## 3. Fundamentos Matemáticos do SVM (Do Primal ao Dual)

### 3.1. A Equação do Hiperplano e a Margem Máxima

Considere um conjunto de dados de treinamento composto por \\(N\\) amostras:
\\[\mathcal{D} = \{(\mathbf{x}_1, y_1), (\mathbf{x}_2, y_2), \dots, (\mathbf{x}_N, y_N)\}\\]
onde \\(\mathbf{x}_i \in \mathbb{R}^d\\) representa o vetor de atributos do sensor e \\(y_i \in \{-1, +1\}\\) representa o rótulo da classe (onde \\(-1\\) é Normal e \\(+1\\) é Falha).

O hiperplano separador é definido pela equação linear:
\\[f(\mathbf{x}) = \mathbf{w}^T \mathbf{x} + b = 0\\]
onde \\(\mathbf{w}\\) é o vetor ortogonal (normal) ao hiperplano e \\(b\\) é o termo de deslocamento (*bias*).

Para amostras perfeitamente separáveis, definimos dois hiperplanos paralelos limites que delimitam a "rua" ou margem de segurança:
\\[\mathbf{w}^T \mathbf{x}_i + b \ge +1 \quad \text{se } y_i = +1\\]
\\[\mathbf{w}^T \mathbf{x}_i + b \le -1 \quad \text{se } y_i = -1\\]

Combinando ambas as desigualdades em uma única expressão, obtemos a restrição da **Margem Rígida (*Hard Margin*)**:
\\[y_i (\mathbf{w}^T \mathbf{x}_i + b) \ge 1, \quad \forall i = 1, \dots, N\\]

Geometricamente, a largura da margem entre os dois hiperplanos paralelos é calculada como:
\\[\text{Margem} = \frac{2}{\|\mathbf{w}\|}\\]

Maximizar a margem \\(\frac{2}{\|\mathbf{w}\|}\\) equivale matematicamente a **minimizar \\(\|\mathbf{w}\|\\)**, ou para fins de diferenciação no cálculo computacional, minimizar a função quadrática convexa \\(\frac{1}{2} \|\mathbf{w}\|^2\\):

\\[\min_{\mathbf{w}, b} \frac{1}{2} \|\mathbf{w}\|^2 \quad \text{sujeito a } y_i (\mathbf{w}^T \mathbf{x}_i + b) \ge 1, \quad \forall i\\]

---

### 3.2. Margem Suave (*Soft Margin*) e Variáveis de Folga (\\(\xi_i\\))

Em cenários industriais reais, os dados contêm ruído, sobreposição e medições imperfeitas, tornando a separação linear perfeita impossível. Para contornar essa restrição, Vapnik introduziu as **variáveis de folga** (\\(\xi_i \ge 0\\)), permitindo que algumas amostras invadam a margem ou sejam temporariamente classificadas de forma incorreta:

\\[y_i (\mathbf{w}^T \mathbf{x}_i + b) \ge 1 - \xi_i, \quad \xi_i \ge 0, \quad \forall i\\]

A nova função objetivo a ser minimizada passa a ser:
\\[\min_{\mathbf{w}, b, \boldsymbol{\xi}} \left( \frac{1}{2} \|\mathbf{w}\|^2 + C \sum_{i=1}^{N} \xi_i \right)\\]

#### O papel do Hiperparâmetro \\(C\\) (Custo de Regularização):
* **\\(C\\) Elevado:** Aplica uma penalidade severa a qualquer erro no treino. O algoritmo tenta zerar as folgas (\\(\xi_i \to 0\\)), resultando em margens mais estreitas. Isso pode causar **Overfitting** (o modelo memoriza o ruído das amostras).
* **\\(C\\) Baixo:** Torna o algoritmo mais permissivo a erros no treino. A margem de separação fica mais larga e generalizável, aumentando o viés mas reduzindo a variância do modelo.

---

### 3.3. A Formulação Dual e os Multiplicadores de Lagrange

Para resolver esse problema de otimização quadrática sujeita a restrições de desigualdade, constrói-se a **Função Lagrangeana Primal** utilizando os multiplicadores de Lagrange \\(\alpha_i \ge 0\\) e \\(\mu_i \ge 0\\):


$$\mathcal{L}(\mathbf{w}, b, \boldsymbol{\xi}, \boldsymbol{\alpha}, \boldsymbol{\mu}) = \frac{1}{2} \|\mathbf{w}\|^2 + C \sum_{i=1}^{N} \xi_i - \sum_{i=1}^{N} \alpha_i \left[ y_i (\mathbf{w}^T \mathbf{x}_i + b) - 1 + \xi_i \right] - \sum_{i=1}^{N} \mu_i \xi_i$$


Derivando \\(\mathcal{L}\\) em relação às variáveis primais (\\(\mathbf{w}\\), \\(b\\), \\(\xi_i\\)) e igualando a zero, chega-se à **Formulação Dual de Wolfe**:

$$\max_{\boldsymbol{\alpha}} \left( \sum_{i=1}^{N} \alpha_i - \frac{1}{2} \sum_{i=1}^{N} \sum_{j=1}^{N} \alpha_i \alpha_j y_i y_j (\mathbf{x}_i^T \mathbf{x}_j) \right)$$

$$\text{Sujeito a: } 0 \le \alpha_i \le C \quad \text{e} \quad \sum_{i=1}^{N} \alpha_i y_i = 0$$

#### Por que a Formulação Dual é Revolucionária?
1. **Dependência Exclusiva de Produtos Escalares:** A otimização não depende mais da dimensão explícita dos dados, mas apenas do produto escalar \\((\mathbf{x}_i^T \mathbf{x}_j)\\) entre os pares de amostras.
2. **Condições de Karush-Kuhn-Tucker (KKT) e Esparsidade:** As condições de otimidade KKT exigem que \\(\alpha_i \left[ y_i (\mathbf{w}^T \mathbf{x}_i + b) - 1 + \xi_i \right] = 0\\).
   * Para a grande maioria das amostras distantes da fronteira, \\(\alpha_i = 0\\).
   * Apenas para os pontos situados sobre a margem ou violando-a, teremos \\(\alpha_i > 0\\). Esses pontos são os **Vetores de Suporte**! O modelo final descarta todas as outras amostras do dataset e depende unicamente desse subconjunto esparso.

---

## 4. O Truque do Kernel (*Kernel Trick*) e Não-Linearidade

Quando as variáveis de processo formam padrões circulares ou agrupamentos complexos, traçar uma linha reta no espaço original resulta em erros massivos. 

A solução teórica seria aplicar uma função de transformação não linear \\(\phi(\mathbf{x})\\) que projeta os dados do espaço original \\(d\\)-dimensional para um espaço de atributos de dimensão muito mais alta \\(\mathcal{H}\\) (onde as classes passam a ser linearmente separáveis).

No entanto, calcular explicitamente \\(\phi(\mathbf{x})\\) para cada amostra em altas dimensões causaria uma **explosão combinatória de memória e tempo de CPU**.

### O Teorema de Mercer e o Truque do Kernel
O **Truque do Kernel** resolve esse impasse: se substituirmos o produto escalar de alta dimensão \\(\phi(\mathbf{x}_i)^T \phi(\mathbf{x}_j)\\) por uma **Função de Kernel** \\(K(\mathbf{x}_i, \mathbf{x}_j)\\), podemos calcular o resultado dessa projeção operando diretamente sobre os vetores no espaço original:

\\[K(\mathbf{x}_i, \mathbf{x}_j) = \phi(\mathbf{x}_i)^T \phi(\mathbf{x}_j)\\]

### Comparativo dos Principais Kernels
* **Kernel Linear:** \\(K(\mathbf{x}_i, \mathbf{x}_j) = \mathbf{x}_i^T \mathbf{x}_j\\). Usado quando os dados já são linearmente separáveis ou quando o número de variáveis é gigantesco.
* **Kernel RBF (*Radial Basis Function* / Gaussiano):** 
  \\[K(\mathbf{x}_i, \mathbf{x}_j) = \exp\left(-\gamma \|\mathbf{x}_i - \mathbf{x}_j\|^2\right)\\]
  onde \\(\gamma > 0\\) representa a largura ou alcance do raio de influência de cada vetor de suporte.

#### A Intuição do Parâmetro \\(\gamma\\) no Kernel RBF:
* **\\(\gamma\\) Elevado:** O raio de alcance de cada amostra fica extremamente curto. O modelo desenha "ilhas" ou curvas fechadas ao redor de pontos individuais de treino, levando ao **Overfitting**.
* **\\(\gamma\\) Baixo:** O raio de alcance é amplo. As curvas de decisão tornam-se suaves e contínuas, mas se for baixo demais, pode causar **Underfitting**.

---

## 5. Principais Dúvidas Práticas e Cuidados no Desenvolvimento

### 5.1 Por que o Escalonamento de Atributos (`StandardScaler`) é Obrigatório?

Em sensores industriais, a Rotação (RPM) oscila em milhares (\\(1800\\) RPM), enquanto a Vibração varia em decimais (\\(2.5\\) mm/s) e a Temperatura em centenas (\\(300\\) K).

Como o SVM calcula a margem otimizando distâncias euclidianas no espaço vetorial, **atributos com magnitudes elevadas dominariam \\(99\%\\) do cálculo vetorial**, ignorando completamente os sensores de menor escala.

#### Padronização via *Z-score*:

\\[z = \frac{x - \mu}{\sigma}\\]

O `StandardScaler` transforma todas as variáveis para que tenham **média zero (\\(\mu=0\\))** e **desvio padrão unitário (\\(\sigma=1\\))**.

> **Cuidado Teórico contra *Data Leakage*:** O ajuste (`fit`) do escalonador deve ser calculado **apenas no conjunto de treinamento**. Fazer o `fit` no dataset inteiro antes da divisão expõe o modelo a estatísticas do teste, corrompendo a validação científica do experimento.

---

### 5.2 Como Tratar o Desbalanceamento Extremo de Classes?

Em plantas industriais, \\(97\%\\) das leituras correspondem ao estado Normal (Classe 0) e apenas \\(3\%\\) correspondem a Falhas (Classe 1).

Se treinarmos o SVM sem ajustes, ele priorizará a classe majoritária para maximizar a acurácia, obtendo \\(97\%\\) de acerto ao **errar \\(100\%\\) das falhas reais** (o que geraria prejuízos catastróficos por paradas não planejadas).

#### A Solução via `class_weight='balanced'`:

Ao ativar essa opção, o Scikit-Learn recalcula o parâmetro \\(C\\) para cada classe proporcionalmente à sua raridade:

\\[w_j = \frac{N}{2 \times N_j}\\]

Dessa forma, o custo de cometer um erro em uma amostra de **Falha** passa a ser multiplicado por um peso substancialmente maior (\\(\approx 17.0\\)), enquanto o erro na classe **Normal** recebe peso menor (\\(\approx 0.51\\)). O hiperplano é forçado a se afastar da classe de falhas, aumentando expressivamente a métrica de **Recall**.

---

### 5.3 Como Usar o Limiar de Decisão (`decision_function`) para Reduzir Alarmes Falsos?

O método `.predict()` do SVM classifica como Falha qualquer amostra cuja pontuação no hiperplano atinja \\(\ge 0.0\\).

Em vez de aceitar o valor padrão, o engenheiro pode extrair a distância contínua de cada ponto até o hiperplano usando `decision_function(X_test)` e ajustar o limiar (ex: \\(\ge 0.5\\)) para calibrar o compromisso entre **Precisão** (confiabilidade dos alarmes) e **Recall** (taxa de captura de quebras).

---

## 6. Limitações, Restrições e Complexidade Computacional

Apesar de suas virtudes matematicamente comprovadas, o engenheiro deve estar ciente das restrições do algoritmo ao projetar sistemas industriais:

| Característica / Módulo | Detalhamento Técnico |
| :--- | :--- |
| **Complexidade no Treinamento** | O solver clássico do `SVC` (baseado na biblioteca `libsvm`) possui complexidade de tempo entre \\(\mathcal{O}(N^2 \cdot d)\\) e \\(\mathcal{O}(N^3 \cdot d)\\), onde \\(N\\) é o número de amostras. Em datasets com centenas de milhares de linhas, o treinamento torna-se inviável. Para *Big Data*, recomenda-se o uso de `LinearSVC` ou `SGDClassifier(loss='hinge')` com complexidade \\(\mathcal{O}(N \cdot d)\\). |
| **Falta de Probabilidades Naturais** | O SVM é um classificador não probabilístico que retorna apenas distâncias geométricas. Para converter saídas em probabilidades, utiliza-se a técnica de *Platt Scaling* (ajuste de uma regressão logística sobre as distâncias), que é apenas uma heurística assintótica. |
| **Sensibilidade a Hiperparâmetros** | O desempenho com Kernel RBF depende criticamente do ajuste conjunto da dupla \\((C, \gamma)\\). Uma escolha inadequada pode levar o modelo do *underfitting* ao *overfitting* rapidamente. |

---

## 7. Quadro Resumo de Conceitos-Chave

$$\begin{array}{|l|l|}
\hline
\textbf{Conceito} & \textbf{Definição Sintética} \\ \hline
\text{Hiperplano Separador} & \text{Superfície de decisão que divide as classes no espaço de atributos } (\mathbf{w}^T\mathbf{x} + b = 0). \\ \hline
\text{Vetores de Suporte} & \text{Amostras situadas sobre as margens ou violando-as } (\alpha_i > 0) \text{ que definem a fronteira.} \\ \hline
\text{Margem Rígida} & \text{Formulação estrita que exige separação perfeita sem qualquer violação.} \\ \hline
\text{Margem Suave} & \text{Formulação flexível que utiliza folgas } (\xi_i) \text{ e o parâmetro } C \text{ para tolerar ruídos.} \\ \hline
\text{Truque do Kernel} & \text{Computação do produto escalar em alta dimensão sem projetar explicitamente os dados.} \\ \hline
\text{Kernel RBF} & \text{Função de base radial gaussiana controlada pelo parâmetro de alcance } \gamma. \\ \hline
\text{StandardScaler} & \text{Padronização obrigatória das variáveis para média } 0 \text{ e desvio padrão } 1. \\ \hline
\end{array}$$

---
