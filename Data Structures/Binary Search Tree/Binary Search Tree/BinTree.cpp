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


#include "BinTree.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


BinTree::BinTree(void)
{
	root = nullptr;
}
BinTree::~BinTree(void)
{
	if(root != nullptr)
	destroy_tree(root);		
}
void BinTree::destroy_tree(Node* leaf)
{
	if( leaf->left != nullptr)
	{
		destroy_tree(leaf->left);
	}
	if (leaf->right != nullptr)
	{
		destroy_tree(leaf->right);
	}
	if(leaf->left == nullptr && leaf->right == nullptr)
			delete leaf;
}
void BinTree::insert( int key, Node* leaf)
{
	if( key != leaf->data)
	{
		if(key < leaf->data)
		{
			if (leaf->left != nullptr)
				insert(key, leaf->left);
			else
			{
				leaf->left = new Node;
				leaf->left->data = key;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
		
		}
		else if (key > leaf->data)
		{
			if (leaf->right != nullptr)
				insert(key, leaf->right);
			else
			{
				leaf->right = new Node;
				leaf->right->data = key;
				leaf->right->right = nullptr;
				leaf->right->left = nullptr;			
			}
		}
	}
	else
	{
		cout << "Item already exist in Tree" << endl;
	}
	
}
void BinTree::insert(int key)
{
	if ( root != nullptr)
		insert (key, root);
	else
	{
		root = new Node;
		root->data = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}
int BinTree::size()
{
		return size(root);
}
int BinTree::size(Node* leaf) const
{
	if (leaf == nullptr)
		return 0;
	else
		 return size(leaf->left) + size(leaf->right) + 1;
}
bool BinTree::find(int key)
{
	if (root != nullptr)
		return find(key, root);
	else
		return false;
}
bool BinTree::find(int key, Node *leaf)
{
	if (leaf != nullptr)
	{
		if (key == leaf->data)
			return true;
		else if (key < leaf->data)
			return find(key, leaf->left);
		else
			return find(key, leaf->right);
	}
	else
		return false;
}
void BinTree::preorder_print(Node* leaf, int depth)
{
	cout << setw(4 * depth) << ""; 
	if (leaf == nullptr)
		cout << "[Empty]" << endl;
	else if (leaf->left == nullptr && leaf->right == nullptr)
	{
		cout << leaf->data << "[leaf]" << endl;
		preorder_print(leaf->left, depth + 1);
		preorder_print(leaf->right, depth + 1);
	}
	else
	{
		cout << leaf->data << endl;
		preorder_print(leaf->left, depth + 1);
		preorder_print(leaf->right, depth + 1);
	}
	
}
void BinTree::preorder_print()
{
		preorder_print(root, 0);
}
void BinTree::postorder_print(Node* leaf, int depth)
{
	cout << setw(4 * depth) << ""; 
	if (leaf == nullptr)
		cout << "[Empty]" << endl;
	else if (leaf->left == nullptr && leaf->right == nullptr)
	{
		preorder_print(leaf->left, depth + 1);
		preorder_print(leaf->right, depth + 1);
		cout << leaf->data << "[leaf]" << endl;
	}
	else
	{
		postorder_print(leaf->left, depth + 1);
		postorder_print(leaf->right, depth + 1);
		cout << leaf->data << endl;
	}
}
void BinTree::inorder_print()
{
		inorder_print(root, 0);
}
void BinTree::inorder_print(Node* leaf, int depth)
{
	cout << setw(4 * depth) << ""; 
	if (leaf == nullptr)
		cout << "[Empty]" << endl;
	else if (leaf->left == nullptr && leaf->right == nullptr)
	{
		inorder_print(leaf->right, depth + 1);
		cout << leaf->data << "[leaf]" << endl;
		inorder_print(leaf->left, depth + 1);
	}
	else
	{
		inorder_print(leaf->right, depth + 1);
		cout << leaf->data << endl;
		inorder_print(leaf->left, depth + 1);
	}
}
void BinTree::postorder_print()
{
		postorder_print(root, 0);
}
Node* BinTree::search(Node* leaf, int key) const
{
	if(leaf == nullptr)
		return nullptr;
	if(key == leaf->data)
		return leaf;
	if (key < leaf->data)
		return search(leaf->left, key);
	else return search(leaf->right, key);
}
 void BinTree::delete_node(int key)
 {
	if (root == nullptr)
		cout << "Tree is empty." << endl;
	else if( find(key))
		delete_node(root, root, key);
	else cout << "Number does not exist in tree." << endl;
}
void BinTree::delete_node(Node* leaf, Node* previous, int key)
{

	if (key < leaf->data)
	{
		if (leaf->left != nullptr)
		{
			previous = leaf;
			delete_node(leaf->left, previous, key);
		}
		

	}
	if (key > leaf->data)
	{
		if (leaf->right != nullptr)
		{
			previous = leaf;
			delete_node(leaf->right, previous, key);
		}

	}
	if (key == leaf->data)
	{
		if (leaf->right == nullptr && leaf->left == nullptr) // no children
		{
			if(leaf == root)
			{
				delete leaf;
				root = nullptr;
			}
			else if (previous->data > leaf->data)
			{
				delete leaf;
				previous->left = nullptr;
				
				cout << "Number succesfully removed from tree!" << endl;
			}
			else
			{
				previous->right = nullptr;
				delete leaf;
				cout << "Number sucessfully removed from tree!" << endl;
			}	
		}
		
		// case if leaf has a right pointer
		else if (leaf->left == nullptr && leaf->right != nullptr)
		{
			if (previous->data < leaf->data)
			{
				previous->right = leaf->right;
				delete leaf;
				cout << "Number sucessfully removed from tree!" << endl;
			}
			else
			{
				previous->left = leaf->right;
				delete leaf;
				cout << "Number sucessfully removed from tree!" << endl;
			}
		}
		// case if leaf has a right pointer
		else if (leaf->right == nullptr && leaf->left != nullptr)
		{
			if (previous->data < leaf->data)
			{
				previous->right = leaf->right;
				delete leaf;
				cout << "Number sucessfully removed from tree!" << endl;
			}
			else
			{
				previous->left = leaf->right;
				delete leaf;
				cout << "Number sucessfully removed from tree!" << endl;
			}
		}
		// case if leaf has two children
		else
		{
				Node* fromLeft = findMax(leaf);
				int temp = leaf->data;
				int replace = fromLeft->data;
				delete_node(replace); // delete max node
				leaf->data = replace; // set leaf value to max value
		}

	}

}
Node*& BinTree::findMax(Node* leaf)
{
	while (leaf->right != nullptr)
	{
		leaf = leaf->right;
	}
	return leaf;
}

// SMALLER DATA GOES ON THE LEFT