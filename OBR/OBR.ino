#include "Motor_DC.h"
#include "ULTRASSOM.h"

Motor_DC Motor1(5, 4); //Primeiro é o pwm
Motor_DC Motor2(6, 7);
Motor_DC MotorTeste1();
Motor_DC MotorTeste2();


Ultrassom us_front(11, 12); //Trig(pwm) e Echo
Ultrassom us_side(3, 2);

// Observações dos motores:
//Motor1(direita) roda pra frente depois dos 100
//e roda pra tras com força total para >=1;
//Motor2(esquerda) roda pra frente depois do 70
//e roda pra tras com força total para >=1

int Dist_front[10];
int Dist_side[5];
int evadeStage = 0;
int sum;
void setup() {
  //Define os pinos como saida

  
  Motor1.setup();
  Motor2.setup();
  us_front.setup();
  us_side.setup();
  Serial.begin(9600);
  delay(2000);

  car_frente(Motor1, Motor2, 3000,200);


}

void loop() {
  car_frente(Motor1, Motor2, 10, 200);

  //Evento de virar a esquerda
  if (evadeStage > 0) {


    if (us_side.dist() > 30) {

      rodar_anthor(Motor1, Motor2, 350, 140);
      car_frente(Motor1, Motor2, 1000, 200);

      //Correção da distancia
      do {
        rodar_anthor(Motor1, Motor2, 70, 140);
        car_parar(Motor1, Motor2, 100);
      } while (us_side.dist() < 10);

    }


  }
  //Evento de virar a direita
  else {
    for (int i = 0; i < 10; i++) {
      Dist_front[i] = us_front.dist_5();

      if (Dist_front[i] < 10 && evadeStage == 0) {
        car_parar(Motor1, Motor2, 50);

        do {
          rodar_hor(Motor1, Motor2, 70, 140);
          car_parar(Motor1, Motor2, 100);
        } while (us_side.dist_5() > 7
        );

        evadeStage = 1;
        break;
      }
      delay(200);
    }
  }



}
void car_frente(Motor_DC motor1, Motor_DC motor2, int duration, int vel) {
  motor1.frente(vel);
  motor2.frente(vel);
  delay(duration);
};

void car_tras(Motor_DC motor1, Motor_DC motor2, int duration, int vel) {
  motor1.tras(vel);
  motor2.tras(vel);
  delay(duration);
};

void car_parar(Motor_DC motor1, Motor_DC motor2, int duration) {
  motor1.parar();
  motor2.parar();
  delay(duration);
};

void rodar_hor(Motor_DC motor1, Motor_DC motor2, int duration,  int vel ) {
  motor1.tras(vel);
  motor2.parar();
  delay(duration);

};
void rodar_anthor(Motor_DC motor1, Motor_DC motor2, int duration, int vel ) {
  motor1.parar();
  motor2.tras(vel);
  delay(duration);

};
