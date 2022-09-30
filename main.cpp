#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

void PrintMenu(string playlist) {
    cout << playlist << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
}
void addsong(PlaylistNode* current) {
    string uID;
    string sName;
    string aName;
    int sLength;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    getline (cin, uID);
    cout << "Enter song's name:" << endl;
    getline (cin, sName); 
    cout << "Enter artist's name:" << endl;
    getline (cin, aName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> sLength;

    current = new PlaylistNode(uID, sName, aName, sLength);
}
void removesong(PlaylistNode* head, string idtoremove) { // Used resource from Scaler Academy
    PlaylistNode* temp = nullptr;
    if (head->GetID() == idtoremove) {
        cout << "\"" << head->GetSongName() << "\" removed" << endl;
        temp = head;
        head = head->GetNext();
        delete temp;
    }
    else {
        PlaylistNode* curr = head;
        while (curr->GetNext() != nullptr) {
            if (curr->GetNext()->GetID() == idtoremove) {
                cout << "\"" << curr->GetNext()->GetSongName() << "\" removed" << endl;
                temp = curr->GetNext();
                curr->SetNext(curr->GetNext()->GetNext());
                delete temp;
                break; // ends loop
            }
            else {
                curr = curr->GetNext();
            }
        }
    }
}

void changeposition (PlaylistNode* head, int position, PlaylistNode* currNode) { // Used resource from AlphaCodingSkills
    PlaylistNode* next = currNode->GetNext();
    if (position < 1) {
        cout << "position should be >= 1" << endl;
    }
    else if (position == 1) {
        next = head;
        head = currNode;
    }
    else {
        PlaylistNode* temp = head;
        for (int i = 1; i < position - 1; ++i) {
            if (temp != nullptr) {
                temp = temp->GetNext();
            }
        }
        if (temp != nullptr) {
        currNode->SetNext(temp->GetNext());
        temp->SetNext(currNode);
    }
        else {
            cout << "The previous node is null" << endl;
        }
    }
}

void outputplaylist(PlaylistNode* head) {
    PlaylistNode* curr = head;
    int number = 1;
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        cout << endl;
    }
    else {
        while (curr != nullptr) {
            cout << number << "." << endl;
            curr->PrintPlaylistNode();
            curr = curr->GetNext();
        }
    }
}

void outputsongs(PlaylistNode* head, string artistName) {
    PlaylistNode* curr = nullptr;
    curr = head;
    int number = 1;
    while (curr != nullptr) {
        if (curr->GetArtistName() == artistName) {
            cout << number << "." << endl;
            curr->PrintPlaylistNode();
        }
        number = number + 1;
        curr = curr->GetNext();
    }
}

void totaltime(PlaylistNode* head) {
    PlaylistNode* curr = nullptr;
    curr = head;
    int total = 0;
    while (curr != nullptr) {
        total = total + curr->GetSongLength();
        curr = curr->GetNext();
    }
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << total << " seconds" << endl;
}

int main() {
    string playlist;
    string option;
    string idtoremove;
    int i;
    int position;
    int newposition;
    bool help = false;
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    PlaylistNode* curr = nullptr;
    cout << "Enter playlist's title:" << endl;
    getline (cin, playlist);
    cout << endl;
    while (option != "q") {
        PrintMenu(playlist);
        cout << endl;
        cout << "Choose an option:" << endl;
        getline (cin, option);
        if (option == "a") {
            if (!help) {
                addsong(head);
                tail = head;
                help = true;
            }
            else {
                addsong(curr);
                tail->InsertAfter(curr);
                tail = curr;
            }
        }
        else if (option == "d") {
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID: " << endl;
            getline (cin, idtoremove);
            removesong(head, idtoremove);
        }
        else if (option == "c") { 
            PlaylistNode* helper = nullptr;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> position;
            cout << "Enter new position for song" << endl;
            cin >> newposition;
            cin.get();
            for (i = 0; i < 3; ++i) {
                helper = helper->GetNext();
            }
            PlaylistNode* tmp = helper;
            removesong(head, helper->GetID());
            changeposition(head, newposition, tmp);
        }
        else if (option == "s") {
            string artistname;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name: " << endl;
            getline (cin, artistname);
            outputsongs(head, artistname);
        }
        else if (option == "t") {
            totaltime(head);
        }
        else if (option == "o") {
            cout << playlist << " - OUTPUT FULL PLAYLIST" << endl;
            outputplaylist(head);
        }

    }

}