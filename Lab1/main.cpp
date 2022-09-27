#include "Playlist.h"


void PrintMenu(string){ } //STEP 3 Declaration

int main(){
    string playlistName; // playlist variable name
    string menuIn; //menu input variable

    cout << "Enter playlist's title: " << endl; //STEP 2 COMPLETE
    cin >> playlistName;

    PrintMenu(playlistName); //paramater used to input playlist name into menu
    cin >> menuIn;

    while(menuIn != "q"){ //used while loop to continuously cycle through loop until q is selected

        if (menuIn == "a"){
            
        }
        else if(menuIn == "d"){

        }
        else if(menuIn == "c"){
            
        }
        else if(menuIn == "s"){
            
        }
        else if(menuIn == "t"){
            
        }
        else if(menuIn == "o"){ //STEP 4
            cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;
        }
    }

    return 0;
}

void PrintMenu(string playlistName){ //STEP 3 Menu Prompt
    cout << playlistName << " PLAYLIST MENU" << endl <<
    "a - Add song" << endl <<
    "d - Remove song" << endl <<
    "c - Change position of song" << endl <<
    "s - Output songs by specific artist" << endl <<
    "t - Output total time of playlist (in seconds)" << endl <<
    "o - Output full playlist" << endl <<
    "q - Quit" << endl << endl <<
    "Choose an option: ";
}