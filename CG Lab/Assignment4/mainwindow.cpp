#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>
#include <math.h>
#include <string.h>
#define height 400
#define width 400

// define a class write a dda function make other class fill this class will inherit class line dda function will call in the fill algorithm
using namespace std;
int ver,a[20],b[20],i,y,xi[20],j,temp,k; // variables used in scan line algorithm
float slope[20],dx,dy;

QImage img(height, width, QImage::Format_RGB888); // this the image
QRgb rgb(qRgb(255, 255, 255)); // this is the color of the line

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
    ver = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnPlotLine_clicked()
{

    int x1 = ui->spinBoxX1->value();
    int y1 = ui->spinBoxY1->value();
    int x2 = ui->spinBoxX2->value();
    int y2 = ui->spinBoxY2->value();

    a[ver] = x2;    // set the value of vertex(x) in the array
    b[ver] = y2;    // set the vlaue of vertex(y) in the array
    ver++;          // change the number of vertex by 1

    DDALine(x1,y1,x2,y2);

    ui->spinBoxX1->setValue(x2);
    ui->spinBoxY1->setValue(y2);
    ui->spinBoxX2->setValue(0);
    ui->spinBoxY2->setValue(0);
}



void MainWindow::on_btnScanLine_clicked()
{

    a[ver] = a[0];
    b[ver] = b[0];

    // set the slope array for all the vertices
    for(i=0;i<ver;i++)
    {
        dy = b[i+1] - b[i];
        dx = a[i+1] - a[i];
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


    for(int y=0;y<height;y++)
    {
        k = 0;

        // code to generate the scan line table
        for(i=0;i<ver;i++)
           {
                if(((b[i]<=y) && (b[i+1]>y)) || ((b[i]>y) && (b[i+1]<=y)))
                {
                    xi[k] = int(a[i] + (slope[i]*(y-b[i])));
                    k++;
                }
           }

           // Code for bubble sort
        for(j=0;j<k-1;j++)
           {
                for(i=0;i<k-j-1;i++)
                    {
                        if(xi[i]>xi[i+1])
                        {
                            temp = xi[i];
                            xi[i] = xi[i+1];
                            xi[i+1] = temp;
                        }
                    }
           }

        // code for printing the final line
        for(i=0;i<k;i+=2)
            {
                DDALine(xi[i],y,xi[i+1]+1,y);
            }
    }

        QMessageBox lineScanned;
        lineScanned.information(0, "Done", "Scan Line Successfull");
}




void MainWindow::on_btnColor_clicked() // To change the line color
{
    QRgb color(QColorDialog::getColor().rgb());
    rgb = color;
}

void MainWindow::on_btnClear_clicked() // To clear the screen
{
    for (int x = 0; x < height; ++x)
        {
            for (int y = 0; y < width; ++y)
            {
                img.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
     ver = 0;
     ui->spinBoxX1->setValue(0);
     ui->spinBoxY1->setValue(0);
     ui->spinBoxX2->setValue(0);
     ui->spinBoxY2->setValue(0);
     ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::DDALine(int x1, int y1, int x2, int y2){ // This is line drawing algorithm


            float dx,dy,step,x,y;
            dx=x2-x1;
            dy=y2-y1;
            if(abs(dx)>=abs(dy))
            {
                step=abs(dx);
            }
            else {
                step=abs(dy);
            }
            dx=dx/step;
            dy=dy/step;
            int i=0;
            x=x1;
            y=y1;
            //img.setPixel(x,y,qRgb(225,0,0));
            while(i<step)
            {
                x=x+dx;
                y=y+dy;
                img.setPixel(x,y,rgb);
                i++;
            }
         ui->drawingArea->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::BresenhamLine(int x1, int y1, int x2, int y2)
{
        int dx = abs(x2-x1);
        int dy = abs(y2-y1);

        int x = x1;
        int y = y1;

        int pk = 2*dy - dx; // This is decision parameter

        for (int i =0; i<dx; i++){
            img.setPixel(x,y, rgb);
            if(pk >= 0){
                pk += 2*(dy-dx);
                x++;
                y++;
            }
            else{
                pk += 2*dy;
                x++;
            }
        }

        ui->label->setPixmap(QPixmap::fromImage(img));
}
