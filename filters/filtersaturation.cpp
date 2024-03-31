#include "filters/filtersaturation.h"


FilterSaturation::FilterSaturation(ImageModifier* _imageModifier)
    : Filter(_imageModifier)
{}

void FilterSaturation::execute(int level){

    QImage newImage = imageModifier->getCurrentImage()->copy();

    float levelAdjustement = 1 + (float)level/100;

    for(int i = 0 ; i < imageModifier->getCurrentImage()->width() ; i++){
        for(int j = 0 ; j < imageModifier->getCurrentImage()->height() ; j++){

            QColor currentPixel = imageModifier->getCurrentImage()->pixel(i,j);

            float newSaturationValue = currentPixel.saturation() * levelAdjustement;
            int newSaturationValueInt = newSaturationValue;

            newSaturationValueInt = (newSaturationValueInt > 255) ? 255 : newSaturationValueInt;
            newSaturationValueInt = (newSaturationValueInt < 0) ? 0 : newSaturationValueInt;

            currentPixel.setHsv(
                currentPixel.hue(),
                newSaturationValueInt,
                currentPixel.value()
            );

            newImage.setPixelColor(i,j, currentPixel);
        }
    }

    imageModifier->setCurrentImage(&newImage);
}
