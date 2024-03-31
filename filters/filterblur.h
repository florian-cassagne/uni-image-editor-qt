#ifndef FILTERGAUSSIANBLUR_H
#define FILTERGAUSSIANBLUR_H

#include "filter.h"
#include "enum/blurlevel.cpp"



class FilterBlur : public Filter
{
private:
    BlurLevel level;

public:
    FilterBlur(ImageModifier* _imageModifier, BlurLevel level = X3);
    ~FilterBlur(){}

    void execute();

    QColor getUpdatedPixelRGB(int i, int j);
};

#endif // FILTERGAUSSIANBLUR_H
