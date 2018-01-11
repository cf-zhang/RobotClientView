#include "topbarwidget.h"

TopBarWidget::TopBarWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background,QColor(0, 0, 0));
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/timg.png")));
    setPalette(palette);
    //top bars
    wifilabel = new WifiLabel("wlp2s0");
    timelabel = new TimeLabel();
    settingbutton = new SettingButton();
    //layout the bars with 30 spacing
    layout = new QHBoxLayout();
    layout->setSpacing(30);
    layout->addStretch();
    layout->addWidget(timelabel,0,Qt::AlignRight);
    layout->addWidget(wifilabel,0,Qt::AlignRight);
    layout->addWidget(settingbutton,0,Qt::AlignRight);

    setLayout(layout);
}

TopBarWidget::~TopBarWidget(){
    delete wifilabel;
    delete timelabel;
    delete settingbutton;
    delete layout;
}
