/*
#if  defined (XIAO_ESP32S3) ||  defined (XIAO_ESP32C3)  //if esp32s3 or esp32C3
  #include <ESP32Servo.h>
#else // all other Arduino boards
//  #include <Servo.h>
#endif
*/
#include <ESP32Servo.h> // esp32 
//#include <Servo.h>   // most arduinos
Servo myservo;

void setup() {
  Serial.begin(115200);
  myservo.attach(A1, 1000, 2000); 
  delay(5000);
  Serial.println("Time to control an ESC Motor driver"); 
}

void loop() {

  myservo.writeMicroseconds(0);    // not realy needed
  delay(500);  
  myservo.writeMicroseconds(1500);  // middle not really needed
  delay(1000);

  
  myservo.writeMicroseconds(1600);  // slow forward
  Serial.println("Slow forward");
  delay(1000);

  myservo.writeMicroseconds(0);
  delay(500);
  myservo.writeMicroseconds(1500);  // middle
  delay(1000);
  myservo.writeMicroseconds(1400);  // slow reverse
  
  Serial.println("Slow backward");
  delay(1000);

  
  Serial.println("Wait 5 seconds");
  delay(5000);

}
