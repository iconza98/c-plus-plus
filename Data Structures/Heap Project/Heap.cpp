#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors
Heap::Heap(void)
{
	heapSize = 0;

}
// Param Constructor
// Postcondition: element at index 0 will be zero for easier calculations and
//				  the heapArray will be intialized by being passed to insert function
Heap::Heap(int a[], int length)
{
	int i = 0;
	int j = 0;
	heapSize = 0;
	heapArray[i] = j;
	for (; i < length; i++)
	{
		j = a[i];
		insert(j);
	}
	heapSize = length;
}

// Destructor
Heap::~Heap(void)
{
	// no dynamic memory allocated, no destructor needed
}
// Print Function
// Iterates through heapArray printing elements
void Heap::print()
{
	for (int i = 1; i <= heapSize; i++)
	{
		cout << heapArray[i] << " ";
	}
	cout << endl;
}
// printTree function
// prints entire tree starting from 1st index
// print 1st index and set intially depth to 0
void Heap::printTree()
{
	printTree(1,0); 
}
// printTree helper function
// Calculates conceptual children nodes and prints them out with respect to the
// The conceptual head by in-order printing
void Heap::printTree(int index, int depth)
{

	int left = leftChild(index);
	int right = rightChild(index);
	cout << setw(4 * depth) << "";
	if( heapSize == 0)
		cout << "[Empty]" << endl;
	else if (index <= heapSize)
	{
		if (left >= heapSize)
		{
			cout << heapArray[index] << " [leaf]" << endl;
		}
		else
		{

			cout << heapArray[index] << endl;
			if (left <= heapSize)
				printTree(left, depth + 1);
			if (right <= heapSize)
				printTree(right, depth +1); 
		}
	}

} // the child is larger than the heapSize it is a leaf
void Heap::insert(int n)
{	
	++heapSize;
	heapArray[heapSize] = n;
	int father = parent(heapSize);
	int current_indx = heapSize;
	if (heapSize == 1)
		heapArray[heapSize] = n;
	else
	{
		do
		{
			if (heapArray[father] >= heapArray[current_indx]) // loop until parent < current
			{
				swap(heapArray[father], heapArray[current_indx]);
				current_indx = father;
				father = parent(father); 
			}
			else
			{
				return;
			}
		} while ( father >= 1);

	}
}
// removeFront function
// postcondition: element in position 1 will be returned by value
//				  heapsize will be decremented
int Heap::removeFront()
{
	int holder = heapArray[1];
	swap(heapArray[1], heapArray[heapSize]);
	heapSize--;
	siftDown(1);
	return holder;

}
// siftDown function
// postcondition: takes an index and shifts all proceeding elements down
void Heap::siftDown(int index)
{
	int smaller;
	int current = index;
	int left = leftChild(current);
	int right = rightChild(current);

	if (left >= heapSize ) // check to see if we reached the end of the array
	{
		if(left >= heapSize)	// if out of scope 
			return;
		else
			smaller = left;
	}
	else
	{
		if (heapArray[left] <= heapArray[right]) // find smallest out of two children
			smaller = left;
		else
			smaller = right;
	}
	if (heapArray[current] > heapArray[smaller])
	{
		swap(heapArray[current], heapArray[smaller]);
		siftDown(smaller);
	}

}
// swap function
// postcondition: int values 'a' and 'b' will be exchanged
void Heap::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// partent calculation
int Heap::parent(int n){ return n/2;}
// rightChild calculation
int Heap::rightChild(int n) { return n * 2 + 1;}
// leftchild calculations
int Heap::leftChild(int n) { return n * 2;}