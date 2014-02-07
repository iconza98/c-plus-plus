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


#include <iosfwd>

const int MAX = 500;

class Heap
{
public:
	Heap(void);
	Heap(int a[], int length);
	~Heap(void);
	void insert(int n);
	int removeFront();
	void print();
	void printTree();

	void swap(int& a, int& b);


private:
	int* passedArray;
	int parent(int);
	int rightChild(int);
	int leftChild(int);
	void siftDown(int);
	void printTree (int index, int depth);

	int heapArray[MAX];
	int heapSize;
};

