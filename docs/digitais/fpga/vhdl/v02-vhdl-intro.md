---
title: Iniciação no VHDL
icon: fontawesome/solid/hard-drive
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - VHDL
---

---

```vhdl title="nome_da_entidade.vhdl"
-- --------------------------------------------------------
--     Cabeçalho de código em comentários de linha
-- Sistemas Digitais Programáveis - 2025-2
-- Código: Estrutura básica do código em VHDL
-- Autor: José W. R. Pereira
-- Data: 2025-09-08
-- --------------------------------------------------------

-- Bibliotecas e Pacotes

-- Entidade: interface de entradas e saídas
entity nome_da_entidade is
    port(
          -- variavel: direcao_de_dados tipo_de_dado;
          -- variavel: direcao_de_dados tipo_de_dado
        );
end entity nome_da_entidade;


-- Arquitetura: descrição de comportamento
architecture main of nome_da_entidade is
-- declaração de objetos
begin
    -- descrição do comportamento
end architecture main;
```


---

```vhdl title="vhdl_portaE"
-- --------------------------------------------------------
-- Sistemas Digitais Programáveis - 2025-2
-- Código: Porta lógica E (AND)
-- Autor: José W. R. Pereira
-- Data: 2025-09-08
-- --------------------------------------------------------

-- Bibliotecas e Pacotes

-- Entidade: interface de entradas e saídas
entity vhdl_portaE is port( a, b: in bit; y: out bit );
end entity vhdl_portaE;


-- Arquitetura: descrição de comportamento
architecture main of vhdl_portaE is
-- declaração de objetos
begin
    y <= a and b;
end architecture main;
```

---


```vhdl title="somador4bits"
-- --------------------------------------------------------
-- Sistemas Digitais Programáveis - 2025-2
-- Código: Somador de 4 bits
-- Autor: José W. R. Pereira
-- Data: 2025-09-08
-- --------------------------------------------------------

-- Bibliotecas e Pacotes

-- Entidade
entity vhdl_somador4bits is
    port(
            a,b: in integer range 0 to 15;  -- declaração de entradas de 4 bits
            y: out integer range 0 to 15    -- declaração de saída de 4 bits
        );
end entity vhdl_somador4bits;

-- Arquitetura
architecture main of vhdl_somador4bits is
begin
    y <= a + b;
end architecture main;
```

---

```vhdl title="interfaces.vhdl"
entity interfaces is
  generic (
              n: tipo := valor -- constante
          );
  port    (
              a,b: in tipo1;      -- entradas
              y1,y2: out tipo2;   -- saídas (não podem ser lidas)
              w: buffer tipo 3;   -- saída  (pode ser lida)
              z1, z2: inout tipo3 -- entrada/saída
          );
end entity interfaces;


architecture nome_arc of interfaces is

-- Declarações
-- Sinais
-- Componentes
-- Subprogramas
-- Novos tipos
-- outros

begin

-- Comandos concorrentes

end architecture nome_arc;
```


---

**Referências**

1. D'AMORE, Roberto. VHDL: descrição e síntese de circuitos digitais. 2. ed. Rio
de Janeiro: LTC, 2012.
2. [Curso VHDL - O Código da Eletrônica](https://youtube.com/playlist?list=PLYE3wKnWQbHDdnb3FsDkNx2tj8xoQAPtN&si=7aHA5SoGaX29JoGp)
