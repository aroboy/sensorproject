/* Driver for Spreeta liquid sensor

   Version 0.01 6/13/2014
   Initial code draft
   
   INTRODUCTION
   
   This code will communicate with the Spreeta liquid sensor and will provide the functionality of reading data from the memory of the sensor.
   
   */

//Word Address contains 16 bits so it is divided into two bytes
#define upper 0x00        //The 8 most significant bits
#define lower 0x00        //The 8 least significant bits
#define NUMBEROFBYTES 16  //Specifies the number of bytes you want to read. Use for sequential read 

#include <Wire.h>


//Setup of serial connection
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
}

void loop()
{
  // First executing a write instruction to set address pointer
  Wire.beginTransmission(B1010111);  //Start sequence with device address
  Wire.write(lower); // low byte     //Sending the 8 least significant bits of the internal register address
  Wire.write(upper); // high byte    //Sending the 8 most significant bits of the internal register address
  Wire.endTransmission();            //Stop sequence
  
  // The read operation
  Wire.requestFrom(B1010111, NUMBEROFBYTES);  //Requesting the specified number of bytes
  while(Wire.available())                     //If no task is going on the bus, storing the bytes received into the variable x
  {
    byte x = Wire.read();                     
    Serial.print(x);                          //Print the variable x
  }
  
 delay(15);                                   //A 15 second delay to give time to the system
}
  
