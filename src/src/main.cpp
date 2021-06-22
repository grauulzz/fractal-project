#include <iostream>
#include <cstdint>
#include "bitmap.h"
#include "mandelbrot.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
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

			double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;	

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);	// pass in getIterations for whatever cooridnate we are currently on in nested loop

			uint8_t red = (uint8_t)(256 *(double)iterations/Mandelbrot::MAX_ITERATIONS);	// bunch of type "casting" stuff I don't understand

			bitmap.setPixel(x, y, red, red, 0);

			if(yFractal < min) min = yFractal;			
			if(yFractal > max) max = yFractal; 
				
		}
	}

	cout << "min: " << min << "... max: " << max << endl;


	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}