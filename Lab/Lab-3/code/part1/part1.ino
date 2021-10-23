#include <LiquidCrystal.h>
#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11

int x,y;
LiquidCrystal lcd (RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ali");
  x = y = 0;

}

void loop() {
  delay(300);
  x++;
  if(x == 15){
    x = 0;
    y++;
  }
  if(y == 2)
    y = 0;
   lcd.clear();
   lcd.setCursor(x,y);
   lcd.print("Ali");

}
