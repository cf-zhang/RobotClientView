#include "batterylabel.h"
#include <QPixmap>
#include <QDebug>
BatteryLabel::BatteryLabel(QWidget *parent) : QLabel(parent)
{
    setFixedSize(100,100);
    //set the initial battery image
    img = new QImage();
    if(img->load(":/image/battery100.png"))
    {
//        qDebug()<<img->width()<<" "<<img->height();
        setPixmap(QPixmap::fromImage(img->scaled(size())));
    }

    //timer for periodically update the wifi signal strenth
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);
}



BatteryLabel::~BatteryLabel(){
    delete img;
//    delete
    delete timer;

}
//timer event for periodically get wifi signal strenth and
//change the image for the wifi lable. rate 1Hz
void BatteryLabel::onTimeout(){
    static int power = 0;
    power %= 100;
    QString qrc = QString(":/image/battery100.png");
//    int status;
//    status = 0;//////////////////////
//    if(0 < status){
        qrc = getQrcImage(power);/////
//    }
//    qDebug()<<" "<<power<<"\n";
    //set backgroud image and scaled with the lable
    if(img->load(qrc))
    {
        setPixmap(QPixmap::fromImage(img->scaled(size())));
    }
    power++;
}

QString BatteryLabel::getQrcImage(int power){

    if(power > 90) return ":/image/battery100.png";
    else if(power <= 90 && power > 80) return ":/image/battery90.png";
    else if(power <= 80 && power > 70) return ":/image/battery80.png";
    else if(power <= 70 && power > 60) return ":/image/battery70.png";
    else if(power <= 60 && power > 50) return ":/image/battery60.png";
    else if(power <= 50 && power > 40) return ":/image/battery50.png";
    else if(power <= 40 && power > 30) return ":/image/battery40.png";
    else if(power <= 30 && power > 20) return ":/image/battery30.png";
    else if(power <= 20 && power > 10) return ":/image/battery20.png";
    else if(power <= 10 && power > 5) return ":/image/battery10.png";
    else if(power <= 5 && power >= 0) return ":/image/battery5.png";

}
