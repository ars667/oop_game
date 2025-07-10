#include "draw.h"
#include <iostream>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

Draw::Draw()
{

};

void Draw::drawField(PlayerMovement& playerMovement)
{
    for (int i = playerMovement.getField().get_height() - 1; i >= 0; i--)
    {
        std::cout << '\n';
        for (int j = 0; j < playerMovement.getField().get_width(); j++)
        {
            if (playerMovement.getX() == j && playerMovement.getY() == i)
            {
                std::cout << "@ ";
            }
            else if (playerMovement.getField().get_cell(i, j)->getIsEvent())
            {
                std::cout << RED << "* " << RESET;
            }
            else if (playerMovement.getField().get_cell(i, j)->getPassability())
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