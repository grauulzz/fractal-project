#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"

using namespace std;
namespace bitmapNS {

class FractalCreator {

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void calculateIteration(); 
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name); 

};  

}   /* namespace bitmapNS */

#endif /* FRACTALCREATOR_H_ */  