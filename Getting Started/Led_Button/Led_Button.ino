const unsigned int BUTTON_PIN = 7;
const unsigned int LED_PIN = 13;

void setup(){
  pinMode(BUTTON_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

int led_state = LOW;
int old_button_state = LOW;

void loop(){
  const int CURRENT_BUTTON_STATE = digitalRead(BUTTON_PIN);
  if ((CURRENT_BUTTON_STATE != old_button_state) && (CURRENT_BUTTON_STATE == HIGH)){
    led_state = (led_state == LOW) ? HIGH:LOW;
    digitalWrite(LED_PIN,led_state);
    delay(100);
  }
  
  old_button_state = CURRENT_BUTTON_STATE;
  
}
