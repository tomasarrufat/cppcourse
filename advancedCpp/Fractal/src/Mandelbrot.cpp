// Name     : Mandelbrot.cpp

#include "Mandelbrot.h"
#include <complex>

using namespace std;

namespace fgen{

Mandelbrot::Mandelbrot(){

};

Mandelbrot::~Mandelbrot(){

};

int Mandelbrot::getIterations(double x, double y){

    complex<double> z(0, 0);
    complex<double> c(x, y);

    int iterations = 0;

    while( iterations < MAX_ITERATIONS )
    {
        z = z * z + c;

        if( abs(z) > 2 ) break; // If it doesn't break they are within the mandelbrot set

        iterations++;
    }

    return iterations;
};





}; // end namespace fgen