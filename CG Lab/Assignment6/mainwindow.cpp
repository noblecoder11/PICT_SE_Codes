#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <math.h>
#include <QTime>
#define height 400
#define width 400

void delay( int millisecondsToWait )
{

    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );

    while( QTime::currentTime() < dieTime )

    {

        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );

    }

}

QImage img(height, width, QImage::Format_RGB888);
QRgb rgb(qRgb(255, 255, 255));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Assignment6A()
{
    ui->label->show();
    int xC = ui->spinXCenter->value();
    int yC = ui->spinYCenter->value();
    int rad = ui->spinRadius->value();

    float x1 = xC + rad * (float)sqrt(3) / 2;
    float x2 = xC - rad * (float)sqrt(3) / 2;
    float y1 = yC + rad / 2;

    BresenhamCircle(xC, yC, rad);
    BresenhamCircle(xC, yC, rad / 2);

    DDALine(x1, y1, x2, y1);
    DDALine(x1, y1, xC, (float)yC - rad);
    BresenhamLine(x2, y1, (float)xC, (float)yC - rad);
}

void MainWindow::BresenhamCircle(int xCenter, int yCenter, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);
    int x_arr[100000], y_arr[100000];
    int count = 0;
    while (x <= y)
    {
        if (d > 0)
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        else
        {
            d = d + (4 * x) + 6;
        }
        x++;
        img.setPixel(xCenter + x, yCenter - y, rgb); // this is the first octant of the circle
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        x_arr[count] = x,
        y_arr[count] = y;
        count++;
        delay(50);
    }
    for(int i = 0; i < count; i++){
        img.setPixel(xCenter - y_arr[i], yCenter - x_arr[i], rgb);
        img.setPixel(xCenter + x_arr[i], yCenter + y_arr[i], rgb);
        img.setPixel(xCenter - x_arr[i], yCenter - y_arr[i], rgb);
        img.setPixel(xCenter - x_arr[i], yCenter + y_arr[i], rgb);
        img.setPixel(xCenter + y_arr[i], yCenter - x_arr[i], rgb);
        img.setPixel(xCenter + y_arr[i], yCenter + x_arr[i], rgb);
        img.setPixel(xCenter - y_arr[i], yCenter + x_arr[i], rgb);
        delay(100);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
    }
}

void MainWindow::BresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1; // condition to check if x1 > x2 then we need to decrement
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy; // error value as we have taken dy negative so its dx - dy
    // err is to get the integer value of the nearest pixel

    while (true)
    {
        img.setPixel(x1, y1, rgb);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err; // decision parameter
        if (e2 >= dy)
        {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDALine(float x1, float y1, float x2, float y2)
{

    float dx = (x2 - x1);
    float dy = (y2 - y1);
    float step = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy); // this is the no of steps the program must run
    // also checks if slope > 1 or < 1

    dx = dx / step; // this is the increment that must happen in each step
    dy = dy / step;

    float x = x1, y = y1;
    int i = 1;

    while (i <= step) // repeat the loop till step gets over
    {
        img.setPixel(x, y, rgb);
        x += dx;
        y += dy;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_btnPlot_clicked()
{
    Assignment6A();
}

void MainWindow::on_btnColor_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw
    rgb = color;                                //sets the value of the selected color to the global variable
}

void MainWindow::on_btnClear_clicked()
{
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

