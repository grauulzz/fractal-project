
#ifndef MANDELBROT_H_
#define MANDELBROT_H_

/* mandelbrot algorithm should except two cooridinates (-1, 1) for x and y
 will ultimately be a loop, that when stable, will complete itself and assign a color
 when unstable, loop will go on forever (will have to write something in to break the loop)
 the loop going on forever will mean it's unstable (will probably assign another colo
*/

namespace bitmapNS { // will receive a number of iterations of a loop, then use that to figure which color to plot in the pixel

class Mandelbrot { 

public:
    static const int MAX_ITERATIONS = 1000; // can modify this more or less to affect image quality (will take longer to build with more iterations)

public:
    Mandelbrot();           // constructor 
    virtual ~Mandelbrot(); // deconstructor 

    static int getIterations(double x, double y);

};

} /* namespace bitmapNS */

#endif /* MANDELBROT_H_ */