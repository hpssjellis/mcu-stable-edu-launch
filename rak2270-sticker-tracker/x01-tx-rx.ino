#include <Arduino.h> // Only needed by https://platformio.org/

void setup() {
  Serial1.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);   // try on Portenta LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
}

void loop() {
  //Serial1.print("41542b5053454e443d333134313631");

 // Serial1.print("AT+PSEND=314161");

  const char myBuffer[] = "AT+PSEND=314161\r\n";  //5c72";
  Serial1.write(myBuffer, sizeof(myBuffer) - 1);

 // const byte myBuffer[] = "41542b5053454e443d333134313631";  //5c72";
 // Serial1.write(myBuffer, sizeof(myBuffer) - 1);


 // const char myBuffer[] = "AT+PSEND=112233\r\n";
/*

//  AT+PSEND=314161\r    =   41542b5053454e443d3331343136315c72
  const char myBuffer1[] = "AT\r";
  Serial1.write(myBuffer1, sizeof(myBuffer1) - 1);
  delay(100);
  const char myBuffer[] = "AT+PSEND=112233\r";
  Serial1.write(myBuffer, sizeof(myBuffer) - 1);

*/
  digitalWrite(LED_BUILTIN, LOW);   // internal LED LOW = on for onboard LED
  delay(4000);                      // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(6000);               
}

