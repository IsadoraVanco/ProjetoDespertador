# Despertador com botões

## Hey! :)
Perdido por aqui? Este projeto é uma evolução do primeiro Despertador, com algumas melhoras incluindo ajustar o horário para despertar utilizando botões.

## Materiais utilizados
* Placa Arduino Uno;
* Módulo TM1637;
* Módulo RTC DS3231;
* Buzzer;
* (4) Resistores de 10K Ohms;
* (3) Resistores de 300 Ohms;
* (3) Leds coloridos;
* (4) Chaves momentâneas;
* Jumpers;

## Circuito
Em comparação com o projeto anterior, temos a adição de 3 botões e 2 leds. Os resistores de 10K Ohms serão ligados entre o negativo dos botões e os pinos que vão ao Arduino, fazendo um Pull-Down. Além disso, os resistores de 300 Ohms ficam entre o ânodo de cada led e o pino que vai ao Arduino. 
* **GND** - liga os pinos GND de ambos os módulos, os leds e o buzzer;
* **5V** - liga os pinos VCC de ambos os módulos e as chaves momentâneas;
* **A4** - pino SDA do DS3231;
* **A5** - pino SCL do DS3231;
* **4** - pino CLK do TM1637;
* **5** - pino DIO do TM1637;
* **6** - positivo do buzzer;
* **7** - botão que será usado para desligar o alarme;
* **8** - anodo do led de configuração;
* **9** - botão que será usado para configurar o alarme;
* **10** - anodo do led das horas;
* **11** - botão que será usado para alterar as horas;
* **12** - anodo do led dos minutos;
* **13** - botão que será usado para alterar os minutos;

## O que deve acontecer?
Ao ligar o Arduino à energia, o display irá iniciar e mostrar o horário que está registrado no RTC, caso tenha acabado a bateria do módulo, ele irá receber o horário da máquina. Assim que a hora atual ser a mesma que a programada no alarme - por padrão, 00:00 -, o buzzer é acionado durante um minuto - Acha pouco tempo? Digamos que o som de um buzzer ligado a uma frequência da sétima oitava da nota Dó, não seja algo aconchegante de ouvir quando acordar -, caso não seja desligado com o botão da porta 7. Para programar o horário do alarme, basta segurar o botão da porta 9 enquanto aperta os botões de hora (porta 11) ou dos minutos (porta 13).

## Referências 
Para o uso dos módulos, é preciso baixar as **bibliotecas** de cada um deles. Você pode encontra-las nos links:
*  [Biblioteca TM1637](https://github.com/avishorp/TM1637)
*  [Biblioteca DS3231](https://blogmasterwalkershop.com.br/arquivos/libs/RTClib.zip)

Além disso, você pode encontrar os **datasheets** nos links:
*  [Datasheet TM1637](https://www.arduinoecia.com.br/downloads/Datasheet_TM1637_V2.4_EN.pdf)
*  [Datasheet DS3231](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)

**Muito obrigada! :)**