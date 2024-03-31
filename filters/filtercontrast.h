#ifndef FILTERCONTRAST_H
#define FILTERCONTRAST_H


#include "filter.h"


class FilterContrast : public Filter
{
public:
    FilterContrast(ImageModifier* _imageModifier);
    ~FilterContrast(){};
    void execute(int level);
};

#endif // FILTERCONTRAST_H
