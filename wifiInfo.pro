#-------------------------------------------------
#
# Project created by QtCreator 2018-01-08T20:02:55
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wifiInfo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lmnl

SOURCES += \
        main.cpp \
    wifi_scan.c \
    wifilabel.cpp \
    timelabel.cpp \
    topbarwidget.cpp \
    mainwidget.cpp \
    splittermanager.cpp \
    settingbutton.cpp \
    customsplash.cpp \
    aboutthis.cpp \
    batterylabel.cpp \
    viewlabel.cpp \
    controlbutton.cpp

HEADERS += \
    wifi_scan.h \
    timelabel.h \
    wifilabel.h \
    topbarwidget.h \
    mainwidget.h \
    splittermanager.h \
    settingbutton.h \
    customsplash.h \
    power.h \
    aboutthis.h \
    batterylabel.h \
    viewlabel.h \
    controlbutton.h

RESOURCES += \
    image.qrc
