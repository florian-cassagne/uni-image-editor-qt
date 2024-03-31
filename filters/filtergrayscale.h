#ifndef FILTERGRAYSCALE_H
#define FILTERGRAYSCALE_H
#include "filter.h"
#include <math.h>

class FilterGrayscale
{
public:
    FilterGrayscale(ImageModifier * img);
    void execute() ;
private :
    ImageModifier * img ;
};

#endif // FILTERGRAYSCALE_H
