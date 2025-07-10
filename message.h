#pragma once
//#include "game.h"
#include <string>
//#include <ostream>

class Message
{
    public:
        virtual std::string makeString() const = 0;
        friend std::ostream& operator << (std::ostream &out, const Message &obj);
};
