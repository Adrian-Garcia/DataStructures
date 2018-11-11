#include <iostream>
#include "Node.h"

using namespace std;

class BST {
		
	public:
		BST();
		BST(int rootData);

		void add(int data);

		int count();
		int sum();

		void print();

	private:
		NodeT *root;

		void counter(NodeT *r, int &sum);
		void adder(NodeT *r, int &totalSum);

		void preOrder(NodeT *r);
		void inOrder(NodeT *r);
		void postOrder(NodeT *r);
};

BST::BST() {
	root = NULL;
}

BST::BST(int rootData) {
	root = new NodeT(rootData);
}

void BST::add(int data) {

	NodeT *curr = root;
	NodeT *father = NULL;

	while (curr->getData() != NULL) {

		if (curr->getData() == data) {
			return;
		}
		else if (curr->getData() > data) {
			curr = curr->getLeft();
		} 
		else {
			curr = curr->getRight();
		}
	}

	if (father == NULL) {
		root = new NodeT(data);
	}

	else {
		if (father->getData() > data) {
			father->setLeft(new NodeT(data));
		} else {
			father->setRight(new NodeT(data));
		}
	}
}

int BST::count() {
	if (root == NULL) {
		return 0;
	}

	else {

		int sum=0;
		counter(root, sum);
		return sum;
	}
}

void BST::counter(NodeT *r, int &sum) {
	if (r != NULL) {
		sum++;
		counter(r->getLeft(), sum);
		counter(r->getRight(), sum);
	}
}

int BST::sum() {

	if (root == NULL) {
		return 0;
	}

	else {
		int totalSum = 0;
		adder(root, totalSum);
		return totalSum;
	}
}

void BST::adder(NodeT *r, int &totalSum) {
	if (r != NULL) {
		totalSum+=r->getData();
		adder(r->getLeft(), totalSum);
		adder(r->getRight(), totalSum);
	}
}

