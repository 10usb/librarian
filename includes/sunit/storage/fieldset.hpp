#ifndef SUNIT_STORAGE_FIELDSET
#define SUNIT_STORAGE_FIELDSET

#include <stdint.h>

#include <sunit/storage/structs.hpp>
#include <sunit/librarian/datatype.hpp>
#include <sunit/librarian/dataset.hpp>

namespace sunit::storage {
    namespace sl = sunit::librarian;

    class FieldSet {
        int size;
        int count;
        Field *fields;
        uint32_t *offsets;
        char *text;
        public:
            FieldSet(const Field *fields, int count, const char *text);
            ~FieldSet();
            
            int count();
            int ordinal(const char *name);
            int key(uint8_t ordinal, char *buffer);
            sl::DataType type(uint8_t ordinal);

            void fromDataSet(const sl::DataSet *dataSet, void *destination);
            sl::DataSet *toDataSet(const void *source);
            int compare(const void *left, const void *right);
    };
}

#endif