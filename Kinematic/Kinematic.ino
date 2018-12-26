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

void setup()           // Used to set-up the robot
{
    // put your setup code here, to run once:
    Robot.initial();
    delay(100);
  int mspeed = 2500;      //This is the time in microseconds between steps
}
void loop() {
  int mspeed = 2500;// put your main code here, to run repeatedly:
  while(true) // Starts a loop
  { 
  
        float a = Robot.readsensor("FS"); //Reads Front-side sensor
        float b = Robot.readsensor("BS"); //Reads Back sensor
        float c = Robot.readsensor("SI"); //Reads Side sensor
        float d = Robot.readsensor("FR"); //Reads Front sensor  
     
        if(d < 25)        //Check if any obstacle in front 
        {
            for(int i=0; i<50; i++)   //If any object in front, make the left slowly
            {
                Robot.left1(mspeed);  //Robot command to make the turn
            }
        }
          float prop = 0.3;       //Defines the propogation constant
          float diff = 0.1;       //Defines the differential constant

    //We have the equation that we simulated in the simulink model. 
    //We put in the equation into the robot and see if the behavior is same as simulink model   

          Robot.TURN(diff*(a - b) + (prop * (c - 20)), mspeed); // Initial distance from wall set to 20
          Robot.TURN(diff*(a - b) + (prop * (c - 20)), mspeed); 
  
  }
}
