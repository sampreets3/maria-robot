MARIA::MARIA()
{
  //Motor control pins
  pinMode(DIR1, OUTPUT);
  pinMode(PUL1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PUL2, OUTPUT);
  //--------------------
  //Sonar control pins
  pinMode(TRIG1, OUTPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO1, OUTPUT);
  pinMode(ECHO2, OUTPUT);
  //--------------------
  pinMode(LED, OUTPUT);
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
    trigPin = TRIG1;
    echoPin = ECHO1;
  }
  else if(sonar_ID == 1)
  {
    trigPin = TRIG2;
    echoPin = ECHO2;
  }
  else if(sonar_ID == 2)
  {
    trigPin = TRIG3;
    echoPin = ECHO3;
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
  wheelRadius = 60;
  stepsPerRev = 6400;
  
  noOfSteps = int(stepsPerRev/(2 * 3.14 * wheelRadius));

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
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  
  for(int count = 0; count < distanceToSteps(distMm); count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("FORWARD");
  mariaStop();
}
//=================================================================
void MARIA::goBack(int distMm)
{
  //code to make the robot go in reverse for some time
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, LOW);

  for(int count = 0; count < distanceToSteps(distMm); count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("REVERSE");
  mariaStop();
}
//================================================================
void MARIA::turnLeft()
{
  //code to make the robot turn left by some angle
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);

  for(int count = 0; count < noOfSteps; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("LEFT");
  mariaStop();
}
//================================================================
void MARIA::turnRight()
{
  //code to make the robot turn right by some angle
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);

  for(int count = 0; count < 6400; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
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
  turnRight();
  delay(1000);
  turnLeft();
  delay(1000);
  goBack();
  delay(1000);
  goForward();
  delay(1000);
}
//================================================================
