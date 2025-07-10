#pragma once
#include "player.h"
#include "field.h"
#include "direction.h"

class PlayerMovement
{
private:
    Player &player;
    Field &field;

    int x;
    int y;

protected:
    void doEvent();

public:
    PlayerMovement(Player &playerPtr, Field &field, int x = 0, int y = 0);

    void move(int distance, direction Dir);

    int getX();

    int getY();

    void updatePlayerHealth(int newHealth);

    void updatePlayerScore(int newScore);

    void changeField(Field &field);

    Field& getField();

    void printGame();

    Player& getPlayer();
};