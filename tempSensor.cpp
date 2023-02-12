#define hotTemp 35
#define warmTemp 25
#define coldTemp 15

int hotLed = 13;
int warmLed = 12;
int coldLed = 11;
int temperatureSensor = A0;

void setup() {
  pinMode(hotLed, OUTPUT);
  pinMode(warmLed, OUTPUT);
  pinMode(coldLed, OUTPUT);
}

void loop() {
  int temperature = analogRead(temperatureSensor);
  temperature = (temperature * 500) / 1024;

  if (temperature >= hotTemp) {
    digitalWrite(hotLed, HIGH);
    digitalWrite(warmLed, LOW);
    digitalWrite(coldLed, LOW);
  }
  else if (temperature >= warmTemp) {
    digitalWrite(hotLed, LOW);
    digitalWrite(warmLed, HIGH);
    digitalWrite(coldLed, LOW);
  }
  else if (temperature >= coldTemp) {
    digitalWrite(hotLed, LOW);
    digitalWrite(warmLed, LOW);
    digitalWrite(coldLed, HIGH);
  }
  else {
    digitalWrite(hotLed, LOW);
    digitalWrite(warmLed, LOW);
    digitalWrite(coldLed, LOW);
  }
}
