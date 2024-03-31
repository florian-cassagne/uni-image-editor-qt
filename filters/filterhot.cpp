#include "filterhot.h"

FilterHot::FilterHot(ImageModifier* image) {this->img = image ;}

void FilterHot::execute(){
    QImage buffer_img = img->getCurrentImage()->copy() ;
    QRgb green ;
    QRgb blue ;
    QRgb red ;
    QColor color() ;

    for(int x = 0 ; x < buffer_img.width() ; x++){
        for (int y = 0 ; y < buffer_img.height(); y++){

            QColor currentPixel = img->getCurrentImage()->pixel(x,y);
            green = currentPixel.green()*0.9 ;

            blue = currentPixel.blue()*0.9 ;

            red = currentPixel.red() ;
            red = red * 1.2 ;
            red = (red >255) ? 255 : red ;

            QColor newColor = QColor(red,green,blue) ;
            buffer_img.setPixelColor(x,y,newColor) ;
        }
    }
    img->setCurrentImage(&buffer_img) ;
}
