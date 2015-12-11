#include "fileloader.h"

#include <QString>

bool FileLoader::file_loaded_ = false;

int FileLoader::max_vector_elements_ = 2*60*60*20000;

QString FileLoader::loaded_file_name_ = "";
