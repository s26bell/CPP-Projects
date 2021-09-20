/**
    ECE250
    playlist.h
    Purpose: 

    Author Simon Bell
    Version 1.0  - 01/19/2021
*/
#ifndef playlist_hpp
#define playlist_hpp
#include <iostream>
using namespace std;

#include "entry.h"

class Playlist {

    // class variables
	private:
	int length;  //length of playlist
    Entry* play_list;


    // class functions
    public:

    //Constructor and Destructor
    Playlist (const int size_list);
    ~Playlist();

    //Member Functions
    void play_song(const int n);
    void add_song(const string artist_name, const string song_name);
    void delete_song(const int n);
    void print();

};
#endif