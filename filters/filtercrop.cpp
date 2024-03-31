#include "filters/filtercrop.h"


FilterCrop::FilterCrop(ImageModifier* _imageModifier)
    : Filter(_imageModifier)
{}


void FilterCrop::crop(int width, int height, Anchor anchor){
    imageModifier->resetDisplay();

    QImage newImage;

    switch (anchor) {
    case TOP_LEFT:
        newImage = imageModifier->getCurrentImage()->
                copy(0, 0, width, height);
        break;
    case TOP:
        newImage = imageModifier->getCurrentImage()->
                copy((imageModifier->getCurrentImage()->width()-width)/2, 0, width, height);
        break;
    case TOP_RIGHT:
        newImage = imageModifier->getCurrentImage()->
                copy(imageModifier->getCurrentImage()->width()-width, 0, width, height);
        break;
    case MIDDLE_LEFT:
        newImage = imageModifier->getCurrentImage()->
                copy(0, (imageModifier->getCurrentImage()->height()-height)/2, width, height);
        break;
    case MIDDLE_RIGHT:
        newImage = imageModifier->getCurrentImage()->
                copy(imageModifier->getCurrentImage()->width()-width, (imageModifier->getCurrentImage()->height()-height)/2, width, height);
        break;
    case BOTTOM_LEFT:
        newImage = imageModifier->getCurrentImage()->
                copy(0, imageModifier->getCurrentImage()->height()-height, width, height);
        break;
    case BOTTOM:
        newImage = imageModifier->getCurrentImage()->
                copy((imageModifier->getCurrentImage()->width()-width)/2, imageModifier->getCurrentImage()->height()-height, width, height);
        break;
    case BOTTOM_RIGHT:
        newImage = imageModifier->getCurrentImage()->
                copy(imageModifier->getCurrentImage()->width()-width, imageModifier->getCurrentImage()->height()-height, width, height);
        break;
    default:
        newImage = imageModifier->getCurrentImage()->
                copy((imageModifier->getCurrentImage()->width()-width)/2, (imageModifier->getCurrentImage()->height()-height)/2, width, height);
        break;
    }

    imageModifier->updateDisplay(&newImage);
}
