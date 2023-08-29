#include <stdexcept>
#include "Stack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ifstream inFS;
    inFS.open("Strings.txt");
    Stack<char> test;
    char things;
    while (inFS >> things) {
        test.push(things);
    }
    cout << test.top() << endl;
    cout << test.size() << endl;
    if (!test.is_empty()) {
        cout << "It isn't empty" << endl;
    }
    test.pop();
    test.pop();
    cout << test.top() << endl;
    cout << test.size() << endl;
    test.pop();
    if (!test.is_empty()) {
        cout << "It's not empty" << endl;
    }
return 0;
}