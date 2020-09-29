#ifndef SUNIT_STORAGE_FILE
#define SUNIT_STORAGE_FILE

#include <stdint.h>
#include <sunit/storage/io.hpp>

namespace sunit::storage {
    class File : public IO {
        char * path;
        void * handle;
        public:
            File(const char *path);
            ~File();
            int getPath(char *buffer, int size);
            bool begin();
            void end();
            size_t read(void * ptr, size_t offset, size_t size);
            size_t write(const void * ptr, size_t offset, size_t size);
    };
}

#endif