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
	double min_x = 999999;	
	double max_x = -999999;
	double min_y = 999999;	
	double max_y = -999999;

	// this is the part which basically converts the x and y cooridnates to a range of -1 and 1 respectivly while still preserving the pixels location. (give each pixel a range from -1 to 1) 
	for (int y=0; y<HEIGHT; y++) {	
		for (int x=0; x<WIDTH; x++) {

			double xFractal = (x - WIDTH/3.5) * 3.5/WIDTH;	
			if(xFractal < min_x) min_x = xFractal;		
			if(xFractal > max_x) max_x = xFractal; 

			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;	
			if(yFractal < min_y) min_y = yFractal;			
			if(yFractal > max_y) max_y = yFractal; 
				
		}
	}

	cout << "min_x: " << min_x << "... max_x: " << max_x << endl;
	cout << "min_y: " << min_y << "... max_y: " << max_y << endl;

	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}