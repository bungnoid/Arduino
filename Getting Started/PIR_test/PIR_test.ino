const int buzzer_pin = 7;
const int pir_pin = 2;
int state = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pir_pin,INPUT);
  Serial.println("Warming up...");
  delay(60000);
}

void loop(){
  state = digitalRead(pir_pin);
  Serial.println(state,DEC);
  delay(200);
}
