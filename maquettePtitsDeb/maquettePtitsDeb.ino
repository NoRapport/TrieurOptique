#include <Stepper.h>

const int stepsPerRevolution = 400;
// Define pin connections
const int dirPin = 8;
const int stepPin = 9;
// initialize the stepper library
Stepper myStepper(stepsPerRevolution, stepPin, dirPin);

// define entry
int buttonR = 2;
int buttonV = 3;
int buttonB = 4;

int sensorR = 5;
int sensorV = 6;
int sensorB = 7;

// parameters
int paramDelay = 10;
int paramSteps = 400;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(480);
  // initialize the serial port:
  Serial.begin(9600);
  // set entry
  pinMode(buttonR, INPUT);
  pinMode(buttonV, INPUT);
  pinMode(buttonB, INPUT);
  
  pinMode(sensorR, INPUT);
  pinMode(sensorV, INPUT);
  pinMode(sensorB, INPUT);
}

// loop checks the button pin each time and move
void loop() {
  if (digitalRead(buttonR) == HIGH) {
    if (digitalRead(sensorR) == HIGH) {
      Serial.print("#");
      delay(paramDelay);
    }
    else if (digitalRead(sensorV) == HIGH) { 
      Serial.print("Move V to R");
      myStepper.step(-paramSteps);
      delay(paramDelay);
    }
    else if (digitalRead(sensorB) == HIGH) { 
      Serial.print("Move B to R");
      myStepper.step(-paramSteps*2);
      delay(paramDelay);
    }
    else {
    Serial.print("#");
    delay(paramDelay);
    }
  }
  else if (digitalRead(buttonV) == HIGH) {
    if (digitalRead(sensorR) == HIGH) {
      Serial.print("Move R to V");
      myStepper.step(paramSteps);
      delay(paramDelay);
    }
    else if (digitalRead(sensorV) == HIGH) { 
      Serial.print("#");
      delay(paramDelay);
    }
    else if (digitalRead(sensorB) == HIGH) { 
      Serial.print("Move B to V");
      myStepper.step(-paramSteps);
      delay(paramDelay);
    }
    else {
    Serial.print("#");
    delay(paramDelay);
    }
  }
  else if (digitalRead(buttonB) == HIGH) {
    if (digitalRead(sensorR) == HIGH) {
      Serial.print("Move R to B");
      myStepper.step(paramSteps*2);
      delay(paramDelay);
    }
    else if (digitalRead(sensorV) == HIGH) { 
      Serial.print("Move V to B");
      myStepper.step(paramSteps);
      delay(paramDelay);
    }
    else if (digitalRead(sensorB) == HIGH) { 
      Serial.print("#");
      delay(paramDelay);
    }
    else {
    Serial.print("#");
    delay(paramDelay);
    }
  }
  else {
    Serial.print("#");
    delay(paramDelay);
  }

  delay(paramDelay);
}
