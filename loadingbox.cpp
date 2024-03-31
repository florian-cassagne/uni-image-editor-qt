#include "loadingbox.h"
#include "ui_loadingbox.h"

LoadingBox::LoadingBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingBox)
{
    ui->setupUi(this);
}

LoadingBox::~LoadingBox()
{
    delete ui;
}
