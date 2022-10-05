#include "IntList.h"

int main(){

    IntList test;

    //testing push_front()

    test.push_front(1);
    test.push_front(2);
    test.push_front(3);
    test.push_front(4);

    cout << test << endl << endl;

    //testing pop_front()

    cout << "popfront 1" << endl;
    test.pop_front();
    cout << test << endl;
    cout << "popfront 2" << endl;
    test.pop_front();
    cout << test << endl;
    cout << "popfront 3" << endl;
    test.pop_front();
    cout << test << endl;
    cout << "popfront 4" << endl;
    test.pop_front();
    cout << test << endl;

    //testing push_back () << endl;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    cout << test << endl << endl;

    //testing pop_back()

    cout << "popback 1" << endl;
    test.pop_back();
    cout << test << endl;
    cout << "popback 1" << endl;
    test.pop_back();
    cout << test << endl;
    cout << "popback 1" << endl;
    test.pop_back();
    cout << test << endl;
    cout << "popback 1" << endl;
    test.pop_back();
    cout << test << endl;
    
    //testing printReverse()

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    test.printReverse();

    return 0;
}
