#include "mainwindow.h"
#include "ui_mainwindow.h"
#define height 400
#define width 400

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < height; ++x)
        {
            for (int y = 0; y < width; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    ui->drawingArea->setPixmap(QPixmap::fromImage(img))
}

MainWindow::~MainWindow()
{
    delete ui;
}

