// Name     : ZoomList.cpp

#include "ZoomList.h"
#include <iostream>

using namespace std;


namespace fgen{

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height){
    
};

void ZoomList::add(const Zoom &zoom){
    zooms.push_back(zoom);

    m_xCenter += static_cast<double>(zoom.x - m_width / 2) * m_scale;
    m_yCenter += static_cast<double>(zoom.y - m_height / 2) * m_scale;

    m_scale *= zoom.scale;

    cout << m_xCenter << " , " << m_yCenter << " , " << m_scale << endl;
};

std::pair<double, double> ZoomList::doZoom(int x, int y){

    double xFractal = static_cast<double>(x - m_width / 2) * m_scale + m_xCenter;
    double yFractal = static_cast<double>(y - m_height / 2) * m_scale + m_yCenter;

    return std::pair<double, double>(xFractal, yFractal);
};

}; // end namespace fgen