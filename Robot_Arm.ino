#include <Servo.h>

int pMeter1 = A1;
int pMeter2 = A2;
int pMeter3 = A3;

Servo baseServo;
Servo armServo;
Servo brushServo;

int basePin = 5;
int armPin = 3;
int brushPin = 6;

void setup() {
  
  Serial.begin(9600);
  
  baseServo.attach(basePin);
  armServo.attach(armPin);
  brushServo.attach(brushPin);
  
}

void loop() {
  
  controlServo();
  
  /*
  int pMeterState = analogRead(pMeter3);
  Serial.print("P State: ");
  Serial.println(pMeterState);

  int mapped = map(pMeterState, 0, 1023, 25, 130);
  armServo.write(mapped);
  */

  //baseServo.write(95);
}

void controlServo(){

  //1: BASE: 50-170; 95 Middle
  //2: 
  //3:
  //4: 
  
  int pMeterState1 = analogRead(pMeter1);
  Serial.print("P State 1: ");
  Serial.println(pMeterState1);
  
  int pMeterState2 = analogRead(pMeter2);
  Serial.print("P State 2: ");
  Serial.println(pMeterState2);

  int pMeterState3 = analogRead(pMeter3);
  Serial.print("P State 3: ");
  Serial.println(pMeterState3);

  int mapped1 = map(pMeterState1, 0, 1000, 50, 160);
  baseServo.write(mapped1);

  int mapped2 = map(pMeterState2, 0, 1000, 30, 170);
  armServo.write(mapped2);

  int mapped3 = map(pMeterState3, 0, 1023, 30, 170);
  brushServo.write(mapped3);

}


