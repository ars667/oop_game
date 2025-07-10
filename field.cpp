#include "field.h"
#include <stdexcept>
#include <iostream>

Field::Field(int height, int width, int start_height, int start_width, int end_height, int end_width)
{
    if (height < 2 || width < 2 || start_height < 0 || start_height > height - 1 ||
        start_width < 0 || start_width > width - 1 || end_height < 0 || end_height > height - 1 || end_width < 0 || end_width > width - 1)
    {
        throw std::invalid_argument("Wrong values");
    }
    Cell **array = new Cell *[height];
    for (int i = 0; i < height; i++)
    {
        array[i] = new Cell[width];
    }
    this->height = height;
    this->width = width;
    this->start_height = start_height;
    this->start_width = start_width;
    this->end_height = end_height;
    this->end_width = end_width;
    this->array = array;
}

Field::Field(const Field &other)
    : height(other.height),
      width(other.width),
      start_height(other.start_height),
      start_width(other.start_width),
      end_height(other.end_height),
      end_width(other.end_width),
      array(new Cell *[other.height])
{
    for (int i = 0; i < other.height; ++i)
    {
        array[i] = new Cell[other.width];
        for (int j = 0; j < other.width; ++j)
        {
            array[i][j] = other.array[i][j];
        }
    }
}

Field::Field(Field &&other) noexcept
    : height(other.height),
      width(other.width),
      start_height(other.start_height),
      start_width(other.start_width),
      end_height(other.end_height),
      end_width(other.end_width),
      array(std::move(other.array))
{
    other.height = 0;
    other.width = 0;
    other.start_height = 0;
    other.start_width = 0;
    other.end_height = 0;
    other.end_width = 0;
}

Field &Field::operator=(const Field &other)
{
    if (this != &other)
    {
        Field temp(other);
        std::swap(*this, temp);
    }
    return *this;
}

Field &Field::operator=(Field &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < height; ++i)
        {
            delete[] array[i];
        }
        delete[] array;

        height = other.height;
        width = other.width;
        start_height = other.start_height;
        start_width = other.start_width;
        end_height = other.end_height;
        end_width = other.end_width;
        array = other.array;

        other.height = 0;
        other.width = 0;
        other.start_height = 0;
        other.start_width = 0;
        other.end_height = 0;
        other.end_width = 0;
        other.array = nullptr;
    }
    return *this;
}

Field::~Field()
{
    for (int i = 0; i < height; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

int Field::get_height()
{
    return this->height;
}
int Field::get_width()
{
    return this->width;
}
int Field::get_start_height()
{
    return this->start_height;
}
int Field::get_start_width()
{
    return this->start_width;
}
int Field::get_end_height()
{
    return this->end_height;
}
int Field::get_end_width()
{
    return this->end_width;
}
Cell *Field::get_cell(int y, int x)
{
    return &(this->array[y][x]);
}