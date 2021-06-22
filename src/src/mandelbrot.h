
#ifndef MANDELBROT_H_
#define MANDELBROT_H_

/* mandelbrot algorithm should except two cooridinates (-1, 1) for x and y
 will ultimately be a loop, that when stable, will complete itself and assign a color
 when unstable, loop will go on forever (will have to write something in to break the loop)
 the loop going on forever will mean it's unstable (will probably assign another colo
*/

namespace bitmapNS { 

class Mandelbrot { 

public:
    static const int MAX_ITERATIONS = 1000; // The higher the maximal number of iterations, the more detail and subtlety emerge in the final image, but the longer time it will take to calculate the fractal image. 

public:
    Mandelbrot();           // constructor 
    virtual ~Mandelbrot(); // deconstructor 

    static int getIterations(double x, double y);

};

} /* namespace bitmapNS */

#endif /* MANDELBROT_H_ */