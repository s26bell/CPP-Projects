/**
    ECE250
    trietest.cpp
    Purpose: To read commands from the standard input and write the output to standard output. Responds to commands as described in project description 

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

int main()
{
    Trie Dictionary;
    string line = "";

	while(true){

    getline(std::cin,line);

    int pos=line.find(" ");
	std::string cmd=line.substr(0,pos);
	std::string input=line.substr(pos+1);

		if ( std::cin.eof() ) {
			break;
		}

		if(line=="exit"){
			break;
		}

		if(cmd=="i"){
            try{
                if(Dictionary.search(input, Dictionary.getRoot())){
                    std::cout<<"failure" <<std::endl;
                }   
                else{
                    Dictionary.insertWord(input, Dictionary.getRoot());
                    std::cout << "success" << std::endl;
                }
            }
            catch(illegal_exception& e){
                std::cout << e.getException() << std::endl;
            }
            
		}

		if(cmd=="e"){
            try{
                if(Dictionary.search(input, Dictionary.getRoot())){
                    Dictionary.deleteWord(input, Dictionary.getRoot());
                    std::cout<<"success" <<std::endl;
                }
                else{
                    std::cout << "failure" << std::endl;
                }
            }
            catch(illegal_exception& e){
                std::cout << e.getException() << std::endl;
            }
            
		}

        if(cmd=="s"){
            try{
                if(Dictionary.search(input, Dictionary.getRoot())){
                    std::cout<<"found " << input << std::endl;
                }
                else{
                    std::cout << "not found" << std::endl;
                }
            }
            catch(illegal_exception& e){
                std::cout << e.getException() << std::endl;
            }
		}

        if(cmd=="print"){
            if(Dictionary.getNumberOfWords() != 0){
                char* words = new char[Dictionary.getMaxWordLength()+1];
                Dictionary.setFirstWord(true);
                Dictionary.printTrie(Dictionary.getRoot(), words); 
                std::cout<<std::endl;
                delete[] words;
                words = nullptr;
            }
            
		}

        if(cmd=="autocomplete"){
            if(Dictionary.getNumberOfWords() != 0){
                char* words = new char[Dictionary.getMaxWordLength()+1];
                Dictionary.setFirstWord(true);
                input.pop_back();
                if(input == "") {
                    Dictionary.printTrie(Dictionary.getRoot(), words);
                }
                else{
                    Dictionary.autocomplete(input, Dictionary.getRoot());
                }

                if(!Dictionary.getFirstWord()){
                    std::cout<<std::endl;
                } 

                delete[] words;
                words = nullptr;
		    }
        }
            

        if(cmd=="empty"){
            if(Dictionary.getNumberOfWords() == 0){
                std::cout << "empty 1" << std::endl;
            }
            else{
                std::cout << "empty 0" << std::endl;
            }
        }

        if(cmd=="clear"){
            Dictionary.clearandCreate(Dictionary.getRoot());
            std::cout << "success" << std::endl;    
        }

        if(cmd=="size"){
            std::cout << "number of words is " << Dictionary.getNumberOfWords() << std::endl;
        }

	}


    return 0;
}

void invalidInput(string input) {
    for(std::size_t i = 0; i< input.length(); ++i){
        if(input[i] < 'a' || input[i] > 'z'){
            throw(illegal_exception("illegal argument"));
        }
    }
}
