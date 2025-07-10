#include "tracker.h"

Tracker::Tracker(Game &game, Draw &drawer)
: game(game), drawer(drawer)
{
}

void Tracker::start()
{
    game.chooseLevel();
    game.newGame();
    
}
void Tracker::draw(PlayerMovement& PlayerMovement)
{
    drawer.drawField(PlayerMovement);
}
