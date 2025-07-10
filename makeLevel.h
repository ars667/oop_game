#pragma once
#include "field.h"
#include "goodEvent.h"
#include "badEvent.h"
#include "teleportEvent.h"

class MakeLevel
{
public:
    MakeLevel();
    Field MakeNewLevel(int x, int y);
    Field MakeNewLevel2(int x, int y);
};