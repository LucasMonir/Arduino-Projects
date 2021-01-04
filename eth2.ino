#include <Ethernet.h>
#include <SD.h>
#include <SPI.h>

String html = "<!DOCTYPE html> <html lang=\"en\"> <head> <meta charset=\"UTF-8\"> <title>Document</title> <script src=\"https://code.jquery.com/jquery-3.5.1.js\" integrity=\"sha256-QWo7LDvxbWT2tbbQ97B53yJnYU3WhH/C8ycbRAkjPDc=\" crossorigin=\"anonymous\"></script> </head> <body> <header> <h1>Prototipo de html por String</h1> </header> <section> <form> <fieldset> <textarea name=\"texto\" id=\"texto\" cols=\"30\" rows=\"10\"></textarea> <button id=\"botao\" >Ativar</button> </fieldset> </form> </section> <script> $(\"button\").on('click', function (e) { e.preventDefault(); let text = $(this).text(); if (text == 'Ativar') { $(this).html('Desativar'); } else if (text == 'Desativar') { $(this).html('Ativar'); } }); </script> </body> </html>";
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 0, 175};
byte gateway[] = {192, 168, 0, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(80);
File pagina;

const int ledPin = 9;
String readString = String(30);
int status = 0;

void setup()
{
    Ethernet.begin(mac, ip, gateway, subnet);
    server.begin();
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    if (!SD.begin(4))
    {
        Serial.println("ERROR - SD card initialization failed!");
        return; // init failed
    }
    Serial.println("SUCCESS - SD card initialized.");
    // check for index.htm file
    if (!SD.exists("index.htm"))
    {
        Serial.println("ERROR - Can't find index.htm file!");
        return; // can't find index file
    }
    Serial.println("SUCCESS - Found index.htm file.");
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
                    if (readString.indexOf("param=l") > 0)
                    {
                        client.println("heh fogo");
                    }
                    else if (readString.indexOf("param=f"))
                    {
                    }
                    else
                    {
                    }

                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("");
                    pagina = SD.open("index.html"); // open web page file
                    if (pagina)
                    {
                        while (pagina.available())
                        {
                            client.write(pagina.read()); // send web page to client
                        }
                        pagina.close();
                    }
                    break;

                    readString = "";
                    client.stop();
                }
            }
        }
    }
}