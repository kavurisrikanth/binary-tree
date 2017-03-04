#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    int val;
    Node *next;
    Node *prev;
    
    public:
        Node();
        ~Node();
        void set_value(int val);
        int get_value();
        void set_next(Node *next);
        Node* get_next();
        void set_prev(Node *prev);
        Node* get_prev();
};

Node::Node() {
    val = 0;
    
    // We'll allocate memory when we're adding the links
    // Design decision
    next = NULL;
    prev = NULL;
}

Node::~Node() {
    val = 0;
    free(next);
    free(prev);
}

void Node::set_value(int val) {
    this->val = val;
}

int Node::get_value() {
    return this->val;
}

void set_next(Node *next) {
    this->next = next;
}

Node* get_next() {
    return this->next;
}

void set_prev(Node *prev) {
    this->prev = prev;
}

Node* get_prev() {
    return this->prev;
}