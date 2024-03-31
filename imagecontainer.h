#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include "ui_imagecontainer.h"

class ImageContainer : public QWidget, private Ui::ImageContainer
{
    Q_OBJECT

private:
    QImage image;

public:
    explicit ImageContainer(QWidget *parent = nullptr);
    void setImage(QImage *image);
    QImage* getImage();
signals :
    void send(ImageContainer* imageContainer);
protected :
    void mousePressEvent ( QMouseEvent * event ) override;

};

#endif // IMAGECONTAINER_H
