---
title: Quartus - Simulação VWF
icon: fontawesome/solid/film
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---

*Vector Waveform File*
![lab2_capa](img/t04-sim_vwf_capa.png)

---

| Figura 1: Criando um novo projeto com assistente |
|:------------------------------------------------:|
| ![Board](img/t04-sim-vwf-01.png)               |
| Fonte: Autor                                     |

| Figura 2: Tipo de projeto e adição de arquivos   |
|:------------------------------------------------:|
| ![Board](img/t04-sim-vwf-02.png)               |
| Fonte: Autor                                     |

| Figura 3: Família, Dispositivo e Configuração de placa  |
|:-------------------------------------------------------:|
| ![Board](img/t04-sim-vwf-03.png)                      |
| Fonte: Autor                                            |

| Figura 4: Configuração da ferramenta EDA e Sumário  |
|:---------------------------------------------------:|
| ![Board](img/t04-sim-vwf-04.png)                  |
| Fonte: Autor                                     |


| Figura 5: Novo projeto criado      |
|:----------------------------------:|
| ![Board](img/t04-sim-vwf-05.png) |
| Fonte: Autor                       |

| Figura 6: Criação do arquivo de esquemático |
|:-------------------------------------------:|
| ![Board](img/t04-sim-vwf-06.png) |
| Fonte: Autor                       |


| Figura 7: Ambiente de simulação vwf (*Vector Waveform File*)|
|:-------------------------------------------:|
| ![Board](img/t04-sim-vwf-07.png) |
| Fonte: Autor                       |

| Figura 8: Ajustando tempo final da simulação |
|:--------------------------------------------:|
| ![Board](img/t04-sim-vwf-08.png) |
| Fonte: Autor                       |

| Figura 9: Inserindo elementos de simulação |
|:------------------------------------------:|
| ![Board](img/t04-sim-vwf-09.png) |
| Fonte: Autor                       |


| Figura 10: Inserindo sinal de simulação em uma entrada |
|:------------------------------------------------------:|
| ![Board](img/t04-sim-vwf-10.png) |
| Fonte: Autor                       |

| Figura 10: Inserindo sinal de simulação em uma entrada |
|:------------------------------------------------------:|
| ![Board](img/t04-sim-vwf-11.png) |
| Fonte: Autor                       |

| Figura 11: Ajustando parâmetros de compilação |
|:---------------------------------------------:|
| ![Board](img/t04-sim-vwf-12.png) |
| Fonte: Autor                       |


| Figura 12: Salvando arquivo de simulação |
|:----------------------------------------:|
| ![Board](img/t04-sim-vwf-13.png) |
| Fonte: Autor                       |

| Figura 13: Resultado da simulação  |
|:----------------------------------:|
| ![Board](img/t04-sim-vwf-14.png) |
| Fonte: Autor                       |


---

**Erros**

| Figura 14: Erro 1 - Parâmetro *-novopt* deve ser retirado |
|:-------------------------------------:|
| ![Board](img/t04-sim-vwf-erro1.png) |
| Fonte: Autor                          |

---

| Figura 14: Erro 2 - Saída indefinida  |
|:-------------------------------------:|
| ![Board](img/t04-sim-vwf-erro2.png) |
| Fonte: Autor                          |

Correção:

No **Quartus Prime**, (Não no *Simulation Waveform Edition*), acesse:

1. *Tools* -> *Options...*
2. Em *Category*, clique em *EDA Tools Options*
3. No campo *ModelSim* insira o diretório correspondente a: `C:/intelFPGA/20.1/modelsim_ase/win32aloem` da instalação do ModelSim.
4. Se não houver o ModelSim instalado, faça o [Download](https://www.intel.com/content/www/us/en/software-kit/750666/modelsim-intel-fpgas-standard-edition-software-version-20-1-1.html) e instale-o.
5. Execute o passo 3 e em seguida execute a simulação novamente.


---
