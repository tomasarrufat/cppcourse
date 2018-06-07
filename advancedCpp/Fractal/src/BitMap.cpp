// Name     : BtMap.cpp

#include <fstream>
#include <iostream>
#include "BitMap.h"
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h"

using namespace fgen;
using namespace std;

namespace fgen{

BitMap::BitMap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}){
    
};

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

    uint8_t *pPixel = m_pPixels.get();

    pPixel += (x * 3) + m_width * (y * 3); // * 3 because there are three colours

    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
    
};

bool BitMap::write(string fileName){
    
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;
    
    fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + sizeof(uint8_t) * m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    std::fstream oFile;
    oFile.open( fileName.c_str(), std::ios::binary | std::ios::out);

    if( !oFile ){
        return false;
    }

    oFile.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
    oFile.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
    oFile.write(reinterpret_cast<char *>(m_pPixels.get()), /*sizeof(uint8_t) * */m_width * m_height * 3); // TODO: check this line

    oFile.close();

    if( !oFile ){
        return false;
    }

    return true;
};

BitMap::~BitMap(){
    
};

}; // end namespace fgen

