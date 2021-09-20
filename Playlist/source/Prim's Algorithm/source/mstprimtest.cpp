/**
    ECE250
    mstprimtest.cpp
    Purpose: To read commands from the standard input and write the output to standard output. Responds to commands as described in project description 

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Graph.h"
#include "Vertex.h"
#include "illegal_exception.h"
#include "priorityQ.h"
#include "iomanip"

void invalidInput(std::size_t u, std::size_t v, std::size_t n, double w, bool checkAll);

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    std::string line = "";
    getline(std::cin, line);
    int pos = line.find(" ");
    std::string cmd = line.substr(0, pos);
    std::string input = line.substr(pos + 1);
    std::size_t graph_size{1};

    if (cmd == "n")
    {
        graph_size = stoi(input);
        std::cout << "success" << std::endl; // initialize graph_size to correct size and make graph object
    }

    Graph g(graph_size);

    while (true)
    {

        getline(std::cin, line);

        int pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string input = line.substr(pos + 1);

        if (std::cin.eof())
        {
            break;
        }

        if (line == "exit")
        {
            break;
        }

        if (cmd == "i")
        {
            try
            {
                int pos_1 = input.find_first_of(";");
                int pos_2 = input.find_last_of(";");
                std::size_t u = stoi(input.substr(0, pos_1));
                std::size_t v = stoi(input.substr(pos_1 + 1, pos_2));
                double w = std::stod(input.substr(pos_2 + 1));
                g.insertEdge(u, v, w);
                std::cout << "success" << std::endl;
            }
            catch (illegal_exception &e)
            {
                std::cout << e.getException() << std::endl;
            }
        }

        if (cmd == "e")
        {
            try
            {
                int pos_1 = input.find_first_of(";");
                std::size_t u = stoi(input.substr(0, pos_1));
                std::size_t v = stoi(input.substr(pos_1 + 1, 3));
                if (g.eraseEdge(u, v))
                {
                    std::cout << "success" << std::endl;
                }
                else
                {
                    std::cout << "failure" << std::endl;
                }
            }
            catch (illegal_exception &e)
            {
                std::cout << e.getException() << std::endl;
            }
        }

        if (cmd == "adjacent")
        {
            try
            {
                int pos_1 = input.find_first_of(";");
                int pos_2 = input.find_last_of(";");
                std::size_t u = stoi(input.substr(0, pos_1));
                std::size_t v = stoi(input.substr(pos_1 + 1, pos_2));
                double w = std::stod(input.substr(pos_2 + 1));

                if (g.adjacent(u, v, w))
                {
                    std::cout << "adjacent " << u << " " << v << " " << w << std::endl;
                }
                else
                {
                    std::cout << "not adjacent " << u << " " << v << " " << w << std::endl;
                }
            }
            catch (illegal_exception &e)
            {
                std::cout << e.getException() << std::endl;
            }
        }

        if (cmd == "degree")
        {
            try
            {
                std::size_t u = stoi(input.substr(0));
                std::size_t degree = g.degree(u);
                std::cout << "degree of " << input << " is " << degree << std::endl;
            }
            catch (illegal_exception &e)
            {
                std::cout << e.getException() << std::endl;
            }
        }

        if (cmd == "edge_count")
        {
            std::cout << "edge count is " << g.edgeCount() << std::endl;
        }

        if (cmd == "clear")
        {
            g.clear();
            std::cout << "success" << std::endl;
        }

        if (cmd == "mst")
        {
            try
            {
                std::size_t u = stoi(input.substr(0));
                double mstValue = g.mst(u);
                if (mstValue != INFINITY)
                {
                    std::cout << "mst " << mstValue << std::endl;
                }
                else
                {
                    std::cout << "not connected" << std::endl;
                }
            }
            catch (illegal_exception &e)
            {
                std::cout << e.getException() << std::endl;
            }
        }
    }
    return 0;
}

void invalidInput(std::size_t u, std::size_t v, std::size_t n, double w, bool checkAll)
{
    if (u >= n)
    {
        throw illegal_exception("illegal argument");
    }

    if (checkAll)
    {
        if (u == v || v >= n || w <= 0 || v < 0 || u < 0)
        {
            throw illegal_exception("illegal argument");
        }
    }
}
