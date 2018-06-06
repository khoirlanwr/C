#include <Wire.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <dht11.h>

#define dht_pin 5
const char* host = "192.168.43.115";

dht11 DHT11;
WiFiClient clients;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.begin("nodemcu", "passwordnodemcu"); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }
  
}
  
void loop() {
  // put your main code here, to run repeatedly:
  // create variable
  int httpPort = 80;
  if(!clients.connect(host, httpPort)) {
    Serial.println("Connection failed!");
    return;
  }

  int chk = DHT11.read();

  float hum = DHT11.humidity;
  float temp = DHT11.temperature;

  DHT11.read(dht_pin);

  Serial.println("Read sensor: ");
  Serial.print("Current Humidity: ");
  Serial.print(hum);
  Serial.print("% ");
  Serial.print(" temperature: ");
  Serial.print(temp);
  Serial.println("C ");

  
  // Create url for request

  String url = "http://192.168.43.115/data/includes/add.php?datahum=";
  url += hum;
  url += "&datatemp=";
  url += temp;

  Serial.print("Requesting URL: ");
  Serial.println(url);
  clients.print(String("GET ") + url + " HTTP/1.1\r\n" + 
              "Host:" + host + "\r\n"
              "Connection: close\r\n\r\n");
  
  unsigned long timeout = millis();
  while(clients.available() == 0) {
    if(millis() - timeout > 5000) {
      Serial.println(">>> Client timeout!");
      clients.stop();
      return;
    }
  }
  
  delay(20000);
}
