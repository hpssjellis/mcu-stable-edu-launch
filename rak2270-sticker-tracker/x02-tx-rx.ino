

#include <Arduino.h> // Only needed by https://platformio.org/

void setup() {
  Serial1.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);   // try on Portenta LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
}

void loop() {

  const char myBuffer[] = "AT+PSEND=3141616263\r\n";  //5c72";
  Serial1.write(myBuffer, sizeof(myBuffer) - 1);

  digitalWrite(LED_BUILTIN, LOW);   // internal LED LOW = on for onboard LED
  delay(4000);                      // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(6000);               
}

