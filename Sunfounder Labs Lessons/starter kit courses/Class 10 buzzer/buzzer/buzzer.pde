/*
  Buzzer Game 
  Making an old school buzzer game
*/
  int speakerPin = 2;  // set the speakerPin to 2 for buzzer
  int button = 9; //  press button pin 9...
  int ledDelay = 100; // time note is played

void setup() {                
  // Sett all the button and speakerPins:
   pinMode (button, INPUT);  // set the button to INPUT
   pinMode(speakerPin, OUTPUT);  // set the speakerpin to OUTPUT
}

// Code to play the note - need to look at this sometime
void playTone(int tone, int duration) {
  for (long i = 0; i < duration *1000L; i += tone *2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

//Main loop.
// If the button is pushed then play the buzzer
void loop () {
int state = digitalRead(button);
if (state == HIGH) { playTone(1915, ledDelay);}
}

