#include <SPI.h>
#include "RF24.h"

byte msg[1];
RF24 radio(7,8);
const uint64_t pipe = 0x8675309ABll;
int led = 9;

void setup() {
  Serial.begin(115200);
  Serial.println("In Setup");
  pinMode(led, OUTPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  msg[0] = 111;
  radio.write(msg, sizeof(msg));  
  Serial.println("Turning Light On");
  digitalWrite(led, HIGH);
  delay(2000);

  msg[0] = 000;
  radio.write(msg, sizeof(msg));  
  Serial.println("Turning Light Off");
  digitalWrite(led, LOW);
  delay(2000);
  
}
