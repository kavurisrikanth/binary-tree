/*
	binary-tree.cpp: Create a binary search tree. Baby steps.
*/

#include "Tree.hh"

int main(int argc, char **argv) {
	
	BinarySearchTree *t = new(BinarySearchTree);
	
	//t = (BinarySearchTree*)calloc(1, sizeof(BinarySearchTree));

	if(argc != 2) {
		printf("Invalid number of args.\n");
		printf("Usage: ./83 <file_name>\n");
		return 1;
	}	
	
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("Unable to open file: %s\n", argv[1]);
		return 1;
	}
	
	Node *n = NULL, *temp = NULL;
	int num = 0;
	while(fscanf(fp, "%d", &num) > 0) {
		n = new(Node);
		n->setValue(num);
		temp = t->getNodeByValue(num);
		if(temp != NULL)
			temp->incrementCount();
		else
			t->addNode(n);
	}
		
	t->printTree();
	printf("\n");

	fclose(fp);
//	free(t);
	delete t;
	
	return 0;
}