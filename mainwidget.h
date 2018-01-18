#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "viewlabel.h"
#include "controlbutton.h"
#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
class MainWidget :public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    virtual ~MainWidget();
    void paintEvent(QPaintEvent *event);
public slots:
    void followBtnControl();
    void backToPkgBtnControl();
    void backToStageBtnControl();
private:
    ViewLabel *viewLabel;
    ControlButton *follow;//follow mode
    QLabel        *followLabel;
    ControlButton *backToPackage;//check plate
    QLabel        *backTopkgLabel;
    ControlButton *backToStage;//wait stage
    QLabel        *backTostageLabel;

};

#endif // MAINWIDGET_H
