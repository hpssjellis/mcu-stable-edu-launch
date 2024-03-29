/*
* RocksettaTinyML by Jeremy Ellis,keyfreemusic@gmail.com
*
* Based on the Arduino Library
* EloquentTinyML by Simone Salerno,eloquentarduino@gmail.com
* https://github.com/eloquentarduino/EloquentTinyML
* 
* Passed from the main program
* #define NUMBER_OF_INPUTS 8
* #define TYPE_OF_INPUTS int32             // uint8_t | int32 | float | bool | double | String 
* 
* #define NUMBER_OF_OUTPUTS 4
* #define TYPE_OF_OUTPUTS float            // uint8_t |int32 | float | bool | double | String 
* 
* #define RETURN_TYPE_FROM_PREDICT float    // void | uint8_t | int32 | float | bool | double | String 
* 
*/




#include <Arduino.h> // Only needed for https://platformio.org/
#include <RocksettaTinyML.h>
#include "rak2270-motion-2-label.h"


//#include <Arduino_LSM9DS1.h> 
//#include <Arduino_LSM6DSOX.h>
//#include "VL53L1X.h"

#include "SparkFunLIS3DH.h"  // for RAK2270 Sticker Tracker

// GLOBAL VAERIABLES
//VL53L1X proximity;



LIS3DH myIMU(I2C_MODE, 0x19); //Default constructor is I2C, addr 0x19.








/*
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


*/

#define NUMBER_OF_INPUTS 108    //  3 senses x 36 readings each input array has 25 integer readings
#define NUMBER_OF_OUTPUTS 3    // one float output
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

// GLOBAL VARIABLES
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
float myInput[NUMBER_OF_INPUTS];
float myOutput[NUMBER_OF_OUTPUTS];
int myCurrentIndex = 0;



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait

  ml.begin(model_files_model_tflite);   // standard c-header name inside the include file


  //myStart = millis();   // set delay
 // randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles


  /*
  if (!IMU.begin()) {
     Serial.println("Failed to initialize IMU!");
     while (1);
  }


*/

  // Initilize the Proximity sensor and com using wire1
  //Wire1.begin();
  //Wire1.setClock(400000); // use 400 kHz I2C
  //proximity.setBus(&Wire1);



 // if (!proximity.init()) {
 //   Serial.println("Failed to detect and initialize sensor!");
 //   while (1);
 // }

 // proximity.setDistanceMode(VL53L1X::Long);
 // proximity.setMeasurementTimingBudget(10000);
 // proximity.startContinuous(10);


  // initialize buffer to zeros
  for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
    myInput[i] = 0.0;
  }




  // Now the RAK2270 Accelerometer
  
    myIMU.settings.adcEnabled = 1;
    myIMU.settings.tempEnabled = 1;
    myIMU.settings.accelSampleRate = 50;  //Hz.  Can be: 0,1,10,25,50,100,200,400,1600,5000 Hz
    myIMU.settings.accelRange = 16;      //Max G force readable.  Can be: 2, 4, 8, 16
    myIMU.settings.xAccelEnabled = 1;
    myIMU.settings.yAccelEnabled = 1;
    myIMU.settings.zAccelEnabled = 1;


     //Call .begin() to configure the IMU
    myIMU.begin();






  
}

void loop() {


//delay(300);

/*
float x, y, z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    x *= 1.00;  //9.81;
    y *= 1.00;  //9.81;
    z *= 1.00;  //9.81;
  }


*/

float myX, myY, myZ;

     myX = (myIMU.readFloatAccelX() * 9.8) - 0.50;
     myY = (myIMU.readFloatAccelY() * 9.8) + 0.50;
     myZ = (myIMU.readFloatAccelZ() * -9.8) + 0.50;

 /* 
     Serial.println( String(myX) + "," + String(myY) + "," +  String(myZ)  );
     delay(50);  // careful here what should be the delay ????? Should it be none blocking with a timer??
*/

  myInput[myCurrentIndex] = myX;
  myInput[myCurrentIndex+1] = myY;
  myInput[myCurrentIndex+2] = myZ;

  // this could be done easier
  myCurrentIndex = (myCurrentIndex + 3) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.

if (myCurrentIndex % NUMBER_OF_INPUTS == 0) {   // slows down showing the results



  float myPredict = ml.predict(myInput, myOutput); // make the proximity prediction on the last 36 samples

  Serial.print("Predicted: "+String(myPredict)  );  // output with minimal formating
 // Serial.println(String(ml.output[0]) );  
 // Serial.println("--" );  
  Serial.println(", same as Label[0]=1flat:"+String(myOutput[0]) + ", label[1]=2side::" + String(myOutput[1])  );  // output for plotter minimal formating
  
  if (myPredict > 0.50) {  
    digitalWrite(LED_BUILTIN, LOW);    // on for portenta, off for Nano33BleSense, Send for RAK2270-sticker-tracker
    mySendLoRaP2P();
}
else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(40);  // just to slow it a bit
}

}


void mySendLoRaP2P() {
  // what to do now?
}





