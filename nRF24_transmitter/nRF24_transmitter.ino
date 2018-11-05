//#include <SPI.h>
//#include "RF24.h"
//
//#define BAUDRATE 9600
//
//const int led_pin = 8;
//char message = 'A';
//
//RF24 radio(9, 10);
//
//const uint64_t pipes[2] = {0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
//
//void setup() {
//  Serial.begin(BAUDRATE);
//
//  radio.begin();
//  radio.openWritingPipe(pipes[0]);
//  radio.openReadingPipe(1, pipes[1]);
//  radio.printDetails();
// 
//}
//
//void loop() {
//  radio.stopListening();
//  Serial.print("Sending:");
//  Serial.print(message);
//  Serial.print(" ");
//  radio.write(&message, 1);
//  radio.startListening();
//
//  unsigned long started_waiting_at = millis();
//  bool timeout =false;
//  while (!radio.available() && !timeout) 
//    if (millis() - started_waiting_at > 200)
//    timeout = true;
//  if ( timeout ) {
//    Serial.println("Failed, response timed out.");
//  } else {
//    byte response;
//    radio.read( &response, sizeof(response));
//    Serial.print("Transmitter. Received response from receiver:");
//    Serial.println(response, BIN);
//
//    if (response == B0) {
//      digitalWrite(led_pin, HIGH);
//      Serial.println("No connection");
//    }
//  }
//
//  // Try again later
//  delay(150);
//}

/*  1300a2 - nRF24 Transmitter
 *   
 * This sketch shows how to create a simple transmitter using the nRF24 module.
 * 
 * This sketch was written by Peter Dalmaris for Arduino Step by Step 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - nRF24L01+
 *  - 470 uF capacitor
 *  - Jumper wires
 *  
 *  Libraries
 *  ---------
 *  - SPI
 *  - RF24
 *
 * Connections
 * -----------
 * Arduino Uno and nRF24 (consult the schematic diagram as most
 * nRF24 modules don't include any pin markings):
 *  
 *  Arduino Uno   |      nRF24
 *  ------------------------------
 *        -       |       IRQ
 *        11      |       MOSI
 *        10      |       CSN
 *        5V      |       VCC
 *        GND     |       GND
 *        9       |       CE
 *        13      |       SCK
 *        12      |       MISO
 *        
 *  
 *  Connect the capacitor between the GND and 3.3V pins (beware of the polarity).
 *        
 *        
 *  Created on October 19 2017 by Peter Dalmaris, Tech Explorations, txplore.com
 * 
 */

#include <SPI.h>
#include "RF24.h"

#define BAUDRATE 9600

char message = 'A';

const int led_pin = 8;
const int TR_PIN = 0;

float voltage, degreesC;

RF24 radio(9,10);

// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

struct dataStruct {
  float voltage;
  float degreesC;
  int * counter;  
} myData;

void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(TR_PIN, INPUT);
  radio.begin();
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);  
  radio.printDetails();
  delay(200);
}

void loop()
{  
  
  voltage = (analogRead(TR_PIN) * 0.004882814);
  degreesC = (voltage - 0.5) * 100.0;
  
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Temperature C: ");
  Serial.println(degreesC);

  myData.voltage = voltage;
  Serial.print("myData.voltage: ");
  Serial.println(myData.voltage);
  
  myData.degreesC = degreesC;
  Serial.print("myData.degreesC: ");
  Serial.println(myData.degreesC);
  
    radio.stopListening();
    Serial.print("Sending:");
    Serial.print(message);
    Serial.print(" ");
    radio.write( &message, 1 );

//Serial.print("Humanity: ");
//Serial.println((float)myData.rf_humanity, DEC);
//myData.rf_humanity = 23.45;

//Serial.print("Temp Celsius: ");
//Serial.println((float)myData.rf_temp_cel, DEC);
//myData.rf_temp_cel = 4.33;

radio.write(&myData, sizeof(myData));
*myData.counter = *myData.counter++;

    // Now, continue listening
    radio.startListening();

    // Wait here until we get a response, or timeout (250ms)
    unsigned long started_waiting_at = millis();
    bool timeout = false;
    while ( ! radio.available() && ! timeout )
      if (millis() - started_waiting_at > 200 )
        timeout = true;

    // Describe the results
    if ( timeout )
    {
      Serial.println("Failed, response timed out.");
      digitalWrite(led_pin,LOW);
    }
    else
    {
      // Grab the response, compare, and send to debugging spew
      byte response;
      radio.read( &response, sizeof(response) );
      Serial.print("Transmitter. Received responsez from receiver:");
      Serial.println(response,BIN);
      
      if (response == 0) 
      {
        digitalWrite(led_pin,HIGH);
        Serial.println("Ok");
      }
      else
      {
        digitalWrite(led_pin,LOW);
        Serial.println("No connection");
      }
      Serial.print("response: ");
      Serial.println(response);
    }

    // Try again  later
    delay(150);
  
}
