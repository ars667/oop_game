#pragma once

class Event; // forward declaration
class Cell
{
private:
    bool passability;
    Event *event;
    bool is_event;

public:
    Cell(bool pass = false);
    void setEvent(Event *event);
    void changePassability(bool pass);
    bool getPassability();
    bool getIsEvent();
    Event *getEvent();
};