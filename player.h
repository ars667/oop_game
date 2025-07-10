#pragma once

class Player
{
private:
    int health;
    int score;

public:
    Player(int initialHealth = 100, int initialScore = 0, int initialX = 0, int initialY = 0);

    void setHealth(int newHealth);

    void setScore(int newScore);

    int getHealth();

    int getScore();
};