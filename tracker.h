#pragma once
#include "game.h"
#include "draw.h"
#include "player.h"
#include "makeLevel.h"

class Tracker
{
    private:
        Game& game;
        Draw& drawer;
    public:
        Tracker(Game& game, Draw& drawer);
        void start();
        void draw(PlayerMovement& PlayerMovement);
};