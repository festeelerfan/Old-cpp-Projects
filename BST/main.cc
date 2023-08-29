/**
 * cs014_sum20A
 * lab4-5
 * main.cc
 * RR
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
  ofstream ofs("output.dot");
  if(!ofs) {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  }
  
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    else if(cmd == "dotty") {
      t.inorder();
      if (mode == "preorder") {
        t.preorder();
      }
      if (mode == "depth") {
        t.depth();
      }
      if (mode == "height") {
        t.height();
      }
      if (mode == "postorder") {
        t.postorder();
      }
      t.dotty(mode);
      t.ender();
    }
    else if(cmd == "display") t.display();
    else if(cmd == "end") break;
    else
      cout << cmd << ", not found, try again." << endl;
  }
  ofs.close();
  // close ofstream
  cout << "Good bye!" << endl;
  return 0;
}
