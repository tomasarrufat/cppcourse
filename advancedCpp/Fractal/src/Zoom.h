// Name     : Zoom.h

#ifndef ZOOM_H_
#define ZOOM_H_

using namespace std;

namespace fgen{

struct Zoom{
    int x{0};
    int y{0};
    double scale{0.0};

    Zoom(int pX, int pY, double pScale): x(pX), y(pY), scale(pScale){};
};

}; // end namespace fgen

#endif /* ZOOM_H_ */
