#define RELAY_CONTROL 22

void setup() {
  pinMode(RELAY_CONTROL, OUTPUT);
  digitalWrite(RELAY_CONTROL, LOW);
}

void loop() {
  digitalWrite(RELAY_CONTROL, LOW);
  delay(2000);
  digitalWrite(RELAY_CONTROL, HIGH);
  delay(2000);
}
