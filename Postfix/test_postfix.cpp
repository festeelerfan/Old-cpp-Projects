#include <iostream> 
#include "Stack.h" 
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void RPN (string P) {
    Stack<double> s;
    double rhs;
    double lhs;
    double sol;
    for (unsigned int i = 0; i < P.size(); ++i) {
        if ((P.at(i) >= '0' && P.at(i) <= '9') || ((i != P.size() - 1) && (P.at(i) == '-') && (P.at(i+1) >= '0') && (P.at(i+1) <= '9'))) {
            string num;
            num.push_back(P.at(i));
            
            i += 1;
            while ((P.at(i) >= '0' && P.at(i) <= '9') || (P.at(i) == '.' && P.at(i+1) >= '0' && P.at(i+1) <= '9')) {
                num.push_back(P.at(i));
                i += 1;
            }
            s.push(stod(num));
        }
        else if (P.at(i) == '+') {
            rhs = s.top();
            s.pop();
            lhs = s.top();
            s.pop();
            sol = rhs + lhs;
            s.push(sol);
        }
        else if (P.at(i) == '-') {
            rhs = s.top();
            s.pop();
            lhs = s.top();
            s.pop();
            sol = lhs - rhs;
            s.push(sol);
        }
        else if (P.at(i) == '*') {
            rhs = s.top();
            s.pop();
            lhs = s.top();
            s.pop();
            sol = lhs * rhs;
            s.push(sol);
        }
        else if (P.at(i) == '/') {
            rhs = s.top();
            s.pop();
            lhs = s.top();
            s.pop();
            sol = lhs / rhs;
            s.push(sol);
        }
    }
    cout << sol << endl;
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
    cerr << "Usage error, expected: infix.txt\n";
    exit(1);
  }
    string postfix = argv[1];
    char postfix_expression;
    ifstream inFS;
    string P;
    inFS.open(postfix);
    if (!inFS.is_open()) {
        cout << "Error opening " << postfix << endl;
        exit(1);
    }
    while (inFS.get(postfix_expression)) {
        P.push_back(postfix_expression);
    }
    
    RPN(P);
   
   return 0;
}
