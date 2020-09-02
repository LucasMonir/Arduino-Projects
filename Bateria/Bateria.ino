#include <Servo.h>
const int botaoPin = 7;
const int servoPin = 9;

Servo servo;
int estadoBotao;

void setup(){
  pinMode(botaoPin, INPUT_PULLUP);
  servo.attach(servoPin);
  servo.write(0);
}

void loop(){
  estadoBotao = digitalRead(botaoPin);
  if(estadoBotao == LOW){
    servo.write(160);
  }else if(estadoBotao == HIGH){
    servo.write(0);  
  }
}
