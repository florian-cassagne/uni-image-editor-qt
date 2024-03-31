#include "filtergrayscale.h"
#include <math.h>

FilterGrayscale::FilterGrayscale(ImageModifier* image) {this->img = image ;}

void FilterGrayscale::execute(){
    QImage buffer_img = img->getImage()->copy() ;
    int gray ;
    QColor color() ;

    for(int x = 0 ; x < buffer_img.width() ; x++){
        for (int y = 0 ; y < buffer_img.height(); y++){

            QColor currentPixel = img->getImage()->pixel(x,y);

            gray = currentPixel.red()*0.2125 + currentPixel.green()*0.7154 + currentPixel.blue()*0.0721 ;
            gray = (gray>255) ?  255 : gray ;

            buffer_img.setPixelColor(x,y,QColor(gray,gray,gray)) ;
        }
    }
    img->setCurrentImage(&buffer_img) ;
}
