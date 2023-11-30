


api.lorawan.join(1,0,7,3)

api.lorawan.nwm.get()


api.lorawan.njs.get()

api.lorawan.cfm.get()


//  if (!api.lorawan.deviceClass.set(RAK_LORA_CLASS_A)) 




if (api.lorawan.send(data->BufferSize, (uint8_t *) data->Buffer, fport, api.lorawan.cfm.get(), retry))
                        Serial.println("Sending is requested");
                    else
                        Serial.println("Sending failed");
                        




      if (api.lorawan.send(data_len, (uint8_t *) & collected_data, fport_period_uplink, api.lorawan.cfm.get(), 1)) // 周期发送数据
        Serial.println("Sending is requested");
      else
        Serial.println("Sending failed");
      last = millis();
    }






  api.lorawan.registerRecvCallback(recvCallback);
  api.lorawan.registerJoinCallback(joinCallback);
  api.lorawan.registerSendCallback(sendCallback);
  service_lora_register_linkcheck_cb(linkcheckCallback);


  
