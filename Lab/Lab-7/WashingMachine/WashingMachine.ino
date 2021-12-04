#include <Wire.h>           // TWI Protocol library
#include <Keypad.h>         // Keypad library
#include <LiquidCrystal.h>  // Terminal library

/*
 * LED Pins
 * 22: Prewash
 * 23: Wash with Tide
 * 24: Wash with Water
 * 25: Dry
 */
const int LED_PINS[] {22, 23, 24, 25};

// Keypad
const byte rows = 4;
const byte cols = 3;
char key[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {29, 30, 31, 32};
byte colPins[cols] = {26, 27, 28};
Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);

// LCD
#define RS_PIN 12
#define EN_PIN 10
#define LC_PIN1 5
#define LC_PIN2 4
#define LC_PIN3 3
#define LC_PIN4 2
LiquidCrystal lcd(RS_PIN, EN_PIN, LC_PIN1, LC_PIN2, LC_PIN3, LC_PIN4);


int selectedMode; // Selected mode
bool isWorking;   // Status of the device
int duration;     // Duration for which the action is being performed
int start;        // The start time of the action
int i;            // Global variable for loops

void setup() {
  // LED setup
  for (i = 0; i < sizeof(LED_PINS)/sizeof(LED_PINS[0]); i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

  // Serial setup
  Wire.begin();
  Serial.begin(9600);

  // Keypad setup
  for (i = 0; i < sizeof(rowPins)/sizeof(rowPins[0]); i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  for (i = 0; i < sizeof(colPins)/sizeof(colPins[0]); i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }

  // LCD setup and display modes
  lcd.begin(20,4);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("1.Pre-Wash");
  lcd.setCursor(0, 1);
  lcd.println("2.Tide-Wash");
  lcd.setCursor(0, 2);
  lcd.println("3.Water-Wash");
  lcd.setCursor(0, 3);
  lcd.println("4.Dry-Wash");

  isWorking = false;
}


void loop() {
  char mode = keypad.getKey();

  if (mode == '#')
    lcd.print('AAAAAAAAAAAAA');

  if (mode) {
    // Select a mode if not already working
    if (!isWorking)
      selectModeAndTime(mode - '0');
    else if (isWorking && mode == '#')
      holdWork();
  }

  if (isWorking) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(duration - (millis() - start) / 1000);
    lcd.println("s remaining...");
    lcd.setCursor(0, 1);
    lcd.println("Press # to hold.");
    delay(1000);
  }
}

// Selects a mode and time
void selectModeAndTime(int mode) {
  if (mode > 0 && mode < 5) {
    highLED(mode - 1);
    selectedMode = mode;

    // Clear the LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("For How Long?");
    lcd.setCursor(0,1);
    lcd.println("Press * to submit.");
    lcd.setCursor(0,2);
    lcd.print("Value: ");

    // Set duration (0-9)
    duration = keypad.waitForKey() - '0';
    lcd.print(duration);

    // Start
    start = millis();
    isWorking = true;
  }
}

// Set the target LED to HIGH and others to LOW
void highLED(int id) {
  for (i = 0; i < sizeof(LED_PINS)/sizeof(LED_PINS[0]); i++) {
    if (i != id)
      digitalWrite(LED_PINS[i], LOW);
    else digitalWrite(LED_PINS[i], HIGH);
  }
}

// Holds the current action in the selected mode
void holdWork() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Work halted.");
  lcd.println("Press # to resume.");

  // Save the remaining time
  duration -= (millis() - start) / 1000;

  while (true) {
    char key = keypad.waitForKey();
    if (key == '#') break;
  }
  start = millis();
}
