#include "ULTRASSOM.h"

Ultrassom::Ultrassom(int t, int e) {
  trigPin = t;
  echoPin = e;
  timeOut = 6000; // 3000 s = 50cm // 30000 s = 5 m
}

long Ultrassom::tempo() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, timeOut);
  if ( duration == 0 ) {
    duration = timeOut;
  }
  return duration;
}

long Ultrassom::dist() {
  tempo();
  distanceCm = duration / 29 / 2 ;
  return distanceCm;

}
long Ultrassom::dist_5() {
  long Distancias[5];
  long Media = 0;
  long Variancia = 0;
  for (int i = 0; i < 5; i++) {
    Distancias[i] = dist();
    Media += Distancias[i];
    Serial.print("Distancias: ");
    Serial.println(Distancias[i]);


  }
  Media /= 5;
  Serial.print("Media: ");
  Serial.println(Media);

  for (int i = 0; i < 5; i++) {
    Variancia += abs(Distancias[i] - Media);
  }
  Variancia /= 4;
  Serial.print("Variancia: ");
  Serial.println(Variancia);

  if (Variancia < 5) {
    return Media;
  }
  else {
    Media *=5;
    int j = 5;
    for (int i = 0; i < 5; i++) {
      if (abs(Distancias[i] - Media/5) > Variancia) {
        Media -= Distancias[i];
        j--;
      }
    }
    Serial.print("Nova Media: ");
    Serial.println(Media/j);
    return Media/j;

  }


}
void Ultrassom::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}
