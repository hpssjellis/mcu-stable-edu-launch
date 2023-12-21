


StartedDec 20th, 2023

The plan is to have a playlist of small videos showing specific things in the big tutorial

Video playlist notes:

# Rakwireless playlist of playlists. 

This playlist simply goes to the entry point for each of the other playlists tutorials


# RAK2270StickerTracker (All short videos)

Full coverage of the main sticker tracker. Every video

1. Setup login at https://trackpac.io/  (Use the QR code to set it up your rak2270stickertracker. ( Do not cut the bottom off the sticker to activate it)
1. removing label (I pull it down enough to show the battery terminals. Reminder don't destroy the qr code)
1. unsolder positive terminal of battery
1. 3D Print latest rig
1. hot glue the pin holes on the rig and scrape off the extra (indent holes if you can). This is easier than re-melting the 3D print
1. push in pogoPins from the top using soldering gun to heat pins
1. line up pins (this is difficult)
1. Check if all pins can be squished, attach elestic bands to cause pressure.
1. For USB TTL serial monitoring and programming over serial attach GND, RX, TX and 3.3V an Arduino can output 3.3V for you. <hr> 
1. Connect the RAK2270StickerTracker with USB TTL monitor setup and working and check the Arduino Serial monitor output. See image below for a fresh RAK2270Sticker Tracker. 
![image](https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/99e4299e-27b2-4385-8317-00950a99aea8)
1. Now check at https://trackpac.io/ to see if the data is following to the website. (Instead of waiting an hour just recycle the power and it will send more data)
1. Note: How inaccurate the location data is. It is just showing you where the HotSpot that is sensing your sticker is located. Hopefully by triangulation it can make better estimates but I doubt if they will be very good since LoRaWan signal strnegth does not represent distance as line of sight is always better signal strength than going through objects.
1. Test if ```AT+BOOT``` and ```AT+RUN``` (Note: small letters are fine) This will also reset the board and send new data to trackpac.io <hr><br>
1. Now test and record on the following chart all the default data on the board especially the LoRaWan connections devEui, AppEui, AppKey as they have been set at the factory and if you change them and can't reset them you lose your access to TrackPac.io 
![image](https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/88614bf7-9d71-4b27-bc9a-266105ce0506)
1. Note: AT+NWM=?    switches between LoRa P2P and LoRaWan so it is very important
1. Note: Sending to trackPac.io probably needs a set data format that I don't know, so you should change the AppKey and setup your own Helium/Chirptstack or The Things Network LoRaWan sit that sends to another cloud site. I use free Adafruit.io See link on this page  [rak2270-lorawan-helium-to-adafruit-mqtt-cayenne-lpp](https://github.com/hpssjellis/mcu-stable-edu-launch/blob/main/rak2270-sticker-tracker/video-playlist.md#rak2270-lorawan-helium-to-adafruit-mqtt-cayenne-lpp)  <hr> <br>
1. Let's switch to LoRa P2P ```AT+NWM=0``` Repeat the above steps for a second sticker tracker so that you can send LoRa P2P communicaiton back and forth
1. When both sticker trackers are in  ```AT+NWM=0``` LoRa P2P mode try sending from one to the other. Set one to send only ```AT+PRECV=0``` and the other to receive only  ```AT+PREC=65534``` Then send data using ```AT+PSEND=314161``` (note: send even number of bytes since 2 bytes make a character.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.
1.







# Rak2270DevKit
1. First look
2. Coding it


# RAK2270StickerTracker 3D Printined rig with PogoPins

# RAK2270 TTL USB

# RAKDAP1

# RAK2270 LoRa P2P send

# RAK2270 LoRa P2P receive 

# RAK2270 LoRa P2P receive Novel WebSerial Static webpage monitor

# RAK2270 LoRaWan Helium to Adafruit MQTT Cayenne LPP

# RAK2270 Machine Learning Acceleration (x,y,z)


















