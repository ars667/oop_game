#include "makeLevel.h"
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

void makePath(Field *field)
{
    int y = field->get_height();
    int x = field->get_width();
    int currentX = 0;
    int currentY = 0;
    int finalX = x - 1;
    int FinalY = y - 1;
    field->get_cell(currentY, currentX)->changePassability(true);
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::srand(std::time(0));
    while (!(currentX == finalX && currentY == FinalY))
    {
        int randomNum = std::rand() % 2;
        int randomIsEvent = std::rand() % 10;
        int randomEvent = std::rand() % 2;
        if (randomIsEvent == 0)
        {
            switch (randomEvent)
            {
            case 0:
                field->get_cell(currentY, currentX)->setEvent(new GoodEvent);
                break;

            case 1:
                field->get_cell(currentY, currentX)->setEvent(new BadEvent);
                break;
            default:
                break;
            }
        }
        switch (randomNum)
        {
        case 0: // UP
            if (currentY + 1 > y - 1)
            {
                continue;
            }
            field->get_cell(currentY + 1, currentX)->changePassability(true);
            currentY++;
            break;
        case 1: // RIGHT
            if (currentX + 1 > x - 1)
            {
                continue;
            }
            field->get_cell(currentY, currentX + 1)->changePassability(true);
            currentX++;
            break;
        default:
            break;
        }
    }
}
MakeLevel::MakeLevel()
{
}
Field MakeLevel::MakeNewLevel(int x, int y)
{
    Field field = Field(y, x, 0, 0, y - 1, x - 1);
    makePath(&field);
    makePath(&field);
    makePath(&field);
    makePath(&field);
    return field;
}