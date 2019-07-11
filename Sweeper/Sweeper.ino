

#include "Sweeper.h"
#include "Servo.h"
#include <Array.h>

//Motor direito: 4,5
//Motor esquerdo: 6,7
//Miniservo: 9
//Ultrassom: 3(Trig),2(Echo)
Servo myservo;
Sweeper Mcqueen(3,2,9,4,5,6,7);
int distancias[4],angulos[4];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 Mcqueen.setup(myservo);
 myservo.write(90);
 delay(2000);
// myservo.write(160);
 //delay(500);
// myservo.write(20);
 //delay(500);
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 
 while(true){

  
  };
}

void loop() {
   //put your main code here, to run repeatedly:
  //Mcqueen.sweeping(myservo);
 //Mcqueen.movMotor("dir","frente");
 //Mcqueen.movSweeper("viraesquerda",10);
  //int array1[5] = {6,3,0,4,5};
  //int array2[5] = {45,0,10,22,3};
  //int x,y = Mcqueen.findSmallestElement(array1,array2,5);
  Mcqueen.sweeping(myservo, "pradireita",3,distancias,angulos);
  int menorDist, menorAng = Mcqueen.findSmallestElement(distancias,angulos,4);
  int clusterDist, flag = Mcqueen.clusterCalc(menorDist, menorAng);
  Mcqueen.LED_teste(flag);
  //Mcqueen.execution(flag);

for(int i=0; i<4;i++){
    Serial.print("Distancia: ");
     Serial.print(distancias[i]);
     Serial.print(" | Angulo: ");
     Serial.println(angulos[i]);
 
  }
     Serial.print("Flag: ");
     Serial.println(flag);

  Mcqueen.sweeping(myservo, "pradireita",3,distancias,angulos);
  menorDist, menorAng = Mcqueen.findSmallestElement(distancias,angulos,4);
  clusterDist, flag = Mcqueen.clusterCalc(menorDist, menorAng);
  Mcqueen.LED_teste(flag);
  //Mcqueen.execution(flag);
  
  for(int i=0; i<4;i++){
    Serial.print("Distancia: ");
     Serial.print(distancias[i]);
     Serial.print(" | Angulo: ");
     Serial.println(angulos[i]);
 
  }
     Serial.print("Flag: ");
     Serial.println(flag);

}
