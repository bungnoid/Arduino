const unsigned int LED_PIN = 13;
const unsigned int BAUD_RATE = 9600;

void setup(){
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop(){
  if(Serial.available() > 0){
    int cmd = Serial.read();
    if(cmd=='1'){
      digitalWrite(LED_PIN,HIGH);
      Serial.println("LED ON");
    } else if (cmd=='2'){
      digitalWrite(LED_PIN,LOW);
      Serial.println("LED OFF");
    } else {
      Serial.print("Unknown command: ");
      Serial.println(cmd);
      Serial.println(cmd,DEC);
      Serial.println(cmd,HEX);
      Serial.println(cmd,OCT);
      Serial.println(cmd,BIN);
      Serial.write(byte(cmd));
    }
  }
}
