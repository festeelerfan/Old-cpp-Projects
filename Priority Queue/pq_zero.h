#ifndef __PQ_ZERO_H_
#define __PQ_ZERO_H_

#include<vector>
#include<map>
#include<limits>

using namespace std;

template< class Item >
class pq_zero {
private:  
  vector<Item> heap; // The heap expands/shrinks to fit data
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  
void percolate_up( indx i ) {
    int parentIndex = (i - 1)/2;
    Item parentNode = heap.at(parentIndex);
    Item currNode = heap.at(i);
    if (priority.at(currNode) < priority.at(parentNode)) {
        swap(parentNode, currNode);
        percolate_up(parentIndex);
    }
}
  
void percolate_down( indx i ) {
    int li = (2*i)+1;
    int ri = (2*i)+2;
    Item* leftNode = nullptr;
    Item* rightNode = nullptr;
    Item currNode = heap.at(i);
    if (li < size()) {
        leftNode = &heap.at(li);
    }
    if (ri < size()) {
        rightNode = &heap.at(ri);
    }
    if (size() > 2 && (rightNode != nullptr && leftNode != nullptr)) {
        Item minNode = min(currNode, *leftNode, *rightNode);
        if (minNode == currNode) return;
    
        swap(currNode, minNode);
        percolate_down(index.at(minNode));
    }
    else if (rightNode != nullptr) {
        if (heap.at(ri) < heap.at(i)) { 
            swap(currNode, *rightNode);
            percolate_down(index.at(*rightNode));
        }
        return;
    }
    else if (leftNode != nullptr) {
        if (heap.at(li) < heap.at(i)) { 
            swap(currNode, *leftNode);
            percolate_down(index.at(*leftNode));
        }
    return;
    }
}

const Item min(const Item& i, const Item& j, const Item& k) {
    float iprio = numeric_limits<float>::max();
    float jprio = numeric_limits<float>::max();
    float kprio = numeric_limits<float>::max();
    iprio = priority.at(i);
    jprio = priority.at(j);
    kprio = priority.at(k);
    if (iprio < jprio) {
        if (iprio < kprio) {
            return i;
        }
    }
    else if (kprio < jprio) {
        return k;
    }
    return j;
}

void swap(const Item& i, const Item& j) {
    int tempIndex = index.at(i);
    Item tempItem = i;
    heap.at(index.at(i)) = j;
    heap.at(index.at(j)) = tempItem;
    index.at(i) = index.at(j);
    index.at(j) = tempIndex;
}

public: 
int size( ) const {
    return heap.size();
}
  
bool empty( ) const {
    return heap.empty();
}
  
const Item& top( ) const {
    return heap.at(0);
}
  
void pop( ) {
    if (size() > 1) {
        swap(top(), heap.back());
    }
    if (size() == 2) {
        if (heap.at(0) < heap.at(1)) {
            swap(top(), heap.back());
        }
    }
    index.erase(heap.back());
    priority.erase(heap.back());
    heap.pop_back();
    if (!empty()) { percolate_down(0); }
}
  
void push( const Item& w, float prio ) {
    if (empty()) {
        heap.push_back(w);
        index[w] = 0;
        priority[w] = prio;
        return;
    }
    heap.push_back(w);
    index[w] = size() - 1;
    priority[w] = prio;
    percolate_up(index.at(w));
    
}

};

#endif