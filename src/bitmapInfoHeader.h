#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmapNS {

struct bitmapInfoHeader // bitmap info header data structure
{
    int32_t headerSize{40};        // cumulative total bytes in struct
    int32_t width;                // in pixals 
    int32_t height;              // in pixals
    int16_t colorPlanes{1};
    int16_t colorDepth{24};     // bits per pixal/color (1byte=8bits*RGB=24bytes) 
    int32_t compression{0};
    int32_t rawBitmapDataSize{0};
    int32_t horizontalResolution{2400};     // in pixel per meter
    int32_t verticalResolution{2400};       // in pixel per meter
    int32_t colors{0};
    int32_t importantColors{0};

};

}

#endif /* BITMAPINFOHEADER_H_ */