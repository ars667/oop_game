#include "buttonMessage.h"

ButtonMessage::ButtonMessage(char key)
{
    this->key = key;
}

std::string ButtonMessage::makeString() const
{
    const std::string output = std::string(1, '\n') + " Button: " + std::string(1, this->key) + std::string(1, '\n');
    return output;
}