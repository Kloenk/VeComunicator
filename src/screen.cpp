#include <Arduino.h>
#include "screen.h"
#include "config.h"

OLED display(SDA, SCL);

void setup_display() {
    pinMode(D2, OUTPUT);
    digitalWrite(D2, LOW);
    delay(50);
    digitalWrite(D2, HIGH);

    display.begin();
    display.print(CONF_DISPLAY_NAME);
    display.on();
}
