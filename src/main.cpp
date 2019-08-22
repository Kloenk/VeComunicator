#include <Arduino.h>

#include "main.h"

void setup() {
  Serial.begin(CONF_VE_BAUT);
  delay(200);
  Serial.println();
  Serial.println("hallo Welt");
  char *req = ve::get(2030);
  Serial.print(req);
  Serial.println("test");
  free(req);
}

void loop() {
  // put your main code here, to run repeatedly:
}