/*
  MARIA.h - Library for running the MARIA Robotics Project.
  Created by Sampreet Sarkar, Jsnuary 17, 2019.
  Soon to be released into the public domain.
*/
#ifndef MARIA_h
#define MARIA_h

#include "Arduino.h"

namespace constants
{
  const int wheelRadius = 60;
  const int stepsPerRev = 6400;
  //Define Pulse and Direction pins for motor1
  const int DIR1 = 2;
  const int PUL1 = 3;
  //Define Pulse and Direction pins for motor2
  const int DIR2 = 4;
  const int PUL2 = 5;
  //Define SONAR Sensor pins:
  const int TRIG1 = 12;
  const int ECHO1 = 11;
  const int TRIG2 = 8;  //Set this when working with second sensor
  const int ECHO2 = 9;  //Set this when working with second sensor
  const int TRIG3 = 7;  //Set this when working with third sensor
  const int ECHO3 = 6;  //Set this when working with third sensor
  //Define onboard LED
  const int LED = 13;
}

class MARIA
{

  public:
    MARIA();
    void testcode();
    void turnRight(int angleDeg);
    void turnLeft(int angleDeg);
    void goBack(int distMm);
    void goForward(int distMm);
    void mariaStop();
    int distanceToSteps(int distance);
    int angleToSteps(int angle);
    float getSonarDistance_cm(int sonar_ID);

    private:
    
};

#endif
