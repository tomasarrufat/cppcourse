// Name     : FractalCreator.h

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Zoom.h"
#include <string>
#include <memory>
#include <iostream>
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "BitMap.h"

using namespace std;

namespace fgen{

class FractalCreator{
        private:
            int m_width{0};
            int m_height{0};
            unique_ptr<int[]> m_pHistogram;
            unique_ptr<int[]> m_pFractal;
            BitMap m_bitmap;
            ZoomList m_zoomList;
        public:
            FractalCreator(int width, int height);
            virtual ~FractalCreator();

            void calculateIteration();
            void drawFractal(int subSample);
            void writeBitmap(string fileName);
            void addZoom(const Zoom &zoom);
};

}; // end namespace fgen

#endif /* FRACTALCREATOR_H_ */