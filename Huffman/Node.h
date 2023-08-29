/* 
 * Node.h
 * cs10c_sum21
 * huffman 
 */
#include <string>

using namespace std;

#ifndef __NODE_H_
#define __NODE_H_

class Node {
public:
 	Node() { 
 	    count = 0; 
 	    left = nullptr;
 	    right = nullptr;
 	}
 	
	Node(char c, int count) {
	    this->c = c;
	    this->count = count;
	    left = nullptr;
	    right = nullptr;
	}
	
	Node(Node* left, Node* right, char c, int count) {
	    this->c = c;
	    this->count = count;
	    this->left = left;
	    this->right = right;
	}
	~Node() {
		left = nullptr;
		right = nullptr;
		delete this;
	}
  Node* left;
  Node* right;
  char c;
  int count;
  string bits;
};

#endif /* NODE_H_ */


