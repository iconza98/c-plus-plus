// Ikani Samani
// Project: Recursive List
// 09/17/2013
//
// I Ikani Samani have not used any code other than my own (or that in the textbook) for this project. 
// I also have not used any function or data-structure from the Standard-Template Library.
// I understand that any violation of this disclaimer will result in a 0 for the project.

#pragma once

#include <cstdlib>
#include "Node.h"

namespace list_2
{
	class List
	{
		Node *head;
		int count;

		// helper function for the destructor
		// add other helper functions here to complete your program.
		// they should all contain one or more Node* as parameters
		void destroy(Node *n);
		void addEnd(Node *n, int d);
		void print(Node *n);
		void insert(Node *n, int d);
		bool find(Node *n, int d);
		int size(Node *n);
	public:
		// postcondition: list is initialized
		List();
		// postcondition: all nodes are destroyed using recursion
		~List();

		// postcondition: add element d at the end of the list
		//                using recursion
		void addEnd(int d);

		// postcondition: print the list ussing recursion
		void print();

		// precondition: list is in sorted order
		//                 (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains
		//                sorted order. using recursison.
		void insert(int d);

		// postcondition: if d is in the list then find returns true
		//                else find returns false
		bool find (int d);

		// postcondition: size is returned. Must be calculated using recursion.
		int size();

	};
}