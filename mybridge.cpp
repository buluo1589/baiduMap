#include "mybridge.h"
#include <QMessageBox>
#include <QJSEngine>
#include <QDebug>

bridge::bridge()
{
}

void bridge::getCoordinate(QString lon, QString lat)
{
    emit Settext(lon,lat);
}
