//----------------------------------------------------------------
//-- CC BY SA (http://ottodiy.com)
//-----------------------------------------------------------------
//-- Otto will run fast straight forward with this code!
//-----------------------------------------------------------------
#include <Arduino.h>

#include <Otto.h>

Otto otto;  //This is Otto!

//---------------------------------------------------------
//-- Make sure the pins for servos are in the right position
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
#define PIN_YL 7 //servo[0] -- left hip
#define PIN_YR 8 //servo[1] -- right hip
#define PIN_RL 9 //servo[2] -- left foot
#define PIN_RR 10 //servo[3] -- right foot

#define YL_TRIM 8
#define YR_TRIM -5
#define RL_TRIM -10
#define RR_TRIM 0

#define SERVO_POS_MIN 0
#define SERVO_POS_MAX 180

#define US_TRIGGER_PIN  A0
#define US_ECHO_PIN     A1

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
//-- Movement parameters
#define STEPS 2
#define T 1000 //Initial duration of movement. Lower value to run faster.
#define MOVEMENT_ID FORWARD

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup()
{
  //Set the servo pins
  bool load_calibration = false;
  otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, load_calibration, PIN_NoiseSensor, PIN_Buzzer, US_TRIGGER_PIN, US_ECHO_PIN);
  otto.setTrims(YL_TRIM, YR_TRIM, RL_TRIM, RR_TRIM);
  otto.setPositionLimits(SERVO_POS_MIN, SERVO_POS_MAX);
  // otto.sing(S_connection); //Otto wake up!
  otto.home();
  delay(5000);
  // otto.sing(S_happy); // a happy Otto :)
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop()
{
  otto.walk(STEPS, T, MOVEMENT_ID); // steps, T, dir
  delay(50);
}
