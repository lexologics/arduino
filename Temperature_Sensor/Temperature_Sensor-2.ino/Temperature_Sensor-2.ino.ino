/*TMP37.pde  
* Arduino Sketch to read a TMP37 Temperature Sensor
* Paul Badger
* 2010
* Sensor works between 5 degrees & 100 degrees C
* 20 mV / degree C
* Can be used with TMP35 & TMP36 by changing voltsPerDegree
*/

float voltsPerDegree = 0.02; // change to 0.01 for TMP35 & 36

void setup() {
    Serial.begin(9600);
}

void loop() {
    int sensorValue;
    float volts;
    float celsius;
    float farenheit;

    sensorValue = analogRead(A1);
    volts = sensorValue * 5.0 / 1024.0;            // convert AD units to volts
    // convert volts to celsius
    celsius = (sensorValue * 5.0 / 1024.0) / voltsPerDegree;
    // standard conversion from celsius to farenheit
    farenheit = (((sensorValue * 5.0 / 1024.0) / voltsPerDegree)  * 9.0 / 5.0) + 32;

    Serial.print(sensorValue, DEC);
    Serial.print(" A/D units   ");
    Serial.print(volts);
    Serial.print(" volts   ");
    Serial.print(celsius);
    Serial.print(" degrees C   ");
    Serial.print(farenheit);
    Serial.println(" degrees F");
}
