#include "imagecontainer.h"
#include <QDebug>
#include <QSize>

ImageContainer::ImageContainer(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    label->setScaledContents(true);
}

void ImageContainer::setImage(QImage *image) {
    this->image = *image;
    label->setPixmap(QPixmap::fromImage(this->image.scaled(label->size())));
}

void ImageContainer::mousePressEvent(QMouseEvent *event) {
    emit send(this);
}

QImage* ImageContainer::getImage() {
    return &this->image;
}
