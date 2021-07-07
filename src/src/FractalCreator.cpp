#include "FractalCreator.h"
#include <assert.h>

using namespace std;

namespace bitmapNS {

void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {	

	m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}

	m_bGotFirstRange = true; 

}	// should add color based off number of iterations within a given range (called from main) both rangeEnd and rgb should be stored in vectors

int FractalCreator::getRange(int iterations) const {
	int range = 0;

	for (int i=1; i < m_ranges.size(); i++) {

		range = i; 

		if (m_ranges[i] > iterations) {
			break;
		}
	}

	range--;

	assert(range > -1); // assert is for running in debug mode in this case, it'll crash if we try and index outside of vector
	assert(range < m_ranges.size());

	return range;
}

void FractalCreator::addZoom(const Zoom& zoom) { 
    m_zoomList.add(zoom);
}

void FractalCreator::run(string name) {

	// methods below must be called in this order
	calculateIteration();
	calculateTotalIterations();
	drawFractal();
	writeBitmap("test.bmp"); 

}

FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 }), m_fractal(new int[m_width*m_height]{ 0 }), m_bitmap(m_width, m_height), m_zoomList(m_width, m_height) {
    m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

FractalCreator::~FractalCreator() {}

void FractalCreator::calculateIteration() {

    for (int y=0; y<m_height; y++) {	
		for (int x=0; x<m_width; x++) {

			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);	

			m_fractal[y*m_width+x] = iterations;	

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;
			}						
		}
	}   // [nested loop1]; (1) scaleing x and y cooridnates... (2) storing number of iterations per pixal... (3) bulding the m_histogram
}

void FractalCreator::calculateTotalIterations() {
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}
}

void FractalCreator::drawFractal() {
	RGB startColor(0, 0, 128);	
	RGB endColor(255, 128, 255);	
	RGB colorDiff = endColor - startColor; 

    for (int y=0; y<m_height; y++) {
		for (int x=0; x<m_width; x++) {

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			int iterations = m_fractal[y*m_width+x];	


			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue = 0.0;

				for (int i=0; i <= iterations; i++) {
					hue += ((double) m_histogram[i]) / m_total;
				}   // colors the historgram

				red = pow(startColor.r + colorDiff.r, hue);
				green = pow(startColor.g + colorDiff.g, hue);
				blue = pow(startColor.b + colorDiff.b, hue);

				// red = startColor.r + colorDiff.r*hue;
				// green = startColor.g + colorDiff.g*hue;
				// blue = startColor.b + colorDiff.b*hue;
                
				// green=pow(255, hue);	// pixels that have more iterations have brighter colors	
				// green = hue * 255;
			}
			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}	// [nested loop2]; calculates color over the given number of iterations
}

void FractalCreator::writeBitmap(string name) {
    m_bitmap.write(name);
}

}   /* namespace bitmapNS */