#pragma once
#include "message.h"

class Output
{
    private:
        int place;

    public:
        Output(int place = 0);
        void print(Message& message);
};