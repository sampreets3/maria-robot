//Define Pulse and Direction pins for motor1
int DIR1 = 2;
int PUL1 = 3;
//Define Pulse and Direction pins for motor2
int DIR2 = 4;
int PUL2 = 5;

int noOfSteps = 6400;  //The number of steps the motors will move by

void setup() {
  // put your setup code here, to run once:
  pinMode(DIR1, OUTPUT);
  pinMode(PUL1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PUL2, OUTPUT);
  Serial.begin(9600);
}

int timeToSteps()
{
  //converts the time in seconds to number of steps
  noOfSteps = 6400;

  return noOfSteps;
}

void mariaStop()
{
  //code to make the robot come to a halt
  Serial.println("HALT");
}

void goForward()
{
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);

  for(int count = 0; count < noOfSteps; count++)
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

void goBack()
{
  //code to make the robot go in reverse for some time
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, LOW);
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
  Serial.println("REVERSE");
  mariaStop();
}

void turnLeft()
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

void turnRight()
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

void loop() {
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
