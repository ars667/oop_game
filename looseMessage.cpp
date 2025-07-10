#include "looseMessage.h"

LooseMessage::LooseMessage(PlayerMovement& playerMovement): x(playerMovement.getX()), y(playerMovement.getY())
{
}

std::string LooseMessage::makeString() const
{
    const std::string output = "Loose! X: " + std::to_string(this->x) + " Y: " + std::to_string(this->y);
    return output;
}