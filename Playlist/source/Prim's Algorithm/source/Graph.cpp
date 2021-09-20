/**
    ECE250
    Graph.cpp

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Graph.h"
#include "Vertex.h"
#include "illegal_exception.h"
#include "priorityQ.h"

void invalidInput(std::size_t, std::size_t v, std::size_t n, double w, bool checkAll);

//Constructor
Graph::Graph(std::size_t size)
{
    edge_count = 0;
    vertex_num = size;
    p_mem = new double[size * size];
    p_matrix = new double *[size];
    p_vertex = new Vertex[size];

    for (std::size_t i{0}; i < size; ++i)
    {
        p_matrix[i] = &p_mem[i * size];
        p_vertex[i].setIndex(i);
        for (std::size_t j{0}; j < size; ++j)
        {
            p_matrix[i][j] = 0;
        }
    }
}

//Destructor
Graph::~Graph()
{ //Deallocate whatever was allocated in the push front/back
    delete[] p_matrix;
    delete[] p_vertex;
    delete[] p_mem;
    p_matrix = nullptr;
    p_vertex = nullptr;
    p_mem = nullptr;
}

void Graph::insertEdge(const std::size_t u, const std::size_t v, double w)
{
    invalidInput(u, v, vertex_num, w, true);

    if (!p_matrix[u][v])
    {
        p_vertex[u].changeDegree(true);
        p_vertex[v].changeDegree(true);
        p_vertex[u].addAdjacent(v);
        p_vertex[v].addAdjacent(u);
        edge_count += 2;
    }

    p_matrix[u][v] = w;
    p_matrix[v][u] = w;
}

bool Graph::eraseEdge(const std::size_t u, const std::size_t v)
{
    invalidInput(u, v, vertex_num, 1, true);

    if (p_matrix[u][v])
    {
        p_matrix[u][v] = 0;
        p_matrix[v][u] = 0;
        p_vertex[u].changeDegree(false);
        p_vertex[v].changeDegree(false);
        p_vertex[u].removeAdjacent(v);
        p_vertex[v].removeAdjacent(u);
        edge_count -= 2;
        return true;
    }
    else
    {
        return false;
    }
}

bool Graph::adjacent(const std::size_t u, const std::size_t v, double w) const
{
    invalidInput(u, v, vertex_num, w, true);

    if (p_matrix[u][v] == w)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::size_t Graph::degree(const std::size_t u) const
{
    invalidInput(u, 0, vertex_num, 0, false);

    return p_vertex[u].getDegree();
}

std::size_t Graph::edgeCount() const
{
    return edge_count;
}

double Graph::mst(std::size_t u) const
{
    invalidInput(u, 0, vertex_num, 0, false);
    priorityQ pQ(vertex_num, p_vertex, u);
    std::size_t row{0};
    bool *pQremoved = new bool[vertex_num];
    double mstValue = 0;

    for (std::size_t i{0}; i < vertex_num; ++i)
    {
        pQremoved[i] = false;
    }

    while (pQ.get_size() != 0)
    {
        Vertex currentV = pQ.popMin();
        row = currentV.getIndex();
        double key = currentV.getKey();
        mstValue += key;

        pQremoved[row] = true;
        std::vector<std::size_t> adjacentList = currentV.getAdjacent();

        for (std::size_t i{0}; i < adjacentList.size(); ++i)
        {
            if (!pQremoved[adjacentList[i]] && p_matrix[row][adjacentList[i]] < pQ.findVertexKey(adjacentList[i]))
            {
                pQ.setVertexKey(adjacentList[i], p_matrix[row][adjacentList[i]]);
                pQ.heapUp(pQ.findVertexIndex(adjacentList[i]));
            }
        }
    }

    delete[] pQremoved;
    pQremoved = nullptr;

    return mstValue;
}

void Graph::clear()
{
    for (std::size_t i{0}; i < vertex_num; ++i)
    {
        p_vertex[i].setDegree(0);
        p_vertex[i].clearAdjacent();
        for (std::size_t j{0}; j < vertex_num; ++j)
        {
            p_matrix[i][j] = 0;
        }
    }
    edge_count = 0;
}
