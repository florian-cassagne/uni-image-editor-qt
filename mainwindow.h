#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "listimagecontainer.h"
#include "imagemodifier.h"
#include "loadingbox.h"
#include "filterexecuter.h"
#include "actions.h"

#include <QMainWindow>


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

private:
    enum actionOnFile{
        OPEN,
        CLOSE,
        SAVE,
        SAVE_AS
    } ;


    ListImageContainer *listImgCnt;
    ImageModifier *imageModifier;
    LoadingBox* loadingBox;
    FilterExecuter* filterExecuter;

    QImage* currentImage;
    void open(QString filename);

    ImageContainer * imgCtn;
    const int sizeMax = 10;
    int size = 0;
    int index = 0;
    QList<Actions> histo;
    QImage previousImage;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void menuBarEventSetUp();
    void updateMetrics();

    void displayActionDock(bool display);
    void displayLoadingBox(bool display);
    void displayMenuButtons(bool display);

    inline ImageModifier* getImageModifier(){ return imageModifier;}
    inline void setPreviousImage(){ previousImage = imageModifier->getCurrentImage()->copy(); }


signals:
    void doActions(Actions*);

public slots :
    void fileOpen();
    void fileSave();
    void fileSaveAs();
    void fileClose();

    void undo();
    void redo();
    void updateHisto(Actions * actions);
    void clickOnImageContainer(ImageContainer* imageContainer);
    void updateImageContainer();

    void executeResize();
    void executeCrop();
    void executeGaussianBlur();
    void executeBasicSettings();
    void executeFilterHot();
    void executeFilterCold();
    void executeFilterGray();


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;


};
#endif // MAINWINDOW_H
