//used GeeksForGeeks insertion algorithm

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

class Token{
    public:
        Token(const string &);
        void addAppCnt();
        void setCode(int);

        const string getWord();
        const int getAppCnt();
        const int getCode();
        Token& operator=(const Token &);
    private:
        string word;
        int appCnt;
        int code;
};

#endif