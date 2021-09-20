/**
    ECE250
    dequeaslisttest.cpp
    Purpose: To read commands from the standard input and write the output to standard output. Responds to commands as described in project description 

    Author Simon Bell
    Version 1.0  - 31/01/2021
*/

#include <iostream>
#include <string>
#include "Deque.h"
#include "URLNode.h"
using namespace std;

string lowerCase (const string input_string);

int main()
{
    Deque history;   
    std::string line;

	while(true){

		if ( std::cin.eof() ) {
			break;
		}

        getline(std::cin,line);

		if(line=="exit"){
			break;
		}

        int pos=line.find_first_of(" ");
        std::string cmd=line.substr(0,pos);
        std::string input=line.substr(pos+1);  

        if(cmd =="print"){
            history.print();
        }

        if(cmd =="clear"){
            history.clear();
            std::cout<< "success" << std::endl;
        }

        if(cmd=="size"){
            std::size_t size_history = history.getSize();
            std::cout << "size is " << size_history << std::endl;        
        }

        if(cmd=="empty"){
            std::cout<< "empty " << history.isEmpty() <<std::endl; 
        }

        if(cmd=="front"){
            URLNode* p_front = history.getFront();   
            if(p_front == nullptr){
                std::cout << "failure" << std::endl;
            }
            else{
                std:cout << "front is " << p_front->getURL_name() << " " << p_front->getURL() << std::endl;
            }    
        }

        if(cmd=="back"){
            URLNode* p_back =history.getBack();   
            if(p_back == nullptr){
                std::cout << "failure" << std::endl;
            }
            else{
                std::cout << "back is " << p_back->getURL_name() << " " << p_back->getURL() << std::endl;
            }    
        }

        if(cmd =="find"){
            int length = input.length();
            string URL_name=input.substr(1,length-2);
            URLNode* p_URL = history.findURL(URL_name);

            if(p_URL == nullptr) {
                std::cout << "not found " << URL_name << std::endl;
            }

            else {
                std::cout << "found " << p_URL->getURL_name() << " " << p_URL->getURL() <<std::endl;
            }

        }

        if(cmd=="pop_front"){
            
            bool success = history.pop_front();

            if(success){
                std::cout << "success" << std::endl;
            }
            else{
                std::cout << "failure" << std::endl;
            }
        }

        if(cmd=="pop_back"){
            
            bool success = history.pop_back();
            
            if(success){
                std::cout << "success" << std::endl;
            }
            else{
                std::cout << "failure" << std::endl;
            }
        }   

        if(cmd=="push_back"){
            pos = input.find_last_of(" ");
            string URL_name= (input.substr(1,pos-2));
            string URL = input.substr(pos+2);
            int length = URL.length();
            URL = URL.substr(0, length-1);

            history.push_back(URL_name, URL);
            std::cout << "success" <<std::endl;
        }

        if(cmd=="push_front"){
            pos = input.find_last_of(" ");
            string URL_name= (input.substr(1,pos-2));
            string URL = input.substr(pos+2);
            int length = URL.length();
            URL = URL.substr(0, length-1);

            history.push_front(URL_name, URL);
            std::cout << "success" <<std::endl;
        }


	}

	return 0;
}

string lowerCase (const string input_string) {
    
        string lowercase_string = input_string;

            for(int i=0; i<input_string.length(); ++i) {
                lowercase_string[i] = tolower(input_string[i]);
            }
            
        return lowercase_string;
}
