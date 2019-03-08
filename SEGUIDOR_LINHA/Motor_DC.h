#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>
class Motor_DC
{
  private:
    int IN1, IN2;
    
  public:
    Motor_DC(int pwmPin, int inPIn);
    void setup();
    void frente(int vel = 255);
    void tras(int vel = 255);
    void parar();
    
    
  
  
  
  
  
};


#endif
