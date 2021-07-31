//Relógio Simples 
//by Isadora Vanço :)

#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>

#define CLK 4
#define DIO 5

RTC_DS3231 rtc;
TM1637Display display(CLK, DIO);

byte hora = 0, minuto = 0;

void setup(){
 Serial.begin(9600);

 display.setBrightness(0x0f);
 
 rtc.begin();
 
 if(!rtc.begin()){
  Serial.println("Módulo DS3231 não encontrado");
  while(true);
 }
 if(rtc.lostPower()){
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("Módulo DS3231 pronto");
 }

 delay(500); 
}

void loop(){
  DateTime now = rtc.now();
  hora = now.hour();
  minuto = now.minute();
  display.showNumberDecEx((hora * 100) + minuto, 0x40, 1, 4, 0);
  
  delay(1000);
}
