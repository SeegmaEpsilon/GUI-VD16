#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T09:44:01
#
#-------------------------------------------------

QT  += core gui network

TARGET = test_mx_adc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/udpserverthread.cpp \
    src/udpserver.cpp \
    src/tu_test.cpp

HEADERS  += \        
    src/udpserverthread.h \
    src/udpserver.h \
    src/tu_test.h \
    mainwindow.h \
    ui_mainwindow.h

FORMS    += mainwindow.ui

RC_FILE = ./src/myicon.rc

OTHER_FILES +=

INCLUDEPATH += $$PWD/inc $$PWD/src
