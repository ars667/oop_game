#pragma once
#include <ostream>
#include "message.h"
#include "button.h"

class ButtonMessage : public Message
{
private:
    char key;

public:
    ButtonMessage(char key);
    std::string makeString() const;
};