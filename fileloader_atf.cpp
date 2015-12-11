#include "fileloader.h"

#include <iostream>

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDialog>

#include "atf_file.h"
#include "data.h"
#include "optionselectdialog.h"


void FileLoader::Load_File_atf(QTextStream& filestream, Data* data)
{


    QStringList column_labels = Get_Column_Labels_atf(filestream);

    int selected_column = Get_Selected_Column_atf(column_labels);

    int total_columns = column_labels.size();

    Get_Period_ATF(filestream, data, total_columns);

    Move_Data_From_Stream_To_Data_ATF(filestream, data, total_columns, selected_column);

    data->set_length();

    data->set_duration();

    data->set_datax();



    return;
}

QStringList FileLoader::Get_Column_Labels_atf(QTextStream& stream)
{

    Skip_Lines(stream, ATF_File::column_label_line_);
    QString column_labels = stream.readLine();
    QStringList column_labels_list = column_labels.split("\"");
    QStringList column_labels_list_cut;

    for(int i = 0; i < column_labels_list.size(); i++)
    {
        if(i%2 == 1) //i is odd only
        {
            column_labels_list_cut << column_labels_list[i];
        }
    }

    return column_labels_list_cut;
}

int FileLoader::Get_Selected_Column_atf(QStringList column_labels)
{
    OptionSelectDialog columnselectdialog(0, column_labels);
    int selectedcolumn;
    columnselectdialog.setModal(true);
    columnselectdialog.exec();
    selectedcolumn = columnselectdialog.selectedoptionint();


    return selectedcolumn;
}

void FileLoader::Move_Data_From_Stream_To_Data_ATF(QTextStream& stream, Data* data, int columncount, int selectedcolumn)
{
    double junk;

    stream.seek(0);
    Skip_Lines(stream, ATF_File::data_start_line_);

    int j = 0;


    std::cerr << "start\n";

    while(stream.atEnd() == false)
    {
        for(int i = 0; i < columncount; i++)
        {
            stream >> junk;
            if(i == selectedcolumn)
            {
                data->Add_Datay_Element(junk);
            }

        }
    }
    std::cerr << "end\n";
    return;
}

void FileLoader::Get_Period_ATF(QTextStream& stream, Data* data, int columncount)
{
    double junk, junk1, junk2;

    stream.seek(0);

    Skip_Lines(stream, ATF_File::data_start_line_);

    stream >> junk1;

    for(int i = 0; i < columncount - 1; i++)
    {
        stream >> junk;
    }

    stream >> junk2;

    data->set_period(junk2-junk1);
    
    return;

}
