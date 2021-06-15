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

	// bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);	// sets a white pixel in the middle of screen https://jonasjacek.github.io/colors/

	for (int y=0; y<HEIGHT; y++) {
		for (int x=0; x<WIDTH; x++) {
			bitmap.setPixel(x, y, 255, 0, 0);	// (https://jonasjacek.github.io/colors/) (https://en.wikipedia.org/wiki/RGBA_color_model)
		}
	}

	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}