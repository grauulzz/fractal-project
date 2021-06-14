#include <iostream>
#include "bitmap.h"

// program should write a fractal image to a bitmap file

using namespace std;
using namespace bitmapNS;

int main()
{
	//  create an object of class Bitmap, declared in bitmap.h (java style declaration where object is the same name as class but lowercase eg.. Bitmap bitmap())

	Bitmap bitmap(800, 600); // standard resolution
	bitmap.write("writeBitmapFileTest.bmp"); 

	cout << "finished" << endl;

}