//
//
#include <iostream>

#pragma once

struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
};
class AVL
{
public:
	AVL(void);
	~AVL(void);
	void print();
	void printPreorder();
	void insert(int d);
	int getHeight(Node* &n);
private:
	void insert(int d, Node* &n);
	void reDoHeight (Node* &n);
	void rebalance(Node* &n);
	Node* rotateLeft(Node* &n);
	Node* rotateRight(Node* &n);
	Node* rotateRightLeft(Node* &n);
	Node* rotateLeftRight(Node* &n);
	void destroy_tree(Node* &n);
	void print(Node* &n, int depth);
	void printPreorder(Node* &n, int depth);

	Node* root;
};

