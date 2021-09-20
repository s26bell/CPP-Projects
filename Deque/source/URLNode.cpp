/**
    ECE250
    URLNode.cpp

    Author Simon Bell
    Version 1.0  - 1/31/2020
*/
#include <iostream>
#include <string>
#include "URLNode.h"
using namespace std;



//Constructor
URLNode::URLNode(){
    URL = "";
    URL_name = "";
    p_next_node = nullptr;
    p_previous_node = nullptr;
}

//Destructor
URLNode::~URLNode() {

 }

    string URLNode::getURL_name() const {
        return URL_name;
    }

    string URLNode::getURL() const {
        return URL;
    }

    URLNode* URLNode::getNext() const {
        return p_next_node;
    }

    URLNode* URLNode::getPrevious() const {
        return p_previous_node;
    }

    void URLNode::setURL_name(const string URL_name_string) {
        URL_name = URL_name_string;
    }

    void URLNode::setURL(const string URL_string) {
        URL = URL_string;
    }

    void URLNode::setNext(URLNode* const p_new_Next) {
        p_next_node = p_new_Next;
    }

    void URLNode::setPrevious(URLNode* const p_new_Previous) {
        p_previous_node = p_new_Previous;
    }


