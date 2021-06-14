
#include <fstream>
#include "bitmap.h"
#include "bitmapInfoHeader.h"
#include "bitmapFileHeader.h"

using namespace bitmapNS;
using namespace std;

namespace bitmapNS {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {
    /* Bitmap::Bitmap constructor notes
    m_pPixels is going to be used to create a "memmory block" that represents the whole screen (in memmory)
    The "new" operator does both the allocation and the initialization, whereas without it, uint8_t() would be initialized but not allocated
    '{}' initalizes the memory of uint8_t[width*height*3] to all zeros for each value (included to minimize bugs and set a clean initialization)*/

}

bool Bitmap::write(string filename) {
    /* Bitmap::write constructor notes

    This constructor will write "bitmapFileHeader.h", "bitmapInfoHeader.h", and all bitmap data to a file

    first arg in .write() must be a char star ptr because it has to know where to look in memory in order to write the file
    second arg needs to say how many bytes we are going to write

    ios::out "|" means flag, as ios::binary (might be default in ofstream but idfk) */

    bitmapFileHeader fileHeader;
    bitmapInfoHeader infoHeader;

    fileHeader.bmpFileSize = sizeof(bitmapFileHeader) + sizeof(bitmapInfoHeader) + m_width*m_height*3;
    fileHeader.pixelDataOffset = sizeof(bitmapFileHeader) + sizeof(bitmapInfoHeader); // tells whatever the image is opened in where to start looking for bitmap data (where bitmap data is immediately located)

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(filename, ios::out|ios::binary);

    if(!file) { 
        return false; // if file cannot open, returns false to bool Bitmap::write
    }
 
    file.write((char *)&fileHeader, sizeof(fileHeader)); 
    file.write((char *)&infoHeader, sizeof(infoHeader)); 
    file.write((char *)m_pPixels.get(), m_width*m_height*3); // the .get() method in this apparently is nesseary to "get" the raw (or normal ptr (not unique ptr)) pointer of m_pPixels unique_ptr declared in bitmap.h

    file.close(); 

    if(!file) { 
        return false;
    }

    return true;
    
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    /* setPixel notes
    
    int x, int y ... used to store cordinates of a pixel

    uint8_t red, uint8_t green, uint8_t blue ... 1 byte of information initialized fom red, green, blue of that particular pixel (as specified by x & y)

    */

   uint8_t *pPixel = m_pPixels.get(); 
   /* pPixel notes... 

    The *pPixel pointer has to use .get() (method of unique ptr) in order to access underlying memeory managed by m_pPixels (declared in Bitmap::bitmap 's methods)
        Unique pointers require .get() to access the smart pointer's memmory

    We need this because we want to be able to move *pPixel to point to the correct pixel *using pointer arithmetic...
        https://www.tutorialspoint.com/cplusplus/cpp_pointer_arithmatic.htm
   
    


   */

}
Bitmap::~Bitmap() {
    // destrcutor (probably wont use)
}

} /* namespace bitmapNS */