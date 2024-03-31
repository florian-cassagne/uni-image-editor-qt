#ifndef LOADING_BOX_H
#define LOADING_BOX_H

#include <QDialog>

namespace Ui {
class LoadingBox;
}

class LoadingBox : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingBox(QWidget *parent = nullptr);
    ~LoadingBox();

private:
    Ui::LoadingBox *ui;
};

#endif // LOADING_BOX_H
