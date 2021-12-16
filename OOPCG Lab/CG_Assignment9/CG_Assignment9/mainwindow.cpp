#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QColorDialog"

#include<QMouseEvent>
#include<QtDebug>
#include<QTime>
#include<QMessageBox>

QImage img(600, 600, QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));

// function to generate random integers in given range
int RangedRand(int range_min, int range_max)
{
    // Generate random number in the interval [range_min, range_max], inclusive.
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

// constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ClearScreen();
    defaultFields();
}

// destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// class for Matrix stores the matrix and contains OPERATOR OVERLOADING for multiplication of matrices
class Matrix
{
public:
    float a[2][3];              // To store x1, y1 co-ordinates.
    float b[3][3];              // To store required matrix.
    Matrix operator*(Matrix ob) // Overloading multiplication operator.
    {
        Matrix temp;                // Creating temporary object.
        for (int i = 0; i < 2; i++) // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                temp.a[i][j] = 0; // Setting value to zero.
                for (int k = 0; k < 3; k++)
                {
                    temp.a[i][j] += a[i][k] * ob.b[k][j]; // Creating result element for the matrix.
                }
            }
        }
        return temp; // Returning result.
    }
};

void MainWindow::ClearScreen()
{
    // clearing the screen
    for (int x = 0; x < 600; ++x) // Iterating in horizontal.
    {
        for (int y = 0; y < 600; ++y) // Iterating in vertical.
        {
            img.setPixel(x, y, qRgb(0, 0, 0)); // Setting pixel to black colour.
        }
    }
    // Re-drawing Co-ordinate axes
    dda(-300, 0, 300, 0, qRgb(255, 0, 0)); // X-axis
    dda(0, -300, 0, 300, qRgb(255, 0, 0)); // Y-axis
}

void MainWindow::defaultFields() // To clear all 5 input fields.
{
    // Clear cleans the input field.
    ui->SpinBoxTx->setValue(0);
    ui->SpinBoxTy->setValue(0);
    ui->SpinBoxSx->setValue(1);
    ui->SpinBoxSy->setValue(1);
    ui->SpinBoxAngle->setValue(0);
}

void MainWindow::dda(float x1, float y1, float x2, float y2, QColor color)
{
    // Giving necessary shift to work with axes.
    x1 += 300;
    y1 += 300;
    x2 += 300;
    y2 += 300;

    float dx, dy, length, x, y; // Necessary variables declared.

    // Change in x and y.
    dx = x2 - x1;
    dy = y2 - y1;

    // Deciding decision parameter i.e. length
    if (abs(dx) > abs(dy))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }

    // Dividing by parameter
    dx = dx / length;
    dy = dy / length;
    x = x1;
    y = y1;
    int i = 0;
    img.setPixel(x, y, color.rgb()); // Setting pixel

    while (i < length) // Drawing line
    {
        // Incrementing variables.
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, color.rgb());
        i++;
    }
    ui->drawingArea->setPixmap(QPixmap::fromImage(img)); // Showing changes on the output screen.
}

void MainWindow::mousePressEvent(QMouseEvent *ev) // To handle mouse events.
{
    if (start)
    {
        // Recording x and y values.
        int p = ev->pos().x();
        int q = ev->pos().y();

        // Subtracting to match with axes.
        a[ver] = p - 300;
        b[ver] = q - 300;

        if (ev->button() == Qt::RightButton) // If right button is pressed, complete the polygon
        {
            dda(a[0], b[0], a[ver - 1], b[ver - 1], rgb); // Drawing last line.
            start = false;                                        // Setting condtion as false.
        }
        else // Keep on drawing as per input.
        {
            if (ver > 0)
            {
                dda(a[ver], b[ver], a[ver - 1], b[ver - 1], rgb);
            }
        }
        ver++;
    }
    // Last co-ordinate is set equal to first co-ordinate.
    a[ver] = a[0];
    b[ver] = b[0];
}

void MainWindow::translate()
{
    ClearScreen(); // Clearing original figure.
    tx = ui->SpinBoxTx->value();
    ty = ui->SpinBoxTy->value();


    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans; // Creating matrices
        /*
            x1 y1   1 0 Tx
            x2 y2   0 1 Ty
            1  1    0 0 1
        */
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}}; // To store x1, y1, x2, y2
        float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, -ty, 1}};       // To store translation value.
        for (int i = 0; i < 2; i++)                                 // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = T[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], rgb); // Drawing that answer to the screen.

        // saving coordinates after translation
        a[i] = ans.a[0][0];
        b[i] = ans.a[0][1];

    }
    a[ver] = a[0];
    b[ver] = b[0];
}

void MainWindow::rotate()
{
    ClearScreen(); // Clearing original figure.
    x = ui->SpinBoxAngle->value();
    x *= 3.142 / 180; // Converting from degree to radian.

    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans;                                                                                       // Creating matrices
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};                                             // To store x1, y1, x2, y2
        float R[3][3] = {{(float)cos(x), ((float)(-sin(x))), 0}, {(float)sin(x), (float)cos(x), 0}, {0, 0, 1}}; // To store rotation value.
        for (int i = 0; i < 2; i++)                                                                             // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = R[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], rgb); // Drawing that answer to the screen.

        // saving coordinates after translation
        a[i] = ans.a[0][0];
        b[i] = ans.a[0][1];
    }
    a[ver] = a[0];
    b[ver] = b[0];
}

void MainWindow::scale()
{
    ClearScreen(); // Clearing original figure.
    sx = ui->SpinBoxSx->value();
    sy = ui->SpinBoxSy->value();

    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans;                                           // Creating matrices
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}}; // To store x1, y1, x2, y2
        float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};        // To store scaling value.
        for (int i = 0; i < 2; i++)                                 // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = S[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], rgb); // Drawing that answer to the screen.

        // saving coordinates after translation
        a[i] = ans.a[0][0];
        b[i] = ans.a[0][1];
    }
    a[ver] = a[0];
    b[ver] = b[0];
}

// fuction to create random polygons
void MainWindow::on_btnFeelingLucky_clicked()
{
    ver = RangedRand(3, 10);
    for (int i=0; i<ver; i++)
    {
         a[i]=RangedRand(-300, 300);
         b[i]=RangedRand(-300, 300);
    }
    a[ver] = a[0];
    b[ver] = b[0];
    for (int i=0; i<ver; i++)
    {
        dda(a[i], b[i], a[i+1], b[i+1], rgb);
    }

}


void MainWindow::on_radbtnEnableMouse_toggled(bool checked)
{
    if (checked) {
        start = true;
    }
}


void MainWindow::on_btnColor_clicked()
{
    QRgb color(QColorDialog::getColor().rgb()); //Able to select any color to draw the shape using Qcolor window
    rgb = color;
}


void MainWindow::on_btnClear_clicked()
{
    ClearScreen(); // Clearing screen.
    defaultFields(); // Clearing input fields.
    start = true;  // Setting condition as true.
    ver = 0;       // Vertex count is set to zero.
}


void MainWindow::on_btnTranslate_clicked()
{
    translate();
}


void MainWindow::on_btnRotate_clicked()
{
    rotate();
}


void MainWindow::on_btnScale_clicked()
{
    scale();
}


void MainWindow::on_btn_TRS_clicked()
{
    translate();
    rotate();
    scale();
}


void MainWindow::on_btnRTS_clicked()
{
    rotate();
    translate();
    scale();
}


void MainWindow::on_btnSRT_clicked()
{
    scale();
    rotate();
    translate();
}

