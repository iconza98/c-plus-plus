// Ikani Samani
// Project: Hash Tables
// Date:
// 

#include "HashTable.h"
#include <iostream>
#include <cassert>

using namespace std;

static const int TABLE_SIZE = 128;

HashChain :: HashChain()
{
	head = nullptr;
}
HashChain :: HashChain(string s, double d)
{
	Node* n = new Node(s,d);
	head = n;
}
void HashChain :: insertNode(string s, double d)
{
	Node* n = new Node(s, d);

	if (head == nullptr)
	{
		head = n;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = n;
	}
}
bool HashChain :: getKey(string s)
{
	Node* temp = head;
	string tempkey = s;
	while (tempkey.compare(temp->name) != 0 && temp->next != nullptr)
		temp = temp->next;
	if(s.compare(tempkey) == 0)
		return true;
	else return false;
}
double HashChain :: getWeight(string s) const
{
	Node* temp = head;						
	while (s.compare(temp->name) != 0 && (temp->next != nullptr)) {			// So long as the temp node's key is not the search key, set the temp node to the next node
		temp = temp->next;
	} 
	if(s.compare(temp->name) == 0)
		return temp->weight;							// return the temp node's value
	else
	{
		cout << "Error: SearchKey does not exist" << endl;
		return -1;
	}
}

// ============================================================================================
//
//=============================================================================================

HashTable::HashTable(void)
{
	for (int i = 0; i < TABLE_SIZE; i++)
		buckets[i] = nullptr;

	size = TABLE_SIZE;
}

HashTable::~HashTable(void)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if(buckets[i] != nullptr)
		{
			deleteNodes(buckets[i]->head);
		}
	}
}
void HashTable :: deleteNodes(Node* n)
{
	if(n->next != nullptr)
		deleteNodes(n->next);
	if(n == nullptr)
		delete n;
}
void HashTable :: insert(string name, double data)
{
	int indx = hash(name);

	if (buckets[indx] == nullptr)
	{
		HashChain* chain = new HashChain(name, data);
		buckets[indx] = chain;
	}
	else
	{
		HashChain* temp = buckets[indx];
		temp->insertNode(name, data);
	}

	used++;
	

}
double HashTable :: retrieve(string s)
{

	int indx = hash(s);
	if( buckets[indx] == nullptr)
	{
		cout << "Error: no information found for: " << s << endl;
		return 0;
	}
	else
	{	
		HashChain* tempChain = buckets[indx];
		Node* temp = tempChain->head;
		while ( temp-> name != s && temp->next != nullptr)
			temp = temp->next;
		if ( temp->name == s)
			return temp->weight;
		else
			cout << "Error: no information found for: " << s << endl;

	}

}

double HashTable :: operator[](string s)
{
	int indx = hash(s);
		assert(indx <= TABLE_SIZE);

		Node* temp = buckets[indx]->head;
		while( temp->name != s && temp->next !=nullptr)
			temp = temp-> next;
		if(temp->name == s)
			return temp->weight;
		else
		{
			cout << "Error: no information found for " << s << endl;

			return 0;
		}


}



int HashTable :: hash(string s)
{
	int stringVal = 0;
	int length = s.length();
	for (int i = 0; i < length; i++)
		stringVal += s[i] * (1 + i);
	return stringVal % TABLE_SIZE;
}