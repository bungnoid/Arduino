
/* turns on and off a light emitting diode(LED) depending on ambient light (using a photocell).
 */

int photocellPin = 2;    // select the input pin for the photocell
int ledPin = 2;   // select the pin for the LED 
int val = 0;       // variable to store the value coming from the sensor 


void setup() { 
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT  
} 

void loop() { 
  val = analogRead(photocellPin);    // read the value from the sensor  
  if(val<=512){
    analogWrite(ledPin, HIGH); 
  }
  else{
    analogWrite(ledPin, LOW);
  }
} 
