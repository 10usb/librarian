#ifndef SUNIT_LIBRARIAN_DATATYPES
#define SUNIT_LIBRARIAN_DATATYPES

namespace sunit::librarian {
    enum DataType {
        Undefined = 0,
        Integer = 1,
        Float = 2,
        Text = 3, 
    };

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
}
#endif