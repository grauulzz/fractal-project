#include <iostream>
#include "FractalCreator.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	int height = 600;
	FractalCreator fractalCreator(800,600); 

	// methods below must be called in this order
	fractalCreator.addZoom(Zoom(364, height - 167, 0.1));
	fractalCreator.addZoom(Zoom(257, height - 95, 0.1));
	fractalCreator.addZoom(Zoom(494, height - 517, 0.1));
	fractalCreator.addZoom(Zoom(387, height - 307, 0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}