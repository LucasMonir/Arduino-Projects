#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>

String html = "<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <title>Document</title> <script src=\"https://code.jquery.com/jquery-3.5.1.js\" integrity=\"sha256-QWo7LDvxbWT2tbbQ97B53yJnYU3WhH/C8ycbRAkjPDc=\" crossorigin=\"anonymous\"></script> </head> <body> <header> <h1>Prototipo de html por String</h1> </header> <section> <form> <fieldset> <textarea name=\"texto\" id=\"texto\" cols=\"30\" rows=\"10\"></textarea> <button id=\"botao\" >Ativar</button> </fieldset> </form> </section> <script> $(\"button\").on('click', function (e) { e.preventDefault(); let text = $(this).text(); if (text == 'Ativar') { $(this).html('Desativar'); } else if (text == 'Desativar') { $(this).html('Ativar'); } }); </script> </body> </html>";
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 0, 175};
byte gateway[] = {192, 168, 0, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(80);
File myFile;
const int ledPin = 9;
String readString = String(30);
int status = 0;

void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

}
void loop()
{
  EthernetClient client = server.available();
  if (client)
  {
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100)
        {
          readString += c;
        }
        if (c == '\n')
        {
          if (readString.indexOf("?") < 0)
          {
          }
          else if (readString.indexOf("ledParam=1") > 0)
          {
            digitalWrite(ledPin, HIGH);
            status = 1;
          }
          else
          {
            digitalWrite(ledPin, LOW);
            status = 0;
          }
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("");
          myFile = SD.open("index.txt");
          if (myFile) {
            Serial.println("test.txt:");

            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              client.println(myFile.read());
            }
            // close the file:
            myFile.close();
          } else {
            // if the file didn't open, print an error:
            Serial.println("error opening test.txt");
          }


          readString = "";
          client.stop();
        }
      }
    }
  }
}
