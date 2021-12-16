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
    void ClearScreen();
    void DrawSquares(int level, int dist, int x1, int y1, int x2, int y2);
    void goToXY(int x, int y);
    void HilbertUp(int level);
    void HilbertLeft(int level);
    void HilbertRight(int level);
    void HilbertDown(int level);
    void DDA(int x1, int y1, int x2, int y2, bool usedelay = 1);
    void drawLine(int dx, int dy, bool usedealay = 1);

private slots:
    void on_btnHilbertCurve_clicked();


    void on_btnColor_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    int x{}, y{}, dist_main{}, dist{};
};
#endif // MAINWINDOW_H
