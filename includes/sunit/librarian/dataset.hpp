#ifndef SUNIT_LIBRARIAN_DATASET
#define SUNIT_LIBRARIAN_DATASET

#include <stdint.h>
#include <sunit/librarian/datatype.hpp>

namespace sunit::librarian {
    class DataSet {
        public:
            virtual ~DataSet() {};
            virtual int count() = 0;
            virtual int ordinal(const char *name) = 0;
            virtual int key(uint8_t ordinal, char *buffer) = 0;
            virtual DataType type(uint8_t ordinal) = 0;
            virtual int32_t get(uint8_t ordinal, void *output) = 0;
    };
}
#endif