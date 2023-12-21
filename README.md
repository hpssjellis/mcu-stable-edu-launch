# mcu-stable-edu-launch
What examples should a new microcontroller board present when it is launched

## As of Dec 2023 

1. So far I have tried [$13.99 USD Seeedstudio XIAO Esp32S3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) with [$16.40 USD expansion board](https://www.seeedstudio.com/Seeeduino-XIAO-Expansion-board-p-4746.html) and [$18 USD round color OLED display](https://www.seeedstudio.com/Seeed-Studio-Round-Display-for-XIAO-p-5638.html). This board is ready for use in a school or university Robotics-IOT lab and I have purchased a class set to begin teaching in Feb 2024. See folder [xiao-esp32s3](xiao-esp32s3)

2. I have tried the [$79.99 USD Google Coral Micro](https://coral.ai/products/dev-board-micro/) and have not yet found it ready for my Robotics course [google-coral-micro](google-coral-micro)

3. I am presently tring the $14 USD (+$6 USD Cloud site) [RakWireless RAK2270 Sticker Tracker](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker) and I think it has a spot in a Robotics-IOT Advanced class as an pad board with LoRa capability. Rakwireless is coming out with a development kit soon.

4. Nano33BleSense Rev2 totally fine for the classroom
5. Nicla Vision Probably the best board for beginner Machine Learning

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
