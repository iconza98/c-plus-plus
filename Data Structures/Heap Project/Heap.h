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

