#pragma once
#include "playerMovement.h"
#include "event.h"

class TeleportEvent : public Event
{
private:
    int distance;
    direction dir;

public:
    TeleportEvent(int distance = 0, direction dir = UP);
    void change(PlayerMovement current_player);
};