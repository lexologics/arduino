#include <SPI.h>
#include "RF24.h"

byte msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0x8675309ABCLL;
int led = 8;

void setup(void) {
  Serial.begin(115200);
  Serial.println("In Setup");
  pinMode(led, OUTPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop(void) {
  msg[0] = 111;
  radio.write(msg, sizeof(msg));
  Serial.println("Turning Light On");
  digitalWrite(led, LOW);
  delay(2000);

  msg[0] = 000;
  radio.write(msg, sizeof(msg));
  Serial.println("Turning Light Off");
  digitalWrite(led, HIGH);
  delay(2000);

}
