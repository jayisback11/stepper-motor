#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
int buttonPressed = 4;
int val = 0;
bool rotate = false;

// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(30);
  pinMode(buttonPressed, INPUT);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  val = digitalRead(buttonPressed);

  if(val == 1){
    if(rotate == true){
      rotate = !rotate;
      // step one revolution in the clockwise direction:
      myStepper.step(stepsPerRevolution/2);
      delay(500);
    } else {
      rotate = !rotate;
      // step one revolution in the other direction:
      myStepper.step((-stepsPerRevolution/2)-20);
      delay(500);
    }
    
  }
  
}
