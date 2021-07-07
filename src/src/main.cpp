#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace bitmapNS;

int main() {
	
	FractalCreator fractalCreator(800,600); 

	fractalCreator.addRange(0.0, RGB(0, 0, 0));		  	   // range based color assignment
	fractalCreator.addRange(0.3, RGB(255, 0, 0));		  // first range 
	fractalCreator.addRange(0.5, RGB(0, 255, 0));		 // second 
	fractalCreator.addRange(0.8, RGB(0, 0, 255));		// etc ...
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.addZoom(Zoom(364, 167, 0.1));
	fractalCreator.addZoom(Zoom(257, 95, 0.1));
	fractalCreator.addZoom(Zoom(494, 517, 0.1));
	fractalCreator.addZoom(Zoom(387, 307, 0.1));

	fractalCreator.run("writeBitmapFileTest.bmp");

	cout << "finished" << endl;

}