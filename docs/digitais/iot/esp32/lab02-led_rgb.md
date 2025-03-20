---
title: Lab02 - LED RGB
icon: fontawesome/solid/circle-half-stroke
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - Conectividade
 - ESP32
---

![ESP32pinlayout](img/lab00-pinlayout.png)

---

# LED RGB

**Criando o primeiro componente**

```bash
idf.py -C ./components create-component led_rgb
```



- Arquivo: `.../main/CMakeLists.txt`
```py
idf_component_register( SRCS        "piscaLED.c"
                        REQUIRES    led_rgb
                        INCLUDE_DIRS ".")

```

---

- Arquivo: `.../components/led_rgb/CMakeLists.txt`
```py
idf_component_register( SRCS            "led_rgb.c"
                        REQUIRES        driver
                        INCLUDE_DIRS    "include")
```

---

- Arquivo: `.../main/piscaLED.c`
```C
#include "led_rgb.h"
```
