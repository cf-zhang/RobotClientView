#include "mainwidget.h"
#include <QPalette>
#include <QDebug>
MainWidget::MainWidget(QWidget *parent):QWidget(parent){
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(255, 0, 0, 127));
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/timg.png")));
    setPalette(palette);
//    qDebug()<<"in mainWidget\n";

}

MainWidget::~MainWidget(){

}

