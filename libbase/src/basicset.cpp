#include <sunit/librarian/basicset.hpp>
#include <sunit/librarian/hash.hpp>
#include <string.h>

using namespace sunit::librarian;

BasicSet::BasicSet(int capacity){
    //this->capacity = hash::makePrime(capacity);
    this->capacity = capacity;
    _count = 0;
    values = new Value[this->capacity];
    //table = new Value*[this->capacity];
    //memset((Value*)table, 0, sizeof(Value*) * this->capacity);
}

BasicSet::~BasicSet(){
    //delete[] table;
    for(int index = 0; index < _count; index++){
        delete values[index].name;
        if(values[index].type == Text) delete values[index].text;
    }
    delete[] values;
}

int BasicSet::count(){
    return _count;
}

int BasicSet::ordinal(const char *name){
    for(int index = 0; index < _count; index++){
        if(strcmp(values[index].name, name) == 0) return index;
    }
    return -1;

    // int index = hash::getHash(name) % capacity;

    // int limit = capacity;

    // while (strcmp(name, table[index]->name) != 0){
    //     index = (index + 2) % capacity;
    //     if(--limit == 0) return -1;
    // }
    
    // return table[index]->ordinal;
}

int BasicSet::key(uint8_t ordinal, char *buffer){
    if(ordinal >= _count) return -1;

    Value *value = &values[ordinal];
    int size = strlen(value->name) + 1;
    if(buffer){
        memcpy(buffer, value->name, size);
    }
    return size;
}

DataType BasicSet::type(uint8_t ordinal){
    if(ordinal >= _count) return Undefined;
    return values[ordinal].type;
}

int32_t BasicSet::get(uint8_t ordinal, void *output){
    if(ordinal >= _count) return -1;

    if(!output) return values[ordinal].size;

    Value *value = &values[ordinal];
    if(value->type == Text){
        memcpy(output, value->text, value->size);
    }else{
        memcpy(output, value->bytes, value->size);
    }
    return value->size;
}

int BasicSet::add(const char *name, DataType type, int32_t size, const void *data){
    // Is it full?
    if(_count >= capacity) return 1;

    // Name already exists
    if(this->ordinal(name) >= 0) return 2;
    
    Value *value = &values[_count];
    value->ordinal = _count++;
    value->name = strcpy(new char[strlen(name) + 1], name);
    value->type = type;
    value->size = size;

    if(type == Text){
        value->text = new char[size];
        memcpy(value->text, data, size);
    }else{
        memcpy(value->bytes, data, size);
    }

    return 0;
}