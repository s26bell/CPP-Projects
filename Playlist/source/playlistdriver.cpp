/**
    ECE250
    playlistdriver.cpp
    Purpose: 

    Author Simon Bell
    Version 1.0  - 17/12/2019
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
#include "playlist.h"
#include "entry.h"

int main()
{
    
    string line;
    int m_input =0;

    getline(std::cin,line);

    int pos=line.find(" ");
	std::string cmd=line.substr(0,pos);
	std::string input=line.substr(pos+1);

    if(cmd=="m"){
            m_input = stoi(input);
            std::cout << "success" <<std::endl;
	}

    Playlist playlist(m_input);

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
            pos=input.find(";");
            std::string song=input.substr(0,pos);
            std::string artist=input.substr(pos+1);

            playlist.add_song(artist, song);
		}

		if(cmd=="p"){
            int song_number = stoi(input);

            playlist.play_song(song_number);

		}

		if(cmd=="e"){
            int erase = stoi(input);

            playlist.delete_song(erase);
		}

	}

	return 0;
}