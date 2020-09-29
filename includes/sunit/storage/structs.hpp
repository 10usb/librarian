#ifndef SUNIT_STORAGE_STRUCTS
#define SUNIT_STORAGE_STRUCTS

#include <stdint.h>
#include <sunit/librarian/datatype.hpp>

namespace sunit::storage {
    namespace sl = sunit::librarian;

    struct IndexHeader {
        uint8_t fields; // The number of fields
        int16_t text; // Offset to the string table
        int16_t textSize; // Total size of the text
        int16_t data; // Offset to start of entry 0
        uint8_t unique; // If not, then a next reference will exist at the end
        uint32_t size : 24; // Size of a node
        uint32_t free : 24; // First node in a linked list of free entries
        uint32_t count : 24; // The number of nodes in the list?
        uint32_t root : 24; // Root node
    } __attribute__ ((__packed__));

    struct Field {
        int16_t name;
        sl::DataType type : 8;
        uint32_t size : 24;
    } __attribute__ ((__packed__));

    struct IndexEntry {
        uint32_t count : 24;
        uint32_t left : 24;
        uint32_t right : 24;
        uint32_t offset;
    } __attribute__ ((__packed__));
    
    struct IndexReferance {
        uint32_t value : 24;
    } __attribute__ ((__packed__));
}

#endif