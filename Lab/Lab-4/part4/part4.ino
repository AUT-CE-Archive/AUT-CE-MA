#include <Servo.h>

Servo myservo;
const int potpin = A0;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9, 1000, 2000);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(potpin);
  int new_value = map(value, 0, 1023, 0, 180);
  myservo.write(new_value);
}
