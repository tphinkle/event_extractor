#-------------------------------------------------
#
# Project created by QtCreator 2015-10-06T18:07:00
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = event_extractor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow_setup.cpp \
    atf_file.cpp \
    fileloader.cpp \
    fileloader_atf.cpp \
    optionselectdialog.cpp \
    data.cpp \
    plot.cpp \
    ../../../../../../../usr/src/QT/Extras/qcustomplot/qcustomplot.cpp \
    fileloader_static.cpp \
    objectbind.cpp \
    plot_ui.cpp \
    cursor.cpp \
    eventsaver.cpp

HEADERS  += mainwindow.h \
    atf_file.h \
    fileloader.h \
    optionselectdialog.h \
    data.h \
    plot.h \
    ../../../../../../../usr/src/QT/Extras/qcustomplot/qcustomplot.h \
    objectbind.h \
    cursor.h \
    eventsaver.h

FORMS    += mainwindow.ui \
    optionselectdialog.ui
