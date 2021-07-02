#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

namespace bitmapNS {

class ZoomList {

private:
    int m_width{0};     // resolution of screen
    int m_height{0};

public:
    ZoomList(int width, int height);

};
}   /* bitmapNS */


#endif /* ZOOMLIST_H_ */