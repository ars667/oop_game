#include "output.h"
#include <iostream>
#include <fstream>

Output::Output(int place)
{
    this->place = place;
}

void Output::print(Message& message)
{
    if (place == 0)
    {
        std::cout << message.makeString();
    }
    else if (place == 1)
    {
        std::ofstream outputFile("output.txt", std::ios::app);

        if (outputFile.is_open())
        {

            outputFile << message.makeString();
            outputFile.close();
        }
        else
        {
            std::cout << "Не удалось открыть файл." << std::endl;
        }
    }
else
{
    std::cout << message.makeString();
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open())
    {

        outputFile << message.makeString();
        outputFile.close();
    }
    else
    {
        std::cout << "Не удалось открыть файл." << std::endl;
    }
}
}