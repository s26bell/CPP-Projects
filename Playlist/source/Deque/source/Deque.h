/**
    ECE250
    Deque.h

    Author Simon Bell
    Version 1.0  - 01/31/2021
*/
#ifndef deque_hpp
#define deque_hpp
#include <iostream>
#include <string>
#include "URLNode.h"
using namespace std;



class Deque {

    // class variables
	private:
    URLNode* p_front;
    URLNode* p_back;
    std::size_t size;

    // class functions
    public:
    //Constructor and Destructor
    Deque();
    ~Deque();

    //Member Functions
    bool isEmpty() const;
    URLNode* getFront() const;
    URLNode* getBack() const;
    std::size_t getSize() const;
    void setFront(URLNode* const p_new_front);
    void setBack(URLNode* const p_new_back);
    URLNode* findURL(const string find_URL) const;
    void push_front(const string URL_add_name, const string URL_add);
    void push_back(const string URL_add_name, const string URL_add );
    bool pop_front();
    bool pop_back();
    void clear();
    void print() const;

};
#endif