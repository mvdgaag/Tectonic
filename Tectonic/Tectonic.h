#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tectonic.h"

class Tectonic : public QMainWindow
{
    Q_OBJECT

public:
    Tectonic(QWidget *parent = Q_NULLPTR);

private:
    Ui::TectonicClass ui;
};
