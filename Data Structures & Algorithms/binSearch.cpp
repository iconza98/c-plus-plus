// Binary Search

#include <cstdlib>
#include <iostream>

using namespace std;
int binary_search(int* array,int first,int last, int key);
int binary_search(int* array, int last, int key);

int main() {
    
    int array[10];
    
    for (int i=0; i<10; i++)
    {
        list[i]=2*i+1;
        cout << list[i] << ' ';
    }
    cout << endl;
    
    cout<< "binary search results: "<< binary_search(list,0,11,21) <<endl;
    cout << "iterative binary search results: " << binary_search(list,11,21)<<endl;
    
    return 0;
}//end of main

// binary_Search funtion
// purpose: find the index where the search is stored
// parameters: int array, first position in array, last position in array, key
// return: -1 if key is not in array, otherwise the position
int binary_search(int array[],int first,int last, int key)
{
    int index;
    
    if (first > last)
        index = -1;
    
    else
    {
        int mid = (first + last)/2;

        
        if (array[mid] == key){
            index = mid;
        }
        
        else if (search_key < array[mid])
            index = binary_search(array,first, mid-1, key);
        else
            index = binary_search(array, mid+1, last, key);
        
    }
    
    return index;
}
// binary_seach function (non-recursive)
// purpose: return the position of the key user is searching for in
// returns: -1 if not found in array, otherwise the position
int binary_search(int array [], int high, int key)
{
    int mid = high/2;
    int low = 0;
    int index = -1;
    
    while (low < high) {
        mid = (high + low) /2;
        
        if(array[mid] == key){
            index = mid;
            break;
        }
        else if(key < array[mid])
            high = mid - 1;
        else if(key > array[mid])
            low = mid + 1;
        else
            break;
    }
    return index;
    
}
