#ifndef SUNIT_LIBRARIAN_ORDER
#define SUNIT_LIBRARIAN_ORDER

namespace sunit::librarian {
    class Order {
        public:
            enum Direction {
                Ascending = 0,
                Decending = 1
            };
        private:
            char * _field;
            Direction _direction;
        public:
            const char *field();
            Direction direction();
    };
}
#endif