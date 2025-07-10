#include "control.h"

Control::Control()
{
    this->place = 0;
    Reader reader("config.txt");
    char *chars = reader.read();
    for (int i = 0; i < 7; i++)
    {
        this->chars[i] = chars[i];
    }
}
void Control::changePlace(int place)
{
    this->place = place;
};

int Control::changer(char ch)
{
    for (int i = 0; i < 7; i++)
    {
        if (ch == this->chars[i])
        {
            return i;
        }
    }
    return 100;
}

button Control::keyToButton(char ch)
{
    switch (this->changer(ch))
    {
    case 0:
        return BUP;
        break;

    case 1:
        return BRIGHT;
        break;

    case 2:
        return BDOWN;
        break;

    case 3:
        return BLEFT;
        break;

    case 4:
        return BQUIT;
        break;

    case 5:
        return BLEVEL;
        break;

    case 6:
        return BCONF;
        break;

    default:
        ButtonMessage buttonMessage(ch);
        Output output(this->place);
        output.print(buttonMessage);
        break;
    }
    return BCONF;
}

button Control::Read()
{
    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (changer(key) != 100)
            {
            ButtonCommandMessage buttonCommandMessage(key, keyToButton(key));
            Output output(this->place);
            output.print(buttonCommandMessage);
            }
            return keyToButton(key);
        }
    }
};