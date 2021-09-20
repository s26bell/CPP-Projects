/**
    ECE250
    entry.h
    Purpose: 

    Author Simon Bell
    Version 1.0  - 01/19/2021
*/
#ifndef entry_hpp
#define entry_hpp
#include <iostream>
using namespace std;

class Entry {

    // class variables
	private:
	string  artist;  // pointer to the playlist
	string  song;  //length of playlist


    // class functions
    public:
    Entry();
    void set_artist(const string artist_name);
    void set_song(const string song_name);
    string get_artist();
    string get_song();

};
#endif