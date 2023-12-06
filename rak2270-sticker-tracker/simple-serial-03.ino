void setup() {
  /void setup() {
  //Serial.begin(115200, RAK_CUSTOM_MODE);
  Serial.begin(115200, RAK_AT_MODE);
  Serial.setTimeout(20);  // To enter AT command mode type "AT" the mode lasts 3 seconds
}

void loop() {
  String myString = ""; 

   while(Serial.available() > 0) {
    char myChar = Serial.read();
    myString += myChar; // Append the character to the string
    Serial.print(myChar);
   }
   
   myString.trim();  // get rid of last character
   if (myString == "Cool"){
      Serial.println("You entered :"+ myString);
      Serial.println("Serial.getTimeout(): "+String(Serial.getTimeout()) );  
    
   }

}
