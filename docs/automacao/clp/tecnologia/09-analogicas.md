---
title: 09 - Analógicas
icon: fontawesome/solid/water
author: José W. R. Pereira
tags:
    - CLP
    - Controlador programável
    - PLC
---

#

# Analógicas


As **entradas e saídas analógicas** de um Controlador Lógico Programável (CLP) são interfaces que permitem a interação com grandezas físicas que variam continuamente ao longo do tempo. Diferente dos sinais digitais, que possuem apenas dois estados (ligado ou desligado), os sinais analógicos podem assumir **infinitos valores dentro de uma escala** específica.

## Características das Entradas Analógicas

As entradas analógicas são utilizadas para **monitorar variáveis de processo** como temperatura, pressão, nível, vazão e velocidade. 

*   **Conversão A/D:** O sinal analógico recebido do sensor é processado por um **conversor analógico-digital (A/D)**, que transforma a grandeza física em um valor digital (binário) que a CPU do CLP consegue interpretar.
*   **Tipos de Sinais:** Os sinais mais comuns no ambiente industrial são de **tensão (tipicamente 0 a 10 V )** e **corrente (geralmente 4 a 20 mA ou 0 a 20 mA)**.
*   **Sinais Unipolares e Bipolares:** Módulos **unipolares** operam apenas com valores positivos, enquanto os **bipolares** podem medir sinais que oscilam entre valores negativos e positivos.
*   **Resolução:** A precisão da leitura depende da resolução do módulo, geralmente expressa em **bits**; por exemplo, um módulo de 12 bits divide a escala em 4.096 combinações, permitindo detectar variações muito pequenas no sinal.

## Características das Saídas Analógicas

As saídas analógicas permitem ao CLP **controlar dispositivos** que exigem atuação proporcional, como válvulas de controle, inversores de frequência e acionadores eletrônicos.

*   **Conversão D/A:** O processador envia um valor digital que é transformado em um sinal elétrico proporcional por um **conversor digital-analógico (D/A)**.
*   **Canais e Conexões:** Esses módulos são organizados em **canais** (geralmente 4, 8 ou 16 por módulo) e as conexões podem ser do tipo **terminal único** (com um terra comum) ou **diferencial** (com terminais positivos e negativos separados para cada canal, o que reduz ruídos).

### Proteção e Integridade do Sinal

*   **Imunidade a Ruídos:** Sinais de corrente (4-20 mA) são menos suscetíveis a interferências eletromagnéticas do que sinais de tensão.
*   **Cabeamento:** Para garantir a integridade dos dados, recomenda-se o uso de **cabos de par trançado blindado**, especialmente para sensores sensíveis como termopares.

---


---

## Equipamentos 

- ### [Altus TB131 - Anaógicas](../altus_tb131/lab08-entradas_saidas_analogicas.md)


---

# Referências


1. ALTUS. **O que é CLP e quando utilizá-lo?**. [S. l.: s. n.], [202-?]. Disponível em: <https://www.altus.com.br/post/490/o-que-e-clp-e-quando-utiliza-lo-3f>. Acesso em: 30 mar. 2026.

2. FAGUNDES, Sueli Ferreira; ALMEIDA, Carla Aparecida C. de. **Curso de Controladores Lógicos Programáveis**. Rio de Janeiro: Universidade do Estado do Rio de Janeiro, LEE - Laboratório de Engenharia Elétrica, [199-?].

3. GEORGINI, Marcelo. **Automação Aplicada**: descrição e implementação de sistemas sequenciais com PLCs. 9. ed. São Paulo: Érica, 2007.

4. MITSUBISHI ELECTRIC BRASIL. **CLP: O que é, para que serve e como funciona na indústria**. [S. l.: s. n.], [202-?]. Disponível em: <https://www.youtube.com/watch?v=R9Xm737D-L8>. Acesso em: 30 mar. 2026.

5. PETRUZELLA, Frank D. **Controladores Lógicos Programáveis**. 4. ed. Porto Alegre: AMGH, 2014.




---