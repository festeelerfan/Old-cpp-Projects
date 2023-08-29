/**
 * cs014_sum20A
 * lab4-5
 * BST.H
 * RR
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
ofstream ofs("output.dot");

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    int postorder_num;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
      }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
      else
	      t->value = v;
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
	      if(v < t->value)
	        t->left = remove(v, t->left);
	      else if(t->value < v)
	        t->right = remove(v, t->right);
	      else if(t->left != NULL && t->right != NULL) {
	        t->value = find_min(t->right)->value;
	        t->right = remove(t->value, t->right);
	      } 
	      else {
	       BinaryNode* oldNode = t;
	       t = (t->left != NULL) ? t->left : t->right;
	       delete oldNode;
	      }
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }

  };

public:
  BST(): root(NULL) {}
  ~BST() {}
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  
  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
  
void inorder() { inorder(root); }
void inorder(BinaryNode *node){
    static int i = 1;
    if (node == nullptr)
        return;
    inorder(node->left);
    node->inorder_num = i++;
    inorder(node->right);
}

void depth() { depth(root, 0, 0); }
void depth(BinaryNode *node, int d, int m){
  if (d > m) {
    m = d;
  }
  root->height = m+1;
    if (node == nullptr)
        return;
    root->depth = 0;
    depth(node->left, d+1, m);
    node->depth = d;
    depth(node->right, d+1, m);
    node->depth = d;
}

void height() {
  depth();
  int i = root->height;
  height(root, i); 
}
void height(BinaryNode *node, int i){
    if (node == nullptr)
        return;
    height(node->left, i-1);
    node->height = i-1;
    height(node->right, i-1);
    node->height = i-1;
}

void preorder() { preorder(root); }
void preorder(BinaryNode *node){
    static int i = 1;
    if (node == nullptr)
        return;
    node->preorder_num = i++;    
    preorder(node->left);
    preorder(node->right);
}

void postorder() { postorder(root, 1); }
void postorder(BinaryNode *node, int j){
    static int i = 1;
    if (i > j) {
      j = i;
    }
    root->postorder_num = j;
    if (node == nullptr)
        return;
    postorder(node->left, j);
    postorder(node->right, j);
    node->postorder_num = i++;
}


  void print(string mode) { print(root, 0, mode); }
  void print(BinaryNode *t,int start, string mode) {
    if (mode == "inorder") {
      if (t == NULL) {
        return;
      }
      if (t->left != NULL) {
        print(t->left, start, mode);
      }
      ofs << t->value << " [color = black, style = empty, label=\"key=" << t->inorder_num << ", in=" << t->inorder_num << "\"];" << endl;
      if (t->right != NULL) {
        print(t->right, start, mode);
      }
    }
    else if (mode == "depth") {
       if (t->left != NULL) {
          print(t->left, start, mode);
        }
        ofs << t->value << " [color = black, style = empty, label=\"key=" << t->inorder_num << ", d=" << t->depth << "\"];" << endl;
        if (t->right != NULL) {
          print(t->right,start, mode);
        }
    }
    else if (mode == "height") {
       if (t->left != NULL) {
          print(t->left, start, mode);
        }
        ofs << t->value << " [color = black, style = empty, label=\"key=" << t->inorder_num << ", h=" << t->height << "\"];" << endl;
        if (t->right != NULL) {
          print(t->right,start, mode);
        }
    }
    else if (mode == "preorder") {
      if (t == NULL) {
        return;
      }
      if (t->left != NULL) {
        print(t->left, start, mode);
      }
      ofs << t->value << " [color = black, style = empty, label=\"key=" << t->inorder_num << ", pre=" << t->preorder_num << "\"];" << endl;
      if (t->right != NULL) {
        print(t->right, start, mode);
      }
    }
    else if (mode == "postorder") {
      if (t == NULL) {
        return;
      }
      if (t->left != NULL) {
        print(t->left, start, mode);
      }
      ofs << t->value << " [color = black, style = empty, label=\"key=" << t->inorder_num << ", pre=" << t->postorder_num << "\"];" << endl;
      if (t->right != NULL) {
        print(t->right, start, mode);
      }
    }
  }
  
  void dotty(string mode) { 
      ofs << "Digraph G {" << endl << endl;
      print(mode);
      ofs << endl;
      dotty(root);
  }
  void dotty( BinaryNode* t ) {
    if ( t == NULL ) return;
    if ( t->right != NULL ) {
      ofs << t->value << " -> " << t->right->value << " [color=black];" << endl;
      dotty(t->right);
    }
    if ( t->left != NULL ) {
      ofs << t->value << " -> " << t->left->value << " [color=black];" << endl;
      dotty(t->left);
    }
  }
  void ender() { ofs << endl << "}"; }
  private:
    BinaryNode* root;
};

#endif /* BST_H_ */

