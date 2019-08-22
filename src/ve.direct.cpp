
#include "ve.direct.h"

bool ve::check(uint8_t *payload) {
    uint8_t checksum = CHECKSUM;
    for (unsigned int i = 0; i < sizeof(payload); i++)
        checksum -= payload[i];
    return (checksum == 0);
}

char *ve::get(uint16_t id) {
    return ve::get(id, 0);
}

char *ve::get(uint16_t id, uint8_t flag) {
    char *buffer = (char *)malloc(11 * sizeof(char));
    sprintf(buffer, "7%04X%02X", id, flag);
    ve::finish(buffer);
    return buffer;
}

void ve::finish(char *payload) {
    Serial.println(payload);
    uint8_t checksum = CHECKSUM;
    char *old = strncpy(old, payload, 11);
    for (unsigned int i =0; i < sizeof(payload); i++)
        checksum -= payload[i];
    sprintf(payload, ":%s%02X\n", old, checksum);
    free(old);
}