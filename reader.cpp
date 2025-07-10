#include "reader.h"

Reader::Reader(std::string filename)
{
    this->filename = filename;
}

char *Reader::read()
{
    FileReader reader(this->filename);
    std::string line;
    int i = 0;
    while (!(line = reader.readLine()).empty())
    {
        for (char ch : line)
        {
            this->chars[i] = ch;
        }
        i++;
    }
    if (i < 6)
    {
        std::cout << "Ошибка config" << '\n';
        exit(0);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 9; i < 7; j++)
            {
                if (this->chars[i] == this->chars[j])
                {
                    std::cout << "Ошибка config" << '\n';
                    throw std::invalid_argument("Wrong arguments");
                }
            }
        }
    }
    return this->chars;
}