//Despertador com botão
//by Isadora Vanço :)

#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>

#define CLK 4
#define DIO 5
#define buzzer 6
#define btnDesliga 7
#define ledConfigurar 8
#define btnConfigurar 9 
#define ledHora 10
#define btnHora 11
#define ledMinuto 12
#define btnMinuto 13

RTC_DS3231 rtc;
TM1637Display display(CLK, DIO);

bool btnApertado = false, btnEstado;
byte hora = 0, minuto = 0;
int horaAlarme = 0, minutoAlarme = 0; 

void setup(){
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT);
 pinMode(btnConfigurar, INPUT_PULLUP);
 pinMode(ledConfigurar, OUTPUT);
 pinMode(btnHora, INPUT_PULLUP);
 pinMode(ledHora, OUTPUT);
 pinMode(btnMinuto, INPUT_PULLUP);
 pinMode(ledMinuto, OUTPUT);
 
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
  btnEstado = digitalRead(btnDesliga);

  if(hora == horaAlarme && minuto == minutoAlarme){
    Buzzer();
  }else{
    noTone(buzzer);
    btnApertado = false;
  }

  if(digitalRead(btnConfigurar) == HIGH){
    digitalWrite(ledConfigurar, HIGH);
    if(digitalRead(btnHora) == HIGH){
      horaAlarme++;
      if(horaAlarme == 24){
        horaAlarme = 0;
      }
      digitalWrite(ledHora, HIGH);
    }else if(digitalRead(btnHora) == LOW){
      digitalWrite(ledHora, LOW);
    }
    
    if(digitalRead(btnMinuto) == HIGH){
      minutoAlarme++;
      if(minutoAlarme == 60){
        minutoAlarme = 0;
      }
      digitalWrite(ledMinuto, HIGH);
    }else if(digitalRead(btnMinuto) == LOW){
      digitalWrite(ledMinuto, LOW);
    }
    
    display.showNumberDecEx((horaAlarme * 100) + minutoAlarme, 0x40, 1, 4, 0);
    
  }else{
    digitalWrite(ledConfigurar, LOW);
    digitalWrite(ledMinuto, LOW);
    digitalWrite(ledHora, LOW);
    display.showNumberDecEx((hora * 100) + minuto, 0x40, 1, 4, 0);
  }

  delay(100);
}

void Buzzer(){
  if(btnEstado == HIGH){
      btnApertado = true;
    }
  
  if(btnApertado == true){
    noTone(buzzer);
  }else{
    tone(buzzer, 2112);
  }
}
