#ifndef SUNIT_LIBRARIAN_FIELDSET
#define SUNIT_LIBRARIAN_FIELDSET

#include <stdint.h>

namespace sunit::librarian {
    class FieldSet {
        char **fields;
        public:
            const char *get(uint8_t index);
            void add(const char *name);
    };
}
#endif