#include "game.h"

// #include "direction.h"

void Game::setDrawCallback(DrawCallback callback)
{
        drawCallback = std::move(callback);
}

Game::Game(Player &player, MakeLevel &makeLevel)
    : player(player), makeLevel(makeLevel)
{
    this->place = 0;
    this->player = player;
    this->makeLevel = makeLevel;
    Control control;
    this->control = control;
};

void Game::chooseLevel()
{
    std::cout << "Choose place for log. 0 - stream, 1 - file, 2 - file and stream" << '\n';
    std::cin >> this->place;
    this->control.changePlace(this->place);
    std::cout << "Choose level l - change level, k - confirm level" << '\n';
    button keylevel = this->control.Read();
    while (keylevel != BCONF)
    {
        if (keylevel == BLEVEL)
        {
            this->level += 1;
            this->level = this->level % 2;
            std::cout << "level" << level << '\n';
        }
        keylevel = this->control.Read();
    }
}
void Game::newGame()
{
    this->chooseLevel();
    Output output(this->place);
    int size = 10;
    if (this->level == 1)
    {
        size = 15;
    }
    Field field = this->makeLevel.MakeNewLevel(size, size);
    PlayerMovement playerMovement(this->player, field);

    NewGameMessage newGameMessage(field);
    output.print(newGameMessage);

    int is_game = 1;
    while (is_game)
    {

        if (this->player.getHealth() == 0)
        {
            LooseMessage looseMessage(playerMovement);
            output.print(looseMessage);
            is_game = 0;
        }

        drawCallback(playerMovement);
        if (playerMovement.getX() == field.get_end_width() && playerMovement.getY() == field.get_end_height())
        {
            WinMessage winMessage(this->player);
            output.print(winMessage);
            is_game = 0;
        }
        button key = this->control.Read();
        switch (key)
        {
        case BUP:
            playerMovement.move(1, UP);
            break;

        case BRIGHT:
            playerMovement.move(1, RIGHT);
            break;

        case BDOWN:
            playerMovement.move(1, DOWN);
            break;

        case BLEFT:
            playerMovement.move(1, LEFT);
            break;

        case BQUIT:
            is_game = 0;
            break;

        default:
            break;
        }
        // playerMovement.printGame();
        // std::cout << "X: " << playerMovement.getX() << " Y: " << playerMovement.getY() << " H: " << player.getHealth() << " S: " << player.getScore() << '\n';
    }
};