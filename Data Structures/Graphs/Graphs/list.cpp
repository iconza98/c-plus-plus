
#include "list.h"
#include <cstdlib>
#include <cassert>


 // CONSTRUCTOR
        list::list( )
		{
			head = nullptr;
		}
		// postcondition: all nodes in the list are destroyed.
		list::~list()
		{
			Node* temp = head;

			while (temp != nullptr )
			{
				Node* deleter = temp;
				temp = temp->next;
				delete deleter;

			}
		}
        // MODIFICATION MEMBER FUNCTIONS
		//postcondition: entry is added to the front of the list
        void list::insert_front(const int& entry)
		{
			// create new node ptr on heap
			Node* add = new Node(entry);
			// post condition - check if head points to nullptr
			if( head == nullptr)
				head = add;
			// post condition - if head already points to an object
			else
			{
				// set add ptr to point to head
				add->next = head;
				// assign add to be head ptr
				head = add;
			}

		}
        //postcondition: entry is added to the back of the list
        void list::add_back(const int& entry)
		{
			Node* add = new Node(entry);
			Node* temp = head;
			if(head != nullptr)
			{
				// traverse to end of the list
				while ( temp->next != nullptr)
					temp = temp->next;
				// set last node to point to newly created node
				temp->next = add;
			}
			else
			{
				insert_front(entry);
			}
		}
		// postcondition: all nodes with data == entry are removed from the list
        void list::remove_all(const int& entry)
		{
				Node* temp = head;
				Node* previouse_ptr = nullptr;
			while ( temp != nullptr)
			{
				if( temp == head)
				{
					if( temp->data == entry)
					{
						Node* remove_ptr = head;
						if (head->next != nullptr)
							head = head->next;
						else
							head = nullptr;
						delete remove_ptr;
						// assert(head, temp);
						temp = head;
					}
					previouse_ptr = temp;
					temp = temp->next;
				}
				else
				{
					if (temp->data == entry)
					{
						Node* remove_ptr = temp;
						temp = temp->next;
						previouse_ptr->next = temp;
						delete remove_ptr;
					}
					else
					{
						previouse_ptr = temp;
						temp = temp->next;	
					}
					
				}

			}
		}
		// postcondition: an iterator is created pointing to the head of the list
		Iterator list::begin(void)
		{
			Iterator I(head);
			return I;
		}
		
		// CONSTANT MEMBER FUNCTIONS
		// postcondition: the size of the list is returned
        int list::size( ) const
		{
			int count = 0;
			Node* temp = head;
			if( head != nullptr)
			{
				while (temp != nullptr)
				{
					count++;
					temp = temp->next;
				}
				return count;
			}
			return 0;
			
		}

	bool list :: is_in(const int target)
	{

		Node* temp = head;
		while(temp->next != nullptr)
		{
			if (temp->data == target)
				return true;
			else
			{
				temp = temp->next;
			}
		}
		return false;



	}

			// Constructor
		Iterator::Iterator(Node *np)
		{
			n = np;
		}
		// precondition: is_item is true
		// post condition n points to the next item in the list
		void Iterator::operator++()
		{
			if(is_item())		
				n = n->next;
		}
		// precondition: 
		// postcondition: returns true if there is a valid item
		// test if next item is nullptr;
		bool Iterator::is_item()
		{
			if (n != nullptr)
				return true;
			else
				return false;
		}
		// precondition: is_item == true
		// postcondition returns data that n is pointing at
		int Iterator::operator* ()
		{
			if(is_item())
			{
				return n->data;
			}
			else
			{
				return -1;
			}

		}
