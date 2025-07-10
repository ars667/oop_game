#include "badEvent.h"

BadEvent::BadEvent()
{
}

void BadEvent::change(PlayerMovement current_player)
{
    current_player.updatePlayerHealth(-100);
    current_player.updatePlayerScore(-10);
}