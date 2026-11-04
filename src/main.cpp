#include <Arduino.h>
#include <ESP32Servo.h>

// PINES
#define RED_LED   12
#define GREEN_LED 13
#define BLUE_LED  14

Servo servo1, servo2;

void red_led()
{
  digitalWrite(RED_LED,HIGH);
  Serial.println("LED ROJO: ON");
  delay(1000);
  digitalWrite(RED_LED,LOW);
  Serial.println("LED ROJO: OFF");
}

void blue_led()
{
  digitalWrite(BLUE_LED,HIGH);
  Serial.println("LED AZUL: ON");
  delay(5000);
  digitalWrite(BLUE_LED,LOW);
  Serial.println("LED AZUL: OFF");
}

void green_led()
{
  digitalWrite(GREEN_LED,HIGH);
  Serial.println("LED VERDE: ON");
  delay(10000);
  digitalWrite(GREEN_LED,LOW);
  Serial.println("LED VERDE: OFF");
}

void servo1_control()
{
  for(int i = 0; 180 >= i; i++)
  {
    servo1.write(i);
    delay(15);
  }
  for(int i = 180; i >= 0; i--)
  {
    servo1.write(i);
    delay(15);
  }
}

void servo2_control()
{
  for(int i = 0; 180 >= i; i++)
  {
    servo2.write(i);
    delay(15);
  }
  for(int i = 180; i >= 0; i--)
  {
    servo2.write(i);
    delay(15);
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED,OUTPUT);
  digitalWrite(RED_LED,LOW);
  pinMode(GREEN_LED,OUTPUT);
  digitalWrite(GREEN_LED,LOW);
  pinMode(BLUE_LED,OUTPUT);
  digitalWrite(BLUE_LED,LOW);
  servo1.setPeriodHertz(50);
  servo1.attach(21, 500, 2400);
  servo2.setPeriodHertz(50);
  servo2.attach(22, 500, 2400);
  delay(1000);
}
void loop() {
  red_led();
  delay(1000);
  green_led(); 
  delay(5000);
  blue_led();
  delay(10000);
  servo1_control();
  delay(15);
  servo2_control();
  delay(15);
}

