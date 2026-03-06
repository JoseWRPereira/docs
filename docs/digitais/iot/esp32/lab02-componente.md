---
title: Lab02 - Componente
icon: fontawesome/solid/puzzle-piece
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - Conectividade
 - ESP32
---

![ESP32pinlayout](img/lab00-pinlayout.png)

---

# Componentes

No ecossistema do ESP-IDF, framawork oficial da Espressif, os `components` são formas de organizar o código de forma lógica, facilitando a manutenção e a reutilização de código. 

Qualquer pasta com um arquivo `CMakeLists.txt`, dentro da estrutura de projeto pode ser um componente, permitindo a modularidade através do encapsulamento de código e posterior portabilidade.

- Modularidade: Cada trecho com funcionalidade específica pode estar agrupado em um componente, sendo usado pelo arquivo principal que orquestra as chamadas e respostas. 

- Encapsulamento: Cada componente pode ter suas próprias configurações de compilação e dependências.

- Portabilidade: Pode-se copiar a pasta do componente de um projeto para outro de forma simples.

- Colaboração: Diferentes desenvolvedores podem trabalhar em componentes distintos sem gerar conflitos no código principal.

---

Segue uma ilustração de um projeto `piscaLED`. Foram excluídos diretórios produzidos de forma automática pelo ESP-IDF. 

![](img/comp-tree.png)

----



**1. Crie um novo projeto**

1. Crie um novo diretório para o projeto;
2. Abra-o no VSCode (ou no seu editor favorito);
3. Abra o terminal integrado

| Figura 1: Novo projeto e Terminal Integrado |
|:-------------------------------------------:|
| ![NovoProjeto](img/lab02-novo_terminal.png) |
| Fonte: Autor                                |


Para abrir o terminal integrado:

4. Pressione `Ctrl+Shift+'`, ou
5. No menu suspenso, clique em `Terminal` > `New Terminal`, ou
6. Clique sob o nome do diretório com o botão direito do mouse, e depois `Open in integrated Terminal`, como ilustrado na Figura 1.

---

**2. Habilite o ambiente de desenvolvimento no diretório local**

```ps1 title="PowerShell - Windows"
C:\Espressif\frameworks\esp-idf-v5.2.1\export.ps1 .
```
```sh title="Bash - GNU/Linux"
. $HOME/espressif/esp-idf/export.sh
```

Obs: O caminho do `export.ps1`/`export.sh` vai mudar em função do local escolhido durante a instalação do framework esp-idf.

---

**3. Criando um novo projeto**

```ps1
idf.py create-project -p . piscaLED
```

---

**4. Definindo dispositivo alvo**

```ps1
idf.py set-target esp32
```

---

**5. Construindo o projeto**

```ps1
idf.py build
```

---

**6. Criando um componente (pela primeira vez)**

```bash
idf.py -C ./components create-component led
```

---

**7. Criando código do componente**

```C title="esp32_component_builtinLED/components/led/led.c"
#include <stdio.h>
#include "driver/gpio.h"
#include "led.h"


/**********************************************************
 * @brief Inicializa pino conectado ao LED embarcado no módulo
 * @param -
**********************************************************/
void led_init( void )
{
    gpio_reset_pin(BUILTINLED_GPIO);
    gpio_set_direction(BUILTINLED_GPIO, GPIO_MODE_OUTPUT);
}



/**********************************************************
 * @brief Liga/Desliga LED embarcado no módulo
 * @param b  1 LED ON, 0 LED OFF
**********************************************************/
void led(char b)
{
    gpio_set_level(BUILTINLED_GPIO, b);
}
```


```C title="esp32_component_builtinLED/components/led/include/led.h"
#ifndef LED_H
#define LED_H

#define BUILTINLED_GPIO         2


void led_init( void );
void led(char b);


#endif
```

```C title="esp32_component_builtinLED/components/led/CMakeLists.txt"
idf_component_register( SRCS            "led.c"
                        REQUIRES        driver
                        INCLUDE_DIRS    "include")
```

---


**8. Criando código principal**

```C title="esp32_component_builtinLED/main/piscaLED.c"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "led.h"

void app_main(void)
{
    led_init();
    while( 1 )
    {
        led( 1 );
        vTaskDelay(500 / portTICK_PERIOD_MS);
        led( 0 );
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
```

```py title="esp32_component_builtinLED/main/CMakeLists.txt"
idf_component_register( SRCS            "piscaLED.c"
                        REQUIRES        led
                        INCLUDE_DIRS    ".")


```

---


**9. CMakeLists inicial**

```py title="esp32_component_builtinLED/CMakeLists.txt"
# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(piscaLED)
```

---

**10. Compilando o projeto**

```ps1
idf.py build
```

**11. Gravando o programa no dispositivo alvo**

```ps1
idf.py -p COM3 flash
```
