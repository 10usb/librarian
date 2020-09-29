#ifndef SUNIT_LIBRARIAN_HASH
#define SUNIT_LIBRARIAN_HASH

#include <stdint.h>

namespace sunit::librarian {
    namespace hash {
        uint16_t makePrime(uint16_t value);
        uint32_t getHash(const char *value);
    };
}
#endif