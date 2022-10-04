#include "IntList.h"

IntList::IntList(){ //creating dummyNodes and setting up their ptrs
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList(){
    IntNode* currNode = dummyHead->next;
    IntNode* sucNode = dummyHead->next->next;

    while (currNode->next != nullptr){
        delete currNode;
        currNode = sucNode;
        sucNode = sucNode->next;
    }
}

void IntList::push_front(int value){
    IntNode* newNode = new IntNode(value);

    newNode->next = dummyHead->next;
    newNode->prev = dummyHead;

    dummyHead->next->prev = newNode;
    dummyHead->next = newNode;
}

void IntList::pop_front(){
    if(!empty()){
        IntNode* currNode = dummyHead->next;
        IntNode* sucNode = currNode->next;

        sucNode->prev = dummyHead;
        dummyHead->next = sucNode;
        delete currNode;
    }
}

void IntList::push_back(int value){
    if(empty()){//if list is empty, copy and paste push_front
        IntNode* newNode = new IntNode(value);

        newNode->next = dummyHead->next;
        newNode->prev = dummyHead;

        dummyHead->next->prev = newNode;
        dummyHead->next = newNode;
    }
    else{
        
    }
}

bool IntList::empty() const{
    if(dummyHead->next = dummyTail){
        return false;
    }
    else{
        return true;
    }
}