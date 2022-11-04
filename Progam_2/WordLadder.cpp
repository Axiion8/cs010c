#include <iostream>
#include <fstream>
#include <list>
using namespace std;

#include "WordLadder.h"

WordLadder::WordLadder(const string& inputFile) {
    ifstream inFS;
    string input;
    inFS.open(inputFile);
    if (!inFS.is_open() || inputFile.size() != 5) {
        cout << "Could not open file " << inputFile << "." << endl;
        exit(1);
    }

    while (inFS >> input) {
        if (input.size() > 5) {
            cout << "Error" << endl;
            exit(1);
        }
        else {
            dict.push_back(input);
        }
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;

    outFS.open(outputFile);

    if (!outFS.is_open() || outputFile.size() != 5) {
        cout << "Could not open file " << outputFile << "." << endl;
    }

    dict.push_front(start);
    dict.push_back(end);

    long unsigned int size = dict.size();
    dict.unique();

    if (dict.size() == size) {
        cout << "No Word Ladder Found" << endl;
        exit(1);
    }

    while (dict.size() != 0) {
        outFS << dict.front() << " ";
        dict.pop_front();
    }
}