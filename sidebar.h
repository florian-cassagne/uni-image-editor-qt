#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "ui_sidebar.h"

class SideBar : public QWidget, private Ui::SideBar
{
    Q_OBJECT

public:
    explicit SideBar(QWidget *parent = nullptr);
};

#endif // SIDEBAR_H
