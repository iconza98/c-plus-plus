#include "AVL.h"
#include <iostream>
#include <iomanip>

using namespace std;

AVL::AVL(void)
{
	root = nullptr;
}

AVL::~AVL(void)
{
	if(root != nullptr)
		destroy_tree(root);
}
void AVL::destroy_tree(Node* &n)
{
		if( n->left != nullptr)
	{
		destroy_tree(n->left);
	}
	if (n->right != nullptr)
	{
		destroy_tree(n->right);
	}
	if(n->left == nullptr && n->right == nullptr)
			delete n;
	
}
void AVL :: insert(int d)
{
	insert(d, root);
}
void AVL::insert(int d, Node* &n)
{
	if (n == nullptr)
	{
		root = new Node;
		root->data = d;
		root->left = nullptr;
		root->right = nullptr;
		root->height = 1;
	}
	else
	{
		if( d != n->data)
		{
			if(d < n->data)
			{
				if (n->left != nullptr)
					insert(d, n->left);
				else
				{
					n->left = new Node;
					n->left->data = d;
					n->left->left = nullptr;
					n->left->right = nullptr;
					n->left->height = 1;
				}

			}
			else if (d > n->data)
			{
				if (n->right != nullptr)
					insert(d, n->right);
				else
				{
					n->right = new Node;
					n->right->data = d;
					n->right->right = nullptr;
					n->right->left = nullptr;
					n->right->height = 1;
				}
			}

		}
		else
		{
			cout << "Item already exist in Tree" << endl;
		} 
	}
	reDoHeight(n);
	rebalance(n);

}
int AVL :: getHeight(Node* &n)
{
	int temp;
	if( n == nullptr)
		return 0;
	else
	{
		temp = n->height;
		return temp;
	}
}
void AVL :: reDoHeight(Node* &n)
{
	int l, r, m;
	l = getHeight(n->left);
	r = getHeight(n->right);
	m = max(l,r);
	n->height = m + 1;
}
void AVL :: printPreorder()
{
	printPreorder(root, 0);
}
void AVL :: printPreorder(Node* &n, int depth)
{
	cout << setw(4 * depth) << ""; 
	if (n == nullptr)
		cout << "[Empty]" << endl;
	else if (n->left == nullptr && n->right == nullptr)
	{
		cout << n->data << "[leaf]" << endl;
		printPreorder(n->left, depth + 1);
		printPreorder(n->right, depth + 1);
	}
	else
	{
		cout << n->data << endl;
		printPreorder(n->left, depth + 1);
		printPreorder(n->right, depth + 1);
	}
}
void AVL :: print()
{
	print(root, 0);
}
void AVL :: print(Node* &n , int depth)
{
	if (n == nullptr)
	{
		for (int i = 0; i < depth; i++)
			cout << "\t";
		cout << "[empty]" << endl;;
			return;
	}
	print(n->right, depth + 1);
	for (int i = 0; i < depth; i++)
		cout << "\t";
		cout << n->data << endl;
		print(n->left, depth + 1);
	
}
Node* AVL :: rotateLeft(Node* &n)
{
	Node* c = n->right;
	n->right = c->left;
	c->left = n;
	return c;
}
Node* AVL :: rotateRight(Node* &n)
{
	Node* c = n->left;
	n->left = c->right;
	c->right = n;
	return c;
}
Node* AVL :: rotateRightLeft(Node* &n)
{
	Node* c = n->right;
	n->right = rotateRight(c);
	return rotateLeft(n);

}
Node* AVL :: rotateLeftRight(Node* &n)
{
	Node* c = n->left;
	n->left = rotateLeft(c);
	return rotateRight(n);

}
void AVL :: rebalance(Node* &n)
{
	int l = getHeight(n->left);
	int r = getHeight(n->right);

	if ((l - r) > 1)
	{
		if (l > r)
			n = rotateRight(n); // addition was in right subtree of left child
		else
			n = rotateLeftRight(n); // addition was right subtree of left child
	}
	else if ((r - l) > 1)
	{
		if (r > l)
			n = rotateLeft(n);
		else
			n = rotateRightLeft(n);
	}

}