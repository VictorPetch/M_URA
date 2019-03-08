#include "Motor_DC.h" 

Motor_DC Motor1(5,4);//Primeiro é o pwm
Motor_DC Motor2(6,7);


void setup()
{
  //Define os pinos como saida
 Motor1.setup();
 Motor2.setup();
 Serial.begin(9600);
 delay(1200);
 
}
  
void loop()
{
  car_frente(Motor1, Motor2, 2000, 200);
  car_parar(Motor1, Motor2, 500);
  
  

 

}


void car_frente(Motor_DC motor1, Motor_DC motor2, int duration, int vel){
    motor1.frente(vel);
    motor2.frente(vel);
    delay(duration);
};

void car_tras(Motor_DC motor1, Motor_DC motor2, int duration, int vel){
    motor1.tras(vel);
    motor2.tras(vel);
    delay(duration);
};

void car_parar(Motor_DC motor1, Motor_DC motor2, int duration){
    motor1.parar();
    motor2.parar();
    delay(duration);
};

void rodar_hor(Motor_DC motor1, Motor_DC motor2,int duration,  int vel ){
  motor1.tras(vel);
  motor2.frente(vel);
  delay(duration);

};
void rodar_anthor(Motor_DC motor1, Motor_DC motor2,int duration, int vel ){
  motor1.frente(vel);
  motor2.tras(vel);

};
