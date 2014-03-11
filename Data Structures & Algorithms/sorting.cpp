//test.cpp

#include <iostream> // cout
#include <cstdlib> // rand

using namespace std;

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    
}
void display(int* array, int MAX){
    int i;
    for(i = 0; i < MAX; ++i)
		cout << array[i] << ' ';
	cout << endl;
}
void randomize(int* array, int MAX){
    for(int i = 0; i < MAX; ++i)
	{
		array[i] = rand()%100+1;
	}
    cout << "\nArray Randomized\n" << endl;
    
}
// Quicksort Performance
// worst case: O(n^2)
// best case: O(n)
// average case: O(n log n)
void quicksort(int* array, int size){
	if(size <= 1)
		return;
	// pivot index is selected at random
	int pivot = array[rand()%size];

	// indicies of the array
	int lower = 0;
	int higher = size - 1;

	// partition
	while(lower < higher){
		while(array[lower] < pivot)
			++lower;
		while(array[higher] > pivot)
			--higher;
		
		swap(array[lower], array[higher]);
	}

	// recursive step	
	quicksort(array, lower);
	quicksort(array, higher);

}
void merge(int* array, int end1, int end2){
	int i = 0; // begining index for first array
	int j = end1; // begining index for second array
	int k = 0; // begining index for new array

	// a new array will be need everytime
	int* tempArray = new int[end2];

	// take each next smallest element
	while(i < end1 && j < end2){
		if(array[i] < array[j]){
			tempArray[k] = array[i];
			++i;
		}
		else{
			tempArray[k] = array[j];
			++j;
		}
		++k;
	}
	// copy any remaining elements
	while(i < end1){
		tempArray[k] = array[i];
		++k;
		++i;
	}
	while(j < end2){
		tempArray[k] = array[j];
		++k;
		++j;
	}

	// copy the array back to
	for(i = 0; i < end2; ++i)
		array[i] = tempArray[i];

	delete [] tempArray;

}
void merge_sort(int array[], int size){
	// every individual element is sorted
	// then mergered into bigger arrays of double its size
	for(int i = 1; i < size; i *=2)
	{
		for(int j = 0; j < size - i; j += i*2){
			int end = (2*i < size - j) ? 2*i : size - j;
			merge(&(array[j]), i, end);
		}

	}
}

int main()
{
	const int MAX = 100;
	int array[MAX];
    
    int i, temp;
    
    randomize(array, MAX);
    display(array, MAX);
    
    
	cout << "\n\n Bubble sorted now:" << endl;
    
    
    // Bubble Sort Performance
	// worst case: O(n^2)
	// best case: O(n)
	// average case: O(n^2)
	for(i = 0; i < MAX; ++i)
	{
		for(int j = 1; j < MAX; ++j )
		{
			if(array[j] < array[j-1])
			{
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
    display(array, MAX);
    cout << endl<<endl;
    randomize(array, MAX);
    

    
    // Insertion sort Performance
	// worst case: O(n^2)
	// best case: O(n)
	// average case: O(n^2)
    for(i=0; i <MAX; ++i){
        int j = i + 1;
        while (j > 0 && array[j] < array[j-1]){
            temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            --j;
        }
    }
    cout << "Insertion Sorted" << endl;
    display(array, MAX);


    randomize(array, MAX);
    cout<<"Merge Sort"<<endl;
    merge_sort(array, MAX);
    display(array, MAX);
    
    // Quicksort Performance
	// worst case: O(n^2) - already sorted
	// best case: O(n)
	// average case: O(n log n)
    //randomize(array, MAX);
    //cout<<"quicksorted"<<endl;
    //quicksort(array, MAX);
    //display(array, MAX);


    
    
    
    
    
	return 0;
    
}