#ifndef IMAGEMODIFIER_H
#define IMAGEMODIFIER_H

#include "ui_imagemodifier.h"

class ImageModifier : public QWidget, private Ui::ImageModifier
{
    Q_OBJECT

private:
    QImage* currentImage;
    QImage* image;
    QGraphicsScene* scene;

public:
    explicit ImageModifier(QWidget *parent = nullptr);

    void setCurrentImage(QImage* Image);
    void updateDisplay(QImage* image);
    void inline resetDisplay() { scene = new QGraphicsScene(); }

    inline QGraphicsScene* getScene() { return scene; }
    inline QImage* getImage() { return image; }
    inline QImage* getCurrentImage() { return currentImage; }
    inline void setScene(QGraphicsScene* _scene) { scene = _scene; }
    inline void setImage(QImage* _image) { image = _image; }

public slots:
    void updateImage(QImage *Image);

};

#endif // IMAGEMODIFIER_H
