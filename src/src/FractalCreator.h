#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "FractalCreator.h"
#include "Zoom.h"
#include "mandelbrot.h"
#include "bitmap.h"
#include "ZoomList.h"

using namespace std;
namespace bitmapNS {

class FractalCreator {
private:

    int m_width;
    int m_height;

    unique_ptr<int[]> m_histogram;	// creating m_histogram  (keeps track of each pixels amount of iterations)
	unique_ptr<int[]> m_fractal;    // storing m_histogram (creates a database of iterations per pixals so we can access them later)

    Bitmap m_bitmap;

    ZoomList m_zoomList;

    int m_total{0};
		
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void calculateIteration(); 
    void calculateTotalIterations();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name); 

};  

}   /* namespace bitmapNS */

#endif /* FRACTALCREATOR_H_ */  