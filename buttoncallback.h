#ifndef BUTTONCALLBACK_H
#define BUTTONCALLBACK_H

#include <QObject>

class ButtonCallBack : public QObject
{
    Q_OBJECT
public:
    explicit ButtonCallBack(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BUTTONCALLBACK_H