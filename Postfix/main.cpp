/*
 * CS010C Summer 2021
 * Programming Assignment 2
 * main.cpp
 * try-catch, exceptions
 */

#include <iostream>
#include <vector>
#include "Stack.h"
#include <stdexcept>

using namespace std;

int main() {

  //Stack s;
  string name = "NEO";
  Stack<string> s;
  try {
    s.is_empty() ? cout << "\nEmpty stack\n" : cout  << "Non-empty stack\n";

    /*s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    */
    s.push(name);
    s.push(name);
    s.push(name);
    s.push(name);
    s.push(name);

    s.push(name); // Raises overflow exception, 1st catch block.

  } catch(overflow_error& e) {
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
  } catch(underflow_error& e) {
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  vector<int> myvector(10);
  cout << myvector.at(20); // vector::at throws an out-of-range
  try {
    cout << myvector.at(20); // vector::at throws an out-of-range
  } catch(out_of_range& e) {
    cerr << "Out of range error: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  //cout << myvector.at(20); // vector::at throws an out-of-range

  try {
    s.top(); // Raises underflow exception, 1st catch block.
  } catch(underflow_error& e) {
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Default Exception.\n";
  }

  cout << "\nThe program flow continues...\n";
  cout << "The \"return 0;\" statement will cause the program to exit.\n";

  return 0;
}