#include <sunit/storage/structure.hpp>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

using namespace sunit::storage;

Structure::Structure(const Field *fields, int count, const char *text){
    int textSize = 0;
    for(int index = 0; index < count; index++){
        textSize += strlen(text + fields[index].name);
    }
    // For the \0
    textSize+=count;

    _text = new char[textSize];
    _fields = new Field[count];
    _offsets = new size_t[count];

    int16_t ptr = 0;
    _size = 0;
    for(int index = 0; index < count; index++){
        // Current _size is offset and _size + size is next offset
        _offsets[index] = _size;
        _size+= fields[index].size;

        // Copy string into new table
        const char * src = text + fields[index].name;
        int length = strlen(src) + 1;
        memcpy(_text + ptr, src, length);
        _fields[index].name = ptr;
        ptr+= length;

        // Remaing vars
        _fields[index].type = fields[index].type;
        _fields[index].size = fields[index].size;
    }

    _count = count;
}

Structure::~Structure(){
    delete[] _text;
    delete[] _fields;
    delete[] _offsets;
}
      
size_t Structure::size(){
    return _size;
}

int Structure::count(){
    return _count;
}

int Structure::ordinal(const char *name){
    for(int index = 0; index < _count; index++){
        // Copy string into new table
        const char * src = _text + _fields[index].name;
        if(strcmp(src, name) == 0) return index;
    }
    return -1;
}

int Structure::key(uint8_t ordinal, char *buffer){
    if(ordinal >= _count) return -1;

    Field *field = &_fields[ordinal];
    char *ptr = _text + field->name;
    int size = strlen(ptr) + 1;
    if(buffer) memcpy(buffer, ptr, size);

    return size;
}

sl::DataType Structure::type(uint8_t ordinal){
    return _fields[ordinal].type;
}

size_t Structure::fromDataSet(const sl::DataSet *dataSet, void *destination, char *text, size_t textSize){
    char buffer[1024];
    for(int index = 0; index < _count; index++){
        Field *field = &_fields[index];
        char *name = _text + field->name;
        int ordinal = dataSet->ordinal(name);

        if(ordinal < 0)
            continue;

        printf("%d: %s\n", ordinal, name);

        if(field->type != sl::Text){
            sl::DataType type = dataSet->type(ordinal);
            if(type == sl::Text)
                continue;

            int length = dataSet->get(ordinal, buffer);

            sl::assign(buffer, type, length, (char*)destination + _offsets[index], field->type, field->size);
        }else{

        }
    }

    return 0;
}

sl::DataSet *Structure::toDataSet(const void *source){
    return 0;
}

int Structure::compare(const void *left, const void *right){
    return 0;
}
