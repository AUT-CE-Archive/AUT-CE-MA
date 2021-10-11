const int SWITCHs[] = {3, 2, 18};
const int LEDs[] = {13, 12, 11, 10, 9};

volatile byte state_0 = 0;
volatile byte state_1 = 0;
volatile byte state_2 = 0;

#define NAME "Keivan"

void LOW_LEDs() {
  for (int i = 0; i <  sizeof(LEDs)/sizeof(LEDs[0]); i++)
    digitalWrite(LEDs[i], LOW);
}

void HIGH_LEDs(int del = 100) {
  for (int i = 0; i <  sizeof(LEDs)/sizeof(LEDs[0]); i++) {
    digitalWrite(LEDs[i], HIGH);
    delay(del);
  }  
}

void setup() {
  // Initialize Switches
  for (int i = 0; i <  sizeof(SWITCHs)/sizeof(SWITCHs[0]); i++)
    pinMode(SWITCHs[i], INPUT);

  // Initialize LEDs
  for (int i = 0; i <  sizeof(LEDs)/sizeof(LEDs[0]); i++)
    pinMode(LEDs[i], OUTPUT);
  LOW_LEDs();

  attachInterrupt(digitalPinToInterrupt(SWITCHs[0]), op_0, RISING);
  attachInterrupt(digitalPinToInterrupt(SWITCHs[1]), op_1, RISING);
  attachInterrupt(digitalPinToInterrupt(SWITCHs[2]), op_2, RISING);
}

void op_0() {
  state_0 = 1;
}

void op_1() {
  state_1 = 1;
}

void op_2() {
  state_2 = 1;
}

void loop() {

  if (state_0 == 1) {
    HIGH_LEDs();
    state_0 = 0;
  } else if (state_1 == 1) {
    for (int i = 0; i < strlen(NAME); i++) {
      HIGH_LEDs(0);
      delay(100);
      LOW_LEDs();
      delay(100);
    }
    state_1 = 0;
  } else if (state_2 == 1)
    LOW_LEDs();
    state_2 = 0;
}
