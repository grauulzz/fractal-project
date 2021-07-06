
#include "ZoomList.h"
#include <iostream>

using namespace std;

namespace bitmapNS {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {}

void ZoomList::add(const Zoom& zoom) {

    zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width/2)*m_scale; // multiplied by m_scale to get the zoom calculation in terms of fractal cooridinates
    m_yCenter += (zoom.y - m_height/2)*m_scale;

    m_scale *= zoom.scale;

    cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << endl;  // test if center calc is working
}

pair<double, double> ZoomList::doZoom(int x, int y) {
    return pair<double, double>(0,0);   // uses the constructor to default values to (0,0)
}

}   /* namespace bitmapNS */

/* zoom function should to be able to select a point on the image

then we take the point choosen and center it to the middle of the screen and zoom in from there
(so center the point first then zoom around it)

then we will set up the repeated zoom using mouse cooridinates

will finally combine all the zooms into 1 and output the final zoomed in part of fractal image

*/