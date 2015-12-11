#ifndef EVENTSAVER_H
#define EVENTSAVER_H

class Data;
class Cursor;

#include <QString>

class EventSaver
{
public:
    EventSaver();
    void set_data(Data* data);
    void set_cursors(Cursor* cursor1, Cursor* cursor2);

    void Save_Event();

    void set_file_prefix(QString fileprefix);

private:
    Data* data_;
    Cursor* cursor1_;
    Cursor* cursor2_;

    int output_precision_;

    QString default_file_directory_;
    QString file_prefix_;
    int event_number_;

};

#endif // EVENTSAVER_H
