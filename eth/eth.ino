#include <SPI.h>
#include <SD.h>
#include <Ethernet.h>

File myFile;
String readString = String(30);
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 0, 175};
byte gateway[] = {192, 168, 0, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(80);


void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

void loop() {
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
         
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("");


          myFile = SD.open("index.txt");
          if (myFile) {
            Serial.println("test.txt:");

            while (myFile.available()) {
              client.write(myFile.read());
            }
            myFile.close();
          } else {
            Serial.println("error opening test.txt");
          }

          readString = "";
          client.stop();

          while(1){}
        }
      }
    }
  }

}

