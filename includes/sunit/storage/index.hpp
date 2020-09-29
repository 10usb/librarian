#ifndef SUNIT_STORAGE_INDEX
#define SUNIT_STORAGE_INDEX

#include <stdint.h>

#include <sunit/storage/io.hpp>
#include <sunit/librarian/datatype.hpp>
#include <sunit/librarian/dataset.hpp>
#include <sunit/librarian/result.hpp>

namespace sunit::storage {
    namespace sl = sunit::librarian;

    class Index {
        IO *io;
        bool owner;
        public:
            Index(IO *io, bool owner);
            ~Index();

            bool isUnique();
            int setUnique(bool unique);

            // Structure
            bool hasFields();
            sl::Result *getFields();
            int addField(const char *name, sl::DataType type, uint32_t size);
            int removeField(const char *name, sl::DataType type, uint32_t size);

            // Data
            bool add(uint32_t offset, const sl::DataSet *key);
            bool remove(const sl::DataSet *key, uint32_t offset);
            sl::Result *find(const sl::DataSet *key);
    };
}

#endif