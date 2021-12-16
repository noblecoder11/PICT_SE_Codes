#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <time.h>
#include <QColorDialog>
#include <QTime>
#include <QMessageBox>
#define height 400
#define width 400

QImage img(width, height, QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));

int xCoord[20], yCoord[20], vertex=0;
int xlastVertex, ylastVertex;

// delay function is used to point points with certain delay so that we can see the plotting of curves
void delay( int ms )    // time in milisecond is given as argument
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )

    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

int RangedRand(int range_min, int range_max)
{
    // Generate random number in the interval [range_min, range_max], inclusive.
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

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
    ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Lines::BresenhamLine(int x1, int y1, int x2, int y2,Ui::MainWindow *ui)
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

void MainWindow::ScanFill(Ui::MainWindow *ui)
{
    //Scan line fill method used to fill the polygon.
    xCoord[vertex] = xCoord[0];
    yCoord[vertex] = yCoord[0];

    float slope[20];
    float dx, dy;

    // set the slope array for all the vertices. If slope is 0 then it is not considered for processing.
    for(int i=0;i<vertex;i++)
    {
        dy = yCoord[i+1] - yCoord[i];
        dx = xCoord[i+1] - xCoord[i];
        if(dy == 0.0)
        {
            slope[i] = 1.0;
        }
        if(dx == 0.0)
        {
            slope[i] = 0.0;
        }
        if((dy != 0.0) && (dx != 0.0))
        {
            slope[i] = dx / dy;
        }
    }

    for (int y = 0; y < height; y++)
    {
        int k = 0;
        int xi[20];
        // code to generate the scan line table
        // Active edge table generation using the y values which are to be further sorted in the increasing order x.
        for(int i=0;i<vertex;i++)
        {
            if(((yCoord[i]<=y) && (yCoord[i+1]>y)) || ((yCoord[i]>y) && (yCoord[i+1]<=y)))
            {
                xi[k] = int(xCoord[i] + (slope[i]*(y-yCoord[i])));
                k++;
            }
        }

        // Code for bubble sort
        //Sorting Active Edge values in order of x values.
        for(int j=0;j<k-1;j++)
        {
            for(int i=0;i<k-j-1;i++)
            {
                if(xi[i]>xi[i+1])
                {
                    int temp = xi[i];
                    xi[i] = xi[i+1];
                    xi[i+1] = temp;
                }
            }
        }

        // Taking pairs of values and then filling the polygon.
        for(int i=0;i<k;i+=2)
        {
          line.BresenhamLine(xi[i],y,xi[i+1]+1,y, ui);
          delay(2);
        }

    }
}


void MainWindow::on_btnPlotLine_clicked()
{

        int x1 = ui->spinBoxX1->value();
        int y1 = ui->spinBoxY1->value();
        int x2 = ui->spinBoxX2->value();
        int y2 = ui->spinBoxY2->value();

        ui->spinBoxX1->setValue(x2);
        ui->spinBoxY1->setValue(y2);
        ui->spinBoxX2->clear();
        ui->spinBoxY2->clear();
        xCoord[vertex] = x1;    // set the value of vertex(x) in the array
        yCoord[vertex] = y1;    // set the valaue of vertex(y) in the array
        xlastVertex = x2;
        ylastVertex = y2;
        vertex++;         // change the number of vertex by 1
        line.BresenhamLine(x1,y1,x2,y2, ui);
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
    for(int q=0;q<=vertex;q++)
    {
         xCoord[q]=0;
         yCoord[q]=0;
    };

    vertex = 0;
    ui->spinBoxX1->setValue(0);
    ui->spinBoxY1->setValue(0);
    ui->spinBoxX2->setValue(0);
    ui->spinBoxY2->setValue(0);
}


void MainWindow::on_btnScanFill_clicked()
{
        if ((xlastVertex != xCoord[0]) && (ylastVertex != yCoord[0]))
        {
            QMessageBox incompletePoly;
            incompletePoly.information(0, "Incomplete Polygon", "Please complete your polygon to use scan fill.");
        }
        else
        {
            xCoord[vertex] = 0;
            yCoord[vertex] = 0;
            ScanFill(ui);
            ui->spinBoxX1->setValue(0);
            ui->spinBoxY1->setValue(0);
            ui->spinBoxX2->setValue(0);
            ui->spinBoxY2->setValue(0);
        }
}


void MainWindow::on_btnFeelingLucky_clicked()
{
    vertex = RangedRand(3, 10);
    for (int i=0; i<vertex; i++)
    {
         xCoord[i]=RangedRand(0, 400);
         yCoord[i]=RangedRand(0, 400);
    }
    xlastVertex = xCoord[0];
    ylastVertex = yCoord[0];
    for (int i=0; i<vertex-1; i++)
    {
        line.BresenhamLine(xCoord[i], yCoord[i], xCoord[i+1], yCoord[i+1], ui);
    }
    line.BresenhamLine(xCoord[vertex-1], yCoord[vertex-1], xCoord[0], yCoord[0], ui);
}

