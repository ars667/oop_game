#include "printWinMessage.h"
#include <iostream>

PrintMessage::PrintMessage()
{
}

void PrintMessage::print(WinMessage &winMessage)
{
    std::cout << "health:" << winMessage->getHealth << " score: " << winMessage->getScore;
}