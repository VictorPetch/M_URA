#ifndef ULTRASSOM_H
#define ULTRASSOM_H
 
#include <Arduino.h>

class Ultrassom
{
  public:
    Ultrassom(int TRIG, int ECHO);
    void setup();
    long tempo();
    long dist();
    long dist_5();

  private:
    int trigPin;
    int echoPin;
    long timeOut;
    long duration, distanceCm, distanceInc;
}; 
 
#endif
