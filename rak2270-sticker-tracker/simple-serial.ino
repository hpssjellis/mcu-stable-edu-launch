void setup() {
 // Serial.begin(115200, RAK_CUSTOM_MODE);
  Serial.begin(115200, RAK_AT_MODE);
}

void loop() {

   while(Serial.available() > 0) {
    char myChar = Serial.read();
    Serial.print(myChar);
  }
  
}
