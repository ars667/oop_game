#include "buttonCommandMessage.h"

ButtonCommandMessage::ButtonCommandMessage(char key, button command)
{
    this->key = key;
    this->command = command;
}

std::string ButtonCommandMessage::commandToString(button command) const
{
    switch (command)
    {
    case BUP:
        return std::string("BUP");
        break;

    case BRIGHT:
        return std::string("BRIGHT");
        break;

    case BDOWN:
        return std::string("BDOWN");
        break;

    case BLEFT:
        return std::string("BLEFT");
        break;

    case BQUIT:
        return std::string("BQUIT");
        break;

    case BLEVEL:
        return std::string("BLEVEL");
        break;

    case BCONF:
        return std::string("BCONF");
        break;
    default:
        break;
    }
}

std::string ButtonCommandMessage::makeString() const
{
    const std::string output = std::string(1, '\n') + " Button: " + std::string(1, this->key) + " Command: " + this->commandToString(this->command) + std::string(1, '\n');
    return output;
}