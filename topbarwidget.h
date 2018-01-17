#ifndef TOPBARWIDGET_H
#define TOPBARWIDGET_H
#include <QVBoxLayout>
#include <QWidget>
#include "wifilabel.h"
#include "timelabel.h"
#include "batterylabel.h"
#include "settingbutton.h"
class TopBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopBarWidget(QWidget *parent = nullptr);
    virtual ~TopBarWidget();
signals:

public slots:
private:
    QVBoxLayout *layout;
    WifiLabel *wifilabel;
    TimeLabel *timelabel;
    BatteryLabel *batterlabel;
    SettingButton *settingbutton;
};

#endif // TOPBARWIDGET_H
