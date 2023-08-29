#ifndef __PQ_ZERO_H_
#define __PQ_ZERO_H_

#include<vector>
#include<map>

#include "Node.h"

using namespace std;

template< class Node >
class pq_zero {
private:  
  vector<Node> heap; 
  typedef int indx;  
  map<Node,indx> index;
  
void percolate_up( indx i ) {
    int parentIndex = (i - 1)/2;
    Node parentNode = heap.at(parentIndex);
    Node currNode = heap.at(i);
    if (currNode->count < parentNode->count) {
        swap(parentNode, currNode);
        percolate_up(parentIndex);
    }
}
  
void percolate_down( indx i ) {
    static int z = 0;
    unsigned int li = (2*i)+1;
    unsigned int ri = (2*i)+2;
    Node* leftNode = nullptr;
    Node* rightNode = nullptr;
    Node currNode = heap.at(i);
    if (li < size()) {
        leftNode = &heap.at(li);
    }
    if (ri < size()) {
        rightNode = &heap.at(ri);
    }
    if (size() > 2 && (rightNode != nullptr && leftNode != nullptr)) {
        Node minNode = min(currNode, *leftNode, *rightNode);
        if (minNode->count == currNode->count) return;
        z += 1;
        if (z > 1) {
            return;
        }
        swap(currNode, minNode);
        percolate_down(index.at(minNode));
    }
    else if (rightNode != nullptr) {
        if (heap.at(ri)->count < heap.at(i)->count) { 
            swap(currNode, *rightNode);
            percolate_down(index.at(*rightNode));
        }
        return;
    }
    else if (leftNode != nullptr) {
        if (heap.at(li)->count < heap.at(i)->count) { 
            swap(currNode, *leftNode);
            percolate_down(index.at(*leftNode));
        }
    return;
    }
}

const Node min(const Node& i, const Node& j, const Node& k) {
    if (i->count < j->count) {
        if (i->count < k->count) {
            return i;
        }
    }
    else if (k->count < j->count) {
        return k;
    }
    return j;
}

void swap( Node& i, Node& j) {
    int tempIndex = index.at(i);
    Node temp = i;
    heap.at(index.at(i)) = j;
    heap.at(index.at(j)) = temp;
    index.at(i) = index.at(j);
    index.at(j) = tempIndex;
}

public: 
unsigned int size( ) const {
    return heap.size();
}
  
bool empty( ) const {
    return heap.empty();
}
  
const Node& top( ) const {
    return heap.at(0);
}
  
void pop( ) {
    if (size() > 1) {
        swap(heap.at(0), heap.at(size() - 1));
    }
    if (size() == 2) {
        if (heap.at(0)->count < heap.at(1)->count) {
            swap(heap.at(0), heap.back());
        }
    }
    index.erase(heap.back());
    heap.pop_back();
    if (size() > 1) { percolate_down(0); }
}
  
void push(const Node& n) {
    if (empty()) {
        heap.push_back(n);
        index[n] = 0;
        return;
    }
    heap.push_back(n);
    index[n] = size() - 1;
    percolate_up(index.at(n));
}

const Node& at(int i) {
    return heap.at(i);
}

};

#endif