/***
 *  This example shows LoRaWan protocol joining the network in OTAA mode, class A, region EU868.
 *  Device will send uplink every 20 seconds.
***/


#include <CayenneLPP.h>
#include <service_lora_p2p.h>



#define OTAA_PERIOD   (70000)

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

CayenneLPP lpp(51);










void setup()
{
    Serial.begin(115200, RAK_AT_MODE);
    delay(5000);
    Serial.println("You have 15 s to connect the serial monitor");
    delay(5000);
    Serial.println("You have 10 s to connect the serial monitor");
    delay(5000);
    Serial.println("You have 5 s to connect the serial monitor"); 
    delay(5000);
     
    Serial.println("RAKwireless LoRaWan OTAA Example");
    Serial.println("------------------------------------------------------");


/*
    if(api.lorawan.nwm.get() != 1)   // 0 = P2P LoRa,   1= LoRaWan
    {
        Serial.printf("Set to LoRaWan mode %s\r\n",
            api.lorawan.nwm.set(0) ? "Success" : "Fail");
       // api.system.reboot();
    }


*/

//SERVICE_LORA_WORK_MODE myN3 = SERVICE_LORA_LORAWAN;  // SERVICE_LORA_P2P;
  service_lora_set_nwm(SERVICE_LORAWAN);  // 0=LoRA,   1= LoRaWan
  /*
  int32_t mmyNwm = service_lora_get_nwm();
  Serial.println(myNwm);
  */
  delay(2000);
    
    if (!api.lorawan.join())  // Join to Gateway
    {
        Serial.printf("LoRaWan OTAA - join fail! \r\n");
        return;
    }
  
    /** Wait for Join success */
    while (api.lorawan.njs.get() == 0) {
        Serial.print("Wait for LoRaWAN join...");
        api.lorawan.join();
        delay(10000);
    }

    show_at();

/*

    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF"); // Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");  // Check Confirm status
    
    uint8_t assigned_dev_addr[4] = { 0 };
    api.lorawan.daddr.get(assigned_dev_addr, 4);
    Serial.printf("Device Address is %02X%02X%02X%02X\r\n", assigned_dev_addr[0], assigned_dev_addr[1], assigned_dev_addr[2], assigned_dev_addr[3]);  // Check Device Address
    Serial.printf("Uplink period is %ums\r\n", OTAA_PERIOD);
    Serial.println("");
*/

    
    api.lorawan.registerRecvCallback(recvCallback);
    api.lorawan.registerJoinCallback(joinCallback);
    api.lorawan.registerSendCallback(sendCallback);
}




void loop()
{
    static uint64_t last = 0;
    static uint64_t elapsed;
  
    if ((elapsed = millis() - last) > OTAA_PERIOD) {
        Serial.println("Wakeup..");
        uplink_routine(); 
        last = millis();        
        Serial.printf("Try sleep %ums..", OTAA_PERIOD);
        DoP2P();
    }

    api.system.sleep.all(OTAA_PERIOD);

}





void recvCallback(SERVICE_LORA_RECEIVE_T * data)
{
    if (data->BufferSize > 0) {
        Serial.println("Something received!");
        for (int i = 0; i < data->BufferSize; i++) {
            Serial.printf("%x", data->Buffer[i]);
        }
        Serial.print("\r\n");
    }
}

void joinCallback(int32_t status)
{
    Serial.printf("Join status: %d\r\n", status);
}

void sendCallback(int32_t status)
{
    if (status == RAK_LORAMAC_STATUS_OK) {
        Serial.println("Successfully sent");
    } else {
        Serial.println("Sending failed");
    }
}



void uplink_routine()
{

  


    
    uint8_t *bufPtr;
    uint8_t data_len = 0;


  lpp.reset();
  float x = rand() / 10000000.0; //analogRead(A0)
  lpp.addTemperature(1, x); 

    bufPtr = lpp.getBuffer();
    data_len = lpp.getSize();
    memcpy(collected_data , bufPtr  , data_len);


    Serial.println();
    Serial.println("Sending:" + String(x, 1));

    if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, false, 1)) {
    

        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}

void show_at()
{

    // A WORK IN PROGRESS
    Serial.println("General LoRaWan Data from AT commands");


//   Serial.printf("DevEui: %s\r\n", api.lorawan.deui.get());
  //  Serial.printf("AppEui: %s\r\n", api.lorawan.appeui.get() );
  //  Serial.printf("AppKey: %s\r\n", api.lorawan.appkey.get() );

    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF"); // Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");  // Check Confirm status

}




void DoP2P(){



    Serial.println("Sending P2P");
    delay(10000);
//SERVICE_LORA_WORK_MODE myN2 = SERVICE_LORA_P2P;
service_lora_set_nwm(SERVICE_LORA_P2P);  // 0=LoRA,   1= LoRaWan
  /*
  int32_t myNwm = service_lora_get_nwm();
  Serial.println(myNwm);
  */
  delay(2000);
    
  uint8_t payload[] = "Who flipped me over?"; // Hex representation of "314161"

  // Send the payload using the service_lora_p2p_send function
  service_lora_p2p_send(payload, sizeof(payload), false);

  // Add a delay to avoid continuously sending data
  delay(5000); // 5-second delay

//SERVICE_LORA_WORK_MODE myN = SERVICE_LORA_LORAWAN;  // SERVICE_LORA_P2P;
service_lora_set_nwm(SERVICE_LORAWAN);  // 0=LoRA,   1= LoRaWan
  /*
  int32_t mmyNwm = service_lora_get_nwm();
  Serial.println(myNwm);
  */
  delay(2000);
  


  
}
