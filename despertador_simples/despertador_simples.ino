//Despertador simples
//by Isadora Vanço :)

#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>

#define CLK 4
#define DIO 5
#define buzzer 8
#define btn 9
#define led 10

RTC_DS3231 rtc;
TM1637Display display(CLK, DIO);

bool btnApertado = false, btnEstado;
byte hora = 0, minuto = 0;
int horaAlarme = 0, minutoAlarme = 0; //Definidos manualmente

void setup(){
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT);
 pinMode(btn, INPUT_PULLUP);
 pinMode(led, OUTPUT);

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
  btnEstado = digitalRead(btn);

  if(hora == horaAlarme && minuto == minutoAlarme){
    Buzzer();
  }else{
    noTone(buzzer);
    btnApertado = false;
    digitalWrite(led, LOW);
  }
}

void Buzzer(){
  if(btnEstado == HIGH){
    btnApertado = true;
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
  if(btnApertado == true){
    noTone(buzzer);
  }else{
    tone(buzzer, 2112);
  }
}
