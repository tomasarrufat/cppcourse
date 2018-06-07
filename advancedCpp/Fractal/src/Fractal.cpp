// Name     : Fractal.cpp

#include <iostream>
#include <cstdint>
#include "BitMap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fgen;

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    BitMap bitmap(WIDTH, HEIGHT);

    unique_ptr<int[]> pHistogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> pFractal(new int[WIDTH * HEIGHT]{0});

    for(int x = 0; x < WIDTH; x++)
    {  
        for(int y = 0; y < HEIGHT; y++)
        {
            double xFractal = 2. * (static_cast<double>(x) / static_cast<double>(min(HEIGHT,WIDTH)) ) - 2.0;
            double yFractal = 2. * (static_cast<double>(y) / static_cast<double>(min(HEIGHT,WIDTH)) ) - 1.0;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            pFractal[y * WIDTH + x] = iterations;
            if( iterations < Mandelbrot::MAX_ITERATIONS) pHistogram[iterations]++;

            // Get piecewice lienar

            const int N = 256; // colors per element
            int N3 = N * N * N;
            // map n on the 0..1 interval (real numbers)
            double t = static_cast<double>(iterations)/static_cast<double>(Mandelbrot::MAX_ITERATIONS);
            // expand n on the 0 .. 256^3 interval (integers)
            iterations = static_cast<int>(t * static_cast<double>(N3));            
            int blue = iterations/(N * N);
            int nn = iterations - blue * N * N;
            int red = nn/N;
            int green = nn - red * N;

            // End of Get picewice linear

            bitmap.setPixel(x, y, static_cast<uint8_t>(red), static_cast<uint8_t>(green), static_cast<uint8_t>(blue));
        }
    }

    
    int totalColouredPixels = 0;
    for ( int it = 0; it < Mandelbrot::MAX_ITERATIONS; it++ ){
        totalColouredPixels += pHistogram[it];
    }

    //Printing loop
     for(int x = 0; x < WIDTH; x++)
    {  
        for(int y = 0; y < HEIGHT; y++)
        {
            int iterations =  pFractal[y * WIDTH + x];
            // Get piecewice lienar

            const int N = 256; // colors per element
            int N3 = N * N * N;
            // map n on the 0..1 interval (real numbers)
            double hue{0};
            for(int it = 0; it < iterations; it++ )
            {
                hue += static_cast<double>(pHistogram[it])/static_cast<double>(totalColouredPixels);
            }
            // expand n on the 0 .. 256^3 interval (integers)
            iterations = static_cast<int>(hue * static_cast<double>(N3));            
            int blue = iterations/(N * N);
            int nn = iterations - blue * N * N;
            int red = nn/N;
            int green = nn - red * N;

            // End of Get picewice linear

            bitmap.setPixel(x, y, static_cast<uint8_t>(red), static_cast<uint8_t>(green), static_cast<uint8_t>(blue));
        }
    }

    /*Histogram validation**
    const int outInterval{30};
    int counter{0};
    int totalSum{0};

    cout << "Ploting histogram with interval " << outInterval << "." << endl;

    for(int it = 0; it < Mandelbrot::MAX_ITERATIONS; it++)
    {
        totalSum += pHistogram[it];
        if( it % outInterval != 0 || it == 0){
            counter += pHistogram[it];
        }
        else{
            cout << counter << endl;
            counter = pHistogram[it];

        }
    }

    cout << counter << endl;

    //cout << "Total sum is: " << totalSum << endl;
    //cout << "Total sum should be: " << WIDTH * HEIGHT << endl; */


    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    
    return 0;
}

