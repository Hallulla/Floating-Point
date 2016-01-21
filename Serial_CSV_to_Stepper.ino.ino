//Punto Flotante 2015
//CC Esteban Serrano
//Code for Arduino Mega

#include <AccelStepper.h>

//define step pins(pwm) for Big Easy Drivers
#define altAstp 13
#define azAstp 12
#define altBstp 11
#define azBstp 10
#define altCstp 9
#define azCstp 8

//dir pins
#define altAdir 32
#define azAdir 30
#define altBdir 28
#define azBdir 26
#define altCdir 24
#define azCdir 22

//vcc pins
#define vcc7 7
#define vcc6 6
#define vcc5 5
#define vcc4 4
#define vcc3 3
#define vcc2 2

//gnd pins
#define gnd34 34
#define gnd36 36
#define gnd38 38
#define gnd40 40
#define gnd42 42
#define gnd44 44

//define ENABLE pins
#define enA 49
#define enB 51
#define enC 53

//Define steppers
AccelStepper altA(1, altAstp, altAdir);
AccelStepper azA(1, azAstp, azAdir);
AccelStepper altB(1, altBstp, altBdir);
AccelStepper azB(1, azBstp, azBdir);
AccelStepper altC(1, altCstp, altCdir);
AccelStepper azC(1, azCstp, azCdir);

// a string to hold incoming data
String inputString = "";

// whether the string is complete
boolean stringComplete = false;

//Variables to store stepper movement values
int altAMove;
int azAMove;
int altBMove;
int azBMove;
int altCMove;
int azCMove;

int stepperSpeed = 1000;
int stepperAcc = 500;
int x;

void setup() {

  //set some pins HIGH to act as vcc for Big Easy Drivers
  pinMode(vcc7, OUTPUT);
  pinMode(vcc6, OUTPUT);
  pinMode(vcc7, OUTPUT);
  pinMode(vcc4, OUTPUT);
  pinMode(vcc3, OUTPUT);
  pinMode(vcc2, OUTPUT);
  digitalWrite(vcc7, HIGH);
  digitalWrite(vcc6, HIGH);
  digitalWrite(vcc5, HIGH);
  digitalWrite(vcc4, HIGH);
  digitalWrite(vcc3, HIGH);
  digitalWrite(vcc2, HIGH);

  //set some pins LOW to act as gnd for Big Easy Drivers
  pinMode(gnd34, OUTPUT);
  pinMode(gnd36, OUTPUT);
  pinMode(gnd38, OUTPUT);
  pinMode(gnd40, OUTPUT);
  pinMode(gnd42, OUTPUT);
  pinMode(gnd44, OUTPUT);
  digitalWrite(vcc7, LOW);
  digitalWrite(vcc6, LOW);
  digitalWrite(vcc5, LOW);
  digitalWrite(vcc4, LOW);
  digitalWrite(vcc3, LOW);
  digitalWrite(vcc2, LOW);

  //set ENABLE pins
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(enC, HIGH);

  //Stepper properties
  altA.setMaxSpeed(stepperSpeed);
  altA.setAcceleration(stepperAcc);

  azA.setMaxSpeed(stepperSpeed);
  azA.setAcceleration(stepperAcc);

  altB.setMaxSpeed(stepperSpeed);
  altB.setAcceleration(stepperAcc);

  azB.setMaxSpeed(stepperSpeed);
  azB.setAcceleration(stepperAcc);

  altC.setMaxSpeed(stepperSpeed);
  altC.setAcceleration(stepperAcc);

  azC.setMaxSpeed(stepperSpeed);
  azC.setAcceleration(stepperAcc);

  //open serial port
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  serialEvent();
  if (stringComplete) {
    int l_start_posn = 0;
    while (l_start_posn != -1) {
      altAMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      azAMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      altBMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      azBMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      altCMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      azCMove = (ENDF2(inputString, l_start_posn, ',').toInt());
      // poner un if para filtrar que los datos recibidos por el serial no sean una wea que mande los motores a la chucha
      altA.moveTo(altAMove);
      azA.moveTo(azAMove);
      altB.moveTo(altBMove);
      azB.moveTo(azBMove);
      altC.moveTo(altCMove);
      azC.moveTo(azCMove);
      String stringToPrint = String();
      stringToPrint = stringToPrint + "Move to: " + altAMove + "," + azAMove + "," + altBMove + "," + azBMove + "," + altCMove + "," + azCMove;
      Serial.println(stringToPrint);
    }
    inputString = "";
    stringComplete = false;
  }
  altA.run();
  azA.run();
  altB.run();
  azB.run();
  altC.run();
  azC.run();
}

/*
SerialEvent occurs whenever a new data comes in the
hardware serial RX.  This routine is run between each
time loop() runs, so using delay inside loop can delay
response.  Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

/*EXTRACT NEXT DELIMITED FIELD VERSION 2
Extract fields from a line one at a time based on a delimiter.
Because the line remains intact we dont fragment heap memory
p_start would normally start as 0
p_start increments as we move along the line
We return p_start = -1 with the last field*/

String ENDF2(String & p_line, int &p_start, char p_delimiter) {
  int l_start = p_start;
  int l_index = p_line.indexOf(p_delimiter, l_start);
  if (l_index == -1) { //last field of the data line
    p_start = l_index;
    return p_line.substring(l_start);
  }
  else { //take the next field off the data line
    p_start = l_index + 1;
    return p_line.substring(l_start, l_index); //Include, Exclude
  }
}

