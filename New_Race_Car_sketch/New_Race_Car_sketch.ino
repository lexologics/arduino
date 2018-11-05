/*

  Data Array positions sent to car:
  
  [0] Right Joystick (X) - U2 Sterring (A2 pin)
  [1] Left Joystick (Y) - U1 Motor drive (A1 pin)
  [2] A button - LED color 
  [3] B button - Manual mode 
  [4] C button - Auto mode   
  [5] D button - Buzzer  
  [6] Pot R1 - U1 Joystick fine adjustment (A4 pin)
  [7] Pot R6 - U2 Joystick fine adjustment (A5 pin)
  [8] Right Joystick (Y) - U2 Ultrasonic sensor servo position (A3 pin)
  [9] Left Joystick (X) - U1 ###### (A0 pin) - to be implemented

*/

#include <SPI.h>
#include "RF24.h"
RF24 radio(9, 10);                          // define the object to control NRF24L01
byte addresses[5] = "00007";                // define communication address which should correspond to remote control

int data[10];                               // define array used to save the communication data
int mode = 0;

const int pot6Pin = 5;                      // define R6
const int pot5Pin = 4;                      // define R1
const int led1Pin = 6;                      // define pin for LED1 which is close to NRF24L01 and used to indicate the state of NRF24L01
const int led2Pin = 7;                      // define pin for LED2 which is the mode is displayed in the car remote control mode  
const int led3Pin = 8;                      // define pin for LED3 which is the mode is displayed in the car auto mode
const int APin = 2;                         // define pin for D2
const int BPin = 3;                         // define pin for D3
const int CPin = 4;                         // define pin for D4
const int DPin = 5;                         // define pin for D5
const int MotorPin = 2;                     // define pin for direction Y of joystick U1
const int ServoPin = 1;                     // define pin for direction Y of joystick U2
const int ultrasonicPin = 3;                // define pin for direction X of joystick U2
const int leftStickXaxisPin = 0;            // define pin for direction X of joystick U1

void setup() {
  
  radio.begin();                            // initialize RF24 module
  radio.setRetries(0, 15);                  // sets retries times
  radio.setPALevel(RF24_PA_LOW);            // set the Power Amplifier level to LOW. Note: for a higher PA level, it is recommended to use a bypass capacitor across GND and 3.3V of the modules for a more stable voltage while operating.
  radio.openWritingPipe(addresses);         // open communication channel between modules
  radio.stopListening();                    // sets module as transmitter
  pinMode(led1Pin, OUTPUT);                 // sets led1Pin to output mode
  pinMode(led2Pin, OUTPUT);                 // sets led2Pin to output mode
  pinMode(led3Pin, OUTPUT);                 // sets led3Pin to output mode
  pinMode(APin, INPUT_PULLUP);              // sets APin to input mode
  pinMode(BPin, INPUT_PULLUP);              // sets BPin to input mode
  pinMode(CPin, INPUT_PULLUP);              // sets CPin to input mode
  pinMode(DPin, INPUT_PULLUP);              // sets DPin to input mode  
  data[3] = 0;
  data[4] = 1;
  
  //Serial.begin(9600);
}

void loop() {
  
  data[0] = analogRead(MotorPin);           // Stores U1 joystick position (motors)
  data[1] = analogRead(ServoPin);           // Stores U2 joystick position (steering servo)
  
  if(digitalRead(APin)==LOW){               // Checks state of A button (LED control) 
    delay(100);                           
    data[2] = digitalRead(APin);          
    }else{
      data[2] = HIGH;
      }
  
  if( digitalRead(BPin)==LOW){              // Checks state of B button (Manual Mode) 
    mode = 0;                               // Sets REMOTE Mode ON
    data[3] = 0;
    data[4] = 1;
  }
  
  if(digitalRead(CPin)==LOW){               // Checks state of C button (Auto Mode)
    mode = 1;                               // Sets AUTO Mode ON
    data[3] = 1;
    data[4] = 0;
  }
  
  data[5] = digitalRead(DPin);              // Stores D button state (Buzzer)
  data[6] = analogRead(pot5Pin);            // Stores Motor drive potentiometer
  data[7] = analogRead(pot6Pin);            // Stores Steering servo potentiometer
  data[8] = analogRead(ultrasonicPin);      // Stores USonic servo position
  data[9] = analogRead(leftStickXaxisPin);  // Stores left stick X axis
  
  if (radio.write( data, sizeof(data) ))    // sends data array to car
  digitalWrite(led1Pin,HIGH);               // turns on the signal LED  on remote control if transmission is successful
  delay(2);                                 // waits 2 ms
  digitalWrite(led1Pin,LOW);                // turns off the signal LED  on remote control for next data transmission

  if(mode==0){                              // checks if remote control mode is active
    digitalWrite(led2Pin,HIGH);             // turns on remote control LED on remote control
    digitalWrite(led3Pin,LOW);              // turns off autonomous driving LED on remote control
  }
  if(mode==1){                              // checks if autonomous driving mode is active
      digitalWrite(led2Pin,LOW);            // turns off remote control LED on remote control
      digitalWrite(led3Pin,HIGH);           // turns on autonomous driving LED on remote control
  }

}
