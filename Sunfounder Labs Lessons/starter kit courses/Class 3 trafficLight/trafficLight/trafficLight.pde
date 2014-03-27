int carRed = 12;                   
int carYellow = 10;                  
int carGreen = 8;                  
int pedRed = 7;                    
int pedGreen = 4;                  
int pedBtn = 2;                    
int val = 0;                        

void setup() {                      
  pinMode(pedRed, OUTPUT);         
  pinMode(pedGreen, OUTPUT);       
  pinMode(carRed, OUTPUT);         
  pinMode(carYellow, OUTPUT);        
  pinMode(carGreen, OUTPUT);       
  pinMode(pedBtn, INPUT);       
}

void loop(){                   
  digitalWrite (pedRed, HIGH);     
  digitalWrite (carGreen, HIGH);
  val = digitalRead(pedBtn);    

  if (val == HIGH) {                
    delay(2000);                    
    digitalWrite(carGreen, LOW);  
    digitalWrite(carYellow, HIGH);  
    delay(3000);                   
    digitalWrite(carYellow, LOW);   
    digitalWrite(carRed, HIGH);   
    delay(3000);                    
    digitalWrite(pedGreen, HIGH);  
    digitalWrite(pedRed, LOW);    
    delay(10000);           
    digitalWrite(pedGreen, LOW);  
    digitalWrite(pedRed, HIGH); 
    delay(3000);                 
    digitalWrite(carYellow, HIGH); 
    delay(3000);                    
    digitalWrite(carYellow, LOW); 
    digitalWrite(carRed, LOW);   
  }                     
}