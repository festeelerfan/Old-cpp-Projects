#include "MyList.h"
#include <iostream>

using namespace std;

MyList::MyList() {
      head = nullptr;
}
  
MyList::MyList(const MyList& str) {
    Node *temp = str.head;
    if (temp != nullptr) {
        Node *node = new Node();
        node->value = temp->value;
        head = node;
        while (temp != nullptr) {
            temp = temp->next;           
            if (temp != nullptr) {
                node->next = new Node();
                node->next->value = temp->value;
                node = node->next;
            }
        }
    }
    else {
        head = nullptr;

    }
}
  
MyList::MyList(const string& str) {
      
}
  
MyList::MyList(const char* str) {
      
}
  
MyList::~MyList() {
    while (head != nullptr) {
        Node* curr = head;
        head = head->next;
        delete curr;
    }
}

  /* Mutators */
void MyList::push_front(char value) {
    Node *temp = new Node();
    temp->value = value;
    temp->next = head;
    head = temp;
}

void MyList::push_back(char value) {
    Node *temp = new Node();
    temp->value = value;
    Node *a = head;
    if (head == nullptr) {
        head = temp;
    }
    else {
        while (a->next != nullptr) {
        a = a->next;
        }
        a->next = temp;
    }
}

void MyList::pop_front() {
    if (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else {
        return;
    }
}

void MyList::pop_back() {
    if (head == nullptr) {
        return;
    }
    else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node *temp = head->next;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        delete temp;
    }
}
/*
void MyList::swap(int i, int j); */

void MyList::insert_at_pos(int i, char value) {
    int j = 0;
    Node *a = head;
    if (i == 0) {
        push_front(value);
    }
    else if (head == nullptr) {
        cout << "Empty list" << endl;
        return -1;
    }
    if (i < 0) {
        cout << "Invalid position" << endl;
        return -1;
    }
    
    else
}
void MyList::reverse() {
    Node *curr = head;
    Node *arc = nullptr;
    Node *sub = nullptr;
    while (curr != nullptr) {
        sub = curr->next;
        curr->next = arc;
        arc = curr;
        curr = sub;
    }
    head = arc;
}

  /* Accessors */
int MyList::size()const {
    int i = 0;
    Node *a = head;
    while (a != nullptr) {
        a = a->next;
        i+=1;
    }
    return i;
}

void MyList::print()const {
    Node *a = head;
    if (head == nullptr) {
        cout << "Empty list" << endl;
    }
    else {
        while (a->next != nullptr) {
            cout << a->value << ", ";
            a = a->next;
        }
        cout << a->value << endl;
    }
}

int MyList::find(char value)const {
    Node *a = head;
    int i = 0;
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return -1;
    }
    while (a != nullptr) {
        if (a->value == value) {
            return i;
        }
        a = a->next;
        i+=1;
    }
    cout << "Character not in list" << endl;
    return -1;
}

//int MyList::find(MyList& query_str)const;

  /* Operator overloaders */ 
MyList& MyList::operator=(const MyList& str) {
    if (this != &str) {
        delete this;
        Node *a = str.head;
        while (a != nullptr) {
            push_back(a->value);
            a = a->next;
        }
    }
    return *this;
}

/*char& MyList::operator[](const int i);
MyList MyList::operator+(const MyList& str); */

  /* Newly assigned functions */ /*
bool MyList::is_palindrome()const;
void MyList::merge_list(MyList A, MyList B);
bool MyList::remove_char(char c);
char MyList::front()const;  */