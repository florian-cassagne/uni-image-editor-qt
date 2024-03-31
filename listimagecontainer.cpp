#include "listimagecontainer.h"

ListImageContainer::ListImageContainer(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    scrollArea->setWidget(widget);

}

ImageContainer* ListImageContainer::addContainer(QImage *image) {
    ImageContainer *imageContainer = new ImageContainer();
    imageContainer->setImage(image);
    scrollArea->widget()->layout()->addWidget(imageContainer);
    return imageContainer;
}
