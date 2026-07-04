#define MQ2pin 4
#define relay 6
#define buzzer 5
#define red 3
#define green 2

unsigned long previousMillis = 0;
unsigned long relayOffMillis = 0;
const long interval = 100;
const long relayDelay = 7000;
bool buzzerState = false;
bool redState = false;
bool gasDetected = false;
bool relayCountdown = false;

void setup() {
  // ✅ First thing - turn off the fan immediately
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
  Serial.println("MQ2 warming up!");
  delay(30000);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}

void loop() {
  int sensorValue = digitalRead(MQ2pin);
  Serial.print("Digital Output: ");
  Serial.println(sensorValue);

  if (sensorValue == 0) {  // ⚠️ Gas detected = danger
    gasDetected = true;
    relayCountdown = false;
    digitalWrite(green, LOW);
    digitalWrite(relay, LOW);
    blinkRedAndBuzzer();
  } else {  // ✅ No gas = safe
    buzzerState = false;
    redState = false;
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(green, HIGH);

    if (gasDetected) {
      gasDetected = false;
      relayCountdown = true;
      relayOffMillis = millis();
    }

    if (relayCountdown) {
      if (millis() - relayOffMillis >= relayDelay) {
        relayCountdown = false;
        digitalWrite(relay, HIGH);
      }
    }
  }
}

void blinkRedAndBuzzer() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    buzzerState = !buzzerState;
    redState = !redState;
    digitalWrite(buzzer, buzzerState);
    digitalWrite(red, redState);
  }
}
