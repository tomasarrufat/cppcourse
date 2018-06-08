// Name     : FractalCreator.h

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Zoom.h"
#include <string>

using namespace std;

namespace fgen{

class FractalCreator{
        public:

        public:
            FractalCreator();
            virtual ~FractalCreator();

            void calculateIteration();
            void drawFractal();
            void writeBitmap(string fileName);
            void addZoom(const Zoom &zoom);
};

}; // end namespace fgen

#endif /* FRACTALCREATOR_H_ */