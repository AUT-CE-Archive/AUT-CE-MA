void show_menu() {
  // LCD setup and display modes
  lcd.begin(20,4);
  lcd.clear();
  for (int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    lcd.print(i + 1);
    lcd.print(". ");
    printMode(i);
    lcd.println();
  }
}

// Selects a mode and time
void start(int mode) {
  lcd.clear();
  lcd.print("Selected: ");
  printMode(mode);
  lcd.println();
  lcd.setCursor(0,1);
  lcd.println("For How Long? (0-9)");
  lcd.setCursor(0,2);
  lcd.print("Value: ");    

  // Set tracking variables
  selectedMode = mode;
  busy = true;
  int remaining = keypad.waitForKey() - '0';  
  for (int i = 0; i < 4; i++)
    if (i >= selectedMode)
      remainings[i] = remaining;
    else
      remainings[i] = 0;    

  for (int i = 0; i < 4; i++)
    digitalWrite(LED_PINS[i], LOW);  
  digitalWrite(LED_PINS[selectedMode], HIGH);
}


// Holds the current action in the selected mode
void hold() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Work halted.");
  lcd.setCursor(0, 1);
  lcd.println("Press # to resume.");

  while (true) {
    char key = keypad.waitForKey();
    if (key == '#') break;
  }
}


// Work
void work() {
  
  // Save the current remaining time to memory
  if (first_read != 0)
    memory_read(345, remainings, TRANSFER_SIZE);
  else
    first_read = 1;

//  Serial.println("1");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current: ");
  printMode(selectedMode);
  lcd.setCursor(0, 1);
  lcd.print(int(remainings[selectedMode]));
  lcd.println("s remaining...");
  lcd.setCursor(0, 2);
//  Serial.println("2");
  lcd.println("Press # to hold.");
//  Serial.println("3");

  remainings[selectedMode] -= 1;
  delay(1000); 
//  Serial.println("4");

  // Save the new remaining time to memory
  memory_write(345, remainings, TRANSFER_SIZE);

  // Go to next mode if timer is up
  if (remainings[selectedMode] <= 0) {
    nextMode();
  }
}


// Changes the current mode of the machine
void nextMode() {  
  delay(1000 * STEP);
  selectedMode++;

  for (int i = 0; i < 4; i++)
    digitalWrite(LED_PINS[i], LOW);  
  digitalWrite(LED_PINS[selectedMode], HIGH);
}


// Finish
void finish() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Finished Working.");
  lcd.setCursor(0, 1);
  lcd.println("Press # for Menu");

  // Set idle and HIGH all LEDs
  busy = false;
  for (int i = 0; i < 4; i++)
    digitalWrite(LED_PINS[i], HIGH);  

  if (keypad.waitForKey() == '#')
    show_menu();
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Bye.");
  }
}


// Prints the current mode to LCD
void printMode(int mode) {
  switch(mode) {
    case 0: lcd.print("Pre-Wash"); break;
    case 1: lcd.print("Tide-Wash"); break;
    case 2: lcd.print("Water-Wash"); break;
    case 3: lcd.print("Dry-Wash"); break;
  }
}
