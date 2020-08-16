#include "MARIA.h"

MARIA robot;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.goForward(50);
  delay(500);
  robot.mariaStop();
  delay(500);
  robot.goBack(50);
  delay(500);
}
