#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <string>
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
    int i;
    int j;
    int counter;
    ofstream outFS;

    outFS.open(outputFile);

    if (!outFS.is_open() || outputFile.size() != 5) {
        cout << "Could not open file " << outputFile << "." << endl;
    }

    stack<string> stacklist;
    stacklist.push(start);
    
    queue<stack<string>> queuelist;
    queuelist.push(stacklist);

    while (queuelist.size() != 0) {
        stack<string> temp = queuelist.front();
        string word = temp.top();
        for (i = 0; i < dict.size(); ++i) {
            for (j = 0; j < 5; ++j) {
                if (word.at(i) == dict.front().at(i)) {
                    counter = counter + 1;
                }
            }
            if (counter != dict.size()) {
                stack<string> nList; 
                nList = queuelist.front();
                nList.push(dict.front());
                if (nList.size() - 1 == 0) {
                    break;
                }
                else {
                    queuelist.push(nList);
                    dict.pop_front();
                }
            }
        }
        queuelist.pop();
    }
}