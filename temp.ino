#include "ESP8266WiFi.h"
#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
String apiWriteKey = "OU7ZSRFMHX3J22BF"; 
const char* ssid = "ADVAN S5E 4GS";
const char* pass = "844429e958d8";

const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test");
  
  dht.begin();
  WiFi.begin(ssid, pass);

  if(WiFi.status() != WL_CONNECTED) {
    Serial.print("Not Connected!");
  }
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }

  if(client.connect(server, 80)) 
  {
    String tsData = apiWriteKey;
      tsData += "&field1=";
      tsData += String(t);
      tsData += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: "+apiWriteKey+"\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(tsData.length());
      client.print("\n\n");
      client.print(tsData);
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.println(" uploaded to Thingspeak server");
      
  }

  client.stop();
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  delay(15000);
}

