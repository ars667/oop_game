#pragma once
#include "playerMovement.h"

class Event
{
public:
    virtual void change(PlayerMovement current_player) = 0;
};