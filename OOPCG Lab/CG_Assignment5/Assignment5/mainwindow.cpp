#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QLabel>
#include <QMouseEvent> // to detect all the mouse events
#include <iostream>

using namespace std;

#define height 600 // set the height of the drawing area
#define width 1000  // set the width of the drawing area

QImage img(width, height, QImage::Format_RGB888);       // this is the drawing area
QRgb rgb(qRgb(255, 255, 255));                          // color bit which is set to white by default

MainWindow::MainWindow(QWidget *parent) // Constructor
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int x = 0; x < width; ++x)                     // this is for initial light yellow coloured screen
    {
        for (int y = 0; y < height; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->ClearButton->setEnabled(true);                //clip disabled
    ui->ClipButton->setEnabled(false);                // clear disabled
}

MainWindow::~MainWindow() // destructor
{
    delete ui;
}

bool mouseEnabled = false;
bool mouseLine = false;

int x1y1[40][2];                    // stores x1-y1 coord for all lines
int LineNo = 0;                     // no of lines present

int diagonal_x[2];                  // diagonal x clipping window
int diagonal_y[2];                  // diagonal y clipping window

int lft;                         // left of window
int rght;                          // right of window
int tp;                         // top of window
int bttom;                        // bottom of window


//DDA line drawing algorithm
void MainWindow::DDALine(float x1, float y1, float x2, float y2)
{
    float dx, dy, step, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) >= abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    int i = 0;
    x = x1;
    y = y1;
    while (i < step)
    {
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, rgb);
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}
int MainWindow::findRegionCode(double x, double y) // this is code for finding the region code
{
    // 4 bit region code system in the algorithm
    // TBRL

    /*
                        left	    central	     right

    top             | 1001 =9  |    1000 =8	  | 1010 =10
                    ------------------------------------
    central         | 0001 =1  |    0000 =0	  | 0010 =2
                    ------------------------------------
    bottom          | 0101 =5  |	0100 =4	  | 0110 =6
     */


    if (diagonal_x[0] > diagonal_x[1])
    {
        rght = diagonal_x[0];
        lft = diagonal_x[1];
    }
    else
    {
        rght = diagonal_x[1];
        lft = diagonal_x[0];
    }


    if (diagonal_y[0] > diagonal_y[1])
    {
        tp = diagonal_y[0];
        bttom = diagonal_y[1];
    }
    else
    {
        tp = diagonal_y[1];
        bttom = diagonal_y[0];
    }
    int bits[4];
    for(int i =0;i<4;i++){
        bits[i]=0;
    }
    if(y>tp){bits[0]=1;}
    else{bits[0]=0;}
    if(y<bttom){bits[1]=1;}
    else{bits[1]=0;}
    if(x>rght){bits[2]=1;}
    else{bits[2]=0;}
    if(x<lft){bits[3]=1;}
    else{bits[3]=0;}
    int m =1;
    int n=0;
    for(int i=3;i>=0;i--){
        n=n+bits[i]*m;
        m=m*2;
    }
    return n;
}

void MainWindow::Clip(int x1, int y1, int x2, int y2)
{
    int code1 = findRegionCode(x1, y1); // find region code of 1st end point
    int code2 = findRegionCode(x2, y2); // find region code of 2nd end point

    bool isVisible = false;

    while (1)
    {
        if (code1 == 0 && code2 == 0) // line completely inside the window
        {
            isVisible = true;
            break;
        }
        else if (code1 & code2) // both are outside so ignore the line
        {
            break;
        }
        else
        {
            int code_out;
            int x=0, y=0;
            if (code1 != 0) // check which point is outside
                code_out = code1;
            else
                code_out = code2;

            if (code_out & 4)
            {
                x = x1 + (x2 - x1) * (bttom - y1) / (y2 - y1);
                y = bttom;
            }
            else if (code_out & 8)
            {
                x = x1 + (x2 - x1) * (tp - y1) / (y2 - y1);
                y = tp;
            }
            else if (code_out & 1)
            {
                y = y1 + (y2 - y1) * (lft - x1) / (x2 - x1);
                x = lft;
            }
            else if (code_out & 2)
            {
                y = y1 + (y2 - y1) * (rght - x1) / (x2 - x1);
                x = rght;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = findRegionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = findRegionCode(x2, y2);
            }
        }
    }

    if (isVisible)
        DDALine(x1, y1, x2, y2);    //after this we will get new co-ordinates
}


