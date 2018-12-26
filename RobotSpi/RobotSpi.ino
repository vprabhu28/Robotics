#include <SPI.h>
#include <robotlib.h>
robotlib Robot;

VL53L0X FRsensor;
VL53L0X FSsensor;
VL53L0X SIsensor;
VL53L0X BSsensor;

void setup() {


Robot.initial();  // This initiallizes the PIC microcontrollers and the Sensors
Serial.begin(9600); // sends data out on the USB

}

void loop() {

int mspeed = 2000; //This is the time in microseconds between steps

// Make the robot go straight
Robot.LCDclear();
Robot.LCDstring("Foward ");
for(int j = 0; j<255;j++)
Robot.forward(mspeed);

// Make the robot go backward
Robot.LCDclear();
Robot.LCDstring("Backward ");
for(int j = 0; j<255;j++)
Robot.backward(mspeed);

// Rotate robot on its axis to the left by moving right wheel forward and left wheel backward by same amount
Robot.LCDclear();
Robot.LCDstring("Left1 ");
for(int j = 0; j<255;j++)
Robot.left1(mspeed);

// Rotate robot on its axis to the right by moving left wheel forward and right wheel backward by same amount
Robot.LCDclear();
Robot.LCDstring("Right1 ");
for(int j = 0; j<255;j++)
Robot.right1(mspeed);

// Rotate robot to left using the right wheel forward and left wheel stationary
Robot.LCDclear();
Robot.LCDstring("Left2 ");
for(int j = 0; j<255;j++)
Robot.left2(mspeed);

// Rotate robot to right using the left wheel forward and right wheel stationary
Robot.LCDclear();
Robot.LCDstring("Right2 ");
for(int j = 0; j<255;j++)
Robot.right2(mspeed);


//This code is for the LCD Display
Robot.LCDclear();   //Clears the LCD display


Robot.LCDchar("This is the end ", 16);  //Writes the string, needs the length

delay(500);
int aa = 27;


Robot.LCDnum(aa); // This writes an integer (no length required

Robot.LCDstring("   ");
Robot.LCDstring("Maybe not");  // This writes a string no length required.
delay(500);

}
