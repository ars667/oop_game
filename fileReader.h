#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileReader
{
public:
    explicit FileReader(const std::string &filename);

    ~FileReader();

    std::string readLine();

private:
    std::ifstream file;
};