#include <Arduino.h>
#include <ESP32Servo.h>

// PINES
#define RED_LED   12
#define GREEN_LED 13
#define BLUE_LED  14
#define SERVO_1   21
#define SERVO_2   22

// DELAY
#define TICK_RED    1000
#define TICK_GREEN  5000
#define TICK_BLUE   10000
#define TICK_SERVO  15  

// Servos
Servo servo1, servo2;

// Variables de posición y direccion por servo
// Son globales e individuales para guardar el valor
int pos1 = 0, dir1 = 1;
int pos2 = 0, dir2 = 1;

// Funciones de manejo de los leds
void red_led()
{
  digitalWrite(RED_LED,HIGH);
  Serial.println("LED ROJO: ON");
  delay(TICK_RED);
  digitalWrite(RED_LED,LOW);
  Serial.println("LED ROJO: OFF");
}

void green_led()
{
  digitalWrite(GREEN_LED,HIGH);
  Serial.println("LED VERDE: ON");
  delay(TICK_GREEN);
  digitalWrite(GREEN_LED,LOW);
  Serial.println("LED VERDE: OFF");
}

void blue_led()
{
  digitalWrite(BLUE_LED,HIGH);
  Serial.println("LED AZUL: ON");
  delay(TICK_BLUE);
  digitalWrite(BLUE_LED,LOW);
  Serial.println("LED AZUL: OFF");
}

// Control Servos
void servo1_control()
{
  Serial.println("Servo #1: 0 -> 180");
  for(int i = 0; 180 >= i; i++)
  {
    servo1.write(i);
    delay(15);
  }
  Serial.println("Servo #1: 180 -> 0");
  for(int i = 180; i >= 0; i--)
  {
    servo1.write(i);
    delay(15);
  }
}

void servo2_control()
{
  Serial.println("Servo #2: 0 -> 180");
  for(int i = 0; 180 >= i; i++)
  {
    servo2.write(i);
    delay(15);
  }
  Serial.println("Servo #2: 180 -> 0");
  for(int i = 180; i >= 0; i--)
  {
    servo2.write(i);
    delay(15);
  }
}

// Setup de los pines de los Leds y los servos
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
  servo1.attach(SERVO_1, 500, 2500);
  servo2.setPeriodHertz(50);
  servo2.attach(SERVO_2, 500, 2500);
  delay(1000);
}
// Loop secuencial de funcion -> delay
void loop() {
  red_led();
  delay(TICK_RED);
  green_led(); 
  delay(TICK_GREEN);
  blue_led();
  delay(TICK_BLUE);
  servo1_control();
  delay(TICK_SERVO);
  servo2_control();
  delay(TICK_SERVO);
}

