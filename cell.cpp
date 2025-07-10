#include "cell.h"

Cell::Cell(bool pass)
{
    passability = pass;
    is_event = false;
}

void Cell::changePassability(bool pass)
{
    this->passability = pass;
}

bool Cell::getPassability()
{
    return this->passability;
}

void Cell::setEvent(Event *event)
{
    this->event = event;
    this->is_event = true;
};

bool Cell::getIsEvent()
{
    return is_event;
}

Event *Cell::getEvent()
{
    return event;
};