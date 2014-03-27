/* use 2 buttons to controll a servo
 */
#include <Servo.h> 

Servo servo1;
const int bottone = 2;     //button 0-180
int stato = 0;            
const int bottone1 = 3;   //button 180-0  
int stato1 = 0; 
int valore=0;
int velocita=10;    //
void setup() {
  pinMode(bottone, INPUT); 
  Serial.begin(9600); 
  servo1.attach(11);
  servo1.write(0);
}

void loop(){

  stato = digitalRead(bottone);
  if (stato == HIGH) { 
    delay(velocita);
    if(valore < 180){
      valore=(valore++);  
      Serial.println(valore);
      servo1.write(valore);
    }
    else{
      Serial.println("stop");
      valore= 180;
    }
  } 
  stato1 = digitalRead(bottone1);
  if (stato1 == HIGH) { 
    delay(velocita);
    if(valore > 1){
      valore=(valore--);  
      Serial.println(valore);
      servo1.write(valore);
    }
    else{
      Serial.println("stop");
      valore=0;
    }
  } 
  //servo1.write(valore); 

}

