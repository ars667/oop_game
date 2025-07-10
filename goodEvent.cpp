#include "goodEvent.h"

GoodEvent::GoodEvent()
{
}

void GoodEvent::change(PlayerMovement current_player)
{
    current_player.updatePlayerHealth(10);
    current_player.updatePlayerScore(10);
}
