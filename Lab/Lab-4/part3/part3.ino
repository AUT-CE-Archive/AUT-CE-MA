#include <Servo.h>

Servo myservo;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9, 1000, 2000);
  myservo.write(90);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    value = Serial.parseInt();

    if (value != 0) {
      myservo.write(myservo.read() - value);
      
      Serial.print("Shifting motor ");
      Serial.print(-value);
      Serial.println(" degrees.");
    }
  }
}
