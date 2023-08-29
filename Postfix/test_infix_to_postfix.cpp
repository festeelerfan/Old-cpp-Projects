#include <iostream> 
#include "Stack.h" 
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int pred (char a) {
    if (a == '*' || a == '/') {
        return 2;
    }
    if (a == '+' || a == '-') {
        return 1;
    }
    if (a == '(') {
        return -1;
    }
    return 0;
}

 void InfixToPostfix (string infix) {
    string postfix;
    char s = ' ';
    Stack<char> ops;
    string stack;
    for (unsigned int i = 0; i < infix.size(); ++i) {
        if (infix.at(i) < '0' || infix.at(i) > '9') {
            if (i > 0 && ((infix.at(i-1) >= '0') || (infix.at(i-1) <= '9')) && (infix.at(i) != '(')) {
              postfix.push_back(s);
            }
            if (infix.at(i) == '-' && ((infix.at(i+1) >= '0') || (infix.at(i+1) <= '9' && infix.at(i+1) != ' '))) {
                postfix.push_back(infix.at(i));
                continue;
            }
            if (infix.at(i) == '(' ) {
                ops.push(infix.at(i));
                stack.push_back(infix.at(i));
            }
            else if (infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/') {
                if (ops.is_empty() || ops.top() == '(') {
                    ops.push(infix.at(i));
                    stack.push_back(infix.at(i));
                }
                else if (pred(infix.at(i)) <= pred(ops.top())) {
                    while((pred(infix.at(i)) <= pred(ops.top())) && ops.top() != '(') {
                        postfix.push_back(ops.top());
                    //    postfix.push_back(s);
                        ops.pop(); 
                        stack.pop_back();
                    }
                    ops.push(infix.at(i));
                    stack.push_back(infix.at(i));
                }
            }
            else if (infix.at(i) == ')') {
                while (ops.top() != '(') {
                    postfix.push_back(ops.top());
                    ops.pop();
                    stack.pop_back();
                }
                if (ops.top() == '(') {
                    ops.pop();
                    stack.pop_back();
                }
                if (i == infix.size() - 1 && (ops.size() > 0 && ops.top() != '(')) {
                    postfix.push_back(s);
                    postfix.push_back(ops.top());
                    ops.pop();
                    stack.pop_back();
                } 
            }
        }
        else {
            postfix.push_back(infix.at(i));
            if (i == infix.size() - 1 && !ops.is_empty()) {
                if (ops.top() == '+' || ops.top() == '-' || ops.top() == '*' || ops.top() == '/') {
                    postfix.push_back(s);
                    postfix.push_back(ops.top());
                    ops.pop();
                    stack.pop_back();
                }
            }
        }
    }
    cout << postfix << endl;
}


int main (int argc, char* argv[]) {
    if (argc != 2) {
    cerr << "Usage error, expected: infix.txt\n";
    exit(1);
  }
    string infix = argv[1];
    char infix_expression;
    ifstream inFS;
    inFS.open(infix);
    string in;
    if (!inFS.is_open()) {
        cout << "Error opening " << infix << endl;
        exit(1);
    }
    while (inFS.get(infix_expression)) {
        in.push_back(infix_expression);
    }
    cout << in << endl;
   InfixToPostfix(in);

    return 0;
}