#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	FractalCreator fractalCreator(800,600); 

	fractalCreator.run("writeBitmapFileTest1.bmp");

	cout << "finished" << endl;

}