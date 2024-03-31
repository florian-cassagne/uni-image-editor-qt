#ifndef FILTERCOLD_H
#define FILTERCOLD_H
#include "filter.h"

class FilterCold
{
public:
    FilterCold(ImageModifier * img);
    void execute() ;
private :
    ImageModifier * img ;
};

#endif // FILTERCOLD_H
