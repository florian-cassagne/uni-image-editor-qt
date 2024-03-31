#include "filters/filterresize.h"

FilterResize::FilterResize(ImageModifier* _imageModifier)
    : Filter(_imageModifier)
{}


// Redimensionnement largeur et hauteur indépendante
void FilterResize::execute(int width, int height){
    imageModifier->resetDisplay();
    QImage newImage = imageModifier->getCurrentImage()->scaled(width, height);
    imageModifier->updateDisplay(&newImage);
}


// Redimensionnement largeur uniquement. La hauteur s'adapte selon la largeur afin de conserver le ratio largeur/hauteur initial.
void FilterResize::execute(int width){
    imageModifier->resetDisplay();
    QImage newImage = imageModifier->getCurrentImage()->scaledToWidth(width);
    imageModifier->updateDisplay(&newImage);
}
