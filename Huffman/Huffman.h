/* Huffman.h
 * cs10c_sum21
 * huffman 
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include "pq_zero.h"
#include "Node.h"

using namespace std;

class Huffman {
public:
  Huffman() { root = NULL; }
  
  Huffman(const string& inputFile) {
    ifstream inFS;
    inFS.open(inputFile);
    string text;
    if (inFS.is_open()) {
      while (!inFS.fail()) {
        getline(inFS, text, '\n');
        message.append(text);
      }
    }
  }

  ~Huffman() {  
    message.clear();
    while (!pq.empty()) {
      pq.pop();
    }
    Node *n = root;
    while (n != NULL) {
      delete n->left;
      delete n->right;
      n = nullptr;
    }
  }
  
 void PrintCharFrequencies() { PrintCharFrequencies(root); }
 void PrintCharFrequencies(Node *node) {
   if (node != NULL) {
    cout << node->c << ": " << node->count << endl;
    PrintCharFrequencies(node->left);
    PrintCharFrequencies(node->right);
   }
 }
  
void BuildPQ() {
  for (unsigned int i = 0; i < message.length(); ++i) {
    if (!duplicate(message.at(i))) {
      Node *node = new Node(message.at(i), getCount(message.at(i)));
      pq.push(node);
    }
  }
}
void BuildHuffmanTree() {
  BuildPQ();
  while (pq.size() != 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();
    int freq = left->count + right->count;
    Node *n = new Node(left, right, '-', freq);
    pq.push(n);
  }
  root = pq.top();
}

bool duplicate(char c) {
  if (!pq.empty()) {
    for (unsigned int i = 0; i < pq.size(); ++i) {
      if (pq.at(i)->c == c) {
        return true;
      }
    }
  }
  return false;
}

int getCount(char c) {
  int count = 0;
  for (unsigned int i = 0; i < message.length(); ++i) {
    if (message.at(i) == c) {
      count += 1;
      mymap[c] +=1;
    }
  }
  return count;
}
  
  
  void SetBitsPerChar() { SetBitsPerChar(root); } 
  void SetBitCodes() { SetBitCodes(root); }  
  void Stats(); // prints the num bits used: non-compressed/compressed format
  void BitMap() { BitMap(root); }
  void BitMap(Node * n) {
    if (n != NULL) {
      cout << n->c << ", " << n->bits << endl;
      BitMap(n->left);
      BitMap(n->right);
    }
  }
  void PrintMessage(); //prints original message in huffman codes
  
private:
  list<string> message_list; // stores multiple input files if needed
  string message;      // stores a single input file
  map<char,int> mymap; // maps frequency "count" indexed by char 'c'
  map<char,string> mymap_compress; // maps frequency "count" to bitstream
  pq_zero<Node*> pq;   // binary heap priority queue stores nodes with priority
  Node* root; // root of prefix tree

  void SetBitCodes(Node* n) {
    if (n != NULL) {
      if (n->left != NULL) {
        string s = n->bits;
        s.push_back('0');
        n->left->bits.append(s);
      }
      if (n->right != NULL && n->c) {
        string s = n->bits;
        s.push_back('1');
        n->right->bits.append(s);
      }
      SetBitCodes(n->left);
      SetBitCodes(n->right);
    }
    return;
  }
  void SetBitsPerChar(Node* n) {
    if (n != NULL) {
      mymap_compress[n->c] = n->bits;
      SetBitsPerChar(n->left);
      SetBitsPerChar(n->right);
    }
  }
};

#endif /* HUFFMAN_H_ */




