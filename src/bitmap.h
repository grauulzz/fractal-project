
#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>
using namespace std;

namespace bitmapNS {

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr}; // declaration of unique pointer m_pPixels. m_pPixels will be used to represent entire (800x600) worth of pixels in memmory 

public:
    Bitmap(int width, int height); // this constructor will allow values to pass into whenevr bitmap obj is created

    bool write(string filename);  //  writes the bitmap data into whatever filename (bool because writing files are error prone, so we need it to return false if it can't be exicuted)

    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);  // should allow the assginment of color to a pixel

    virtual ~Bitmap(); 
};

} /*namespace bitmapNS */

#endif /* BITMAP_H_ */



/* notes

    .h files typically contain declarations, while the .cpp files (of the same name) conatain initializations

    upshot...
    1) allocate enough memmory for all information (pixel, colors, etc..)
    2) set the pixel information in memmory
    3) write to a file

    in unique_ptr .... [](arrybrackets) unique pointer to avoid making a destructor (normal pointers require a destructor to delete the memmory with an array form of delete)

*/