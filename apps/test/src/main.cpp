#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

#include <sunit/storage/index.hpp>
#include <sunit/storage/file.hpp>
#include <sunit/storage/structs.hpp>
#include <sunit/librarian/basicset.hpp>
#include <sunit/librarian/hash.hpp>
#include <sunit/storage/structure.hpp>

using namespace sunit::storage;
using namespace sunit::librarian;

int main(int argc, const char ** argv){
    setbuf(stdout, 0);

    // Make sure the working directory is the same this executable is in
    char * path = dirname(strcpy(new char[strlen(argv[0]) + 1], argv[0]));
    if(chdir(path) < 0){
        free(path);
        fprintf(stderr, "Failed to set the working directory");
        return -1;
    }
    free(path);

    printf("-----------------\n");
    printf("IndexHeader: %d\n", sizeof(IndexHeader));
    printf("Field: %d\n", sizeof(Field));
    printf("IndexEntry: %d\n", sizeof(IndexEntry));
    printf("IndexReferance : %d\n", sizeof(IndexReferance));
    printf("-----------------\n");

    const char *text = "customer_id\0created";
    Field *fields = new Field[2];
    fields[0].name = 0;
    fields[0].size = 3;
    fields[0].type = sl::Integer;
    fields[1].name = 12;
    fields[1].size = 5;
    fields[1].type = sl::Integer;
    Structure *structure = new Structure(fields, 2, text);

    printf("-----------------\n");
    printf("structure->count: %d\n", structure->count());
    printf("structure->size: %d\n", structure->size());
    printf("-----------------\n");
    char buffer[256];
    printf("key 0 -> d : %d\n", structure->key(0, buffer));
    printf("key 0 -> s : %s\n", buffer);

    printf("key 1 -> d : %d\n", structure->key(1, buffer));
    printf("key 1 -> s : %s\n", buffer);
    printf("-----------------\n");


    // Index *index = new Index(new File("test.x"), true);
    // if(!index->hasFields()){
    //     index->setUnique(true);
    //     index->addField("customer_id", sl::Integer, 4);
    //     index->addField("created", sl::Integer, 4);
    // }

    printf("-----------------\n");

    BasicSet *key = new BasicSet(5);
    int32_t value;

    value = 1600553386;
    key->add("created", sl::Integer, 4, &value);

    value = 123;
    key->add("customer_id", sl::Integer, 4, &value);

    printf("count: %d\n", key->count());
    printf("ordinal: %d\n", key->ordinal("created"));
    printf("size: %d\n", key->get(1, 0));

    int32_t extract;
    printf("size: %d\n", key->get(0, &extract));
    printf("extract: %d\n", extract);

    printf("-----------------\n");

    structure->fromDataSet(key, buffer);
    delete key;

    printf("-----------------\n");
    // index->add(1234, key);
    // printf("-----------------\n");
    
    // delete index;


    return 0;
}