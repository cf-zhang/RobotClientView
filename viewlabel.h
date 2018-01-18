#ifndef VIEWLABEL_H
#define VIEWLABEL_H
#include <QString>
#include <QLabel>
class ViewLabel :public QLabel
{
    Q_OBJECT
public:
    ViewLabel(QWidget *parent = nullptr);
    virtual ~ViewLabel();
    void setBackgroundPixmap(QString qrc);
private:

signals:

public slots:

private:


};

#endif // VIEWLABEL_H
