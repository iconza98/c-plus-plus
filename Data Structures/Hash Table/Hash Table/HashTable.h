// Ikani Samani
// Project: Hash Tables
// Date:
// 


#pragma once
#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
public:
	// Default Constructor
	Node(){next = nullptr; name = "none"; weight = 0.0;};
	// Param Constructor
	Node(string d, double n){ name = d; weight = n; next = nullptr;};
	int key;
	string name;
	double weight;
	Node* next;
};

class HashChain // list object to hold chained Nodes
{
public:	
	HashChain();
	HashChain(string n, double d);
	void insertNode(string s, double d);
	bool getKey(string s);
	double getWeight(string s) const;
	Node* head;
};
 
class HashTable
{
public:
	HashTable(void);
	HashTable(const HashTable& source);
	~HashTable(void);

	static const int TABLE_SIZE = 128;
	int hash(string s);
	void insert(string name, double data);

	int getSize() { return size;};
	int getUsed() { return used;};
	double retrieve(string s);
	bool keyExist(string s) const;
	double HashTable :: operator[](string s);
	void print()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{	
			if (buckets[i] != nullptr)
			{
				if (buckets[i]->head != nullptr)
				{

					Node* temp = buckets[i]->head;
					if(temp != nullptr)
						cout << i << " " << temp->name<< " " << temp->weight << endl;

					if (temp->next != nullptr)
					{
						while (temp->next != nullptr)
						{
							temp = temp->next;
							cout << i << " " << temp->name << " " << temp->weight << endl;
						} 
					}  
				}
			}
		}
	};

	
private:
	// Private Data Memebers
	HashChain *buckets[TABLE_SIZE];
	int size;
	int used;
	// Private Member Functions
	double returnWeight(string s) const; 
	void deleteNodes(Node* n);
	
};