int k1 = 0;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (mouseLine)
    {
        if (mouseEnabled == true)
        {
            int p = event->pos().x()-10;
            int q = event->pos().y()-30;
            x1y1[LineNo][0] = p;
            x1y1[LineNo][1] = q;

            if (event->button() == Qt::RightButton)     //change
            {
                if(LineNo%2==1)
                {
                    DDALine(x1y1[LineNo][0], x1y1[LineNo][1], x1y1[LineNo - 1][0], x1y1[LineNo - 1][1]);
                    mouseEnabled = false;
                    QMessageBox messageBox;
                    messageBox.information(0, "Message", "Line Complete");

                    ui->DrawLines->setEnabled(false);
                    if (k1 != 0)
                    {
                        ui->ClipButton->setEnabled(true);
                    }
                }
                else
                {
                    QMessageBox messageBox;
                    messageBox.information(0, "Message", "Line incomplete.\nNeed one more point before exit!");
                }
            }
            else
            {
                if (LineNo%2==1)
                {
                    DDALine(x1y1[LineNo][0], x1y1[LineNo][1], x1y1[LineNo - 1][0], x1y1[LineNo - 1][1]);
                }
            }
            LineNo++;
            if (LineNo>1)
            {
                ui->ClipButton->setEnabled(true);
            }
        }
        else
        {
            if (event->button() == Qt::RightButton || event->button() == Qt::LeftButton)
            {
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Mouse Functionality is disabled");
                messageBox.setFixedSize(200, 200);
                return;
            }
        }
    }


    else
    {
        if (mouseEnabled == true)
        {
            int p = event->pos().x();
            int q = event->pos().y();
            diagonal_x[k1] = p;
            diagonal_y[k1] = q;
            k1++;
            if (k1==2)
            {
                DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);
                DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);
                DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
                DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
                mouseEnabled = false;
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Window has been completed");
                messageBox.setFixedSize(200, 200);
                if (LineNo > 1)
                {
                    ui->ClipButton->setEnabled(true);
                }
                ui->DrawWindow->setEnabled(false);
                mouseEnabled = false;
            }
        }
        else
        {
            if (event->button() == Qt::RightButton || event->button() == Qt::LeftButton)
            {
                QMessageBox messageBox;
                messageBox.information(0, "Message", "Mouse button disabled"),
                    messageBox.setFixedSize(200, 200);
                return;
            }
        }
    }
}
//choosing a color with which the lines will be drawn
void MainWindow::on_SelectColor_clicked()
{
    QRgb getColor(QColorDialog::getColor().rgb());
    rgb = getColor;
}

//clear screen button
void MainWindow::on_ClearButton_clicked()
{
    LineNo = 0;
    for (int i = 0; i < 40; i++)
    {
        x1y1[i][0] = -1;
        x1y1[i][1] = -1;
    }
    k1 = 0;
    diagonal_x[0] = 0;
    diagonal_x[1] = 0;
    diagonal_y[0] = 0;
    diagonal_y[1] = 0;

    mouseEnabled = false;
    mouseLine = true;
    for (int x = 0; x < width; ++x) // this is for initial black coloured screen
    {
        for (int y = 0; y < height; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->DrawLines->setEnabled(true);
    ui->DrawWindow->setEnabled(true);
    ui->ClipButton->setEnabled(false);
    ui->ClearButton->setEnabled(true);
}

//clipping the lines within the window
void MainWindow::on_ClipButton_clicked()
{
    for (int x = 0; x < width; ++x) // this is for initial black coloured screen
    {
        for (int y = 0; y < height; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    int i = 0;
    DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[1], diagonal_y[0]);
    DDALine(diagonal_x[0], diagonal_y[0], diagonal_x[0], diagonal_y[1]);
    DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[1], diagonal_y[0]);
    DDALine(diagonal_x[1], diagonal_y[1], diagonal_x[0], diagonal_y[1]);
    for (i = 0; i < LineNo - 1; i=i+2)
    {
        Clip(x1y1[i][0], x1y1[i][1], x1y1[i + 1][0], x1y1[i + 1][1]);

    }
    ui->DrawLines->setEnabled(false);
}


//initiating the process for drawing the clipping window
void MainWindow::on_DrawWindow_clicked()
{
    mouseEnabled = true;                //enabling mouse functionality
    mouseLine = false;                  //initiating window drawing sequence
    ui->DrawLines->setEnabled(false);
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled");
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

//draw lines button sets the array initially and allows the user to draw the lines
void MainWindow::on_DrawLines_clicked()
{
    for (int i = 0; i < 40; i++)
    {
        x1y1[i][0] = -1;               //setting all elements of the array to -1
        x1y1[i][1] = -1;
    }
    mouseEnabled = true;                //enabling use of mouse
    mouseLine = true;                   //initiating line drawing sequence
    QMessageBox messageBox;
    messageBox.information(0, "Message", "Mouse functionality enabled"),
    messageBox.setFixedSize(200, 200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

