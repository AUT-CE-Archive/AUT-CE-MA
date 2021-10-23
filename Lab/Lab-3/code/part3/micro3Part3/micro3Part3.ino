#include <Keypad.h>
#include <LiquidCrystal.h>

#define rs 25
#define rw 26
#define en 27
#define d0 45
#define d1 46
#define d2 48
#define d3 49
#define d4 50
#define d5 51
#define d6 52
#define d7 53
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7) ;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
 {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'O','0','=','+'}
};
byte rowPins[ROWS] = {A15, A14, A13, A12}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4, A5, A6 ,A7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int op1 =0;//if flag == 0
int op2 =0;//if flag == 1
int flag =0;

char operation;


void setup(){
  Serial.begin(9600);
  lcd.begin(16 , 2);
  lcd.clear();
  lcd.setCursor(0 ,0);
}


  
void loop(){
    char key = keypad.getKey();  
    bool check = false;
   

    if (key){
      //check if key is an number
       if (key=='0' ||key=='1' ||key=='2' ||key=='3' ||key=='4' ||key=='5' ||key=='6' ||key=='7' ||key=='8'||key=='9' ) {
          check = true;
       } else{
        check= false;
       }
     
      if(check){
        if(flag==0){
          op1 = op1 * 10 + ((int) key -(int)'0');
          } else{
           op2 = op2 * 10 + ((int) key -(int)'0');
            }
        lcd.write(key);
      }
      else if(key == '='){
        lcd.setCursor(0,1);
        if(operation == '+'){
          lcd.print(op1+op2);
        }else if(operation == '-'){
          lcd.print(op1-op2);
        }else if(operation == '/'){
          lcd.print(op1/op2);
        }else if(operation == '*'){
           lcd.print(op1*op2);
        }
      } else{
        flag = 1;
        operation = key;
        lcd.write(key);
      }
    }
}
