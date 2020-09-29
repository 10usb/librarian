#include <sunit/storage/index.hpp>
#include <sunit/storage/structs.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace sunit::storage;

Index::Index(IO *io, bool owner){
    this->io = io;
    this->owner = owner;
}

Index::~Index(){
    if(owner) delete io;
}

bool Index::isUnique(){
    IndexHeader header;
    io->begin();
    if(io->read(&header, 0, sizeof(IndexHeader)) != sizeof(IndexHeader)){
        io->end();
        return false;
    }
    io->end();
    return (header.unique & 1) != 0;
}

int Index::setUnique(bool unique){
    IndexHeader header;

    io->begin();
    int read = io->read(&header, 0, sizeof(IndexHeader));
    if(read != sizeof(IndexHeader)){
        memset(&header, 0, sizeof(IndexHeader));
    }

    // Index needs to be empty
    if(header.count > 0){
        io->end();
        return 1;
    }

    // Update the field
    header.unique = unique;

    io->write(&header, 0, sizeof(IndexHeader));

    io->end();
    return 0;
}

bool Index::hasFields(){
    IndexHeader header;
    io->begin();
    if(io->read(&header, 0, sizeof(IndexHeader)) != sizeof(IndexHeader)){
        io->end();
        return false;
    }
    io->end();
    return header.fields > 0;
}

sl::Result *Index::getFields(){
    return 0;
}

int Index::addField(const char *name, sl::DataType type, uint32_t size){
    IndexHeader header;
    Field *fields;
    char *text;

    io->begin();
    int read = io->read(&header, 0, sizeof(IndexHeader));
    if(read != sizeof(IndexHeader)){
        memset(&header, 0, sizeof(IndexHeader));
    }

    // Index needs to be empty
    if(header.count > 0){
        io->end();
        return 1;
    }

    // Make space for the current fields + 1
    fields = new Field[header.fields + 1];
    io->read(fields, sizeof(IndexHeader), sizeof(Field) * header.fields);

    // Make space for the string table + current string appended to it
    uint16_t textSize = header.textSize + strlen(name) + 1;
    text = new char[textSize];
    io->read(text, header.text, header.textSize);

    // Set field values
    fields[header.fields].name = header.textSize;
    fields[header.fields].type = type;
    fields[header.fields].size = size;

    // Copy the name to the table
    memcpy(text + fields[header.fields].name, name, strlen(name) + 1);

    // Now update the header with the new values
    header.fields++;
    header.textSize = textSize;
    header.text = sizeof(IndexHeader) + sizeof(Field) * header.fields;
    header.data = header.text + textSize;

    io->write(&header, 0, sizeof(IndexHeader));
    io->write(fields, sizeof(IndexHeader), sizeof(Field) * header.fields);
    io->write(text, header.text, textSize);

    io->end();
    return 0;
}

int Index::removeField(const char *name, sl::DataType type, uint32_t size){
    return 0;
}

bool Index::add(uint32_t offset, const sl::DataSet *key){
    return 0;
}

bool Index::remove(const sl::DataSet *key, uint32_t offset){
    return 0;
}

sl::Result *Index::find(const sl::DataSet *key){
    return 0;
}