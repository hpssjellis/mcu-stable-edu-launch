# mcu-stable-edu-launch
What examples should a new microcontroller board present when it is launched

## As of Dec 2023 

1. So far I have tried [$13.99 USD Seeedstudio XIAO Esp32S3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) with [$16.40 USD expansion board](https://www.seeedstudio.com/Seeeduino-XIAO-Expansion-board-p-4746.html) and [$18 USD round color OLED display](https://www.seeedstudio.com/Seeed-Studio-Round-Display-for-XIAO-p-5638.html). This board is ready for use in a school or university Robotics-IOT lab and I have purchased a class set to begin teaching in Feb 2024. See folder [xiao-esp32s3](xiao-esp32s3)

2. I have tried the [$79.99 USD Google Coral Micro](https://coral.ai/products/dev-board-micro/) and have not yet found it ready for my Robotics course. The folder is at [google-coral-micro](google-coral-micro). This board has multiple pins (~200 pins) avaialble through 2 HD connectors. The issues I am having is that it does not seem to be being maintained on the github and as far as I know the machine learning does not work on the Windows Arduino IDE. The USB connection is also a bit strange needing 2 connectors just to be able to do Serial read and write.

3. I am presently trying the $14 USD (+$6 USD for the Cloud site) [RakWireless RAK2270 Sticker Tracker](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker) and I think it has a spot in a Robotics-IOT Advanced class as a pad based board (no headers) with LoRa capability, and sensors: etmp erature humidity and 9 axis accerlometer. Rakwireless is coming out with a development kit soon.

4. [$43.50 USD Nano33BleSense Rev2](https://store-usa.arduino.cc/products/nano-33-ble-sense-rev2-with-headers) totally fine for the classroom (No WiFi only BLE)

5. [$115 USD Nicla Vision] Probably the best board for beginner Machine Learning, but a bit expensive

6. [$114 PortentaH7](https://store-usa.arduino.cc/products/portenta-h7) with the [$69 USD LoRa Vision Shield](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-lora%C2%AE) This is the board I really, with 160 pins available through 2 HD connectors (~160 pins) like but it is fairly expensive and not the best mcu for a classroom as it does not like having wires connected improperly. (Orange LED)

-------

# General 
For Makers, micrconcontrollers launch as soon as the board is ready so that Makers can start using it. This does not work for education that takes from 6 months to 2 years to design a course around the new board which after 2 years is replaced by a cheaper better board. Making a horrible situation for Machine Learning and Robotics Educators. Here is a list of expected examples for a new board to present for it's mcuStableEduLaunch.


Have a webpage saying the date, Platform version, Board Version, library version, link to product, cost and sketch

To be able to teach a new board I would expect these examples: Basically my course [maker100](https://github.com/hpssjellis/maker100)
1. Blink the onboard LED and print to the serial monitor
2. A button that causes an offboard LED to blink
3. Any 2 wire (variable resistor) sensor connected as a voltage divider and the results printed to the Serial Monitor
4. DAC to ADC both Analog and Digital printout to serial monitor
5. Basic programming examples VIDEO-FLAC (Variables, input-output, decisions, events, Objects-Structs, Functions, Loops, Arrays, Classes)
6. WiFi server example, If WiFi not on the board then how to connect a WiFi module   
6B. Possibly a Simple BLE example (I don't teach this)
7. Servo 
8. Simple working Transistor example  
9. Small motor driver  
10. Big motor driver   
10b. Possibly a 120 V relay example (I don't teach this)
11. Stepper motor example
12. Serial I2C (SDA, SCL) example I do the Grove OLED
13. Serial SPI (MISO, SCLK, MOSI, CS-SS) example I do the incredible Pixy2 Shade sensitive ML camera
14. Serial UART (TX, RX) Fingerprint scanner
15. Grove GPS
16. Accelerometer
17. FSLP
18. Grayscale fast OLED with MCU camera
19. E-ink display
20. TFT touch screen
21. SD Card 
22. Ethernet if applicable
23. Multiplexers, both GPIO: input, output, Analog: input, output if you can find any (I don't teach this yet)
24. Other IOT connectivity examples such as websockets, MQTT connectivity, LoRa and LoRaWan, Radio etc



After all these examples are working we can say that the new board is mcu-stable-edu-launch ready for High School and University classrooms
