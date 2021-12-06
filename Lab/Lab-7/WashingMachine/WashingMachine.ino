#include <Wire.h>
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

// EEPROM variables
#define DEVICE_ADDRESS 0b1010000
#define TRANSFER_SIZE 4
uint8_t data[TRANSFER_SIZE] = {0};
uint8_t read_data[TRANSFER_SIZE] = {0};

// Machine variables
#define STEP 0.2        // STEP for delay
int selectedMode = -1;  // Selected mode
bool busy = false;      // Status of the device
int remainings[4] = {0};


void setup() {
  // LED setup
  for (int i = 0; i < sizeof(LED_PINS)/sizeof(LED_PINS[0]); i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

  Wire.begin();
  Serial.begin(9600);

  // Keypad setup
  for (int i = 0; i < sizeof(rowPins)/sizeof(rowPins[0]); i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  for (int i = 0; i < sizeof(colPins)/sizeof(colPins[0]); i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }

  int arr[] = {1, 2, 3, 4};

//  machineWriteMemory(remainings, TRANSFER_SIZE);
//  machineReadMemory(TRANSFER_SIZE);

  show_menu();    // Show menu
}


void loop() {
  char key = keypad.getKey();
  int _key = key - '0';

  if (key) {
    if (!busy && (_key >= 1 && _key < 5))
      start(_key - 1);  // Start working
    else if (busy && key == '#')
      hold();       // Halt working
  }

  if (busy) {
    if (selectedMode < 4)
      work();       // Continue working   
    else
      finish();     // Finish working
  }
}


// Interface for writing in memory
void machineWriteMemory(int arr[], int _size) { 
  memset(data, 0, _size);
  sprintf(data, "%d%d%d%d",arr[0], arr[1], arr[2], arr[3]);  
  memory_write(345, data, TRANSFER_SIZE);
}


// Interface for reading from memory
void machineReadMemory(int _size) {
  memset(read_data, 0, TRANSFER_SIZE);
  memory_read(345, read_data, TRANSFER_SIZE);
}
