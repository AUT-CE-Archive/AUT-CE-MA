#define BCD_A 22
#define BCD_B 23
#define BCD_C 24
#define BCD_D 25


// This function displays numbers from 0 to 9
// it uss BCD decoded values to turn on or turn off BCD pins
void show_number(int num)  
{
  switch(num)
  {
   case 0:
    digitalWrite(BCD_A, LOW);  
    digitalWrite(BCD_B, LOW); 
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, LOW); 
    break;
    case 1:
    digitalWrite(BCD_A, HIGH);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, LOW);
    break;
    case 2:
    digitalWrite(BCD_A, LOW);
    digitalWrite(BCD_B, HIGH);
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, LOW);
    break;
    case 3:
    digitalWrite(BCD_A, HIGH); 
    digitalWrite(BCD_B, HIGH); 
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, LOW);
    break;
    case 4:
    digitalWrite(BCD_A, LOW);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, HIGH);
    digitalWrite(BCD_D, LOW);
    break;
    case 5:
    digitalWrite(BCD_A, HIGH);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, HIGH);
    digitalWrite(BCD_D, LOW);
    break;
    case 6:
    digitalWrite(BCD_A, LOW);
    digitalWrite(BCD_B, HIGH);
    digitalWrite(BCD_C, HIGH);
    digitalWrite(BCD_D, LOW);
    break;
    case 7:
    digitalWrite(BCD_A, HIGH);
    digitalWrite(BCD_B, HIGH);
    digitalWrite(BCD_C, HIGH);
    digitalWrite(BCD_D, LOW);
    break;
    case 8:
    digitalWrite(BCD_A, LOW);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, HIGH);
    break;
    case 9:
    digitalWrite(BCD_A, HIGH);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, HIGH);
    break;
    default:
    digitalWrite(BCD_A, LOW);
    digitalWrite(BCD_B, LOW);
    digitalWrite(BCD_C, LOW);
    digitalWrite(BCD_D, LOW);
    break;
}
}

void setup() {
  //set as digital output pins
  pinMode(BCD_A  , OUTPUT); 
  pinMode(BCD_B  , OUTPUT);
  pinMode(BCD_C  , OUTPUT);
  pinMode(BCD_D  , OUTPUT);
}

void loop() {
  int i;  // variable to keep control of loop and counter value
  // this loop displays from 0-9
  for(i = 0; i<=9; i++)
  {
     show_number(i);
    delay(1000);
  }  
}
