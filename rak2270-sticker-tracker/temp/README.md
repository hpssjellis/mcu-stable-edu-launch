Just a plce for general stuff that I might use

Full P2P examples here

https://github.com/Kongduino/RUI3_LoRa_Basic_Rx_Tx




Cool infor here    https://github.com/RAKWireless/RAK-STM32-RUI/blob/main/cores/STM32WLE/component/service/lora/service_lora_p2p.h



```

SERVICE_LORA_WORK_MODE service_lora_p2p_get_nwm(void);

int32_t service_lora_set_nwm(SERVICE_LORA_WORK_MODE nwm);

int32_t service_lora_p2p_init(void);

int32_t service_lora_p2p_config(void);

int32_t service_lora_p2p_send(uint8_t *p_data, uint8_t len, bool cad_enable);

int32_t service_lora_p2p_recv(uint32_t timeout);
```



Possible code from ChatGPT


```
#include <service_lora_p2p.h>

void setup() {
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
  service_lora_p2p_send(payload, sizeof(payload));

  // Add a delay to avoid continuously sending data
  delay(5000); // 5-second delay
}

// Additional functions to handle callbacks or events may be required, 
// depending on the library and hardware specifics.
```
