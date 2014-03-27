/*
  RGD LED
  
  Current Code

  
  Requirements :  1 x RGB LED
                  3 x 320 resisters
  
  0.05  ON / OFF constants
  0.04  Blinking green at the end
  0.03  DigitalWrite instead of AnalogWrite {abandoned}
  0.02  RGBOut function
  0.01  Light each colour once
*/

// Pins
const int iRed = 8;
const int iGreen = 9;
const int iBlue = 10;

// ON / OFF
const byte ON = 0;
const byte OFF = 255;

//////////////////////////////////////////////////////
//
// SETUP
//
void setup() {
  
  // Light up red first
  RGBOut(ON, OFF, OFF);
  delay(2000);
  
  // Light up green
  RGBOut(OFF, ON, OFF);
  delay(2000);
  
  // Light up blue
  RGBOut(OFF, OFF, ON);
  delay(2000);
  
  // All off
  RGBOut(OFF, OFF, OFF);
  delay(3000);
  
  // Colours
  RGBOut(ON, OFF, OFF);   // Red
  delay(1000);
  RGBOut(ON, ON, OFF);    // Yellow / Green
  delay(1000);
  RGBOut(OFF, ON, ON);    // Pale blue
  delay(1000);
  RGBOut(OFF, OFF, ON);   // Blue
  delay(1000);
  RGBOut(OFF, ON, OFF);   // Green
  delay(1000);
  RGBOut(ON, OFF, ON);    // Pink
  delay(1000);
  RGBOut(ON, ON, ON);     // White (all on)
  delay(1000);
  
  // All off
  RGBOut(OFF, OFF, OFF);
  delay(3000);

  // Blink Green 10 times
  for (int i = 0; i < 10; i++) {
    RGBOut(OFF, ON, OFF);   // Green on
    delay(200);             // 200 ms
    RGBOut(OFF, OFF, OFF);  // All off
    delay(200);             // 200 ms
  }
  
  // All off
  RGBOut(255, 255, 255);
}
  
//////////////////////////////////////////////////////
//
// LOOP
//
void loop() {
  // We'e only going to run through SETUP once
  
}

//////////////////////////////////////////////////////
//
// RGBOut
//
void RGBOut(byte bRed, byte bGreen, byte bBlue) {
  analogWrite(iRed, bRed);
  analogWrite(iGreen, bGreen);
  analogWrite(iBlue, bBlue);
}

