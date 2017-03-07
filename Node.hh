#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//class Node
class Node {
	private:
		int val;
		int count;
		class Node *left;
		class Node *right;
		class Node *prev;
	public:
		//class Node getParent(class Node *n);
		//class Node getChild(class Node *n);
		Node();
		~Node();
		bool setValue(int val);
		int getValue();
		class Node* getLeftChild();
		class Node* getRightChild();
		class Node* getParent();
		int getCount();
		void setLeftChild(class Node *n);
		void setRightChild(class Node *n);
		void setParent(class Node *n);
		void incrementCount();
};

Node::Node() {
	this->left = NULL;
	this->right = NULL;
	this->prev = NULL;
	this->count = 0;
}

Node::~Node() {
	free(this->left);
	free(this->right);
	free(this->prev);
	//free(this->count);
	free(this);
}

bool Node::setValue(int val) {
	this->val = val;
//	this->left = NULL;
//	this->right = NULL;
//	this->prev = NULL;
	return true;
}

int Node::getValue(void) {
	return this->val;
}

Node* Node::getLeftChild() {
	return this->left;
}

Node* Node::getRightChild() {
	return this->right;
}

Node* Node::getParent() {
	return this->prev;
}

int Node::getCount() {
	return this->count;
}

void Node::setLeftChild(class Node *n) {
	this->left = n;
}

void Node::setRightChild(class Node *n) {
	this->right = n;
}

void Node::setParent(class Node *n) {
	this->prev = n;
}

void Node::incrementCount() {
	this->count += 1;
}