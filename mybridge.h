#ifndef MYBRIDGE_H
#define MYBRIDGE_H

#include <QObject>
#include <QJSValue>
#include <functional>
#include <QVariant>

class bridge : public QObject
{
Q_OBJECT
public:
    bridge();
signals:
    void Settext(QString lon,QString lat);
public slots:
    void getCoordinate(QString lon,QString lat);
};

#endif // BRIDGE_H

