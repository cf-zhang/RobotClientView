#ifndef VIEWLABEL_H
#define VIEWLABEL_H

#include <QLabel>
class ViewLabel :public QLabel
{
    Q_OBJECT
public:
    ViewLabel(QWidget *parent = nullptr);
    virtual ~ViewLabel();
private:

signals:

public slots:

private:


};

#endif // VIEWLABEL_H
