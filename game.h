#pragma once
#include "playerMovement.h"
#include "makeLevel.h"
#include "player.h"
#include "control.h"
#include <functional>
#include "reader.h"
#include <iostream>

class Game
{
public:
    using DrawCallback = std::function<void(PlayerMovement &)>;
    void setDrawCallback(DrawCallback callback);

private:
int place;
    Player &player;
    MakeLevel &makeLevel;
    int level;
    Control control;
    DrawCallback drawCallback;

public:
    Game(Player &player, MakeLevel &makeLevel);
    void chooseLevel();
    void newGame();
};