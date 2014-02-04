
#include "Search.h"
#include <iostream>
#include <cassert>

using namespace std;

Search::Search(int length,int num)
{	
	seed = num;
	size = length;
	array = new int[size];
	srand(seed);
	for (int i = 0; i < size; i++)
		array[i] = rand()%size;
}

Search::~Search(void)
{
	delete [] array;
}
bool Search::sequential_find(int num)
{
	resetCounter();

	for (int i = 0; i < size; i++)
	{
		counter++;
		if (array[i] == num)
			return true;
	}
	
	// code might break here;
	return false;

}
	bool Search::recursive_binary_find(int d, int low, int high)
	{
		counter++;

		if(low > high) 
			return false;

		int mid = ( low + high ) / 2;
		if ( array[mid] == d) 
		{
				return true;
		}
		else if (d < array[mid])
		{
			recursive_binary_find(d, low, mid - 1); 
			// mid is not he highest point and we've already check mid
		}
		else
		{
			recursive_binary_find(d, mid + 1, high);
		}
		
	}

	bool Search::iterative_binary_find(int d, int low, int high)

	{
	 resetCounter();
	
	 int mid = (high + low) / 2;

		 while (low < high || array[mid] != d)
		 {
			 counter++;
			 mid = (high + low) / 2;

			 if (array[mid] == d)
			 {
				 low = high + 1;
			 }
			 else if ( d < array[mid])
			 {
				 high = mid - 1;
			 }
			 else if( d < array[mid])
			 {
				 low = high - 1;
			 }
			 else
				 break;
		 }

	 if (array[mid] == d)
		 return true;
	 else 
		 return false;
	}

	void Search:: init_array()
	{

		int i = 0;
		int j = 0;
		srand(seed);
		array[i] = rand()%size;
		while( i < (size - 1))
		{
			j++;
			array[j] = array[i] + rand()%size;
			i++;
		}
		
		
	
	}
	void Search:: init_sorted_array()
	{

		int i, j;
		int temp;
		int numLength = size;
		
		for( i=0; i < numLength; i++)
		{
			for (j = 0; j < numLength -1; j++)
			{
				if(array[j+1] < array[j])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}

			}
		}

	}
	void Search:: set_seed(int num)
	{
		seed = num;
		srand(seed);
	}
	int Search::getSize()
	{
		return size;
	}
