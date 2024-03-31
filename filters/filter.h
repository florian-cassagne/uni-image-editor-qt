#ifndef FILTER_H
#define FILTER_H


#include "imagemodifier.h"


class Filter
{
protected:
    ImageModifier* imageModifier;

public:
    Filter(ImageModifier* _imageModifier) : imageModifier(_imageModifier){};
    ~Filter(){ imageModifier = nullptr; };

    inline ImageModifier* getImageModifier() { return imageModifier; };
};

#endif // FILTER_H
