#ifndef TOPBARWIDGET_H
#define TOPBARWIDGET_H
#include <QHBoxLayout>
#include <QWidget>
#include "wifilabel.h"
#include "timelabel.h"
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
    QHBoxLayout *layout;
    WifiLabel *wifilabel;
    TimeLabel *timelabel;
    SettingButton *settingbutton;
};

#endif // TOPBARWIDGET_H
