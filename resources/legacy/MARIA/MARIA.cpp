#include "MARIA.h"

int noOfSteps;

MARIA::MARIA()
{
  //Motor control pins
  pinMode(constants::DIR1, OUTPUT);
  pinMode(constants::PUL1, OUTPUT);
  pinMode(constants::DIR2, OUTPUT);
  pinMode(constants::PUL2, OUTPUT);
  //--------------------
  //Sonar control pins
  pinMode(constants::TRIG1, OUTPUT);
  pinMode(constants::TRIG2, OUTPUT);
  pinMode(constants::TRIG3, OUTPUT);
  pinMode(constants::ECHO1, OUTPUT);
  pinMode(constants::ECHO2, OUTPUT);
  pinMode(constants::ECHO3, OUTPUT);
  //--------------------
  pinMode(constants::LED, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("Constructor has been initialised.");
}
//==================================================
float MARIA::getSonarDistance_cm(int sonar_ID)
{
  int trigPin, echoPin;
  float distance;

  //Get reading of sonar sensor with particular ID
  if(sonar_ID == 0)
  {
    trigPin = constants::TRIG1;
    echoPin = constants::ECHO1;
  }
  else if(sonar_ID == 1)
  {
    trigPin = constants::TRIG2;
    echoPin = constants::ECHO2;
  }
  else if(sonar_ID == 2)
  {
    trigPin = constants::TRIG3;
    echoPin = constants::ECHO3;
  }
  else
  {
    Serial.println("Error: ID not valid");
  }
  //Fetches the reading from the sonar sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //Sensors are triggerred by short pulse of 10+ microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH);

  //Convert the time between the trigger and echo into distance
  distance = (duration/2) / 29.1;

  return distance;
}
//=================================================================
int MARIA::distanceToSteps(int distance)
{
  //converts the distance covered in mm to number of steps 
  int noOfSteps = int(constants::stepsPerRev/(2 * 3.14 * constants::wheelRadius));

  return noOfSteps;
}
//=================================================================
int MARIA::angleToSteps(int angle)
{
  
}
//=================================================================
void MARIA::mariaStop()
{
  //code to make the robot come to a halt
  Serial.println("HALT");
}
//=================================================================
void MARIA::goForward(int distMm)
{
  //Code to make the robot go forward for some time
  digitalWrite(constants::DIR1, HIGH);
  digitalWrite(constants::DIR2, HIGH);
  
  for(int count = 0; count < distanceToSteps(distMm); count++)
  {
    digitalWrite(constants::PUL1, HIGH);
    digitalWrite(constants::PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(constants::PUL1, LOW);
    digitalWrite(constants::PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("FORWARD");
  mariaStop();
}
//=================================================================
void MARIA::goBack(int distMm)
{
  //code to make the robot go in reverse for some time
  digitalWrite(constants::DIR1, LOW);
  digitalWrite(constants::DIR2, LOW);

  for(int count = 0; count < distanceToSteps(distMm); count++)
  {
    digitalWrite(constants::PUL1, HIGH);
    digitalWrite(constants::PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(constants::PUL1, LOW);
    digitalWrite(constants::PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("REVERSE");
  mariaStop();
}
//================================================================
void MARIA::turnLeft(int angleDeg)
{
  //code to make the robot turn left by some angle
  digitalWrite(constants::DIR1, HIGH);
  digitalWrite(constants::DIR2, LOW);

  for(int count = 0; count < angleToSteps(angleDeg); count++)
  {
    digitalWrite(constants::PUL1, HIGH);
    digitalWrite(constants::PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(constants::PUL1, LOW);
    digitalWrite(constants::PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("LEFT");
  mariaStop();
}
//================================================================
void MARIA::turnRight(int angleDeg)
{
  //code to make the robot turn right by some angle
  //Code to make the robot go forward for some time
  digitalWrite(constants::DIR1, LOW);
  digitalWrite(constants::DIR2, HIGH);

  for(int count = 0; count < angleToSteps(angleDeg); count++)
  {
    digitalWrite(constants::PUL1, HIGH);
    digitalWrite(constants::PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(constants::PUL1, LOW);
    digitalWrite(constants::PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("FORWARD");
  mariaStop();
}
//================================================================
void MARIA::testcode()
{
  // put your main code here, to run repeatedly:
  Serial.println("TEST CODE RUNNING FOR TWO MOTORS:");
  turnRight(30);
  delay(1000);
  turnLeft(90);
  delay(1000);
  goBack(500);
  delay(1000);
  goForward(500);
  delay(1000);
}
//================================================================
