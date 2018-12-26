/*This code is to test the use of the LIDAR sensors, the VL53L0X

I2C communicates with each of the units*/

#include <string.h>
#include <SPI.h>
#include <robotlib.h>
robotlib Robot;
#include <Wire.h>

// VL53L0X needed stuff
#include <VL53L0X.h>
VL53L0X FRsensor;
VL53L0X FSsensor;
VL53L0X SIsensor;
VL53L0X BSsensor;

void setup() {
  // put your setup code here, to run once:
  Robot.initial();
  delay(100);
}
float a;
void loop() {
  // put your main code here, to run repeatedly:
  //Read and print the VL53L0x to the LCD and the Serial Monitor
  
  Robot.LCDclear();
  delay(10);
  
  a = Robot.readsensor("FR"); // FRont sensor
  Serial.print(a);
  Serial.print("   ");
  Robot.LCDnum(a);
  Robot.LCDstring(",  ");
  
  a = Robot.readsensor("FS"); // FrontSide sensor
  Serial.print(a);
  Serial.print("   ");
  Robot.LCDnum(a);
  Robot.LCDstring(",  ");
  
  a = Robot.readsensor("SI"); // SIde sensor
  Serial.print(a);
  Serial.print("   ");
  Robot.LCDnum(a);
  Robot.LCDstring(",  ");
  
  a = Robot.readsensor("BS"); //BackSide sensor
  Serial.print(a);
  Serial.print("   ");
  Serial.println();
  Robot.LCDnum(a);
  Robot.LCDstring(",  ");
  
  Serial.println();
  delay(500);
  
}
