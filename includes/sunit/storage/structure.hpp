#ifndef SUNIT_STORAGE_STRUCTURE
#define SUNIT_STORAGE_STRUCTURE

#include <stdint.h>
#include <stddef.h>

#include <sunit/storage/structs.hpp>
#include <sunit/librarian/datatype.hpp>
#include <sunit/librarian/dataset.hpp>

namespace sunit::storage {
    namespace sl = sunit::librarian;

    class Structure {
        size_t _size;
        int _count;
        Field *_fields;
        size_t *_offsets;
        char *_text;
        public:
            Structure(const Field *fields, int count, const char *text);
            ~Structure();
            
            size_t size();
            int count();
            int ordinal(const char *name);
            int key(uint8_t ordinal, char *buffer);
            sl::DataType type(uint8_t ordinal);

            size_t fromDataSet(const sl::DataSet *dataSet, void *destination, char *text, size_t textSize);
            sl::DataSet *toDataSet(const void *source);
            int compare(const void *left, const void *right);
    };
}

#endif