#ifndef ABOUTTHIS_H
#define ABOUTTHIS_H

#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
class AboutThis : public QMessageBox
{
    Q_OBJECT
public:
    explicit AboutThis(QWidget *parent = nullptr);
    virtual ~AboutThis();
signals:

public slots:
//    void showAboutThis();
private:

};

#endif // ABOUTTHIS_H
