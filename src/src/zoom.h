#ifndef ZOOM_H_
#define ZOOM_H_

namespace bitmapNS {

struct Zoom {

    int x{0};  // cooridinates to zoom too in the bitmap cooridinates system 
    int y{0};
    double scale{0.0};   
    Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {}; // fancy initialization of function Zoom 

};  // using struct instead of class here because structs have all members public by default (apart from that, structs and classes are exactly the same)

}   /* bitmapNS */


#endif /* ZOOM_H_ */