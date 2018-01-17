#include "controlbuttonandlabel.h"
#include <QDebug>
ControlButtonAndLabel::ControlButtonAndLabel(QString labelName, void (*callFunc)(), QWidget *parent) : QWidget(parent)
{
    signalMapper = new QSignalMapper(this);

    vLayout = new QVBoxLayout(this);

    btn = new QPushButton(this);

    label = new QLabel(this);
    label->setText(labelName);
    //处理最终信号的槽
    connect(signalMapper, SIGNAL(mapped(const QString&)),
            this, SLOT(ClickedButton(const QString&)));

    vLayout->addWidget(btn);
    vLayout->addWidget(label);
    //原始信号传递给signalmapper
    connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
    //设置signalmapper的转发规则, 转发为参数为QString类型的信号， 并把text的内容作为参数传递。
    signalMapper->setMapping(btn, callFunc);

    setLayout(vLayout);
}

ControlButtonAndLabel::~ControlButtonAndLabel()
{

    delete btn;
    delete label;
    delete signalMapper;

    delete vLayout;

}


void ControlButtonAndLabel::ClickedButton(void (*callFunc)())
{
//    qDebug()<<text<<"\n";
    callFunc();
}
