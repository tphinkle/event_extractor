#include "objectbind.h"

#include <QMainWindow>
#include "mainwindow.h"
#include "/usr/src/QT/Extras/qcustomplot/qcustomplot.h"

#include "plot.h"
#include "eventsaver.h"

void Bind_MainWindow_Data_Plot_EventSaver(MainWindow& window, Data* data, Plot* plot, EventSaver* eventsaver)
{
    window.set_data(data);
    window.set_plot(plot);
    window.set_eventsaver(eventsaver);

    eventsaver->set_data(data);
    eventsaver->set_cursors(plot->cursor_1(), plot->cursor_2());

    return;
}
