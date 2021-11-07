#include <Servo.h>

Servo myservo;
int deg = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9, 1000, 2000);
  myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (deg = 0; deg <= 90; deg += 1) { 
//    myservo.write(deg);
//    delay(100);                       
//  }
//  delay(500);
//  for (deg = 90; deg >= 0; deg -= 1) { 
//    myservo.write(deg);
//    delay(100);                       
//  }
//  delay(500);

  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
}
