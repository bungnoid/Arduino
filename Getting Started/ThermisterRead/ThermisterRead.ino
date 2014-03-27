#include <math.h>

int led_pin = 13;

void setup(void) {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
}

double Thermister(int RawADC) {
  double Temp;
  // See http://en.wikipedia.org/wiki/Thermistor for explanation of formula
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;           // Convert Kelvin to Celcius
  return Temp;
}

void printTemp(void) {
  double fTemp;
  double temp = Thermister(analogRead(0));  // Read sensor
  fTemp = (temp * 1.8) + 32.0;    // Convert to USA
  Serial.println("Temp C:");
  Serial.println(temp);
  Serial.println("Temp F:");
  Serial.println(fTemp);
  if (fTemp > 68 && fTemp < 78) {
    Serial.println("Very comfortable");
    digitalWrite(led_pin,HIGH);
  } else {
    digitalWrite(led_pin,LOW);
  }
  
}

void loop(void) {
  printTemp();
  delay(1000);
}


