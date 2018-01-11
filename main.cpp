#include "splittermanager.h"
#include "mainwidget.h"
#include "topbarwidget.h"
#include "mainwidget.h"
#include <QApplication>
#include <QSplitter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplitterManager sm;

    return a.exec();
}
