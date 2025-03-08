---
title: Lab00 - Ambientação
icon: fontawesome/solid/wifi
author:
 - José W. R. Pereira
tags:
 - Sistemas Eletrônicos
 - Conectividade
 - ESP32
---

![ESP32pinlayout](img/lab00-pinlayout.png)

---

# ESP32


## Criando um projeto na linha de comando

``` bash
idf.py create-project -p . <nome do projeto>

# Definindo o dispositivo alvo
idf.py set-target esp32

# Acessando o menu de configuração
idf.py menuconfig

```

``` bash
# Compilando o projeto
idf.py build

# Gravando o projeto
idf.py -p <port> flash


# Monitorando o projeto
idf.py -p <port> monitor

# Sair do monitoramento
# Ctrl+[ ou Ctrl+]

# Limpeza da compilação
idf.py fullclean
```


---

