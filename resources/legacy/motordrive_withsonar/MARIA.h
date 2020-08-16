/*
  MARIA.h - Library for running the MARIA Robotics Project.
  Created by Sampreet Sarkar, Jsnuary 17, 2019.
  Released into the public domain.
*/
#ifndef MARIA_h
#define MARIA_h

#include "Arduino.h"

class MARIA
{
  public:
    MARIA();
    void testcode();
    void turnRight();
    void turnLeft();
    void goBack(int distMm);
    void goForward(int distMm);
    void mariaStop();
    int distanceToSteps(int distance);
    int angleToSteps(int angle);
    float getSonarDistance_cm(int sonar_ID);

    int DIR1 = 2;
    int PUL1 = 3;
    //Define Pulse and Direction pins for motor2
    int DIR2 = 4;
    int PUL2 = 5;
    //Define SONAR Sensor pins:
    int TRIG1 = 12;
    int ECHO1 = 11;
    int TRIG2 = 0;  //Set this when working with second sensor
    int ECHO2 = 0;  //Set this when working with second sensor
    int TRIG3 = 0;  //Set this when working with third sensor
    int ECHO3 = 0;  //Set this when working with third sensor
    //Define onboard LED
    int LED = 13;

   private:
    
};

#endif
