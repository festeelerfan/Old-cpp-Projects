/*
 * CS010C Summer 2021
 * Programming Assignment 2
 * Stack.h
 * template, exceptions
 */

#ifndef STACK_H_
#define STACK_H_

#define CAPACITY 100
#include <stdexcept>

using namespace std;

template<class T> class Stack {
public:
  int t; // type must be int, index into array
  T S[CAPACITY];
  Stack() { t = -1; }
  
  T& top() {
  if(is_empty()) {
    throw underflow_error("stack underflow");
    }
  else {
    return S[t];
    }
  }
  
  void push(const T& item) {
    if (t < 0) {
      t = 0;
      S[0] = item;
    }
    else if (t >= 0 && t < CAPACITY) {
      t += 1;
      S[t] = item;
    }
    else {
        throw overflow_error("stack overflow");
    }
  }
  
  void pop() {
   if (!is_empty()) {
       t -= 1;
   }
   else {
       throw underflow_error("stack underflow");
   }
  }

  bool is_empty() {
    if (t == -1) {
          return true;
      }
    return false;
  }

  unsigned int size() const {
    if (t >= 0) {
      unsigned int u = t;
      unsigned int j = 0;
      for (unsigned int i = 0; i <= u; ++i) {
        j += 1;
      }
     return j;
    }
    return 0;
  }
};

#endif /* STACK_H_ */