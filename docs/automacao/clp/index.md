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

## Aulas

| Aula | Título                                                                                                          | Conteúdo                                                                                                                                                                                                                                                                         | Material complementar |
| ---- | --------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------- |
| 01   | [Contexto histórico](slides/aula01-contexto_historico.pdf)                                                      | - O problema da indústria;<br>- O desafio da General Motors - 1968;<br>- Modular Digital Controller (MODICON 084);<br>- Ler-Decidir-Acionar;<br>- Definições (ABNT, NEMA e IEC);<br>- Tipos de CLPs (Compactos e Modulares);<br>- Fabricantes; <br>- Norma IEC 61131-3;          | 1. [Modicon: 50 anos de Pioneirismo e Inovações - Blog Schneider Electric](https://blog.se.com/br/automacao-industrial/2018/11/30/modicon-50-anos-de-pioneirismo-e-inovacoes/) <br> 2. [A história dos controladores programáveis - Altus](https://www.altus.com.br/post/505/a-historia-do-controlador-programavel) <br> 3. [Curiosidades sobre os CLPs ou PLC - O Professor Leandro](https://oprofessorleandro.wordpress.com/tag/modicon/) <br> 4. [The Modicon 084 PLC Literally Changed the World - Kalil4.0](https://youtu.be/FPhPDF8v6AA?si=Gjuso6V5BH2-OWYc) <br> 5. [Who is the Father of the PLC ? - RealPairs](https://youtu.be/4BxOizho1UE?si=6nlc-9I1SwYyh8mE) <br> 6. [Programable Logic Controller Basics Explained - automation engineering - The Engineering Mindset](https://youtu.be/uOtdWHMKhnw?si=geIVApkCKgSr-l6P) |
| 02   | [Descrição estrutural](slides/aula02-descricao_estrutural.pdf)                                                  | - Fonte de alimentação;<br>- Unidade Central de Processamento - *CPU*;<br>- Memórias;<br>- Entradas Digitais;<br>- Saídas Digitais;<br>- Comunicação;<br>- Expansão;<br>- Scan-time / Tempo de varredura;                                                                        | 1. [Programable Logic Controller Basics Explained - The Engineering Mindset](https://youtu.be/uOtdWHMKhnw?si=1IrKs67Iis5yiBli) <br> 2. [PLC Basics - Programmable Logic Controller - RealPairs](https://youtu.be/PbAGl_mv5XI?si=aiqbq88qaY9JAKWf) <br> 3. [PLC Hardware Components - Automatedo](https://youtu.be/wlCG8d2iQ5c?si=tq6QTypNT3LbYfkn) |
| 03   | [Descrição funcional](slides/aula03-descricao_funcional.pdf)                                                    | - Sinais de Entradas e Saídas;<br>- Mapa de Entradas e Saídas;<br>- Planejar e Executar - Partida de motor:<br> &emsp; - Contato aberto e contato fechado;<br> &emsp; - Bobina e Memória;<br>	&emsp; - Lógica Combinacional (E, OU e NÃO);<br>	&emsp; - Função Set e Reset |                       |
| 04   | [Maximização de contatos](slides/aula05-metodos_programacao_max.pdf) - <br>Cadeia estacionária ou Passo a passo | - Circuito Eletropneumático<br>- Sequência de Acionamento<br>- Bloco funcional                                                                                                                                                                                                   |                       |
| 05   | [Minimização de contatos](slides/aula06-metodos_programacao_min.pdf) - <br>Cascata, Sequência mínima            | - Circuito Eletropneumático<br>- Sequência de Acionamento<br>- Bloco funcional                                                                                                                                                                                                   |                       |



## TB131: Training Box Altus Duo



| Tema                          | Ferramenta/Periférico                                                                                                                                                                                 |
| ----------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Projeto                       | [Novo Projeto](altus_tb131/h1_1-novo_projeto.md)                                                                                                                                                      |
| Contatos e Bobinas            | [Set e Reset](altus_tb131/h1_2-setReset.md)<br>[Detecção de de borda](altus_tb131/h1_3-borda_subida_descida.md)                                                                                       |
| Temporidores                  | [Temporizadores](altus_tb131/h1_4-temporizadores.md)                                                                                                                                                  |
| Contadores                    | [Contadores](altus_tb131/h1_5-contadores.md)                                                                                                                                                          |
| Analógicos                    | [Entradas e Saídas Analogicas](altus_tb131/h1_6-entradas_saidas_analogicas.md)                                                                                                                        |
| Blocos funcionais úteis       | [Comparação](altus_tb131/h1_7_1-blocos_funcionais_comparacao.md)<br>[Aritméticos](altus_tb131/h1_7_2-blocos_funcionais_operacao.md)<br>[Seleção](altus_tb131/h1_7_3-blocos_funcionais_selecao.md)<br> |
| Função                        | [Função](altus_tb131/h1_8-funcao.md)<br>[Bloco Funcional](altus_tb131/h1_9-bloco_funcional.md)                                                                                                        |
| IHM - Interface Homem-Máquina | [Exibição de variável no display](altus_tb131/h1_10_1-ihm_display_var.md)<br>[Edição de variável](altus_tb131/h1_10_2-ihm_edita_var.md)                                                               |



## Situações de Aprendizagem


| #   | Situação de aprendizagem                                                           | Competências                                                                                                                                                                                                                                |
| --- | ---------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 01  | Partida direta de motor;                                                           |                                                                                                                                                                                                                                             |
| 02  | Partida direta com reversão                                                        |                                                                                                                                                                                                                                             |
| 03  | Sequência de movimentos: Maximização de contatos                                   |                                                                                                                                                                                                                                             |
| 04  | Sequência de movimentos: Minimização de contatos;                                  |                                                                                                                                                                                                                                             |
| 05  | [Partida Estrela-Triângulo](altus_tb131/A1_5-projeto_partida_estrela_triangulo.md) | - Declaração de Variáveis de Entradas e Saídas físicas no programa principal;<br>- Criação de Bloco Funcional;<br>- Declaração de variáveis no bloco funcional: VAR_INPUT, VAR_OUTPUT e VAR;<br>- Incluindo e executando o bloco funcional. |
| 06  | [Semáforo](altus_tb131/A1_6-projeto_semaforo.md)                                   |                                                                                                                                                                                                                                             |
| 07  | Acionamento Bi-manual;                                                             |                                                                                                                                                                                                                                             |
| 08  | Contagem de lotes;                                                                 |                                                                                                                                                                                                                                             |
| 09  | Entradas e Saídas analógicas;                                                      |                                                                                                                                                                                                                                             |
| 10  | IHM;                                                                               |                                                                                                                                                                                                                                             |
| 11  | Acionamento de motor de passo;                                                     |                                                                                                                                                                                                                                             |


