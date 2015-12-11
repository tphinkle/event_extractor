#include "fileloader.h"

#include <iostream>

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include "atf_file.h"
#include "data.h"

void FileLoader::Load_File(Data* data)
{
    QString filename = QFileDialog::getOpenFileName(0, "Open file", "", "");
    QString filetype = Get_File_Type(filename);
    set_loaded_file_name(filename);

    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream filestream(&file);

    if(filetype == "atf")
    {
        Load_File_atf(filestream, data);
    }

    file_loaded_ = true;

    return;
}

QString FileLoader::Get_File_Type(QString filename)
{
    QStringList file_name_parts = filename.split(".");

    QString fileextension = file_name_parts[file_name_parts.size() - 1];

    return fileextension;
}



void FileLoader::Skip_Lines(QTextStream& stream, int lines)
{

    for(int i = 0; i < lines; i++)
    {
        stream.readLine();
    }

    return;
}

void FileLoader::set_loaded_file_name(QString filename)
{
    loaded_file_name_ = filename;
    return;
}

QString FileLoader::loaded_file_name()
{
    return loaded_file_name_;
}
