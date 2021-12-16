/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *drawingArea;
    QPushButton *btnHilbertCurve;
    QSpinBox *spinBoxOrder;
    QLabel *label_2;
    QPushButton *btnColor;
    QPushButton *btnClear;
    QLabel *label;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 586);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 47, 41);\n"
"font: 75 10pt \"Yu Gothic\";\n"
"color: white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        drawingArea = new QLabel(centralwidget);
        drawingArea->setObjectName(QString::fromUtf8("drawingArea"));
        drawingArea->setGeometry(QRect(10, 10, 512, 512));
        btnHilbertCurve = new QPushButton(centralwidget);
        btnHilbertCurve->setObjectName(QString::fromUtf8("btnHilbertCurve"));
        btnHilbertCurve->setGeometry(QRect(660, 190, 111, 41));
        btnHilbertCurve->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 92);"));
        spinBoxOrder = new QSpinBox(centralwidget);
        spinBoxOrder->setObjectName(QString::fromUtf8("spinBoxOrder"));
        spinBoxOrder->setGeometry(QRect(660, 100, 101, 41));
        spinBoxOrder->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 128, 255);"));
        spinBoxOrder->setMaximum(8);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 110, 61, 31));
        btnColor = new QPushButton(centralwidget);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        btnColor->setGeometry(QRect(660, 280, 111, 41));
        btnColor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 92);"));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(660, 380, 111, 41));
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 92);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 490, 141, 51));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 79, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 20, 161, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 79, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawingArea->setText(QString());
        btnHilbertCurve->setText(QCoreApplication::translate("MainWindow", "Hilbert Curve", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Order:", nullptr));
        btnColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "21132_Shreyash", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "A10 Hilbert Curve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
