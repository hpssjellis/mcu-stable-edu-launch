#include <service_lora_p2p.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Yougot 10 seconds to AT+BOOT if things screw up");
  delay(10000);
  // Initialize LoRa module
  // Configure LoRa P2P parameters like frequency, bandwidth, spreading factor, etc.
  // Ensure these settings are compatible with the receiver's settings

  // Initialize LoRa P2P service
  service_lora_p2p_init();
}

void loop() {
  // Define the payload
  uint8_t payload[] = {0x31, 0x34, 0x31, 0x36, 0x31}; // Hex representation of "314161"

  // Send the payload using the service_lora_p2p_send function
  service_lora_p2p_send(payload, sizeof(payload), false);

  // Add a delay to avoid continuously sending data
  delay(5000); // 5-second delay
}

// Additional functions to handle callbacks or events may be required, 
// depending on the library and hardware specifics.
