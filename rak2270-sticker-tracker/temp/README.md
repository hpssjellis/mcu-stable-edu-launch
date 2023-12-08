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
