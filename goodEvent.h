#pragma once
#include "playerMovement.h"
#include "event.h"

class GoodEvent : public Event
{
public:
    GoodEvent();
    void change(PlayerMovement current_player);
};