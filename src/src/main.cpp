#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"


// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	FractalCreator fractalCreator(800,600); 

	fractalCreator.addRange(0.0, RGB(0, 0, 0));		  	   // range based color assignment
	fractalCreator.addRange(0.3, RGB(255, 0, 0));		  // first range 
	fractalCreator.addRange(0.5, RGB(0, 255, 0));		 // second 
	fractalCreator.addRange(0.8, RGB(0, 0, 255));		// etc ...
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	// cout << fractalCreator.getRange(200) << endl;	// check range index values
	// cout << fractalCreator.getRange(400) << endl;	

	// next we need to determine how many pixels are contained within each range

	fractalCreator.addZoom(Zoom(364, 167, 0.1));
	fractalCreator.addZoom(Zoom(257, 95, 0.1));
	fractalCreator.addZoom(Zoom(494, 517, 0.1));
	fractalCreator.addZoom(Zoom(387, 307, 0.1));

	fractalCreator.run("test.bmp");

	cout << "finished" << endl;

}