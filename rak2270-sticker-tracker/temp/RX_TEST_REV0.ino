double myFreq = 915000000;
//uint16_t sf = 12, bw = 0, cr = 0, preamble = 8, txPower = 8;  //PROGRAM DEFAULT
//uint16_t sf = 7, bw = 9, cr = 3, preamble = 8, txPower = 10;  //FILM SENSOR REV1
uint16_t sf = 7, bw = 0, cr = 0, preamble = 10, txPower = 14;  //P2P TEST

bool rx_done = true;

void recv_cb(rui_lora_p2p_recv_t data)
{
    //rx_done = true;
    if (data.BufferSize == 0) 
    {
      Serial.println("Empty buffer.");
    }
    else
    {
    char buff[92];
    sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d",
  	    data.BufferSize, data.Rssi, data.Snr);
    Serial.println(buff);
    }
    Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(30000) ? "Success" : "Fail");
}

void send_cb()
{

}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("RAKwireless LoRaWan P2P Example");
    Serial.println("------------------------------------------------------");
    delay(2000);
    
    if(api.lorawan.nwm.get() != 0)
    {
        Serial.printf("Set Node device work mode %s\r\n",
            api.lorawan.nwm.set(0) ? "Success" : "Fail");
        api.system.reboot();
    }

    Serial.println("P2P Start");
    Serial.printf("Hardware ID: %s\r\n", api.system.chipId.get().c_str());
    Serial.printf("Model ID: %s\r\n", api.system.modelId.get().c_str());
    Serial.printf("RUI API Version: %s\r\n",
  		api.system.apiVersion.get().c_str());
    Serial.printf("Firmware Version: %s\r\n",
  		api.system.firmwareVersion.get().c_str());
    Serial.printf("AT Command Version: %s\r\n",
  		api.system.cliVersion.get().c_str());
    Serial.printf("Set P2P mode frequency %3.3f: %s\r\n", (myFreq / 1e6),
  		api.lorawan.pfreq.set(myFreq) ? "Success" : "Fail");
    Serial.printf("Set P2P mode spreading factor %d: %s\r\n", sf,
  		api.lorawan.psf.set(sf) ? "Success" : "Fail");
    Serial.printf("Set P2P mode bandwidth %d: %s\r\n", bw,
  		api.lorawan.pbw.set(bw) ? "Success" : "Fail");
    Serial.printf("Set P2P mode code rate 4/%d: %s\r\n", (cr + 5),
  		api.lorawan.pcr.set(cr) ? "Success" : "Fail");
    Serial.printf("Set P2P mode preamble length %d: %s\r\n", preamble,
  		api.lorawan.ppl.set(preamble) ? "Success" : "Fail");
    Serial.printf("Set P2P mode tx power %d: %s\r\n", txPower,
  		api.lorawan.ptp.set(txPower) ? "Success" : "Fail");
    api.lorawan.registerPRecvCallback(recv_cb);
    api.lorawan.registerPSendCallback(send_cb);
    Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(30000) ? "Success" : "Fail");
    // let's kick-start things by waiting 3 seconds.
}

void loop() 
{ 
//if(rx_done) 
//{
  //rx_done = false;
  //api.lorawan.precv(0);
  //Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(5000) ? "Success" : "Fail");
//}

}