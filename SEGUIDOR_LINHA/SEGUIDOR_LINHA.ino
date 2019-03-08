#include "Motor_DC.h"


Motor_DC Motor1(5, 4); //Primeiro é o pwm
Motor_DC Motor2(6, 7);
int pinSensor1 = 9; //Esquerda
int pinSensor2 = 10; //Direita

bool val1, val2 = 1;
void setup() {
pinMode(pinSensor1,INPUT);
pinMode(pinSensor2,INPUT); 
  Motor1.setup();
  Motor2.setup();
  Serial.begin(9600); 

  //car_frente(Motor1, Motor2, 10,200);
  
}

void loop() {

  val1 =  digitalRead(pinSensor1);
  val2 = digitalRead(pinSensor2);
  if(val1 !=0 or val2 != 0){
    car_parar(Motor1, Motor2, 10);
    if( val1 == 1 && val2 == 1) {
      car_parar(Motor1, Motor2, 1000);
    }
    else if( val1 == 1){
      rodar_anthor(Motor1, Motor2, 20, 100 );
      car_parar(Motor1, Motor2, 1);
    }
    else if (val2 == 1){
      rodar_hor(Motor1, Motor2, 20, 100 );
      car_parar(Motor1, Motor2, 1);
    }
  }
  car_frente(Motor1, Motor2, 10,140);
  
  Serial.print("Esquerda: ");
  Serial.println(val1);
  Serial.print("Direita: ");
  Serial.println(val2);
  delay(500);
  



  
}



//////////////////////////////////////////////////////////////////////
//Funçoes do carro(frente,tras, etc)
//////////////////////////////////////////////////////////////////////

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
