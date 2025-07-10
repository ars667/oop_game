#pragma once
#include <ostream>
#include "message.h"
#include "button.h"

class ButtonCommandMessage : public Message
{
private:
    button command;
    char key;

public:
    ButtonCommandMessage(char key, button command);
    std::string commandToString(button command) const;
    std::string makeString() const;
};