---
title: Lab06 - Modbus RTU
icon: fontawesome/solid/network-wired
author: José W. R. Pereira
tags:
    - Redes Industriais
    - Protocolos de Comunicação
    - RPI
---

# Lab. 06 - Modbus RTU (Remote Terminal Unit)



---


```c title="ModbusRTUserver"
    // Bibliotecas
#include <ArduinoRS485.h>   // ArduinoModbus depende da lib ArduinoRS485 (instalar via gerenciador)
#include <ArduinoModbus.h>  // Lib Arduino Modbus (instalar via gerenciador)

    // Parametros de comunicao
#define SLAVE_ID            1              // endereco do escravo Modbus RTU
#define BAUDRATE            9600          // 19200 bps
#define UART_CONFIG         SERIAL_8N1  // 8 data bits, sem paridade, 2 stop bits

    // Mapeamento dos pinos de entradas e saidas
const int inputDigitalMap[]   = { 8, 9 };     // pinos usados como entradas digitais - digital inputs
const int inputAnalogMap[]    = { A0, A1 };   // pinos usados como entradas analogicas - input registers
const int outputCoilMap[]     = { 11, 12 };   // pinos usados como saidas digitais - coils
const int outputPwmMap[]      = { 5, 6 };     // pinos usados como saidas analogicas (pwm) - holding register 16 bits
    // o pino 13, do led interno (LED_BUILTIN) utilizado para teste dos holding registers

    // Numero de entradas e saidas
#define DIGITAL_INPUTS_SIZE       (sizeof(inputDigitalMap)>>1)  // discrete inputs - bit
#define ANALOG_INPUTS_SIZE        (sizeof(inputAnalogMap)>>1)   // input registers - 16 bits
#define COILS_SIZE                (sizeof(outputCoilMap)>>1)    // coils - bit
#define PWM_OUTPUTS_SIZE          (sizeof(outputPwmMap)>>1)     // holding registers - 16 bits
#define HOLDING_REGISTERS_SIZE    8                             // 8 variaveis internas (holding registers - 16 bits)

    // Enderecos iniciais dos registradores - 16 enderecos para cada tipo
#define DIGITAL_INPUT_ADDRESS   0x0000
#define ANALOG_INPUT_ADDRESS    0x0010
#define COIL_ADDRESS            0x0020
#define PWM_OUTPUTS_ADDRESS     0x0030
#define HOLDING_REGS_ADDRESS    PWM_OUTPUTS_ADDRESS + PWM_OUTPUTS_SIZE  // endereco das variaveis internas comeca depois dos pwm

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// Configuracoes

void setup() 
{

///////////////////////////////////////////////////// Arduino

  for(int i = 0; i < DIGITAL_INPUTS_SIZE; i++) 
  {
    pinMode(inputDigitalMap[i], INPUT_PULLUP);      // Entradas com Pull-up habilitado
  }

  for (int i = 0; i < COILS_SIZE; i++) 
  {
    pinMode(outputCoilMap[i], OUTPUT);              // Saídas
    digitalWrite(outputCoilMap[i], LOW);            // Inicializadas com 0
  }

  for (int i = 0; i < PWM_OUTPUTS_SIZE; i++) 
  {
    analogWrite(outputPwmMap[i], 0);                // Saídas Analógicas com PWM=0
  }

  pinMode(LED_BUILTIN, OUTPUT);                     // LED da placa

////////////////////////////////////////////////////// Servidor Modbus RTU
 
  if (!ModbusRTUServer.begin(SLAVE_ID, BAUDRATE, UART_CONFIG)) 
  {
    Serial.println("Falhou ao iniciar o Servidor Modbus RTU!");
    while (1)
      ;
  }

    // Associa os enderecos de registradores do servidor modbus para as entradas e saídas definidas 
  ModbusRTUServer.configureDiscreteInputs(DIGITAL_INPUT_ADDRESS, DIGITAL_INPUTS_SIZE);
  ModbusRTUServer.configureInputRegisters(ANALOG_INPUT_ADDRESS, ANALOG_INPUTS_SIZE);
  ModbusRTUServer.configureCoils(COIL_ADDRESS, COILS_SIZE);
  ModbusRTUServer.configureHoldingRegisters(PWM_OUTPUTS_ADDRESS, PWM_OUTPUTS_SIZE + HOLDING_REGISTERS_SIZE);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////// Sincroniza entradas e saidas com o Modbus RTU Server

void loop() 
{
  
  ModbusRTUServer.poll();               // Verifica requisicoes Modbus RTU recebidas e atualiza dados no servidor


  // Rotina de atualizacao das ENTRADAS
  // atualiza o estado das entradas mapeadas na memoria do servidor

  for (int i = 0; i < DIGITAL_INPUTS_SIZE; i++) 
  {
    ModbusRTUServer.writeDiscreteInputs(DIGITAL_INPUT_ADDRESS + i, digitalRead(inputDigitalMap[i]), 1);
  }

  for (int i = 0; i < ANALOG_INPUTS_SIZE; i++) 
  {
    uint16_t tempRead = analogRead(inputAnalogMap[i]);
    ModbusRTUServer.writeInputRegisters(ANALOG_INPUT_ADDRESS + i, &tempRead, 1);
  }

  // Rotina de atualizacao das SAIDAS
  // escreve estado das saidas mapeadas conforme a memoria atual do servidor

  for (int i = 0; i < COILS_SIZE; i++) 
  {
    digitalWrite(outputCoilMap[i], ModbusRTUServer.coilRead(COIL_ADDRESS + i));
  }

  for (int i = 0; i < PWM_OUTPUTS_SIZE; i++) 
  {
    analogWrite(outputPwmMap[i], ModbusRTUServer.holdingRegisterRead(PWM_OUTPUTS_ADDRESS + i));
  }

  // Rotina de atualizacao das vars analógicas pós pwm

  // Teste de leitura dos holding registers (word, 16 bits)
  uint16_t testValue = ModbusRTUServer.holdingRegisterRead(PWM_OUTPUTS_ADDRESS + PWM_OUTPUTS_SIZE + 0);
  if (testValue > 1000) 
    digitalWrite(LED_BUILTIN, HIGH);
  else 
    digitalWrite(LED_BUILTIN, LOW);

  // Teste de escrita dos holding registers
  // o holding register com offset 1 guarda o tempo decorrido em segundos desde a inicializacao do Arduino
  uint16_t seconds = millis() / 1000;
  ModbusRTUServer.holdingRegisterWrite(PWM_OUTPUTS_ADDRESS + PWM_OUTPUTS_SIZE + 1, seconds);
}

```