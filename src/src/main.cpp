#include <iostream>
#include "bitmap.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	//  create an object of class Bitmap, declared in bitmap.h (java style declaration where object is the same name as class but lowercase eg.. Bitmap bitmap())
	int const WIDTH = 800;	// uppercase because const 
	int const HEIGHT = 600;	// reason for these two is it saves us from having to re write the value over and over which is bad practice
	Bitmap bitmap(WIDTH, HEIGHT); 

	// this bit is the hacky part which is needed to see the fractal onscreen as we write it
	// the fractal algorithm excepts cooridinates x and y to range from -1 to 1 
	double min = 999999;	
	double max = -999999;

	// this is the part which basically converts the x and y cooridnates to a range of -1 and 1 respectivly while still preserving the pixels location. (give each pixel a range from -1 to 1) 
	for (int y=0; y<HEIGHT; y++) {	
		for (int x=0; x<WIDTH; x++) {
			double xFractal = (x - WIDTH/2) * 2.0/WIDTH;	// taking x and offseting it by respective width/2 of step in for loop (so if loop starts at 0, this would mean 0 - 800/2=400)
															// then multiple 400 * 2/400 = 2 (which is exactly what we want, 2 values for -1, and 1 respectivly for current position of pixel)
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;	// exactly the same for y...

			if(xFractal < min) min = xFractal;				// from the first pass of the the loop... xFractal would currently be set to 2 so min gets updated to 2
			if(xFractal > max) max = xFractal; 
				
		}
	}

	cout << min << ", " << max << endl;

	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}