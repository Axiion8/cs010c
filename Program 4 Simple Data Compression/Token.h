/*Online Sources Used:

https://www.geeksforgeeks.org/insertion-sort/
https://linuxhint.com/remove-first-character-string-cpp/#:~:text=Example%201%3A%20Remove%20the%20First,from%20a%20string%20in%20place.
*/

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