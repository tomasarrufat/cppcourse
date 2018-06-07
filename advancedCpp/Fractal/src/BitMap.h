// Name     : BitMap.h

#ifndef BITMAP_H_
#define BITMAP_H

#include <string>
#include <memory> // std::unique_ptr
#include <cstdint>

using namespace std;

namespace fgen{

class BitMap{
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr};
    public:
        BitMap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(string filename);
        virtual ~BitMap();
};

}; // end namespace fgen

#endif /* BITMAP_H_ */
