#include "filtercontrast.h"

FilterContrast::FilterContrast(ImageModifier* _imageModifier)
    : Filter(_imageModifier)
{}


void FilterContrast::execute(int level){
    QImage newImage = imageModifier->getCurrentImage()->copy();

    float levelAdjustement = 128/100;
    float levelAdjusted = levelAdjustement*level/100 + 1;

    for(int i = 0 ; i < imageModifier->getCurrentImage()->width() ; i++){
        for(int j = 0 ; j < imageModifier->getCurrentImage()->height() ; j++){

            QColor currentPixel = imageModifier->getCurrentImage()->pixel(i,j);

            int red = levelAdjusted*(currentPixel.red() - 128) + 128;
            int green = levelAdjusted*(currentPixel.green() - 128) + 128;
            int blue = levelAdjusted*(currentPixel.blue() - 128) + 128;

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
