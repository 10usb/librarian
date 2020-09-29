#ifndef SUNIT_STORAGE_TABLE
#define SUNIT_STORAGE_TABLE

#include <stdint.h>

#include <sunit/librarian/table.hpp>

namespace sunit::storage {
    namespace sl = sunit::librarian;

    class Table : public sl::Table {
        char *path;
        public:
            Table(const char *path);
            ~Table();

            // Structure
            virtual void addField(const char *name, sl::DataType type, int32_t size);
            virtual void removeField(const char *name, sl::DataType type, int32_t size);
            virtual sl::Result *getFields();

            // Indexes
            virtual void addIndex(const char *name, const sl::FieldSet &fields);
            virtual void removeIndex(const char *name);
            virtual sl::Result *getIndexes();
            virtual sl::Result *getIndexFields(const char *name);

            // Data
            virtual sl::Result *insert(const sl::DataSet *data);
            virtual sl::Result *select(const sl::Query *query);
            virtual sl::Result *remove(const sl::DataSet *key);
            virtual sl::Result *update(const sl::DataSet *key, const sl::DataSet *data);
    };
}

#endif