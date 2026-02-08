---
title: 1. Pisca LED
icon: fontawesome/solid/lightbulb
author: José W. R. Pereira
tags: 
    - Arduino UNO
---

#

# TinkerCad

![Blink](img/uno01-blink.png)


# SimulIDE

| Ligação do pino como fonte (Source) | Ligação do pino como dreno (Sink) |
|:-----------------------------------:|:---------------------------------:|
|![pinSouce](img/01-pin_source.gif)  | ![pinSink](img/01-pin_sink.gif)  |

# Código Fonte

```C
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  	digitalWrite(LED_BUILTIN, HIGH);  
  	delay(1000); 
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); 
}
```

---

# Referências

1. [Arduino Builtin Examples - Blink](https://docs.arduino.cc/built-in-examples/basics/Blink/?_gl=1*1l1ps36*_up*MQ..*_ga*MTk3MjQxOTcwOC4xNzcwMzMyNjA1*_ga_NEXN8H46L5*czE3NzAzMzI2MDMkbzEkZzEkdDE3NzAzMzI3MDYkajQzJGwwJGgxNjY5MDAwODU0)


---
