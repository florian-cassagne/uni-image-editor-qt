#ifndef SETTING_BRIGHTNESS_H
#define SETTING_BRIGHTNESS_H


#include "filter.h"


class FilterBrightness : public Filter
{
public:
    FilterBrightness(ImageModifier* _imageModifier);
    ~FilterBrightness(){};
    void execute(int level);
};

#endif // SETTING_BRIGHTNESS_H
