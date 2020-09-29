#ifndef SUNIT_LIBRARIAN_BASE
#define SUNIT_LIBRARIAN_BASE

#include "table.hpp"

namespace sunit::librarian {
    class Base {
        public:
            virtual ~Base() = 0;
            virtual Table *table(const char *name) = 0;
            virtual Table *create(const char *name) = 0;
    };
}
#endif