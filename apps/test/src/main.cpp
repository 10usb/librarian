#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sunit/storage/index.hpp>
#include <sunit/storage/file.hpp>
#include <sunit/storage/structs.hpp>
#include <sunit/librarian/basicset.hpp>
#include <sunit/librarian/hash.hpp>

using namespace sunit::storage;
using namespace sunit::librarian;

int main(int argc, const char ** argv){
    setbuf(stdout, 0);

    printf("-----------------\n");
    printf("IndexHeader: %d\n", sizeof(IndexHeader));
    printf("Field: %d\n", sizeof(Field));
    printf("IndexEntry: %d\n", sizeof(IndexEntry));
    printf("IndexReferance : %d\n", sizeof(IndexReferance));
    
    printf("-----------------\n");
    Index *index = new Index(new File("test.x"), true);

    if(!index->hasFields()){
        index->setUnique(true);
        index->addField("customer_id", sl::Integer, 4);
        index->addField("created", sl::Integer, 4);
    }
    printf("-----------------\n");


    BasicSet *key = new BasicSet(5);
    int32_t value = 123;
    key->add("customer_id", sl::Integer, 4, &value);

    value = 1600553386;
    key->add("created", sl::Integer, 4, &value);

    printf("count: %d\n", key->count());
    printf("ordinal: %d\n", key->ordinal("created"));
    printf("size: %d\n", key->get(1, 0));

    int32_t extract;
    printf("size: %d\n", key->get(0, &extract));
    printf("extract: %d\n", extract);


    printf("-----------------\n");
    index->add(1234, key);
    printf("-----------------\n");
    // delete key;
    delete index;

    return 0;
}