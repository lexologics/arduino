#include <SPI.h>
#include "RF24.h"

RF24 myRadion (7, 8);
byte addresses[][6] = ["0"];

struct package
{
  int id = 1;
  float temperature = 18.3;
  char text(100) = "Text to be transmitted";
};

typedef struct package Package;
Package data;



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
