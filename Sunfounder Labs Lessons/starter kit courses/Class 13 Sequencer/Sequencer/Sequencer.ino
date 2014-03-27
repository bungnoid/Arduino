/*
    Loop Sequencer
    
  Allows to loop a sequence of tones indefinately.
  
  Usage:
  1) When the sketch is started, first you have to choose the loop 
  length by turning the poti. The begin of the loop is indicated
  by a click of the buzzer.
  2) When you are satisfied with the loop length, you have to confirm 
  your choice by pressing the confirm button. The green LED should light.
  3) Now you are in recording mode. Pressing and holding the input button sets 
  start and duration of the tone. The red LED indicates the recording. Attention, 
  if the button is hold past the end of the loop, the tone is discarded. The poti 
  can be used to set the pitch.   If you are not satisfied with pitch or 
  timing, pressing and holding the button again overwrites.
  4) Once you are satisfied with the tone, you can confirm it with the confirm 
  button. The green LED should light. Now you are ready to record the next tone.
  5) Repeat this procedure up to ten times. Afterwards the first tones get overwritten.
  6) Happy sampling!
  
 
  
  This sketch is in the public domain
*/

#define BUTTON_CONFIRM 0
#define BUTTON_INPUT 1

static const int button_pins[2] = {13,12};
//Button Management, by comparing pressed and last key_down and key_up events can be detected
int button_pressed[2];
int button_last[2];

int buzzer_pin = 2;
int poti_pin = A0;

//Loop length choice = 0
//Recording = 1 
int state = 0;
//State of the piezo buzzer, HIGH or LOW
int click_state;

int loop_length = 3000;

//Begin of the current loop
long loop_begin = 0;
//milliseconds since the last loop begin
int loop_delta = 0;

//tones, up to ten tones
#define N_TONES 10
int tone_current = 0;//for recording
//number of milliseconds after start of the loop
int tone_start[N_TONES];//start of the tone
int tone_end[N_TONES];//end of the tone
int tone_click[N_TONES];//last click
//number of milliseconds between switching on and off, values between 1 and about 10
int tone_period[N_TONES];
//number of milliseconds  the last click

void setup(){
  pinMode(button_pins[BUTTON_CONFIRM],INPUT);
  pinMode(button_pins[BUTTON_INPUT], INPUT);
  pinMode(buzzer_pin, OUTPUT);
  digitalWrite(buzzer_pin,LOW);
  click_state = 0;
  loop_begin = millis();
  Serial.begin(9600);
  loop_length = 2000;
  int i;
  for(i=0;i<10;i++){
    tone_start[i] = 0;
    tone_end[i] = -1;
    tone_period[i] = 0;
    tone_click[i] = 0;
  }
}

//Output one click by switching from low to high or other way round
void click(){
  digitalWrite(buzzer_pin,click_state == 0 ? HIGH : LOW);
  click_state = (click_state + 1) % 2;
}

//check state of buttons and whether it changed since last time
void update_buttons(){
  int bid;
  for(bid=0;bid<2;bid++){
    button_last[bid] = button_pressed[bid];
    button_pressed[bid] = digitalRead(button_pins[bid]);
  }
}
  
void loop(){
  int i;
  loop_delta = millis() - loop_begin;
  update_buttons();
  switch(state){
    //Choose loop length
    case(0):
      loop_length = analogRead(poti_pin)*10 + 100;
      Serial.println(loop_length);
      if(loop_delta > loop_length){
        click();
        loop_begin = millis();
      }
      //Advance to next state if confirmed
      if(button_pressed[BUTTON_CONFIRM] == HIGH && button_last[BUTTON_CONFIRM] == LOW)
        state++;
      break;

    //Record tones
    case(1):
      if(button_pressed[BUTTON_INPUT] == HIGH && button_last[BUTTON_INPUT] == LOW){
        tone_start[tone_current] = loop_delta;
        tone_period[tone_current] = analogRead(poti_pin)/100;
        //preliminarily set tone until end of the loop
        tone_end[tone_current] = loop_length - loop_delta;
      }
      if(button_pressed[BUTTON_INPUT] == LOW && button_last[BUTTON_INPUT] == HIGH){
        tone_end[tone_current] = loop_delta;
      }
      if(button_pressed[BUTTON_CONFIRM] == HIGH && button_last[BUTTON_CONFIRM] == LOW)
        tone_current = (tone_current + 1) % N_TONES;

      //Play tones
      for(i=0;i<N_TONES;i++){
        if((loop_delta >= tone_start[i])
        && (loop_delta < tone_end[i])
        && (loop_delta - tone_click[i] >= tone_period[i])){
          click();
          tone_click[i] = loop_delta;
        }
      }

      //Reloop
      if(loop_delta >= loop_length){
        click();
        loop_begin = millis();
        for(i=0;i<N_TONES;i++){
          tone_click[i] = 0;
        }
      }    
  }
}




