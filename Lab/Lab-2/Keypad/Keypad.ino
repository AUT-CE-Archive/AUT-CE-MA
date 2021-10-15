#include <Keypad.h>

const int LEDs[] = {30, 29, 28, 27, 26, 25, 24, 23, 22};

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

// Trun all LEDs on
void goHigh(int range, int interval = 100, int final = 500) {
  for (int i = 0; i <  range; i++) {
    digitalWrite(LEDs[i], HIGH);
    delay(interval);
  }
  delay(final);
}

// Trun all LEDs off
void goLow() {
  for (int i = 0; i <  sizeof(LEDs)/sizeof(LEDs[0]); i++)
    digitalWrite(LEDs[i], LOW);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key){
    // Conversion
    int range = key - '0';

    // Console
    Serial.print("Input character: ");
    Serial.println(range);

    // LEDs    
    goHigh(range);    
  }

  if (Serial.available()) {  
    int range = Serial.parseInt();

    if (range >= 1 && range <= 9)
      goHigh(range);
    else
      Serial.println("Invalid number");
  }  
  
  goLow();
}
