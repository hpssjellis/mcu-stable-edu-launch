/* only for the XIAO-esp32 Boards
to send and receive data from the XIAO-SAMD21 
board using the sercom module and the SercomSPISlave library



Normal Master SPI connectivity
which are normally default assigned

#define MISO = D10;
#define SCK = D9;
#define MOSI = D8;
#define SS = D7; // Slave select pin, can be any GPIO pin

*/

#include <SPI.h>

#define MISO  D10
#define SCK D9
#define MOSI  D8
#define SS  D7 // Slave select pin, can be any GPIO pin

byte myDataToSend;
byte myDataToReceive;

void setup() {
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH); 
  SPI.begin(SCK, MISO, MOSI, SS);

  Serial.begin(115200); // Initialize serial communication for debugging
}

void loop() {
  digitalWrite(SS, LOW);  // Select the slave device by pulling chip select low
 // delayMicroseconds(20);

  myDataToSend = 3; // Data to send to the slave
  myDataToReceive = SPI.transfer(myDataToSend); // Send data and receive response

 // delayMicroseconds(20);
  digitalWrite(SS, HIGH);  // Deselect the slave device

  Serial.print("Master sent to slave: ");
  Serial.print(myDataToSend);
  Serial.print(", Master received from slave: ");
  Serial.println(myDataToReceive);

  delay(1000); // Wait for 1 second before sending the next data
}
