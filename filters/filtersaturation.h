#ifndef SETTINGSATURATION_H
#define SETTINGSATURATION_H


#include "filter.h"


class FilterSaturation : public Filter
{
public:
    FilterSaturation(ImageModifier* _imageModifier);
    ~FilterSaturation(){};
    void execute(int level);
};

#endif // SETTINGSATURATION_H
