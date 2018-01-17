#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "viewlabel.h"
#include "controlbuttonandlabel.h"
#include <QWidget>

class MainWidget :public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    virtual ~MainWidget();
    static void followBtnControl();
    static void backToPkgBtnControl();
    static void backToStageBtnControl();
private:
    ViewLabel *viewLabel;
    ControlButtonAndLabel *follow;//follow mode
    ControlButtonAndLabel *backToPackage;//check plate
    ControlButtonAndLabel *backToStage;//wait stage


};

#endif // MAINWIDGET_H
