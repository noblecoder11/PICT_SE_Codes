#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class Lines
{
public:
    void BresenhamLine(int x1, int y1, int x2, int y2,Ui::MainWindow *ui);
};

class MainWindow : public QMainWindow, public Lines
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    void ScanFill(Ui::MainWindow *);
    Lines line;
private slots:
    void on_btnPlotLine_clicked();
    void on_btnColor_clicked();
    void on_btnClear_clicked();
    void on_btnScanFill_clicked();
    void on_btnFeelingLucky_clicked();
};
#endif // MAINWINDOW_H
