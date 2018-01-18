#include "controlbutton.h"
#include "mainwidget.h"
#include <QDebug>
#include <QBitmap>
#include <QPainter>

ControlButton::ControlButton(QWidget *parent) : QPushButton(parent)
{
    setStyleSheet("QPushButton{border:5px;}");//这句务必加上，否则看到的就是矩形了，而不是不规则图形了

    setFlat(true);
    QPixmap *pm = new QPixmap(":/image/arrow1.png");
    setIcon(*pm);
    setIconSize(QPixmap(":/image/arrow1.png").size());

    //set the circle view
    QBitmap bmp(QPixmap(":/image/arrow1.png").size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawEllipse(bmp.rect());
//    setMask(bmp);


    //timer for periodically update the wifi signal strenth
    curIcon = 1;
    isActive = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

ControlButton::~ControlButton()
{
    delete timer;
}

void ControlButton::startRotate()
{
    timer->start(200);
}
void ControlButton::stopRotate()
{
    timer->stop();
}


void ControlButton::onTimeout(){

//        qDebug()<<curIcon;
    QString qrc= QString(":/image/arrow%1.png").arg(curIcon);
    setIcon(QPixmap(qrc));

    curIcon %= 3;
    curIcon++;

}
