#include <ostream>
#pragma once
#include "message.h"
#include "playerMovement.h"

class LooseMessage : public Message
{
private:
    int y;
    int x;

public:
    LooseMessage(PlayerMovement& playerMovement);
    std::string makeString() const;
};