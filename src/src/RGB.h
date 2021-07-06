#ifndef RGB_H_
#define RGB_H_ 

namespace bitmapNS {
struct RGB {
private:
    double r;
    double g;
    double b;

public:
    RGB();
    virtual ~RGB();
};

}   /* bitmapNS */   

#endif /* RGB_H_ */