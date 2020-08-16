//Define Pulse and Direction pins for motor1
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

//Define onboard LED
int LED = 13;

int noOfSteps = 6400;  //The number of steps the motors will move by
float dist1;  //Collects distance reading from Sonar sensor 1

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
