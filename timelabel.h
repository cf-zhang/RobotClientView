#ifndef TIMELABEL_H
#define TIMELABEL_H

#include <QObject>
#include <QLabel>
#include <QTimer>

class TimeLabel : public QLabel
{
    Q_OBJECT
public:
    TimeLabel(QWidget *parent = nullptr);
    virtual ~TimeLabel();
private:
    QTimer *timer;
signals:

public slots:
    void onTimeout();
};

#endif // TIMELABLE_H
