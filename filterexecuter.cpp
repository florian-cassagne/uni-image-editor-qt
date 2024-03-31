#include "filterexecuter.h"
#include "mainwindow.h"

FilterExecuter::FilterExecuter(MainWindow* _mainWindow)
    : mainWindow(_mainWindow)
{}


void FilterExecuter::executeResize(){
    mainWindow->displayLoadingBox(true);
    FilterResize filterResize = FilterResize(mainWindow->getImageModifier());
    filterResize.execute(mainWindow->resizeWidthSpin->value(),
                         mainWindow->resizeHeightSpin->value());
    mainWindow->displayLoadingBox(false);
    mainWindow->updateMetrics();

}

void FilterExecuter::executeCrop(){
    mainWindow->displayLoadingBox(true);
    FilterCrop filterCrop = FilterCrop(mainWindow->getImageModifier());
    switch (mainWindow->cropAnchorBox->currentIndex()) {
    case 0:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::TOP_LEFT);
        break;
    case 1:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::TOP);
        break;
    case 2:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::TOP_RIGHT);
        break;
    case 3:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::MIDDLE_LEFT);
        break;
    case 5:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::MIDDLE_RIGHT);
        break;
    case 6:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::BOTTOM_LEFT);
        break;
    case 7:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::BOTTOM);
        break;
    case 8:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::BOTTOM_RIGHT);
        break;
    default:
        filterCrop.crop(mainWindow->cropWidthSpin->value(),
                        mainWindow->cropHeightSpin->value(),
                        Anchor::MIDDLE);
        break;
    }
    mainWindow->displayLoadingBox(false);
    mainWindow->updateMetrics();
}


void FilterExecuter::executeGaussianBlur(){
    mainWindow->displayLoadingBox(true);
    BlurLevel blurLevel;
    switch (mainWindow->gaussianBlurLevelBox->currentIndex()) {
    case 1:
        blurLevel = X5;
        break;
    case 2:
        blurLevel = X7;
        break;
    case 3:
        blurLevel = X9;
        break;
    case 4:
        blurLevel = X11;
        break;
    case 5:
        blurLevel = X13;
        break;
    case 6:
        blurLevel = X15;
        break;
    default:
        blurLevel = X3;
        break;
    }
    FilterBlur gaussianBlur = FilterBlur(mainWindow->getImageModifier(), blurLevel);
    gaussianBlur.execute();
    mainWindow->displayLoadingBox(false);
    mainWindow->updateMetrics();
}


void FilterExecuter::executeBasicSettings(){
    mainWindow->displayLoadingBox(true);
    executeBrightness();
    executeContrast();
    executeSaturation();
    mainWindow->settingsBrightnessSpin->setValue(0);
    mainWindow->settingsContrastSpin->setValue(0);
    mainWindow->settingsSaturationSpin->setValue(0);
    mainWindow->displayLoadingBox(false);
}


void FilterExecuter::executeBrightness(){
    FilterBrightness filter = FilterBrightness(mainWindow->getImageModifier());
    filter.execute(mainWindow->settingsBrightnessSpin->value());
}


void FilterExecuter::executeContrast(){
    FilterContrast filter = FilterContrast(mainWindow->getImageModifier());
    filter.execute(mainWindow->settingsContrastSpin->value());
}


void FilterExecuter::executeSaturation(){
    FilterSaturation filter = FilterSaturation(mainWindow->getImageModifier());
    filter.execute(mainWindow->settingsSaturationSpin->value());
}

void FilterExecuter::executeFilterHot(){
    FilterHot filter = FilterHot(mainWindow->getImageModifier());
    filter.execute();
}

void FilterExecuter::executeFilterCold(){
    FilterCold filter = FilterCold(mainWindow->getImageModifier());
    filter.execute();
}

void FilterExecuter::executeFilterGrayscale(){
    FilterGrayscale filter = FilterGrayscale(mainWindow->getImageModifier()) ;
    filter.execute() ;
}
