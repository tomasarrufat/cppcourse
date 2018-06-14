// Name     : FractalCreator.cpp

#include "FractalCreator.h"


namespace fgen{

FractalCreator::FractalCreator(int width, int height): m_width(width),
    m_height(height), m_pHistogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0}),
    m_pFractal(new int[m_width * m_height]{0}),
    m_bitmap(width, height), m_zoomList(width, height){};

FractalCreator::~FractalCreator(){

};

void FractalCreator::calculateIteration(){
    
    for(int x = 0; x < m_width; x++)
    {  
        for(int y = 0; y < m_height; y++)
        {
            auto coordinates = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);

            m_pFractal[y * m_width + x] = iterations;
            //if( iterations < Mandelbrot::MAX_ITERATIONS) 
            m_pHistogram[iterations]++;

        }
    }

};

void FractalCreator::drawFractal(int subSample){

    int totalColours = 0;
    unique_ptr<int[]> pSubHistogram(new int[Mandelbrot::MAX_ITERATIONS/subSample]{});
    for ( int it = 0; it < Mandelbrot::MAX_ITERATIONS; it++ ){
        totalColours += m_pHistogram[it];
        pSubHistogram[it/subSample] += m_pHistogram[it];
    }
    totalColours += m_pHistogram[Mandelbrot::MAX_ITERATIONS];

    //Printing loop
    for(int x = 0; x < m_width; x++)
    {  
        for(int y = 0; y < m_height; y++)
        {
            int iterations =  m_pFractal[y * m_width + x];
            // Get piecewice lienar

            const int N = 255; // colors per element
            int N3 = N * N * N;
            // map n on the 0..1 interval (real numbers)
            double hue{0.0};
            if( iterations == Mandelbrot::MAX_ITERATIONS)
            {
                hue = 1.0;
            }
            else
            {
                for(int it = 0; it < iterations/subSample; it++ )
                {
                    hue += static_cast<double>(pSubHistogram[it]);
                }
                hue = hue / static_cast<double>(totalColours);
            }

            if( x == m_width / 2 && y == m_height / 2 ) cout <<  hue << endl;

            // expand n on the 0 .. 256^3 interval (integers)
            iterations = static_cast<int>((1.0 - hue) * static_cast<double>(N3));            
            int blue = iterations/(N * N);
            int nn = iterations - blue * N * N;
            int red = nn/N;
            int green = nn - red * N;

            // End of Get picewice linear

            m_bitmap.setPixel(x, y, static_cast<uint8_t>(red), static_cast<uint8_t>(green), static_cast<uint8_t>(blue));
        }
    }
};

void FractalCreator::writeBitmap(string fileName){
    m_bitmap.write("test.bmp");
};

void FractalCreator::addZoom(const Zoom &zoom){
    m_zoomList.add(zoom);
};

};
