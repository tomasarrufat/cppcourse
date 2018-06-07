// Name     : BitMapFileHeader.h

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace fgen{

struct BitMapFileHeader{
    char header[2]{'B', 'M'};
    int32_t fileSize; // Needs to be 32 bits
    int32_t reserved{0};
    int32_t dataOffset;
};

}; // end namespace fgen

#endif /* BITMAPFILEHEADER_H_ */
