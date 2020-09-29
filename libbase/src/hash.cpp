#include <sunit/librarian/hash.hpp>
#include <string.h>

namespace sunit::librarian::hash {
    int primes[] = {
        2,2,2,
        3,
        5,5,
        7,7,
        11,11,11,11,
        13,13,
        17,17,17,17,
        19,19,
        23,23,23,23,
        29,29,29,29,29,29,
        31,31,
        37,37,37,37,37,37,
        41,41,41,41,
        43,43,
        47,47,47,47,
        53,53,53,53,53,53,
        59,59,59,59,59,59,
        61,61,
        67,67,67,67,67,67,
        71,71,71,71,
    };

    uint16_t makePrime(uint16_t value){
        return primes[value];
    }

    uint32_t getHash(const char *value){
        uint32_t hash = *value;

        while(*++value){
            hash <<= 1;
            hash += *value;
        }

        return hash;
    }
}