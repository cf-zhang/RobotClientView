#ifndef CONTROLBUTTONANDLABEL_H
#define CONTROLBUTTONANDLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QSignalMapper>
#include <QVBoxLayout>
class ControlButtonAndLabel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlButtonAndLabel(QString labelName, void (*callFunc)(), QWidget *parent = nullptr);
    virtual ~ControlButtonAndLabel();
signals:

public slots:
    void ClickedButton(const QString&);
private:
    QSignalMapper *signalMapper;
    QPushButton *btn;
    QLabel      *label;
    QVBoxLayout *vLayout;
};

#endif // CONTROLBUTTONANDLABEL_H
