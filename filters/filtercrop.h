#ifndef FILTERCROP_H
#define FILTERCROP_H

#include "filter.h"
#include "enum/anchor.cpp"



class FilterCrop : public Filter
{

public:
    FilterCrop(ImageModifier* _imageModifier);
    void crop(int width, int height, Anchor anchor = MIDDLE);
    ~FilterCrop(){};
};

#endif // FILTERCROP_H
