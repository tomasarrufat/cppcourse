// Name     : Fractal.cpp

#include <iostream>
#include <cstdint>
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace fgen;

int main()
{
    int const WIDTH = 1960;
    int const HEIGHT = 1080;
    int const SUB = 10;

    BitMap bitmap(WIDTH, HEIGHT);

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH));
    zoomList.add(Zoom(-475, HEIGHT/2, 0.05));
    zoomList.add(Zoom(-410, HEIGHT/2, 0.01));
    zoomList.add(Zoom(WIDTH/2+282, HEIGHT/2, 0.01));
    zoomList.add(Zoom(WIDTH/2-332, HEIGHT/2, 0.01));
    zoomList.add(Zoom(WIDTH/2-60, HEIGHT/2, 0.001));
    zoomList.add(Zoom(WIDTH/2-25, HEIGHT/2, 0.01));

    
    unique_ptr<int[]> pHistogram(new int[Mandelbrot::MAX_ITERATIONS/SUB]{0});
    unique_ptr<int[]> pFractal(new int[WIDTH * HEIGHT]{0});

    for(int x = 0; x < WIDTH; x++)
    {  
        for(int y = 0; y < HEIGHT; y++)
        {
            auto coordinates = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);

            pFractal[y * WIDTH + x] = iterations;
            if( iterations < Mandelbrot::MAX_ITERATIONS) pHistogram[iterations/SUB]++;

        }
    }

    
    int totalColouredPixels = 0;
    for ( int it = 0; it < Mandelbrot::MAX_ITERATIONS/SUB; it++ ){
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
                hue += static_cast<double>(pHistogram[it/SUB])/static_cast<double>(totalColouredPixels);
            }
            // expand n on the 0 .. 256^3 interval (integers)
            iterations = static_cast<int>((1.0 - hue) * static_cast<double>(N3));            
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

