//#include <Servo.h>
#include <ESP32Servo.h> 


void setup() {
  Serial.begin(115200);
  myServo.attach(A1, 1000, 2000); 
  delay(5000);

  
  myServo.milliseconds(0);    // not realy needed
  delay(500);  
  myServo.milliseconds(1500);  // middle not really needed
  delay(1000);
  myServo.milliseconds(1600);  // slow forward
  Serial.println("Slow forward");
  delay(1000);

  myServo.milliseconds(0);
  delay(500);
  myServo.milliseconds(1500);  // middle
  delay(1000);
  myServo.milliseconds(1400);  // slow reverse
  
  Serial.println("Slow backward");
  delay(1000);

  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
