// Ikani Samani
// CS 2410
// Project: Graphs
// 12/13/2013

#include "Set.h"
#include <iostream> 
using namespace std;

#pragma once
#ifndef GRAPH_H
#define GRAPH_H
class Graph
{
public:
	static const int MAXIMUM = 20;
	Graph(void);
	Graph(int vertices);
	~Graph(void);
	
	// Modification Member Functions
	void add_edge(int source, int target, int weight);
	void add_vertex(const int);
	void remove_edge(int source, int target);

	// Constant Memeber Functions
	int getWeight(int source, int target);
	void DepthFirstSearch(int start); // start is a vertrex to begin DFS
	int size() const;
	void dijkstra(int start, int v); // shortest path algorithm
	Set neighbors(int vertex);
	void print();
	void printArray(int dist[]);
private:
	// DFS private helper function
	bool is_edge(int source, int target);
	int minDist(int dist[], bool visited[]);
	void DFS(int vertex, bool marked[] );
	void print_v(int v);
	int edges[MAXIMUM][MAXIMUM]; // graph adjacency matrix
	int many_verticies; // stores the number of verticies in the graph and numbered from 0 - to many verticies_-1
	int verticies[MAXIMUM]; // the verticies
	
};
#endif
