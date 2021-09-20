/**
    ECE250
    Graph.h

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#ifndef graph_hpp
#define graph_hpp
#include <iostream>
#include <vector>
#include <cmath>
#include "Vertex.h"
#include "priorityQ.h"

class Graph
{

    // class variables
private:
    std::size_t edge_count;
    std::size_t vertex_num;
    double *p_mem;
    double **p_matrix;
    Vertex *p_vertex;

    // class functions
public:
    //Constructor and Destructor
    Graph(std::size_t size);
    ~Graph();

    //Member Functions
    void insertEdge(const std::size_t u, const std::size_t v, const double w);
    bool eraseEdge(const std::size_t u, const std::size_t v);
    bool adjacent(const std::size_t u, const std::size_t v, const double w) const;
    std::size_t degree(std::size_t u) const;
    std::size_t edgeCount() const;
    void clear();
    double mst(const std::size_t u) const;
};
#endif