

Bit of a pain to install.  Long winded explanaition here https://wiki.seeedstudio.com/get_start_round_display/ 

my Steps:

1. Download and zip install in the Arduino IDE the ```Seeed_Arduino_RoundDisplay```  library  https://github.com/Seeed-Studio/Seeed_Arduino_RoundDisplay/archive/refs/heads/main.zip
2. Find the ```lv_conf.h``` file in the Seeed_Arduino_RoundDisplay main folder from (typically in documents/arduino/libraries/Seeed_Arduino_RoundDisplay) and drag it one folder up to the libraries folder
3. Download into the Arduino IDE the normal way the ```LVGL``` library, but don't move it's config folder into the main libraries folder since you already did it above
4. Download into the Arduino IDE the normal way the ```TFT-eSPI``` library, don't load the one Seeedstudio gave as a zip file as it did not work for me.
5. Find the ```User_Setup_Select.h``` file in the ```TFT-eSPI``` library folder and comment out the line that says ```#include <User_Setup.h>``` and add below it the line ```#define TOUCH_CS PIN_D2   ``` and uncomment the line ```#include <User_Setups/Setup66_Seeed_XIAO_RoundDisplay.h>```
6. Download into the Arduino IDE the normal way the ```animationGif``` library by Laryy Bank
7. Download into the Arduino IDE the normal way the ```SD``` library 
8. Download into the Arduino IDE the normal way the ```I2C_BM8563``` library

9. NOPE NOT WORKING
