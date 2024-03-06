August 2023

Awesome tutorial here using edgeLab  ML with the XIAO-Sense

https://wiki.seeedstudio.com/tinyml_workshop_course/

which uses   senseCraft   https://seeed-studio.github.io/SenseCraft-Web-Toolkit/#/setup/process

This esp flashing tool is also interesting

https://espressif.github.io/esptool-js/



![image](https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/44be02f9-3c90-476c-a86b-9c96c78dc9c9)


April 2023



All edgeimpulse code is fast if you copy the  the [ESP-NN.zip](ESP-NN.zip) extracted folder into the edgeimpulse installed library into the correct location

```..src\edge-impulse-sdk\porting\espressif\ESP-NN```




This XIAO Esp32s3 for $15 USD shows amazing potentail for Robotics and Machine Learning Education but presently the Education Launch is not yet read. See this CSV file of the process

[xiao-esp32s3/edu-launch-esp32s3.csv](xiao-esp32s3/edu-launch-esp32s3.csv)

## The getting started XIAO Sense is very good. Look at the examples
https://wiki.seeedstudio.com/xiao_esp32s3_getting_started


# Marcelo link (More XIAO Sense working  examples)  
https://github.com/Mjrovai/XIAO-ESP32S3-Sense

For ML sound try his file at   https://github.com/Mjrovai/XIAO-ESP32S3-Sense/blob/main/xiao_esp32s3_microphone/xiao_esp32s3_microphone.ino  it is for a downloaded edgeimpulse include file

For the grove vision ai v2 this is essential

https://www.hackster.io/mjrobot/computer-vision-at-the-edge-with-grove-vision-ai-module-v2-0003c7

## NOTE: For new programs hold boot button while plugging in the USB cable. I have a small 3D Printed clip to help hold the boot button

Then after the program is uploaded unplug and plug in the USB cable again but without holding the boot button (YOu could push the reset button but it is hard to push.)

## Note: might as well activate the PSRAM  Tools--> PSRAM --> OPI PSRAM


This line is needed for camera stuff
```
#define CAMERA_MODEL_XIAO_ESP32S3  Has PSRAM    // Note Has PSRAM is important
```

and perhaps this

```

#elif defined(CAMERA_MODEL_XIAO_ESP32S3)
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     10
#define SIOD_GPIO_NUM     40
#define SIOC_GPIO_NUM     39

#define Y9_GPIO_NUM       48
#define Y8_GPIO_NUM       11
#define Y7_GPIO_NUM       12
#define Y6_GPIO_NUM       14
#define Y5_GPIO_NUM       16
#define Y4_GPIO_NUM       18
#define Y3_GPIO_NUM       17
#define Y2_GPIO_NUM       15
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     47
#define PCLK_GPIO_NUM     13
```












Iages in JPG format working along with saving to the SD card and WiFi  and basic BLE.



## XIAO Esp32s3 (sense) 

Notice my 3D printed clip to help depress the boot button when you plug the usb cable in. STL file here [XIAO-esp32s3-pin-hold01-v04.stl](XIAO-esp32s3-pin-hold01-v04.stl)

Impressive camera, WiFi/BLE SD card, mic all for around $15 USD

<img width=800 src="https://user-images.githubusercontent.com/5605614/234172684-73cca7de-0868-4178-ba56-516ea1afe3f3.jpg" /><br>

<br><br><br>

Color Images 1600px by 1200px RGB JPG images<br>
<img width=400 src="https://user-images.githubusercontent.com/5605614/234101828-6c487024-0c76-4797-b660-688db3c12ff3.jpg" /><br>
<img width=400 src="https://user-images.githubusercontent.com/5605614/234101845-e76cf515-bbe5-4c54-a381-1945e697e21f.jpg" /><br>

<br><br>
Web Server showing images streamed and able to save<br>

<img width=400 src="https://user-images.githubusercontent.com/5605614/234172678-32683f4b-19de-4127-9cec-fc7d6ef5cb85.png" /><br>



.
XIAO esp32s3 using GRAYSCALE and 96x96 resolution with waveshare 128x128 fast OLED. This is in prep to get an edgeimpulse machine learning model working quickly <br>
<img width=400 src="https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/7fbf78b3-e1a6-49cd-97a5-e8e43c0ace53" /><br>


.





Datasheet   https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf

Technical sheet  https://www.espressif.com/sites/default/files/documentation/esp32-s3_technical_reference_manual_en.pdf

