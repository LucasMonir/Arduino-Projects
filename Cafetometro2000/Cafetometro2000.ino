#include <Thermistor.h>
Thermistor temp(0); //pino de leitura

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(8, OUTPUT);
}

void loop() {
  int temperature=temp.getTemp();
   Serial.print("Temperatura atual: ");
   Serial.print(temperature);
   Serial.println("cº");
   delay(1000);

   if(temperature<25){
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
   }

}
