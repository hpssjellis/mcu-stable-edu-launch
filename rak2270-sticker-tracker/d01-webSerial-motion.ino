/*
 * webSerial for testing javascript connection with an arduino
 * 
 * Latest work at   https://github.com/hpssjellis/webMLserial
 * 
 * Note: On the Arduino Serial monitor make sure no line-ending or if statements will not work
 * 
 * Android https://hpssjellis.github.io/web-serial-polyfill/index.html
 * Laptops Desktops  https://hpssjellis.github.io/my-examples-of-arduino-webUSB-webSerial/public/index.html
 * IOS     not really sure
 * 
 */



#include <Arduino.h> // Only needed for https://platformio.org/
//#include <Arduino_LSM9DS1.h> 
//#include <Arduino_LSM6DSOX.h>
//#include "VL53L1X.h"

#include "SparkFunLIS3DH.h"  // for RAK2270 Sticker Tracker



LIS3DH myIMU(I2C_MODE, 0x19); //Default constructor is I2C, addr 0x19.





// GLOBAL VAERIABLES
//VL53L1X proximity;

#define FREQUENCY_HZ        25     // how many samples per second 
#define COLLECTION_SECONDS  1     // how many seconds to collect samples
#define INTERVAL_MS  (1000 / (FREQUENCY_HZ + 1)) // need for the timer 
#define CONVERT_G_TO_MS2    9.80665f   // accleration conversion

int myMaxData = FREQUENCY_HZ * COLLECTION_SECONDS;
int myCount = 0;
int myDelay = INTERVAL_MS;   // non-block delay in milliseconds
unsigned long myStart; 

String readString;
bool mySendData = true;
bool mySendProximity = false;
int myProximityReading = 0;


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait
  
  myStart = millis();   // set delay
  randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles


  // Now the RAK2270 Accelerometer
  
    myIMU.settings.adcEnabled = 1;
    myIMU.settings.tempEnabled = 0;   //1;
    myIMU.settings.accelSampleRate = 50;  // 200;  //Hz.  Can be: 0,1,10,25,50,100,200,400,1600,5000 Hz
    myIMU.settings.accelRange = 4;  //16;      //Max G force readable.  Can be: 2, 4, 8, 16
    myIMU.settings.xAccelEnabled = 1;
    myIMU.settings.yAccelEnabled = 1;
    myIMU.settings.zAccelEnabled = 1;


     //Call .begin() to configure the IMU
    myIMU.begin();


  /*
  if (!IMU.begin()) {
     Serial.println("Failed to initialize IMU!");
     while (1);
  }


  // Initilize the Proximity sensor and com using wire1
  Wire1.begin();
  Wire1.setClock(400000); // use 400 kHz I2C
  proximity.setBus(&Wire1);



  if (!proximity.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  proximity.setDistanceMode(VL53L1X::Long);
  proximity.setMeasurementTimingBudget(10000);
  proximity.startContinuous(10);


  */

}

void loop() {
  //float x, y, z;
//myProximityReading = proximity.read();

/*


  if ( (millis() - myStart ) >= myDelay) {       
     myStart = millis();      //  reset the delay time
     myCount += 1;


     */

   float myX, myY, myZ;
   int myCount;

   delay(5000);
   
   Serial.println( "" );
   Serial.println( "" );
   Serial.println( "" );
   delay(50); // short delay to get ready to do something

   // heading best if saving csv files
   //  Serial.println( "accX, accY, accZ" );

   for (myCount=0; myCount < 36; myCount++){
     myX = (myIMU.readFloatAccelX() * 9.8) - 0.44;
     myY = (myIMU.readFloatAccelY() * 9.8) + 0.48;
     myZ = (myIMU.readFloatAccelZ() * -9.8) + 0.40;
  
     Serial.println( String(myX) + "," + String(myY) + "," +  String(myZ)  );
     delay(50);
   }










   }

