#include "newGameMessage.h"

NewGameMessage::NewGameMessage(Field &field) : fieldX(field.get_width()),
 fieldY(field.get_height()), startX(field.get_start_width()), startY(field.get_start_height())
{
}

std::string NewGameMessage::makeString() const
{
    const std::string output = "Field width: " + std::to_string(this->fieldX) + " Field height: " +
    std::to_string(this->fieldY) + " Start X: " + std::to_string(this->startX) + " Start Y: " + std::to_string(this->startY);
    return output;
}