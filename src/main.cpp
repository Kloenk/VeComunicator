#include <Arduino.h>

#include "main.h"

void setup() {
  Serial.begin(CONF_VE_BAUT);
  delay(200);
  //char *req = ve::get(2030);
  //Serial.print(req);
}

void loop() {
  uint16_t addresses[] = {
    0x0100, // Product Id
    0x0104, // Group Id
    0x0105, // Device instance
    0x0106, // Device class
    0x010A, // Serial number
    0x010B, // Model name
    0x0140, // Capabilities
    0x0200, // Device mode
    0x0201, // Device state
    0x0202, // Remote control used
    0x0205, // Device off reason (*1)
    0xEDFF, // Batterysafe mode (*1)
    0xEDFD, // Automatic equalization mode (*2)
    0xEDFC, // Battery bulk time limit
    0xEDFB, // Battery absorption time limit
    0xEDF7, // Battery absorption voltage (*5)
    0xEDF6, // Battery float voltage (*5)
    0xEDF4, // Battery equalization voltage (*3,*5)
    0xEDF2, // Battery temp. compensation (*5)
    0xEDF1, // Battery type
    0xEDF0, // Battery maximum current
    0xEDE0, // Battery low temperature level (*8)
    0xEDEF, // Battery voltage (*4)
    0xEDEC, // Battery temperature (*8)
    0xEDEA, // Battery voltage setting (*4, *7)
    0xEDE8, // BMS present (*6)
    0xEDE6, // Low temperature charge current (*8)
    0xEDDF, // Charger maximum current (*1)
    0xEDDD, // System yield (*2)
    0xEDDC, // User yield (resettable) (*2)
    0xEDDB, // Charger internal temperature
    0xEDDA, // Charger error code
    0xEDD7, // Charger current (*3)
    0xEDD5, // Charger voltage (*3)
    0xEDD4, // Additional charger state info
    0xEDD3, // Yield today (*2)
    0xEDD2, // Maximum power today (*2)
    0xEDD1, // Yield yesterday (*2)
    0xEDD0, // Maximum power yesterday (*2)
    0xEDCE, // Voltage settings range (*5)
    0xEDCD, // History version (*1)
    0xEDCC, // Streetlight version (*1)
    0x2211, // Adjustable voltage minimum (*6)
    0x2212, // Adjustable voltage maximum (*6)
    0xEDBC, // Panel power
    0xEDBB, // Panel voltage
    0xEDBD, // Panel current (*1)
    0xEDB8, // Panel maximum voltage (*2)
    0xEDAD, // Load current
    0xEDAC, // Load offset voltage
    0xEDAB, // Load output control
    0xEDA9, // Load output voltage (*1)
    0xEDA8, // Load output state
    0xED9D, // Load switch high level (*2)
    0xED9C, // Load switch low level (*2)
    0xED91, // Load output off reason (*3)
    0xEDD9, // Relay operation mode
    0x0350, // Relay battery low voltage set
    0x0351, // Relay battery low voltage clear
    0x0352, // Relay battery high voltage set
    0x0353, // Relay battery high voltage clear
    0xEDBA, // Relay panel high voltage set
    0xEDB9, // Relay panel high voltage clear
    0x100A, // Relay minimum enabled time
  };
  while (true) {
    for (int i = 0; i < (sizeof(addresses) / sizeof(uint16_t)); i += 5) {
      String input;
      for (int j = i; j < i+5; j++) {
        char *req = ve::get(addresses[j]);
        Serial.print(req);
      }
      while (Serial.available()) {
        input.concat(Serial.readStringUntil('\n'));
      }

    }
  }
} 