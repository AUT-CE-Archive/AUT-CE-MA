/**
 * Writes bytes data array to I2C EEPROM
 */
void memory_write(uint16_t memory_address, uint8_t* data, uint8_t _size) {
  Serial.print("Writing to EEPROM...");
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write((uint8_t)((memory_address & 0xFF00) >> 8));
  Wire.write((uint8_t)(memory_address & 0x00FF));

  for (int i = 0 ; i < _size ; i++)
    Wire.write(data[i]);

  Wire.endTransmission();
  delay(10); // Maximum I2C cycle duration is 5, 10 just to be sure

  Serial.print(" Wrote: ");
  for (int i = 0; i < _size; i++)
    Serial.print((char)data[i]);
  Serial.println();
}

/**
 * Reads bytes data array from I2C EEPROM
 */
void memory_read(uint16_t memory_address, uint8_t* data, uint8_t _size) {
  Serial.print("Reading from EEPROM...");
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write((uint8_t)((memory_address & 0xFF00) >> 8));
  Wire.write((uint8_t)(memory_address & 0x00FF));
  Wire.endTransmission();
  delay(10); // Maximum I2C cycle duration is 5, 10 just to be sure

  Wire.requestFrom(DEVICE_ADDRESS, _size);
  for (int i = 0 ; i < _size ; i++)
    data[i] = Wire.read();

  Serial.print(" Read: ");
  for (int i = 0; i < _size; i++)
    Serial.print((char)data[i]);
  Serial.println();
}
