// Ikani Samani
// Project: Recursive List
// 09/17/2013
//
// I  have not used any code other than my own (or that in the textbook) for this project. 
// I also have not used any function or data-structure from the Standard-Template Library.
// I understand that any violation of this disclaimer will result in a 0 for the project.

#include <cstdlib>
#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;
namespace list_2
{


		// postcondition: list is initialized
		List::List()
		{ head = nullptr; count = 0;}
		// postcondition: all nodes are destroyed using recursion
		List::~List()
		{
			Node* temp = head;
		if ( count == 0 )
			{
				delete head;
				head = nullptr;
			}
		else
			destroy(temp);
		}
		// ~List helper function
		void List::destroy(Node *n)
		{
			if ( n->next == nullptr)
			{
				delete n;
				count--;
				if ( count != 0)
				{Node *temp = head; destroy(temp); }

			}
			else
			{
				destroy(n->next);
			}

		}

		// postcondition: add element d at the end of the list
		//                using recursion
		void List::addEnd(int d)
		{
			// if head is null;
			if ( head == nullptr)
				head = new Node(d);
			else
			{
				addEnd(head, d);
			}

		}
		// addEnd helper function
		void List::addEnd(Node *n, int d)
		{
			// base case: next is null;
			if (n->next == nullptr)
			{
				Node* add = new Node(d);
				n->next = add;
			}
			else
			{
				addEnd(n->next, d);
			}

		}

		// postcondition: print the list ussing recursion
		void List::print()
		{
			print(head);
		}
		void List::print(Node *n)
		{
			if(n->next != nullptr)
			{
				cout << n->data << endl;
				print(n->next);
			}
			else cout << n->data;
		}

		// precondition: list is in sorted order
		//              (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains
		//                sorted order. using recursison.
		void List::insert(int d)
		{

			if (head == nullptr)
				{
					Node *add= new Node(d);
					head = add;
				}	
			else {
					if (head->data > d)
					{ 
						Node* add = new Node(d);
						add->next = head; 
						head = add;
					}
					else 
					{
						insert(head, d);
					}	
				}

		}
		void List::insert(Node* n, int d)
		{
			Node* peek = n->next;

			 //base case
			if ( n->next == nullptr && d > n->data)
			{
				Node *add = new Node(d);
				n->next = add;
			}
			else if ( d < peek->data && peek != nullptr)
			{
				Node* add = new Node(d);
				add->next = n->next;
				n->next = add;
			}
			else
			{
				insert(n->next, d);
			}
			
		}




		// postcondition: if d is in the list then find returns true
		//                else find returns false
		bool List::find (int d)
		{
			return find(head, d);

		}
		bool List::find(Node* n, int d)
		{
			if (n->data == d)
				return true;
			else
			{
				if ( n->next != nullptr)
					find(n->next, d);
				else
				{
					return false;
				}
			}
		}

		// postcondition: size is returned. Must be calculated using recursion.
		int List::size()
		{
			return size(head);

		}
		// size helper function
		int List::size(Node *n)
		{
			if( n == nullptr) return 0;
			else
				return 1 + size( n->next);
		}

} // end of namespace