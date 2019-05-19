//----------------------------------------------------------------
//-- CC BY SA (http://ottodiy.com)
//-----------------------------------------------------------------
//-- Otto will run fast straight forward with this code!
//-----------------------------------------------------------------
#include <Arduino.h>

#include <Otto.h>

Otto otto;  //This is Otto!

//---------------------------------------------------------
//-- First step: Make sure the pins for servos are in the right position
/*
         --------------- 
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         --------------- 
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
#define PIN_YL 2 //servo[2]
#define PIN_YR 3 //servo[3]
#define PIN_RL 4 //servo[4]
#define PIN_RR 5 //servo[5]

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
//---------------------------------------------------------
bool obstacleDetected = false;

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup()
{
  //Set the servo pins
  otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  otto.sing(S_connection); //Otto wake up!
  otto.home();
  delay(50);
  otto.sing(S_happy); // a happy Otto :)
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  otto.walk(2,500,1); //change T for lower value to run faster!
  delay(50);
}
         
///////////////////////////////////////////////////////////////////
//-- Function to read distance sensor & to actualize obstacleDetected variable
void obstacleDetector()
{
  int distance = otto.getDistance();
  obstacleDetected = (distance < 15);
}
