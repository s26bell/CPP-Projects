/**
    ECE250
    Vertex.h

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/
#ifndef vertex_hpp
#define vertex_hpp
#include <iostream>
#include <cmath>
#include <vector>

class Vertex
{

    // class variables
private:
    std::size_t degree;
    double key;
    std::size_t index;
    std::vector<std::size_t> adjacent;

    // class functions
public:
    //Constructor and Destructor
    Vertex();
    ~Vertex();

    //Member Functions
    std::size_t getDegree() const;
    double getKey() const;
    std::size_t getIndex() const;
    std::vector<std::size_t> getAdjacent() const;
    void setDegree(const std::size_t new_degree);
    void setKey(const double new_key);
    void setIndex(const std::size_t i);
    void changeDegree(const bool increment);
    void addAdjacent(const std::size_t index);
    void removeAdjacent(const std::size_t index);
    void clearAdjacent();
};
#endif