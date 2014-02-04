//
#ifndef NODE_H
#define NODE_H

struct Node
{
	int data;
	Node *next;
	
	// Constructor
	//Postcondition: Node data is initialized
	Node(int d){ data = d; next = nullptr;}

};

#endif