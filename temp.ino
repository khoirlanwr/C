#include <ESP8266WiFi.h>
#include <DHT.h>

String apiWriteKey = "OU7ZSRFMHX3J22BF"; 
const char* ssid = "ADVAN S5E 4GS";
const char* pass = "844429e958d8";

const char* server = "api.thingspeak.com";
WiFiClient client;

#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, pass);

  Serial.println();
  Serial.println();
  Serial.print("NodeMCU Connecting to WiFi....");

  WiFi.begin(ssid, pass);
  dht.begin();
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMCU Connected to ");
  Serial.println(ssid);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if(isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  }else {
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
