#ifndef SUNIT_LIBRARIAN_BASICSET
#define SUNIT_LIBRARIAN_BASICSET

#include <stdint.h>
#include <sunit/librarian/dataset.hpp>

namespace sunit::librarian {
    class BasicSet : public DataSet {
        struct Value {
            uint8_t ordinal;
            char *name;
            DataType type;
            int32_t size;
            union {
                uint8_t bytes[8];
                char *text;
            };
        } *values;
        int _count;
        int capacity;
        public:
            BasicSet(int capacity);
            ~BasicSet();
            int count() const;
            int ordinal(const char *name) const;
            int key(uint8_t ordinal, char *buffer) const;
            DataType type(uint8_t ordinal) const;
            int32_t get(uint8_t ordinal, void *output) const;
            int add(const char *name, DataType type, int32_t size, const void *data);
    };
}
#endif