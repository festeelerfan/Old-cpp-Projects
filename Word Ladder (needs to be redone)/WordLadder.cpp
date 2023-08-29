#include "WordLadder.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

WordLadder::WordLadder() { }

WordLadder::WordLadder(const string& listFile) {
    ifstream inFS;
    string word;
    inFS.open(listFile);
    if (!inFS.is_open()) {
        cout << "Error opening " << listFile << endl;
        exit(1);
    }
    while (inFS >> word) {
        dict.push_back(word);
    }
    dict.unique();
}

WordLadder::~WordLadder() {
    dict.clear();
}

void WordLadder::outputLadder(const string& start, const string& end) {
    stack<string> s;
    s.push(start);
    queue <stack<string>> q;
    queue <stack<string>> r;
    queue <stack<string>> t;
    q.push(s);
    t.push(s);
    while (!q.empty()) {
        for (list<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            stack<string> temp = q.front();
            if (offByOne(temp.top(), *it)) {
           //     cout << "it: " << *it << " ";
              //  cout << "Temp: " << temp.top() << endl;
                if (*it == end) {
                    temp.push(end);
                 //   cout << "Got one! " << endl;
                    if (r.empty()) {
                        r.push(temp);
                    }
                    else {
                        stack<string> front = r.front();
                        if (temp.size() < front.size()) {
                            r.pop();
                            r.push(temp);
                        }
                    }
                }

                else if (!r.empty()) {
                    stack<string> rb = r.back();
                    queue<stack<string>> z;
                    z = q;
                    queue<stack<string>> x;
                    x = t;
                    if (temp.size() < rb.size() - 2) {
                        stack<string> c = temp;
                        c.push(*it);
                       /* if (offByOne(c.top(), end)) {
                            c.push(end);
                            r.push(c);
                            r.pop();
                        } */
                      //  else {
                            if (uniqueue(c, z) && uniqueue(c, x)) {
                                q.push(c);
                            }
                            else if (uniqueue(c, x)) {
                                t.push(c);
                                t.push(temp);
                            }
                     //   }
                    }
                    it = dict.erase(it);
                } 
                else {
                    queue<stack<string>> z;
                    z = q;
                    queue<stack<string>> x;
                    x = t;
                    stack<string> c = temp;
                    c.push(*it);
                   if (uniqueue(c, z) && uniqueue(c, x)) {
                        q.push(c);
                    }
                    else if (uniqueue(c, x)) {
                        t.push(c);
                        t.push(temp);
                    }
                    it = dict.erase(it);
                  //  cout << q.size() << endl;
                }
            }
         /*   else if (*it == dict.back() && r.empty()) {
                q.push(temp);
              //  cout << "Running it back " << a.top() << endl;
            } */
        } 
    /*    queue<stack<string>> x;
        x = t;
        stack<string> front = q.front();
        if (uniqueue(front, x)) {
            t.push(front);
        } */
        q.pop();
    }
    while (!t.empty()) {
        t.pop();
    }
   if (!r.empty()) {
        stack<string> back = r.back();
        long unsigned int min = back.size();
        while (r.size() > 1) {
            stack<string> front = r.front();
            if (min < front.size()) {
                r.pop();
            }
            else {
                min = front.size();
                stack<string> s = r.front();
                r.pop();
                r.push(s);
                back = r.back();
            }
        }
        outputLadder(back, start);
        r.pop();
        return;
   }
    else {
    cout << "No Ladder found!" << endl;
    }
    return;
}

bool WordLadder::uniqueue(stack<string>&s, queue<stack<string>> &q) {
    stack<string> z = q.front();
    while (q.size() > 1) {
        if (s == z) {
            return false;
        }
        else {
            q.pop();
            z = q.front();
        }
    }
    if (s != z) {
        return true;
    }
    return false;
}

void WordLadder::outputLadder(stack<string>& s, const string& start) {
    while (s.top() != start) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << start << endl;
}

void WordLadder::printDictionary() {
    for (list<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << ' ' << *it;
    }
}

bool WordLadder::offByOne(const string& s1, const string& s2) {
    int diffs = 0;
    for (unsigned int i = 0; i < s1.size(); ++i) {
        if (s1.at(i) != s2.at(i)) {
            diffs += 1;
        }
    }
    if (diffs == 0 || diffs > 1) {
        return false;
    }
    if (diffs == 1) {
        return true;
    }
    return false;
}

list<string> dict;