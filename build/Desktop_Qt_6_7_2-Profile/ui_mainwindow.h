/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *le_latitude;
    QLineEdit *le_longitude;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pb_send;
    QWebEngineView *wg_map;
    QPushButton *get_now;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        le_latitude = new QLineEdit(centralwidget);
        le_latitude->setObjectName("le_latitude");
        le_latitude->setGeometry(QRect(370, 470, 181, 22));
        le_longitude = new QLineEdit(centralwidget);
        le_longitude->setObjectName("le_longitude");
        le_longitude->setGeometry(QRect(100, 470, 201, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 470, 57, 14));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 470, 57, 14));
        pb_send = new QPushButton(centralwidget);
        pb_send->setObjectName("pb_send");
        pb_send->setGeometry(QRect(560, 470, 80, 22));
        wg_map = new QWebEngineView(centralwidget);
        wg_map->setObjectName("wg_map");
        wg_map->setGeometry(QRect(20, 20, 751, 421));
        get_now = new QPushButton(centralwidget);
        get_now->setObjectName("get_now");
        get_now->setGeometry(QRect(680, 470, 80, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "latitude", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "longitude", nullptr));
        pb_send->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        get_now->setText(QCoreApplication::translate("MainWindow", "Now", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
