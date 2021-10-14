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
    void on_btnPlot_clicked();

    void on_btnColor_clicked();

    void on_btnClear_clicked();

    void Assignment6B();

    void DDALine(float,float,float,float);

    void BresenhamLine(int, int, int, int);

    void BresenhamCircle(int, int, int);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
