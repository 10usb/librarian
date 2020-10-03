#ifndef SUNIT_LIBRARIAN_DATATYPES
#define SUNIT_LIBRARIAN_DATATYPES


namespace sunit::librarian {
    enum DataType {
        Undefined = 0,
        Integer = 1,
        Float = 2,
        Text = 3, 
    };

    void assign(const void *source, DataType srcType, int srcLength, void *destination, DataType dstType, int dstLength);

    // Integers
    inline void assign(char value, void *destination, DataType dstType, int dstLength){
        assign(&value, Integer, sizeof(char), destination, dstType, dstLength);
    }
    inline void assign(short value, void *destination, DataType dstType, int dstLength){
        assign(&value, Integer, sizeof(short), destination, dstType, dstLength);
    }
    inline void assign(long value, void *destination, DataType dstType, int dstLength){
        assign(&value, Integer, sizeof(long), destination, dstType, dstLength);
    }
    inline void assign(long long value, void *destination, DataType dstType, int dstLength){
        assign(&value, Integer, sizeof(long long), destination, dstType, dstLength);
    }

    // Floats
    inline void assign(float value, void *destination, DataType dstType, int dstLength){
        assign(&value, Float, sizeof(float), destination, dstType, dstLength);
    }
    inline void assign(double value, void *destination, DataType dstType, int dstLength){
        assign(&value, Float, sizeof(double), destination, dstType, dstLength);
    }
    inline void assign(long double value, void *destination, DataType dstType, int dstLength){
        assign(&value, Float, sizeof(long double), destination, dstType, dstLength);
    }

    int compare(const void *left, const void *right, DataType type, int length);
}
#endif