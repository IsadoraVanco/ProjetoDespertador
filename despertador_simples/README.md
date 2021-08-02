# Despertador Simples

## Oi de novo :)
Mais uma parte essencial para o projeto se desenvolver.

## Materiais utilizados
* Placa Arduino Uno;
* Módulo TM1637;
* Módulo RTC DS3231;
* Buzzer;
* Resistor de 10K Ohms;
* Resistor de 300 Ohms;
* Led colorido;
* Chave momentânea;
* Jumpers;

## Circuito
Aqui temos a adição de um botão e um led. O resistor de 10K Ohms será ligado entre o negativo do botão e o pino que vai ao Arduino, fazendo um Pull-Down. Além disso, o resistor de 300 Ohms fica entre o ânodo do led e o pino que vai ao Arduino.
* **GND** - liga os pinos GND de ambos os módulos, o led e o buzzer;
* **5V** - liga os pinos VCC de ambos os módulos e a chave momentânea;
* **A4** - pino SDA do DS3231;
* **A5** - pino SCL do DS3231;
* **4** - pino CLK do TM1637;
* **5** - pino DIO do TM1637;
* **8** - positivo do buzzer;
* **9** - botão que será usado para desligar o alarme;  
* **10** - anodo do led;

## O que deve acontecer?
Ao ligar o Arduino à energia, o display irá iniciar e mostrar o horário que está registrado no RTC, caso tenha acabado a bateria do módulo, ele irá receber o horário da máquina. Assim que a hora atual ser a mesma que a programada no alarme - por padrão, 00:00 -, o buzzer é acionado durante um minuto, caso não seja desligado com o botão da porta 9. Para programar o horário do alarme, ele terá de ser configurado manualmente no código (linha 19).

## Referências
Para o uso dos módulos, é preciso baixar as **bibliotecas** de cada um deles. Você pode encontra-las nos links:
*  [Biblioteca TM1637](https://github.com/avishorp/TM1637)
*  [Biblioteca DS3231](https://blogmasterwalkershop.com.br/arquivos/libs/RTClib.zip)  

Além disso, você pode encontrar os **datasheets** nos links:
*  [Datasheet TM1637](https://www.arduinoecia.com.br/downloads/Datasheet_TM1637_V2.4_EN.pdf)
*  [Datasheet DS3231](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)  

**Muito obrigada! :)**