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
        IntNode* currNode = dummyHead->next;//make new ptrs
        IntNode* sucNode = currNode->next;

        sucNode->prev = dummyHead;//
        dummyHead->next = sucNode;
        delete currNode;
        currNode = nullptr;
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
        IntNode* newNode = new IntNode(value);//set up ptrs
        IntNode* currNode = dummyTail->prev;

        newNode->prev = currNode;//linking newNode to neighbors
        newNode->next = dummyTail;

        currNode->next = newNode;//linking neighbors to newNode
        dummyTail->prev = newNode;
    }
}

void IntList::pop_back(){
    if(!empty()){//if empty, function does nothing
        IntNode* currNode = dummyTail->prev;//set up ptrs
        IntNode* sucNode = currNode->prev;

        sucNode->next = dummyTail;
        dummyTail->prev = sucNode;
        delete currNode;
        currNode = nullptr;
    }
}

bool IntList::empty() const{
    if(dummyHead->next == dummyTail){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream &out, const IntList &rhs){
    if(rhs.empty()){
        out << "";
        return out;
    }
    
    else{
        IntNode* currNode = rhs.dummyHead->next;

        while (currNode != rhs.dummyTail){
            if (currNode->next != rhs.dummyTail){
                out << currNode->data << " ";
            }
            else{
                out << currNode->data;
            }
            currNode = currNode->next;
        }
        return out;
    }
}

void IntList::printReverse() const{
    if(!empty()){
        IntNode* currNode = dummyTail->prev;

        while(currNode != dummyHead){
            if(currNode->prev != dummyHead){
                cout << currNode->data << " ";
            }
            else{
                cout << currNode->data;
            }
            currNode = currNode->prev;
        }
    }
}