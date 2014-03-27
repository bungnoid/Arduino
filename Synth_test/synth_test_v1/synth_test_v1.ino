const int buttonPin = 2;
int note1 = 0;
int phase_inc = 1;
int phase_min = 100;
int phase_max = 5000;

int phase = 0;

int buttonState = 0;

double potVal = 0.0;

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  note1 = phase_min;
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState==HIGH){
    tone(8,note1);
  } else {
    noTone(8);
  }
  
  potVal = (1.0/1023) * analogRead(A0);
  //Serial.println(potVal);
  
  phase = (phase+phase_inc)%5000;
  //note1 = ((sin(phase*0.1)+1)*500)+200;
  note1 = ((sin(phase*0.1*potVal)+1)*500)+200;
  //Serial.println("note:");
  //Serial.println(note1);
  //Serial.println("phase:");
  //Serial.println(phase);
  delay(10);
  
}
