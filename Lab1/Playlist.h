#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>

using namespace std;

class PlaylistNode{

    PlaylistNode();
    //Parameterized constructor? suppose to be here.

    public:
        void InsertAfter(); //not sure if it's suppose to be void
        void SetNext();
        string GetID() const;

        


};

#endif