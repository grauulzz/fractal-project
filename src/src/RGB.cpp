#include "RGB.h"

namespace bitmapNS {

RGB::RGB(double r, double g, double b): r(r), g(g), b(b) {
    
}

RGB operator-(const RGB& first, const RGB& second) {    // overloaded (-) operator
    return RGB(first.r - second.r, first.g - second.g, first.b - second.b); 
}   

}