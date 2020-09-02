int buzzer = 7;
int sensorPin = A0;
int luzes = 8;
int flag = 0;

void setup() {
  pinMode(luzes, OUTPUT);
}

void loop() {
  int luz = analogRead(sensorPin);
  if(flag == 0){
    delay(100);
    digitalWrite(buzzer, LOW);
    digitalWrite(luzes,HIGH);
    delay(100);
    digitalWrite(luzes, LOW);
    analogWrite(buzzer, 200);
    delay(100);
    digitalWrite(buzzer, LOW);
    if(luz >100){
      flag=1;
    }
  }
}
