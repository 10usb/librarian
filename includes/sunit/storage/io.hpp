#ifndef SUNIT_STORAGE_IO
#define SUNIT_STORAGE_IO

#include <stdint.h>
#include <stddef.h>

namespace sunit::storage {
    class IO {
        public:
            virtual ~IO(){}
            virtual bool begin() = 0;
            virtual void end() = 0;
            virtual size_t read(void * ptr, size_t offset, size_t size) = 0;
            virtual size_t write(const void * ptr, size_t offset, size_t size) = 0;
    };
}

#endif