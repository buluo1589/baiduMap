#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>
#include "mybridge.h"
#include "GPS.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initWidget();
    void init_L();
    int Timer_ID;

private slots:
    void slot_showDate(QString longitude,QString latitude);

    void on_pb_send_clicked();
    void on_get_now_clicked();

    void Timer_func(QTimerEvent *event);

private:
    Ui::MainWindow *ui;

    bridge *mybridge;

    QString lon_now;
    QString lat_now;



};
#endif // MAINWINDOW_H
