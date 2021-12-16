#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // general functions
    void dda(float x1, float y1, float x2, float y2, QColor color); // Line drawing function

    void mousePressEvent(QMouseEvent *ev);                          // Mouse event

    void ClearScreen();                                             // CLearing screen

    void defaultFields(); // clearing fields

    // functions for operations
    void translate();

    void rotate();

    void scale();

    // buttons
    void on_btnFeelingLucky_clicked();

    void on_radbtnEnableMouse_toggled(bool checked);

    void on_btnColor_clicked();

    void on_btnClear_clicked();

    void on_btnTranslate_clicked();

    void on_btnRotate_clicked();

    void on_btnScale_clicked();

    void on_btn_TRS_clicked();

    void on_btnRTS_clicked();

    void on_btnSRT_clicked();

private:
    Ui::MainWindow *ui;

    float x1, y1, x2, y2, tx, ty, sx, sy, x; // Necessary variables.
    float a[20], b[20];                      // To store x and y values for mouse event
    int ver;
    bool start = false;
};
#endif // MAINWINDOW_H
