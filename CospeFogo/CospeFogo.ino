#include <IRremote.h>
#include <Servo.h>
/*
  const int  buttonPin = 8;
  int buttonState = 0;
  int lastButtonState = 0;
  const int relePin = 6;
*/

const int servoPin = 9;
int IR_Recv = 7;
Servo servo;
IRrecv irrecv(IR_Recv);
decode_results result;

void setup() {
  servo.attach(servoPin);
  servo.write(0);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&result)) {
    long int codigo = result.value;
    Serial.println(result.value);
    irrecv.resume();

    switch (codigo) {
      //enter
      case 551494365:
        servo.write(170);
        delay(500);
        servo.write(0);
        break;
    }

    /*
      buttonState = digitalRead(buttonPin);

      if (buttonState != lastButtonState) {
      if (buttonState == HIGH) {
        Serial.println("on");
        //liberar servo pra rodar rexona dps d 500 ms
        //+ 500ms liberar faisca com o relê
      } else {
        Serial.println("off");
        //apaga td por safety
      }
      delay(50);
      }
    */
  }
}
