#pragma once
#include "playerMovement.h"
#include "event.h"

class BadEvent : public Event
{
public:
    BadEvent();
    void change(PlayerMovement current_player);
};
