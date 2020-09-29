#ifndef SUNIT_LIBRARIAN_TABLE
#define SUNIT_LIBRARIAN_TABLE

#include <stdint.h>

#include "result.hpp"
#include "query.hpp"
#include "dataset.hpp"
#include "fieldset.hpp"
#include "datatype.hpp"

namespace sunit::librarian {
    class Table {
        public:
            virtual ~Table() {}
            // Structure
            virtual void addField(const char *name, DataType type, int32_t size) = 0;
            virtual void removeField(const char *name, DataType type, int32_t size) = 0;
            virtual Result *getFields() = 0;

            // Indexes
            virtual void addIndex(const char *name, const FieldSet *fields) = 0;
            virtual void removeIndex(const char *name) = 0;
            virtual Result *getIndexes() = 0;
            virtual Result *getIndexFields(const char *name) = 0;

            // Data
            virtual Result *insert(const DataSet *data) = 0;
            virtual Result *select(const Query *query) = 0;
            virtual Result *remove(const DataSet *key) = 0;
            virtual Result *update(const DataSet *key, const DataSet *data) = 0;
    };
}
#endif