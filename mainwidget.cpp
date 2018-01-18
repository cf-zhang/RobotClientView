#include "mainwidget.h"
#include <QPalette>
#include <QDebug>
#include <QVBoxLayout>
#include <QPainter>
MainWidget::MainWidget(QWidget *parent):QWidget(parent){

//    QPalette palette;
//    palette.setColor(QPalette::Background,QColor(255, 8, 8, 127));
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/background.png")));
//    setPalette(palette);
//    setAutoFillBackground(true);


//    qDebug()<<"in mainWidget\n";
    QVBoxLayout *vLayout = new QVBoxLayout();

    viewLabel = new ViewLabel(this);

    //  第0行，第1列开始，占2行3列
    vLayout->addWidget(viewLabel, 0, Qt::AlignTop|Qt::AlignCenter);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setSpacing(50);

    QFont font("Microsoft YaHei", 20, QFont::Black);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);

    QVBoxLayout *vLayout1 = new QVBoxLayout();
//    vLayout1->setSpacing(5);
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    QVBoxLayout *vLayout3 = new QVBoxLayout();

    follow = new ControlButton();//follow mode
    followLabel = new QLabel();
    followLabel->setFont(font);
    followLabel->setPalette(pa);
    followLabel->setText("跟随");
    followLabel->setAlignment(Qt::AlignCenter);
    vLayout1->addWidget(follow, 0, Qt::AlignBottom | Qt::AlignHCenter);
    vLayout1->addWidget(followLabel, 0, Qt::AlignTop | Qt::AlignHCenter);

    backToPackage = new ControlButton();//check plate
    backTopkgLabel = new QLabel();
    backTopkgLabel->setFont(font);
    backTopkgLabel->setPalette(pa);
    backTopkgLabel->setText("去打包台");
    backTopkgLabel->setAlignment(Qt::AlignCenter);
    vLayout2->addWidget(backToPackage, 0, Qt::AlignBottom | Qt::AlignHCenter);
    vLayout2->addWidget(backTopkgLabel, 0, Qt::AlignTop | Qt::AlignHCenter);


    backToStage = new ControlButton();//wait stage
    backTostageLabel = new QLabel();
    backTostageLabel->setFont(font);
    backTostageLabel->setPalette(pa);
    backTostageLabel->setText("去等待区");
    backTostageLabel->setAlignment(Qt::AlignCenter);
    vLayout3->addWidget(backToStage, 0, Qt::AlignBottom | Qt::AlignHCenter);
    vLayout3->addWidget(backTostageLabel, 0, Qt::AlignTop | Qt::AlignHCenter);

    connect(follow, SIGNAL(clicked()), this, SLOT(followBtnControl()));
    connect(backToPackage, SIGNAL(clicked()), this, SLOT(backToPkgBtnControl()));
    connect(backToStage, SIGNAL(clicked()), this, SLOT(backToStageBtnControl()));

    hLayout->addLayout(vLayout1);
    hLayout->addLayout(vLayout2);
    hLayout->addLayout(vLayout3);
    vLayout->addLayout(hLayout, 0);
    setLayout(vLayout);

}
void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/image/background.png"));
}
MainWidget::~MainWidget(){
    delete viewLabel;
    delete follow;
    delete followLabel;
    delete backToPackage;
    delete backTopkgLabel;
    delete backToStage;
    delete backTostageLabel;
}

void MainWidget::followBtnControl()
{
    qDebug()<<"in followBtnControl\n";

    static bool flag = false;
    flag = !flag;
    if(flag)
    {
        followLabel->setText("暂停跟随");
        follow->startRotate();
        backToPackage->setEnabled(false);
        backToStage->setEnabled(false);
        viewLabel->setBackgroundPixmap(":/image/tracking.png");

    }
    else
    {
        followLabel->setText("跟随");
        follow->stopRotate();
        backToPackage->setEnabled(true);
        backToStage->setEnabled(true);
        viewLabel->setBackgroundPixmap(":/image/waitforman.png");
    }
}
void MainWidget::backToPkgBtnControl()
{
    qDebug()<<"in backToPkgBtnControl\n";
    static bool flag = false;
    flag = !flag;
    if(flag)
    {
        backTopkgLabel->setText("暂停导航");
        backToPackage->startRotate();
        follow->setEnabled(false);
        backToStage->setEnabled(false);
        viewLabel->setBackgroundPixmap(":/image/backtopackage.png");

    }
    else
    {
        backTopkgLabel->setText("去打包台");
        backToPackage->stopRotate();
        follow->setEnabled(true);
        backToStage->setEnabled(true);
        viewLabel->setBackgroundPixmap(":/image/standby.png");
    }
}
void MainWidget::backToStageBtnControl()
{
    qDebug()<<"in backToStageBtnControl\n";
    static bool flag = false;
    flag = !flag;
    if(flag)
    {
        backTostageLabel->setText("暂停导航");
        backToStage->startRotate();
        backToPackage->setEnabled(false);
        follow->setEnabled(false);
        viewLabel->setBackgroundPixmap(":/image/backtopackagebuffer.png");

    }
    else
    {
        backTostageLabel->setText("去等待区");
        backToStage->stopRotate();
        backToPackage->setEnabled(true);
        follow->setEnabled(true);
        viewLabel->setBackgroundPixmap(":/image/standby.png");
    }

}
