#ifndef __VE_DIRECT_H__
#define __VE_DIRECT_H__

#include <Arduino.h>

// checksum for payload data
#define CHECKSUM 0x55

namespace ve
{
    // verify checksum
    bool check(uint8_t *payload);

    // create request
    char *get(uint16_t id, uint8_t flag);

    // create get request with flag 0
    char *get(uint16_t id);

    // finish line with checksum and add delimeters
    void finish(char *payload);
} // namespace ve


#endif // __VE_DIRECT_H__