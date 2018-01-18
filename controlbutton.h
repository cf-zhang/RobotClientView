#ifndef ControlButton_H
#define ControlButton_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QTimer>
class ControlButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ControlButton(QWidget *parent = nullptr);
    virtual ~ControlButton();
    void startRotate();
    void stopRotate();
signals:

public slots:
    void onTimeout();
private:
    QTimer *timer;
    int curIcon;
    bool isActive;
};

#endif // ControlButton_H

