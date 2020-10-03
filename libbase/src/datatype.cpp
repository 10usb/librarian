#include <sunit/librarian/datatype.hpp>
#include <stdint.h>

using namespace sunit::librarian;
namespace sl = sunit::librarian;

union DataConvert {
    int8_t int1;
    int16_t int2;
    int32_t int3 : 24;
    int32_t int4;
    int64_t int5 : 40;
    int64_t int6 : 48;
    int64_t int7 : 56;
    int64_t int8;
    float float4;
    double  float8;
    long double float12;
    char *text;
};

inline void assignFloat(long double value, DataConvert *destination, DataType dstType, int dstLength);
inline void assignInt(int64_t value, DataConvert *destination, DataType dstType, int dstLength);

inline void assignInt(int64_t value, DataConvert *destination, DataType dstType, int dstLength){
    if(dstType == Integer){
        switch (dstLength){
            case 1: destination->int1 = value; break;
            case 2: destination->int2 = value; break;
            case 3: destination->int3 = value; break;
            case 4: destination->int4 = value; break;
            case 5: destination->int5 = value; break;
            case 6: destination->int6 = value; break;
            case 7: destination->int7 = value; break;
            case 8: destination->int8 = value; break;
        }
    }else if(dstType == Float){
        assignFloat(value, destination, dstType, dstLength);
    }else if(dstType == Text){
    }
}

inline void assignFloat(long double value, DataConvert *destination, DataType dstType, int dstLength){
    if(dstType == Float){
        switch (dstLength){
            case 1: destination->int1 = value; break;
            case 2: destination->int2 = value; break;
            case 3: destination->int3 = value; break;
            case 4: destination->int4 = value; break;
            case 5: destination->int5 = value; break;
            case 6: destination->int6 = value; break;
            case 7: destination->int7 = value; break;
            case 8: destination->int8 = value; break;
        }
    }else if(dstType == Integer){
        assignInt(value, destination, dstType, dstLength);
    }else if(dstType == Text){
    }
}


void sl::assign(const void *source, DataType srcType, int srcLength, void *destination, DataType dstType, int dstLength){
    DataConvert *src = (DataConvert*)source;
    DataConvert *dst = (DataConvert*)destination;

    if(srcType == Integer){
        switch (srcLength){
            case 1: assignInt(src->int1, dst, dstType, dstLength); break;
            case 2: assignInt(src->int2, dst, dstType, dstLength); break;
            case 3: assignInt(src->int3, dst, dstType, dstLength); break;
            case 4: assignInt(src->int4, dst, dstType, dstLength); break;
            case 5: assignInt(src->int5, dst, dstType, dstLength); break;
            case 6: assignInt(src->int6, dst, dstType, dstLength); break;
            case 7: assignInt(src->int7, dst, dstType, dstLength); break;
            case 8: assignInt(src->int8, dst, dstType, dstLength); break;
        }
    }else if(srcType == Float){
        switch (srcLength){
            case 4: assignFloat(src->float4, dst, dstType, dstLength); break;
            case 8: assignFloat(src->float8, dst, dstType, dstLength); break;
            case 12: assignFloat(src->float12, dst, dstType, dstLength); break;
        }
    }else{

    }
}

int sl::compare(const void *left, const void *right, DataType type, int length){
    return 0;
}