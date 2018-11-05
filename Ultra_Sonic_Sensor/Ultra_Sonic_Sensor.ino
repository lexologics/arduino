#include <HC_SR04.h>

#define TRIG_PIN 3
#define ECHO_PIN 2
#define ECHO_INT 0

HC_SR04 sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);

void setup() {
  
  
  sensor.begin();
  Serial.begin(9600);
  while(!Serial) continue;
}

void loop() {
  sensor.start();
  while(!sensor.isFinished()) continue;          // If the sensor does not have a reading, wait!
  //while(!sensor.isFinished()) return;  // this one continues
  Serial.print(sensor.getRange());
  Serial.println(" cm");
  delay(1000);
}
