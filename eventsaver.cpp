#include "eventsaver.h"

#include <iostream>

#include <QFile>
#include <QTextStream>

#include "data.h"
#include "cursor.h"


EventSaver::EventSaver()
{
    event_number_ = 0;
    default_file_directory_ = "/home/preston/Desktop/Science/Research/QtApplications/event_extractor/save/";
}

void EventSaver::set_data(Data* data)
{
    data_ = data;

    output_precision_ = QString::number(static_cast<int>(data->frequency())).length() + 10;

    return;
}

void EventSaver::set_cursors(Cursor* cursor1, Cursor* cursor2)
{
    cursor1_ = cursor1;
    cursor2_ = cursor2;
    return;
}

void EventSaver::Save_Event()
{
    int startindex = static_cast<int>(cursor1_->xpos()*data_->frequency());
    int endindex = static_cast<int>(cursor2_->xpos()*data_->frequency());

    QString index = QString::number(event_number_);

    int n = index.length();

    for(int i = 0; i < 4-n; i++)
    {
        index.insert(0, "0");
    }


    QString temp = "event_" + index + "\n\n\n";
    std::cerr << temp.toStdString();


    QFile output_file(default_file_directory_ + file_prefix_ + "_" + index);
    output_file.open(QIODevice::WriteOnly);

    QTextStream output_file_stream;


    std::cerr << output_precision_ << "\n\n\n";
    output_file_stream.setDevice(&output_file);
    output_file_stream.setRealNumberNotation(QTextStream::FixedNotation);
    output_file_stream.setRealNumberPrecision(output_precision_);

    for(int i = 0; i < endindex - startindex; i++)
    {
        output_file_stream << data_->datax()[startindex + i] << "\t" << data_->datay()[startindex + i] << "\n";
    }

    event_number_ = event_number_ + 1;


    return;
}

void EventSaver::set_file_prefix(QString file_prefix)
{
    file_prefix_ = file_prefix;
    return;
}
