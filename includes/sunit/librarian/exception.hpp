#ifndef SUNIT_LIBRARIAN_EXCEPTION
#define SUNIT_LIBRARIAN_EXCEPTION

namespace sunit::librarian {
    class Exception {
        public:
            virtual int code();
            virtual const char *message();
    };
}
#endif