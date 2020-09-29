#ifndef SUNIT_LIBRARIAN_SOCKET
#define SUNIT_LIBRARIAN_SOCKET

namespace sunit::librarian {
    class Socket {
        protected:
            virtual int _read(void *buffer, int offset, int length) = 0;
            virtual int _write(void *buffer, int offset, int length) = 0;
        public:
            virtual ~Socket() = 0;
            template<typename T> int read(void *buffer, int offset, int length){
                return _read((T*)buffer, offset, length);
            }
            template<typename T> int write(void *buffer, int offset, int length){
                return _write((T*)buffer, offset, length);
            }
            virtual void close();
    };
}
#endif