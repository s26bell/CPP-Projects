/**
    ECE250
    illegal_exception.cpp

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#ifndef illegal_exception_hpp
#define illegal_exception_hpp
#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;


class illegal_exception {
    // class variables
	private:
    string exception;
    public:
    //Constructor and Destructor
    illegal_exception(const string& e) : exception(e) {}
    const string getException(){return exception;};
};
#endif


