#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin
const int SERVO2 = 8;

int buzzerPin = 2;

Servo servo; // create servo object to control a servo
Servo servo2; // second servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button


int pin1 = 13;
int pin2 = 12;
int pin3 = 11;


void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

   //servo
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object4

  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  servo2.attach(SERVO2);

  servo.write(0);
  currentButtonState = digitalRead(BUTTON_PIN);

  //buzzer
  pinMode(buzzerPin, OUTPUT);

  //tone(buzzerPin, 1000, 2000);
}

void loop() {
  digitalWrite(pin1, HIGH);
  delay(1000);
    
  digitalWrite(pin2, HIGH); 
  delay(1000);

  digitalWrite(pin3, HIGH); 
  delay(1000);

  //servo
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(currentButtonState == LOW) {
  //  Serial.println("The button is pressed");

    // change angle of servo motor
    for(int i = 180; i>0; i--){
      servo.write(i);
      delay(15);
    }

    for(int i = 0; i<180; i++){
      servo2.write(i);
      delay(15);
    }


    delay(2000);  //delay 2 sec
    tone(buzzerPin, 10000,2000); 

  }
    
}
