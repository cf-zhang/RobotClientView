#include "wifilabe.h"

#include <QDebug>
#include <QString>

WifiLable::WifiLable(QString wifiname, QWidget *parent) : QLabel(parent),wifiName(wifiname){
    resize(40,40);
    //set the initial wifi strenth image
    img = new QImage();
    if(img->load(":/image/wifi-gray.png"))
    {
        qDebug()<<img->width()<<" "<<img->height();
        setPixmap(QPixmap::fromImage(img->scaled(size())));
    }

    wifi=wifi_scan_init(wifiName.toStdString().c_str());

    //timer for periodically update the wifi signal strenth
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);
}

WifiLable::~WifiLable(){
    delete img;
    //free the library resources
    wifi_scan_close(wifi);
}
//timer event for periodically get wifi signal strenth and
//change the image for the wifi lable. rate 1Hz
void WifiLable::onTimeout(){
    QString qrc = QString(":/image/wifi-gray.png");
    int status;
    status = wifi_scan_station(wifi, &station);
    if(0 < status){
        qrc = getQrcImage(station.signal_dbm);
    }
    qDebug()<<station.signal_dbm<<"\n";
    //set backgroud image and scaled with the lable
    if(img->load(qrc))
    {
        setPixmap(QPixmap::fromImage(img->scaled(size())));
    }

}

QString WifiLable::getQrcImage(int strength){
    if(strength <= -30 && strength > -67) return ":/image/wifi4.png";
    else if(strength <= -67 && strength > -70) return ":/image/wifi3.png";
    else if(strength <= -70 && strength > -80) return ":/image/wifi2.png";
    else if(strength <= -80 && strength > -90) return ":/image/wifi1.png";
    else return ":/image/wifi0.png";
}
