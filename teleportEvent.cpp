#include "teleportEvent.h"

TeleportEvent::TeleportEvent(int distance, direction dir)
{
    this->distance = distance;
    this->dir = dir;
}

void TeleportEvent::change(PlayerMovement current_player)
{
    current_player.move(this->distance, this->dir);
}