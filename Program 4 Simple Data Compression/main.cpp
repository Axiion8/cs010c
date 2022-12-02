#include "Token.h"

#include <iostream>
#include <vector> //to store "hashtable" values
#include <fstream> //to open/edit files
#include <cctype> //to detect whitespaces, characters, and punctuation
#include <cstdlib> //for exit function
#include <algorithm> //to reverse table contents after insertionSort

void insertionSort(vector <Token> &table);
void insertTable(vector<Token> &table, string word);

int main(){
    
    vector<Token> table;
    string filename = "";
    string line = "";
    int length = 0;
    string word;
    ifstream inFS;
    ofstream outFS;
    
    cout << "Type in the name of the file." << endl;
    cin >> filename;

    inFS.open(filename);
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit (1);
    }

    while(!inFS.eof()){
        getline(inFS, line);
        int length = line.size(); //input each line into inFS one at a time

        while(length > 0){ //nested loop to move through each line

            while(isspace(line.at(0)) && (!line.empty())){ //removes any existing whitespaces in front of the text
                line.erase(0,1);//linuxhint.com recommended to use erase to remove first char of string
                --length;
                
                if(line.empty()){ //if line is empty, get new line
                    break;
                }
            }

            while(ispunct(line.at(0)) && (!line.empty())){ //if punctuation is present

                word = line.at(0);
                insertTable(table, word);

                line.erase(0,1);
                --length;

                if(line.empty()){ //if line is empty, get new line
                    break;
                }
            }
            word = ""; //reset word string

            int alphaCnt = 0;
            while(isalpha(line.at(alphaCnt)) && (!line.empty())){
                word.push_back(line.at(alphaCnt));
                line.erase(0,1);
                --length;

                if(line.empty()){ //if line is empty, get new line
                    break;
                }
            }
            insertTable(table, word);
            word = ""; //reset word string
        }
    }

    inFS.close();
    insertionSort(table); //sort table by word consistency
    reverse(table.begin(), table.end()); //reserve table since it's smallest to highest appCnt

    for(unsigned int i = 0; i < table.size(); ++i){ //assigns code to each word
        table.at(i).setCode(i);
    }

    outFS.open("decoder.txt");
    if(!outFS.is_open()){
        cout << "Error opening " << "decoder.txt" << endl;
        exit (1);
    }

    for(unsigned int i = 0; i < table.size(); ++i){
        outFS << table.at(i).getCode() << '\t' << table.at(i).getWord() << endl;
    }

    inFS.open(filename); //reset inFS file (not sure if needed but better safe than sorry)
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit (1);
    }



    return 0;
}

void insertionSort(vector <Token> &table){ //used geeksforgeeks algorithm
    int i = 0;
    int j = 0;
    Token temp = Token("temp");

    for(i = 1; i < table.size(); ++i){
        temp = table.at(i);
        j = i -1;

        while(j >= 0 && table.at(j).getAppCnt() > temp.getAppCnt()){
            table.at(j+1) = table.at(j);
            --j;
        }
        table.at(j+1) = temp;
    }
}

void insertTable(vector <Token> &table, string word){ //used to add AppCnt(apperance count) or create word in table
    
    for(int i = 0; i < table.size(); ++i){ //searches through table for word
        if(table.at(i).getWord() == word){
            table.at(i).addAppCnt();
            return;
        }
    }

    Token newEntry(word); //if word not found, word is created in table
    table.push_back(newEntry);
}