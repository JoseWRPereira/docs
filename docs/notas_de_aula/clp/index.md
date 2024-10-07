---
title: Controladores Programáveis
icon: fontawesome/solid/tachograph-digital
author: José W. R. Pereira
tags: 
    - CLP
    - Controlador programável
    - PLC
    - IFSP
---



# Controladores Programáveis



## C1. [Contexto histórico](slides/aula01-contexto_historico.pdf)

1. O problema da indústria;
2. O desafio da General Motors - 1968;
3. Modular Digital Controller (MODICON 084);
4. Ler-Decidir-Acionar;
5. Definições (ABNT, NEMA e IEC);
6. Tipos de CLPs (Compactos e Modulares);
7. Fabricantes;
8. Norma IEC 61131-3;



## C2. [Descrição estrutural](slides/aula02-descricao_estrutural.pdf)

1. Fonte de alimentação;
2. Unidade Central de Processamento - *CPU*;
3. Memórias;
4. Entradas Digitais;
5. Saídas Digitais;
6. Comunicação;
7. Expansão;
7. Scan-time / Tempo de varredura;



## C3. [Descrição funcional](slides/aula03-descricao_funcional.pdf)

1. Sinais de Entradas e Saídas;
2. Mapa de Entradas e Saídas;
3. Planejar e Executar - Partida de motor:
	1. Contato aberto e contato fechado;
	2. Bobina e Memória;
	3. Lógica Combinacional (E, OU e NÃO);
	4. Função Set e Reset

## C5. [Método de Programação - Maximização de contatos](slides/aula05-metodos_programacao_max.pdf)

1. Circuito Eletropneumático
2. Sequência de Acionamento
3. Bloco funcional
4. Maximização de contatos, Cadeia estacionária ou Passo a passo


## C6. [Método de Programação - Minimização de contatos](slides/aula06-metodos_programacao_min.pdf)

1. Circuito Eletropneumático
2. Sequência de Acionamento
3. Bloco funcional
4. Minimização de contatos, Cascata, Sequência mínima


## H1. Equipamento: Training Box (TB131) Altus

### 2024.2 - Atualizado
1. [Novo Projeto ("Hello, World!")](altus_tb131/h1_1-novo_projeto.md)
2. [Set e Reset](altus_tb131/h1_2-setReset.md)
3. [Detecção de de borda](altus_tb131/h1_3-setReset.md)
4. [Temporizadores](altus_tb131/h1_4-temporizadores.md)

### 2024.1 
2. [Declaração de Variáveis e Contato Auxiliar](altus_tb131/memoria.md)
6. [Display Variável](altus_tb131/ihm_display_var.md)
7. [Contador](altus_tb131/contador.md)
8. [Entradas e Saídas Analógicas](altus_tb131/analog_entradas_saidas.md)
9. [Edição de Variáveis](altus_tb131/ihm_edita_var.md)
10. [Motor de Passo e Encoder](altus_tb131/saidas_entradas_rapidas.md)




## A1. Situações de Aprendizagem

1. Partida direta de motor;
2. Partida direta com reversão;
3. Sequência de movimentos: Maximização de contatos;
4. Sequência de movimentos: Minimização de contatos;
5. [Projeto: Partida Estrela-Triângulo](altus_tb131/A1_5-projeto_partida_estrela_triangulo.md)
	1. Declaração de Variáveis de Entradas e Saídas físicas no programa principal;
	2. Criação de Bloco Funcional;
	3. Declaração de variáveis no bloco funcional: VAR_INPUT, VAR_OUTPUT e VAR;
	4. Incluindo e executando o bloco funcional.
6. Semáforo;
7. Acionamento Bi-manual;
8. Contagem de lotes;
9. Entradas e Saídas analógicas;
10. IHM;
11. Acionamento de motor de passo;


