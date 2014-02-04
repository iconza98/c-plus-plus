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

#include <iostream>
#include <cstdlib>
#include "AVL.h"

using namespace std;

void print_menu();
char get_user_command();
int get_number();

int main()
{
	AVL test;
	char choice;

	cout << "I have initialized an empty Binary tree of integer." << endl;
	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case 'PP' : test.printPreorder();
			break;
		case 'P' : test.print();
			break;
		case 'I' : test.insert(get_number());
			break;

		case 'Q' : cout << "Ridicule is the best test of truth." << endl;
			break;
		default: cout << choice << "is invalid." << endl;
		}

	} while (choice != 'Q');

	return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " P    Print the results In-Order" << endl;
	cout << " PP   Print the Tree in Pre-Order" << endl;
    cout << " I    Insert a new number with the insert(...) function" << endl;
	cout << " Q    Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}
int get_number( )
// Library facilities used: iostream
{
    int result;
    
    cout << "Please enter a integer number for the tree: ";
    cin  >> result;
    cout << result << " has been processed." << endl;
    return result;
}