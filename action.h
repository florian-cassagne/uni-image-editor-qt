#ifndef ACTION_H
#define ACTION_H

#include "imagecontainer.h"

class Action
{
public:
    Action(ImageContainer* affectedImage, QImage oldImage, QImage newImage);
    void applyNew();
    void applyOld();

    ImageContainer* affectedImage;

private:
    QImage newImage;
    QImage oldImage;

};

#endif // ACTION_H
