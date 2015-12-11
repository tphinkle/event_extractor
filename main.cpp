#include "mainwindow.h"
#include <QApplication>

#include <data.h>
#include <plot.h>
#include <eventsaver.h>

#include "objectbind.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Data data;
    Plot plot;
    EventSaver eventsaver;


    Bind_MainWindow_Data_Plot_EventSaver(w, &data, &plot, &eventsaver);

    w.show();

    return a.exec();
}
