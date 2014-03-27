// Controlling a servo position by voltage from 0 V to 5 V 
// and display it on al scale by pointer moved by servo. 

#include <Servo.h> 
 
Servo mypointerservo0;  // create servo object to control a servo 
 
int ANAin0 = 0;         // analog pin 0 used to measure a voltage over two cables
                        // the pin is protected over a diode and a resistor.
int ANAval0;            // variable to read the value from the analog pin 
 
void setup() 
{ 
  mypointerservo0.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  ANAval0 = analogRead(ANAin0);                // reads the value of the voltage up to 5 V (value between 0 and 1023) 
  ANAval0 = map(ANAval0, 0, 1023, 179, 0);     // scale it to use it with the servo (value between 0 and 180) and this reverse!
  mypointerservo0.write(ANAval0);              // sets the servo position according to the measured voltage 
  delay(15);                                   // waits for the servo to get there 
} 
