/**
    ECE250
    Trie.h

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#ifndef trie_hpp
#define trie_hpp
#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

class Trie {

    // class variables
	private:
    std::size_t numberOfWords;
    std::size_t maxWordLength;
    TrieNode* p_root;
    bool firstWord = true;

    // class functions
    public:
    //Constructor and Destructor
    Trie();
    ~Trie();

    //Member Functions
    std::size_t getNumberOfWords() const;
    std::size_t getMaxWordLength() const;
    TrieNode* getRoot() const;
    bool getFirstWord() const;
    void setFirstWord(const bool value);
    bool search(const string word, TrieNode* p_node, std::size_t position = 0) const;
    void autocomplete(const string letter, TrieNode* p_node, std::size_t position = 0);
    bool insertWord(const string newWord, TrieNode* p_node, std::size_t position = 0);
    void deleteWord(const string newWord, TrieNode* p_current, std::size_t position = 0);
    void clear(TrieNode* p_current);
    void clearandCreate(TrieNode* p_current);
    void printTrie(TrieNode* p_current, char wordArray [], std::size_t position = 0);
    void printTrie(TrieNode* p_current, char wordArray[], const string prefix, std::size_t position = 0);


};
#endif