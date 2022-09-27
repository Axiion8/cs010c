#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>

using namespace std;

class PlaylistNode{

    PlaylistNode();
    PlaylistNode(string, string, string, int);

    public:
        void InsertAfter();
        void SetNext();
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        string GetSongLength() const;
        string GetNext() const;
        void PrintPlaylistNode();
    
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

#endif