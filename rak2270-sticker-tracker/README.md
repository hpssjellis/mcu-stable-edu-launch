
RAK2270 Sticker Tracker

RAKwireless store at  

https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=42714196967622

<img width="669" alt="image" src="https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/a63e5854-690c-4ad9-a133-5c6de194e9e3">


Github at

https://github.com/RAKWireless/RAK2270-Sticker-Tracker

but the firmware for the tracker is at github

https://github.com/RAKWireless/RAK-STM32-RUI

This website uses the sticker tracker to program some machine learning. (This is advanced)

https://hpssjellis.github.io/tinyMLjs/public/acceleration/a00-best-acceleration-rak2270-sticker-tracker.html



My 3D Print Rig for it is at 

https://github.com/hpssjellis/my-3D-printing-stl/tree/master/RAK2270



Arduino IDE prefernces    
```
https://raw.githubusercontent.com/RAKWireless/RAKwireless-Arduino-BSP-Index/main/package_rakwireless.com_rui_index.json
```

Load the RAK3272-SIP Board  (which is a bit confusing that it has a different name)


Possibly does not install on the new windows Arduino IDE
Fine on Linux. 


# Best links:


Rak Forum my chat  https://forum.rakwireless.com/t/rak2270-sticker-tracker-nov-2023-update/10800

RUI3 API coding    https://docs.rakwireless.com/RUI3/Arduino-API/#read

RUI3 "AT" LoRa P2P commands   https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#p2p-instructions

RUI3 "AT" LoRaWan Commands   https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content



Note: Kind of like ASCII but not really.

```
AT+PSEND=303132      sends 012
AT+PSEND=616263      sends abc
AT+PSEND=414243      sends ABC

AT+PSEND=3a3b3c3d3e3f40     sends :;<=>?@

AT+PSEND=5b5c5d5e5f60    sends  [\]^_`

AT+PSEND=1f20212223242526272829202a2b2c2d2e2f3031      sends  !"#$%&'()*+,-./01        Note the space for AT+PSEND=20     


```



# Software
The main chip used on the RAK2270 is the WisDuo Module RAK3172-SiP/RAK3172LP-SiP (pin-to-pin and software compatible). This chip has STM32WL SoC which is a combination of MCU and LoRa/SubGhz transceiver. 
The firmware written on this is based on [RUI3](https://docs.rakwireless.com/RUI3/). You can start creating your own firmware using this [RAK3172-SiP guide](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3172-SiP/Quickstart/#rak3172-sip-as-a-stand-alone-device-using-rui3).


<img width="800" alt="image" src="https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/20fdae1b-bc87-4d19-8777-8efe0ed5f843">







Useful AT commands list

https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content


Interesting link for RAK downloads

https://downloads.rakwireless.com/




RAK2270 Quickstart pdf   

https://s3.eu-central-1.amazonaws.com/rakwireless-downloads-center-prod/LoRa/RAK2270/Quick%20Start%20Guide/RAK2270%20Quick%20Start%20Guide.pdf


RAK270 Datasheet

https://s3.eu-central-1.amazonaws.com/rakwireless-downloads-center-prod/LoRa/RAK2270/Datasheet/RAK2270%20Datasheet.pdf




## accelerometer 

It uses the LIS3DH  ?  I need more info!





https://store.rakwireless.com/products/daplink-tool?m=5&h=wisblock-accessory   RAKDAP1   $10 USD

<img width="500" alt="image" src="https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/7592e52d-1c52-4929-9fd6-ab74dadba277">




Arm datasheet stm32wle5

https://www.st.com/resource/en/datasheet/stm32wle5c8.pdf



# DEMO AT

https://hpssjellis.github.io/mcu-stable-edu-launch/rak2270-sticker-tracker/html/lora-webpage03.html

