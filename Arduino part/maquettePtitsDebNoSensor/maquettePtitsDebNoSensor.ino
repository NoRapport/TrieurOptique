#include <Stepper.h>

const int stepsPerRevolution = 200;
// Define pin connections
const int dirPin = 8;
const int stepPin = 9;
// initialize the stepper library
Stepper myStepper(stepsPerRevolution, stepPin, dirPin);

// define entry
int buttonR = 2;
int buttonV = 3;
int buttonB = 4;

int redPos = 1;
int greenPos = 0;
int bluePos = 0;


// parameters
int paramDelay = 100;
int paramSteps = 500;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(350);
  // initialize the serial port:
  Serial.begin(9600);
  // set entry
  pinMode(buttonR, INPUT);
  pinMode(buttonV, INPUT);
  pinMode(buttonB, INPUT);
}

// loop checks the button pin each time and move
void loop() {
  if (digitalRead(buttonR) == HIGH) {
    if (redPos == 1) {
      Serial.print("#");
      delay(paramDelay);
    }
    else if (greenPos == 1) { 
      Serial.print("Move V to R");
      myStepper.step(-paramSteps);
      delay(paramDelay);
      redPos = 1;
      greenPos = 0;
      bluePos = 0;
    }
    else if (bluePos == 1) { 
      Serial.print("Move B to R");
      myStepper.step(-paramSteps*2);
      delay(paramDelay);
      redPos = 1;
      greenPos = 0;
      bluePos = 0;
    }
    else {
    Serial.print("#");
    delay(paramDelay);
    }
  }
  else if (digitalRead(buttonV) == HIGH) {
    if (redPos == 1) {
      Serial.print("Move R to V");
      myStepper.step(paramSteps);
      delay(paramDelay);
      redPos = 0;
      greenPos = 1;
      bluePos = 0;
    }
    else if (greenPos == 1) { 
      Serial.print("#");
      delay(paramDelay);
    }
    else if (bluePos == 1) { 
      Serial.print("Move B to V");
      myStepper.step(-paramSteps);
      delay(paramDelay);
      redPos = 0;
      greenPos = 1;
      bluePos = 0;
    }
    else {
    Serial.print("#");
    delay(paramDelay);
    }
  }
  else if (digitalRead(buttonB) == HIGH) {
    if (redPos == 1) {
      Serial.print("Move R to B");
      myStepper.step(paramSteps*2);
      delay(paramDelay);
      redPos = 0;
      greenPos = 0;
      bluePos = 1;
    }
    else if (greenPos == 1) { 
      Serial.print("Move V to B");
      myStepper.step(paramSteps);
      delay(paramDelay);
      redPos = 0;
      greenPos = 0;
      bluePos = 1;
    }
    else if (bluePos == 1) { 
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
