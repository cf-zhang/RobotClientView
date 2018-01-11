#ifndef SETTINGBUTTON_H
#define SETTINGBUTTON_H
#include <QObject>
#include <QImage>
#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QAction>
class SettingButton : public QPushButton
{
    Q_OBJECT
public:
    SettingButton(QWidget *parent = nullptr);
    virtual ~SettingButton();
private:
    QMenu *settingMenu;
    QAction *aboutDevice;
signals:
public slots:
};

#endif // SETTINGBUTTON_H

