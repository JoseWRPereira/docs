---
title: Lab01 - Novo Projeto
icon: fontawesome/solid/earth-americas
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - FPGA
 - DE1-SoC
---

![Board](img/lab00-board.png)



| Figura 1: Novo Projeto                             |
|:--------------------------------------------------:|
| ![newProjectWizard](img/lab01-newProjectWizard.png)|
| Fonte: Autor                                       |


| Figura 2: Identificação do projeto        |
|:-----------------------------------------:|
| ![newProject](img/lab01-nome_projeto.png) |
| Fonte: Autor                              |

| Figura 3: Seleção de placa e simulação    |
|:-----------------------------------------:|
| ![board_sim](img/lab01-board_sim.png)     |
| Fonte: Autor                              |




| Figura 4: Novo arquivo - Diagrama de Blocos             |
|:-------------------------------------------------------:|
| ![new_file](img/lab01-novo_arquivo_diagramaBlocos.png)  |
| Fonte: Autor                                            |

| Figura 5: Importação de atribuição de pinos             |
|:-------------------------------------------------------:|
| ![pinAssignments](img/lab01-importAssignments.png)      |
| Fonte: Autor                                            |


[Intel® Quartus® Prime Design Software Setting File with Pin Assignments](https://www.intel.com/content/www/us/en/developer/articles/technical/fpga-academic-boards.html)
[DE1-SoC.qsf](qsf/DE1_SoC.qsf)


| Figura 6: Inserindo portas lógicas básicas              |
|:-------------------------------------------------------:|
| ![symbolTool](img/lab01-symbolTool.png)                 |
| Fonte: Autor                                            |

| Figura 7: Inserindo elementos primitivos                |
|:-------------------------------------------------------:|
| ![primitives_logic](img/lab01-primitives_logic.png)     |
| Fonte: Autor                                            |

| Figura 8: Inserindo conectores                          |
|:-------------------------------------------------------:|
| ![conectores](img/lab01-in_out_inout.png)               |
| Fonte: Autor                                            |


| Figura 9: Alocando os pinos                             |
|:-------------------------------------------------------:|
| ![pinPlanner](img/lab01-pinPlanner.png)                 |
| Fonte: Autor                                            |


| Figura 10: Compilando o circuito                        |
|:-------------------------------------------------------:|
| ![compileDesign](img/lab01-compileDesign.png)           |
| Fonte: Autor                                            |

| Figura 11: Abrindo o Program Device                     |
|:-------------------------------------------------------:|
| ![programDevice](img/lab01-hardware_setup.png)          |
| Fonte: Autor                                            |

| Figura 12: Auto Detect                                  |
|:-------------------------------------------------------:|
| ![autoDetect](img/lab01-autoDetect.png)                 |
| Fonte: Autor                                            |


| Figura 13: Output_files                                 |
|:-------------------------------------------------------:|
| ![output_files](img/lab01-output_files.png)             |
| Fonte: Autor                                            |

| Figura 14: Gravar dispositivo                           |
|:-------------------------------------------------------:|
| ![gravar_dispositivo](img/lab01-start_prog.png)             |
| Fonte: Autor                                            |


| Figura 15: Operação de lógica E                         |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-operacao.png)                     |
| Fonte: Autor                                            |


# Referências

1. [Quartus com Questa:Escolhendo o hardware | Nets&Nuts](https://nets-nuts.com.br/quartus-com-questa-modelsim-instalacao-e-configuracao-1/)

| Figura : Questa Install                                 |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-questa_install.png)               |
| Fonte: Autor                                            |

| Figura : Questa Install                                 |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-questa_install-2.png)             |
| Fonte: Autor                                            |

| Figura : Modelsim Install                               |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-modelsim_install.png)             |
| Fonte: Autor                                            |

| Figura : Modelsim Install                               |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-modelsim_install-2.png)           |
| Fonte: Autor                                            |


| Figura : EDA licenseSetup_sim                           |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-EDAlicenseSetup_sim.png)          |
| Fonte: Autor                                            |

| Figura : EDA tool Option_sim                            |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-EDAtoolOption_sim.png)            |
| Fonte: Autor                                            |

| Figura : EDA tool Setting_sim                           |
|:-------------------------------------------------------:|
| ![operacao](img/lab01-EDAtoolSetting_sim.png)           |
| Fonte: Autor                                            |


```bash title=".bashrc"
export LM_LICENSE_FILE="$HOME/intelFPGA_lite/24.1std/licenses/LR-NNNNNN_License.dat"
```



QuestaSim: /home/josewrpereira/intelFPGA_lite/24.1std/questa_fse/bin
Qesta Intel F?: /home/josewrpereira/intelFPGA_lite/24.1std/questa_fse/linux_x86_64
ModelSim: /home/josewrpereira/intelFPGA/20.1/modelsim_ase/bin
