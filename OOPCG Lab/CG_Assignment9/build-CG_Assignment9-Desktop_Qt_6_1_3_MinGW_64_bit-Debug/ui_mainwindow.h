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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *drawingArea;
    QPushButton *btnFeelingLucky;
    QRadioButton *radbtnEnableMouse;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *SpinBoxTx;
    QDoubleSpinBox *SpinBoxTy;
    QDoubleSpinBox *SpinBoxAngle;
    QDoubleSpinBox *SpinBoxSx;
    QDoubleSpinBox *SpinBoxSy;
    QPushButton *btnTranslate;
    QPushButton *btnRotate;
    QPushButton *btnScale;
    QPushButton *btn_TRS;
    QPushButton *btnRTS;
    QPushButton *btnSRT;
    QPushButton *btnColor;
    QPushButton *btnClear;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_10;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1329, 760);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #222831;\n"
"color: #ffffff;\n"
"font: 57 10pt \"Yu Gothic Medium\";"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        drawingArea = new QLabel(centralwidget);
        drawingArea->setObjectName(QString::fromUtf8("drawingArea"));
        drawingArea->setGeometry(QRect(40, 40, 600, 600));
        btnFeelingLucky = new QPushButton(centralwidget);
        btnFeelingLucky->setObjectName(QString::fromUtf8("btnFeelingLucky"));
        btnFeelingLucky->setGeometry(QRect(710, 20, 171, 51));
        btnFeelingLucky->setStyleSheet(QString::fromUtf8("background-color: #885a89;"));
        radbtnEnableMouse = new QRadioButton(centralwidget);
        radbtnEnableMouse->setObjectName(QString::fromUtf8("radbtnEnableMouse"));
        radbtnEnableMouse->setGeometry(QRect(920, 20, 171, 51));
        radbtnEnableMouse->setLayoutDirection(Qt::LeftToRight);
        radbtnEnableMouse->setStyleSheet(QString::fromUtf8("background-color: #885a89;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 140, 101, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 310, 91, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(660, 420, 81, 31));
        SpinBoxTx = new QDoubleSpinBox(centralwidget);
        SpinBoxTx->setObjectName(QString::fromUtf8("SpinBoxTx"));
        SpinBoxTx->setGeometry(QRect(850, 140, 81, 41));
        SpinBoxTx->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 74, 73);"));
        SpinBoxTx->setMinimum(-600.000000000000000);
        SpinBoxTx->setMaximum(600.000000000000000);
        SpinBoxTy = new QDoubleSpinBox(centralwidget);
        SpinBoxTy->setObjectName(QString::fromUtf8("SpinBoxTy"));
        SpinBoxTy->setGeometry(QRect(850, 190, 81, 41));
        SpinBoxTy->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 74, 73);"));
        SpinBoxTy->setMinimum(-600.000000000000000);
        SpinBoxTy->setMaximum(600.000000000000000);
        SpinBoxAngle = new QDoubleSpinBox(centralwidget);
        SpinBoxAngle->setObjectName(QString::fromUtf8("SpinBoxAngle"));
        SpinBoxAngle->setGeometry(QRect(850, 300, 81, 41));
        SpinBoxAngle->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 74, 73);"));
        SpinBoxAngle->setMinimum(-360.000000000000000);
        SpinBoxAngle->setMaximum(360.000000000000000);
        SpinBoxSx = new QDoubleSpinBox(centralwidget);
        SpinBoxSx->setObjectName(QString::fromUtf8("SpinBoxSx"));
        SpinBoxSx->setGeometry(QRect(850, 410, 81, 41));
        SpinBoxSx->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 74, 73);"));
        SpinBoxSx->setMinimum(0.100000000000000);
        SpinBoxSx->setMaximum(10.000000000000000);
        SpinBoxSx->setSingleStep(0.100000000000000);
        SpinBoxSy = new QDoubleSpinBox(centralwidget);
        SpinBoxSy->setObjectName(QString::fromUtf8("SpinBoxSy"));
        SpinBoxSy->setGeometry(QRect(850, 470, 81, 41));
        SpinBoxSy->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 74, 73);"));
        SpinBoxSy->setMinimum(0.100000000000000);
        SpinBoxSy->setMaximum(10.000000000000000);
        SpinBoxSy->setSingleStep(0.100000000000000);
        btnTranslate = new QPushButton(centralwidget);
        btnTranslate->setObjectName(QString::fromUtf8("btnTranslate"));
        btnTranslate->setGeometry(QRect(970, 160, 111, 51));
        btnTranslate->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btnRotate = new QPushButton(centralwidget);
        btnRotate->setObjectName(QString::fromUtf8("btnRotate"));
        btnRotate->setGeometry(QRect(970, 300, 111, 51));
        btnRotate->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btnScale = new QPushButton(centralwidget);
        btnScale->setObjectName(QString::fromUtf8("btnScale"));
        btnScale->setGeometry(QRect(970, 430, 111, 51));
        btnScale->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btn_TRS = new QPushButton(centralwidget);
        btn_TRS->setObjectName(QString::fromUtf8("btn_TRS"));
        btn_TRS->setGeometry(QRect(1130, 160, 111, 51));
        btn_TRS->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btnRTS = new QPushButton(centralwidget);
        btnRTS->setObjectName(QString::fromUtf8("btnRTS"));
        btnRTS->setGeometry(QRect(1130, 300, 111, 51));
        btnRTS->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btnSRT = new QPushButton(centralwidget);
        btnSRT->setObjectName(QString::fromUtf8("btnSRT"));
        btnSRT->setGeometry(QRect(1130, 430, 111, 51));
        btnSRT->setStyleSheet(QString::fromUtf8("background-color: rgb(254, 215, 102);\n"
"color: #222831;"));
        btnColor = new QPushButton(centralwidget);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        btnColor->setGeometry(QRect(810, 560, 111, 51));
        btnColor->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 159, 183);"));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(960, 560, 111, 51));
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 159, 183);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(790, 150, 31, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(790, 200, 31, 21));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(774, 310, 71, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(790, 420, 31, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(790, 470, 51, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(930, 640, 171, 51));
        label_7->setStyleSheet(QString::fromUtf8("background-color: #0e1c36;"));
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(250, 660, 261, 41));
        label_10->setStyleSheet(QString::fromUtf8("background-color: #0e1c36;"));
        label_10->setAlignment(Qt::AlignCenter);
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
        btnFeelingLucky->setText(QCoreApplication::translate("MainWindow", "I'm feeling lucky", nullptr));
        radbtnEnableMouse->setText(QCoreApplication::translate("MainWindow", "Enable Mouse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Translation:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rotation:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Scaling:", nullptr));
        btnTranslate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        btnRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        btnScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        btn_TRS->setText(QCoreApplication::translate("MainWindow", "TRS", nullptr));
        btnRTS->setText(QCoreApplication::translate("MainWindow", "RTS", nullptr));
        btnSRT->setText(QCoreApplication::translate("MainWindow", "SRT", nullptr));
        btnColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Tx", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ty", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sx", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Sy", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "21132_Shreyash", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "A9. Basic Transformations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
