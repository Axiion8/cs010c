#include "Token.h"

#include <iostream>
#include <vector> //to store "hashtable" values
#include <fstream> //to open/edit files
#include <cctype> //to detect whitespaces
#include <cstdlib> //for exit function
#include <sstream> //to seperate words from sentences

void insertionSort(vector <Token> &table);
void insertTable(vector<Token> &table, stringstream word);

int main(){
    
    vector<Token> table;
    string filename = "";
    string line = "";
    int temp;
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
        int temp = line.size(); //input each line into inFS one at a time

        while(temp > 0){ //nested loop to move through each line

            while(isspace(line.at(0)) && (!line.empty())){ //removes any existing whitespaces in front of the text
                line.erase(0,1);//linuxhint.com recommended to use erase to remove first char of string
                
                if(line.empty()){ //if line is empty, get new line
                    break;
                }
            }


        }
    }

    return 0;
}

void insertionSort(vector <Token> &table){ //used geeksforgeeks.com
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

void insertTable(vector <Token> &table, stringstream word){

}