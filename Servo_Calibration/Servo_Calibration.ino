/*  0932 - Simple servo motor demo
 * 
 * This sketch shows you how to control two small 5V servo motors connected directly to the Arduino.
 * 
 * The sketch makes the arm of the servo motor to move in a 180 degree angle.
 * 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - One or two hobby servo motors
 *  - A small electrolitic capacitor
 *  
 *  Libraries
 *  ---------
 *  - Servo (comes with the Arduino IDE)
 *
 * Connections
 * -----------
 *  
 * For the motors:
 * Brown wire: Breadboard's "-" power rail.
 * Red wire: Breadboard's "+" power rail.
 * Yellow wire: One motor's to Arduino pin 9, and the other motor's to Arduino pin 10.
 * 
 * For the breadboard:
 * Connect the external power supply. The GND wire goes to the breadboard's "-" power rail. The 5V 
 * wire goes to breadboard's "+" power rail.
 * Connect a small electrolitic capacitor directly onto the power rail if you notice your servos
 * not working properly. Observe the polarity of the capacitor!
 * 
 *     
 *  More information
 *  ----------------
 *  For more information on the servo library, see https://www.arduino.cc/en/reference/servo
 *  
 *  Created on May 29 2017 by Peter Dalmaris
 * 
 */

#include <Servo.h> 
 
Servo myservo1, myservo2;  // create servo object to control a servo 
                           // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10);
} 
 
 
void loop() 
{ 
// If you are using a normal 180-degree servo, try the following. 
// The code below sweeps the servo from 0 degrees to 180 degrees
// If you notice that your servo is "trashing" when it reaches the ends of its travel
// path, increase the low end by a little (say, make it 10 degrees) and decrease the 
// top end by a little (say, make it 170 degrees).
//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo1.write(pos);              // tell servo 1 to go to position in variable 'pos'
////    myservo2.write(pos);              // tell servo 2 to go to position in variable 'pos'
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }
//for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo1.write(pos);              // tell servo 1 to go to position in variable 'pos'
////    myservo2.write(pos);              // tell servo 2 to go to position in variable 'pos'
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }

// Uncoment the following lines to test your servo's ability to hold a position.
// You can set the position of a servo , and hold it.
//  myservo1.write(0);  //Servo 1 go to position 85
//  myservo2.write(110); //Servo 2 go to position 85
//  delay(500);
//  myservo1.write(80); //Servo 1 go to position 20
//  myservo2.write(10); //Servo 2 go to position 10
//  delay(1000);
//  myservo1.write(180); //Servo 1 go to position 170
//  myservo2.write(160); //Servo 2 go to position 20
//  delay(500);
  myservo1.write(90);
  delay(1000);
} 
