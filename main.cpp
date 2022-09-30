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
void addsong(PlaylistNode*& current, int &size) {
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
    cin.ignore();
    cout << endl;
    current = new PlaylistNode(uID, sName, aName, sLength);
    size++;
}
void removesong(PlaylistNode*& head, string idtoremove, int &size) { // Used resource from Scaler Academy
    PlaylistNode* temp = nullptr;
    if (head->GetID() == idtoremove) {
        cout << "\"" << head->GetSongName() << "\" removed" << endl;
        temp = head;
        head = head->GetNext();
        delete temp;
        size--;
    }
    else {
        PlaylistNode* curr = head;
        while (curr->GetNext() != nullptr) {
            if (curr->GetNext()->GetID() == idtoremove) {
                cout << "\"" << curr->GetNext()->GetSongName() << "\" removed." << endl;
                cout << endl;
                temp = curr->GetNext();
                curr->SetNext(curr->GetNext()->GetNext());
                delete temp;
                temp = nullptr;
                size--;
                break; // ends loop
            }
            else {
                curr = curr->GetNext();
            }
        }
    }
}

void changeposition (PlaylistNode*& head, int position, PlaylistNode*& current, int &size) { // Used resource from AlphaCodingSkills
    //position is new node location
    //current is 
    
    int count = 1;
    PlaylistNode* previous = nullptr;
    current->SetNext(head);
    head = current;
    if (position < 1) {
        position = 1;
    }
    else if (position > size) {
        position = size;
    }

    while (count < position) {
        if (current->GetNext() != nullptr) {
            previous = current;
            current = current->GetNext();
            count++;
        }
        else {
            break;
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
            cout << endl;
            curr = curr->GetNext();
            number = number + 1;
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
            cout << endl;
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
    cout << endl;
}

int main() {
    string playlist;
    string option;
    string idtoremove;
    int i;
    int position;
    int newposition;
    int size = 0;
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
                addsong(head, size);
                tail = head;
                help = true;
            }
            else {
                addsong(curr, size);
                tail->InsertAfter(curr);
                tail = curr;
            }
        }
        else if (option == "d") {
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline (cin, idtoremove);
            removesong(head, idtoremove, size);
        }
        else if (option == "c") { 
            PlaylistNode* helper = nullptr;
            helper = head;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> position;
            cout << "Enter new position for song" << endl;
            cin >> newposition;
            cin.ignore();
            while (position--) {
                helper = helper->GetNext();
            }
            changeposition(head, newposition, helper, size);
            cout << helper->GetSongName() << " moved to position " << newposition << endl;
        }
        else if (option == "s") {
            string artistname;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cout << endl;
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