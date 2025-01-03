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

## C4. Métodos de Programação
1. [Maximização de contatos](slides/aula05-metodos_programacao_max.pdf) - Cadeia estacionária ou Passo a passo
2. [Minimização de contatos](slides/aula06-metodos_programacao_min.pdf) - Cascata, Sequência mínima
3. Competências
	1. Circuito Eletropneumático
	2. Sequência de Acionamento
	3. Bloco funcional



## H1. Equipamento: Training Box (TB131) Altus

1. [Novo Projeto](altus_tb131/h1_1-novo_projeto.md)
2. [Set e Reset](altus_tb131/h1_2-setReset.md)
3. [Detecção de de borda](altus_tb131/h1_3-borda_subida_descida.md)
4. [Temporizadores](altus_tb131/h1_4-temporizadores.md)
5. [Contadores](altus_tb131/h1_5-contadores.md)
6. [Entradas e Saídas Analogicas](altus_tb131/h1_6-entradas_saidas_analogicas.md)
7. Blocos Funcionais Úteis
	1. [Comparação](altus_tb131/h1_7_1-blocos_funcionais_comparacao.md)
	2. [Aritméticos](altus_tb131/h1_7_2-blocos_funcionais_operacao.md)
	3. [Seleção](altus_tb131/h1_7_3-blocos_funcionais_selecao.md)
8. [Função](altus_tb131/h1_8-funcao.md)
9. [Bloco Funcional](altus_tb131/h1_9-bloco_funcional.md)
10. IHM - Interface Homem-Máquina
	1. [Exibição de variável no display](altus_tb131/h1_10_1-ihm_display_var.md)
	2. [Edição de variável](altus_tb131/h1_10_2-ihm_edita_var.md)





## A1. Situações de Aprendizagem

1. Partida direta de motor;
2. Partida direta com reversão;
3. Sequência de movimentos: Maximização de contatos;
4. Sequência de movimentos: Minimização de contatos;
5. [Partida Estrela-Triângulo](altus_tb131/A1_5-projeto_partida_estrela_triangulo.md)
	1. Declaração de Variáveis de Entradas e Saídas físicas no programa principal;
	2. Criação de Bloco Funcional;
	3. Declaração de variáveis no bloco funcional: VAR_INPUT, VAR_OUTPUT e VAR;
	4. Incluindo e executando o bloco funcional.
6. [Semáforo](altus_tb131/A1_6-projeto_semaforo.md)
7. Acionamento Bi-manual;
8. Contagem de lotes;
9. Entradas e Saídas analógicas;
10. IHM;
11. Acionamento de motor de passo;


