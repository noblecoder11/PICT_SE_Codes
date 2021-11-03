#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <math.h>
#include<QTime>
#define height 401
#define width 401

QImage img(width, height, QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));

// delay function is used to point points with certain delay so that we can see the plotting of curves
void delay( int ms )    // time in milisecond is given as argument
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )

    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

// constructor for MainWindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // code below paints the drawing area in black at start of program
    for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}

// destructor for MainWindow class
MainWindow::~MainWindow()
{
    delete ui;
}

// bresenham Circle algorithm
void algorithms::BresenhamCircle(int xCenter, int yCenter, int radius,Ui::MainWindow *ui) //defining Bresenham Circle drawing algorithm
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
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
        x_arr[count] = x,
        y_arr[count] = y;
        count++;
        delay(10);
    }

    // loops for each octant in circle
    // even numbered octants are looped in reverse order to obtain continuous circle drawing animation
    for(int i = count-1; i >=0; i--){ //2nd octant
//        img.setPixel(xCenter - y_arr[i], yCenter - x_arr[i], rgb);
        img.setPixel(xCenter + y_arr[i], yCenter - x_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i=0; i < count; i++){ //3rd octant
//        img.setPixel(xCenter + x_arr[i], yCenter + y_arr[i], rgb);
        img.setPixel(xCenter + y_arr[i], yCenter + x_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i = count-1; i >=0; i--){ //4th octant
//        img.setPixel(xCenter - x_arr[i], yCenter - y_arr[i], rgb);
        img.setPixel(xCenter + x_arr[i], yCenter + y_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i=0; i < count; i++){ //5th octant
        img.setPixel(xCenter - x_arr[i], yCenter + y_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i = count-1; i >=0; i--){ //6th octant
//        img.setPixel(xCenter + y_arr[i], yCenter - x_arr[i], rgb);
        img.setPixel(xCenter - y_arr[i], yCenter + x_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i=0; i < count; i++){ //7th octant
//        img.setPixel(xCenter + y_arr[i], yCenter + x_arr[i], rgb);
        img.setPixel(xCenter - y_arr[i], yCenter - x_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
    for(int i = count-1; i >=0; i--){ //8th octant
//        img.setPixel(xCenter - y_arr[i], yCenter + x_arr[i], rgb);
        img.setPixel(xCenter - x_arr[i], yCenter - y_arr[i], rgb);
        delay(10);
        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        ui->drawingArea->show();
    }
}

// Bresenham Line Algorithm
void algorithms::BresenhamLine(int x1, int y1, int x2, int y2,Ui::MainWindow *ui)
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
        int e2 = 2 * err; // err is decision parameter
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
    ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}

//defining function for DDA line algorithm
void algorithms::DDALine(float x1, float y1, float x2, float y2,Ui::MainWindow *ui)
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

    ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}

// Function of class assignment for ploting the curves of assignment 6A
void assignment::Assignment6a(Ui::MainWindow *ui)
{
    // reading the values entered by user
    ui->drawingArea->show();
    int xC = ui->spinBoxXc->value();
    int yC = ui->spinBoxYc->value();
    int rad = ui->spinBoxRadius->value();

    //triangle formed is equilateral
    float x1 = xC + rad * (float)sqrt(3) / 2;
    float x2 = xC - rad * (float)sqrt(3) / 2;
    float y1 = yC + rad / 2;

    //drawing the two concentric circles
    algo.BresenhamCircle(xC, yC, rad,ui);
    algo.BresenhamCircle(xC, yC, rad / 2,ui);

    //drawing the lines using both DDA line algorithm and bresenham line algorithm
    algo.DDALine(x1, y1, x2, y1,ui);
    algo.DDALine(x1, y1, xC, (float)yC - rad,ui);
    algo.BresenhamLine(x2, y1, (float)xC, (float)yC - rad,ui);
}

//printing pattern of assignment 6B
void assignment::Assignment6b(Ui::MainWindow *ui)
{
    // reading the values given by user
    ui->drawingArea->show();
    int x1 = ui->spinBoxX1->value();
    int y1 = ui->spinBoxY1->value();
    int x2 = ui->spinBoxX2->value();
    int y2 = ui->spinBoxY2->value();

    // using object algo of class algorithms to call algorith(i.e. dda line)
    algo.DDALine(x1,y1,x2,y1,ui);
    algo.DDALine(x2,y1,x2,y2,ui);
    algo.DDALine(x2,y2,x1,y2,ui);
    algo.DDALine(x1,y2,x1,y1,ui);

    int x1c = (x1 + x2)/2;
    int y1c = (y1 + y2)/2;

    // co-ordinates are (x1c, y1), (x2,y1c), (x1c, y2), (x1, y1c) respectively

    algo.BresenhamLine(x1c, y1, x2, y1c,ui);
    algo.BresenhamLine(x2, y1c, x1c, y2,ui);
    algo.BresenhamLine(x1c, y2, x1, y1c,ui);
    algo.BresenhamLine(x1, y1c, x1c, y1,ui);

    // coordinates for the points are ( (x1c+x1)/2 , (y1 + y1c)/2 ) ,
    // center coordinates are = x1+x2/2 , y1+y2/2
    // center = x1c, y1c

    float h1 = abs(x1-x2)/2;
    float w1 = abs(y1-y2)/2;

    float reqRadius = h1 * w1 / sqrt(h1*h1+w1*w1);

    algo.BresenhamCircle(x1c, y1c, reqRadius,ui);
}

// Slots for each button
void MainWindow::on_btnPlot6A_clicked()
{
    assignment.Assignment6a(ui);
}

void MainWindow::on_btnPlot6B_clicked()
{
    assignment.Assignment6b(ui);
}

void MainWindow::on_btnColor_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw the shape using Qcolor window
    rgb = color;
}


void MainWindow::on_btnClear_clicked()
{
    // paints all drawing area pixels as black
    for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}
