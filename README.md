# mcu-stable-edu-launch
What examples should a new microcontroller board present when it is launched


All edgeimpulse code is fast if you copy the  the [ESP-NN.zip](ESP-NN.zip) extracted folder into the edgeimpulse installed library into the correct location

..src\edge-impulse-sdk\porting\espressif\ESP-NN



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
