#include <iostream>
#include "player.h"
#include "playerMovement.h"
#include "field.h"
#include "makeLevel.h"
#include "event.h"
#include "game.h"
#include "tracker.h"
#include "draw.h"

int main()
{
    Player player;
    MakeLevel makeLevel;
    Game game(player, makeLevel);
    Draw drawer;
    Tracker tracker(game, drawer);
    game.setDrawCallback([&tracker](PlayerMovement& playerMovement) {
        tracker.draw(playerMovement);
    });
    tracker.start();
    return 0;
}