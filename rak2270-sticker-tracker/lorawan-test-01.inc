/**
 * Example of ABP device
 * Authors: 
 *        Ivan Moreno
 *        Eduardo Contreras
 *  June 2019
 * 
 * This code is beerware; if you see me (or any other collaborator 
 * member) at the local, and you've found our code helpful, 
 * please buy us a round!
 * Distributed as-is; no warranty is given.
 */
//#include <lorawan.h>
#include<CayenneLPP.h>

CayenneLPP lpp(51);
/*
//ABP Credentials 
const char *devAddr = "00000000";
const char *nwkSKey = "00000000000000000000000000000000";
const char *appSKey = "00000000000000000000000000000000";
*/
const unsigned long interval = 200000;    // 60 s interval to send message
unsigned long previousMillis = 0;  // will store last time message sent
unsigned int counter = 0;     // message counter



uint8_t *bufPtr;
uint8_t collected_data[51] = { 0 };
uint8_t data_len = 0;


  
char myStr[50];
char outStr[255];
byte recvStatus = 0;


/*
const sRFM_pins RFM_pins = {
  .CS = 20,
  .RST = 9,
  .DIO0 = 0,
  .DIO1 = 1,
  .DIO2 = 2,
  .DIO5 = 15,
};


*/
void setup() {
  // Setup loraid access
  Serial.begin(115200);
  delay(5000);
  Serial.println("Wait 20 s");
  delay(5000);
  Serial.println("Wait 15 s");
  delay(5000);
  Serial.println("Wait 10 s");
  delay(5000);
  Serial.println();
  
  //api.lorawan(?);
  
  Serial.println();

  
       //join lora
    Serial.println("Wait for LoRaWAN join...");
    if (!api.lorawan.join(1,0,7,3))  // Join to Gateway
    {
      Serial.printf("LoRaWan OTAA - join fail! \r\n");
    } 

    
  /*
  if(!lora.init()){
    Serial.println("RFM95 not detected");
    delay(5000);
    return;
  }


*/

/*

  // Set LoRaWAN Class change CLASS_A or CLASS_C
  lora.setDeviceClass(CLASS_A);

  // Set Data Rate
  lora.setDataRate(SF8BW125);

  // set channel to random
  lora.setChannel(MULTI);
  
  // Put ABP Key and DevAddress here
  lora.setNwkSKey(nwkSKey);
  lora.setAppSKey(appSKey);
  lora.setDevAddr(devAddr);


  */
}





void loop() {
  // Check interval overflow
  if(millis() - previousMillis > interval) {
    previousMillis = millis(); 

    printVariables();


/*
    bufPtr = g_solution_data.getBuffer();
    data_len = g_solution_data.getSize();
    memcpy(collected_data , bufPtr  , data_len);
    
    if (api.lorawan.send(data_len, (uint8_t *) & collected_data, fport, api.lorawan.cfm.get(), 1)) 
    

    */

    Serial.print("Sending: ");


    
   // lora.sendUplink((char *)lpp.getBuffer(), lpp.getSize(), 0, 1);

//  if (api.lorawan.send(data_len, (uint8_t *) & collected_data, fport_period_uplink, api.lorawan.cfm.get(), 1)) 
 
//  if (api.lorawan.send(lpp.getSize(), (uint8_t *)lpp.getBuffer(), 3, api.lorawan.cfm.get(), 1)) 
 // if (api.lorawan.send(lpp.getSize(), (uint8_t *)lpp.getBuffer(), 2, api.lorawan.cfm.get(), 1 ) ) 


    bufPtr = lpp.getBuffer();
    data_len = lpp.getSize();
    memcpy(collected_data , bufPtr  , data_len);

    

//char *dataReceived; // This is your received data as char *
// ... code to receive data ...

uint8_t *byteData = reinterpret_cast<uint8_t *>(lpp.getBuffer());
// Now you can use byteData as uint8_t *


   // This one might be the best and only one working
 //if (api.lorawan.lpsend(4, 0, (uint8_t *) & collected_data, data_len)) 
 
 //  if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 4, api.lorawan.cfm.get(), 1)) 

 //AT+SEND=4:0467041A
 //AT+LPSEND=4:0:0467041A




 
  // best does actually work. 
  if (api.lorawan.lpsend(2, 0, (uint8_t *) & byteData , lpp.getSize())) 

  // i don't think this one works even with small 
  // if (api.lorawan.send(lpp.getSize(), (uint8_t *) & byteData , 2, api.lorawan.cfm.get(), 1) )


  
    
  //  if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, api.lorawan.cfm.get(), 1)) 
   // if (api.lorawan.send(lpp.getSize(), (uint8_t *) & byteData , 2, api.lorawan.cfm.get(), 1)) 

   
   // if (api.lorawan.send(lpp.getSize(), (uint8_t *) & byteData , 2, api.lorawan.cfm.get(), 1) )
   
{
 
        Serial.println("Sending is requested");
}
      else {
        Serial.println("Sending failed");

}

//03683C0467067C07730010080200C8
    
  }   // end if


/*
 * 
 * 
  recvStatus = lora.readData(outStr);
  if(recvStatus) {
    Serial.println(outStr);
  }

*/
  
  // Check Lora RX
  //lora.update();
}

void printVariables()
{
  lpp.reset();

  Serial.println();
  int temp = random(0,200);
  Serial.print(F("Random Temp="));
  Serial.print(temp, 1);
  lpp.addTemperature(4, temp);


/*
  
  int humidity = random(0,300);
  Serial.print(F("humidity="));
  Serial.print(humidity, 1);
  lpp.addRelativeHumidity(3, humidity);

  int pressure = random(0,2000);
  Serial.print(F(", pressure="));
  Serial.print((pressure/100.0), 2);
  lpp.addBarometricPressure(7,(pressure/100.0));

  int batt_lvl = random(0,3.3);
  Serial.print(F(", batt_lvl="));
  Serial.println(batt_lvl, 2);
  lpp.addAnalogInput(8, batt_lvl);



  */
  Serial.println();
  Serial.println(F("----------------"));

  Serial.println(lpp.getSize());
  if (lpp.getSize() >= 11) {     // might be 12 have to test
    Serial.print("AT+LPSEND=2:0:");
  } else {

    Serial.print("AT+SEND=2:");
  
  }
  for (uint8_t i=0; i< lpp.getSize(); i++) {
      if(lpp.getBuffer()[i] < 0X10 ) { Serial.print("0");  }
      Serial.print( lpp.getBuffer()[i], HEX);
    }
  
  //Serial.write( lpp.getBuffer(), lpp.getSize());
  Serial.println();




  
}
