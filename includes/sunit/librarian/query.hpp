#ifndef SUNIT_LIBRARIAN_QUERY
#define SUNIT_LIBRARIAN_QUERY

#include <stdint.h>
#include "order.hpp"

namespace sunit::librarian {
    class Query {
        public:
            void addField(const char *name);
            const char *getField(uint8_t index);

            void addOrder(const Order &order);
            const Order &getOrder(uint8_t index);
    };
}
#endif