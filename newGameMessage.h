#include <ostream>
#pragma once
#include "message.h"
#include "Field.h"

class NewGameMessage : public Message
{
private:
    int fieldX;
    int fieldY;
    int startX;
    int startY;

public:
    NewGameMessage(Field& field);
    std::string makeString() const;
};