#include "splittermanager.h"


SplitterManager::SplitterManager()
{
    splitter = new QSplitter(Qt::Vertical,0);
    QList<int> widgetSizes;
    widgetSizes << 50 << 520;
    splitter->setSizes(widgetSizes);
    splitter->setHandleWidth(5);
    splitter->setStyleSheet("QSplitter::handle { background-color: black }");
    topWidget = new TopBarWidget();
    mainWidget = new MainWidget();

    splitter->addWidget(topWidget);
    splitter->addWidget(mainWidget);

    splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,24);
    splitter->showFullScreen();
}

SplitterManager::~SplitterManager()
{
    delete topWidget;
    delete mainWidget;
    delete splitter;
}
