#ifndef SUNIT_LIBRARIAN_RESULT
#define SUNIT_LIBRARIAN_RESULT

#include <stdint.h>

namespace sunit::librarian {
    class Result {
        protected:
            virtual int _get(uint8_t index, void *output) = 0;
        public:
            virtual ~Result() {};
            template<typename T> int get(uint8_t index, T *output){
                return _get(index, output);
            }
            virtual bool next() = 0;
    };
}
#endif