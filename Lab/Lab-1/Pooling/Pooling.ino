
//const byte ledPin = 13;
//const byte interruptPin = 2;
//volatile byte state = LOW;

#define key1_pin 3
#define key2_pin 2
#define key3_pin 18
#define led1_pin 13
#define led2_pin 12
#define led3_pin 11
#define led4_pin 10
#define led5_pin 9
void setup() {
  
  pinMode(key1_pin, INPUT);
  pinMode(key2_pin, INPUT);
  pinMode(key3_pin, INPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led4_pin, OUTPUT);
  pinMode(led5_pin, OUTPUT);
//turn off LEDs
  digitalWrite(led1_pin, LOW);
  digitalWrite(led2_pin, LOW);
  digitalWrite(led3_pin, LOW);
  digitalWrite(led4_pin, LOW);
  digitalWrite(led5_pin, LOW);
  
}

void loop() {
  if(digitalRead(key1_pin)){
    digitalWrite(led1_pin, HIGH);
    delay(100);
    digitalWrite(led2_pin, HIGH);
    delay(100);
    digitalWrite(led3_pin, HIGH);
    delay(100);
    digitalWrite(led4_pin, HIGH);
    delay(100);
    digitalWrite(led5_pin, HIGH);
  }

  else if(digitalRead(key2_pin)){
    int len = strlen("Ali");
    for(int i=0; i<len; i++){
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, HIGH);
    digitalWrite(led4_pin, HIGH);
    digitalWrite(led5_pin, HIGH);
    delay(100);
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    digitalWrite(led5_pin, LOW);
    delay(100);
    }
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, HIGH);
    digitalWrite(led4_pin, HIGH);
    digitalWrite(led5_pin, HIGH);
  }
  else if (digitalRead(key3_pin)){
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);
    digitalWrite(led4_pin, LOW);
    digitalWrite(led5_pin, LOW);
  }
}
