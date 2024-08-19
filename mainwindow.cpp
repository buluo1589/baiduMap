#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWidget()
{
    double lon=0;
    double lat=0;
    //创建MyBridge对象用于与JS交互
    //m_bridge = new MyBridge();

    //将单个对象注册到QWebChannel,注册名为bridge
    QWebChannel *channel = new QWebChannel(this);
    //channel->registerObject(QString("bridge"),(QObject*)m_bridge);
    //ui->wg_map->page()->setWebChannel(channel);

    bridge *mybridge = new bridge();     //创建通道对象用于JS交互
    channel = new QWebChannel(this);    //创建通道用于JS交互
    channel->registerObject("my_bridge",(QObject*)mybridge);
    ui->wg_map->page()->setWebChannel(channel);

    //加载HTML文件
    ui->wg_map->page()->load(QUrl("qrc:/baiduMap.html"));

    GET_GPS(&lon,&lat);

    lon_now = QString::number(lon, 'f', 7);
    lat_now = QString::number(lat, 'f', 7);

    //关联信号和槽函数
    connect(ui->wg_map, &QWebEngineView::loadFinished, this,&MainWindow::init_L);
    connect(mybridge,SIGNAL(Settext(QString,QString)),this,SLOT(slot_showDate(QString,QString)));
    // connect(Timer_, SIGNAL(timeout()), this, SLOT(Timer_func()));

    Timer_ID=startTimer(60000);
}

void MainWindow::init_L()
{
    QString cmd = QString("init_L(%1,%2)").arg(lon_now).arg(lat_now);
    ui->wg_map->page()->runJavaScript(cmd);
}

void MainWindow::slot_showDate(QString longitude,QString latitude)
{
    double lon=longitude.toDouble();
    double lat=latitude.toDouble();

    ui->le_longitude->setText(QString::number(lon, 'f', 15));
    ui->le_latitude->setText(QString::number(lat, 'f', 15));
}

void MainWindow::on_pb_send_clicked()
{
    QString cmd = QString("Set_target(%1,%2)").arg(ui->le_longitude->text()).arg(ui->le_latitude->text());
    ui->wg_map->page()->runJavaScript(cmd);
}

void MainWindow::on_get_now_clicked()
{
    QString cmd = QString("Set_cent(%1,%2)").arg(lon_now).arg(lat_now);
    ui->wg_map->page()->runJavaScript(cmd);
}

void MainWindow::Timer_func(QTimerEvent *event)
{
    double lon=0;
    double lat=0;
    GET_GPS(&lon,&lat);

    lon_now = QString::number(lon, 'f', 15);
    lat_now = QString::number(lat, 'f', 15);

    QString cmd = QString("Set_start(%1,%2)").arg(lon_now).arg(lat_now);
    ui->wg_map->page()->runJavaScript(cmd);
}
