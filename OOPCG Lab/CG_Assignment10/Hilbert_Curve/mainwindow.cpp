#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QColorDialog>
#include <QMessageBox>
#define HEIGHT 513
#define WIDTH 513

QImage img(WIDTH, HEIGHT,QImage::Format_RGB888);
QRgb rgb(qRgb(0,255,0));

// constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dist_main = 512;
    x = 0;
    y = 0;
    dist = dist_main;
    ClearScreen();
}

// destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// delay function is used to point points with certain delay so that we can see the plotting of curves
void delay( float ms )    // time in milisecond is given as argument
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )

    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

//function to clear the screen
void MainWindow::ClearScreen()
{

    for(int i=0; i<WIDTH;i++){
        for(int j=0; j<HEIGHT;j++){
            img.setPixel(i, j, qRgb(0, 0, 0));
        }
    }
    ui->spinBoxX1->setValue(0);
    ui->spinBoxY1->setValue(0);
    ui->spinBoxX2->setValue(512);
    ui->spinBoxY2->setValue(512);
    ui->drawingArea->setPixmap(QPixmap :: fromImage(img));
}

// function to draw squares
void MainWindow::DrawSquares(int level, int dist, int x1, int y1, int x2, int y2) {
    // drawing squares
    rgb = qRgb(255, 0, 0);  // Setting color to red

    for (int i = 0; i <= x2-x1; i+=dist) {  // vertical lines
        goToXY(x1+i, y1);
        drawLine(0, y2-y1, 0);
    }

    for (int j = 0; j <= y2-y1; j+=dist) {  // horizontal lines
        goToXY(x1, y1+j);
        drawLine(x2-x1, 0, 0);
    }

}

void MainWindow::DDA(int x1, int y1, int x2, int y2, bool usedelay)
{
    float x, y, dx, dy, xinc, yinc, step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(std::abs(dx) > std::abs(dy)) {
        step = std::abs(dx);
    }
    else {
        step = std::abs(dy);
    }
    xinc = dx/step;
    yinc = dy/step;
    x = x1;
    y = y1;
    for (int i = 1; i <= step ; i++) {
        img.setPixel(x, y, rgb);
        if (usedelay) {
            delay(1);
        }

        ui->drawingArea->setPixmap(QPixmap::fromImage(img));
        x = x + xinc;
        y = y + yinc;
    }
}

// function to draw a line to given point from current point
void MainWindow::drawLine(int dx, int dy, bool usedelay)
{
    DDA(x, y, x + dx, y + dy, usedelay);
    x = x + dx;
    y = y + dy;
}

// function for setting x and y to given parameters
void MainWindow::goToXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

/*
 * Cups in upper case, joins in lower case
 * Cup subdivision rules i.e. each cup is further divided into 4 cups and 3 joins in next order
 * UP => LEFT down UP right UP up RIGHT
 * LEFT => UP right LEFT down LEFT left DOWN
 * DOWN => RIGHT up DOWN left DOWN down LEFT
 * RIGHT => DOWN left RIGHT up RIGHT right UP
*/

// cup facing up
void MainWindow::HilbertUp(int level)
{
    if (level > 0) {
        HilbertLeft(level -1);
        drawLine(0, dist); // down (because origin in QT is at top-left)
        HilbertUp(level - 1);
        drawLine(dist, 0); // right
        HilbertUp(level - 1);
        drawLine(0, -dist); // up
        HilbertRight(level - 1);
    }
}

// cup facing left
void MainWindow::HilbertLeft(int level)
{
    if (level > 0) {
        HilbertUp(level - 1);
        drawLine(dist, 0); // right
        HilbertLeft(level - 1);
        drawLine(0, dist); // down
        HilbertLeft(level - 1);
        drawLine(-dist, 0); // left
        HilbertDown(level - 1);
    }
}

// cup facing right
void MainWindow::HilbertRight(int level)
{
    if(level > 0) {
        HilbertDown(level - 1);
        drawLine(-dist, 0); // left
        HilbertRight(level - 1);
        drawLine(0, -dist); // up
        HilbertRight(level - 1);
        drawLine(dist, 0); // right
        HilbertUp(level - 1);
    }
}

// cup facing down
void MainWindow::HilbertDown(int level)
{
    if(level > 0) {
        HilbertRight(level - 1);
        drawLine(0, -dist);  // up
        HilbertDown(level -1);
        drawLine(-dist, 0); // left
        HilbertDown(level - 1);
        drawLine(0, dist);  // down
        HilbertLeft(level -1);
    }
}

// When Hilbert Curve button is clicked
void MainWindow::on_btnHilbertCurve_clicked()
{
    int level, x1, y1, x2, y2;
    level = ui->spinBoxOrder->value();
    x1 = ui->spinBoxX1->value();
    x2 = ui->spinBoxX2->value();
    y1 = ui->spinBoxY1->value();
    y2 = ui->spinBoxY2->value();

    if (x1 ==x2 || y1==y2) {
        QMessageBox msg;
        msg.information(0, "Square size 0", "Please modify co-ordinates to increase size of square.");
    } else {

//    dist = 512;
        dist = x2-x1;

        // halveing distance for each order/level of curve
        for (int i = level; i > 0 ; i--) {
            dist = dist / 2;
        }

        DrawSquares(level, dist, x1, y1, x2, y2);

        // drawing hilbert curve
        QMessageBox curveColor; // asking for color of hilbert curve
        curveColor.information(0, "Curve Color", "Select color for the hilbert curve");
        on_btnColor_clicked(); // color button clicked

        // sets x and y to given values
        goToXY(x1 + dist/2, y1 + dist/2);

        HilbertUp(level);    // recursive fuction HilbertUp called

        ui->drawingArea->setPixmap(QPixmap::fromImage(img));  // setting pixmap
    }
}

// Selecting color of line
void MainWindow::on_btnColor_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw the shape using Qcolor window
    rgb = color;
}

// Clearing the screen
void MainWindow::on_btnClear_clicked()
{
    ClearScreen();
}
