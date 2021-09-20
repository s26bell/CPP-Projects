/**
    ECE250
    priorityQ.h

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/
#ifndef priorityQ_hpp
#define priorityQ_hpp
#include <iostream>
#include "Vertex.h"

class priorityQ
{

    // class variables
private:
    Vertex *p_queue;
    std::size_t *p_vertex;
    std::size_t q_size;

    // class functions
public:
    //Constructor and Destructor
    priorityQ(std::size_t size_q, Vertex *vertex, std::size_t u);
    ~priorityQ();

    //Member Functions
    std::size_t get_size() const;
    void swap(const std::size_t parent, const std::size_t child);
    Vertex popMin();
    void heapify(const std::size_t index);
    void heapUp(const std::size_t i);
    void buildHeap();
    double findVertexKey(const std::size_t index) const;
    std::size_t findVertexIndex(const std::size_t index) const;
    void setVertexKey(const std::size_t index, const double key);
};
#endif