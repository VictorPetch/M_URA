#include "ULTRASSOM.h"
#include "Servo.h"
int pos = 20;
// Pin do trig e echo 
Ultrassom us(11,12); 
Servo myservo;
void setup() {
  int Reading[10] = {};
  Serial.begin(9600); 
  us.setup(); 
  //myservo.attach(4);
}

void loop() {
   
 
      //myservo.write(pos); Tell servo to go to position pos
      Serial.println(us.dist()); //returns distance 
      delay(200);                        
      
}
  

/*     
        delay(200);
    myservo.write(pos);
    delay(200);
    Serial.print("Angle: ");
    Serial.println(pos);
    Serial.println(us.dist())
    Serial.println(us.dist());
    Serial.println(us.dist());

    Serial.println("Ja era");
    delay(2000);
*/
    


 //70 = 90graus
  
  //
