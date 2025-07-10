#pragma once
#include "cell.h"
#include <algorithm>

class Field
{
private:
    int height;
    int width;
    int start_height;
    int start_width;
    int end_height;
    int end_width;
    Cell **array;

public:
    Field(int height = 10, int width = 10, int start_height = 0, int start_width = 0, int end_height = 9, int end_width = 9);
    Field(const Field &other);
    Field(Field &&other) noexcept;
    Field &operator=(const Field &other);
    Field &operator=(Field &&other) noexcept;
    ~Field();
    int get_height();
    int get_width();
    int get_start_height();
    int get_start_width();
    int get_end_height();
    int get_end_width();
    Cell *get_cell(int y, int x);
};