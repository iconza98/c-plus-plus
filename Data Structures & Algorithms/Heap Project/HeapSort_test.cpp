// Ikani Samani
// CS 2420
// Project : Heap Project
// Novemember 4, 2013
//
// I Ikani Samani have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library. 
// I understand that any violation of this disclaimer will result in a 0 for the project.
// ---------------------------------------------------------------------------------
//
// I created this test program to intialize an array and pass it to a heap class to perform
// a sort in accending order.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Heap.h"

using namespace std;

void print_menu();
char get_user_command();
int get_number();
void randomizeArray(int a [], int size);
void printArray(int a[], int size);
void heapSort(int a[], int size);

int main()
{
	const int MAX = 20;

	int array [MAX];
	randomizeArray(array, MAX);
	Heap test(array, MAX);
	char choice;

	cout << "I have initialized an empty Binary tree of integer." << endl;
	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case '*' : printArray(array, MAX);
			break;
		case '?' : randomizeArray(array, MAX);
			break;
		case 'A' : test.print();
			break;
		case 'P' : test.printTree();
			break;
		case 'I' : test.insert(get_number());
			break;
		case 'H' : heapSort(array, MAX);
			break;
		case 'D' : cout << test.removeFront() << " Has been removed from the Heap" << endl;
			break;
		case 'Q' : cout << "Ridicule is the best test of truth." << endl;
			break;
		default: cout << choice << " is invalid." << endl;
		}

	} while (choice != 'Q');

	return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " ?   Create a random array of 20 elements" << endl;
	cout << " *   Print the current array" << endl;
    cout << " A   Print the result from the Heap Print funciton" << endl;
    cout << " P   Print the results from the Heap Print Tree fucntion" << endl;
	cout << " H   Activate Global Heap Sort Function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " D   Remove first element in Heap" << endl;
    cout << " Q   Quit this test program" << endl;
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
    
    cout << "Please enter a integer number for the heap: ";
    cin  >> result;
    cout << result << " has been processed." << endl;
    return result;
}
void randomizeArray(int a[], int size)
	// libaries used: time.h
{
	srand(clock());
	for (int i = 0; i < size; i++)
	{
		a[i] = rand()%size;
	}

}
void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void heapSort(int a[], int size)
{
	Heap h(a,size);

	for (int i = 0; i < size; i++)
	{
		a[i] = h.removeFront(); 
	}
	cout << "Array sorted with Heap Sort\n" << endl;
	cout << "**Print Out current array to check!" << endl;
}