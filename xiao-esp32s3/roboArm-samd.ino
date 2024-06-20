// needs the XIAO-SAMD borad to run 6 servos
then send a digital high to D0 to activate the roboArm

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// Define the pins for each servo
int servoPin1 = 1;
int servoPin2 = 2;
int servoPin3 = 3;
int servoPin4 = 4;
int servoPin5 = 5;
int servoPin6 = 6;

void setup() {
  // Attach each servo to its respective pin

  pinMode(D0, INPUT_PULLDOWN);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  servo6.attach(servoPin6);



    

  
}

void loop() {
  // Initialize servos to starting positions
  servo1.write(90);
  servo2.write(0);
  servo3.write(90);
  servo4.write(90);  //90
  servo5.write(0);
  servo6.write(10);
  delay(20);

  if (digitalRead(D0) == HIGH){


    servo1.write(45);
    delay(1000); 
    servo2.write(170);
    delay(1000); 
    servo4.write(160);   // 160
    delay(1000); 
    servo5.write(0);
    delay(1000); 
    servo3.write(120);
    delay(1000); 
    servo6.write(100);
    delay(1000); 

}

}
