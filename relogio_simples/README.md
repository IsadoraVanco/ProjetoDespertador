# Relógio

## Olá! :)
Este projeto é o primeiro passo para algo mais completo. Meu primeiro projeto feito por mim mesma utilizando a plataforma Arduino.

## Materiais utilizados
* Placa Arduino Uno;
* Módulo TM1637;
* Módulo RTC DS3231;
* Jumpers;

## Circuito
Utilizando um circuito simples, aqui está as ligações de cada porta do Arduino:
* **GND** - liga os pinos GND de ambos os módulos;
* **5V** - liga os pinos VCC de ambos os módulos;
* **A4** - pino SDA do DS3231;
* **A5** - pino SCL do DS3231;
* **4** - pino CLK do TM1637;
* **5** - pino DIO do TM1637;

## O que deve acontecer?
Assim que a placa Arduino estiver energizada, o display do módulo TM1637 deverá acender, caso o módulo RTC DS3231 tenha sido ligado pela primeira vez, ou tenha acabado a bateria, ele receberá o horário da máquina que ele está ligado. Como o próprio nome diz, ele terá uma única função: marcar horas.

## Referências
Para o uso dos módulos, é preciso baixar as **bibliotecas** de cada um deles. Você pode encontra-las nos links:
*  [Biblioteca TM1637](https://github.com/avishorp/TM1637)
*  [Biblioteca DS3231](https://blogmasterwalkershop.com.br/arquivos/libs/RTClib.zip)

Além disso, você pode encontrar os **datasheets** nos links:
*  [Datasheet TM1637](https://www.arduinoecia.com.br/downloads/Datasheet_TM1637_V2.4_EN.pdf)
*  [Datasheet DS3231](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)

**Muito obrigada! :)**