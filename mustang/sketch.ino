#include <Stepper.h>

int stepsPerRevolution = 200;
const int botao = 12;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
const int swtich1 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(botao, INPUT);
  pinMode(swtich1, INPUT);
  myStepper.setSpeed(200);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(swtich1) == HIGH) {
    stepsPerRevolution = -200;
  } else {
    stepsPerRevolution = 200;
  }

  if (digitalRead(botao) == HIGH) {
    myStepper.step(stepsPerRevolution);
  } else {
    delay(500);
    myStepper.step(0);

  }
}
