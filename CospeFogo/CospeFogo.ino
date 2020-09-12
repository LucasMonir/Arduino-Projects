const int  buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
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
}
