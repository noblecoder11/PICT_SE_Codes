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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *drawingArea;
    QPushButton *btnClear;
    QPushButton *btnColor;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnPlot6A;
    QPushButton *btnPlot6B;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *spinBoxX1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *spinBoxY1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBoxX2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *spinBoxY2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QSpinBox *spinBoxRadius;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBoxXc;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBoxYc;
    QMenuBar *menubar;
    QMenu *menuAssingment_6;
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
        drawingArea->setGeometry(QRect(30, 30, 451, 431));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(492, 415, 80, 25));
        btnColor = new QPushButton(centralwidget);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        btnColor->setGeometry(QRect(492, 383, 80, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 460, 131, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setBold(true);
        label->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(492, 349, 169, 27));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        btnPlot6A = new QPushButton(layoutWidget);
        btnPlot6A->setObjectName(QString::fromUtf8("btnPlot6A"));

        horizontalLayout_10->addWidget(btnPlot6A);

        btnPlot6B = new QPushButton(layoutWidget);
        btnPlot6B->setObjectName(QString::fromUtf8("btnPlot6B"));

        horizontalLayout_10->addWidget(btnPlot6B);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(492, 181, 162, 86));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_5);

        spinBoxX1 = new QSpinBox(layoutWidget1);
        spinBoxX1->setObjectName(QString::fromUtf8("spinBoxX1"));
        spinBoxX1->setMaximum(400);

        horizontalLayout_4->addWidget(spinBoxX1);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_6);

        spinBoxY1 = new QSpinBox(layoutWidget1);
        spinBoxY1->setObjectName(QString::fromUtf8("spinBoxY1"));
        spinBoxY1->setMaximum(400);

        horizontalLayout_5->addWidget(spinBoxY1);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_7);

        spinBoxX2 = new QSpinBox(layoutWidget1);
        spinBoxX2->setObjectName(QString::fromUtf8("spinBoxX2"));
        spinBoxX2->setMaximum(400);

        horizontalLayout_6->addWidget(spinBoxX2);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_8);

        spinBoxY2 = new QSpinBox(layoutWidget1);
        spinBoxY2->setObjectName(QString::fromUtf8("spinBoxY2"));
        spinBoxY2->setMaximum(400);

        horizontalLayout_7->addWidget(spinBoxY2);


        gridLayout->addLayout(horizontalLayout_7, 2, 1, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(490, 80, 111, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_4);

        spinBoxRadius = new QSpinBox(layoutWidget2);
        spinBoxRadius->setObjectName(QString::fromUtf8("spinBoxRadius"));
        spinBoxRadius->setMaximum(1000);

        horizontalLayout_8->addWidget(spinBoxRadius);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(494, 14, 220, 52));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        spinBoxXc = new QSpinBox(layoutWidget3);
        spinBoxXc->setObjectName(QString::fromUtf8("spinBoxXc"));
        spinBoxXc->setMaximum(400);

        horizontalLayout->addWidget(spinBoxXc);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        spinBoxYc = new QSpinBox(layoutWidget3);
        spinBoxYc->setObjectName(QString::fromUtf8("spinBoxYc"));
        spinBoxYc->setMaximum(400);

        horizontalLayout_2->addWidget(spinBoxYc);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuAssingment_6 = new QMenu(menubar);
        menuAssingment_6->setObjectName(QString::fromUtf8("menuAssingment_6"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAssingment_6->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawingArea->setText(QString());
        btnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        btnColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "21132_Shreyash", nullptr));
        btnPlot6A->setText(QCoreApplication::translate("MainWindow", "Plot 6a", nullptr));
        btnPlot6B->setText(QCoreApplication::translate("MainWindow", "Plot 6b", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "For Assingnment 6B", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Y2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "For Assingnment 6A", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Xcenter", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ycenter", nullptr));
        menuAssingment_6->setTitle(QCoreApplication::translate("MainWindow", "Assingment 6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
