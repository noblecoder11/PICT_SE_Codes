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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *drawingArea;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxX1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxY1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxX2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBoxY2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPlotLine;
    QPushButton *btnScanLine;
    QPushButton *btnColor;
    QPushButton *btnClear;
    QMenuBar *menubar;
    QMenu *menuAssignment_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        drawingArea = new QLabel(centralwidget);
        drawingArea->setObjectName(QString::fromUtf8("drawingArea"));
        drawingArea->setGeometry(QRect(50, 50, 461, 411));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(530, 50, 211, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBoxX1 = new QSpinBox(widget);
        spinBoxX1->setObjectName(QString::fromUtf8("spinBoxX1"));
        spinBoxX1->setMaximum(400);

        horizontalLayout->addWidget(spinBoxX1);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        spinBoxY1 = new QSpinBox(widget);
        spinBoxY1->setObjectName(QString::fromUtf8("spinBoxY1"));
        spinBoxY1->setMaximum(400);

        horizontalLayout_2->addWidget(spinBoxY1);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        spinBoxX2 = new QSpinBox(widget);
        spinBoxX2->setObjectName(QString::fromUtf8("spinBoxX2"));
        spinBoxX2->setMaximum(400);

        horizontalLayout_3->addWidget(spinBoxX2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        spinBoxY2 = new QSpinBox(widget);
        spinBoxY2->setObjectName(QString::fromUtf8("spinBoxY2"));
        spinBoxY2->setMaximum(400);

        horizontalLayout_4->addWidget(spinBoxY2);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(590, 270, 101, 151));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPlotLine = new QPushButton(widget1);
        btnPlotLine->setObjectName(QString::fromUtf8("btnPlotLine"));

        verticalLayout->addWidget(btnPlotLine);

        btnScanLine = new QPushButton(widget1);
        btnScanLine->setObjectName(QString::fromUtf8("btnScanLine"));

        verticalLayout->addWidget(btnScanLine);

        btnColor = new QPushButton(widget1);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));

        verticalLayout->addWidget(btnColor);

        btnClear = new QPushButton(widget1);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        verticalLayout->addWidget(btnClear);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuAssignment_4 = new QMenu(menubar);
        menuAssignment_4->setObjectName(QString::fromUtf8("menuAssignment_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAssignment_4->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawingArea->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "y2", nullptr));
        btnPlotLine->setText(QCoreApplication::translate("MainWindow", "Plot Line", nullptr));
        btnScanLine->setText(QCoreApplication::translate("MainWindow", "Scan Line", nullptr));
        btnColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuAssignment_4->setTitle(QCoreApplication::translate("MainWindow", "Assignment 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
