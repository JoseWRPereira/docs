---
title: 11 - Blocos Funcionais Personalizados
icon: fontawesome/solid/cube
author: José W. R. Pereira
tags:
    - CLP
    - Controlador programável
    - PLC
---

#

# Blocos Funcionais Personalizados


A criação de um **bloco funcional personalizado (BFP)**, permite ao programador definir algoritmos e lógicas que são utilizados com frequência, transformando-os em instruções reutilizáveis.


## 1. Definição e Comportamento

*   As instruções BFP são **representações gráficas de códigos executáveis** criadas pelo próprio usuário.
*   Uma vez definida no projeto, a instrução personalizada passa a aparecer na **fb def. pelo usuário** (aba "Inserir... Bloco Funcional") e se comporta exatamente como uma instrução padronizada do sistema.
*   Elas permitem simplificar sistemas complexos, encapsulando a lógica para que o usuário precise apenas preencher as informações necessárias dentro do bloco ao utilizá-lo em uma rotina.


## 2. Elementos do Bloco Personalizado
Ao criar a lógica interna do bloco (que pode ser feita em linguagens como Diagrama de Blocos Funcionais - FBD, Ladder, Structured Text, etc), utilizam-se:
*   **Parâmetros de Entrada e Saída:** Devem ser especificados na configuração do bloco para que ele possa receber dados à esquerda e gerar resultados à direita.
*   **Etiquetas (Tags):** As referências dentro do bloco representam etiquetas vinculadas à memória do controlador.
*   **Pinos e Fios:** No ambiente gráfico, os fios indicam o trajeto do sinal e os pinos de entrada e saída determinam como os dados fluem através da instrução BFP.





---

## Equipamentos 

- ### [Altus TB131 - Blocos Funcionais Personalizados](../altus_tb131/lab09-bloco_funcional.md)


---

# Referências

1. PETRUZELLA, Frank D. Controladores lógicos programáveis. Tradução de Romeu Abdo; revisão técnica de Antonio Pertence Júnior. 4. ed. Porto Alegre: AMGH, 2014.

2. GEORGINI, Marcelo. Automação Aplicada: Descrição e Implementação de Sistemas Sequenciais com PLCs. 9. ed. São Paulo: Érica, 2007.

3. FACULDADE DE ENGENHARIA DA UERJ. Curso de Controladores Lógicos Programáveis. Rio de Janeiro: Laboratório de Engenharia Elétrica, [s.d.].

4. ALTUS SISTEMAS DE AUTOMAÇÃO. O que é CLP e quando utilizá-lo?. São Leopoldo: Altus, 2025.

---