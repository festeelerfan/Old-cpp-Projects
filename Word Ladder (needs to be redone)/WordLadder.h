/*
 * WordLadder.h
 * Ryan Rusich
 */

#ifndef WORDLADDER_H_
#define WORDLADDER_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class WordLadder {
public:
  WordLadder();
  WordLadder(const string& listFile);
  ~WordLadder();
  void outputLadder(const string& start, const string& end);
  void outputLadder(stack<string>& s, const string& start);
  void printDictionary();
  bool offByOne(const string& s1, const string& s2);
  bool uniqueue(stack<string> &s, queue<stack<string>> &q);
  list<string> dict;
};

#endif /* WORDLADDER_H_ */
