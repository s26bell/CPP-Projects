/**
    ECE250
    TrieNode.h

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#ifndef trienode_hpp
#define trienode_hpp
#include <iostream>
#include <string>
using namespace std;

class TrieNode {

    // class variables
	private:
    TrieNode* LetterNode[26];
    bool isTerminal;


    // class functions
    public:
    
    //Constructor and Destructor
    TrieNode ();
    ~TrieNode();

    //Member Functions
    bool getTerminal() const;
    TrieNode* getNode(std::size_t index) const;
    void setTerminal(const bool terminal);
    void setNode(TrieNode* node, const std::size_t letter);
    bool isEmpty() const;
    void clear();
};
#endif