// list.h file
// contains the struct Node also
#include "Node.h"

#ifndef LIST_H
#define LIST_H

class Iterator
{
public:

	// Constructor
	Iterator(Node *np);
	// precondition: is_item is true
	// post condition n points to the next item in the list
	void operator++();
	// precondition: 
	// postcondition: returns true if there is a valid item
	bool is_item();
	// precondition: is_item == true
	// postcondition returns data that n is pointing at
	int operator* ();
private:
		Node* n;

};

class list
{
   public:
	   // CONSTRUCTOR
	   list( );
	   // postcondition: all nodes in the list are destroyed.
		~list();
        // MODIFICATION MEMBER FUNCTIONS
		//postcondition: entry is added to the front of the list
        void insert_front(const int& entry);
        //postcondition: entry is added to the back of the list
        void add_back(const int& entry);
		// postcondition: all nodes with data == entry are removed from the list
        void remove_all(const int& entry);
		// postcondition: an iterator is created pointing to the head of the list
		Iterator begin(void);
		bool is_in(const int target);
		
		
		// CONSTANT MEMBER FUNCTIONS
		// postcondition: the size of the list is returned
        int size( ) const;
    private:
		Node* head;
};

#endif