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
} //end void setup

float a,b;
int state =1;
int x=0,y=0;
void loop() 
{ 

  // Main code to dictate the robot behaviour
 
  Robot.LCDclear();
  delay(10);
  int mspeed = 3500;             //This is the time in microseconds between steps

  while(state==1)
  // This state uses only the front sensor to see if obstacles are there
  {
    a = Robot.readsensor("FR");   // Variable that stores distance from FRont sensor
    if (a>5)                      //If clear of obstacle in the front
    {
      for(int j = 0; j<100;j++)   // Go forward for 100 steps
      Robot.forward(mspeed);
      Robot.LCDstring("Foward ");
      state=1;
    }
    else                          // when obstacle is too close
    {
      Robot.LCDclear();
      Robot.LCDstring("Left2");   // make a left to avoid front collision    
      for(int j = 0; j<185;j++)     
      Robot.left2(mspeed);

      for(int j = 0; j<100;j++)   // Go forward for 100 steps. Before changing the state
      Robot.forward(mspeed);
      
      x=x+1;                      // variable to ensure return to the initial position
      state=2;
    }
  }
  while(state==2)
  {
      
      
      a = Robot.readsensor("FR");   // sense front sensor
      b = Robot.readsensor("SI");   // sense side sensor

      if (a>5 && b<5)                 // if no obstacle in front and obstacle on right side
        {
          for(int j = 0; j<100;j++)   // Go forward for 100 steps. Cushion
          Robot.forward(mspeed);
          Robot.LCDstring("Foward ");

          a = Robot.readsensor("FR"); // check the front sensor again to see if behavior 3
          if (a>20 && b<5)
          {
            state = 3;                // if behavior 3, go to state 3
          }
          else
          {
          state =2;
          }
        }
       else if (a>5 && b>5)             // if robot is clear of obstacles from both front and side
        {
          for(int j = 0; j<100;j++)   
          Robot.forward(mspeed);       // Go forward for 100 steps. Cushion
          Robot.LCDstring("Foward ");

          Robot.LCDstring("Right2 ");
          for(int j = 0; j<170;j++)
          Robot.right2(mspeed);        // Turn right
          state = 3;
           
        }
      else if (a<5 && b<5)                // if obstacle in front and on side
        {
          Robot.LCDclear();
          Robot.LCDstring("Left2");     
          for(int j = 0; j<185;j++)     
          Robot.left2(mspeed);
          
          x=x+1;                      // increment x everytime we go away from initial line
          
          state =2;                      
        }
      else
      {
        state=1;
      }
  }

  while (state == 3)
    {
       for(int j = 0; j<100;j++)        //go forward for few steps 
       Robot.forward(mspeed);       
       Robot.LCDstring("Foward ");

       a = Robot.readsensor("FR");   // sense front sensor
       b = Robot.readsensor("SI");   // sense side sensor

       if ( a>20 && b>5)              // state 2 behavior
       {
        state = 2;
       }
       else if ( a>20 && b <5)
       {
          for(i=0;i=x;i--)            // to go back to initial position
          for(int j = 0; j<100;j++)        
          Robot.forward(mspeed);

          Robot.LCDclear();
          Robot.LCDstring("Left2");   //turn left to follow the first condition    
          for(int j = 0; j<185;j++)     
          Robot.left2(mspeed);

          state = 1;                  // go back to state 1
          
       }
       else
       {
        state = 2;
       }
       
    }
Serial.println();
delay(500);
Robot.LCDchar("This is the end ", 16);  //Writes the string, needs the length

delay(500);
int aa = 27;



Robot.LCDnum(aa); // This writes an integer (no length required

Robot.LCDstring("   ");
Robot.LCDstring("Maybe not");  // This writes a string no length required.
delay(500);
}
