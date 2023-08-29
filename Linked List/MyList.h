#include "Node.h"
#include <iostream>

using namespace std;

#ifndef MYLIST_H_
#define MYLIST_H_

class MyList{
 private:
  Node* head;
 public:
  MyList();
  MyList(const MyList& str);
  MyList(const string& str);
  MyList(const char* str);
  ~MyList();

  /* Mutators */
  void push_front(char value);
  void push_back(char value);
  void pop_front();
  void pop_back();
  void swap(int i, int j);
  void insert_at_pos(int i, char value);
  void reverse();

  /* Accessors */
  int  size()const;
  void print()const;
  int  find(char value)const;
  int  find(MyList& query_str)const;

  /* Operator overloaders */
  MyList& operator=(const MyList& str);
  char& operator[](const int i);
  MyList operator+(const MyList& str);

  /* Newly assigned functions */
  bool is_palindrome()const;
  void merge_list(MyList A, MyList B);
  bool remove_char(char c);
  char front()const;
};
#endif /* MYLIST_H_ */