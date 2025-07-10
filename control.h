#pragma once
//#include "direction.h"
#include "buttonMessage.h"
#include "buttonCommandMessage.h"
#include "looseMessage.h"
#include "winMessage.h"
#include "newGameMessage.h"
#include "output.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "reader.h"
#include "output.h"

class Control
{
private:
    char chars[7];
    int place;

protected:
    int changer(char ch);
    
public:
    Control();
    void changePlace(int place);
    button Read();
    button keyToButton(char ch);
};