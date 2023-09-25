## First look at the Google Coral Micro with WiFi and POE Power on Ethernet shields

## Sep 25th, 2023 Update

1. Works best on Linux, (I didn;t test a Mac), works on WSL (Linux on Windows) but no access to the Port for uploading. Working on this.
2. Installs on both Arduino IDE old and New but onnly compiles on the new IDE 2.x Simple code works on Arduino IDE, I have not yet got machine learning code working with the new Arduino IDE.


### On Linux, Ubuntu

To find the Serial USB port
```
ls /dev/ttyUSB*
```

To find the USB Serial Port 
```
ls /dev/ttyUSB*
```

If you make your own foler then to build that folder use (check this) expect the code to be built in the same folder as the sketch
```
bash build.sh -b /foldername
```






### Original Post

[installation-notes.md](installation-notes.md) Notes about how installation is going.

Suggests linux or Mac, but does install on widows Arduino IDE 2 using this preference
```
https://dl.google.com/coral/micro/package_coral_index.json
```

First starting spots Coral- Micro with Arduino

https://coral.ai/docs/dev-board-micro/arduino/#1-gather-requirements

Coral API for Arduino
https://coral.ai/docs/reference/micro/arduino/



Main CoralMicro github for Arduino

https://github.com/google-coral/coralmicro

