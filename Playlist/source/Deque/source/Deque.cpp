/**
    ECE250
    Deque.cpp

    Author Simon Bell
    Version 1.0  - 1/31/2020
*/

#include <iostream>
#include <string>
#include "Deque.h"
#include "URLNode.h"
#include <string>
using namespace std;

string lowerCase (const string input_string);

    //Constructor
    Deque::Deque() {
        p_back = nullptr;
        p_front = nullptr;
        size = 0;
    }
    //Destructor
    Deque::~Deque(){ //Deallocate whatever was allocated in the push front/back
        clear();
    }

    bool Deque::isEmpty() const{
        if (size == 0){
            return true;
        }
        else {
            return false;
        }
    }

    URLNode* Deque::getFront() const {
        if (size>0) {
            return p_front;
        }
        else{
            return nullptr;
        }
        
    }

    URLNode* Deque::getBack() const {
        if(size>0) {
            return p_back;
        }
        else{
            return nullptr;
        }
    }

    std::size_t Deque::getSize() const {
        return size;
    }

    void Deque::setFront(URLNode* const p_new_front) {
        p_front = p_new_front;
    }

    void Deque::setBack(URLNode* const p_new_back) {
        p_back = p_new_back;
    }

    URLNode* Deque::findURL(const string find_URL) const{
        URLNode* p_next = p_front;

        while (p_next!=nullptr){

            if(p_next->getURL_name().length() == find_URL.length()){

                if(lowerCase(p_next->getURL_name()) == lowerCase(find_URL)){
                        return p_next;
                        break;
                }

            }
            
            p_next = p_next->getNext();
        }

        return nullptr;
    }

    void Deque::push_front(const string URL_add_name, const string URL_add ){
        if(p_front == nullptr) {
            p_front = new URLNode;
            p_back = p_front;
            p_front->setURL(URL_add);
            p_front->setURL_name(URL_add_name);
            ++size;
        }
        
        else { 
            URLNode* p_newNode = new URLNode;
            p_newNode->setNext(p_front);
            p_newNode->setURL(URL_add);
            p_newNode->setURL_name(URL_add_name);
            p_front->setPrevious(p_newNode);
            p_front = p_newNode;
            ++size;
        }

    }

    void Deque::push_back(const string URL_add_name, const string URL_add) {
        if(p_back == nullptr) {
            p_back = new URLNode;
            p_front = p_back;
            p_back->setURL(URL_add);
            p_back->setURL_name(URL_add_name);
            ++size;
        }
        else { 
            URLNode* p_newNode = new URLNode;
            p_newNode->setPrevious(p_back);
            p_newNode->setURL(URL_add);
            p_newNode->setURL_name(URL_add_name);
            p_back->setNext(p_newNode);
            p_back = p_newNode;
            ++size;
        }

    }

    bool Deque::pop_front() {
        if(!isEmpty()) {
            URLNode* p_delete = p_front; 
            p_front = p_front->getNext();
            delete p_delete;
            if(p_front == nullptr){
                p_back = nullptr;
            }
            else {
                p_front->setPrevious(nullptr);
            }
            --size;
            return true;
        }
        else {
            return false;
        }
    }

    bool Deque::pop_back() {
        if(!isEmpty()) {
            URLNode* p_delete = p_back; 
            p_back = p_back->getPrevious();
            delete p_delete;
            if(p_back == nullptr){
                p_front = nullptr;
            }
            else {
                 p_back->setNext(nullptr);
            }
            --size;
            return true;
        }
        else {
            return false;
        }  
    }

    void Deque::clear() {
        while(p_front!=nullptr) {
            pop_front();
        }
    }

    void Deque::print() const {
        if(size > 0) {
            URLNode* p_current_node = p_back;
            for(std::size_t i =0; i<size; ++i) {
                std::cout << p_current_node->getURL_name() << " " << p_current_node->getURL() << std::endl;
                p_current_node = p_current_node->getPrevious();
            }    
        }
     }





