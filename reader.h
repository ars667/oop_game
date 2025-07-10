#pragma once
#include <string>
#include "fileReader.h"

class Reader{
    private:
        char chars[7];
        std::string filename;
    public:
        Reader(std::string filename);

        char *read();
};