#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T22:58:29
#
#-------------------------------------------------

QT       += core gui network xml xmlpatterns
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xPLSimulator
TEMPLATE = app

INCLUDEPATH += ../lib \
#               /usr/local/include

#LIBS += -L/usr/local/lib/ -lxPL

OBJECTS_DIR = ../../build/xPLSimulator/obj
MOC_DIR = ../../build/xPLSimulator/moc
DESTDIR = ../../bin

CONFIG(debug, debug|release) {
    TARGET = xPLSimulatord
}
else {
    TARGET = xPLSimulator
}


SOURCES += main.cpp\
        MainWindow.cpp \
        xPLMessage.cpp \
        xPLNameValuePair.cpp \
        MessageListWidget.cpp \
        MessageWidget.cpp \
        utils.cpp \
        FilterDialog.cpp \
        MessageCreationDialog.cpp \
        xPL_NameValuePairForm.cpp \
        SendMessageDialog.cpp

HEADERS  += MainWindow.h \
        xPLMessage.h \
        xPLNameValuePair.h \
        MessageListWidget.h \
        MessageWidget.h \
        utils.h \
        FilterDialog.h \
        MessageCreationDialog.h \
        xPL_NameValuePairForm.h \
        SendMessageDialog.h

FORMS    += MainWindow.ui \
    MessageCreationDialog.ui \
    xPL_NameValuePairForm.ui \
    SendMessageDialog.ui
