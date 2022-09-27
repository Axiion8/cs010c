#include "Playlist.h"

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength){
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* afterThis){
    this->nextNodePtr = afterThis->GetNext();
}

void PlaylistNode::SetNext(PlaylistNode* nextNode){
    nextNodePtr = nextNode;
}

string PlaylistNode::GetID() const{
    return uniqueID;
}

string PlaylistNode::GetSongName() const{
    return songName;
}

string PlaylistNode::GetArtistName() const{
    return artistName;
}

int PlaylistNode::GetSongLength() const{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl <<
            "Song Name: " << songName << endl <<
            "Artist Name: " << artistName << endl <<
            "Song Length (in seconds): " << songLength << endl;
}