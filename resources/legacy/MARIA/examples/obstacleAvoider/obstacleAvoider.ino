/*-----------------------------------------------------------------
 * EXAMPLE SKETCH: 02
 * 
 * This is an Example Sketch to show the basic functionalities
 * of the MARIA library. The task at hand is to devise an 
 * obstacle avoiding algorithm, which will make use of the three
 * HC-SR04 sensors on MARIA. 
 * 
 * Maintained by Sampreet Sarkar.
 * 
 * Date: 18th January, 2019.
 *------------------------------------------------------------------*/
#define SAFE_DIST 20
#include "MARIA.h"

MARIA robot;  //Create an instance of the class MARIA

//We create the three variables to store the reading
//of the three distance sensors.
float leftSensor;
float rightSensor;
float centerSensor;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  leftSensor = getSonarDistance_cm(0);
  middleSensor = getSonarDistane_cm(1);
  rightSensor = getSonarDistance_cm(2);

  //Now, our logic dictates, if the 
  if(middleSensor <= SAFE_DIST)
  {
    if((rightSensor <= SAFE_DIST) && (leftSensor <= SAFE_DIST))
    {
      robot.mariaStop();
      delay(100);
      robot.goBack(100);
    }
    else if(rightSensor > SAFE_DIST)
    {
      robot.turnRight(30);
      delay(100);
      robot.goForward(100);
    }
    else if(leftSensor > SAFE_DIST)
    {
      robot.turnLeft(30);
      delay(100);
      robot.goForward(100);
    }
    else
    {
      robot.mariaStop();
    }
  }
  else
  {
    robot.goForward(300);
  }
}
