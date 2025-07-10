#include "player.h"

Player::Player(int initialHealth, int initialScore, int initialX, int initialY)
{
    health = initialHealth;
    score = initialScore;
}

void Player::setHealth(int newHealth)
{
    if (newHealth < 0)
    {
        health = 0;
    }
    else
    {
        health = newHealth;
    }
}

void Player::setScore(int newScore)
{
    if (newScore < 0)
    {
        score = 0;
    }
    else
    {
        score = newScore;
    }
}

int Player::getHealth()
{
    return health;
}

int Player::getScore()
{
    return score;
}