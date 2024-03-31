#ifndef LISTIMAGECONTAINER_H
#define LISTIMAGECONTAINER_H

#include "ui_listimagecontainer.h"
#include "imagecontainer.h"

class ListImageContainer : public QWidget, private Ui::ListImageContainer
{
    Q_OBJECT

public:
    explicit ListImageContainer(QWidget *parent = nullptr);
    ImageContainer* addContainer (QImage *image);
};

#endif // LISTIMAGECONTAINER_H
