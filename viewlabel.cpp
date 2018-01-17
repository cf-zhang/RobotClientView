#include "viewlabel.h"
#include <QBitmap>
#include <QPainter>
ViewLabel::ViewLabel(QWidget *parent) : QLabel(parent)
{
    setFixedSize(1200,600);
    setWindowFlags(Qt::FramelessWindowHint);
    setAutoFillBackground(true);
//    setFixedWidth(140);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(37, 109, 167));
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/timg.png")));
    setPalette(palette);
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(),20,20);

    setMask(bmp);
}


ViewLabel::~ViewLabel(){

}

