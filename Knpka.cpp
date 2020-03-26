#include <Arduino.h>

int pin =13;
int pinD=2;
volatile int voltage = LOW;
volatile unsigned long last_press=0;
volatile unsigned long delta =100;

    void buttonTick() {
     if( millis()-last_press > delta){
    	 voltage =!voltage;
    	 last_press = millis();
//         Serial.println(voltage);
     }
    }

void setup() {
//Serial.begin(9600);
      pinMode(pin, OUTPUT);
      pinMode(pinD, INPUT);
      attachInterrupt(digitalPinToInterrupt(pinD), buttonTick, RISING);
 //     Serial.println(voltage);
    }

    void loop() {
      digitalWrite(pin, voltage);
    }

/* int flag=0;

void setup()
{
    pinMode(13, OUTPUT);
}

void loop()
{
     if(digitalRead(2)==HIGH&&flag==0)//если кнопка нажата
     {
       digitalWrite(13,!digitalRead(13));
       flag=1;
     }
      if(digitalRead(2)==LOW&&flag==1)//если кнопка НЕ нажата
      {
        flag=0;//обнуляем переменную flag
     }
}*/

