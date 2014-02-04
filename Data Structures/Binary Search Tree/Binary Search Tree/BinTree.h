// Ikani Samani
// CS 2420
// Project : Binary Search Tree
// October 29, 2013
//
// I Ikani Samani have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.
// ---------------------------------------------------------------------------------
//

#include <cstdlib>
#pragma once

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(){left = nullptr; right = nullptr;};
};

class BinTree
{
public:
	BinTree(void);
	~BinTree(void);

	void preorder_print();
	void postorder_print();
	void inorder_print();
	void insert(int key);
	bool find(int key);
	void destroy_tree();
	int size();
	void delete_node(int key);
	Node* search(int key) { return search(root, key);};
	int& findMax() { Node* temp = findMax(root); return temp->data;};

private:
	Node*& findMax(Node* leaf);
	Node* search(Node* leaf, int key) const;
	void destroy_tree(Node *leaf);
	void insert(int key, Node *leaf);
	int size(Node* leaf) const;
	bool find(int key, Node *leaf);
	void preorder_print(Node* leaf, int depth);
	void postorder_print(Node* leaf, int depth);
	void inorder_print(Node* leaf, int depth);
	void delete_node(Node* leaf, Node* previous, int key);

	Node* root;
};

