#ifndef FILTERRESIZE_H
#define FILTERRESIZE_H

#include "filter.h"


class FilterResize : public Filter
{
public:
    FilterResize(ImageModifier* _imageModifier);
    void execute(int width, int height);
    void execute(int width);
    ~FilterResize(){};
};

#endif // FILTERRESIZE_H
