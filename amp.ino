const int input = 0;
float res;
int r = 5;

float getAnalogRead(int pin)
{
  float analogread = 0;
  for(int i=0; i<10; i++) {
    analogread += analogRead(pin);
  }

  return analogread /10;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(input, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  res = getAnalogRead(input);
  res = (res* 5)/ 1024;

  res = res/ r;

  Serial.print("Arus: ");
  Serial.print(res);
  Serial.println(" A");
  

  delay(1000);
}
