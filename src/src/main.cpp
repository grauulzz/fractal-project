#include <iostream>
#include <cstdint>
#include <memory>
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

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});	// histogram array   

	for (int y=0; y<HEIGHT; y++) {	
		for (int x=0; x<WIDTH; x++) {

			double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;	// this is the part which basically converts the x and y cooridnates to a range of -1 and 1 respectivly while still preserving the pixels location. (give each pixel a range from -1 to 1) 
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;	

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);	// passes in getIterations for whatever cooridnate we are currently on in nested loop

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}	// saves us from writting into memory that is unallocated

			uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);	// bunch of type "casting" stuff I don't understand

			color = color*color*color;				// increases density of green 	
			bitmap.setPixel(x, y, 0, color, 0);		// green


			if(color < min) min = color;			
			if(color > max) max = color; 
				
		}
	}

	int count;
	for (int i=0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		cout << histogram[i] << " " << flush;
		count += histogram[i];
	}

	cout << endl;

	cout << count << "; " << WIDTH*HEIGHT << endl;	// checks to see if histogram equals the same as total pixels (also shows each array value when iterating through histogram)

	cout << "min: " << min << "... max: " << max << endl;

	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}