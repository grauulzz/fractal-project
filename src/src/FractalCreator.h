#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "FractalCreator.h"
#include "Zoom.h"
#include "mandelbrot.h"
#include "bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

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
    vector<int> m_ranges;
	vector<RGB> m_colors;
    vector<int> m_rangeTotals;
    bool m_bGotFirstRange{false};
	

private:
    // these methods are private because they are only called in run()
    void calculateIteration(); 
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name); 
    


public:
    // these methods are public becuase they are called from main ... (run() is the beefy method which is used to declutter main as well as run all methods of fractal generation in the correct order)
    FractalCreator(int width, int height);
    void addRange(double rangeEnd, const RGB& rgb); 
    int getRange(int iterations) const;
    void addZoom(const Zoom& zoom);
    virtual ~FractalCreator();
    void run(string name); 

};  

}   /* namespace bitmapNS */

#endif /* FRACTALCREATOR_H_ */  