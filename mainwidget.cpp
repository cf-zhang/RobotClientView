#include "mainwidget.h"

#include <QPalette>
#include <QDebug>

#include <QGridLayout>
MainWidget::MainWidget(QWidget *parent):QWidget(parent){
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(255, 8, 8, 127));
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/timg.png")));
    setPalette(palette);
//    qDebug()<<"in mainWidget\n";
    QVBoxLayout *vLayout = new QVBoxLayout(this);


    viewLabel = new ViewLabel(this);

    //  第0行，第1列开始，占2行3列
    vLayout->addWidget(viewLabel, 0, Qt::AlignTop|Qt::AlignCenter);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->setSpacing(50);
    follow = new ControlButtonAndLabel("跟随",&MainWidget::followBtnControl,this);//follow mode
    backToPackage = new ControlButtonAndLabel("去打包台",&MainWidget::backToPkgBtnControl,this);//check plate
    backToStage = new ControlButtonAndLabel("去等待区", &MainWidget::backToStageBtnControl,this);//wait stage
    hLayout->addWidget(follow, 0, Qt::AlignCenter);
    hLayout->addWidget(backToPackage, 0, Qt::AlignCenter);
    hLayout->addWidget(backToStage, 0, Qt::AlignCenter);

    vLayout->addLayout(hLayout, 0);
}

MainWidget::~MainWidget(){

}

void MainWidget::followBtnControl()
{
    qDebug()<<"in followBtnControl\n";
}
void MainWidget::backToPkgBtnControl()
{
    qDebug()<<"in backToPkgBtnControl\n";
}
void MainWidget::backToStageBtnControl()
{
    qDebug()<<"in backToStageBtnControl\n";
}
