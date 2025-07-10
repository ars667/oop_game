#include "playerMovement.h"
#include <iostream>
#include "goodEvent.h"
#include "badEvent.h"
#include "teleportEvent.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

PlayerMovement::PlayerMovement(Player &player, Field &field, int x, int y)
    : player(player), field(field), x(x), y(y)
{
    this->field = field;
    this->player = player;
    this->x = x;
    this->y = y;
}

void PlayerMovement::doEvent()
{
    if (this->field.get_cell(this->y, this->x)->getIsEvent())
    {
        std::cout << "\nEVENT\n";
        this->field.get_cell(this->y, this->x)->getEvent()->change(*this);
    }
}

void PlayerMovement::move(int distance, direction Dir)
{
    switch (Dir)
    {
    case UP:
        if (y + distance < this->field.get_height() && y + distance >= 0 && this->field.get_cell(y + distance, x)->getPassability())
        {
            this->y += distance;
            doEvent();
        }

        break;
    case DOWN:
        if (y - distance < this->field.get_height() && y - distance >= 0 && this->field.get_cell(y - distance, x)->getPassability())
        {
            this->y -= distance;
            doEvent();
        }

        break;
    case RIGHT:
        if (x + distance < this->field.get_width() && x + distance >= 0 && this->field.get_cell(y, x + distance)->getPassability())
        {
            this->x += distance;
            doEvent();
        }

        break;
    case LEFT:
        if (x - distance < this->field.get_width() && x - distance >= 0 && this->field.get_cell(y, x - distance)->getPassability())
        {
            this->x -= distance;
            doEvent();
        }
        break;
    default:
        break;
    }
}

void PlayerMovement::updatePlayerHealth(int newHealth)
{
    player.setHealth(player.getHealth() + newHealth);
}

void PlayerMovement::updatePlayerScore(int newScore)
{
    player.setScore(player.getScore() + newScore);
}

int PlayerMovement::getX()
{
    return x;
}

int PlayerMovement::getY()
{
    return y;
}

void PlayerMovement::changeField(Field& field){
    this->field = field;
}

Field &PlayerMovement::getField()
{
    return this->field;
}

void PlayerMovement::printGame()
{
    for (int i = this->field.get_height() - 1; i >= 0; i--)
    {
        std::cout << '\n';
        for (int j = 0; j < this->field.get_width(); j++)
        {
            if (this->getX() == j && this->getY() == i)
            {
                std::cout << "@ ";
            }
            else if (this->field.get_cell(i, j)->getIsEvent())
            {
                std::cout << RED << "* " << RESET;
            }
            else if (this->field.get_cell(i, j)->getPassability())
            {
                std::cout << "_ ";
            }
            else
            {
                std::cout << "# ";
            }
        }
    }
    std::cout << '\n';
}

Player& PlayerMovement::getPlayer()
{
    return this->player;
}
