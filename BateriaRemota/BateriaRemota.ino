#include <Servo.h>
#include <IRremote.h>

Servo servo;
int servoPin = 8;
int IR_Recv = 7;
IRrecv irrecv(IR_Recv);
decode_results result;

void setup(){
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);  
  irrecv.enableIRIn();
}
 
void loop(){
  if (irrecv.decode(&result)){
    long int codigo = result.value;
    Serial.println(result.value);
    irrecv.resume();
    if(code == 551494365){
      
    }
    switch(code){
      
      //enter
      case 551494365:
        servo.write(50);
        delay(1000);
        servo.write(0);   
      break;
      
      //zero
      case 551487735:
        servo.write(50);
        delay(500);
        servo.write(0); 
        delay(100);
        servo.write(50);
        delay(500);
        servo.write(0);
        delay(100);
        servo.write(50);
        delay(900);
        servo.write(0);   
      break;
      
      //seis
      case 551512215:
        servo.write(50);
        delay(100);
        servo.write(0);
        servo.write(50);
        delay(100);
        servo.write(0);
        servo.write(50);
        delay(100);
        servo.write(0);
        servo.write(50);
        delay(100);
        servo.write(0);
        servo.write(50);
        delay(100);
        servo.write(0);
      break;
    }
  }
  delay(10);
}
