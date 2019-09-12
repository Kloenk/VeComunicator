
#include "ve.direct.h"

bool ve::check(byte *payload) {
    byte checksum = CHECKSUM;
    for (unsigned int i = 0; i < sizeof(payload) - 1; i++ )
        checksum -= payload[i];
    return (checksum == payload[sizeof(payload)]);
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
    uint8_t checksum = CHECKSUM;
    char *old = (char *)malloc(11 * sizeof(char));
    strncpy(old, payload, 11);
    for (unsigned int i =0; i < sizeof(payload); i++)
        checksum -= payload[i];
    sprintf(payload, ":%s%02X\n", old, checksum);
    free(old);
}

uint8_t ve::hex::decodenibble(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;

    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;

  return 0;  // Not a valid hexadecimal character
}