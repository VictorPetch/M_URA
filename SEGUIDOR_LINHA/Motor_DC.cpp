#include "Motor_DC.h"

Motor_DC::Motor_DC(int pwm, int in) {
  IN1 = pwm;
  IN2 = in;
}

void Motor_DC::setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void Motor_DC::frente(int vel = 255) {
  analogWrite(IN1, vel);
  digitalWrite(IN2, LOW);
  
}
void Motor_DC::tras(int vel = 255) {
  analogWrite(IN1, LOW);
  digitalWrite(IN2, vel);
  
}
void Motor_DC::parar(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  
}
