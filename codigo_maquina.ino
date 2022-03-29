#include<Servo.h>

Servo servo1; //Servomotor

int servo_a = 0; //Ángulo del servomotor

String Lado; //Lado de la moneda: "c" o "s"

void setup() {
  servo1.attach(6);
  servo1.write(servo_a);
  Serial.begin(9600);
}

void loop() {
  Serial.println("¿Cara o sello?");     //Preguntar cara o sello
  while(Serial.available() == 0);
  Lado = Serial.readStringUntil('\n');  //Entrada de texto
    
  if (Lado == "c")  //Si la entrada fue c
  {
    Serial.println("Lado: cara");
    servo1.write(100);                  //Mover el servomotor
    delay(1000);
    servo1.write(0);                   //Volver a 0º
  }
  else if(Lado == "s") //Si la entrada fue s
  {
    Serial.println("Lado: sello");
    if (servo_a < 120)
    {
      for(servo_a = 0; servo_a <= 120; servo_a += 2)  //mover el servomotor
      {
        servo1.write(servo_a);
        delay(3);
      }
      servo_a = 0;
      delay(1000);
      servo1.write(servo_a);      //Volver a 0º
    }
  }
  else  //Si la entrada no fue ni c ni s
  {
    Serial.println("c = cara, sello = s"); 
  }
}
