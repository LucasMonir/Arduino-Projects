#define potPin 0
#define ledPin 0

int leituraPot=0;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){

  leituraPot=analogRead(potPin);
  leituraPot=map(leituraPot,0,1023,0,255);
  analogWrite(ledPin, leituraPot);

}
