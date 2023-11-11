//library 
#include <Servo.h>

#define ACTIVE_N_LEDS 10
#define SERVO_PIN 12
int leds[ACTIVE_N_LEDS] = {2,3,4,5,6,7,8,9,10,11};
char entry;
Servo garageServo;

void toggleLed(int nLed, boolean status){
  digitalWrite(leds[nLed], status);
}

void moveServo(int angle)
{
  garageServo.write(angle);
  delay(1000);
}


void setup() {
  // set ports as OUTPUT
  for (int i = 0 ; i < ACTIVE_N_LEDS; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  // Servo config
  garageServo.attach(SERVO_PIN);
  moveServo(0);
  // read from BT
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    entry = Serial.read();
  }

  switch(entry) {
    case 'a':
      toggleLed(0, HIGH); // pin 2 | OK
      break;
    case 'A':
      toggleLed(0, LOW);  
      break;
    case 'b':
      toggleLed(1, HIGH); // pin 3 | OK
      break;
    case 'B':
      toggleLed(1, LOW); // pin 3 | OK
      break;
    case 'c':
      toggleLed(2, HIGH); // pin 4 | OK
      break;
    case 'C':
      toggleLed(2, LOW);
      break;
    case 'd':
      toggleLed(3, HIGH); // pin 5 | OK
      break;
    case 'D':
      toggleLed(3, LOW);
      break;
    case 'e':
      toggleLed(4, HIGH); // pin 6
      break;
    case 'E':
      toggleLed(4, LOW);
      break;
    case 'f':
      toggleLed(5, HIGH); // pin 7 | OK
      break;
    case 'F':
      toggleLed(5, LOW);
      break;
    case 'g':
      toggleLed(6, HIGH); // pin 8 | OK
      break;
    case 'G':
      toggleLed(6, LOW);
      break;
    case 'h':
      toggleLed(7, HIGH); // pin 9 | OK
      break;
    case 'H':
      toggleLed(7, LOW);
      break;
    case 'i':
      toggleLed(8, HIGH); // pin 10
      break;
    case 'I':
      toggleLed(8, LOW);
      break;
    case 'j':
      toggleLed(9, HIGH); // pin 11
      break;
    case 'J':
      toggleLed(9, LOW);
      break;
    case 'k':
      moveServo(80);
      break;
    case 'K':
      moveServo(0);
      break;
  }
}
