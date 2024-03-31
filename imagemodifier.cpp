#include "imagemodifier.h"

#include <QMouseEvent>

ImageModifier::ImageModifier(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    image = nullptr;
    currentImage = nullptr;
    scene = new QGraphicsScene();
    imageView->show();
}


void ImageModifier::setCurrentImage(QImage *image) {
    updateImage(image);
}

void ImageModifier::updateDisplay(QImage* _image){
    QPixmap pixmap = QPixmap::fromImage(*_image);
    image = new QImage(*_image);
    currentImage = new QImage(*_image);
    scene = new QGraphicsScene();
    scene->addPixmap(pixmap);
    imageView->setScene(scene);
    imageView->show();
}

void ImageModifier::updateImage(QImage *_image) {
    QPixmap pixmap = QPixmap::fromImage(*_image);
    scene->clear();
    scene->addPixmap(pixmap);
    image = new QImage(*_image);
    currentImage = new QImage(*_image);
    imageView->setScene(scene);
}


