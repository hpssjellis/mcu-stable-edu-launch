#include <Servo.h>
//#include <ESP32Servo.h>   //esp32 only
#include "ESC.h"

/* This example shows how to use an ESC controller that can go
 * forward and backard
 */

ESC esc(ESC::MODE_FORWARD_BACKWARD);

void setup() 
{
  esc.attach(A0);
} 
 
void loop() 
{ 
    esc.setSpeed(0);
    esc.setDirection(ESC::FORWARD);
    esc.setSpeed(30);
    delay(1000);
    esc.setSpeed(0);
    esc.setDirection(ESC::BACKWARD);
    esc.setSpeed(30);
    delay(1000);
} 
