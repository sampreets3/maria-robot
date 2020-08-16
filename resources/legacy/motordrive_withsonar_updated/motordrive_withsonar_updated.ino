//Define Pulse and Direction pins for motor1
#define DIR1 2
#define PUL1 3
//Define Pulse and Direction pins for motor2
#define DIR2 4
#define PUL2 5
//Define SONAR Sensor pins:
#define TRIG1 12
#define ECHO1 11
#define TRIG2 0  //Set this when working with second sensor
#define ECHO2 0  //Set this when working with second sensor

//Define onboard LED
#define LED 13

int noOfSteps;  //The number of steps the motors will move by
float dist1;    //Collects distance reading from Sonar sensor 1

void setup() {
  // put your setup code here, to run once:
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
}

/*struct MOTOR: Used to create a MOTOR Type data, where we hold
 * the DIR, PUL, ENA pins, and also an ID for the motor for easy 
 * reference.
 * We then create an array of structure MOTOR called motor, where
 * we store only two entries(left and right). This is done to 
 * maintain consistency, and allowing possible room for upgrade 
 * in the future
 */
struct MOTOR{
  int DIR;  //Direction pin of the controller
  int PUL;  //Pulse pin of the controller
  int ENA;  //Enable pin of the controller(optional)
  int ID;   //Motor ID
} motor[2];

/*void initMotor: Defines a stepper motor controller
 * with appropriate pins to control the direction,
 * pulse, and setting the ID of the motor. Enable option
 * is not available yet. NOTE: ID SHALL START FROM '0'.
 */
void initMotor(int dirPin, int pulPin, int ID)
{
  motor[ID].DIR = dirPin;
  motor[ID].PUL = pulPin;
  motor[ID].ID = ID;
}
/* struct SONAR: Creates a SONAR type variable where we
 * can store the info of the TRIG pin, the ECHO pin, and
 * the ID of the sonar sensor. Will see, if ID can be
 * auto generated. We create a SONAR type array also, so
 * that we have an array of the structure SONAR.
 */
struct SONAR{
  int TRIG;
  int ECHO;
  int ID;
}sonar[2];

/*void initSonar: Initialises a Sonar sensor by taking as input 
 * the Trigger pin, the Echo pin, and the ID of the sensor.
 * NOTE: ID SHALL START FROM '0'
 */
 void initSonar(int trigPin, int echoPin, int ID)
 {
  sonar[ID].TRIG = trigPin;
  sonar[ID].ECHO = echoPin;
  sonar[ID].ID = ID;
 }
 
float getSonarDistance_cm(int sonar_ID)
{
  //The local variables trigPin and echoPin substitute for the TRIGx and 
  //ECHOx pins of the sensor with ID (x-1). Maybe in later revisions we 
  //could change this scheme for the data structure approach.
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
  else
  {
    Serial.println("Error: ID not valid");
  }
  //Fetches the reading from the sonar sensor
  //This short pulse of 5 microseconds is to cleanse the trigger
  //line so we get a better reading
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

int distanceToSteps()
{
  //converts the travel distance(in mm) to number of steps
  noOfSteps = 6400;

  return noOfSteps;
}

int angleToSteps(float angle)
{
  //Converts the angle of turn(in degrees) into number of steps
  /*Current Settings of the stepper motors(Edit code if settings changed):
   * Steps per revolution: 6400
   */
   noOfSteps = ceil((6400/360)*angle);
   
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

void testcode()
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
void loop() {

  delay(100);
  dist1 = getSonarDistance_cm(0);
  Serial.println(dist1);
  if(dist1 < 20.0)
  {
    mariaStop();
    digitalWrite(LED, HIGH);
  }
  else
  {
    testcode();
  }
}
