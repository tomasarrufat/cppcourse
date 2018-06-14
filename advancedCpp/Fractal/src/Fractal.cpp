// Name     : Fractal.cpp

#include <iostream>
#include <cstdint>
#include "FractalCreator.h"

using namespace std;
using namespace fgen;

int main()
{
    int const WIDTH = 1960;
    int const HEIGHT = 1080;
    int const SUB = 10;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    //BitMap m_bitmap(m_width, m_height);

    //ZoomList m_zoomList(m_width, m_height);
    fractalCreator.addZoom(Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH));
    fractalCreator.addZoom(Zoom(-475, HEIGHT/2, 0.05));
    fractalCreator.addZoom(Zoom(-410, HEIGHT/2, 0.01));
    fractalCreator.addZoom(Zoom(WIDTH/2+282, HEIGHT/2, 0.01));
    fractalCreator.addZoom(Zoom(WIDTH/2-332, HEIGHT/2, 0.01));
    fractalCreator.addZoom(Zoom(WIDTH/2-60, HEIGHT/2, 0.001));
    fractalCreator.addZoom(Zoom(WIDTH/2-25, HEIGHT/2, 0.01));

    fractalCreator.calculateIteration();

    int subsample{1};
    char answer{'n'};

    while( answer != 'y' && answer != 'Y')
    {
        cout << "Enter subsample: ";
        cin >> subsample;
        cout << endl;

        fractalCreator.drawFractal(subsample);
        fractalCreator.writeBitmap("test.bmp");

        cout << "Do you want to finish? [Y/n]: ";
        cin >> answer;
        cout << endl;

    }

    cout << "Finished." << endl;
    
    return 0;
}

