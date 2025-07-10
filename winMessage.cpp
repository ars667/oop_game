#include "winMessage.h"

WinMessage::WinMessage(Player player)
{
    this->health = player.getHealth();
    this->score = player.getScore();
}

std::string WinMessage::makeString() const
{
    const std::string output = "Win! Health: " + std::to_string(this->health) + " Score: " + std::to_string(this->score);
    return output;
}