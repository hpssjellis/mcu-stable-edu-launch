

Bit of a pain to install.  Long winded explanaition here https://wiki.seeedstudio.com/get_start_round_display/ 

my Steps:

1. Download and zip install in the Arduino IDE the ```Seeed_Arduino_RoundDisplay```  library  https://github.com/Seeed-Studio/Seeed_Arduino_RoundDisplay/archive/refs/heads/main.zip
2. Find the ```lv_conf.h``` file in the Seeed_Arduino_RoundDisplay main folder from (typically in documents/arduino/libraries/Seeed_Arduino_RoundDisplay) and drag it one folder up to the libraries folder
3. Download and zip install in the Arduino IDE the ```TFT-eSPI``` library https://github.com/Maxwelltoo/TFT_eSPI/archive/refs/heads/master.zip
4. Find the ```User_Setup_Select.h``` file in the ```TFT-eSPI``` and comment out the line that says ```#include <User_Setup.h>``` and uncomment the line ```#include <User_Setups/Setup66_Seeed_XIAO_RoundDisplay.h>``` 
