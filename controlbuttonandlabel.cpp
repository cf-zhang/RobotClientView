#include "controlbuttonandlabel.h"
#include "mainwidget.h"
#include <QDebug>
#include <QBitmap>
#include <QPainter>
ControlButtonAndLabel::ControlButtonAndLabel(QString labelName, int type, QWidget *parent) : QWidget(parent)
{
    signalMapper = new QSignalMapper(this);

    vLayout = new QVBoxLayout(this);
    vLayout->setSpacing(50);
    btn = new QPushButton(this);

    btn->setStyleSheet("QPushButton{border:5px;background-color: rgb(0, 255, 255);}");//这句务必加上，否则看到的就是矩形了，而不是不规则图形了
    btn->setFlat(true);
    QPixmap *pm = new QPixmap(":/image/arrow1.png");
    btn->setIcon(*pm);
    btn->setIconSize(QPixmap(":/image/arrow1.png").size());

    //set the circle view
    QBitmap bmp(QPixmap(":/image/arrow1.png").size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawEllipse(bmp.rect());
    btn->setMask(bmp);


    label = new QLabel(this);

    QFont font("Microsoft YaHei", 20, QFont::Black);

    label->setFont(font);
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(37, 109, 167));
    label->setPalette(pa);
    label->setText(labelName);
    label->setAlignment(Qt::AlignCenter);
    //处理最终信号的槽
    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(ClickedButton(int)));

    vLayout->addWidget(btn);
    vLayout->addWidget(label);
    //原始信号传递给signalmapper
    connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
    //设置signalmapper的转发规则, 转发为参数为QString类型的信号， 并把text的内容作为参数传递。
    signalMapper->setMapping(btn, type);

    setLayout(vLayout);

    //timer for periodically update the wifi signal strenth
    curIcon = 1;
    isActive = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

}

ControlButtonAndLabel::~ControlButtonAndLabel()
{

    delete btn;
    delete label;
    delete signalMapper;

    delete vLayout;

}

void ControlButtonAndLabel::ClickedButton(int type)
{
    isActive = !isActive;

    switch (type) {
    case FOLLOWBUTTON:
        //
        MainWidget::followBtnControl();
        if(isActive)
        {
            label->setText("暂停跟随");
        }
        else
        {
            label->setText("跟随");
        }
        break;
    case BACKTOCHECKPOINT:
        //
        MainWidget::backToPkgBtnControl();
        break;
    case BACKTOSTAGE:
        //
        MainWidget::backToStageBtnControl();
        break;

    default:
        break;
    }
    if(isActive)
    {
        timer->start(200);//min /
    }
    else
    {
        timer->stop();//min /
    }
}

void ControlButtonAndLabel::onTimeout(){

//        qDebug()<<curIcon;
        QString qrc= QString(":/image/arrow%1.png").arg(curIcon);
        btn->setIcon(QPixmap(qrc));

        curIcon %= 3;
        curIcon++;

}
