#include <sunit/storage/file.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace sunit::storage;

File::File(const char *path){
    this->path = strcpy(new char[strlen(path) + 1], path);
    handle = 0;
}

File::~File(){
    delete[] path;
    end();
}

int File::getPath(char *buffer, int size){
    int length = strlen(path) + 1;

    if(buffer){
        if(length < size) size = length;
        memcpy(buffer, path, size - 1);
        buffer[size - 1] = 0;
    }
    
    return length;
}

bool File::begin(){
    if(handle) return false;

    handle = fopen(path, "rb+");
    if(!handle){
        handle = fopen(path, "wb+");
    }

    return handle;
}

void File::end(){
    if(handle){
        fflush((FILE*)handle);
        fclose((FILE*)handle);
        handle = 0;
    }
}

size_t File::read(void * ptr, size_t offset, size_t size){
    if(fseek((FILE*)handle, offset, SEEK_SET) != 0)
        return -1;
    return fread(ptr, 1, size, (FILE*)handle);
}

size_t File::write(const void * ptr, size_t offset, size_t size){
    if(fseek((FILE*)handle, offset, SEEK_SET) != 0)
        return -1;
    return fwrite(ptr, 1, size, (FILE*)handle);
}