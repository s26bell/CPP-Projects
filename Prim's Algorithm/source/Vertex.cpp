/**
    ECE250
    Vertex.cpp

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Vertex.h"

//Constructor
Vertex::Vertex()
{
    key = INFINITY;
    degree = 0;
}

//Destructor
Vertex::~Vertex()
{
    adjacent.clear();
}

//Member Functions
std::size_t Vertex::getDegree() const
{
    return degree;
}

double Vertex::getKey() const
{
    return key;
}

std::size_t Vertex::getIndex() const
{
    return index;
}

std::vector<std::size_t> Vertex::getAdjacent() const
{
    return adjacent;
}

void Vertex::setDegree(const std::size_t new_degree)
{
    degree = new_degree;
}

void Vertex::setKey(const double new_key)
{
    key = new_key;
}

void Vertex::setIndex(const std::size_t i)
{
    index = i;
}

void Vertex::changeDegree(const bool increment)
{
    increment ? ++degree : --degree;
}

void Vertex::addAdjacent(const std::size_t index)
{
    adjacent.push_back(index);
}

void Vertex::removeAdjacent(const std::size_t index)
{
    int location = -1;

    for (int i{0}; i < adjacent.size(); ++i)
    {
        if (adjacent[i] == index)
        {
            location = i;
        }
    }
    if (location >= 0)
    {
        adjacent.erase(adjacent.begin() + location);
    }
}

void Vertex::clearAdjacent()
{
    adjacent.clear();
}
