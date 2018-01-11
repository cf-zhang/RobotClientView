#ifndef WIFILABLE_H
#define WIFILABLE_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QImage>
#include "wifi_scan.h"
class WifiLabel : public QLabel
{
    Q_OBJECT
public:
    WifiLabel(QString wifiname="wlan0", QWidget *parent = nullptr);
    virtual ~WifiLabel();
private:
    QString getQrcImage(int strength);
signals:

public slots:
    void onTimeout();
private:
    QString wifiName;
    QImage *img;
    QTimer *timer;
    struct wifi_scan *wifi;
    struct station_info station;
};

#endif // WIFILABLE_H
