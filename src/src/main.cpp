#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "bitmap.h"
#include "mandelbrot.h"
#include "ZoomList.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	int const WIDTH = 800;	// uppercase because const 
	int const HEIGHT = 600;	// reason for these two is it saves us from having to re write the value over and over which is bad practice

	Bitmap bitmap(WIDTH, HEIGHT); 

	// double min = 999999;	// declartion of min and max left in, but not currently being called in anyway at the moment
	// double max = -999999;

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 1));	// add a zoom to Zoomlist class

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });	
		// creating histogram  (keeps track of each pixels amount of iterations) https://en.wikipedia.org/wiki/Histogram

	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{ 0 });
		// storing histogram (creates a database of iterations per pixals so we can access them later)

	for (int y=0; y<HEIGHT; y++) {	
		for (int x=0; x<WIDTH; x++) {
			double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;	// scaling part which basically converts the x and y cooridnates to a range of -1 and 1 respectivly while still preserving the pixels location. (give each pixel a range from -1 to 1) 
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;	
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);	// passes in getIterations for whatever cooridnate we are currently on in nested loop
			fractal[y*WIDTH+x] = iterations;	// this is a calculation of how fractal will parse through the iterations stored in the histogram. reads values starting bottom left working it's way up by 1 column with each completed row
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
				// if statement above saves us from writting into memory that is unallocated
			}						
		}
	}	// [nested loop1]; (1) scaleing x and y cooridnates... (2) storing number of iterations per pixal... (3) bulding the histogram


	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for (int y=0; y<HEIGHT; y++) {
		for (int x=0; x<WIDTH; x++) {

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			int iterations = fractal[y*WIDTH+x];	


			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue = 0.0;

				for (int i=0; i <= iterations; i++) {
					hue += ((double) histogram[i]) / total;
				}	// colors the historgram

				green=pow(255, hue);	// pixels that have more iterations have brighter colors	
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}	// [nested loop2]; calculates color over the given number of iterations 


	/* code listed below displays an output to get a visual feel for what the histogram is actually doing (should work as is if uncommented)
	int count;
	for (int i=0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		cout << histogram[i] << " " << flush;
		count += histogram[i];
	}
	cout << endl;

	cout << count << "; " << WIDTH*HEIGHT << endl;

	cout << "min: " << min << "... max: " << max << endl;
	*/


	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}