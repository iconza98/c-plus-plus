// Driver for Graph Class
//
// Project: Graphs

#include <iostream>
#include "Graph.h"
#include "Set.h"


int main(void)
{
	cout << "Non-Interactive Driver for Graph Class" << endl;
	cout << "======================================" << endl;
	Graph g(7);
	cout << "Initialized graph object using pg. 756" << endl;
	g.add_edge(0, 4, 1);
    g.add_edge(0, 1, 1);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 0, 1);
    g.add_edge(3, 0, 1);
    g.add_edge(3, 6, 1);
	g.add_edge(3, 5, 1);
	g.add_edge(6, 1, 1);
	cout << endl << endl;

 
    cout << "Following is Depth First Traversal (starting from vertex 0) \n";
    g.DepthFirstSearch(0);
	cout << "\n=========================================" << endl;
	cout << "\nPerform Dijkstra's Alogrithm to vertices from pg. 773\n" << endl;
	Graph f(6);
	f.add_edge(0, 1,2);
	f.add_edge(0, 5, 9);
	f.add_edge(1, 3, 15);
	f.add_edge(1, 2, 8);
	f.add_edge(2, 3, 1);
	f.add_edge(4, 2, 7);
	f.add_edge(4, 3, 3);
	f.add_edge(5, 4, 3);


	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("From %d to %d", i,j);
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}