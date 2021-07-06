#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include <vector>
#include <utility>  // template class which contains "pair" used in doZoom for an easy way to return a pair (in this case coordinates)
#include "Zoom.h"

using namespace std;
namespace bitmapNS {
class ZoomList {
private:
    double m_xCenter{0};   // center cooridinates
    double m_yCenter{0};   
    double m_scale{1.0};     // result of all zooms applied

    int m_width{0};     // resolution of screen
    int m_height{0};


public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    vector<Zoom> zooms;

    // method that maps from the bitmap cooridinates to the actual fractal cooridinates then will apply some sort of algrothm on all the zooms (or some shit)


    pair<double, double> doZoom(int x, int y); // will take the cooridinates of the pixel we want to apply the zoom alg to (applied pixel by pixel) and transform them into the fractal cooridinates system
    
};
}   /* bitmapNS */

#endif /* ZOOMLIST_H_ */