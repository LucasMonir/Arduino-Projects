#include <Servo.h>
Servo servo;

int servoPin = 9;
int sensorPin = A0;

void setup(){
    servo.attach(servoPin);
    servo.write(0);
}
 
void loop(){
    int luz= analogRead(sensorPin);
    if(luz>100){
      servo.write(50);
      delay(500);
      servo.write(0);
    }
    delay(100);
}
