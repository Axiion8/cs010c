#include "Token.h"

Token::Token(const string &input){ //default constructor
    word = input;
    appCnt = 1;
    code = 0;
}

void Token::addAppCnt(){
    ++appCnt;
}

void Token::setCode(int input){
    code = input;
}

const string Token::getWord(){
    return word;
}

const int Token::getAppCnt(){
    return appCnt;
}

const int Token::getCode(){
    return code;
}

Token& Token::operator=(const Token &rhs){
    word = rhs.word;
    appCnt = rhs.appCnt;
    code = rhs.code;
    return *this;
}