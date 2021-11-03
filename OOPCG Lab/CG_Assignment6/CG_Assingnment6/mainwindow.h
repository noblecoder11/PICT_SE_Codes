#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class algorithms
{
public:
    void BresenhamCircle(int,int,int,Ui::MainWindow *ui);
    void DDALine(float,float,float,float,Ui::MainWindow *ui);
    void BresenhamLine(int,int,int,int,Ui::MainWindow *ui);
};

class assignment
{
public:
    void Assignment6a(Ui::MainWindow *ui);
    void Assignment6b(Ui::MainWindow *ui);
    algorithms algo;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    assignment assignment;

private slots:
    void on_btnPlot6A_clicked();

    void on_btnPlot6B_clicked();

    void on_btnColor_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    friend class assignment;

};
#endif // MAINWINDOW_H
