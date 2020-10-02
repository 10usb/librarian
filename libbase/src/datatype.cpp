#include <sunit/librarian/datatype.hpp>
#include <stdint.h>

using namespace sunit::librarian;
namespace sl = sunit::librarian;

union DataConvert {
    int8_t int8;
    int16_t int16;
    int32_t int24 : 24;
    int32_t int32;
    int64_t int40 : 40;
    int64_t int48 : 48;
    int64_t int56 : 56;
    int64_t int64;
    float float4;
    double  float8;
    char *text;
};

void sl::assign(const void *source, DataType srcType, int srcLength, void *destination, DataType dstType, int dstLength){

}

int sl::compare(const void *left, const void *right, DataType type, int length){
    return 0;
}