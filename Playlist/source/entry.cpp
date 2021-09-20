/**
    ECE250
    entry.cpp
    Purpose:

    Author Simon Bell
    Version 1.0  - 1/19/2020
*/
#include <iostream>
using namespace std;

#include "entry.h"

    Entry::Entry() {
        song = "";
        artist = "";
    }

    void Entry::set_artist(const string artist_name) {
        artist = artist_name;
    }

    void Entry::set_song(const string song_name) {
        song = song_name;
    }

    string Entry::get_artist() {
        return artist;
    }

    string Entry::get_song() {
        return song;
    }


