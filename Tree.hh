
#include "Node.hh"

//class BinarySearchTree
class BinarySearchTree {

private:
	Node *root;

public:
	BinarySearchTree();	
	~BinarySearchTree();
	bool addNode(Node *n, Node *start = NULL);
	//bool isEmpty();
	//bool removeNode(Node *n);
	void printTree(Node *start = NULL, bool desc = false);
	Node* getNodeByValue(int val, Node *start = NULL);
};

BinarySearchTree::BinarySearchTree() {
	this->root = NULL;
}

BinarySearchTree::~BinarySearchTree() {

}

bool BinarySearchTree::addNode(Node *n, Node *start) {
	
	if(start == NULL)
		start = this->root;	
	
	if(start == NULL) {
		//this is the first node to be inserted
		this->root = n;
		this->root->setLeftChild(NULL);
		this->root->setRightChild(NULL);
		this->root->setParent(NULL);
		return true;
	}
	else {
		//not empty tree
		Node *temp = start, *buf = NULL;
		
		if(n->getValue() > temp->getValue()) {
			//given value is greater than that of the val in the leaf
			//means the node must be inserted to the right
			
			buf = temp->getRightChild();
			if(buf == NULL) {
				//there is nothing to the right
				//so go ahead and insert
				temp->setRightChild(n);
				n->setLeftChild(NULL);
				n->setRightChild(NULL);
				n->setParent(temp);
				return true;
			}
			else
				return addNode(n, buf);
		}
		
		else {
			//given value is less than that of the value in the current node
			//means the node must be inserted to the left
			
			buf = temp->getLeftChild();
			if(buf == NULL) {
				//nothing to the left
				//insert
				temp->setLeftChild(n);
				n->setLeftChild(NULL);
				n->setRightChild(NULL);
				n->setParent(temp);
				return true;
			}
			else
				return addNode(n, buf);
			
		}
		
	}
}


void BinarySearchTree::printTree(Node *start, bool desc) {

	/*
		Prints the tree. In ascending order, unless specified otherwise.
	*/

	if(start == NULL) {
		start = this->root;
				//printf("got root\n");
	}
	if(start->getLeftChild() != NULL) {
//		printf("going left\n");
		printTree(start->getLeftChild());
		
	}

		printf("%d ", start->getValue());
	if(start->getRightChild() != NULL) {
	//		printf("going right\n");
			printTree(start->getRightChild());
	}
		return;
	
}

Node* BinarySearchTree::getNodeByValue(int val, Node *start) {
	
	if(start == NULL)
		start = this->root;
		
	if(start == NULL)
		return NULL;
	
	if(val == start->getValue())
		return start;
	else {
		if(val < start->getValue()) {
			if(start->getLeftChild() == NULL)
				return NULL;
			return getNodeByValue(val, start->getLeftChild());
		}
	
		else {
			if(start->getRightChild() == NULL)
				return NULL;
			return getNodeByValue(val, start->getRightChild());
		}
	}
}