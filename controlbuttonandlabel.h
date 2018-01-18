#ifndef CONTROLBUTTONANDLABEL_H
#define CONTROLBUTTONANDLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QObject>
#include <QTimer>
class ControlButtonAndLabel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlButtonAndLabel(QString labelName, int, QWidget *parent = nullptr);
    virtual ~ControlButtonAndLabel();
    enum {
        FOLLOWBUTTON=0,
        BACKTOSTAGE,
        BACKTOCHECKPOINT
    };

signals:

public slots:
    void ClickedButton(int);
    void onTimeout();
private:
    QSignalMapper *signalMapper;
    QPushButton *btn;
    QLabel      *label;
    QVBoxLayout *vLayout;
    QTimer *timer;
    int curIcon;
    bool isActive;

};

#endif // CONTROLBUTTONANDLABEL_H

