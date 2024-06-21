/*
  ONLY for the XIAO-SAMD21 board to be a salave for the other XIAO boards or between itself
  MOSI   PA08         A4      
  SCK    PA09         A5 
  SS     PA10         A2   //slave select
  MISO   PA11         A3

// The order is important
  SPISlave.SercomInit(SPISlave.MOSI_Pins::PA08, SPISlave.SCK_Pins::PA09, SPISlave.SS_Pins::PA10, SPISlave.MISO_Pins::PA11);

NOTE for reference the normal master SPI is

#define MOSI    PA07     D8;
#define SCK     PA05     D9;
#define SS      PB09     D7; // Slave select pin, can be any GPIO pin
#define MISO    PA06     D10;
 
  Copyright (C) 2022 lenvm

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  For the GNU General Public License see https://www.gnu.org/licenses/

  Contact Information
  -------------------
  lenvm
  GitHub   : https://github.com/lenvm
*/

/*
  Example code for the SercomSPISlave library.
  This code initializes a SERCOM0 SPI Slave and prints the data received.

  Written 2020 July 15
  by lenvm
  Modified 2020 December 30
  by stubb
  Updated 2021 June 8
  by lenvm
  Updated 2022 November 1
  by lenvm
*/

#include <SercomSPISlave.h>
Sercom0SPISlave SPISlave; // to use a different SERCOM, change this line and find and replace all SERCOM0 with the SERCOM of your choice

#define DEBUG // uncomment this line to print debug data to the serial bus
#define INTERRUPT2BUFFER // uncomment this line to copy the data received in the Data Received Complete interrupt to a buffer to be used in the main loop
#define INTERRUPT2SERIAL // uncomment this line to print the data to the serial bus whenever the Data Received Complete interrupt is triggered

// initialize variables
byte buf[1]; // initialize a buffer of 1 byte


//volatile uint8_t myDataToSend;
byte myDataToSend;
byte mySentToPrint;

byte myDataToReceive;
byte myReceiveToPrint;



void setup()
{
  Serial.begin(115200);
  Serial.println("Serial started");
  SPISlave.SercomInit(SPISlave.MOSI_Pins::PA08, SPISlave.SCK_Pins::PA09, SPISlave.SS_Pins::PA10, SPISlave.MISO_Pins::PA11);
  delay(3000);

  Serial.println("SERCOM0 SPI slave initialized");
}

void loop(){
    mySentToPrint = myDataToSend;
    myReceiveToPrint = myDataToReceive;
    Serial.print("Slave Received from Master: ");
    Serial.print(myReceiveToPrint, HEX); // Print received data
    Serial.print(", Slave sent to Master: ");
    Serial.println(mySentToPrint, HEX); // Print received data
    Serial.println(); // Print received data

    delay(2000);


}

void SERCOM0_Handler(){ 

  //uint8_t data = 0;
  myDataToReceive = 0;
  myDataToReceive = (uint8_t)SERCOM0->SPI.DATA.reg;
  uint8_t interrupts = SERCOM0->SPI.INTFLAG.reg; // Read SPI interrupt register
 
  // Slave Select Low interrupt
  if (interrupts & (1 << 3)){ // 1000 = bit 3 = SSL // page 503   

    SERCOM0->SPI.INTFLAG.bit.SSL = 1; // Clear Slave Select Low interrupt
  }
  
  // Data Received Complete interrupt: this is where the data is received, which is used in the main loop
  if (interrupts & (1 << 2)) { // 0100 = bit 2 = RXC // page 503
  
    myDataToReceive = SERCOM0->SPI.DATA.reg; // Read data register
    SERCOM0->SPI.INTFLAG.bit.RXC = 1; // Clear Receive Complete interrupt
  }
  
  // Data Transmit Complete interrupt
  if (interrupts & (1 << 1)) { // 0010 = bit 1 = TXC // page 503

    SERCOM0->SPI.INTFLAG.bit.TXC = 1; // Clear Transmit Complete interrupt
  }
  
  // Data Register Empty interrupt
  if (interrupts & (1 << 0)) // 0001 = bit 0 = DRE // page 503
  {

    myDataToSend = 6;
    SERCOM0->SPI.DATA.reg = myDataToSend;
  }


}
