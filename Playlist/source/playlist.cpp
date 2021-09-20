/**
    ECE250
    playlist.cpp
    Purpose:

    Author Simon Bell
    Version 1.0  - 1/19/2020
*/
#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"
#include "entry.h"


Playlist::Playlist (const int size_list){
    length = size_list;
    play_list = new Entry[size_list];
}

Playlist::~Playlist() {
 	delete [] play_list;
    play_list = nullptr;

 }

 void Playlist::play_song(const int n){
     
     if(n <= length && n>0) {
    string play_song = play_list[n-1].get_song();
    string play_artist = play_list[n-1].get_artist();

        if(play_song == "" || play_artist == "") {
             std::cout << "can not play " << n <<std::endl;
        }
        else {
            std::cout << "played " << n << " "<< play_song << ";" << play_artist << std::endl;
        }
    
    }
    else{
        std::cout << "can not play " << n <<std::endl;
    }   
 }

 void Playlist::delete_song(const int n) {

    if( n > length || n<=0) {
        std::cout << "can not erase " << n <<std::endl;
    }
    else if (play_list[n-1].get_artist() == "" || play_list[n-1].get_song() == "") {
        std::cout << "can not erase " << n <<std::endl;
    }
    else{
        Entry* new_playlist = new Entry[length];

        if (n > 1 && n < length){
            for(int i =0; i<n-1; ++i) {
                new_playlist[i] = play_list[i]; 
            }

            for(int k=n; k<length; ++k) {
                new_playlist[k-1] = play_list[k];
            }
        }

        else if (n == 1 ) {
            for(int j=1; j<length; ++j){
                new_playlist[j-1] = play_list[j];
            }
        }

        else if (n == length){
            for(int f=0; f<length-1; ++f){
                new_playlist[f] = play_list[f];
            }
        }
        std::cout<< "success" <<std::endl;

    delete [] play_list;
    play_list = new_playlist;
    new_playlist = nullptr;


    }
    
 }


 void Playlist::add_song(const string artist_name, const string song_name) {

    bool copy_flag = false;
    bool success_add = false;

        for(int j=0; j<length; ++j) {

            if(play_list[j].get_artist().length() == artist_name.length() && play_list[j].get_song().length() == song_name.length()){
                string temp_artist = artist_name;
                string current_artist = play_list[j].get_artist();

                    for(int i=0; i<temp_artist.length(); ++i) {
                        temp_artist[i] = tolower(artist_name[i]);
                        current_artist[i] = tolower(current_artist[i]);
                    }    


                    if (temp_artist == current_artist) {
                        
                        string current_song = play_list[j].get_song();
                        string temp_song = song_name;

                            for(int i=0; i<temp_song.length(); ++i) {
                            temp_song[i] = tolower(song_name[i]);
                            current_song[i] = tolower(current_song[i]);

                            if(temp_song == current_song){
                                copy_flag = true;
                            }

                            }
                    }
        
            }
        
        }

            if(copy_flag == false) {

                for(int i=0; i<length; ++i) {

                    if(play_list[i].get_artist() == "" && play_list[i].get_song() == "" && success_add == false) {
                        int current_length = i+1;
                            if(current_length <= length){
                                Entry* new_playlist = new Entry[length+1];

                                for(int j=0; j<length; ++j) {
                                    new_playlist[j] = play_list[j];
                                }

                                new_playlist[i].set_artist(artist_name);
                                new_playlist[i].set_song(song_name);

                                std::cout << "success"<< std::endl;
                                success_add = true;

                                delete [] play_list;
                                play_list = new_playlist;
                                new_playlist = nullptr;

                            }
                            else{
                                success_add = true;
                            }
                    }
                }
                
                
            }
            if(success_add == false || copy_flag == true){
                    std::cout << "can not insert " << song_name << ";" << artist_name << std::endl;
                }    
    }
 


 void Playlist::print() {
     for(int j=0; j<length; ++j) {

         std::cout << play_list[j].get_song() << " by " << play_list[j].get_artist() << std::endl;

     }
 }



