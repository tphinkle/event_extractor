#ifndef LOAD_FILE_H
#define LOAD_FILE_H

class QString;
class QStringList;
class QFile;
class QTextStream;

class Data;
class QString;

#include <vector>

class FileLoader
{

public:
    static void Load_File(Data* data);

    static QString loaded_file_name();

    static void set_loaded_file_name(QString loaded_file_name);

private:


    static void Load_File_atf(QTextStream& filestream, Data* data);

    static QString Get_File_Type(QString filename);

    static QStringList Get_Column_Labels_atf(QTextStream& stream);

    static int Get_Selected_Column_atf(QStringList column_labels);

    static void Move_Data_From_Stream_To_Data_ATF(QTextStream& stream, Data* data, int columncount, int selectedcolumn);

    static void Get_Period_ATF(QTextStream& stream, Data* data, int columncount);

    static void Skip_Lines(QTextStream& stream, int lines);

    static bool file_loaded_;

    static QString loaded_file_name_;

    static int max_vector_elements_;

};


#endif // LOAD_FILE_H
