---
title: Lab - I2C
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

# I2C

I2C is a serial, synchronous, multi-device, half-duplex communication protocol that allows co-existence of multiple masters and slaves on the same bus. I2C uses two bidirectional open-drain lines: serial data line (SDA) and serial clock line (SCL), pulled up by resistors.

ESP32 has 2 I2C controller(s) (also called port), responsible for handling communication on the I2C bus.

A single I2C controller can be a master or a slave.

Typically, an I2C slave device has a 7-bit address or 10-bit address. ESP32 supports both I2C Standard-mode (Sm) and Fast-mode (Fm) which can go up to 100 kHz and 400 kHz respectively.

- The clock frequency of SCL in master mode should not be larger than 400 kHz.

- The frequency of SCL is influenced by both the pull-up resistor and the wire capacitance. Therefore, it is strongly recommended to choose appropriate pull-up resistors to make the frequency accurate. The recommended value for pull-up resistors usually ranges from 1 kΩ to 10 kΩ.
Keep in mind that the higher the frequency, the smaller the pull-up resistor should be (but not less than 1 kΩ). Indeed, large resistors will decline the current, which will increase the clock switching time and reduce the frequency. A range of 2 kΩ to 5 kΩ is recommended, but adjustments may also be necessary depending on their current draw requirements.




**Referências**

asdf

- [Inter-Integrated Circuit (I2C) | Espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/i2c.html)
-[MPU-6000 and MPU-6050 Product Specification Revision 3.4](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
- [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.0](https://cdn.sparkfun.com/datasheets/Sensors/Accelerometers/RM-MPU-6000A.pdf)
- [MPU-6000/MPU-6050 9-Axis Evaluation Board User Guide](https://media.digikey.com/pdf/Data%20Sheets/TDK%20PDFs/MPU-6000_6050_EvalBrd_UG.pdf)
