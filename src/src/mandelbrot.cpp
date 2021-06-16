#include <complex>
#include "mandelbrot.h"

using namespace std;

namespace bitmapNS {

Mandelbrot::Mandelbrot() {
    
}

Mandelbrot::~Mandelbrot() {

}

int Mandelbrot::getIterations(double x, double y) {             // uses complex number header

    complex<double> z = 0;  // z is used traditionally to represent complex numbers. z is also overloaded in this template class because complex numbers come in format (int, int) so z is now init to (0,0)
    complex<double> c(x, y);

    int iterations = 0;     // this will be the method that will see how many loops we have to do before the above variables start shooting off to infinity


    return 0;
}


} /* namespace bitmapNS */
