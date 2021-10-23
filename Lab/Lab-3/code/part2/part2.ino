#include <LiquidCrystal.h>
#include <Keypad.h>
#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {A12, A11, A10, A9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A13, A14, A15}; //connect to the column pinouts of the keypad

String inputPass = "";
const String password="9831130";
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );  


LiquidCrystal lcd (RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
int x,y;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);

}

void loop() {
    char key = keypad.getKey();  
    if (key){
       bool check = false;
       //check if key is an number
       if (key =='0' ||key =='1' ||key =='2' ||key =='3' ||key=='4' ||key=='5' ||key=='6' ||key=='7' ||key=='8'||key=='9' ) {
        check = true;
       }

      
      if(check){
        inputPass += key;
        lcd.write(key);
      } else if(key == '*'){
        lcd.setCursor(0,1);
        if(inputPass == password ){
            lcd.print("Correct pass");
      } else
            lcd.print("wrong pass");  
      }
    }
}
