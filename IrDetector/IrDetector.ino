int leituraSensor;
int buzzer = 8;
int fotoTransistor = 7;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(fotoTransistor, INPUT);
}

void loop() {
  leituraSensor= digitalRead(fotoTransistor);
  if(leituraSensor == 0){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  delay(500);
}
