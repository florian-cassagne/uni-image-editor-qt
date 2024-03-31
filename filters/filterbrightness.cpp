#include "filters/filterbrightness.h"

FilterBrightness::FilterBrightness(ImageModifier* _imageModifier)
    : Filter(_imageModifier)
{}


void FilterBrightness::execute(int level){

    QImage newImage = imageModifier->getCurrentImage()->copy();

    float levelAdjustement = 128/100;

    for(int i = 0 ; i < imageModifier->getCurrentImage()->width() ; i++){
        for(int j = 0 ; j < imageModifier->getCurrentImage()->height() ; j++){
            QColor currentPixel = imageModifier->getCurrentImage()->pixel(i,j);

            int red = currentPixel.red() + level*levelAdjustement;
            int green = currentPixel.green() + level*levelAdjustement;
            int blue = currentPixel.blue() + level*levelAdjustement;

            red = (red > 255) ? 255 : red ;
            red = (red < 0) ? 0 : red ;
            green = (green > 255) ? 255 : green ;
            green = (green < 0) ? 0 : green ;
            blue = (blue > 255) ? 255 : blue ;
            blue = (blue < 0) ? 0 : blue ;

            QColor newPixelColor = QColor(
                red,
                green,
                blue);
            newImage.setPixelColor(i,j, newPixelColor);
        }
    }

    imageModifier->setCurrentImage(&newImage);
}
