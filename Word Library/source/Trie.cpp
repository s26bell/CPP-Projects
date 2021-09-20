/**
    ECE250
    Trie.cpp

    Author Simon Bell
    Version 1.0  - 03/12/2021
*/
#include <iostream>
#include <string>
#include "Trie.h"
#include "TrieNode.h"
#include "illegal_exception.h"
using namespace std;

void invalidInput(string input);

    //Constructor
    Trie::Trie() {
        numberOfWords = 0;
        maxWordLength = 0;
        p_root = new TrieNode;
    }

    //Destructor
    Trie::~Trie(){ //Deallocate whatever was allocated in the push front/back
        clear(p_root);
        numberOfWords = 0;
        maxWordLength = 0;
    }

    std::size_t Trie::getNumberOfWords() const {
        return numberOfWords;
    }

    std::size_t Trie::getMaxWordLength() const {
        return maxWordLength;
    }

    TrieNode* Trie::getRoot() const {
        return p_root;
    }

    bool Trie::getFirstWord() const{
        return firstWord;
    }

    void Trie::setFirstWord(const bool value) {
        firstWord = value;
    }

    bool Trie::search(const string word, TrieNode* p_node, std::size_t position) const {
        if (position == 0) {
            invalidInput(word);
        }
        std::size_t NodeIndex = word[position] - 'a';
        if (position <= word.length()) {

            if (p_node->getNode(NodeIndex) != nullptr) {
                    return search(word, p_node->getNode(NodeIndex), position + 1);
            }
            else if (p_node->getTerminal() && position == word.length()){
                return true;
            }
            else{
                return false;
            }

        }
        else {
            return false;
        }
    }

    void Trie::autocomplete(const string letter, TrieNode* p_node, std::size_t position){
        std::size_t NodeIndex = letter[position] - 'a';
        if (position < letter.length() && p_node->getNode(NodeIndex) != nullptr) {
            autocomplete(letter, p_node->getNode(NodeIndex), position +1);
        }
        else if (position == letter.length()){

            if (p_node->getTerminal()){
                std::cout << letter;
                firstWord = false;
            }
            char* printAuto = new char[maxWordLength +1];
            printTrie(p_node, printAuto, letter);
            delete[] printAuto;
            printAuto = nullptr;
        }
    
    }

    bool Trie::insertWord(const string newWord, TrieNode* p_node, std::size_t position){
        if (position == 0) {
            invalidInput(newWord);
        }
        if(position < newWord.length()){
            std::size_t nodeIndex = newWord[position] - 'a'; 
            if(p_node->getNode(nodeIndex) == nullptr){
                TrieNode* new_node = new TrieNode;
                p_node->setNode(new_node, nodeIndex);
            }
            insertWord(newWord, p_node->getNode(nodeIndex), position+1);
        }
        else{
            ++numberOfWords;
            if(newWord.length() > maxWordLength){
                maxWordLength = newWord.length();
            }
            p_node->setTerminal(true);
        }

    }

    void Trie::deleteWord(const string newWord, TrieNode* p_current, std::size_t position){
        if (position == 0) {
            invalidInput(newWord);
        }
        std::size_t nodeIndex = newWord[position] - 'a';
        if(position < newWord.length() -1){
            deleteWord(newWord, p_current->getNode(nodeIndex), position+1 );
            if(p_current->getNode(nodeIndex) != nullptr){
                if(p_current->getNode(nodeIndex)->isEmpty() && !p_current->getNode(nodeIndex)->getTerminal()) {
                    delete p_current->getNode(nodeIndex);
                    p_current->setNode(nullptr, nodeIndex);
                }
            }
        }
        else if(p_current->getNode(nodeIndex)->isEmpty() && p_current->getNode(nodeIndex)->getTerminal()){
            delete p_current->getNode(nodeIndex);
            p_current->setNode(nullptr, nodeIndex);
            --numberOfWords;
        }
        else if (p_current->getNode(nodeIndex)->getTerminal()){
            p_current->getNode(nodeIndex)->setTerminal(false);
            --numberOfWords;
        }
        return;
    }

    void Trie::clear(TrieNode* p_current){
        for(std::size_t i=0; i<26; ++i){ 
            if(p_current->getNode(i) != nullptr){
               clear(p_current->getNode(i));
            }
        } 
        delete p_current;
        p_current = nullptr;
    }

    void Trie::clearandCreate(TrieNode* p_current) {
        clear(p_current);
        p_root = new TrieNode;
        numberOfWords = 0;
    }

    void Trie::printTrie(TrieNode* p_current, char wordArray[], std::size_t position){
        for(std::size_t i =0; i<26; ++i){
            if(p_current->getNode(i) != nullptr){
                wordArray[position] = i + 'a';
                if(p_current->getNode(i)->getTerminal()){
                    wordArray[position+1] = '\0';
                    if(!firstWord){
                        std::cout << " ";
                    }
                    std::cout << wordArray;
                    firstWord = false;
                }
                printTrie(p_current->getNode(i), wordArray, position+1);
            }
        }
    }

    void Trie::printTrie(TrieNode* p_current, char wordArray[], const string prefix, std::size_t position){
        for(std::size_t i =0; i<26; ++i){
            if(p_current->getNode(i) != nullptr){
                wordArray[position] = i + 'a';
                if(p_current->getNode(i)->getTerminal()){
                    wordArray[position+1] = '\0';
                    if(!firstWord){
                        std::cout << " ";
                    }
                    std::cout << prefix << wordArray;
                    firstWord = false;
                }
                printTrie(p_current->getNode(i), wordArray, prefix, position+1);

            }
        }
        
    }






