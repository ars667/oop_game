#include "fileReader.h"

FileReader::FileReader(const std::string &filename) : file(filename)
{
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }
}

FileReader::~FileReader()
{
    if (file.is_open())
    {
        file.close();
    }
}

std::string FileReader::readLine()
{
    std::string line;
    std::getline(file, line);
    return line;
}
