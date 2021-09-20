/**
    ECE250
    illegal_exception.h

    Author Simon Bell
    Version 1.0  - 03/28/2021
*/
#ifndef illegal_exception_hpp
#define illegal_exception_hpp
#include <iostream>
#include <string>

class illegal_exception
{

    // class variables
private:
    std::string exception;

public:
    //Constructor and Destructor
    illegal_exception(const std::string &e) : exception(e) {}
    const std::string getException() { return exception; };
};
#endif
