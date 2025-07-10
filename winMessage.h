#include <ostream>
#pragma once
#include "message.h"
#include "player.h"

class WinMessage : public Message
{
private:
    int health;
    int score;

public:
    WinMessage(Player player);
    std::string makeString() const;
};