#ifndef FILTEREXECUTER_H
#define FILTEREXECUTER_H


#include "filters/filtercrop.h"
#include "filters/filterresize.h"
#include "filters/filterblur.h"
#include "filters/filterbrightness.h"
#include "filters/filtercontrast.h"
#include "filters/filtersaturation.h"
#include "filters/filterhot.h"
#include "filters/filtercold.h"
#include "filters/filtergrayscale.h"


class MainWindow;

class FilterExecuter
{
private:
    MainWindow* mainWindow;

public:
    FilterExecuter(MainWindow* mainWindow);

    void executeResize();
    void executeCrop();
    void executeGaussianBlur();
    void executeBasicSettings();

    void executeBrightness();
    void executeContrast();
    void executeSaturation();


    void executeFilterHot();
    void executeFilterCold();
    void executeFilterGrayscale() ;
};

#endif // FILTEREXECUTER_H
