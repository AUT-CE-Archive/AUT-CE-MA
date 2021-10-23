#include <LiquidCrystal.h>
#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11

LiquidCrystal lcd (RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
//  lcd.print("Ali");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0 ,0);
  lcd.print("N");

  for(int i=0 ; i<16 ;i++){
    int j=0;
        if(i % 2 == 0){
          j=0;
          }else{
            j=1;
            }
        delay(200);
        lcd.clear();
        lcd.setCursor(i , j);
        lcd.print("N");
        delay(200);
        lcd.clear();
  
      }
  }
