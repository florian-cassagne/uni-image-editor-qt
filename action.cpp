#include "action.h"

Action::Action(ImageContainer * affectedImage, QImage oldImage, QImage newImage)
{
    this->affectedImage = affectedImage;
    this->oldImage = oldImage;
    this->newImage = newImage;
}

void Action::applyNew() {
    this->affectedImage->setImage(&newImage);
}

void Action::applyOld() {
    this->affectedImage->setImage(&oldImage);
}
