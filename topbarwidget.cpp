#include "topbarwidget.h"

TopBarWidget::TopBarWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setFixedWidth(140);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(37, 109, 167));
//    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/timg.png")));
    setPalette(palette);
    //top bars
    wifilabel = new WifiLabel("wlp2s0");
    timelabel = new TimeLabel(this);
    batterlabel = new BatteryLabel(this);
    settingbutton = new SettingButton(this);
    //layout the bars with 30 spacing
    layout = new QVBoxLayout();
    layout->setSpacing(50);

    layout->addWidget(timelabel,0,Qt::AlignTop | Qt::AlignCenter);
    layout->addWidget(wifilabel,0,Qt::AlignTop | Qt::AlignCenter);
    layout->addWidget(batterlabel, 0, Qt::AlignTop | Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(settingbutton,0,Qt::AlignBottom | Qt::AlignCenter);

    setLayout(layout);
}

TopBarWidget::~TopBarWidget(){
    delete wifilabel;
    delete timelabel;
    delete settingbutton;
    delete batterlabel;
    delete layout;
}
