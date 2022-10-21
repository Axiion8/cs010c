#ifndef STACK_H
#define STACK_H

#include<stdexcept>

using namespace std;

template<typename T>

class stack {

    private:
        static const int length = 20;
        T data[length];
        int size;
    public:
        stack<T>(){
            size = 0;
        }

        void push(T val){
            if(size == length){
                throw overflow_error("Called push on full stack.");
            }
            else{
                data[size] = val;
                ++size;
            }
        }

        void pop(){
            if(size == 0){
                throw out_of_range("Called pop on empty stack.");
            }
            else{
                size -= 1;
            }
        }

        void pop_two(){
            if(size == 1){
                throw out_of_range("Called pop_two on a stack of size 1.");
            }

            else if(size == 0){
                throw out_of_range("Called pop on empty stack.");
            }

            else{
                size -= 2;
            }
        }

        T top(){
            if(size == 0){
                throw underflow_error("Called top on empty stack.");
            }

            else{
                return data[size-1];
            }
        }

        bool empty(){
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }
};

#endif