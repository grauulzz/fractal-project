/* https://upload.wikimedia.org/wikipedia/commons/c/c4/BMPfileFormat.png */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmapNS {

// tells that this binary file is a bitmap file (bitmap files have a "fixed" format)
struct bitmapFileHeader {   
    char bmpSignatureBytes[2] = {'B', 'M'};
    int32_t bmpFileSize;
    int32_t reservedBytes{0};
    int32_t pixelDataOffset; 

};

} /* namespace bitmapNS */

#endif /* BITMAPFILEHEADER_H_ */