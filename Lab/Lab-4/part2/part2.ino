#include <Servo.h>
#include <Keypad.h>

Servo myservo;
int value = 0;

const byte ROWS = 4;
const byte COLS = 3;
const char keys[ROWS][COLS] = {           // keypad keys
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

const byte rowPins[ROWS] = {53, 52, 51, 50};  // row pinouts
const byte colPins[COLS] = {33, 32, 31};     // column pinouts
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9, 1000, 2000);
  myservo.write(90);
}
void loop() {
  // put your main code here, to run repeatedly:

  char key = keypad.getKey();

  if (key){

    if (key == '*') {
      int new_value = map(value, 0, 359, 0, 180);
      myservo.write(new_value);

      Serial.print("Scaled to "); 
      Serial.println(new_value);
    } else {
      // Conversion
      int digit = key - '0';
      value = (value * 10) + digit;
  
      // Console
      Serial.println(value);
    }        
  }
}
