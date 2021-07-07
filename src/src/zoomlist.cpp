
#include "ZoomList.h"

using namespace std;
namespace bitmapNS {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {}

void ZoomList::add(const Zoom& zoom) {

    zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width/2)*m_scale; // multiplied by m_scale to get the zoom calculation in terms of fractal cooridinates
    m_yCenter += (zoom.y - m_height/2)*m_scale;

    m_scale *= zoom.scale;

    // cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << endl;  // debug output 
}

pair<double, double> ZoomList::doZoom(int x, int y) {

    double xFractal = (x - m_width/2)*m_scale + m_xCenter;  // finally able to replace hacky bit 
    double yFractal = -(y - m_height/2)*m_scale + m_yCenter;
    return pair<double, double>(xFractal, yFractal);   // uses the constructor to default values to (0,0)
}

}   /* namespace bitmapNS */

/* zoom function should to be able to select a point on the image

then we take the point choosen and center it to the middle of the screen and zoom in from there
(so center the point first then zoom around it)

then we will set up the repeated zoom using mouse cooridinates

will finally combine all the zooms into 1 and output the final zoomed in part of fractal image

*/