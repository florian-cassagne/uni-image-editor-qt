#ifndef FILTERHOT_H
#define FILTERHOT_H
#include "filter.h"

class FilterHot
{
public:
    FilterHot(ImageModifier * img);
    void execute() ;
private :
    ImageModifier * img ;
};

#endif // FILTERHOT_H
