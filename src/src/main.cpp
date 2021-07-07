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

	fractalCreator.addZoom(Zoom(364, 167, 0.1));
	fractalCreator.addZoom(Zoom(257, 95, 0.1));
	fractalCreator.addZoom(Zoom(494, 517, 0.1));
	fractalCreator.addZoom(Zoom(387, 307, 0.1));

	fractalCreator.run("test.bmp");

	cout << "finished" << endl;

}