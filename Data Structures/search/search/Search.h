
#pragma once
#include <iostream>
#include <ostream>

using namespace std;


class Search
{
public:
	bool sequential_find(int num);
	bool recursive_binary_find(int d, int low, int high);
	bool iterative_binary_find(int d, int low, int high);

	void init_array();
	void init_sorted_array();
	void set_seed(int seed);
	int getSize();
	double getCounter() { return counter; };
	void resetCounter() {counter = 0;};

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Search& s)
	{	
		for(int i = 0; i < s.size; i++)
		{
			out << s.array[i] << ' ';
		}

		return out;
	};
	
	Search(int,int seed = 0);
	~Search();

private:
	double counter;
	int size;
	int seed;
	int* array;
};

