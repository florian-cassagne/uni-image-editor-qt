#include "filters/filterblur.h"

FilterBlur::FilterBlur(ImageModifier* _imageModifier, BlurLevel _level)
    : Filter(_imageModifier), level(_level)
{}


QColor FilterBlur::getUpdatedPixelRGB(int i, int j){
    int usedNeighborPixels = 0;
    int sumRValueNeighbors = 0;
    int sumGValueNeighbors = 0;
    int sumBValueNeighbors = 0;
    int sumAValueNeighbors = 0;


    for(int neighborPixelW = -level ; neighborPixelW <= level ; neighborPixelW++ ){
        for(int neighborPixelH = -level ; neighborPixelH <= level ; neighborPixelH++ ){
            if(((i+neighborPixelW) >= 0) &&
                    ((i+neighborPixelW) < imageModifier->getCurrentImage()->width()) &&
                    ((j+neighborPixelH) >= 0) &&
                    ((j+neighborPixelH) < imageModifier->getCurrentImage()->height()))
            {
                usedNeighborPixels++;
                QColor currentPixel = imageModifier->getCurrentImage()->pixel(i+neighborPixelW, j+neighborPixelH);
                sumRValueNeighbors += currentPixel.red();
                sumGValueNeighbors += currentPixel.green();
                sumBValueNeighbors += currentPixel.blue();
                sumAValueNeighbors += currentPixel.alpha();
            }
        }
    }

    QColor currentPixel = imageModifier->getCurrentImage()->pixel(i, j);
    QColor newPixelColor = QColor(sumRValueNeighbors/usedNeighborPixels,
                                  sumGValueNeighbors/usedNeighborPixels,
                                  sumBValueNeighbors/usedNeighborPixels,
                                  sumAValueNeighbors/usedNeighborPixels);
    return newPixelColor;
}


// TODO : Gérer images grises, et pour autres formats que RGB
void FilterBlur::execute(){
    QImage newImage = imageModifier->getCurrentImage()->copy();
    for(int i = 0 ; i < imageModifier->getCurrentImage()->width() ; i++){
        for(int j = 0 ; j < imageModifier->getCurrentImage()->height() ; j++){
            newImage.setPixelColor(i,j, getUpdatedPixelRGB(i, j));
        }
    }

    imageModifier->setCurrentImage(&newImage);
}




