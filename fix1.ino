/* By. CE CREW'S */
#include <SoftwareSerial.h>
#include <UIPEthernet.h>
#include <NewPing.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xEE};
IPAddress ip(192, 168, 1, 20);
EthernetServer server(1007);
const int trigPin = 3;
const int echoPin = A4;

/* Create some variable */
const int warning1 = 6;
const int warning2 = 7;
const int warning3 = 8;

#define rainPin A2
#define kondisi 2
SoftwareSerial simgsm(4, 5);

String data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  simgsm.begin(9600);
  server.begin();
  
  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());
  data = "";

  /* Select pin mode */
  pinMode(warning1, OUTPUT);
  pinMode(warning2, OUTPUT);
  pinMode(warning3, OUTPUT);
  pinMode(rainPin, INPUT);
  pinMode(kondisi, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  EthernetClient client = server.available();

  boolean sms_terkirim = false;
  int kondisi_sensor = digitalRead(rainPin);
  long duration, inches, cm;
  int status_sensorHujan;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = microSecondsToInches(duration);
  cm = microSecondsToCentimeters(duration);

  
  /* Pengecekan Sensor hujan */
  if(kondisi_sensor == LOW) {
    Serial.println("CUACA HUJAN");
      digitalWrite(kondisi, HIGH);
  }else {
    Serial.println("CUACA CERAH");
     digitalWrite(kondisi, LOW);
  }

  /* Sending data to database */
  data = "inc=" + String(inches) + "&cm=" + String(cm) + "&status=" + String(kondisi_sensor);
  if(client.connect("192.168.1.1", 1007)) {
    client.println("POST /php_app/includes/add.php HTTP/1.1");
    client.println("Host: 192.168.1.1");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.print(data);
  } 

  if(client.connected()) {
    client.stop();
  }


  /* Pengecekan Ultrasonik */
  if((cm <= 10) && (sms_terkirim == false)) {
    digitalWrite(warning1, HIGH);
    digitalWrite(warning2, LOW);
    digitalWrite(warning3, LOW);

    simgsm.println("at");
    delay(1000);
    simgsm.println("at+cmgf=1");
    delay(1000);

    simgsm.println("AT+CMGS=\082339272418\"\r\n");
    delay(1000);
    simgsm.println("Perhatian! Darurat sampah meluap! Ketinggian < 10 Cm! By: FloTraSys");
    delay(1000);
    simgsm.println((char)100);
    sms_terkirim = true;
  }
  else if((cm > 10 ) && (cm <= 30)){
    digitalWrite(warning1, LOW);
    digitalWrite(warning2, HIGH);
    digitalWrite(warning3, LOW);
  } 
  else if((cm >= 31) && (cm < 60)) {
    digitalWrite(warning1, LOW);
    digitalWrite(warning2, LOW);
    digitalWrite(warning3, HIGH);
  } else {
    digitalWrite(warning1, LOW);
    digitalWrite(warning2, LOW);
    digitalWrite(warning3, LOW);
  }

  
  Serial.print(inches); 
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();  
  Serial.print(status_sensorHujan);
  Serial.println();
  Serial.print("Kondisi sensor: ");
  Serial.println(kondisi_sensor);
  delay(10000);
}


long microSecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microSecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

