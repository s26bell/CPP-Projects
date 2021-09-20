/**
    ECE250
    priorityQ.cpp

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/
#include <iostream>
#include "priorityQ.h"
#include "Vertex.h"

std::size_t get_parent(std::size_t index);
std::size_t get_left(std::size_t index);
std::size_t get_right(std::size_t index);

//Constructor
priorityQ::priorityQ(std::size_t size_q, Vertex *vertex, std::size_t u)
{
    p_queue = new Vertex[size_q];
    p_vertex = new std::size_t[size_q];
    q_size = size_q;

    for (std::size_t i{0}; i < size_q; ++i)
    {
        p_queue[i] = vertex[i];
        p_vertex[i] = i;
        if (i == u)
        {
            p_queue[i].setKey(0);
        }
    }

    buildHeap();
}

//Destructor
priorityQ::~priorityQ()
{
    delete[] p_queue;
    delete[] p_vertex;
    p_queue = nullptr;
    p_vertex = nullptr;
}

//Member Functions
std::size_t priorityQ::get_size() const
{
    return q_size;
}

void priorityQ::swap(const std::size_t parent, const std::size_t child)
{
    Vertex tempV = p_queue[parent];
    p_vertex[p_queue[parent].getIndex()] = child;
    p_vertex[p_queue[child].getIndex()] = parent;
    p_queue[parent] = p_queue[child];
    p_queue[child] = tempV;
}

Vertex priorityQ::popMin()
{
    Vertex min = p_queue[0];
    swap(0, q_size - 1);
    --q_size;
    heapify(0);
    return min;
}

void priorityQ::heapify(const std::size_t index)
{
    std::size_t left = get_left(index);
    std::size_t right = get_right(index);
    std::size_t smallest = index;

    if (left < q_size && p_queue[left].getKey() < p_queue[smallest].getKey())
    {
        smallest = left;
    }

    if (right < q_size && p_queue[right].getKey() < p_queue[smallest].getKey())
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(index, smallest);
        heapify(smallest);
    }
}

void priorityQ::heapUp(const std::size_t i)
{
    if (i > 0)
    {
        heapify(get_parent(i));
        heapUp(get_parent(i));
    }
}

double priorityQ::findVertexKey(const std::size_t index) const
{
    return p_queue[p_vertex[index]].getKey();
}

std::size_t priorityQ::findVertexIndex(const std::size_t index) const
{
    return p_vertex[index];
}

void priorityQ::setVertexKey(const std::size_t index, const double key)
{
    p_queue[p_vertex[index]].setKey(key);
}

void priorityQ::buildHeap()
{
    for (int i{(int)get_parent(q_size - 1)}; i >= 0; --i)
    {
        heapify(i);
    }
}

//Non member functions
std::size_t get_parent(std::size_t index)
{
    return (index - 1) / 2;
}

std::size_t get_left(std::size_t index)
{
    return 2 * index + 1;
}

std::size_t get_right(std::size_t index)
{
    return 2 * (index + 1);
}
