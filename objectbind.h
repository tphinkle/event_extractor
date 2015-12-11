#ifndef OBJECTBIND_H
#define OBJECTBIND_H

class MainWindow;
class QCustomPlot;
class Plot;
class Data;
class EventSaver;


void Bind_MainWindow_Data_Plot_EventSaver(MainWindow& window, Data* data, Plot* plot, EventSaver* eventsaver);

#endif // OBJECTBIND_H

