# Acenda a luz!

## O que é isto? :)
A primeira versão modificada de um despertador comum. Você precisará acender a luz!

## Materiais utilizados
* Placa Arduino Uno;
* Módulo TM1637;
* Módulo RTC DS3231;
* Buzzer;
* (4) Resistores de 10K Ohms;
* (3) Resistores de 300 Ohms;
* (3) Leds coloridos;
* (3) Chaves momentâneas;
* LDR;
* Jumpers;

## Circuito
Nesta primeira versão modificada, temos a luz como o quesito para desligar o alarme, portanto usaremos o LDR ao invés de um botão. Os resistores de 10K Ohms serão ligados entre o negativo dos botões e os pinos que vão ao Arduino, fazendo um Pull-Down. O mesmo acontece com o LDR, ligado ao VCC de 5V em uma das "perninhas" e em outra, um resistor de 10K que vai ao GND, também o pino A0 do Arduino, nesta ordem. Além disso, os resistores de 300 Ohms ficam entre o ânodo de cada led e o pino que vai ao Arduino.  
* **GND** - liga os pinos GND de ambos os módulos, os leds e o buzzer;
* **5V** - liga os pinos VCC de ambos os módulos, as chaves momentâneas e o LDR;
* **A0** - recebe a leitura do LDR;
* **A4** - pino SDA do DS3231;
* **A5** - pino SCL do DS3231;
* **4** - pino CLK do TM1637;
* **5** - pino DIO do TM1637;
* **6** - positivo do buzzer;
* **8** - anodo do led de configuração;
* **9** - botão que será usado para configurar o alarme;
* **10** - anodo do led das horas;
* **11** - botão que será usado para alterar as horas;
* **12** - anodo do led dos minutos;
* **13** - botão que será usado para alterar os minutos;

## O que deve acontecer?
Ao ligar o Arduino à energia, o display irá iniciar e mostrar o horário que está registrado no RTC, caso tenha acabado a bateria do módulo, ele irá receber o horário da máquina. Assim que a hora atual ser a mesma que a programada no alarme - por padrão, 00:00 -, o buzzer é acionado durante um minuto, caso a luz do ambiente estiver apagada, ou com pouca luz. É importante lembrar que o valor de intensidade deve ser alterado para cada caso. Para programar o horário do alarme, basta segurar o botão da porta 9 enquanto aperta os botões de hora (porta 11) ou dos minutos (porta 13).

## Referências 
Para o uso dos módulos, é preciso baixar as **bibliotecas** de cada um deles. Você pode encontra-las nos links:
*  [Biblioteca TM1637](https://github.com/avishorp/TM1637)
*  [Biblioteca DS3231](https://blogmasterwalkershop.com.br/arquivos/libs/RTClib.zip)

Além disso, você pode encontrar os **datasheets** nos links:
*  [Datasheet TM1637](https://www.arduinoecia.com.br/downloads/Datasheet_TM1637_V2.4_EN.pdf)
*  [Datasheet DS3231](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)

**Muito obrigada! :)**