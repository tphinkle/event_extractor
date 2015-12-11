/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *Plot_Widget;
    QPushButton *SaveEvent_Button;
    QPushButton *LoadFile_Button;
    QPushButton *Zoom_In_x_Button;
    QPushButton *Zoom_Out_x_Button;
    QPushButton *Zoom_In_y_Button;
    QPushButton *Zoom_Out_y_Button;
    QScrollBar *x_Bar;
    QScrollBar *y_Bar;
    QPlainTextEdit *EventFile_Label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1051, 769);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Plot_Widget = new QCustomPlot(centralWidget);
        Plot_Widget->setObjectName(QStringLiteral("Plot_Widget"));
        Plot_Widget->setGeometry(QRect(90, 50, 811, 591));
        SaveEvent_Button = new QPushButton(centralWidget);
        SaveEvent_Button->setObjectName(QStringLiteral("SaveEvent_Button"));
        SaveEvent_Button->setGeometry(QRect(920, 80, 99, 91));
        LoadFile_Button = new QPushButton(centralWidget);
        LoadFile_Button->setObjectName(QStringLiteral("LoadFile_Button"));
        LoadFile_Button->setGeometry(QRect(920, 180, 99, 91));
        Zoom_In_x_Button = new QPushButton(centralWidget);
        Zoom_In_x_Button->setObjectName(QStringLiteral("Zoom_In_x_Button"));
        Zoom_In_x_Button->setGeometry(QRect(90, 660, 41, 41));
        Zoom_Out_x_Button = new QPushButton(centralWidget);
        Zoom_Out_x_Button->setObjectName(QStringLiteral("Zoom_Out_x_Button"));
        Zoom_Out_x_Button->setGeometry(QRect(130, 660, 41, 41));
        Zoom_In_y_Button = new QPushButton(centralWidget);
        Zoom_In_y_Button->setObjectName(QStringLiteral("Zoom_In_y_Button"));
        Zoom_In_y_Button->setGeometry(QRect(30, 600, 41, 41));
        Zoom_Out_y_Button = new QPushButton(centralWidget);
        Zoom_Out_y_Button->setObjectName(QStringLiteral("Zoom_Out_y_Button"));
        Zoom_Out_y_Button->setGeometry(QRect(30, 560, 41, 41));
        x_Bar = new QScrollBar(centralWidget);
        x_Bar->setObjectName(QStringLiteral("x_Bar"));
        x_Bar->setGeometry(QRect(90, 640, 811, 20));
        x_Bar->setOrientation(Qt::Horizontal);
        y_Bar = new QScrollBar(centralWidget);
        y_Bar->setObjectName(QStringLiteral("y_Bar"));
        y_Bar->setGeometry(QRect(70, 50, 20, 591));
        y_Bar->setOrientation(Qt::Vertical);
        EventFile_Label = new QPlainTextEdit(centralWidget);
        EventFile_Label->setObjectName(QStringLiteral("EventFile_Label"));
        EventFile_Label->setGeometry(QRect(90, 10, 301, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1051, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        SaveEvent_Button->setText(QApplication::translate("MainWindow", "Save Event", 0));
        LoadFile_Button->setText(QApplication::translate("MainWindow", "Load File", 0));
        Zoom_In_x_Button->setText(QApplication::translate("MainWindow", "><", 0));
        Zoom_Out_x_Button->setText(QApplication::translate("MainWindow", "<>", 0));
        Zoom_In_y_Button->setText(QApplication::translate("MainWindow", "V^", 0));
        Zoom_Out_y_Button->setText(QApplication::translate("MainWindow", "^V", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
