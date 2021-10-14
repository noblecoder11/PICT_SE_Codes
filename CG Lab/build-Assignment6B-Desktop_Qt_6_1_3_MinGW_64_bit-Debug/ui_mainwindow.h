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
    QLabel *x1Label;
    QSpinBox *spinX1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *y1Label;
    QSpinBox *spinY1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *x2Label;
    QSpinBox *spinX2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *y2Label;
    QSpinBox *spinY2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPlot;
    QPushButton *btnColor;
    QPushButton *btnClear;
    QMenuBar *menubar;
    QMenu *menuAssignment_6_b;
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
        drawingArea->setGeometry(QRect(30, 20, 451, 451));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(550, 40, 221, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        x1Label = new QLabel(widget);
        x1Label->setObjectName(QString::fromUtf8("x1Label"));
        x1Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(x1Label);

        spinX1 = new QSpinBox(widget);
        spinX1->setObjectName(QString::fromUtf8("spinX1"));
        spinX1->setMaximum(400);

        horizontalLayout->addWidget(spinX1);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        y1Label = new QLabel(widget);
        y1Label->setObjectName(QString::fromUtf8("y1Label"));
        y1Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(y1Label);

        spinY1 = new QSpinBox(widget);
        spinY1->setObjectName(QString::fromUtf8("spinY1"));
        spinY1->setMaximum(400);

        horizontalLayout_2->addWidget(spinY1);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        x2Label = new QLabel(widget);
        x2Label->setObjectName(QString::fromUtf8("x2Label"));
        x2Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(x2Label);

        spinX2 = new QSpinBox(widget);
        spinX2->setObjectName(QString::fromUtf8("spinX2"));
        spinX2->setMaximum(400);

        horizontalLayout_3->addWidget(spinX2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        y2Label = new QLabel(widget);
        y2Label->setObjectName(QString::fromUtf8("y2Label"));
        y2Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(y2Label);

        spinY2 = new QSpinBox(widget);
        spinY2->setObjectName(QString::fromUtf8("spinY2"));
        spinY2->setMaximum(400);

        horizontalLayout_4->addWidget(spinY2);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(610, 220, 111, 151));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPlot = new QPushButton(widget1);
        btnPlot->setObjectName(QString::fromUtf8("btnPlot"));

        verticalLayout->addWidget(btnPlot);

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
        menuAssignment_6_b = new QMenu(menubar);
        menuAssignment_6_b->setObjectName(QString::fromUtf8("menuAssignment_6_b"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAssignment_6_b->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawingArea->setText(QString());
        x1Label->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        y1Label->setText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        x2Label->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        y2Label->setText(QCoreApplication::translate("MainWindow", "y2", nullptr));
        btnPlot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        btnColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuAssignment_6_b->setTitle(QCoreApplication::translate("MainWindow", "Assignment 6 B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
