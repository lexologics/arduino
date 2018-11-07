///*TMP37.pde  
//* Arduino Sketch to read a TMP37 Temperature Sensor
//* Paul Badger
//* 2010
//* Sensor works between 5 degrees & 100 degrees C
//* 20 mV / degree C
//* Can be used with TMP35 & TMP36 by changing voltsPerDegree
//*/
//
//float voltsPerDegree = 0.02; // change to 0.01 for TMP35 & 36
//#define sensorPin A0
//
//void setup() {
//    delay(200);
//    Serial.begin(9600);
//    delay(200);
//}
//
//void loop() {
//    int sensorValue;
//    float volts;
//    float celsius;
//    float farenheit;
//
//    sensorValue = analogRead(sensorPin);
//    volts = sensorValue * 5.0 / 1024.0;            // convert AD units to volts
//    // convert volts to celsius
//    celsius = (sensorValue * 5.0 / 1024.0) / voltsPerDegree;
//    // standard conversion from celsius to farenheit
//    farenheit = (((sensorValue * 5.0 / 1024.0) / voltsPerDegree)  * 9.0 / 5.0) + 32;
//
//    Serial.print(sensorValue, DEC);
//    Serial.print(" A/D units   ");
//    Serial.print(volts);
//    Serial.print(" volts   ");
//    Serial.print(celsius);
//    Serial.print(" degrees C   ");
//    Serial.print(farenheit);
//    Serial.println(" degrees F");
//}


#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
