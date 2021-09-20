/**
    ECE250
    TrieNode.cpp

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

    //Constructor
    TrieNode::TrieNode(){
        isTerminal=false;
        clear();
    }

    //Destructor
    TrieNode::~TrieNode() {
        clear();
    }
    
    //Member Functions

    bool TrieNode::getTerminal() const {
        return isTerminal;
    }

    TrieNode* TrieNode::getNode(const std::size_t index) const {
        if(index < 26 && index >= 0){
            return LetterNode[index];
        }
        return nullptr;
    }

    void TrieNode::setTerminal(const bool terminal) {
        isTerminal = terminal;
    }

    void TrieNode::setNode(TrieNode* node, const std::size_t letter){
            if(letter < 26 && letter >= 0){
                LetterNode[letter] = node; 
            }       
    }
    
    bool TrieNode::isEmpty() const {
        for(std::size_t i = 0; i<26; ++i){
            if(LetterNode[i] != nullptr){
                return false;
            }
        }
        return true;
    }

    void TrieNode::clear() {
        for(std::size_t i=0; i<26; ++i) {
            LetterNode[i] = nullptr;
        }
        
    }

   


