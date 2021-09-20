/**
    ECE250
    URLNode.h

    Author Simon Bell
    Version 1.0  - 01/31/2021
*/
#ifndef URLNode_hpp
#define URLNode_hpp
#include <iostream>
#include <string>
using namespace std;

class URLNode {

    // class variables
	private:
    string URL_name;
    string URL;
    URLNode* p_next_node;
    URLNode* p_previous_node;


    // class functions
    public:
    //Constructor and Destructor
    URLNode ();
    ~URLNode();

    //Member Functions
    string getURL_name() const;
    string getURL() const;
    URLNode* getNext()  const;
    URLNode* getPrevious() const ;
    void setURL_name(const string URL_name_string);
    void setURL(const string URL_string); 
    void setNext(URLNode* const p_new_Next);
    void setPrevious(URLNode* const p_new_Previous);
};
#endif