#include <complex>
#include "mandelbrot.h"

using namespace std;

namespace bitmapNS {

Mandelbrot::Mandelbrot() {
    
}

Mandelbrot::~Mandelbrot() {

}

int Mandelbrot::getIterations(double x, double y) { 

    complex<double> z = 0;  // z is used traditionally to represent complex numbers. z is also overloaded in this template class because complex numbers come in format (int, int) so z is now init to (0,0)
    complex<double> c(x, y);

    int iterations = 0;  // this will be the method that will see how many loops we have to do before the above variables start shooting off to infinity

    while (iterations < MAX_ITERATIONS) {

        z = z*z + c;    // z*z squares the complex number within z (follows arthmetic rules of multiplying complex numbers)

        if (abs(z) > 2) {
            break;      // the number of iterations it takes to get to this break point will be mapped to a color
        }

        iterations++;
    }
    return iterations;  // returns the number of iterations to either hit MAX_ITERATIONS or exceed 2
}


} /* namespace bitmapNS */
