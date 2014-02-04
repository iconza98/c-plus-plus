#include "Graph.h"
#include <cassert>


Graph::Graph(void)
{
	// intiallize edges matrixs with -1
	for (int i = 0; i < MAXIMUM; i++)
	{
		for (int j = 0; j < MAXIMUM; j++)
		{
			edges[i][j] = -1;
		}
	}
	many_verticies = 0;
}
Graph :: Graph(int vertices)
{
	// intiallize edges matrixs with -1
	for (int i = 0; i < MAXIMUM; i++)
	{
		for (int j = 0; j < MAXIMUM; j++)
		{
			edges[i][j] = -1;
		}
	}

	many_verticies = 0;
	for (int i = 0; i < vertices; i++)
	{
		this->add_vertex(i);
	}

}
Graph::~Graph(void)
{
	// only need to have s destructor for dynamtically created objects
	// linked list in set class?
}
void Graph :: add_edge(int source, int target, int weight)
{
	assert(source < size() );
	assert(target < size() );
	edges[source][target] = weight;
}
void Graph :: add_vertex(const int label)
{
	int new_vertex;
	
	assert(size() < MAXIMUM);
	new_vertex = many_verticies;
	++many_verticies;
	for (int i = 0; i < many_verticies; i++)
	{
		edges[new_vertex][i] = -1;
		edges[i][new_vertex] = -1;
	}
	verticies[new_vertex] = label;
}
void Graph :: remove_edge(int source, int target)
{
	assert(source < size());
	assert(target < size());
	edges[source][target] = -1;
}

bool Graph :: is_edge(int source, int target)
{
	assert(source < size());
	assert(target < size());
	if( edges[source][target] >= 0 )
		return true;
	else return false;
}

int Graph :: size() const
{
	return many_verticies;
}

Set Graph :: neighbors(int vertex)
{
	Set answer;
	
	assert(vertex < size());
	for (int i = 0; i < size(); i++)
	{
		if(edges[vertex][i] > 0)
			answer.insert_front(i);
	}
	return answer;
}
void Graph :: DepthFirstSearch(int v)
{
	bool marked[MAXIMUM];
	for (int i = 0; i < many_verticies; i++)
		marked[i] = false;
	
	DFS(v,marked);

}
void Graph :: DFS(int v, bool marked[])
{
	 // Mark the current node as visited and print it
    marked[v] = true;
   print_v( v);
 
	for (int i = 0; i < many_verticies; i++)
	{
		for (int j = 0; i < many_verticies; i++)
		{
			if(!marked[i] && edges[i][j] < 0)
				DFS(i,marked);
		}
		
	}

}
void Graph :: print_v(int v)
{
	cout << v << " ";
}
void Graph :: print()
{
	for (int i = 0; i < many_verticies; i++)
	{
		for (int j = 0; j < many_verticies; j++)
		{
			cout << edges[i][j] << ' ';
		}
		cout << endl;
	}
}
void Graph :: printArray(int dist[])
{
	cout << "Vertice distances from source" << endl;
	for (int i = 0; i < many_verticies; i++)
	{
		cout << dist[i] << ' ';
	}
	cout << endl;
}
int Graph :: minDist(int dist[], bool visited[])
{
	int min = INT_MAX;
	int min_indx;

	for (int i = 0; i < many_verticies; i++)
		if (visited[i] == false && dist[i] <= min)
		{
			min = dist[i];
			min_indx = i;
		}
		return min_indx;
}
void Graph :: dijkstra(int start, int v)
{
	// create a distance array
	int distance[MAXIMUM];
	bool visited[MAXIMUM];

	// intialize all the value with infinity
	for(int i = 0; i < many_verticies; ++i)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[start] = 0; //  distance from "start" to itself is zero
	

	for(int count = 1; count <= many_verticies; ++count)
	{
		int u = minDist(distance, visited);

		visited[u] = true;

		for (int j = 0; j < many_verticies; j++)
		{
			if (!visited[j] && (distance[u] != INT_MAX) && (edges[u][j] > 0) && (edges[u][j] < distance[j]))
			{
				distance[j] = distance[u] + edges[u][j];

			}
		}
		
		printArray(distance);
	}

}
