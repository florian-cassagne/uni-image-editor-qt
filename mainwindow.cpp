#include "mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QPixmap>
#include <QImage>
#include <QSplitter>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QClipboard>
#include <IOStream>

#include "mainwindow.h"
#include "loadingbox.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setAcceptDrops(true);
    listImgCnt = new ListImageContainer();
    imageModifier = new ImageModifier(this);
    loadingBox = new LoadingBox(this);
    filterExecuter = new FilterExecuter(this);
    displayMenuButtons(false);

    index = 0;
    size = 0;
    connect(this, SIGNAL(doActions(Actions*)), this, SLOT(updateHisto(Actions*)));


//Menu contextuel
    //File
    connect(clickFileOpen,SIGNAL(triggered(bool)), this, SLOT(fileOpen()));
    connect(clickFileSave,SIGNAL(triggered(bool)), this, SLOT(fileSave()));
    connect(clickFileSaveAs,SIGNAL(triggered(bool)), this, SLOT(fileSaveAs()));
    connect(clickFileClose,SIGNAL(triggered(bool)), this, SLOT(fileClose()));
    //Edit
    connect(editUndo,SIGNAL(triggered(bool)), this, SLOT(undo()));
    connect(editRedo,SIGNAL(triggered(bool)), this, SLOT(redo()));

    //Settings
    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(listImgCnt);
    splitter->addWidget(imageModifier);
    imageModifier->setAcceptDrops(true);
    this->setCentralWidget(splitter);
    displayActionDock(false);

    connect(resizeApplyButton, SIGNAL(clicked(bool)), this, SLOT(executeResize()));
    connect(cropApplyButton, SIGNAL(clicked(bool)), this, SLOT(executeCrop()));
    connect(gaussianBlurApplyButton, SIGNAL(clicked(bool)), this, SLOT(executeGaussianBlur()));
    connect(settingsApplyButton, SIGNAL(clicked(bool)), this, SLOT(executeBasicSettings()));
    connect(gaussianBlurApplyButton, SIGNAL(clicked(bool)), this, SLOT(executeGaussianBlur()));
    connect(filterHotButton, SIGNAL(clicked(bool)), this, SLOT(executeFilterHot()));
    connect(filterColdButton, SIGNAL(clicked(bool)), this, SLOT(executeFilterCold()));
    connect(filterGrayButton, SIGNAL(clicked(bool)), this, SLOT(executeFilterGray()));
}


MainWindow::~MainWindow() {}


void MainWindow::menuBarEventSetUp(){

}

void MainWindow::displayActionDock(bool display){
    if(display)
        actionsDock->show();
    else
        actionsDock->hide();
}

void MainWindow::displayLoadingBox(bool display){
    if(display)
        loadingBox->show();
    else
        loadingBox->hide();

}

void MainWindow::displayMenuButtons(bool display){
    if(display){
        editUndo->setEnabled(true);
        editRedo->setEnabled(true);
    }
    else{
        editUndo->setEnabled(false);
        editRedo->setEnabled(false);
    }
}

// Permet de mettre à jour les valeurs des widgets de gestions des filtres lorsqu'une nouvelle image est chargée.
// Par exemple, mettre à jour les valeurs de largeur et hauteur du widget de redimensionnement, afin d'améliorer l'ergonomie
void MainWindow::updateMetrics(){
    resizeWidthSpin->setValue(imageModifier->getImage()->width());
    resizeHeightSpin->setValue(imageModifier->getImage()->height());
    cropWidthSpin->setValue(imageModifier->getImage()->width());
    cropHeightSpin->setValue(imageModifier->getImage()->height());
}


void MainWindow::open(QString fileName) {
    QImage image = QImage(fileName);
    image.setText("path", fileName);
    ImageContainer *ctn = listImgCnt->addContainer(&image);
    this->imgCtn = ctn;
    connect(ctn, SIGNAL(send(ImageContainer*)), this, SLOT(clickOnImageContainer(ImageContainer*)));
    imageModifier->updateImage(&image);
    updateMetrics();
    displayActionDock(true);
    displayMenuButtons(true);
}

void MainWindow::fileOpen(){
    QStringList inputFile = QFileDialog::getOpenFileNames(this, tr("Ouvrir une image"),QDir::currentPath(), nullptr) ;

    if(!inputFile.isEmpty()){
        imageModifier->resetDisplay();
        displayMenuButtons(false);

        QString fileName = inputFile[0] ;
        open(fileName);
    }else{
        std::cerr << "Aucun fichier sélectionné" << std::endl ;
    }
}

void MainWindow::fileSave(){
    if (!this->imageModifier->getCurrentImage()->isNull()) {
        this->imageModifier->getCurrentImage()->save(this->imageModifier->getCurrentImage()->text("path"));
    }
}
void MainWindow::fileSaveAs(){
    if(!this->imageModifier->getCurrentImage()->isNull()){
        QString imagePath = QFileDialog::getSaveFileName(
                    this,
                    tr("Enregistrer sous"),
                    QString(),
                    nullptr
                );
        if(!imagePath.isEmpty()){
            if (!imagePath.contains(".")) {
                imagePath = imagePath + ".png";
            }
            this->imageModifier->getCurrentImage()->save(imagePath) ;
        }
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        open(fileName);
    }
}

void MainWindow::fileClose(){
    close() ;
}


void MainWindow::undo(){
    if (index > 0) {
        index--;
        Actions actions = histo.at(index);
        ImageContainer *ctn = actions.applyOld();
        this->imgCtn = ctn;
        imageModifier->updateImage(imgCtn->getImage());
    }
    updateMetrics();
}

void MainWindow::redo(){
    if (index < size) {
        Actions actions = histo.at(index);
        ImageContainer *ctn = actions.applyNew();
        this->imgCtn = ctn;
        imageModifier->updateImage(imgCtn->getImage());
        index++;
    }
    updateMetrics();
}


void MainWindow::executeResize(){
    filterExecuter->executeResize();
}

void MainWindow::executeCrop(){
    setPreviousImage();
    filterExecuter->executeCrop();
    updateImageContainer();
}

void MainWindow::executeGaussianBlur(){
    setPreviousImage();
    filterExecuter->executeGaussianBlur();
    updateImageContainer();
}

void MainWindow::executeBasicSettings(){
    setPreviousImage();
    filterExecuter->executeBasicSettings();
    updateImageContainer();
}

void MainWindow::executeFilterHot(){
    setPreviousImage();
    filterExecuter->executeFilterHot();
    updateImageContainer();
}

void MainWindow::executeFilterCold(){
    setPreviousImage();
    filterExecuter->executeFilterCold();
    updateImageContainer();
}

void MainWindow::executeFilterGray(){
    setPreviousImage();
    filterExecuter->executeFilterGrayscale();
    updateImageContainer();
}

void MainWindow::clickOnImageContainer(ImageContainer *imageContainer) {
    this->imgCtn = imageContainer;
    imageModifier->updateImage(imgCtn->getImage());
    updateMetrics();
}

void MainWindow::updateHisto(Actions * actions){
    histo = histo.sliced(0, index);
    histo.append(*actions);
    if (size == sizeMax) {
        histo.removeFirst();
    }
    else {
        index++;
        size = index;
    }
}


void MainWindow::updateImageContainer() {
    imgCtn->setImage(imageModifier->getImage());
    Actions *actions = new Actions();
    Action *action = new Action(imgCtn, previousImage, imageModifier->getCurrentImage()->copy());
    actions->addAction(action);
    emit doActions(actions);
}
